#pragma once

#include "kaizen.h" // test using generated header: jump with the parachute you folded

#include "../internal.h"

void test_deque_of_strings()
{
    BEGIN_SUBTEST;
    zen::deque<zen::string> x = { "1", "2", "3", "4" };
    x.push_back("0");

    ZEN_EXPECT(silent_print(x) == "[1, 2, 3, 4, 0]");
    ZEN_EXPECT(x.contains("0"));
    ZEN_EXPECT(zen::is_empty(x) == x.is_empty());
}

void main_test_deque()
{
    BEGIN_TEST;

    zen::deque<int> q;
    zen::generate_random(q);
    q.push_back(777);

    ZEN_EXPECT(q.contains(777));
    ZEN_EXPECT(zen::to_string(q).contains("777"));
    ZEN_EXPECT(zen::is_empty(q) == q.is_empty());

    test_deque_of_strings();
}