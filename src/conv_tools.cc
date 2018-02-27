#include "conv_tools.hh"

void bchtoa(const char* src, char* dst, int len)
{
	for( int i = 0; i < len; i++ ) {
		int left = ((unsigned char) src[i]) >> 4;
		int right = src[i] & 0x0f;
		dst[i * 2] = (char) (left < 10 ? left + '0' : left + 'A' - 10);
		dst[i * 2 + 1] = (char) (right < 10 ? right + '0' : right + 'A' - 10);
	}
	dst[len * 2] = '\0';
}

