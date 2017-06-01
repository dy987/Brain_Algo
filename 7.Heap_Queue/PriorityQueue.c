#include "PriorityQueue.h"

PriorityQueue* PQ_Create(int IntitialSize)
{
	PriorityQueue *NewPQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	NewPQ->Capacity = IntitialSize;
	NewPQ->UsedSize = 0;
	NewPQ->Nodes = (PQNode *)malloc(sizeof(PQNode) * IntitialSize);

	return NewPQ;
}

void  PQ_Destroy(PriorityQueue* PQ)
{
	free(PQ->Nodes);
	free(PQ);
}

void  PQ_Enqueue(PriorityQueue* PQ, PQNode NewNode)
{
	int Current = PQ->UsedSize;
	int Parent = PQ_GetParent(Current);
	
	if (PQ->UsedSize == PQ->Capacity)
	{
		if (PQ->Capacity == 0)
			PQ->Capacity = 1;

		PQ->Capacity *= 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}

	PQ->Nodes[Current] = NewNode;

	//정렬
	while (Current > 0 && PQ->Nodes[Current].Priority < PQ->Nodes[Parent].Priority)
	{
		PQ_SwapNodes(PQ, Current, Parent);
		Current = Parent;
		Parent = PQ_GetParent(Parent);
	}

	PQ->Nodes[Current] = NewNode;
	PQ->UsedSize++;
}

void PQ_SwapNodes(PriorityQueue* PQ, int Index1, int Index2)
{
	PQNode* Temp = (PQNode*)malloc(sizeof(PQNode));

	memcpy(Temp, &PQ->Nodes[Index2], sizeof(PQNode));
	memcpy(&PQ->Nodes[Index2], &PQ->Nodes[Index1], sizeof(PQNode));
	memcpy(&PQ->Nodes[Index1], Temp, sizeof(PQNode));
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root)
{
	int Parent = 0;
	int Left = 0;
	int Right = 0;

	memcpy(Root, &PQ->Nodes[0], sizeof(PQNode));
	memset(&PQ->Nodes[0], 0, sizeof(PQNode));

	PQ->UsedSize--;
	PQ_SwapNodes(PQ, 0, PQ->UsedSize);

	
	while (1)
	{
		Left = PQ_GetLeftChild(Parent);
		Right = Left + 1;

		int SelectedChild = 0;

		if (Left >= PQ->UsedSize) // 왼쪽 자식 없음
			break;
		
		if (Right >= PQ->UsedSize) // 오른쪽 자식은 없지만 왼쪽은 있음
		{
			SelectedChild = Left;
		}
		else { // 양쪽 자식 우선순위 비교
			if (PQ->Nodes[Left].Priority > PQ->Nodes[Right].Priority)
				SelectedChild = Right;
			else
				SelectedChild = Left;
		}

		if (PQ->Nodes[SelectedChild].Priority < PQ->Nodes[Parent].Priority)
		{
			PQ_SwapNodes(PQ, Parent, SelectedChild);
			Parent = SelectedChild;
		}
		else
			break;
	}

}

int PQ_GetParent(int Index)
{
	return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild(int Index)
{
	return (2 * Index) + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ)
{
	return (PQ->UsedSize == 0);
}