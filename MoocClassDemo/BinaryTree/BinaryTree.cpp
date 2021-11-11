#include "BinaryTree.h"

BinaryTree::BinaryTree() {

}

void BinaryTree::ADD(string data) {
	Node* node = new Node(data);
	queue<Node*> queue;
	queue.push(root);
	if (!this->root) {
		root = node;
		return;
	}
	while (!queue.empty()) {
		Node* curNode = queue.front();
		queue.pop();
		if (!curNode->lchild) {
			curNode->lchild = node;
			return;
		}
		else {
			queue.push(curNode->lchild);
		}
		if (!curNode->rchild) {
			curNode->rchild = node;
			return;
		}
		else {
			queue.push(curNode->rchild);
		}
	}
}

void BinaryTree::PreOrder(const Node* node) {
	if (!node) {
		return;
	}
	cout << node->data << " ";
	PreOrder(node->lchild);
	PreOrder(node->rchild);
}

void BinaryTree::InOrder(const Node* node) {
	if (!node) {
		return;
	}
	InOrder(node->lchild);
	cout << node->data << " ";
	InOrder(node->rchild);
}

void BinaryTree::PostOrder(const Node* node) {
	if (!node) {
		return;
	}
	PostOrder(node->lchild);
	PostOrder(node->rchild);
	cout << node->data << " ";
}

void BinaryTree::DestoryBinaryTree(Node* node) {
	if (node) {
		if (node->lchild) {
			DestoryBinaryTree(node->lchild);
		}
		if (node->rchild) {
			DestoryBinaryTree(node->rchild);
		}
	}
	delete node;
	node = nullptr;
}

BinaryTree::~BinaryTree() {
	DestoryBinaryTree(root);
}