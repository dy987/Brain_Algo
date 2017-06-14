#include <stdio.h>
#include <stdlib.h>

void MergeSort(int DataSet[], int Start, int End);
void Merge(int DataSet[], int Start, int Middle, int End);


void MergeSort(int DataSet[], int Start, int End)
{
	int Middle = 0;
	if (End - Start < 1)
		return;

	Middle = (Start + End) / 2;

	MergeSort(DataSet, Start, Middle);
	MergeSort(DataSet, Middle + 1, End);

	Merge(DataSet, Start, Middle, End);
}

void Merge(int DataSet[], int Start, int Middle, int End)
{

	int i = 0;
	int left = Start;
	int right = Middle + 1;
	int des = 0;

	int * data = (int*)malloc(sizeof(int)*(End - Start + 1));

	while (left <= Middle && right <= End) {
		if (DataSet[left] < DataSet[right]) {
			data[des++] = DataSet[left++];
		}
		else
			data[des++] = DataSet[right++];
	}

	while (left <= Middle) {
		data[des++] = DataSet[left++];
	}

	while (right <= End) {
		data[des++] = DataSet[right++];
	}

	des = 0;
	for ( i = Start; i <= End; i++)
		DataSet[i] = data[des++];

	free(data);
}



int main(void)
{
	int DataSet[] = { 6, 4, 2, 3, 100, 5, 15, 9, 24, 13 };
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	MergeSort(DataSet, 0, Length - 1);
	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}

