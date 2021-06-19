all:
	gcc -O3 -Wall -Wextra -DED25519_NO_INLINE_ASM -DED25519_FORCE_32BIT -DED25519_CUSTOMHASH -DED25519_TEST main.c monocypher.c monocypher-ed25519.c ed25519.c *.h -I.
	./a.out
