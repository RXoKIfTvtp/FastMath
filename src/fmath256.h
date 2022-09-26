
#ifndef FMATH256_H
#define FMATH256_H

/**
 * Approximates a sine wave with 256 samples of a sine wave length
 * Returns a signed byte value between -127 and 127
**/
char fsin256(unsigned char v);

/**
 * Approximates a cosine wave with 256 samples of a cosine wave length
 * Returns a signed byte value between -127 and 127
**/
char fcos256(unsigned char v);

#endif /* FMATH256_H */
