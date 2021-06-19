mono:
	gcc -O3 -Wall -Wextra main.c monocypher.c monocypher-ed25519.c
	./a.out
