# FastMath

The purpose of the fast math functions is to allow the approximation of a sine wave or cosine wave on micro-controllers.

Most micro-controller processors either don’t support floating point numbers or are very processor intensive. If accuracy is not as important as speed or memory, these functions can be used to represent a sine or cosine wave using a single byte. These functions represent 1 with the byte value 127, 0 is 0 and -1 is represented with -127. The values in between 127 and -127 are linearly proportional fractions between 1 and -1. For example 64 is about 1/2 and 32 is about 1/4.

sin64 has 64 possible sample points of accuracy along a wave-length.
sin256 has 256 possible sample points of accuracy along a wave-length.
And so on.

The more sample points are used, the higher the accuracy of the function, however because the lookup table must be larger it also requires more memory to store the function.


