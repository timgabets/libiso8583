#include "parser.hh"
#include "conv_tools.hh"
#include "stdlib.h"
#include "string.h"

#define FIELDSCNT 2

iso8583field iso8583spec[FIELDSCNT] = {
	{2,     FIXED,  BCH,    CONTENT_TYPE_B, "MTI"},
	{16,    FIXED,  BCH,    CONTENT_TYPE_B, "Bitmap"}
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
		break;
	case ASCII:
		return atoi(trimmed);
	default:
		break;
	}

	return -1;
}

int parse_message(const char* msg, iso8583msg* parsed)
{
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
	return 0;
}
