import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class ContactTest {

    @Test
    public void testContactConstructor() {
        assertThrows(IllegalArgumentException.class, () -> new Contact(null, "Ale", "Del", "1234567890", "Address"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("12345678901", "Ale", "Del", "1234567890", "Address"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", null, "Del", "1234567890", "Address"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "Ale", null, "1234567890", "Address"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "Ale", "Del", null, "Address"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "Ale", "Del", "123456789", "Address"));
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "Ale", "Del", "1234567890", null));
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "Ale", "Del", "1234567890", "1234567890123456789012345678901"));
    }

    @Test
    public void testContactSetters() {
        Contact contact = new Contact("1234567890", "Ale", "Del", "1234567890", "Address");
        assertThrows(IllegalArgumentException.class, () -> contact.setFirstName(null));
        assertThrows(IllegalArgumentException.class, () -> contact.setFirstName("12345678901"));
        assertThrows(IllegalArgumentException.class, () -> contact.setLastName(null));
        assertThrows(IllegalArgumentException.class, () -> contact.setLastName("12345678901"));
        assertThrows(IllegalArgumentException.class, () -> contact.setPhone(null));
        assertThrows(IllegalArgumentException.class, () -> contact.setPhone("123456789"));
        assertThrows(IllegalArgumentException.class, () -> contact.setAddress(null));
        assertThrows(IllegalArgumentException.class, () -> contact.setAddress("1234567890123456789012345678901"));
    }
}