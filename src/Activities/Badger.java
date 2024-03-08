/**
 * Badger.java
 *
 * A simple class to demonstrate pointers in Java
 *
 */
public class Badger {

    private String name;

    /**
     * Creates a new Badger with the specifed name.
     */
    public Badger(String name) {
        this.name = name;
    }


    /**
     * Returns the name of the badger.
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the name of the badger.
     */
    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return String.format("Badger[name='%s']", name);
    }

    public static void main(String... args) {
        Badger b1 = new Badger("Nemorino");
        Badger b2 = new Badger("Maddalena");

        System.out.printf("b1 = %s\n", b1);
        System.out.printf("b2 = %s\n", b2);
    }
}
