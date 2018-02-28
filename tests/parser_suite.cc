#include "snow.h"
#include "parser.hh"
#include "stdio.h"

static iso8583msg parsed;

describe(parser_suite, {
	subdesc(get_data_len, {
		it("get_data_len(): should get FIXED field data length", {
			iso8583field f = {6, FIXED, BCH, CONTENT_TYPE_N, "DE03"};
			const char* msg = "\x31\x01\x02";
			asserteq_int(get_data_len(msg, &f), 6);
			//asserteq_str(parsed.PAN, "4219664003348003");
		});
		it("get_data_len(): should get LLVAR field data length 0-9", {
			iso8583field f = {19, LLVAR, BCD, CONTENT_TYPE_N, "DE02"};
			char msg[19] = {0};
			for(int i = '\x00'; i <= '\x09'; i++) {
				msg[0] = i;
				asserteq_int(get_data_len(msg, &f), i);
			}
		});
		it("get_data_len(): should get LLVAR field data length 10-19", {
			iso8583field f = {19, LLVAR, BCD, CONTENT_TYPE_N, "DE02"};
			char values[11] = "\x10\x11\x12\x13\x14\x15\x16\x17\x18\x19";
			int lengths[11] =   {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0};

			char msg[19] = "\x10\x44";
			for (int i = 0; i < 11; i++) {
				msg[0] = values[i];
				asserteq_int(get_data_len(msg, &f), lengths[i]);
			}
		});
		it("get_data_len(): should get LLVAR field data length 90-99", {
			iso8583field f = {19, LLVAR, BCD, CONTENT_TYPE_N, "DE02"};
			char values[11] = "\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99";
			int lengths[11] =   {90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 0};

			char msg[19] = "\x10\x44";
			for (int i = 0; i < 11; i++) {
				msg[0] = values[i];
				asserteq_int(get_data_len(msg, &f), lengths[i]);
			}
		});
	});


	subdesc(parse_de002, {
		it("parse_de002(): should parse BCH-encoded LLVAR PAN", {
			iso8583field f = {16, LLVAR, BCD, CONTENT_TYPE_N, "DE02"};
			const char* msg = "\x16\x42\x19\x66\x40\x03\x34\x80\x03";
			asserteq_int(parse_de002(msg, &f, &parsed), 0);
			asserteq_str(parsed.PAN, "4219664003348003");
		});
	});

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
			const char* msg = "\x02\x00\x60\x38\x06\x81\x20\x80\x90\x01\x16\x42\x19\x66\x40\x03\x34\x80\x03\x31\x00\x00\x00\x00\x09\x14\x56\x00\x02\x06\x00\x01\x00\x00\x14\x09\x81\x98\x01\x26\x30\x37\x62\x19 \x86\x40\x03\x34\x80\x03\xd1\x90\x41\x00\x71\x53\x28\x83\x68\x48\x8f\x30\x30\x31\x37\x31\x35\x33\x32\x33\x36\x34\xc9\xf8\x81\x59\x66\xde\xad\xc1\x1f\xd1\x8f\x40\xbf\xda\xbf\x79";
			iso8583msg parsed;

			asserteq_int(parse_message(msg, &parsed), 0);
			asserteq_int(parsed.mti, 200);
		});
	});
});

