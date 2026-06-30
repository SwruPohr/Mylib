Info: the language defined below is not rust, its my own pseudo-code.

# First, an array in the program stack.

```rust
x : [_]i32 = [0, 1];
```

```c
#import <types/int.h>
i32 x[2] = {0, 1};
```

# Now we point to It.

```rust
y : &i32 = x&;
ya : &[_]i32 = x&;
/*
y  : &i32      = x&.as<&i32>;
ya : &[_]i32  = x&.as<&[_]i32>;
*/
```

```c
i32 (*y)[2] = &x;
i32 *y = x;
```

Small note:
C has no "infer array size" syntax.

Important Note:
In C, when you use `x` in an expression that needs a pointer, it decays:

`x: [_]i32  ->  x[0]& : &i32`, or
`i32 x[] -> i32 *x`

So in C, it is better to write what is in line 22.
I.e. y points to the first element of the array (x[0]).

One reason is because:

`i32 (*y)[2] = &x;` means that `y` points to the array itself, where the pointer arithmetic done to it will move it by `@sizeof([2]i32)`.


# Lets move the array to the heap.

Another reason to have some kind of array decay (wether explicit or implicit), is that malloc cannot return a comptime type based on runtime size of the object being allocated.

```rust
w : usize = /* user input value */ ;

za : &[??]i32 = malloc<i32>(w);
// w is not constant, we do not know size of the array

z : &i32 = malloc<i32>(w);
```

```c
#import <stdlib.h>

usize w = /* user input value */ ;

i32 (*z)[??] = malloc(w * sizeof(i32);
// w is not constant, we do not know size of the array

i32 *z = malloc(w * sizeof(i32));
```
z points to a heap array of length w.


# Now, It is time to implement the array-like types.


The full name of all array-like types are:

update semantics / indexing discipline
Unmanaged: does not implement `set` operations, or similar to a weak pointer.
LI/O*: last in/out.
FI/O*: first in/out.
MI/O*: insert/delete
Arbritary: do more things (if those are possible?)

Indexing & capacity model:
normal**: fixed-length and fixed-capacity
fixed-length (flen): every element in the structure is valid, or len = cap.
fixed-capacity (fcap): the capacity is known at compile time.
dynamic*** (dyn): neither fixed-length nor fixed-capacity.

kind:
array: an array type.

\* while lets say a List allows for deleting the first element, because it rearranges the whole list, and is the same operation as MI/O, it is thus classified without FI/O.
\*\* only the array is "normal", else these types are useless.
\*\*\* dynamic is my own meaning, since the original meaning of "goes on the heap" allowed for fuzzy sets that include the infamous `fixed capacity dynamic array` from odin.


## First comes the slice, or the unmanaged flen array.


```rust
struct Slice<T> (
	buf: *T,
	cap: usize,
);
fn Slice::from_buf<T>(buf : &T, cap : usize): Slice<T> {
	return (buf, cap).as<Slice<T>>;
}
```

```c
#include "type/int.h"

#define DEF_SLICE(T) \
typedef struct Slice_##T { \
	T *buf; \
	size_t cap; \
} Slice_##T; \
static inline Slice_##T Slice_##T##_from_buf(T *buf, size_t cap) { \
	return (Slice_##T){ .buf = buf, .cap = cap }; \
}
```

