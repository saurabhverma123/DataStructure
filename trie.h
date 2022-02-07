#ifndef TRIE
#define TRIE
#include <bits/stdc++.h>

using namespace std;
struct Node{
    unordered_map<char, Node*> data;
    bool EOW{false};
};

void insertTrie(Node* root, string word)
{
    Node* head = root;
    for ( char ch: word)
    {
        auto iter = head->data.find(ch);
        if (iter == head->data.end())
        {
            //ch not present
            Node* next = new Node;
            head->data.insert(pair<char, Node*>(ch, next));
            head = next;
        }
        else
        {
            // ch present
            head = iter->second;
        }
    }
    head->EOW = true;
}


void runTrie()
{
    Node* root = new Node;
    insertTrie(root, "india");
    insertTrie(root, "iceland");
}

#endif // TRIE

