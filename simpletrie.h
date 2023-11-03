#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const unsigned ALPHA_SIZE = 26; // Tamaño del alfabeto de letras minúsculas

class TrieSimple {
private:
    struct TrieNode {
        TrieNode* children[ALPHA_SIZE];
        bool endWord; 
        int count;   

        TrieNode() {
            for (unsigned int i = 0; i < ALPHA_SIZE; i++) {
                children[i] = nullptr;
            }
            endWord = false;
            count = 0;
        }
    };

    TrieNode* root;

public:
    TrieSimple() : root(new TrieNode) {}

    void insert(string key) {
        transform(key.begin(), key.end(), key.begin(), ::tolower);

        TrieNode* temp = root;
        for (char c : key) {
            int index = c - 'a';
            if (!temp->children[index]) {
                temp->children[index] = new TrieNode;
            }
            temp->count++;
            temp = temp->children[index];
        }
        temp->endWord = true;
    }

    bool search(string key) {
        TrieNode* temp = root;
        for (char c : key) {
            int index = c - 'a';
            if (!temp->children[index]) {
                return false; 
            }
            temp = temp->children[index];
        }
        return temp->endWord; 
    }

    void remove(string key) {
        TrieNode* temp = root;
        TrieNode* parent = nullptr;

        for (char c : key) {
            int index = c - 'a';
            if (!temp->children[index]) {
                return; 
            }

            if (temp->count == 1) {
                delete temp;
                parent->children[index] = nullptr;
                return;
            }

            parent = temp;
            temp->count--; 
            temp = temp->children[index];
        }

        if (temp->endWord) {
            temp->endWord = false;
        }
    }

    string toString(string sep) {
        return toString(root, sep, "");
    }

private:
    string toString(TrieNode* node, string sep, string prefix) {
        string result = "";
        if (node->endWord) {
            result += prefix + sep;
        }

        for (unsigned int i = 0; i < ALPHA_SIZE; i++) {
            if (node->children[i]) {
                char c = 'a' + i;
                result = result + toString(node->children[i], sep, prefix + c);
            }
        }
        return result;
    }
};
