
#ifndef FMATH128_H
#define FMATH128_H

/**
 * Approximates a sine wave with 128 samples of a sine wave length
 * Returns a signed byte value between -127 and 127
**/
char fsin128(unsigned char v);

/**
 * Approximates a cosine wave with 128 samples of a cosine wave length
 * Returns a signed byte value between -127 and 127
**/
char fcos128(unsigned char v);

#endif /* FMATH128_H */
