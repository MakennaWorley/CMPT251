#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

// Struct for an image, containing its dimensions and pixel data
// DO NOT CHANGE ANYTHING ABOUT THIS or the testers will break!
struct bitmap
{
	int width;
	int height;
	int *pixels;
};

const int DIB_HEADER_SIZE = 14;
const int BMP_HEADER_SIZE = 40;

// Make "byte" mean "unsigned char"
typedef unsigned char byte;

// Calculates the stride of a .bmp file.
// (The stride is how many bytes of memory a single row of
// the image requires.)
inline int bmp_file_stride(struct bitmap *bmp);

// Calculates the total size that a .bmp file for this bitmap
// would need (in bytes)
inline int bmp_file_size(struct bitmap *bmp);

// Opens the file with the given name and maps it into memory
// so that we can access its contents through pointers.
void *map_file_for_reading(char *filename);

// Opens (and creates if necessary) the file with the given name
// and maps it into memory so that we can access its contents
// through pointers.
void *map_file_for_writing(char *filename, int file_size);

// Takes the contents of a bitmap file (bmp_file) and reads
// its data, filling in the struct bitmap pointed to by bmp.
// Returns 0 if everything worked, -1 if the file data isn't
// valid.
int read_bitmap(void *bmp_file, struct bitmap *bmp);

// Converts between a packed pixel (0xRRGGBB) and its components.
void rgb_to_pixel(int *p, int r, int g, int b);
void pixel_to_rgb(int p, int *r, int *g, int *b);

// Step 4 functions
void bitmap_to_grayscale(struct bitmap *bmp);
void bitmap_posterize(struct bitmap *bmp);

// Step 5 functions
void bitmap_squash(struct bitmap *bmp);
void bitmap_mirror(struct bitmap *bmp);

void do_main_menu();

int main()
{
    // Write any testing code you wish ---
    //char *filepath = "something.txt";
    //map_file_for_reading(filepath);


    /* Uncomment this if you want to run the menu-based application
     * (this won't do anything useful until you have completed at
     * least Steps 1 through 3). */
    do_main_menu();

	return 0;
}

int bmp_file_stride(struct bitmap *bmp)
{
    return (24 * bmp->width + 31) / 32 * 4;
}

int bmp_file_size(struct bitmap *bmp)
{
    int stride = bmp_file_stride(bmp);
    return DIB_HEADER_SIZE
        + BMP_HEADER_SIZE
        + stride * bmp->height;
}

void *map_file_for_reading(char *filename)
{
    // A) Use open() to open the file for reading.
    int fd = open(filename, O_RDONLY);
    printf("File opened\n");

    if (fd == -1)
    {
        printf("Cannot open the file\n");
        perror(NULL);
        return NULL;
    }

    // B) Use fstat() to determine the size of the file.
    struct stat info;
    struct stat *i = &info;
    printf("info created\n");

    if (fstat(fd, i) == -1)
    {
        printf("Cannot get file size\n");
        perror(NULL);
        return NULL;
    }
    printf("fstat opened\n");

    if (info.st_size == 0)
    {
        printf("fstat is empty\n");
        perror(NULL);
        return NULL;
    }

    // C) Call mmap() to map the file into memory.
    char *address = (char *)mmap(NULL, i->st_size, PROT_READ, MAP_SHARED, fd, 0);
    printf("mmap has been run\n");

    if (address == MAP_FAILED)
    {
        close(fd);
        printf("Cannot map the file\n");
        perror(NULL);
        return NULL;
    }

    // D) Close the file using close().
    close(fd);
    printf("File closed\n");

    // E) Return the pointer returned from mmap().
    return address;

    // Default implementation: just returns NULL.
    return NULL;
}

void *map_file_for_writing(char *filename, int file_size)
{
    // A) Use open() to open the file for writing.
    int fd = open(filename, O_RDWR | O_CREAT, 0600);
    printf("File opened/created\n");

    if (fd == -1)
    {
        printf("Cannot open the file\n");
        perror(NULL);
        return NULL;
    }

    // B) Use ftruncate() to set the size of the file.
    if (ftruncate(fd, file_size) == -1)
    {
        printf("Cannot make file\n");
        perror(NULL);
        return NULL;
    }
    printf("ftruncate opened\n");

    // C) Call mmap() to map the file into memory.
    char *address = (char *)mmap(&fd, file_size, PROT_WRITE, MAP_SHARED, fd, 0);
    printf("mmap has been run\n");

    if (address == MAP_FAILED)
    {
        close(fd);
        printf("Cannot map the file\n");
        perror(NULL);
        return NULL;
    }

    // D) Close the file using close().
    close(fd);
    printf("File closed\n");

    // E) Return the pointer returned from mmap().
    return address;

    // Default implementation: just returns NULL.
    return NULL;

}

