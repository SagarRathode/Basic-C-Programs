

// this program demonstrate structure of size blueprint and footprint


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct ABC {
    int a;    // typically 4 bytes
    char b;   // 1 byte
    float c;  // typically 4 bytes
}; /// all above size is just blueprint but memory is allocated when we create actual object

int main(void) {
    printf("sizeof(struct ABC) = %zu\n", sizeof(struct ABC));

    struct ABC obj;//here menory is allocated  for ABC Structure

    printf("sizeof(obj) = %zu\n", sizeof obj);

    printf("offsetof: a=%zu, b=%zu, c=%zu\n",
           offsetof(struct ABC, a),
           offsetof(struct ABC, b),
           offsetof(struct ABC, c));

    printf("offsets from &obj: a=%td, b=%td, c=%td\n",
           (char*)&obj.a - (char*)&obj,
           (char*)&obj.b - (char*)&obj,
           (char*)&obj.c - (char*)&obj);

    struct ABC *p = malloc(sizeof *p);
    printf("malloc returned %p, sizeof *p = %zu\n", (void*)p, sizeof *p);
    free(p);

    return 0;
}

