#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monocypher-ed25519.h"
#include "edsign.h"

typedef uint8_t u8;
typedef uint64_t u64;

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

	ARRAY(hash2, 64);
	ARRAY(msg2, 64);
	ARRAY(pk2, 32);

	for(size_t i = 0; i < 1000; i++) {
		crypto_ed25519_sign(hash, hash, 0, hash, 64);

		edsign_sec_to_pub(pk2, hash2);
		edsign_sign(hash2, pk2, hash2, msg2, 64);
		memcpy(msg2, hash2, 64);
	}
	print_vector(hash, 64);
	print_vector(hash2, 64);
	return 0;
}

