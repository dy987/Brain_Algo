#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType NewData)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Data = NewData;
	NewNode->Left = NULL;
	NewNode->Right = NULL;

	return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
	if (Tree->Left != NULL)
		BST_DestroyTree(Tree->Left);

	if (Tree->Right != NULL)
		BST_DestroyTree(Tree->Right);

	Tree->Left = NULL;
	Tree->Right = NULL;
	free(Tree);
}

BSTNode*  BST_SearchNode(BSTNode* Tree, ElementType Target)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Data == Target)
		return Tree;
	else if (Tree->Data < Target)
		BST_SearchNode(Tree->Right, Target);
	else
		BST_SearchNode(Tree->Left, Target);
}


BSTNode*  BST_SearchMinNode(BSTNode* Tree)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Left != NULL)
		BST_SearchMinNode(Tree->Left);

	return Tree;
}

void BST_InsertNode(BSTNode* Tree, BSTNode *Child)
{
	if (Tree->Data < Child->Data) {
		if (Tree->Right == NULL)
			Tree->Right = Child;
		else
			BST_InsertNode(Tree->Right, Child);
	}
	else {
		if (Tree->Left == NULL)
			Tree->Left = Child;
		else
			BST_InsertNode(Tree->Left, Child);
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
	BSTNode* RemovedNode = NULL;

	if (Tree == NULL)
		return NULL;

	if (Tree->Data < Target)
		BST_RemoveNode(Tree->Right, Tree, Target);
	else if (Tree->Data > Target)
		BST_RemoveNode(Tree->Left, Tree, Target);
	else
	{
		RemovedNode = Tree;

		//�� ����ΰ�� , �ڽ��� ���� ���
		if (Tree->Left == NULL && Tree->Right == NULL) {
			if (Parent->Left == Tree)
				Parent->Left = NULL;
			else
				Parent->Right = NULL;
		}
		//2���� �ڽ��� �ִ� ���
		else {
			if (Tree->Left != NULL && Tree->Right != NULL) {
				//�ּҰ� ��带 ã�� ���ŵ� ����ڸ��� �̵�
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
				RemovedNode = BST_RemoveNode(Tree, NULL, MinNode->Data);
				Tree->Data = MinNode->Data;
			}
			else { // �ڽ����ϳ� �ΰ��
				BSTNode* Temp = NULL; 

				if (Tree->Left != NULL)
					Temp = Tree->Left;
				else
					Temp = Tree->Right;

				if (Parent->Left == Tree)
					Parent->Left = Temp;
				else
					Parent->Right = Temp;
			}
		}
	}
	return RemovedNode;
}

void BST_InorderPrintTree(BSTNode* Node)
{
	if (Node == NULL)
		return;

	/*  ���� ���� Ʈ�� ��� */
	BST_InorderPrintTree(Node->Left);

	/*  ��Ʈ ��� ��� */
	printf("%d ", Node->Data);

	/*  ������ ���� Ʈ�� ��� */
	BST_InorderPrintTree(Node->Right);
}