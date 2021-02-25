#pragma once
#include <string>

using namespace std;

class Node {
public:
	string data;
	Node* lchild = nullptr;
	Node* rchild = nullptr;

	Node(string);
	~Node();
};