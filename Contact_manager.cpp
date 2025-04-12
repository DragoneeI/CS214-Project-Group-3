#include "Contact_manager.h"

// Contact Class implementation 

void Contact::setN(string n) { name = n; }
void Contact::setP(string n) { phone = n; }
void Contact::setE(string n) { email = n; }
string Contact::getN() { return name; }
string Contact::getP() { return phone; }
string Contact::getE() { return email; }

//  ContactManager Class implementation

ContactManager::ContactManager() {
    for (int i = 0; i < tableSize; i++)
        table[i] = nullptr;
}

int ContactManager::getIndex(char c) {
    c = toupper(c);
    return c - 'A';
}

bool ContactManager::phoneExists(string phone) {
    for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];
        while (temp) {
            if (temp->data.getP() == phone)
                return true;
            temp = temp->next;
        }
    }
    return false;
}

void ContactManager::insert(Contact c) {
    if (phoneExists(c.getP())) {
        cout << "Duplicate phone number found: " << c.getP() << endl;
        return;
    }

    int index = getIndex(c.getN()[0]);

    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = nullptr;

    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        Node* temp = table[index];
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Contact added: " << c.getN() << endl;
}

void ContactManager::searchByNumber(string phone) {
    for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];
        while (temp != nullptr) {
            if (temp->data.getP() == phone) {
                cout << "Contact found:\n";
                cout << "Name: " << temp->data.getN() << endl;
                cout << "Phone: " << temp->data.getP() << endl;
                cout << "Email: " << temp->data.getE() << endl;
                return;
            }
            temp = temp->next;
        }
    }
    cout << "Contact with phone number " << phone << " not found.\n";
}

void ContactManager::searchByName(string name) {
    int x = 0;
    int i = getIndex(name[0]);
    Node* temp = table[i];
    while (temp != nullptr) {
        if (temp->data.getN() == name) {
            cout << "Contact found:\n";
            cout << "Name: " << temp->data.getN() << endl;
            cout << "Phone: " << temp->data.getP() << endl;
            cout << "Email: " << temp->data.getE() << endl;
            x++;
        }
        temp = temp->next;
    }
    if (x == 0)
        cout << "Contact with Name " << name << " not found.\n";
}

void ContactManager::editContact(string phone){

    string name,newPhone, email;
    
    for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];
        while (temp != nullptr) {
            if (temp->data.getP() == phone) {
                //Prompt
                cout <<" Enter [0] if you don't want to change the elmant \n";
                cout << "Enter name to edit: ";
                getline(cin, name);
                cout << "Enter Phone number to edit: ";
                getline(cin, newPhone);
                cout << "Enter  email to edit: ";
                getline(cin, email);
                //edit
                if(name  != "0")
                temp->data.setN(name);
                if(newPhone != "0")
                temp->data.setP(newPhone);
                if(email != "0")
                temp->data.setE(email);
                cout << "Contact Changed:\n";
                return;
            }
            temp = temp->next;
        }
    }
    cout << "Contact with phone number " << phone << " not found.\n";
}

void ContactManager::deleteContact(string phone) {
    for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data.getP() == phone) {
                if (prev == nullptr) {
                    table[i] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Contact deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    cout << "Contact with phone number " << phone << " not found.\n";
}

void ContactManager::printAll() {
    for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];
        if (temp != nullptr) {
            cout << "Contacts starting with '" << char('A' + i) << "':\n";
            while (temp != nullptr) {
                cout << "  Name: " << temp->data.getN()
                     << ", Phone: " << temp->data.getP()
                     << ", Email: " << temp->data.getE() << endl;
                temp = temp->next;
            }
        }
    }
}

void ContactManager::loadFromFile(string filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Unable to load the file!\n";
        return;
    }

    string name, phone, email;
    while (getline(inFile, name, ',') && getline(inFile, phone, ',') && getline(inFile, email)) {
        if (name[0] == ' ') name = name.substr(1);
        if (phone[0] == ' ') phone = phone.substr(1);
        if (email[0] == ' ') email = email.substr(1);

        Contact c;
        c.setN(name);
        c.setP(phone);
        c.setE(email);

        insert(c);
    }

    inFile.close();
    cout << "\nContacts loaded successfully from " << filename << endl;
}

void ContactManager::saveToFile(string filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Unable to save the file!\n";
        return;
    }

    for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];
        while (temp != nullptr) {
            outFile << temp->data.getN() << ","
                    << temp->data.getP() << ","
                    << temp->data.getE() << endl;
            temp = temp->next;
        }
    }

    outFile.close();
    cout << "Contacts saved successfully to " << filename << endl;
}

