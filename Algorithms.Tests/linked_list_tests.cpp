#include "pch.h"
#include "../Algorithms/linked_list.h"

namespace algorithms
{
    TEST(linked_list, initial_state_test)
    {
        linked_list<int> ll;
        EXPECT_TRUE(ll.empty());
    }

    TEST(linked_list, push_back_test)
    {
        linked_list<int> ll;
        ll.push_back(4);
        ll.push_back(3);
        ll.push_back(2);
        EXPECT_FALSE(ll.empty());
        EXPECT_EQ(ll.size(), 9);
    }
}