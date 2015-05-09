#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <inttypes.h>

uint64_t fibRecur(uint32_t n);
uint64_t fibLUT(uint32_t n);

int main(int argc, char *argv[]) {

	uint32_t input = strtoul(argv[1], NULL, 10);

	if (errno == 0) {
		printf("%4u\t%8" PRIu64 "\n", input, fibLUT(input));
//		printf("%4u\t%8u\n", input, fibRecur(input));
	} else {
		printf("Invalid input %4u\n", input);
	}

	return 0;
}

uint64_t fibLUT(uint32_t n) {
	// In this example, we will calculate the terms of the
	// fib. sequence from 0..n, returning the nth fib number
	// as the result.
	uint64_t *fibLUT = malloc(n * sizeof(uint64_t *));

	fibLUT[0] = 0;
	fibLUT[1] = 1;

	for (uint32_t i = 2; i <= n; i++) {
		fibLUT[i] = fibLUT[i - 1] + fibLUT[i - 2];
	}

	return fibLUT[n];;
}

uint64_t fibRecur(uint32_t n) {
	// The fibonacci sequence is defined as the sum of the two proceeding
	// numbers, with the first two numbers being 0 and 1.
	// Thus, the Fn = Fn-1 + Fn-2. 
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return fibRecur(n-1) + fibRecur(n-2);
	}
}
