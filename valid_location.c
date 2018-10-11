#include "haversine.h"

bool valid_location (double latitude, double longitude) 
{
    if (latitude < MIN_LAT || latitude > MAX_LAT || longitude < MIN_LON || longitude > MAX_LON) {
        return false;
    } else {
        return true;
    }   
}

