
#include "fmath64.h"

char fsin64(unsigned char v) {
	v = v % 64;
	// First quarter of a sin wave
	static const char sin_table_64[] = {
		0,12,24,36,48,59,70,80,89,98,
		105,112,117,121,124,126,127
	};
	
	// Offset table for phase
	if (v <= 16) {
		return sin_table_64[v];
	} else if (v <= 32) {
		return sin_table_64[16 - (v - 16)];
	} else if (v <= 48) {
		return -sin_table_64[(v - 32)];
	} else {
		return -sin_table_64[16 - (v - 48)];
	}
}

char fcos64(unsigned char v) {
	v = v % 64;
	return fsin64(v + 16);
}
