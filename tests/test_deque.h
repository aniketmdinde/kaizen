#pragma once

#include <cassert>
#include "../build/kaizen.h" // test using generated header

void sanitest_deque()
{
    zen::log("BEGIN TEST------------------------------------------------", __func__);

    zen::deque<int> q;
    zen::populate_random(q);
    q.push_back(777);

    zen::log(q);

    ZEN_EXPECT(q.contains(777));
}