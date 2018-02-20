#include "snow.h"
#include "parser.hh"

describe(parser_suite, {
    subdesc(parse_message, {
        it("parse_message() dummy", {
             asserteq_int(parse_message(), 0);
        });
    });
});

