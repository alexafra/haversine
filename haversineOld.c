#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#define MIN_LAT         -90.0
#define MAX_LAT         90.0
#define MIN_LON         -180.0
#define MAX_LON         180.0

#define EARTH_R         6372797

double degrees_to_radians (double degreeAngle)
{
    double radianAngle = degreeAngle / 180.0 * M_PI;
    return radianAngle;
}

double radians_to_degrees (double radianAngle) 
{
    double degreeAngle = radianAngle * 180.0 / M_PI;
    return degreeAngle;
}

bool valid_location (double latitude, double longitude) 
{
    if (latitude < MIN_LAT || latitude > MAX_LAT || longitude < MIN_LON || longitude > MAX_LON) {
        return false;
    } else {
        return true;
    }
}

double haversine(double latitude1, double longitude1, double latitude2, double longitude2) 
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

/* 
    Main will check the number of arguments. Keep most code outside of main.
*/
int main (int argc, char *argv[]) 
{
    if(argc != 5) {
        fprintf(stderr, "Incorrect number of arguments\n");
        exit(EXIT_FAILURE);
    }
    
    double latitude1 = atof(argv[1]);
    double longitude1 = atof(argv[2]);
    double latitude2 = atof(argv[3]);
    double longitude2 = atof(argv[4]);
    
    if (!valid_location(latitude1, longitude1) ) {
        fprintf(stderr, "Invalid first location\n");
        exit(EXIT_FAILURE);
    }

    if (!valid_location(latitude2, longitude2)) { 
        fprintf(stderr, "Invalid first location\n");
        exit(EXIT_FAILURE);
    }
    printf("distance = %fm\n", haversine(latitude1, longitude1, latitude2, longitude2));
    return EXIT_SUCCESS;
}



/* 
   First command-line argument is degrees to radians.
   Second command-line argument is radians to degrees.
*/

/*
int main (int argc, char *argv[])
{
    double initialDegrees;
    double initialRadians;
    double finalDegrees;
    double finalRadians;

    if (argc != 3) {
        fprintf(stderr, "Please input two command-line arguments.\n");
        fprintf(stderr, "The first in degrees, the second in radians.\n");
        exit(EXIT_FAILURE);
    }

    initialDegrees = atof(argv[1]);
    initialRadians = atof(argv[2]);

    finalDegrees = radians_to_degrees(initialRadians);
    finalRadians = degrees_to_radians(initialDegrees);

    printf("%f degrees is converted to %f radians\n", initialDegrees, finalRadians);
    printf("%f radians is converted to %f degrees\n", initialRadians, finalDegrees);

    return EXIT_SUCCESS;
}
*/
