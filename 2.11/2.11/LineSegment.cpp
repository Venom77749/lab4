#include "LineSegment.h"
#include <algorithm>

void LineSegment::normalize(double& x, double& y)
{
    if (x > y) std::swap(x, y);
}

LineSegment::LineSegment()
{
    x = 0;
    y = 0;
}

LineSegment::LineSegment(double x, double y)
{
    normalize(x, y);
    this->x = x;
    this->y = y;
}

LineSegment::LineSegment(double x)
{
    this->x = x;
    y = x;
}

bool LineSegment::intersects(const LineSegment& other) const
{
    double left = std::max(x, other.x);
    double right = std::min(y, other.y);
    return left <= right;
}

std::ostream& operator<<(std::ostream& os, const LineSegment& s)
{
    os << "[" << s.x << "; " << s.y << "]";
    return os;
}

double LineSegment::operator!() const {
    return y - x;
}

LineSegment& LineSegment::operator++() {
    x -= 1;
    y += 1;
    return *this;
}

LineSegment LineSegment::operator++(int) {
    LineSegment temp = *this;
    ++(*this);
    return temp;
}

LineSegment::operator int() const {
    return static_cast<int>(x);
}

LineSegment::operator double() const {
    return y;
}

LineSegment LineSegment::operator-(int value) const {
    return LineSegment(x - value, y);
}

bool LineSegment::operator<(const LineSegment& other) const {
    return this->intersects(other);
}