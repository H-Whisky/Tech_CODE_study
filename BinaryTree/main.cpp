#include<iostream>
#include "BinaryTree.h"
using namespace std;
int main() {
	BinaryTree tree;
	tree.ADD("A");
	tree.ADD("B");
	tree.ADD("C");
	tree.ADD("D");
	tree.ADD("E");
	tree.ADD("F");
	tree.ADD("G");
	cout << "先序遍历:";
	tree.PreOrder(tree.root);
	cout << endl << "中序遍历:";
	tree.InOrder(tree.root);
	cout << endl << "后序遍历:";
	tree.PostOrder(tree.root);

	cin.get();
	return (0);
}