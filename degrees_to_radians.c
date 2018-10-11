#include "haversine.h"

double degrees_to_radians (double degreeAngle)
{
    double radianAngle = degreeAngle / 180.0 * M_PI;
    return radianAngle;
}
