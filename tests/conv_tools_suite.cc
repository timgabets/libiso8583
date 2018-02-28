#include "snow.h"
#include "conv_tools.hh"

describe(conv_tools_suite, {
	subdesc(bcdtoa, {
		it("bcdtoa() => '00'", {
			const char* src = "\x00";
			char dst[64] = {0};

			bcdtoa(src, dst, 1);
			asserteq_str(dst, "00");
		});

		it("bcdtoa() => '010203040506070809'", {
			const char* src = "\x01\x02\x03\x04\x05\x06\x07\x08\x09";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "010203040506070809");
		});
		it("bcdtoa() => '111213141516171819'", {
			const char* src = "\x11\x12\x13\x14\x15\x16\x17\x18\x19";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "111213141516171819");
		});
		it("bcdtoa() => '212223242526272829'", {
			const char* src = "\x21\x22\x23\x24\x25\x26\x27\x28\x29";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "212223242526272829");
		});
		it("bcdtoa() => '313233343536373839'", {
			const char* src = "\x31\x32\x33\x34\x35\x36\x37\x38\x39";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "313233343536373839");
		});
		it("bcdtoa() => '414243444546474849'", {
			const char* src = "\x41\x42\x43\x44\x45\x46\x47\x48\x49";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "414243444546474849");
		});
		it("bcdtoa() => '515253545556575859'", {
			const char* src = "\x51\x52\x53\x54\x55\x56\x57\x58\x59";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "515253545556575859");
		});
		it("bcdtoa() => '616263646566676869'", {
			const char* src = "\x61\x62\x63\x64\x65\x66\x67\x68\x69";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "616263646566676869");
		});
		it("bcdtoa() => '717273747576777879'", {
			const char* src = "\x71\x72\x73\x74\x75\x76\x77\x78\x79";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "717273747576777879");
		});
		it("bcdtoa() => '818283848586878889'", {
			const char* src = "\x81\x82\x83\x84\x85\x86\x87\x88\x89";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "818283848586878889");
		});
		it("bcdtoa() => '919293949596979899'", {
			const char* src = "\x91\x92\x93\x94\x95\x96\x97\x98\x99";
			char dst[64] = {0};

			bcdtoa(src, dst, strlen(src));
			asserteq_str(dst, "919293949596979899");
		});
});

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
		it("bchtoa() => '3132333435363738393A3B3C3D3E3F'", {
			const char* src = "\x31\x32\x33\x34\x35\x36\x37\x38\x39\x3a\x3b\x3c\x3d\x3e\x3f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "3132333435363738393A3B3C3D3E3F");
		});
		it("bchtoa() => '4142434445464748494A4B4C4D4E4F'", {
			const char* src = "\x41\x42\x43\x44\x45\x46\x47\x48\x49\x4a\x4b\x4c\x4d\x4e\x4f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "4142434445464748494A4B4C4D4E4F");
		});
		it("bchtoa() => '5152535455565758595A5B5C5D5E5F'", {
			const char* src = "\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5a\x5b\x5c\x5d\x5e\x5f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "5152535455565758595A5B5C5D5E5F");
		});
		it("bchtoa() => '6162636465666768696A6B6C6D6E6F'", {
			const char* src = "\x61\x62\x63\x64\x65\x66\x67\x68\x69\x6a\x6b\x6c\x6d\x6e\x6f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "6162636465666768696A6B6C6D6E6F");
		});
		it("bchtoa() => '7172737475767778797A7B7C7D7E7F'", {
			const char* src = "\x71\x72\x73\x74\x75\x76\x77\x78\x79\x7a\x7b\x7c\x7d\x7e\x7f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "7172737475767778797A7B7C7D7E7F");
		});
		it("bchtoa() => '8182838485868788898A8B8C8D8E8F'", {
			const char* src = "\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8a\x8b\x8c\x8d\x8e\x8f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "8182838485868788898A8B8C8D8E8F");
		});
		it("bchtoa() => '9192939495969798999A9B9C9D9E9F'", {
			const char* src = "\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9a\x9b\x9c\x9d\x9e\x9f";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "9192939495969798999A9B9C9D9E9F");
		});
		it("bchtoa() => 'A1A2A3A4A5A6A7A8A9AAABACADAEAF'", {
			const char* src = "\xa1\xa2\xa3\xa4\xa5\xa6\xa7\xa8\xa9\xaa\xab\xac\xad\xae\xaf";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "A1A2A3A4A5A6A7A8A9AAABACADAEAF");
		});
		it("bchtoa() => 'B1B2B3B4B5B6B7B8B9BABBBCBDBEBF'", {
			const char* src = "\xb1\xb2\xb3\xb4\xb5\xb6\xb7\xb8\xb9\xba\xbb\xbc\xbd\xbe\xbf";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "B1B2B3B4B5B6B7B8B9BABBBCBDBEBF");
		});
		it("bchtoa() => 'C1C2C3C4C5C6C7C8C9CACBCCCDCECF'", {
			const char* src = "\xc1\xc2\xc3\xc4\xc5\xc6\xc7\xc8\xc9\xca\xcb\xcc\xcd\xce\xcf";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "C1C2C3C4C5C6C7C8C9CACBCCCDCECF");
		});
		it("bchtoa() => 'D1D2D3D4D5D6D7D8D9DADBDCDDDEDF'", {
			const char* src = "\xd1\xd2\xd3\xd4\xd5\xd6\xd7\xd8\xd9\xda\xdb\xdc\xdd\xde\xdf";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "D1D2D3D4D5D6D7D8D9DADBDCDDDEDF");
		});
		it("bchtoa() => 'E1E2E3E4E5E6E7E8E9EAEBECEDEEEF'", {
			const char* src = "\xe1\xe2\xe3\xe4\xe5\xe6\xe7\xe8\xe9\xea\xeb\xec\xed\xee\xef";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "E1E2E3E4E5E6E7E8E9EAEBECEDEEEF");
		});

		it("bchtoa() => 'F1F2F3F4F5F6F7F8F9FAFBFCFDFEFF'", {
			const char* src = "\xf1\xf2\xf3\xf4\xf5\xf6\xf7\xf8\xf9\xfa\xfb\xfc\xfd\xfe\xff";
			char dst[64] = {0};

			bchtoa(src, dst, strlen(src));
			asserteq_str(dst, "F1F2F3F4F5F6F7F8F9FAFBFCFDFEFF");
		});

	});
});
