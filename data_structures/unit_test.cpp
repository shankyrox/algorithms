//
//  unit_test.cpp
//  data_structures
//
//  Created by Shashank Gupta on 26/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "heap.hpp"
#include "segment_tree.h"
#include "disjoint_ds.hpp"
#include "trie.hpp"

TEST_CASE("Test functionality of SegmentTrees", "[SegmentTree]") {
    SegmentTree st(std::vector<int>{1, 3, 5, 7, 9, 11});
    
    SECTION("Works well for different queries") {
        REQUIRE(st.query(0, 0) == 1);
        REQUIRE(st.query(40, 50) == INT_MIN);
    }
    
    SECTION("Works well for different queries after update") {
        st.update(0, 20);
        REQUIRE(st.query(0, 1) == 20);
        REQUIRE(st.query(0, 3) == 20);
        REQUIRE(st.query(1, 4) == 9);
        REQUIRE(st.query(1, 5) == 11);
    }
}

TEST_CASE("Heap functionality test", "Heap") {
    Heap heap(std::vector<int> {5, 7, 4, 20, 10, 11, 9});
    
    SECTION("Returns correct element from the top") {
        REQUIRE(heap.top() == 20);
    }
    
    SECTION("Able to push element successfully in heap") {
        heap.push(40);
        REQUIRE(heap.top() == 40);
    }
    
    SECTION("Able to pop element successfully from heap") {
        REQUIRE(heap.top() == 20);
        heap.pop(); REQUIRE(heap.top() == 11);
        heap.pop(); REQUIRE(heap.top() == 10);
        heap.pop(); REQUIRE(heap.top() == 9);
        heap.pop(); REQUIRE(heap.top() == 7);
    }
}

TEST_CASE("Disjoint Data Structures functionality test", "[DijsointDS]") {
    DisjointDS ds(10);
    
    SECTION("Verify union find_string operations") {
        REQUIRE(ds.Find(0, 1) == false);
        ds.Union(1, 2);
        ds.Union(3, 4);
        ds.Union(4, 5);
        ds.Union(5, 7);
        ds.Union(8, 9);
        REQUIRE(ds.Find(8, 9) == true);
        REQUIRE(ds.Find(5, 3) == true);
        REQUIRE(ds.Find(0, 8) == false);
        ds.Union(9, 3);
        REQUIRE(ds.Find(8, 4) == true);
    }
}

TEST_CASE("Tests functionality of Trie") {
    Trie trie;
    
    SECTION("Returns true if string present in trie") {
        trie.insert("hello");
        REQUIRE(trie.find_string("hell") == true);
    }
    
    SECTION("Returns false if string not present in trie") {
        REQUIRE(trie.find_string("hell") == false);
        trie.insert("hell");
        REQUIRE(trie.find_string("hello") == false);
    }
}
