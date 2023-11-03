#include <vector>
#include "simpletrie.h"
using namespace std;
void testTrie(TrieSimple* trie, vector<string> diccionario){
    for(string word : diccionario)
    trie->insert(word);
    cout<<trie->toString(" ")<<endl;
    cout<<trie->search("amor")<<endl;
    cout<<trie->search("rosa")<<endl;
    trie->remove("roma");
    trie->remove("amorfo");
    cout<<trie->toString(",")<<endl;
}
int main(){
    vector<string> diccionario = {"romano", "roma", "romario", "rosario", "rata", "amor", "amorfo", "amorcito", "amiga"};
    testTrie(new TrieSimple(), diccionario);
    return 0;
}
