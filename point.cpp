#include "point.h"

Point::Point():mp_x(0), mp_y(0)
{
}

void Point::setMP(const int &x, const int &y)
{
    mp_x = x;
    mp_y = y;
}
