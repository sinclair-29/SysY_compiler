#include "dfa.h"
#include "compiler.h"
#include "lexical_analyzer.h"
#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	std::string filename;
	/**
	 * For debug
	 * */
	filename = "test.txt";
	//std::cin >> filename;
	std::ifstream infile(filename);

	std::stringstream buffer;	
	buffer << infile.rdbuf();
	contents = buffer.str();
	lexical_analyze();

	infile.close();

	return 0;
}