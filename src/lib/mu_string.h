#pragma once // mu_string.h


typedef struct {
    char *buf;
    size_t cap;
} Slice_char_t;

typedef Slice_char_t String;