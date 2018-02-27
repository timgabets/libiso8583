#include "snow.h"
#include "bitops.hh"

describe(bitops_suite, {
	subdesc(dummy, {
		it("dummy", {
			asserteq_int(1, 0);
		});
	});
});
