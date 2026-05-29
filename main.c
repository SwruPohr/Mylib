#include <stdio.h>

void scanit (int* f, int* i, int* l, int* r);
void fillit (int* array, int l, int i);
int mathit (int* f, int* i, int* l, int* r, int* list);

int f, i, l, r;
int* factor = &f;
int* initial = &i;
int* length = &l;
int* repeats = &r;
int* list;

int main() {
  scanit(factor, initial, length, repeats);

  int array[*length];
  list = (int*) &array;

  fillit(list, *length, *initial);
  mathit(factor, initial, length, repeats, list);
  printf("%d", *initial);

  return 0;
} 

void scanit (int* f, int* i, int* l, int* r) {
  printf("Please enter the change factor\n");
  scanf("%d", f);
  
  printf("Please enter the initial number\n");
  scanf("%d", i);
  
  printf("Please enter the array\'s length\n");
  scanf("%d", l);
  
  printf("Please enter the # of repeats\n");
  scanf("%d", r);
}

void fillit (int* array, int l, int i) {
  int j;
  for (j = 0; j < l; j++) {
    *(array+j) = i;
  }
}

int mathit (int* f, int* i, int* l, int* r, int* list) {
  int j = 0; int k = 0;
  for (j = 0; j < *r; j++) {
    *list += *f;
    for (k = 1; k < *l; k++) {
      *(list+k) += *f * *(list+k-1);
    }
    *i += *f * *(list+*l-1);
  }
}