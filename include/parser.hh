typedef struct iso8583msg {
	int mti;
	char PAN[19]; 		// DE 02 - Primary Account Number
	int prcode;			// DE 03 - Processing Code
	int amount_trxn; 	// DE 04 - Transaction Amount
	int amount_sttl; 	// DE 05 - Settlement Amount
	int amount_billing; // DE 06 - Billing Amount
} iso8583msg;

int parse_message(const char*, iso8583msg*);
