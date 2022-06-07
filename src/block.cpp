#include "block.h"

Node::Node(Node *_father) :
	father(_father) {} 

Node* Node::get_extern_block() const {
	return this->father;
}

Node::~Node() {
	this->identifier_table.clear();
}

Block::Block() {
	*null = new Node();
}

