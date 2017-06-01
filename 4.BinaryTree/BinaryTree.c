#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData)
{
	SBTNode * NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Data = NewData;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_DestroyTree(SBTNode* Node)
{
	/*  왼쪽 하위 트리 소멸 */
	if (Node->Left != NULL)
		SBT_DestroyTree(Node->Left);

	/*  오른쪽 하위 트리 소멸 */
	if (Node->Right != NULL)
		SBT_DestroyTree(Node->Right);

	/*  루트 노드 소멸 */
	SBT_DestroyNode(Node);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	/*  루트 노드 출력 */
	printf("%c ", Node->Data);

	/*  왼쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Left);

	/*  오른쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	/*  왼쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Left);

	/*  루트 노드 출력 */
	printf("%c ", Node->Data);

	/*  오른쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	/*  왼쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Left);

	/*  오른쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Right);

	/*  루트 노드 출력 */
	printf("%c ", Node->Data);
}