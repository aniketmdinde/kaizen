#pragma once

#include "kaizen.h" // test using generated header: jump with the parachute you folded

void test_priority_queue_of_strings()
{
    BEGIN_SUBTEST;
    zen::priority_queue<zen::string> x = zen::strings{ "1", "2", "3", "4" };

    x.push("0");

    ZEN_EXPECT(
        std::size(x) == 5 &&
        zen::is_empty(x) == x.is_empty()
    );
}

void test_queue_of_strings()
{
    BEGIN_SUBTEST;
    zen::queue<zen::string> x = zen::strings{ "1", "2", "3", "4" }; // queue is not directly contructible from an initializer list
    x.push("0");

    ZEN_EXPECT(zen::is_empty(x) == x.is_empty());
}

void main_test_priority_queue()
{
    BEGIN_TEST;

    zen::priority_queue<int> x(zen::ints{5, 5, 5});
    x.push(1);
    x.push(2);
    x.push(3);

    ZEN_EXPECT(
        std::size(x) == 6 &&
        zen::is_empty(x) == x.is_empty()
    );

    test_priority_queue_of_strings();
}

void main_test_queue()
{
    BEGIN_TEST;

    zen::queue<int> x;
    x.push(1);
    x.push(2);
    x.push(3);

    ZEN_EXPECT(zen::is_empty(x) == x.is_empty());

    test_queue_of_strings();
}