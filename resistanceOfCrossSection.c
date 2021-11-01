#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1416

/*
The idea of this code is to use the given Ix, Iy and Ixy values
to calculate the min/max angle of rotation for the crossSection
alpha and how much it is able to bend shown by elliptical
components i1, and i2
*/

float radToDegree( float );
float angle( float, float, float);
float *main_I( float, float, float );
float *elipse_i( float *, float );

void result( float, float, float, float );

/*==========================================*/

int main() {
    float A, Ix, Iy, Ixy;

    printf("Insert value for A: ");
        scanf("%f", &A);
    printf("Insert value for Ix: ");
        scanf("%f", &Ix);
    printf("Insert value for Iy: ");
        scanf("%f", &Iy);
    printf("Insert value for Ixy: ");
        scanf("%f", &Ixy);

    result( Ix, Iy, Ixy, A );

    return 0;
}

/*==========================================*/

float radToDegree( float alpha ) {
    return alpha * ( 180 / PI );
}

float angle( float Ix, float Iy, float Ixy ) {
    return radToDegree( atan( ( -2 * Ixy )/( Ix - Iy ) ) / 2 );
}

float *main_I( float Ix, float Iy, float Ixy ) {
    static float I_arr[2];
    I_arr[0] = ( ( Ix + Iy ) / 2 ) + sqrt( ( Ix - Iy ) * ( Ix - Iy ) + 4 * ( Ixy * Ixy ) ) / 2;
    I_arr[1] = ( ( Ix + Iy ) / 2 ) - sqrt( ( Ix - Iy ) * ( Ix - Iy ) + 4 * ( Ixy * Ixy ) ) / 2;

    return I_arr;
}

float *elipse_i( float *arr, float area ) {
    static float i_arr[2];

    i_arr[0] = sqrt( arr[0] / area );
    i_arr[1] = sqrt( arr[1] / area );

    return i_arr;
}

void result( float Ix, float Iy, float Ixy, float A ) {
    float *I_arr = main_I( Ix, Iy, Ixy );
    float *i_arr = elipse_i( I_arr, A );

    printf("\nThe primary axis is: %c", Ix > Iy ? 'x' : 'y' );
    printf("\nThe angle: \n\t%f degrees", angle( Ix, Iy, Ixy ) );
    printf("\nPrimary axis: \n\tI1 = %f \n\tI2 = %f", I_arr[0], I_arr[1] );
    printf("\nElipse values: \n\ti1 = %f \n\ti2 = %f\n", i_arr[0], i_arr[1] );
}

