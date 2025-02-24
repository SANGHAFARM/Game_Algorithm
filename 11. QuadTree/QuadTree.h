#pragma once

#include "Node.h"

// 쿼드 트리 클래스
class QuadTree
{
public:
	QuadTree(const Bounds& bounds);
	~QuadTree();

	void Insert(Node* node);

	std::vector<Node*> Query(Node* queryNode);

public:
	static const int maxDepth = 4;

private:
	Node* root = nullptr;
};