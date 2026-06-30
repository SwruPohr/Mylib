#pragma once // lib/print.h

#import <stdio.h>

#import "mu_error.h"
#import "mu_string.h"



#define MUPRINT(x) _Generic((x), \
    const char *: print_conststr, \
    char *      : print_chararr_unsafe,  \
    String : print_StringSlice, \
    intmax_t    : print_intN_t, \
    uintmax_t   : print_uintN_t, \
    default:      ERROR(ERROR_INVALID_TYPE) \
)(x)

static inline void print_conststr(const char *string) {
    for (size_t i = 0; string[i]; i++) {
        putchar(string[i]);
    }
}

static inline void print_chararr_unsafe(char *string) {
    for (size_t i = 0; string[i]; i++) {
        putchar(string[i]);
    }
}

static inline void print_StringSlice(String string) {
    for (size_t i = 0; i < string.cap; i++) {
        putchar(string.buf[i]);
    }
}

static inline void print_uintN_t(uintmax_t x) {
    char buf[3 * (size_t)sizeof(x) + 1];
    size_t i = 0;

    if (x == 0) {
        putchar('0');
        return;
    }

    while (x > 0) {
        buf[i++] = (char)('0' + (x % 10u));
        x /= 10u;
    }

    while (--i >= 0) {
        putchar(buf[i]);
    }
}

static inline void print_intN_t(intmax_t x) {
    char buf[3 * (size_t)sizeof(x) + 1];
    size_t i = 0;

    if (x == 0) {
        putchar('0');
        return;
    }

    if (x < 0) {
    	putchar('-');
    	x = -x;
    }

    while (x > 0) {
        buf[i++] = (char)('0' + (x % 10));
        x /= 10;
    }

    while (--i >= 0) {
        putchar(buf[i]);
    }
}