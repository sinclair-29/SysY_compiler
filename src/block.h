#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <string>
/**
 * Class block is used to record current block, 
 * thus the scope of each variable can be specified. 
 * */
class Node {
private:
	Node *father;
	std::map<std::string, int> identifier_table;
public:
	Node() = default;
	~Node();
	Node(Node *_father);
	Node *get_extern_block() const;
};

class Block {
private:
	Node *root, *null;
public:
	Block();
	~Block();
};

#endif