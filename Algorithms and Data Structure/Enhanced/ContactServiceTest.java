import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ContactServiceTest {

    @Test
    public void testAddContact() {
        ContactService contactService = new ContactService();
        Contact contact = new Contact("1234567890", "Ale", "Del", "1234567890", "Address");
        
        contactService.addContact(contact);
        assertTrue(contactService.getContacts().containsKey("1234567890"));
    }

    @Test
    public void testDeleteContact() {
        ContactService contactService = new ContactService();
        Contact contact = new Contact("1234567890", "Ale", "Del", "1234567890", "Address");
        
        contactService.addContact(contact);
        contactService.deleteContact("1234567890");
        assertFalse(contactService.getContacts().containsKey("1234567890"));
    }

    @Test
    public void testUpdateContact() {
        ContactService contactService = new ContactService();
        Contact contact = new Contact("1234567890", "Ale", "Del", "1234567890", "Address");
        
        contactService.addContact(contact);
        contactService.updateContact("1234567890", "Ale", "Smith", "0987654321", "New Address");
        Contact updatedContact = contactService.getContacts().get("1234567890");
        
        assertEquals("Ale", updatedContact.getFirstName());
        assertEquals("smith", updatedContact.getLastName());
        assertEquals("0987654321", updatedContact.getPhone());
        assertEquals("New Address", updatedContact.getAddress());
    }
}
