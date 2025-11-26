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
