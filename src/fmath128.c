
#include "fmath128.h"

char fsin128(unsigned char v) {
	v = v % 128;
	// First quarter of a sin wave
	static const char sin_table_128[] = {
		0,6,12,18,24,30,36,42,48,54,
		59,65,70,75,80,85,89,94,98,102,
		105,108,112,114,117,119,121,123,124,125,
		126,126,127
	};
	
	// Offset table for phase
	if (v <= 32) {
		return sin_table_128[v];
	} else if (v <= 64) {
		return sin_table_128[32 - (v - 32)];
	} else if (v <= 96) {
		return -sin_table_128[(v - 64)];
	} else {
		return -sin_table_128[32 - (v - 96)];
	}
}

char fcos128(unsigned char v) {
	v = v % 128;
	return fsin128(v + 32);
}