int read_bitmap(void *bmp_file, struct bitmap *bmp)
{
    // Cast bmp_file to a byte * so we can access it
    // byte by byte.
    byte *file = (byte *) bmp_file;

    // Check the magic: it should start with "BM"
    if (file[0] == 0x42 && file[1] == 0x4D)
    {
        //file[10] is specific to that byte only, file+10 goes to that place in the file and collects x bytes
        int offset = *((int *)(file+10));
        int width = *((int *)(file+18));
        int height = *((int *)(file+22));
        short colorDepth = *((short *)(file+28));
        int compression = *((int *)(file+30));
        //printf("offset, width, height, colorDepth, compression are: %d, %d, %d, %hd, %d\n", offset, width, height, colorDepth, compression);

        if (colorDepth != 24)
        {
            printf("Color Depth is not 24");
            return -1;
        }

        if (compression != 0)
        {
            printf("Compression is not 0");
            return -1;
        }

        bmp->width = width;
        bmp->height = height;

        int *p = (int *)malloc(width*height*sizeof(int));
        bmp->pixels = p;

        int stride = (24 * width + 31) / 32 * 4;

        for (int y = 0; y < height; ++y)
        {
            int heightUpdated = height - 1 - y;
            byte *row = file + offset + heightUpdated * stride;
            for (int x = 0; x < width; ++x)
            {
                //pixels stored in little indian, b then g then r
                //printf("Row++ is %d, Row+1 is %d\n", row++, row);

                int b = *(row++);
                int g = *(row++);
                int r = *(row++);

                int i = y * width + x; //row number * width + column number

                rgb_to_pixel(&bmp->pixels[i], r, g, b);
            }
        }


        // Default implementation: just returns 0.
        return 0;
    }
    else
    {
        printf("The file being read in is not a bmp file\n");
        return -1;
    }
}

void write_bitmap(void *bmp_file, struct bitmap *bmp)
{

    // Cast bmp_file to a byte * so we can access it
    // byte by byte.
    byte *file = (byte *) bmp_file;

    // Fill in the rest :)
    file[0] = 0x42;
    file[1] = 0x4D;

    *((int *)(file+2)) = bmp_file_size(bmp); //file
    *((int *)(file+10)) = 54; //offset
    *((int *)(file+14)) = 40; //header
    *((int *)(file+18)) = bmp->width; //width
    *((int *)(file+22)) = bmp->height; //height
    *((short *)(file+26)) = (short)1; //color plane
    *((short *)(file+28)) = (short)24; //color depth
    *((int *)(file+30)) = 0; //compression

    int stride = (24 * bmp->width + 31) / 32 * 4;
    int size = bmp->height*stride;
    *((int *)(file+34)) = size; //image size

    for (int y = 0; y < bmp->height; ++y)
    {
        int heightUpdated = bmp->height - 1 - y;
        byte *row = file + 54 + heightUpdated * stride;
        for (int x = 0; x < bmp->width; ++x)
        {
            int j = y * bmp->width + x;
            int pixel = bmp->pixels[j];

            int b, g, r;

            pixel_to_rgb(pixel, &r, &g, &b);

            row[3*x] = b;
            row[3*x+1] = g;
            row[3*x+2] = r;
        }
    }

}

void rgb_to_pixel(int *p, int r, int g, int b)
{
    // Pack r, g, and b into an int value and save
    // into what p points to
    byte red = r & 0xff;
    byte green = g & 0xff;
    byte blue = b & 0xff;

    *p = (red << 16) | (green << 8) | blue;

}

void pixel_to_rgb(int p, int *r, int *g, int *b)
{
    // Separate the pixel p into its components
    // and save in the pointers
    int red = (p & 0xff0000) >> 16;
    int green = (p & 0x00ff00) >> 8;
    int blue = p & 0x0000ff;

    *r = red;
    *g = green;
    *b = blue;

}

// Step 4 functions
void bitmap_to_grayscale(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    //printf("bitmap_to_grayscale() not yet implemented\n");

    int blue = 0;
    int green = 0;
    int red = 0;
    int grey = 0;
    int size = bmp->height*bmp->width;

    /*pixel_to_rgb(bmp->pixels[0], &red, &green, &blue);
    grey = (red + green + blue)/3;
    rgb_to_pixel(&bmp->pixels[0], grey, grey, grey);*/

    for (int i = 0; i < size; ++i)
    {
        pixel_to_rgb(bmp->pixels[i], &red, &green, &blue);
        grey = (red + green + blue)/3;
        rgb_to_pixel(&bmp->pixels[i], grey, grey, grey);
    }

}

void bitmap_posterize(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    //printf("bitmap_posterize() not yet implemented\n");

    //Yes I know this is long, but it works and I don't want to shorten working code

    int blue = 0;
    int green = 0;
    int red = 0;

    int size = bmp->height*bmp->width;

    for (int i = 0; i < size; ++i)
    {
        pixel_to_rgb(bmp->pixels[i], &red, &green, &blue);
        if (red < 32)
        {
            red = 0;
        }
        else if (red < 96)
        {
            red = 64;
        }
        else if (red < 160)
        {
            red = 128;
        }
        else if (red < 224)
        {
            red = 192;
        }
        else
        {
            red = 255;
        }

        if (green < 32)
        {
            green = 0;
        }
        else if (green < 96)
        {
            green = 64;
        }
        else if (green < 160)
        {
            green = 128;
        }
        else if (green < 224)
        {
            green = 192;
        }
        else
        {
            green = 255;
        }

        if (blue < 32)
        {
            blue = 0;
        }
        else if (blue < 96)
        {
            blue = 64;
        }
        else if (blue < 160)
        {
            blue = 128;
        }
        else if (blue < 224)
        {
            blue = 192;
        }
        else
        {
            blue = 255;
        }

        rgb_to_pixel(&bmp->pixels[i], red, green, blue);
    }
}

