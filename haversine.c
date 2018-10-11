#include "haversine.h"

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
    printf("distance = %fm\n", haversine_function(latitude1, longitude1, latitude2, longitude2));
    return EXIT_SUCCESS;
}
