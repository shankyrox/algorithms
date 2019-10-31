//
//  trie.cpp
//  data_structures
//
//  Created by Shashank Gupta on 31/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#include "trie.hpp"

using namespace std;

Trie::Trie() {
    root = make_unique<TrieNode>();
    root->isLeaf = true;
}

void Trie::insert(const string& s) {
    if (s=="") return ;
    TrieNode* curr_node = root.get();
    curr_node->isLeaf = false;
    for(auto ch: s) {
        if (curr_node->children.find(ch) == curr_node->children.end()) {
            curr_node->children[ch] = make_unique<TrieNode>();
        }
        curr_node = curr_node->children[ch].get();
    }
    curr_node->isLeaf = true;
}

bool Trie::find_string(const string &s) {
    TrieNode* curr_node = root.get();
    for(auto ch: s) {
        if(curr_node->isLeaf == true || curr_node->children.find(ch) == curr_node->children.end()) return false;
        curr_node = curr_node->children[ch].get();
    }
    return true;
}
