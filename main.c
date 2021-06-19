#include <stdlib.h>
#include <stdio.h>
// #include "monocypher.h"
#include "monocypher-ed25519.h"
#include "utils.h"
#include "ed25519.h"

typedef uint8_t u8;
typedef uint64_t u64;

#define ARRAY(name, size) \
    u8 name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = i;

int main(void) {
    ARRAY(hash, 64);
    ARRAY(sk1, 32);
    ARRAY(pk1, 32);
    ARRAY(msg1, 64);

    ARRAY(hash2, 64);
    ARRAY(pk2, 32);
    ARRAY(sk2, 32);
    ARRAY(msg2, 64);




	for(size_t i = 0; i < 1; i++) {
		crypto_ed25519_public_key(pk1, sk1);
		crypto_ed25519_sign(hash, sk1, pk1, msg1, 64);

		ed25519_publickey(sk2, pk2);
		ed25519_sign(msg2, 64, hash2, pk2, 	hash2);

	}


	print_vector(hash, 64);
	print_vector(hash2, 64);
	print_vector(pk1, 32);
	print_vector(pk2, 32);
	print_vector(sk1, 32);
	print_vector(sk2, 32);
	return 0;
}

