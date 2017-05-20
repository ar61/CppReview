#pragma once

// deepCopy


#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;

static const int SIZE = 5;

typedef struct Node {
	vector<Node*> children;
}Node;

typedef struct Graph {
	vector<Node*> nodes;
}Graph;

vector<Node*> visited;

bool IsVisited(Node* n) {
	for (uint8_t i = 0; i < visited.size(); ++i) {
		if (visited[i] == n) {
			// std::cout << "address: v[i] = " << visited[i] << ", n = " << n << std::endl;
			return true;
		}
	}
	return false;
}

void markVisited(Node* n) {
	visited.push_back(n);
}

void PrintGraph(Graph g)
{
	int count = 0, timeout = 0;
	queue<Node*> q;
	q.push(g.nodes[0]);
	markVisited(g.nodes[0]);
	std::cout << "Start Node" << std::endl;
	while (!q.empty()) {
		Node* n = q.front();
		q.pop();
		//std::cout << "queue size: " << q.size() << std::endl;
		std::cout << "parent" << std::endl;
		for (auto &i : n->children) {
			if (!IsVisited(i)) {
				markVisited(i);
				q.push(i);
				++count;
				std::cout << "child(" << count << ")" << std::endl;
				++timeout;
			}
		}
		count = 0;
		if (timeout > 20) {
			//std::cout << "queue size: " << q.size() << std::endl;
			while (!q.empty()) {
				q.pop();
			}
		}
	}
}

Node* DeepCopy(Node* node)
{


	return nullptr;
}

// To execute C++, please define "int main()"
int Run() {
	Graph g;
	for (int j = 0; j < SIZE; ++j) {
		g.nodes.push_back(new Node);
	}
	int counter = -1, randVal = 0;
	srand(time(NULL));
	for (auto &node : g.nodes) {
		++counter;
		std::cout << "current Node: " << counter << std::endl;
		randVal = 1;//rand()%(g.nodes.size()) + 1;
					//std::cout << "Total Nodes: " << randVal << std::endl;
		while (randVal > 0) {
			int x = rand() % (g.nodes.size());
			while (x == counter) {
				x = rand() % (g.nodes.size());
			}
			Node* t = g.nodes[x];

			if (find(node->children.begin(), node->children.end(), t) == node->children.end())
			{
				std::cout << "Push: " << x << std::endl;
				node->children.push_back(t);
				--randVal;
			}
		}
	}
	PrintGraph(g);



	return 0;
}