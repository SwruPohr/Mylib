#pragma once

#include <stdint.h>
const int32_t x = 2;

#define OPTION_INIT(T) {
	enum {Some, None} x;
	union {void, T} x;
} OPTION_##T;