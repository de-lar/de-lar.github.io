import java.util.HashMap;
import java.util.Map;

public class ContactService {
    private final Map<String, Contact> contacts;

    public ContactService() {
        this.contacts = new HashMap<>();
    }

    public void addContact(Contact contact) {
        contacts.put(contact.getId(), contact);
    }

    public void deleteContact(String id) {
        contacts.remove(id);
    }

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
    
    public Map<String, Contact> getContacts() {
        return contacts;
    }
}
