
#ifndef FMATH64_H
#define FMATH64_H

/**
 * Approximates a sine wave with 64 samples of a sine wave length
 * Returns a signed byte value between -127 and 127
**/
char fsin64(unsigned char v);

/**
 * Approximates a cosine wave with 64 samples of a cosine wave length
 * Returns a signed byte value between -127 and 127
**/
char fcos64(unsigned char v);

#endif /* FMATH64_H */
