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
    void insert(const string& s);
    bool find_prefix(const string& s); // returns true if this prefix matches with any string in trie
    bool find_string(const string& s); // returns true only if complete string matches
};

#endif /* trie_h */
