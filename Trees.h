#pragma once
#include <iostream>
#include <vector>

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node(int data) {
		val = data;
		left = nullptr;
		right = nullptr;
	}
};

Node * CreateBST(std::vector<int> v, int l, int r)
{
	if (l > r) {
		return nullptr;
	}
	int mid = l + (r - l) / 2;
	Node *n = new Node(v[mid]);
	//std::cout << n->val << std::endl;
	n->left = CreateBST(v, l, mid - 1);
	n->right = CreateBST(v, mid + 1, r);
	return n;
}

// in order traversal
void PrintBST(Node *n)
{
	if (n == nullptr) {
		return;
	}
	PrintBST(n->left);
	std::cout << n->val << std::endl;
	PrintBST(n->right);
}

void MinimalBST() {

	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };

	Node *n = CreateBST(v, 0, v.size() - 1);

	std::cout << std::endl;
	PrintBST(n);
}