#include <iostream>
#include <map>
#include <cstdio>
#include "dfa.h"
#include "lexical_analyzer.h"

std::string contents;
DFA dfa;

void lexical_analyze() {
	/**
	 * In this project, the result of scanner will not be displayed 
	 * in the screen. Instead, the tokens will be stored in a token stream.
	 * */
	//printf("%-30s%s\n", "TOKEN-TYPE", "TOKEN-VALUE");
	//printf("-------------------------------------------------\n");
	DFA::initialize();	
	int length = contents.size();
	bool flag = false;
	for(int i = 0; i < length; ++i) {
		if(contents[i] == EOF) break;
		if(isws(contents[i]) && !dfa.is_comment(contents[i])) {
			if(flag) {
				dfa.terminate();
				flag = false;
			}
			continue;
		}
		if(!flag) {
			int start_symbol = get_symbol(contents[i]);
			if(start_symbol == symbol::ILLEGAL) {
				output_error_message(error_message[0]);
			} else {
				dfa.reset(contents[i]);
				flag = true;
			}
		} else {
			int current_symbol = get_symbol(contents[i]);
			if(current_symbol != symbol::ILLEGAL && dfa.transfer(contents[i])) {
				continue;
			} else {
				if(current_symbol == symbol::ILLEGAL) {
					dfa.terminate();
					flag = false;
					output_error_message(error_message[0]);
				} else {
					dfa.terminate();
					i -= 1;
					flag = false;
				}
			}
		}
	}
	if(flag) dfa.terminate();
}

bool isws(char ch) {
	if(ch == ' ' || ch == '\t') return true;
	if(ch == '\n') {
		current_line += 1;
		return true;
	}
	return false;
}

