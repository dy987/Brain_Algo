#include "LinkedListStack.h"

void  LLS_CreateStack(LinkedListStack** Stack)
{
	/*  ������ ��������ҿ� ���� */
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
	/*  ������ ���� ����ҿ��� ���� */
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	/*  �����͸� �����Ѵ�. */
	strcpy(NewNode->Data, NewData);

	/*  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. */
	NewNode->NextNode = NULL;
	return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
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
	/*  LLS_Pop() �Լ��� ��ȯ�� �ֻ��� ��� */

	Node* TopNode = Stack->Top;

	if (Stack->List == TopNode)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		/*  ���ο� �ֻ��� ��带 ������ Top �ʵ忡 ����Ѵ�. */
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
