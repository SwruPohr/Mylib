//
// Created by Swarup on 2026-05-29.
//

#ifndef OTHERS_H
#define OTHERS_H



int nonzero_strlen(const char *str);

int true_strlen(const char *str);

void reverseInPlace(char *str);

void reverseInPlace(char *str, int nonzero_len);

void reverseCopy(const char *src, char *dest);

void reverseCopy(const char *src, char *dest, int nonzero_len);

void numberToBaseNString(int num, int base, char *out);

int stringToBaseNNumber(const char *str, int len, int base);

void numberToBase10String(int num, char *out);



//assume '0' <= character <= '9'
int stringToBase10Number(const char *str, int len);

//assume '0' <= character <= '9'
int substringToBase10Number(const char *str, int start, int end);

#endif //OTHERS_H
