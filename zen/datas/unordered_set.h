// MIT License
// 
// Copyright (c) 2023 Leo Heinsaar
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <unordered_set>

#include "alpha.h" // internal; will not be included in kaizen.h

namespace zen {

///////////////////////////////////////////////////////////////////////////////////////////// zen::unordered_set

template<
    class T,
    class H = std::hash<T>,
    class E = std::equal_to<T>,
    class A = std::allocator<T>
>
class unordered_set : public std::unordered_set<T, H, E, A>, private zen::stackonly
{
public:
    using std::unordered_set<T, H, E, A>::unordered_set; // inherit constructors, has to be explicit

    bool is_empty() const { return my::empty(); }

private:
    using my = unordered_set<T, H, E, A>;
};

///////////////////////////////////////////////////////////////////////////////////////////// zen::unordered_multiset

template<
    class T,
    class H = std::hash<T>,
    class E = std::equal_to<T>,
    class A = std::allocator<T>
>
class unordered_multiset : public std::unordered_multiset<T, H, E, A>, private zen::stackonly
{
public:
    using std::unordered_multiset<T, H, E, A>::unordered_multiset; // inherit constructors, has to be explicit

    bool is_empty() const { return my::empty(); }

private:
    using my = unordered_multiset<T, H, E, A>;
};

} // namespace zen