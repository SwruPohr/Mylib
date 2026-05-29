//
// Created by Swarup on 2026-05-29.
//

#ifndef MODULI_H
#define MODULI_H

short up(double a);
short down(double a);
short inf(double a);
short zero(double a);
short nearest_up(double a);
short nearest_down(double a);
short nearest_inf(double a);
short nearest_zero(double a);

short modulus(short (*custom_round)(double), short a, short b);

short mod_euclidean(short a, short b);



#endif //MODULI_H
