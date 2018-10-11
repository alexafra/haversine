#include "haversine.h"

double radians_to_degrees (double radianAngle)
{
    double degreeAngle = radianAngle * 180.0 / M_PI;
    return degreeAngle;
}
