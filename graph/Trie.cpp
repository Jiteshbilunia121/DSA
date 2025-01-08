#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    Node* links[26];
    bool flag;

public:
    Node() {
        for (int i = 0; i < 26; ++i) {
            links[i] = nullptr;
        }
        flag = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool isPrefix(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }

    ~Trie() {
        // Add destructor logic here if needed for cleanup
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("apxl");
    cout << (trie.search("apple") ? "Found" : "Not Found") << endl;  // Output: Found
    cout << (trie.search("app") ? "Found" : "Not Found") << endl;    // Output: Not Found
    cout << (trie.isPrefix("app") ? "Prefix Exists" : "No Prefix") << endl;  // Output: Prefix Exists

    trie.insert("app");
    cout << (trie.search("app") ? "Found" : "Not Found") << endl;    // Output: Found

    return 0;
}

