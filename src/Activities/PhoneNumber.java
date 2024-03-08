import java.util.Scanner;
import java.util.regex.*;

public class PhoneNumber {

    private static final Pattern PHONE_NUMBER_PATTERN = Pattern.compile(
        // fill this in!
        // (123) 456-7890
        // (123)456-7890
        // 123-456-7890
        // 123/456-7890
        // 1234567890
        // or spaces around anything of these

        //[0-9]{3} beginning
        //[0-9]{3} middle
        //[0-9]{4} end

        // ^\(*\d{3}[) -]*\d{3}-*\\d{4}$ // * 0 or more (
            // ((((((123))--))   ---))456-------------7890 is valid
        // ^\(?[1-9][0-9]{2}[/)]?[0-9]{3}-?[0-9]{4}$ // ? at most (
            // (123/4567890
        // ^D*\d{3}\D\d{3}\D\d{4}\D*$
            //my 123 favorite 456 color is 7890 purple!
        
        "^ *\\(?([1-9]\\d{2})[/)]?-? ?(\\d{3}) ?-? ?(\\d{4}) *$" //acounts for extra spaces

    );

    // to extract pieces of a matched string, we need to enclose them in ()
    // (this is called a catpure group)

    public static void main(String[] args) {
        var in = new Scanner(System.in);
        while (true) {
            System.out.print("Enter a phone number in (xxx) xxx-xxxx form: ");
            String line = in.nextLine();

            if (line.isBlank())
                break;

            Matcher m = PHONE_NUMBER_PATTERN.matcher(line);
            if (!m.matches()) {
                System.out.println("Invalid phone number!\n");
                continue;
            } else {
                System.out.println("This looks like a valid phone number");
                // .group(0) gives entire match string
                String areaCode = m.group(1);
                String exchangeCode = m.group(2);
                String stationNumber = m.group(3);
                System.out.println("Area code: " + areaCode + "\nExchange code: " + exchangeCode + "\nStation Number: " + stationNumber);
            }


        }
    }
}
