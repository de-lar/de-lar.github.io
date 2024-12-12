// ContactService is responsible for managing contacts using the Singleton design pattern.
import java.util.HashMap;
import java.util.Map;

public class ContactService {
    private static ContactService instance; // Single instance of the ContactService
    private final Map<String, Contact> contacts; // Map to store contacts, keyed by ID

    // Private constructor to prevent instantiation outside the class
    private ContactService() {
        this.contacts = new HashMap<>();
    }

    // Method to retrieve the single instance of ContactService
    public static ContactService getInstance() {
        if (instance == null) {
            instance = new ContactService(); // Initialize if not already created
        }
        return instance;
    }

    // Method to add a contact to the map
    public void addContact(Contact contact) {
        if (contact == null || contact.getId() == null) {
            throw new IllegalArgumentException("Contact or ID cannot be null");
        }
        contacts.put(contact.getId(), contact);
    }

    // Method to delete a contact by ID
    public void deleteContact(String id) {
        contacts.remove(id);
    }

    // Method to update a contact by ID
    public void updateContact(String id, String firstName, String lastName, String phone, String address) {
        Contact contact = contacts.get(id);
        if (contact != null) {
            if (firstName != null) {
                contact.setFirstName(firstName);
            }
            if (lastName != null) {
                contact.setLastName(lastName);
            }
            if (phone != null) {
                contact.setPhone(phone);
            }
            if (address != null) {
                contact.setAddress(address);
            }
        }
    }

    // Method to retrieve all contacts
    public Map<String, Contact> getContacts() {
        return contacts;
    }
}