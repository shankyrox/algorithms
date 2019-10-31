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
#include "fenwick_tree.hpp"

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

TEST_CASE("Trie functionality test") {
    Trie trie;
    
    SECTION("Returns true if string present in trie") {
        trie.insert("hell");
        trie.insert("hello");
        REQUIRE(trie.startsWith("hell") == true);
        REQUIRE(trie.startsWith("hello") == true);
    }
    
    SECTION("Returns false if string not present in trie") {
        REQUIRE(trie.startsWith("hell") == false);
        trie.insert("hell");
        REQUIRE(trie.startsWith("hello") == false);
    }
    
    SECTION("Returns correct value for search") {
        trie.insert("hello");
        REQUIRE(trie.search("hell") == false);
        trie.insert("hell");
        REQUIRE(trie.search("hell") == true);
    }
}

TEST_CASE("Compressed tries functionality test") {
    CompressedTrie ct;
    ct.insert("facepalm");
    ct.insert("face");
    
    SECTION("Returns correct value for search") {
        REQUIRE(ct.search("face") == true);
        REQUIRE(ct.search("facebook") == false);
    }
    
    SECTION("Returns correct value for prefix") {
        REQUIRE(ct.startsWith("face") == true);
        REQUIRE(ct.startsWith("facep") == true);
        REQUIRE(ct.startsWith("facx") == false);
    }
}

TEST_CASE("Fenwick Tree functionality test") {
    vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    BIT bit(arr);
    
    SECTION("Returns correct sum of first n values") {
        REQUIRE(bit.getSum(5) == 12);
        REQUIRE(bit.getSum(2) == 4);
    }
    
    SECTION("Returns correct sum after update operation") {
        bit.update(3, 6);
        REQUIRE(bit.getSum(2) == 4);
        REQUIRE(bit.getSum(5) == 18);
    }
}
