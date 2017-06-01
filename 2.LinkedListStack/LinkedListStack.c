#include "LinkedListStack.h"

void  LLS_CreateStack(LinkedListStack** Stack)
{
	/*  스택을 자유저장소에 생성 */
	*Stack = (LinkedListStack*)malloc(sizeof(LinkedListStack));

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack)) {
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}
	/*  스택을 자유 저장소에서 해제 */
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	/*  데이터를 저장한다. */
	strcpy(NewNode->Data, NewData);

	/*  다음 노드에 대한 포인터는 NULL로 초기화 한다. */
	NewNode->NextNode = NULL;
	return NewNode;/*  노드의 주소를 반환한다. */
}

void  LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		if (Stack->Top != NULL) {
			Stack->Top->NextNode = NewNode;
			Stack->Top = NewNode;
		}
		else {
			Node* OldTop = Stack->List;
			while (OldTop->NextNode != NULL)
			{
				OldTop = OldTop->NextNode;
			}
			OldTop->NextNode = NewNode;
			Stack->Top = NewNode;
		}
	}

}

Node* LLS_Pop(LinkedListStack* Stack)
{
	/*  LLS_Pop() 함수가 반환할 최상위 노드 */

	Node* TopNode = Stack->Top;

	if (Stack->List == TopNode)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		/*  새로운 최상위 노드를 스택의 Top 필드에 등록한다. */
		Node* Current = Stack->List;
		while (Current->NextNode != Stack->Top)
		{
			Current = Current->NextNode;
		}
		Stack->Top = Current;
		Stack->Top->NextNode = NULL;
	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int    Count = 0;
	Node*  Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}
