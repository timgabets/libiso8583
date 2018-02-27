#include "snow.h"
#include "conv_tools.hh"

describe(conv_tools_suite, {
	subdesc(bchtoa, {
		it("bchtoa() => '00'", {
			const char* src = "\x00";
			char dst[64] = {0};

			bchtoa(src, dst, 1);
			asserteq_str(dst, "00");
		});
		it("bchtoa() => '0102030405060708090A0B0C0D0E0F'", {
			const char* src = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "0102030405060708090A0B0C0D0E0F");
		});
		it("bchtoa() => '1112131415161718191A1B1C1D1E1F'", {
			const char* src = "\x11\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "1112131415161718191A1B1C1D1E1F");
		});
		it("bchtoa() => '2122232425262728292A2B2C2D2E2F'", {
			const char* src = "\x21\x22\x23\x24\x25\x26\x27\x28\x29\x2a\x2b\x2c\x2d\x2e\x2f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "2122232425262728292A2B2C2D2E2F");
		});

	});
});
