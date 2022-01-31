#include <iostream>

struct Node 
{
	int Value;
	Node* Left;
	Node* Right;
};

class BinaryTree 
{
public:
	BinaryTree();
	~BinaryTree();
	void Insert(int Key);
	Node* Search(int Key);
	void DestroyTree();
	void InorderTree();
	void PostorderPrint();
	void PreorderPrint();
	void DestroyTree(Node* Leaf);
	void Insert(int Key, Node* Leaf);
	Node* Search(int Key, Node* Leaf);
	void InorderTree(Node* Leaf);
	void PostorderPrint(Node* Leaf);
	void PreorderPrint(Node* Leaf);

private:
	Node* Root;
};


BinaryTree::BinaryTree() 
{
	Root = nullptr;
}

BinaryTree::~BinaryTree() 
{
	DestroyTree();
}

void BinaryTree::DestroyTree(Node* Leaf) 
{
	if (Leaf != nullptr) {
		DestroyTree(Leaf->Left);
		DestroyTree(Leaf->Right);
		delete Leaf;
	}
}

void BinaryTree::Insert(int Key, Node* Leaf) 
{

	if (Key < Leaf->Value) {
		if (Leaf->Left != nullptr) 
		{
			Insert(Key, Leaf->Left);
		}
		else 
		{
			Leaf->Left = new Node;
			Leaf->Left->Value = Key;
			Leaf->Left->Left = nullptr;
			Leaf->Left->Right = nullptr;
		}
	}
	else if (Key >= Leaf->Value) 
	{
		if (Leaf->Right != nullptr) 
		{
			Insert(Key, Leaf->Right);
		}
		else 
		{
			Leaf->Right = new Node;
			Leaf->Right->Value = Key;
			Leaf->Right->Right = nullptr;
			Leaf->Right->Left = nullptr;
		}
	}

}

void BinaryTree::Insert(int Key) 
{
	if (Root != nullptr) 
	{
		Insert(Key, Root);
	}
	else 
	{
		Root = new Node;
		Root->Value = Key;
		Root->Left = nullptr;
		Root->Right = nullptr;
	}
}

Node* BinaryTree::Search(int Key, Node* Leaf) 
{
	if (Leaf != nullptr) 
	{
		if (Key == Leaf->Value) 
		{
			return Leaf;
		}
		if (Key < Leaf->Value) 
		{
			return Search(Key, Leaf->Left);
		}
		else 
		{
			return Search(Key, Leaf->Right);
		}
	}
	else 
	{
		return 0;
	}
}

Node* BinaryTree::Search(int Key) 
{
	return Search(Key, Root);
}

void BinaryTree::DestroyTree() 
{
	DestroyTree(Root);
}

void BinaryTree::InorderTree() 
{
	InorderTree(Root);
	std::cout << "\n";
}

void BinaryTree::InorderTree(Node* Leaf) {
	if (Leaf != nullptr) 
	{
		InorderTree(Leaf->Left);
		std::cout << Leaf->Value << ",";
		InorderTree(Leaf->Right);
	}
}

void BinaryTree::PostorderPrint() 
{
	PostorderPrint(Root);
	std::cout << "\n";
}

void BinaryTree::PostorderPrint(Node* Leaf) 
{
	if (Leaf != nullptr) 
	{
		InorderTree(Leaf->Left);
		InorderTree(Leaf->Right);
		std::cout << Leaf->Value << ",";
	}
}

void BinaryTree::PreorderPrint() 
{
	PreorderPrint(Root);
	std::cout << "\n";
}

void BinaryTree::PreorderPrint(Node* Leaf) 
{
	if (Leaf != nullptr) 
	{
		std::cout << Leaf->Value << ",";
		InorderTree(Leaf->Left);
		InorderTree(Leaf->Right);
	}
}

int main() 
{
	BinaryTree* Tree = new BinaryTree();

	Tree->Insert(10);
	Tree->Insert(6);
	Tree->Insert(14);
	Tree->Insert(5);
	Tree->Insert(8);
	Tree->Insert(11);
	Tree->Insert(18);

	Tree->PreorderPrint();
	Tree->InorderTree();
	Tree->PostorderPrint();

	delete Tree;
}