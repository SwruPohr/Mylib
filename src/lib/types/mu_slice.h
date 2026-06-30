#pragma once // types/slice.h

#include <stdint.h>
#include <stddef.h>

#include "../mu_error.h" // ERROR(E)

#define DEF_SLICE(T) \
typedef struct Slice_##T { \
	T *buf; \
	size_t cap; \
} Slice_##T; \
\
static inline Slice_##T Slice_##T##_from_buf(T *buf, size_t cap) { \
	return (Slice_##T){ .buf = buf, .cap = cap }; \
} \
\
static inline T Slice_##T##_get(Slice_##T array, size_t index) { \
	if (index > array.cap) {\
		ERROR(ERROR_INDEX_OUT_OF_BOUNDS); \
	} return *(array.buf + index); \
}

#define mu_Slice_get(T) Slice_##T##_get
#define mu_Slice_init(T) Slice_##T##_from_buf