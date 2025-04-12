#include "Contact_manager.h"
int main() {
    ContactManager manager;
    const string dataFileName = "Contacts.txt";
    manager.loadFromFile(dataFileName);

    int choice;
    while (true) {
        cout << "\n***** Contact Manager Menu *****\n";
        cout << "1) Add Contact\n";
        cout << "2) Edit Contact\n";     
        cout << "3) Search Contact \n";
        cout << "4) Delete Contact \n";
        cout << "5) Print All Contacts\n";
        cout << "6) Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            //ADD
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
            //EDIT
            case 2: {

                string phone;
                cout << "Enter Phone number to edit: ";
                getline(cin, phone);
                manager.editContact(phone);
                break;
            }
            //SEARCH
            case 3: {
                int sChoice;
                cout << "Do you want by name or by number? [0] or [1]\n";
                cin >> sChoice;
                cin.ignore(); 

                if(sChoice == 0){
                    string Name;
                    cout << "Enter Name to search: ";
                    getline(cin, Name);
                    manager.searchByName(Name);
                }
                else if(sChoice == 1){
                    string phone;
                    cout << "Enter Phone number to search: ";
                    getline(cin, phone);
                    manager.searchByNumber(phone);
                }
                break;
            }
            //DELETE
            case 4: {
                string phone;
                cout << "Enter Phone number to delete: ";
                getline(cin, phone);

                manager.deleteContact(phone);
                break;
            }
            //PRINT
            case 5: {
                manager.printAll();
                break;
            }
            //EXIT
            case 6: {
                manager.saveToFile(dataFileName);
                cout << "Exiting program\n";
                return 0;
            }
            default:
                cout << "Invalid choice Please try again\n";
        }
    }
}