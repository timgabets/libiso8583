#ifndef PARSER_HH
#define PARSER_HH

typedef enum lengthType {
    FIXED, 
    LVAR,
    LLVAR,
    LLLVAR,
    LLLLVAR
} lengthType;

typedef enum encodingType {
    BCH,
    ASCII,
    BCD
} encodingType;

typedef enum contentType {
    CONTENT_TYPE_B,
    CONTENT_TYPE_N,
    CONTENT_TYPE_A,
    CONTENT_TYPE_AN,
    CONTENT_TYPE_ANS,
    CONTENT_TYPE_Z,
} contentType;

//1 :   { 'ContentType':'b',     'MaxLen': 8,   'LenType': LT.FIXED,   'Description': 'Bitmap' },
typedef struct iso8583field {
    int length;
    lengthType length_type;
    encodingType encoding_type;
    contentType content_type;
    const char* description;
} iso8583field;

typedef struct iso8583msg {
    int mti;
    char PAN[19];       // DE 02 - Primary Account Number
    int prcode;         // DE 03 - Processing Code
    int amount_trxn;    // DE 04 - Transaction Amount
    int amount_sttl;    // DE 05 - Settlement Amount
    int amount_billing; // DE 06 - Billing Amount
} iso8583msg;

int parse_message(const char*, iso8583msg*);

#endif
