#include "snow.h"
#include "bitops.hh"

describe(bitops_suite, {
	subdesc(getbit_testcases, {
		it("GETBIT(1) == 128", {
			asserteq_int(GETBIT(1), 128);
		});
		it("GETBIT(2) == 64", {
			asserteq_int(GETBIT(2), 64);
		});
		it("GETBIT(3) == 32", {
			asserteq_int(GETBIT(3), 32);
		});
		it("GETBIT(4) == 16", {
			asserteq_int(GETBIT(4), 16);
		});
		it("GETBIT(5) == 8", {
			asserteq_int(GETBIT(5), 8);
		});
		it("GETBIT(6) == 4", {
			asserteq_int(GETBIT(6), 4);
		});
		it("GETBIT(7) == 2", {
			asserteq_int(GETBIT(7), 2);
		});
		it("GETBIT(8) == 1", {
			asserteq_int(GETBIT(8), 1);
		});
		it("GETBIT(9) == 128", {
			asserteq_int(GETBIT(9), 128);
		});
	});
});
