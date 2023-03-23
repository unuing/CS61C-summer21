#include "transpose.h"

/* The naive transpose function as a reference. */
void transpose_naive(int n, int blocksize, int *dst, int *src)
{
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			dst[y + x * n] = src[x + y * n];
		}
	}
}

/* Implement cache blocking below. You should NOT assume that n is a
 * multiple of the block size. */
void transpose_blocking(int n, int blocksize, int *dst, int *src)
{
	/* blocksize = 256 works the best on my computer. */
	for (int bx = 0; bx < n; bx += blocksize) {
		for (int by = 0; by < n; by += blocksize) {
			for (int k = 0; k < blocksize && k + bx < n; k++) {
				for (int h = 0; h < blocksize && h + by < n; h++) {
					int x = k + bx, y = h + by;
					dst[y + x * n] = src[x + y * n];
				}
			}
		}
	}
}
