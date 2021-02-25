#pragma once

#include "Node.h"
#include <queue>
#include <iostream>
using namespace std;

class BinaryTree {
public:
	Node* root = nullptr;
	BinaryTree();
	void ADD(string data);
	void PreOrder(const Node* node);
	void InOrder(const Node* node);
	void PostOrder(const Node* node);
	~BinaryTree();
private:
	void DestoryBinaryTree(Node* node);
};