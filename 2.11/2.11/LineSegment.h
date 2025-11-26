#pragma once

#include <iostream>

class LineSegment
{
private:
    double x;
    double y;

    static void normalize(double& x, double& y);

public:
    LineSegment();
    LineSegment(double x, double y);
    LineSegment(double x);

    bool intersects(const LineSegment& other) const;

    friend std::ostream& operator<<(std::ostream& os, const LineSegment& s);

    double operator!() const;
    LineSegment& operator++();
    LineSegment operator++(int);
    operator int() const;          
    explicit operator double() const;
    LineSegment operator-(int value) const;
    bool operator<(const LineSegment& other) const;
};