#include "parser.hh"
#include "stdio.h"

iso8583field iso8583spec[2] = {
	{2,     FIXED,  BCH,    CONTENT_TYPE_B, "MTI"},
	{16,    FIXED,  BCH,    CONTENT_TYPE_B, "Bitmap"}
};

int parse_message(const char* msg, iso8583msg* parsed)
{
	return 0;
}
