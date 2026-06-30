#include <stdio.h>
#include <stdint.h>
#include <stdio.h>

#include "lib/types/mu_slice.h"
#include "lib/mu_print.h"

DEF_SLICE(int8_t);

#define pointer(T)  typeof(T *)
#define array(T, N) typeof(T [N])




// _Generic macro for printing types.
// can it differenciate conststr and string?
// maybe we never use the *char type for strings, only const strings?




int main(void) {
    int8_t x[3] = {1, 2, 3};

    Slice_int8_t y = Slice_int8_t_from_buf(x, 3);

    MUPRINT("y[0], y[1], y[2]:\n");
    print_uint(Slice_int8_t_get(y, 0));
    print_conststr(", ");
    print_uint(Slice_int8_t_get(y, 0));
    print_conststr(", ");
    print_uint(Slice_int8_t_get(y, 0));

    printf("y[0]: %i\n", Slice_int8_t_get(y, 0));
    printf("y[1]: %i\n", Slice_int8_t_get(y, 1));
    printf("y[2]: %i\n", Slice_int8_t_get(y, 2));
    


    return 0;
}