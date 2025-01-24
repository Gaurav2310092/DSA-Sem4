#include <bits/stdc++.h>
using namespace std;

struct Node {
    string word;
    string meaning;
    Node* next;
};

struct HashTable {
    int tableSize;
    Node** table;
    
    HashTable(int size) {
        tableSize = size;
        table = new Node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    void insertion() {
         string n;
        cout << "Enter the word that you want to insert: ";
        cin >> n;  
        cin.ignore();
        
        string a;
        cout << "Enter the meaning of the word: ";
        getline(cin, a); 
        
        int sum_ascii=0;
        int i=n.size()-1;
        while(i>=0){
            char d=n[i];
            int ascii=int(d);
            int index=n.size()-1-i;
            sum_ascii+=ascii*pow(10,index);
            i--;
        }
        
        int index=sum_ascii%10;

        Node* new_node = new Node;
        new_node->word = n;
        new_node->meaning=a;
        new_node->next = nullptr;

        new_node->next = table[index];
        table[index] = new_node;
    }

    
    void displaying() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << i << " : ";
            Node* temp = table[i];
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->word << " -> " << temp->meaning << " || ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }

    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            Node* temp = table[i];
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] table;
    }
};

int main() {
    int tableSize = 10;
    HashTable hashTable(tableSize); 
    
    int choice;
    do {
        cout << "--------Menu-------" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                hashTable.insertion();
                break;
            case 2:
                hashTable.displaying();
                break;
            case 3:
                cout<<"Exiting the programm..."<<endl;
                break;
            default:
                cout<<"Enter valid choice "<<endl;

        }
    }while(choice!=3);
    return 0;
}
