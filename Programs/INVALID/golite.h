#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *concatenate(char *c, char *sucks){
	strcat(c,sucks);
	return c;
}

typedef struct Array_int {
  int *array;
  size_t used;
  size_t size;
} Array_int;

void initArray_int(Array_int *a, int initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

Array_int insertArray_int(Array_int *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
  return *a;
}

void freeArray_int(Array_int *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

typedef struct Array_float {
  float *array;
  size_t used;
  size_t size;
} Array_float;

void initArray_float(Array_float *a, int initialSize) {
  a->array = (float *)malloc(initialSize * sizeof(float));
  a->used = 0;
  a->size = initialSize;
}

Array_float insertArray_float(Array_float *a, float element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (float *)realloc(a->array, a->size * sizeof(float));
  }
  a->array[a->used++] = element;
  return *a;
}

void freeArray_float(Array_float *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

typedef struct Array_char {
  char *array;
  size_t used;
  size_t size;
} Array_char;

void initArray_char(Array_char *a, int initialSize) {
  a->array = (char *)malloc(initialSize * sizeof(char));
  a->used = 0;
  a->size = initialSize;
}

Array_char insertArray_char(Array_char *a, char element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (char *)realloc(a->array, a->size * sizeof(char));
  }
  a->array[a->used++] = element;
  return *a;
}

void freeArray_char(Array_char *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

typedef struct Array_string {
  char **array;
  size_t used;
  size_t size;
} Array_string;

void initArray_string(Array_string *a, int initialSize) {
  a->array = (char **)malloc(initialSize * sizeof(char *));
  a->used = 0;
  a->size = initialSize;
}

Array_string insertArray_string(Array_string *a, char *element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (char **)realloc(a->array, a->size * sizeof(char *));
  }
  a->array[a->used++] = element;
  return *a;
}

void freeArray_string(Array_string *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}
