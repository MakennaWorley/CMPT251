#include <stdio.h>

int main()
{
    // An RGB color is stored as
    // hexadecimal: 0xRRGGBB
    //Binary: 0b0000 0000 RRRR RRRR GGGG GGGG BBBB BBBB
    //Each hexidecimal digit is 4 bits or a nibble

    //splitting a color into components
    int color = 0xfe87c7;
    //This will use << >> & | ^

    //Binaray:      0b0000 0000 RRRR RRRR GGGG GGGG BBBB BBBB
    //            & 0b0000 0000 0000 0000 0000 0000 1111 1111
    //Will give-    0b0000 0000 0000 0000 0000 0000 BBBB BBBB
    int b = color & 0x0000ff; //0xff is a mask

    //Binaray:      0b0000 0000 RRRR RRRR GGGG GGGG BBBB BBBB
    //            & 0b0000 0000 0000 0000 1111 1111 0000 0000
    //Will give-    0b0000 0000 0000 0000 GGGG GGGG 0000 0000
    int g = (color &0x00ff00) >> 8;

    //Binaray:      0b0000 0000 RRRR RRRR GGGG GGGG BBBB BBBB
    //            & 0b0000 0000 1111 1111 0000 0000 0000 0000
    //Will give-    0b0000 RRRR RRRR 0000 0000 0000 0000 0000
    int r = (color &0xff0000) >> 16;

    printf("color = 0x%x\n", color);
    printf("    r = 0x%x\n", r);
    printf("    g = 0x%x\n", g);
    printf("    b = 0x%x\n\n", b);

    //assembling r,g,b into a single color
    r = 0x44;
    g = 0x55;
    b = 0x66;
    //Binaray:      0b0000 0000 RRRR RRRr 0000 0000 0000 0000
    //            & 0b0000 0000 0000 0000 GGGG GGGG 0000 0000
    //Will give-    0b0000 0000 0000 0000 0000 0000 BBBB BBBB
    color = (r << 16) | (g << 8) | b;
    printf("color = 0x%x\n", color);

}
