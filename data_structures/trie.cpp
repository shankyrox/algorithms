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

bool Trie::startsWith(const string &s) {
    TrieNode* curr_node = root.get();
    for(auto ch: s) {
        if(curr_node->children.find(ch) == curr_node->children.end()) return false;
        curr_node = curr_node->children[ch].get();
    }
    return true;
}

bool Trie::search(const string &s) {
    TrieNode* curr_node = root.get();
    for(auto ch: s) {
        if(curr_node->children.find(ch) == curr_node->children.end()) return false;
        curr_node = curr_node->children[ch].get();
    }
    return curr_node->isLeaf;
}


/* ---------------- CompressedTrie ---------------- */

CompressedTrie::CompressedTrie() {
    root = make_unique<CompressedTrieNode>();
}

void CompressedTrie::insert(const string &word) {
    if(word == "") return;
    // Case 1 (easiest) : No matching edge present, just insert entire word
    if(root->children.find(word[0]) == root->children.end()) {
        root->children[word[0]] = make_unique<CompressedTrieNode>();
        CompressedTrieNode* curr_node = root->children[word[0]].get();
        curr_node->edgelabel = word;
        curr_node->isLeaf = true;
    }
    else {
        size_t i=0, j=0;
        string word_to_cmp;
        CompressedTrieNode* curr_node = root->children[word[0]].get();
        while(i < word.length()) {
            word_to_cmp = curr_node->edgelabel;
            j = 0;
            while(i<word.length() && j<word_to_cmp.length() && word[i] == word_to_cmp[j]) {
                i++;
                j++;
            }
            // Case 2 : i complete
            if(i == word.length()) {
                // Case 2a : j also complete - mark this as leaf node
                if(j == word_to_cmp.length()) {
                    curr_node->isLeaf = true;
                }
                // Case 2b : j remaining - split word into 2
                else {
                    string rem_word = word_to_cmp.substr(j);
                    unique_ptr<CompressedTrieNode> newnode = make_unique<CompressedTrieNode>();
                    newnode->edgelabel = rem_word;
                    newnode->isLeaf = curr_node->isLeaf;
                    newnode->children = std::move(curr_node->children);
                    
                    curr_node->edgelabel = word_to_cmp.substr(0,j);
                    curr_node->isLeaf = true;
                    curr_node->children.clear();
                    curr_node->children[rem_word[0]] = std::move(newnode);
                }
            }
            // Case 3 : i not complete, j complete
            else if( j == word_to_cmp.length()) {
                // Case 3(a) : no remaining edge
                if (curr_node->children.find(word[i]) == curr_node->children.end()) {
                    curr_node->children[word[i]] = make_unique<CompressedTrieNode>();
                    curr_node = curr_node->children[word[i]].get();
                    curr_node->edgelabel = word.substr(i);
                    curr_node->isLeaf = true;
                    i = word.length();
                }
                else {
                    // Case 3(b) : remaining edge - continue with matching
                    curr_node = curr_node->children[word[i]].get();
                }
            }
            // Case 4 : i not complete & j not complete. Split into two and insert
            else {
                string rem_word_i = word.substr(i);
                string rem_word_j = word_to_cmp.substr(j);
                string match_word = word_to_cmp.substr(0,j);
                
                unique_ptr<CompressedTrieNode> newnode = make_unique<CompressedTrieNode>();
                newnode->isLeaf = curr_node->isLeaf;
                newnode->children = std::move(curr_node->children);
                newnode->edgelabel = rem_word_j;
                
                unique_ptr<CompressedTrieNode> newnode2 = make_unique<CompressedTrieNode>();
                newnode2->isLeaf = true;
                newnode2->edgelabel = rem_word_i;
                
                curr_node->isLeaf = false;
                curr_node->edgelabel = match_word;
                curr_node->children.clear();
                curr_node->children[rem_word_j[0]] = std::move(newnode);
                curr_node->children[rem_word_i[0]] = std::move(newnode2);
                
                i = word.length();
            }
        }
    }
}

bool CompressedTrie::search(const string &word) const {
    size_t i=0, j=0;
    string word_to_match;
    if(word == "") return false;
    if(root->children.find(word[0]) == root->children.end()) {
        return false;
    }
    bool ispresent = false;
    CompressedTrieNode* curr_node = root->children[word[0]].get();
    while (i < word.length()) {
        j=0;
        word_to_match = curr_node->edgelabel;
        while(i < word.length() && j < word_to_match.length() && word[i] == word_to_match[j]) {
            i++;
            j++;
        }
        // Case 1 : completed matching
        if( i == word.length()) {
            if(j == word_to_match.length() && curr_node->isLeaf == true) ispresent = true;
            else ispresent = false;
        }
        // Case 2 : match remaining
        else {
            // Case 2a: j completed
            if( j == word_to_match.length()) {
                // Case 2aa: nowhere to go
                if(curr_node->children.find(word[i]) == curr_node->children.end()) {
                    ispresent = false;
                    break;
                }
                else {
                    // case 2ab : continue matching
                    curr_node = curr_node->children[word[i]].get();
                }
            }
            // case 2b : j remaining, no match
            else {
                ispresent = false;
                break;
            }
        }
    }
    return ispresent;
}


bool CompressedTrie::startsWith(const string &word) const {
    size_t i=0, j=0;
    string word_to_match;
    if(word == "") return false;
    if(root->children.find(word[0]) == root->children.end()) {
        return false;
    }
    bool ispresent = false;
    CompressedTrieNode* curr_node = root->children[word[0]].get();
    while (i < word.length()) {
        j=0;
        word_to_match = curr_node->edgelabel;
        while(i < word.length() && j < word_to_match.length() && word[i] == word_to_match[j]) {
            i++;
            j++;
        }
        // Case 1 : completed matching
        if( i == word.length()) {
            ispresent = true;
        }
        // Case 2 : match remaining
        else {
            // Case 2a: j completed
            if( j == word_to_match.length()) {
                // Case 2aa: nowhere to go
                if(curr_node->children.find(word[i]) == curr_node->children.end()) {
                    ispresent = false;
                    break;
                }
                else {
                    // case 2ab : continue matching
                    curr_node = curr_node->children[word[i]].get();
                }
            }
            // case 2b : j remaining, no match
            else {
                ispresent = false;
                break;
            }
        }
    }
    return ispresent;
}
