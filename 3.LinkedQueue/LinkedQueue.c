#include "LinkedQueue.h"

void  LQ_CreateQueue(LinkedQueue** Queue)
{
	/*  ť�� ��������ҿ� ���� */
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Count = 0;
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
}

void LQ_DestroyQueue(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty(Queue)) {
		Node * Pop = LQ_Dequeue(Queue);
		LQ_DestroyNode(Pop);
	}
	/*  ť�� ���� ����ҿ��� ���� */
	free(Queue);
}

Node* LQ_CreateNode(char* NewData)
{
	Node *NewNode = (Node*)malloc(sizeof(NewNode));
	NewNode->Data = (char*)malloc(strlen(NewData));
	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL;
	return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

void  LQ_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}
	Queue->Count++;
}

Node* LQ_Dequeue(LinkedQueue* Queue)
{
	/*  LQ_Dequeue() �Լ��� ��ȯ�� �ֻ��� ��� */
	Node* Front = Queue->Front;

	if (Front->NextNode == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else {
		Queue->Front = Queue->Front->NextNode;
	}
	Queue->Count--;

	return Front;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
	return  (Queue->Count);
}