#include <math.h>
//#include <stdlib.h>
#include "moduli.h"

short custom_abs(short a) {
    if (a < 0 ) return -a;
    return a;
}

// Round up (ceil)
short up(double a) {
    if (a != 0) return (short)ceil(a);
    return 0;
}

// Round down (floor)
short down(double a) {
    if (a != 0) return (short)floor(a);
    return 0;
}

// Round towards infinity
short inf(double a) {
    if (a > 0) return up(a);
    if (a < 0) return down(a);
    return 0;
}

// Round towards zero (truncate)
short zero(double a) {
    if (a > 0) return down(a);
    if (a < 0) return up(a);
    return 0;
}

// Round towards nearest up for 0.5 case
short nearest_up(double a) {
    if (a != 0) return (short)round(a);
    if (a == 0) return 0;
}

// Round towards nearest down for 0.5 case
short nearest_down(double a) {
    if (a != 0) return (short)round(a - 0.5);
    if (a == 0) return 0;
}

// Round towards nearest infinity for 0.5 case
// negatives round down for 0.5
// positives round up for 0.5
short nearest_inf(double a) {
    if (a < 0 ) return nearest_down(a);
    if (a > 0 ) return nearest_up(a);
    if (a == 0) return 0;
}

// Round towards nearest zero for 0.5 case
short nearest_zero(double a) {
    if (a < 0 ) return nearest_up(a);
    if (a > 0 ) return nearest_down(a);
    if (a == 0) return 0;
}


// General modulus using a rounding function
short modulus(short (*custom_round)(double), short a, short b) {
    //if (b == 0) exit(1);
    if (a == 0) return 0;
    return a - b * custom_round((double)a / b);
}

// Euclidean modulus (just floor)
short mod_euclidean(short a, short b) {
    //if (b == 0) exit(1);
    if (a == 0) return 0;
    short s = custom_abs(b);
    return a - s * down(a / s);
}
