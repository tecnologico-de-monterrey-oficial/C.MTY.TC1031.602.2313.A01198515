#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using  namespace std;

struct TreeNode {
    string ip;
    int count;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const string& ip) : ip(ip), count(1), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();
    void Insert(TreeNode* &root, const string& ip);
    int Search(const string& ip);
};

BST::BST() {}

BST::~BST() {
    // Implementa la liberación de memoria (destrucción del árbol) si es necesario.
}

void BST::Insert(TreeNode* &root, const string& ip) {
    if (!root) {
        root = new TreeNode(ip);
        return;
    }

    int cmp = ip.compare(root->ip);
    if (cmp < 0) {
        Insert(root->left, ip);
    } else if (cmp > 0) {
        Insert(root->right, ip);
    } else {
        root->count++;
    }
}

int BST::Search(const string& ip) {
    // Abre el archivo de entrada
    ifstream inputFile("log602-3.txt");
    if (!inputFile) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 0;
    }

   string line;
    int count = 0;

    // Lee el archivo línea por línea y busca la IP
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string month, day, year, time, fileIP, message;
        iss >> month >> day >> year >> time >> fileIP;
        getline(iss, message);  // Lee el mensaje completo

        if (ip == fileIP) {
            count++;
        }
    }

    // Cierra el archivo
    inputFile.close();

    return count;
}

#endif  // BST_H
