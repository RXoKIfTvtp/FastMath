
#include "fmath256.h"

char fsin256(unsigned char v) {
	// First quarter of a sin wave
	static const char sin_table_256[] = {
		0,3,6,9,12,15,18,21,24,27,
		30,33,36,39,42,45,48,51,54,57,
		59,62,65,67,70,73,75,78,80,82,
		85,87,89,91,94,96,98,100,102,103,
		105,107,108,110,112,113,114,116,117,118,
		119,120,121,122,123,123,124,125,125,126,
		126,126,126,126,127
	};
	
	// Offset table for phase
	if (v <= 64) {
		return sin_table_256[v];
	} else if (v <= 128) {
		return sin_table_256[64 - (v - 64)];
	} else if (v <= 192) {
		return -sin_table_256[(v - 128)];
	} else {
		return -sin_table_256[64 - (v - 192)];
	}
}

char fcos256(unsigned char v) {
	if (v > 191) {
		// Safely wrap around without overflowing
		return fsin256(v - 192);
	} else {
		return fsin256(v + 64);
	}
}
