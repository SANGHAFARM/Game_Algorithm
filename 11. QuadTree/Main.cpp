#include "QuadTree.h"

#include <iostream>

int main()
{
	// 0, 0�� ���� ������� �ϴ� (200, 200) ũ���� ���� ����
	QuadTree tree(Bounds(0, 0, 200, 200));

	// ����
	tree.Insert(new Node(Bounds(60, 80)));
	tree.Insert(new Node(Bounds(50, 50)));
	tree.Insert(new Node(Bounds(90, 120)));
	tree.Insert(new Node(Bounds(150, 150)));
	tree.Insert(new Node(Bounds(10, 10)));

	std::cout << "��� ���� �Ϸ�\n";

	Node testNode(Bounds(45, 45, 20, 40));
	std::vector<Node*> intersects = tree.Query(&testNode);
	if (intersects.size() == 0)
	{
		std::cout << "��ġ�� ��带 ã�� ���߽��ϴ�\n";
	}
	else
	{
		std::cout << "��ġ�� ��带 " << intersects.size() << "�� ã�ҽ��ϴ�\n";
	}
}