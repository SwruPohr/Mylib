#pragma once // lib/error.h

#define OK 0
#define ERROR_INDEX_OUT_OF_BOUNDS 1
#define ERROR_TEST_FAIL 2

#ifndef __ERROR__PROPOGATE__
#define ERROR(E) return E
#endif