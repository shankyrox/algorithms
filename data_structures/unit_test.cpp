//
//  unit_test.cpp
//  data_structures
//
//  Created by Shashank Gupta on 26/10/19.
//  Copyright © 2019 Shashank Gupta. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "segment_tree.h"

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
