import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ContactServiceTest {

    // Test adding a valid contact
    @Test
    public void testAddContactValid() {
        ContactService contactService = ContactService.getInstance();
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Elm St");
        contactService.addContact(contact);
        assertTrue(contactService.getContacts().containsKey("1234567890"));
    }

    // Test adding a contact with null ID
    @Test
    public void testAddContactNullId() {
        ContactService contactService = ContactService.getInstance();
        assertThrows(IllegalArgumentException.class, () -> contactService.addContact(new Contact(null, "John", "Doe", "1234567890", "123 Elm St")));
    }

    // Test adding a contact with invalid phone number
    @Test
    public void testAddContactInvalidPhone() {
        ContactService contactService = ContactService.getInstance();
        assertThrows(IllegalArgumentException.class, () -> new Contact("1234567890", "John", "Doe", "12345", "123 Elm St"));
    }

    // Test deleting a contact
    @Test
    public void testDeleteContact() {
        ContactService contactService = ContactService.getInstance();
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Elm St");
        contactService.addContact(contact);
        contactService.deleteContact("1234567890");
        assertFalse(contactService.getContacts().containsKey("1234567890"));
    }

    // Test updating a contact's address
    @Test
    public void testUpdateContact() {
        ContactService contactService = ContactService.getInstance();
        Contact contact = new Contact("1234567890", "John", "Doe", "1234567890", "123 Elm St");
        contactService.addContact(contact);
        contactService.updateContact("1234567890", null, null, null, "456 Oak St");
        Contact updatedContact = contactService.getContacts().get("1234567890");
        assertEquals("456 Oak St", updatedContact.getAddress());
    }

    // Test retrieving singleton instance
    @Test
    public void testSingletonInstance() {
        ContactService instance1 = ContactService.getInstance();
        ContactService instance2 = ContactService.getInstance();
        assertSame(instance1, instance2); // Ensure both instances are the same
    }
}