#include "ContactManager.h" 
int main() {
    ContactManager manager;
    int choice;

    while (true) {
        cout << "\n***** Contact Manager Menu *****\n";
        cout << "1) Add Contact\n";
        cout << "2) Search Contact by Phone\n";
        cout << "3) Delete Contact by Phone\n";
        cout << "4) Print All Contacts\n";
        cout << "5) Search Contact by Name\n";
        cout << "6) Load Contacts from file\n";
        cout << "7) save Contacts to file\n";
        cout << "8) Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int num;
                string name, phone, email;
                Contact c1;

                cout << "How many contacts would you like to add: ";
                cin >> num;
                cin.ignore();

                for (int i = 0; i < num; i++) {
                    cout << "Contact number ["<<i+1<<"]\n";
                    cout << "Enter Name: ";
                    getline(cin, name);
                    c1.setN(name);

                    cout << "Enter Phone: ";
                    getline(cin, phone);
                    c1.setP(phone);

                    cout << "Enter Email: ";
                    getline(cin, email);
                    c1.setE(email);

                    manager.insert(c1);
                }
                break;
            }
            case 2: {
                string phone;
                cout << "Enter Phone number to search: ";
                getline(cin, phone);
                manager.search(phone);
                break;
            }
            case 3: {
                string phone;
                cout << "Enter Phone number to delete: ";
                getline(cin, phone);

                manager.deleteContact(phone);
                break;
            }
            case 4: {
                manager.printAll();
                break;
            }
            case 5: {
            string Name;
                cout << "Enter Name to search: ";
                getline(cin, Name);
                manager.searchByName(Name);
                break;
            }
            case 6: {
                string filename;
                cout << "Enter filename to load from: ";
                getline(cin, filename);
                manager.loadFromFile(filename);
                break;
            }
            case 7: {
                string filename;
                cout << "Enter filename to save to: ";
                getline(cin, filename);
                manager.saveToFile(filename);
                break;
            }
            case 8: {
                cout << "Exiting program\n";
                return 0;
            }
            default:
                cout << "Invalid choice Please try again\n";
        }
    }

}