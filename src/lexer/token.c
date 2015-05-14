#include "token.h"

Token *createToken(int lineNumber, int charNumber, sds fileName) {
	Token *tok = safeMalloc(sizeof(*tok));
	tok->type = TOKEN_UNKNOWN;
	tok->content = NULL;
	tok->lineNumber = lineNumber;
	tok->charNumber = charNumber;
	tok->fileName = fileName;
	return tok;
}

char* getTokenContext(Vector *stream, Token *tok) {
	sds result = sdsempty();
	
	for (int i = 0; i < stream->size; i++) {
		Token *tempTok = getVectorItem(stream, i);
		if (tempTok->lineNumber == tok->lineNumber) {
			result = sdscat(result, tempTok->content);
			result = sdscat(result, " ");
		}
	}
	return result;
}


void destroyToken(Token *token) {
	free(token);
}
