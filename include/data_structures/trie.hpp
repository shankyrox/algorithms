//
//  trie.hpp
//  data_structures
//
//  Created by Shashank Gupta on 31/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#ifndef trie_h
#define trie_h

#include <iostream>
#include <map>
using namespace std;

struct TrieNode {
    map<char, unique_ptr<TrieNode>> children;
    bool isLeaf;
};

class Trie {
    unique_ptr<TrieNode> root;
public:
    Trie();
    void insert(const string& word);
    bool startsWith(const string& word); // returns true if this string matches with prefix of any string in trie
    bool search(const string& word); // returns true only if complete string matches
};

struct CompressedTrieNode {
    map<char, unique_ptr<CompressedTrieNode> > children;
    string edgelabel;
    bool isLeaf;
};

class CompressedTrie {
    unique_ptr<CompressedTrieNode> root;
public:
    CompressedTrie();
    void insert(const string& word);
    bool search(const string& word) const;
    bool startsWith(const string& word) const;
};

#endif /* trie_h */
