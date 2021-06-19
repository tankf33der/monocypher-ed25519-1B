#include <stdlib.h>
#include <stdio.h>
#include "monocypher.h"
#include "monocypher-ed25519.h"

typedef uint8_t u8;

#define ARRAY(name, size) \
    u8 name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = i;

void print_vector(const u8 *buf, size_t size)
{
    for(size_t i =0; i < size; i++) {
        printf("%02x", buf[i]);
    }
    printf("\n");
}


int main(void) {
    ARRAY(hash, 64);

	for(size_t i = 0; i < 100000; i++) {
		crypto_ed25519_sign(hash, hash, 0, hash, 64);
	}
	print_vector(hash, 64);
	return 0;
}
