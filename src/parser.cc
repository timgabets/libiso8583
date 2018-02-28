#include "parser.hh"
#include "conv_tools.hh"
#include "bitops.hh"
#include "stdlib.h"
#include "string.h"

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

int get_data_len(const char* msg, iso8583field* f)
{
	char converted[8] = {0};
	switch(f->length_type) {
	case FIXED:
		return f->length;
	case LLVAR:
		// TODO: skip conversion to ASCII
		bcdtoa(msg, converted, 1);
		return atoi(converted);
	}
	return -1;
}

int parse_de002(const char* msg, iso8583field* f, iso8583msg* parsed)
{
	char* ptr = (char*) msg;
	int data_len = get_data_len(msg, f);

	ptr += 1;

	switch(f->encoding_type){
	case BCD:
		bcdtoa(ptr, parsed->PAN, data_len / 2);
		break;
	}

	return 0;
}

#define FIELDSCNT 4
iso8583field iso8583spec[FIELDSCNT] = {
	{2,     FIXED,  BCH,    CONTENT_TYPE_B, "MTI"},
	{16,    FIXED,  BCH,    CONTENT_TYPE_B, "Bitmap"},
	{16,    LLVAR,  BCD,    CONTENT_TYPE_N, "Primary Account Number"},
	{6,     FIXED,  BCD,    CONTENT_TYPE_N, "Processing Code"}
};

int parse_message(const char* msg, iso8583msg* parsed)
{
	char* ptr = (char*) msg;
	parsed->mti = parse_mti(ptr, iso8583spec[0].length, iso8583spec[0].encoding_type);
	ptr += iso8583spec[0].length;

	char* bitmap = ptr;
	int bitmap_len = ISBITSET(bitmap, 1) ? 16 : 8;
	ptr += bitmap_len;

	parse_de002(ptr, &iso8583spec[2], parsed);

	return 0;
}
