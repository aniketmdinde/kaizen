#pragma once

#include "kaizen.h" // test using generated header: jump with the parachute you folded

void test_forward_list_of_strings()
{
    BEGIN_SUBTEST;
    zen::forward_list<zen::string> x = { "1", "2", "3", "4" };
    x.push_front("0");

    ZEN_EXPECT(x.contains("0"));
    ZEN_EXPECT(zen::is_empty(x) == x.is_empty());
}

void main_test_forward_list()
{
    BEGIN_TEST;

    const auto r = []{ return zen::random_int(); };

    zen::forward_list<int> x = { r(), r(), r(), r(), r()};
    x.push_front(777);

    ZEN_EXPECT(x.contains(777));
    ZEN_EXPECT(zen::is_empty(x) == x.is_empty());

    test_forward_list_of_strings();
}