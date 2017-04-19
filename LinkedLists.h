#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void Swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

// Singly Linked List
template<typename T>
struct SLLNode
{
	T val;
	SLLNode* next;
	SLLNode(T data) {
		val = data;
		next = nullptr;
	}
};

// basic insert into Linked List
template<typename T>
void SLL_Insert(SLLNode<T>** head, T v)
{
	if (head == nullptr || *head == nullptr) {
		*head = nullptr;
		std::cout << "Inserting head" << std::endl;
		auto h = new SLLNode<T>(v);
		*head = h;
		return;
	}
	SLLNode<T>* temp = *head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = new SLLNode<T>(v);
}

// Delete by swapping values and removing the next node
template<typename T>
void SLL_Delete(SLLNode<T>** head,SLLNode<T>** n)
{
	if (*n == nullptr) {
		std::cout << "Invalid node" << std::endl;
		return;
	}
	// deleting the last node
	else if ((*n)->next == nullptr) {
		// if head is the only node, delete it
		if ((*head)->next == nullptr) {
			*head = nullptr;
			delete *head;
			return;
		}
		auto cur = *head;
		while (cur->next->next != nullptr) {
			cur = cur->next;
		}
		auto temp = &cur;
		// delete previous to last's next pointer reference
		(*temp)->next = nullptr;
		*n = nullptr;
		delete *n;
		return;
	}
	SLLNode<T>* nxt = (*n)->next;
	Swap(&((*n)->val), &(nxt->val));
	(*n)->next = nxt->next;
	nxt->next = nullptr;
	nxt = nullptr;
	delete nxt;
}

template<typename T>
void SLL_RemoveDups(SLLNode<T>** head)
{
	std::vector<T> nodes;
	SLLNode<T>* temp = head;
	while (temp != nullptr) {
		if (find(nodes.begin(), nodes.end(), temp->val) == nodes.end()) {
			nodes.push_back(temp->val);
			temp = temp->next;
		}
		else {
			SLL_Delete(&head, &temp);
		}
	}
}

template<typename T>
SLLNode<T>* SLL_Reverse(SLLNode<T>* head)
{
	if (head == nullptr || head->next == nullptr) {
		std::cout << "Returning only head" << std::endl;
		return head;
	}
	SLLNode<int>* prev = head;
	SLLNode<int>* cur = head;
	SLLNode<int>* ahead = head->next;
	while (ahead != nullptr) {
		cur = ahead;
		ahead = ahead->next;
		cur->next = prev;
		prev = cur;
	}
	head->next = nullptr;
	return cur;
}

template<typename T>
void SLL_DisplayNodes(SLLNode<T>* head)
{
	if (head == nullptr) {
		return;
	}
	SLLNode<T>* temp = head;
	while (temp != nullptr) {
		std::cout << temp->val << " ,";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void Run()
{
	std::vector<int> v = { 6 };// , 29, 35, 2, 6, 0, 35, 99, 99
	SLLNode<int>* head = nullptr;
	for (auto &i : v) {
		SLL_Insert(&head, i);
	}
	SLL_Delete(&head, &head);
	//head = SLL_Reverse(head);
	//SLL_RemoveDups(head);
	SLL_DisplayNodes(head);
}