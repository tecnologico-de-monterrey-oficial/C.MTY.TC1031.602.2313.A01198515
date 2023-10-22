#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST<int> bst;
    int choice, data;
    int level; // Declara level fuera del switch

    while (true) {
        cout << "Binary Search Tree Menu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Print" <<endl;
        cout << "4. Find" <<endl;
        cout << "5. Height" << endl;
        cout << "6. Ancestors" << endl;
        cout << "7. What Level Am I" << endl;
        cout << "8. Exit" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                bst.insert(data);
                break;
            case 2:
                cout << "Enter data to delete: ";
                cin >> data;
                // Add code to delete data from the tree
                break;
            case 3:
                cout << "Binary Search Tree:" << endl;
                bst.print();
                break;
            case 4:
                cout << "Enter data to find: ";
                cin >> data;
                if (bst.find(data)) {
                    cout << "Data found in the tree." << endl;
                } else {
                    cout << "Data not found in the tree." << endl;
                }
                break;
            case 5:
                cout << "Height of the tree: " << bst.height() << endl;
                break;
            case 6:
                cout << "Enter data to find ancestors: ";
                cin >> data;
                cout << "Ancestors of " << data << ": ";
                bst.ancestors(data);
                break;
            case 7:
                cout << "Enter data to find its level: ";
                cin >> data;
                level = bst.whatLevelAmI(data); // Asigna el valor a level
                if (level != -1) {
                    cout << "Data is at level " << level << endl;
                } else {
                    cout << "Data not found in the tree." << endl;
                }
                break;
            case 8:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

