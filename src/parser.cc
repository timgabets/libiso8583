#include "parser.hh"
#include "conv_tools.hh"
#include "bitops.hh"
#include "stdlib.h"
#include "string.h"

#define FIELDSCNT 3

iso8583field iso8583spec[FIELDSCNT] = {
	{2,     FIXED,  BCH,    CONTENT_TYPE_B, "MTI"},
	{16,    FIXED,  BCH,    CONTENT_TYPE_B, "Bitmap"},
	{16,    LLVAR,  BCD,    CONTENT_TYPE_N, "Primary Account Number"}
};

int parse_mti(const char* msg, int length, encodingType encoding)
{
	char trimmed[8] = {0};
	char converted[8] = {0};
	if(length <= 4)
		memcpy(trimmed, msg, length);
	else
		return -1;

	switch(encoding) {
	case BCH:
		bchtoa(trimmed, converted, length);
		return atoi(converted);
	case ASCII:
		return atoi(trimmed);
	default:
		break;
	}

	return -1;
}


int parse_de002(const char* msg, iso8583field* f, iso8583msg* parsed)
{
	return 0;
}

int parse_message(const char* msg, iso8583msg* parsed)
{
	char* ptr = (char*) msg;
	parsed->mti = parse_mti(ptr, iso8583spec[0].length, iso8583spec[0].encoding_type);
	ptr += iso8583spec[0].length;

	char* bitmap = ptr;
	int bitmap_len = ISBITSET(bitmap, 1) ? 16 : 8;
	ptr += bitmap_len;

	memcpy(parsed->PAN, ptr, iso8583spec[2].length);
/*
	for(int i = 0; i < FIELDSCNT; i++) {
		iso8583field f = iso8583spec[i];

		switch(i) {
		case 0:
			parsed->mti = parse_mti(msg, f.length, f.encoding_type);
			break;
		case 1:
			break;
		default:
			break;
		}
	}
*/
	return 0;
}
