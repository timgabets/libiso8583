#include "parser.hh"

iso8583field iso8583spec = {2,     FIXED,  BCH,    CONTENT_TYPE_B, "MTI"}; 

int parse_message(const char* msg, iso8583msg* parsed)
{
    return 0;
}
