//#include <stdio.h>
//
//void Swap(int* A, int* B)
//{
//	int Temp = *A;
//	*A = *B;
//	*B = Temp;
//}
//
//int Partition(int DataSet[], int Left, int Right)
//{
//	int First = Left;
//	int Pivot = DataSet[First];
//
//	Left++;
//
//	while (Left <= Right) {
//		while (DataSet[Left] <= Pivot && Left < Right) {
//			Left++;
//		}
//
//		while (DataSet[Right] >= Pivot && Left <= Right) {
//			Right--;
//		}
//
//		if (Left < Right)
//			Swap(&DataSet[Left], &DataSet[Right]);
//		else
//			break;
//	}
//	Swap(&DataSet[First], &DataSet[Right]);
//	return Right;
//}
//
//void QuickSort(int DataSet[], int Left, int Right)
//{
//	if (Left < Right) {
//		int index = Partition(DataSet, Left, Right);
//
//		QuickSort(DataSet, Left, index - 1);
//		QuickSort(DataSet, index + 1, Right);
//	}
//}
//
//int main(void)
//{
//	int DataSet[] = { 6, 4, 2, 3, 1, 5, 15, 9, 24, 13 };
//	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
//	int i = 0;
//
//	QuickSort(DataSet, 0, Length - 1);
//
//	for (i = 0; i < Length; i++)
//	{
//		printf("%d ", DataSet[i]);
//	}
//
//	printf("\n");
//
//	return 0;
//}


#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

/*  리턴값이
< 0 이면, _elem1이 _elem2보다 작다.
0   이면, _elem1이 _elem2와 같다.
> 0 이면, _elem1이 _elem2보다 크다.  */
int CompareScore(const void *_elem1, const void *_elem2)
{
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2)
		return 1;
	else if (*elem1 < *elem2)
		return -1;
	else
		return 0;
}

int main(void)
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	qsort((void*)DataSet, Length, sizeof(DataSet[0]), CompareScore);

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}
