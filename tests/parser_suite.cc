#include "snow.h"
#include "parser.hh"

describe(parser_suite, {
	subdesc(parse_mti, {
		it("should return -1 if MTI length is more than 4", {
			const char* msg = "\x02\x00";
			asserteq_int(parse_mti(msg, 5, BCH), -1);
		});

		it("should parse BCH-encoded MTI", {
			const char* msg = "\x02\x00";
			asserteq_int(parse_mti(msg, 2, BCH), 200);
		});
		it("should parse ASCII-encoded MTI", {
			const char* msg = "1420999999";
			asserteq_int(parse_mti(msg, 4, ASCII), 1420);
		});
	});

	subdesc(parse_message, {
		it("parse_message() dummy 0200 message", {
			const char* msg = "\x02\x00\x60\x38\x06\x81\x20\x80\x90\x01\x16\x62\x19\x86\x40\x03\x34\x80\x03\x31\x00\x00\x00\x00\x09\x14\x56\x00\x02\x06\x00\x01\x00\x00\x14\x09\x81\x98\x01\x26\x30\x37\x62\x19 \x86\x40\x03\x34\x80\x03\xd1\x90\x41\x00\x71\x53\x28\x83\x68\x48\x8f\x30\x30\x31\x37\x31\x35\x33\x32\x33\x36 \x34\xc9\xf8\x81\x59\x66\xde\xad\xc1\x1f\xd1\x8f\x40\xbf\xda\xbf\x79";
			iso8583msg parsed;

			asserteq_int(parse_message(msg, &parsed), 0);
			asserteq_int(parsed.mti, 200);
		});
	});
});

