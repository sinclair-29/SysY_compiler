#ifndef PARSER_H
#define PARSER_H

#include "dfa.h"
#include <vector>

extern std::vector<Token> token_stream;

void parse();

#endif