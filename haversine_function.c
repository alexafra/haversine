#include "haversine.h"

double haversine_function(double latitude1, double longitude1, double latitude2, double longitude2)
{
    double lat1 = degrees_to_radians(latitude1);
    double lat2 = degrees_to_radians(latitude2);
    double lon1 = degrees_to_radians(longitude1);
    double lon2 = degrees_to_radians(longitude2);
        
    double t1 = sin( (lat2 - lat1) / 2); 
    double t2 = t1 * t1; 

    double t3 = sin ( (lon2 - lon1) / 2); 
    double t4 = t3 * t3; 
    double t5 = cos(lat1) * cos(lat2) * t4; 

    double t6 = t2 + t5; 
    double t7 = sqrt(t6);
    double t8 = 2 * EARTH_R * asin(t7);
    return t8; 
}
