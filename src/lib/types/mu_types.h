#pragma once // types/types.h

#include <stdint.h>
#include <stddef.h>

#ifdef _NONZERO_TYPES

// base "nonzero" integers
typedef uint8_t   uint8nz_t;
typedef uint16_t  uint16nz_t;
typedef uint32_t  uint32nz_t;
typedef uint64_t  uint64nz_t;

typedef int8_t    int8nz_t;
typedef int16_t   int16nz_t;
typedef int32_t   int32nz_t;
typedef int64_t   int64nz_t;

// size/type and max
typedef size_t    sizenz_t;
typedef uintmax_t uintmaxnz_t;
typedef intmax_t  intmaxnz_t;

// min-width and corresponding "min" types (signed/unsigned)
typedef uint8_t   uintmin8nz_t;
typedef uint16_t  uintmin16nz_t;
typedef uint32_t  uintmin32nz_t;
typedef uint64_t  uintmin64nz_t;

typedef int8_t    intmin8nz_t;
typedef int16_t   intmin16nz_t;
typedef int32_t   intmin32nz_t;
typedef int64_t   intmin64nz_t;

// intptr/uintptr
typedef uintptr_t uintpnz_t;
typedef intptr_t  intpnz_t;

// fast types
typedef uint_fast8_t  uintfast8nz_t;
typedef uint_fast16_t uintfast16nz_t;
typedef uint_fast32_t uintfast32nz_t;
typedef uint_fast64_t uintfast64nz_t;

typedef int_fast8_t   intfast8nz_t;
typedef int_fast16_t  intfast16nz_t;
typedef int_fast32_t  intfast32nz_t;
typedef int_fast64_t  intfast64nz_t;

#endif
