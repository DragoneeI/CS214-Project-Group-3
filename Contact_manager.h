#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Contact {
private:
    string name, phone, email;
public:
    void setN(string n);
    void setP(string n);
    void setE(string n);
    string getN();
    string getP();
    string getE();
};

class ContactManager {
private:
    struct Node {
        Contact data;
        Node* next;
    };

    static const int tableSize = 26;
    Node* table[tableSize];

    int getIndex(char c);
    bool phoneExists(string phone);

public:
    ContactManager();
    void insert(Contact c);
    void searchByNumber(string phone);
    void searchByName(string name);
    void editContact(string phone);
    void deleteContact(string phone);
    void printAll();
    void loadFromFile(string filename);
    void saveToFile(string filename);
    void mangeData(){}
};

#endif
