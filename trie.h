#include <iostream>
using namespace std;
const int E = 26;

class Trie {
    struct Node {
        bool endWord;
        Node* children[E];
        int count;
        Node() {
            endWord = false;
            count = 0;
            for (int i = 0; i < E; i++)
                children[i] = nullptr;
        }
    };

    Node* root;

public:  
    Trie() {
        root = new Node();  
    }

    void insert(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a'; 
            if (temp->children[index] == nullptr)
                temp->children[index] = new Node();
            temp = temp->children[index];
        }
        temp->endWord = true;
    }

    bool search(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a';  
            if (temp->children[index] == nullptr)
                return false;
            temp = temp->children[index];
        }
        return temp->endWord;
    }
};






