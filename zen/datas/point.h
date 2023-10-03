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

#include <utility>

namespace zen {

///////////////////////////////////////////////////////////////////////////////////////////// zen::point2d

class point2d : public std::pair<double, double> {
public:
    point2d(double xc = 0.0, double yc = 0.0)    : std::pair<double, double>(xc, yc)       {}
    point2d(const std::pair<double, double>&  p) : std::pair<double, double>(p)            {}
    point2d(      std::pair<double, double>&& p) : std::pair<double, double>(std::move(p)) {}

    // Allows conversions from other arithmetic pair types
    template <class T, class U, typename std::enable_if<
                                         std::is_arithmetic_v<T> &&
                                         std::is_arithmetic_v<U>, int>::type = 0>
    point2d(const std::pair<T, U>& p)
        : std::pair<double, double>(
            static_cast<double>(p.first),
            static_cast<double>(p.second)
        )
    {}

    point2d& operator=(const std::pair<double, double>& p) {
        this->first  = p.first;
        this->second = p.second;
        return *this;
    }

    point2d& operator=(std::pair<double, double>&& p) {
        this->first  = std::move(p.first);
        this->second = std::move(p.second);
        return *this;
    }

    // Returning reference to the member is deliberate since
    // x() and y() are simply meant to be a convenience alias
    // interface to avoid writing '.first' or '.second' 
    constexpr double& x()       { return this->first;  }
    constexpr double& y()       { return this->second; }
    constexpr double  x() const { return this->first;  }
    constexpr double  y() const { return this->second; }

    friend point2d operator+(const point2d& a, const point2d& b) { return point2d(a.x() + b.x(), a.y() + b.y()); }
    friend point2d operator-(const point2d& a, const point2d& b) { return point2d(a.x() - b.x(), a.y() - b.y()); }
    friend point2d operator*(const point2d& a, const double   k) { return point2d(a.x() * k, a.y() * k); }
    friend bool   operator==(const point2d& a, const point2d& b) { return a.x() == b.x() && a.y() == b.y(); }
    friend bool   operator!=(const point2d& a, const point2d& b) { return !(a == b); }
    friend point2d operator/(const point2d& a, double k) {
        if (k != 0) {
            return point2d(a.x() / k, a.y() / k);
        } else {
            throw std::invalid_argument("ATTEMPTED DIVISION BY ZERO FOR point2d");
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////////// zen::point3d

class point3d : public point2d {
public:
    point3d(double xc = 0.0, double yc = 0.0, double zc = 0.0) : point2d(xc, yc), z_(zc) {}

    point3d(const point2d& p, double zc = 0.0) : point2d(p), z_(zc) {}

    template <class T, class U, class V, typename std::enable_if<
                                                  std::is_arithmetic_v<T> &&
                                                  std::is_arithmetic_v<U> &&
                                                  std::is_arithmetic_v<V>, int>::type = 0>
    point3d(const std::tuple<T, U, V>& p)
        : point2d(std::get<0>(p), std::get<1>(p)),
           z_(static_cast<double>(std::get<2>(p)))
    {}

    point3d& operator=(const std::pair<double, double>& p) {
        point2d::operator=(p);            // inherit behavior for x and y
        z_ = 0;                           // reset to default
        return *this;
    }

    point3d& operator=(std::pair<double, double>&& p) {
        point2d::operator=(std::move(p)); // inherit behavior for x and y
        z_ = 0;                           // reset to default
        return *this;
    }

    // Returning reference to the member is deliberate since
    // x(), y() and z() are simply meant to be a convenience alias
    // interface to avoid writing '->first', '->second' or '->z_'
    constexpr double& z()       { return z_; }
    constexpr double  z() const { return z_; }

    friend point3d operator+(const point3d& a, const point3d& b) { return point3d(a.x() + b.x(), a.y() + b.y(), a.z() + b.z()); }
    friend point3d operator-(const point3d& a, const point3d& b) { return point3d(a.x() - b.x(), a.y() - b.y(), a.z() - b.z()); }
    friend point3d operator*(const point3d& a, const double k)   { return point3d(a.x() * k, a.y() * k, a.z() * k); }
    friend bool   operator==(const point3d& a, const point3d& b) { return a.x() == b.x() && a.y() == b.y() && a.z() == b.z(); }
    friend bool   operator!=(const point3d& a, const point3d& b) { return !(a == b); }

    friend point3d operator/(const point3d& a, double k) {
        if (k != 0) {
            return point3d(a.x() / k, a.y() / k, a.z() / k);
        }
        else {
            throw std::invalid_argument("ATTEMPTED DIVISION BY ZERO FOR point3d");
        }
    }

private:
    double z_;
};

// ------------------------------------------------------------------------------------------ aliases

using point = point2d;

} // namespace zen