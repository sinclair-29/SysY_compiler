#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <cstring>

extern std::string contents;
extern DFA dfa;

void lexical_analyze();
bool isws(char ch);

#endif
