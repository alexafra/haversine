#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//

//Declare Global Preprocessor constants

#define MIN_LAT         -90.0
#define MAX_LAT         90.0
#define MIN_LON         -180.0
#define MAX_LON         180.0

#define EARTH_R         6372797

//Declare Global Functions

extern double degrees_to_radians (double);
extern double radians_to_degrees (double);
extern double haversine_function(double, double, double, double);
extern bool valid_location (double, double);

//Declare Global Variables

