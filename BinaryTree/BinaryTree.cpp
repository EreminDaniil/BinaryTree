#include <iostream>
#include "BinaryTree.h"
#include <ctime>

UBinaryTree::UBinaryTree()
{
	Root = nullptr;
}

UBinaryTree::~UBinaryTree()
{
	Remove(0);
}

FNode* UBinaryTree::Insert(FNode* AddNode, int Key)
{
	if (AddNode == nullptr)
	{
		AddNode = new FNode;
		AddNode->Key = Key;
		AddNode->Left = nullptr;
		AddNode->Right = nullptr;
		AddNode->Parent = nullptr;
	}
	else if (AddNode->Key < Key)
	{
		AddNode->Right = Insert(AddNode->Right, Key);
		AddNode->Right->Parent = AddNode;
	}
	else
	{
		AddNode->Left = Insert(AddNode->Left, Key);
		AddNode->Left->Parent = AddNode;
	}
	return AddNode;
}

void UBinaryTree::Insert(int Key)
{
	//srand(time(nullptr));
	Root = Insert(Root, Key);
	//std::cout << std::endl << "Runtime= " << clock() / 1000.0 << " ms" << std::endl;
}

void UBinaryTree::PrintTreeInOrder(FNode* AddNode)
{
	if (AddNode == nullptr)
	{
		return;
	}
	PrintTreeInOrder(AddNode->Left);
	std::cout << AddNode->Key << " ";
	PrintTreeInOrder(AddNode->Right);
}

void UBinaryTree::PrintTreeInOrder()
{
	PrintTreeInOrder(Root);
	std::cout << std::endl;
}

FNode* UBinaryTree::Search(FNode* AddNode, int Key)
{
	if (AddNode == nullptr)
	{
		return nullptr;
	}
	else if (AddNode->Key == Key)
	{
		return AddNode;
	}
	else if (AddNode->Key < Key)
	{
		return Search(AddNode->Right, Key);
	}
	else
	{
		return Search(AddNode->Left, Key);
	}
}

bool UBinaryTree::Search(int Key)
{
	FNode* result = Search(Root, Key);
	return result == nullptr ? false : true;
}

int UBinaryTree::FindMin(FNode* AddNode)
{
	if (AddNode == nullptr)
	{
		return -1;
	}
	else if (AddNode->Left == nullptr)
	{
		return AddNode->Key;
	}
	else
	{
		return FindMin(AddNode->Left);
	}
}

int UBinaryTree::FindMin()
{
	return FindMin(Root);
}

int UBinaryTree::FindMax(FNode* AddNode)
{
	if (AddNode == nullptr)
	{
		return -1;
	}
	else if (AddNode->Right == nullptr)
	{
		return AddNode->Key;
	}
	else
	{
		return FindMax(AddNode->Right);
	}
}

int UBinaryTree::FindMax()
{
	return FindMax(Root);
}

int UBinaryTree::Successor(FNode* AddNode)
{
	if (AddNode->Right != nullptr)
	{
		return FindMin(AddNode->Right);
	}
	else
	{
		FNode* ParentNode = AddNode->Parent;
		FNode* CurrentNode = AddNode;

		while ((ParentNode != nullptr) && (CurrentNode == ParentNode->Right))
		{
			CurrentNode = ParentNode;
			ParentNode = CurrentNode->Parent;
		}
		return ParentNode == nullptr ? -1 :	ParentNode->Key;
	}
}

int UBinaryTree::Successor(int Key)
{
	FNode* KeyNode = Search(Root, Key);
	return KeyNode == nullptr ? -1 : Successor(KeyNode);
}

int UBinaryTree::Predecessor(FNode* AddNode)
{
	if (AddNode->Left != nullptr)
	{
		return FindMax(AddNode->Left);
	}
	else
	{
		FNode* ParentNode = AddNode->Parent;
		FNode* CurrentNode = AddNode;

		while ((ParentNode != nullptr) && (CurrentNode == ParentNode->Left))
		{
			CurrentNode = ParentNode;
			ParentNode = CurrentNode->Parent;
		}
		return ParentNode == nullptr ? -1 : ParentNode->Key;
	}
}

int UBinaryTree::Predecessor(int Key)
{
	FNode* KeyNode = Search(Root, Key);
	return KeyNode == nullptr ? -1 : Predecessor(KeyNode);
}

FNode* UBinaryTree::Remove(FNode* AddNode, int Key)
{
	if (AddNode == nullptr)
	{
		return nullptr;
	}
	if (AddNode->Key == Key)
	{
		if (AddNode->Left == nullptr && AddNode->Right == nullptr)
		{
			AddNode = nullptr;
		}
		else if (AddNode->Left == nullptr && AddNode->Right != nullptr)
		{
			AddNode->Right->Parent = AddNode->Parent;
			AddNode = AddNode->Right;
		}
		else if (AddNode->Left != nullptr && AddNode->Right == nullptr)
		{
			AddNode->Left->Parent = AddNode->Parent;
			AddNode = AddNode->Left;
		}
		else
		{
			int SuccessorKey = Successor(Key);
			AddNode->Key = SuccessorKey;
			AddNode->Right = Remove(AddNode->Right, SuccessorKey);
		}
	}
	else if (AddNode->Key < Key)
	{
		AddNode->Right = Remove(AddNode->Right, Key);
	}
	else
	{
		AddNode->Left = Remove(AddNode->Left, Key);
	}
	return AddNode;
}

void UBinaryTree::Remove(int Key)
{
	srand(time(nullptr));
	Root = Remove(Root, Key);
	std::cout << std::endl << "Runtime= " << clock() / 1000.0 << " ms" << std::endl;
}

void UBinaryTree::TestAddValueAndTime(FNode* Root)
{
	srand(time(nullptr));
	UBinaryTree* Tree = new UBinaryTree;
	for (int i = 0; i < 262144; i++)
	{
		Tree->Insert(rand() % 262144);
	}
	Tree->PrintTreeInOrder();
	std::cout << std::endl << "Runtime= " << clock() / 1000.0 << " ms" << std::endl;
	Tree->Insert(1000);
	Tree->PrintTreeInOrder();
	std::cout << std::endl << "Runtime= " << clock() / 1000.0 << " ms" << std::endl;
// 	Tree->Insert(1100);
// 	Tree->PrintTreeInOrder();
// 	std::cout << std::endl << "Runtime= " << clock() / 1000.0 << " ms" << std::endl;
	Tree->Remove(1000);
	Tree->PrintTreeInOrder();
	std::cout << std::endl << "Runtime= " << clock() / 1000.0 << " ms" << std::endl;
// 	Tree->Remove(1100);
// 	Tree->PrintTreeInOrder();
// 	std::cout << std::endl << "Runtime= " << clock() / 1000.0 << " ms" << std::endl;
}

int main()
{
	std::cout << "Binary Search Tree" <<std::endl;
 	UBinaryTree* Tree = new UBinaryTree;
	FNode* Root = nullptr;
 	std::cout << "Tree Keys: ";
 	Tree->TestAddValueAndTime(Root);
	return 0;
}