// Step 5 functions
void bitmap_squash(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    //printf("bitmap_squash() not yet implemented\n");

    int width = bmp->width;
    int height = bmp->height;

    int nWidth = width/2;

    int *p = (int *)malloc(nWidth*height*sizeof(int));

    bmp->width = nWidth;

    int red, red1, red2, green, green1, green2, blue, blue1, blue2;

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < nWidth; ++x)
        {
            int i = y * width + 2 * x; //evens
            int j = i + 1;  //odds
            int k = y * nWidth + x;

            pixel_to_rgb(bmp->pixels[i], &red, &green, &blue);
            pixel_to_rgb(bmp->pixels[j], &red1, &green1, &blue1);

            red2 = (red + red1) / 2;
            green2 = (green + green1) / 2;
            blue2 = (blue + blue1) / 2;

            rgb_to_pixel(&p[k], red2, green2, blue2);
        }
    }
    free(bmp->pixels);
    bmp->pixels = p;
}

void bitmap_mirror(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    //printf("bitmap_mirror() not yet implemented\n");

    int width = bmp->width;
    int height = bmp->height;

    int nWidth = width*2;

    int *p = (int *)malloc(nWidth*height*sizeof(int));

    bmp->width = nWidth; //updates bmp

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int i = y * nWidth + x;
            int j = (y+1) * nWidth - 1 - x;
            int k = y * width + x;

            p[i] = bmp->pixels[k]; //this is for the original image
            //p[x] = bmp->pixels[x]; for row y=0

            //int row = (y+1) * nWidth;
            //int j = row - 1 -x;
            p[j] = bmp->pixels[k]; //this is for the mirrored image
            //p[nWidth-x-1] bmp->pixels[x]; for row y=0;
        }
    }
    free(bmp->pixels);
    bmp->pixels = p;
}

// Extra credit functions
void bitmap_reflect(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    printf("bitmap_reflect() not yet implemented\n");
}

void bitmap_skew(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    printf("bitmap_skew() not yet implemented\n");
}

void bitmap_shrink(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    printf("bitmap_shrink() not yet implemented\n");
}

void bitmap_rotate(struct bitmap *bmp)
{
    // Delete this print when you fill in the code
    printf("bitmap_rotate() not yet implemented\n");
}

void do_main_menu()
{
    char input_filename[100];

    void *file;
    while (1)
    {
        printf("Enter input image (a .bmp file): ");
        scanf("%s", input_filename);

        file = map_file_for_reading(input_filename);
        if (file != NULL)
            break;

        printf("Unable to read file \"%s\". Please try again.\n\n", input_filename);
    }

    struct bitmap bmp;
    if (read_bitmap(file, &bmp) == -1)
    {
        printf("Unable to read bitmap from \"%s\".\n", input_filename);
        return;
    }

    char choice_str[20];
    char choice = '\0';

    while (choice != 'Q' && choice != 'q')
    {
        printf("Menu:\n");
        printf("\tG) Make grayscale\n");
        printf("\tP) Posterize\n");
        printf("\tU) Squash\n");
        printf("\tM) Mirror\n");
        printf("\tS) Save\n");
        printf("\tQ) Quit\n");
        printf("What would you like to do? ");
        scanf("%s", choice_str);
        choice = choice_str[0];

        if (choice == 'G' || choice == 'g')
        {
            printf("Grayscale selected\n\n");
            bitmap_to_grayscale(&bmp);
        }
        else if (choice == 'P' || choice == 'p')
        {
            printf("Posterize selected\n\n");
            bitmap_posterize(&bmp);
        }
        else if (choice == 'U' || choice == 'u')
        {
            printf("Squash selected\n\n");
            bitmap_squash(&bmp);
        }
        else if (choice == 'M' || choice == 'm')
        {
            printf("Mirror selected\n\n");
            bitmap_mirror(&bmp);
        }
        else if (choice == 'S' || choice == 's')
        {
            printf("Enter filename: ");
            char filename[100];
            scanf("%s", filename);
            printf("Saving to %s...\n", filename);
            void *output = map_file_for_writing(filename, bmp_file_size(&bmp));
            if (output)
            {
                write_bitmap(output, &bmp);
                munmap(output, bmp_file_size(&bmp));
                printf("Saved!\n\n");

            }
            else
            {
                printf("Unable to save to file.\n\n");
            }
        }
        else if (choice == 'Q' || choice == 'q')
        {
            printf("Bye!\n\n");
            return;
        }
        else
        {
            printf("Invalid option. Please try again!\n\n");
        }
    }
}
