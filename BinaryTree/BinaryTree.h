#include <iostream>

class FNode
{
public:
	int Key;
	int Height;
	FNode* Left;
	FNode* Right;
	FNode* Parent;
};

class UBinaryTree
{
public:
	UBinaryTree();
	~UBinaryTree();
	FNode* Insert(FNode* AddNode, int Key);
	FNode* Search(FNode* AddNode, int Key);
	FNode* Remove(FNode* AddNode, int Value);
	int FindMin();
	int FindMax();
	int Successor(int Key);
	int Predecessor(int Key);
	int FindMin(FNode* AddNode);
	int FindMax(FNode* AddNode);
	int Successor(FNode* AddNode);
	int Predecessor(FNode* AddNode);
	bool Search(int Key);
	void Insert(int Key);
	void PrintTreeInOrder();
	void PrintTreeInOrder(FNode* AddNode);
	void Remove(int Value);
	void TestAddValueAndTime(FNode* Root);
private:
	FNode* Root;
};
