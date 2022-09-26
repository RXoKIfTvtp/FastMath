
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#include "fmath256.h"
#include "fmath128.h"
#include "fmath64.h"

// Tests

#define NEWLINE "\r\n"

/**
 * Prints a byte array a of length len
**/
void print(int8_t *a, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d,", a[i]);
		if (i % 10 == 9 && i > 0) {
			printf("%s", NEWLINE);
		}
	}
	if (i % 10 != 9 && i > 0) {
		printf("%s", NEWLINE);
	}
}

/**
 * Creates a lookup table with a given amount of samples
 * using the sin function from math.h
**/
int8_t *generate_Lookup(unsigned int cnt) {
	int8_t *ptr = malloc(cnt);
	double pi2 = 2 * 3.1415926535897932384626433832795;
	int i;
	
	for (i = 0; i < cnt; i++) {
		double input = i * pi2 / cnt;
		double output = sin(input);
		ptr[i] = (int8_t)(output * 0x7F);
	}
	
	return ptr;
}

/**
 * Generates and prints a lookup table with a given accuracy.
**/
void print_lut(int cnt) {
	int8_t *p = generate_Lookup(cnt);
	print(p, cnt);
	free(p);
}

/**
 * Compares the output of sin from math.h to the output
 * of the lookup table and phase shift function.
**/
void run_tests() {
	double pi2 = 2 * 3.1415926535897932384626433832795;
	int cnt, i;
	unsigned int errors = 0;
	
	cnt = 256;
	for (i = 0; i < cnt; i++) {
		double input = i * pi2 / 256;
		double output = sin(input);
		int8_t byte = (int8_t)(output * 0x7F);
		
		int8_t fsin_ret = fsin256((uint8_t)i);
		
		//fsin and sin_as_byte should have the same values, if they don't something is wrong.
		if (fsin_ret != byte) {
			printf("sin(%f) = %f | %d | fsin256(%d)=%d%s", input, output, byte, i, fsin_ret, NEWLINE);
			errors++;
		}
	}
	
	cnt = 256;
	for (i = 0; i < cnt; i++) {
		double input = i * pi2 / 128;
		double output = sin(input);
		int8_t byte = (int8_t)(output * 0x7F);
		
		int8_t fsin_ret = fsin128((uint8_t)i);
		
		//fsin and sin_as_byte should have the same values, if they don't something is wrong.
		if (fsin_ret != byte) {
			printf("sin(%f) = %f | %d | fsin128(%d)=%d%s", input, output, byte, i, fsin_ret, NEWLINE);
			errors++;
		}
	}
	
	cnt = 256;
	for (i = 0; i < cnt; i++) {
		double input = i * pi2 / 64;
		double output = sin(input);
		int8_t byte = (int8_t)(output * 0x7F);
		
		int8_t fsin_ret = fsin64((uint8_t)i);
		
		//fsin and sin_as_byte should have the same values, if they don't something is wrong.
		if (fsin_ret != byte) {
			printf("sin(%f) = %f | %d | fsin64(%d)=%d%s", input, output, byte, i, fsin_ret, NEWLINE);
			errors++;
		}
	}
	
	if (!errors) {
		printf("Sin functions produced expected output.%s", NEWLINE);
	}
}

int main(int argc, char *argv[]) {
	print_lut(64);
	printf("==========%s", NEWLINE);
	print_lut(128);
	printf("==========%s", NEWLINE);
	print_lut(256);
	printf("==========%s", NEWLINE);
	run_tests();
	return 0;
}
