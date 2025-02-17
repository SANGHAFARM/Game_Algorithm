#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// ���� �Լ� (Merge)
// array : ������ �迭 ����
// leftArray : ���� �迭 ����
// leftArrayLength : ���� �迭 ũ��
// rightArray : ������ �迭 ����
// rightArrayLength : ������ �迭 ũ��
void Merge(int* array, int* leftArray, int leftArrayLength, int* rightArray, int rightArrayLength)
{
	// �ε��� ���� ����
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// ����/������ �迭�� ��Ҹ� ���ϸ鼭 ���� ������ array�� �� �Ҵ�
	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		// ����/������ ��
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex;
		}
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex;
		}

		++mergedIndex;
	}

	// �� �������� ���� ���� �迭 ��Ҹ� ���� �迭�� ����
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++mergedIndex;
		++leftIndex;
	}

	// �� �������� ���� ������ �迭 ��Ҹ� ���� �迭�� ����
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++mergedIndex;
		++rightIndex;
	}
}

// ���� �Լ� (MergeSort)
void MergeSort(int* array, int length)
{
	// Ż�� ����
	if (length <= 1)
	{
		return;
	}

	// �迭 ���� (������)
	int mid = length / 2;

	// ����/������ �迭�� ���� Ȯ��
	int* leftArray = new int[mid];
	int* rightArray = new int[length - mid];

	// �� ����
	memcpy(leftArray, array, sizeof(int) * mid);
	memcpy(rightArray, array + mid, sizeof(int) * (length - mid));

	// ����� ȣ��
	// ���� �迭�� ���� ��� ȣ��
	MergeSort(leftArray, mid);

	// ������ �迭�� ���� ��� ȣ��
	MergeSort(rightArray, length - mid);

	// ����
	Merge(array, leftArray, mid, rightArray, length - mid);

	// �޸� ����
	delete[] leftArray;
	delete[] rightArray;
}

// �迭 ��� �Լ�.
void PrintArray(int array[], int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix] << (ix < length - 1 ? ", " : "");
	}

	std::cout << "\n";
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �迭.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// ���� ���
	int length = _countof(array);

	// ���� �� ���
	std::cout << "���� �� : ";
	PrintArray(array, length);

	// ����
	MergeSort(array, length);

	// ���� �� ���
	std::cout << "���� �� : ";
	PrintArray(array, length);
}

//#include <iostream>
//
//void divide(int lt, int rt, int* array, int* tmpArray)
//{
//	int mid;
//	int p1, p2, p3;
//
//	if (lt < rt)
//	{
//		mid = (lt + rt) / 2;
//
//		divide(lt, mid, array, tmpArray);
//		divide(mid + 1, rt, array, tmpArray);
//
//		p1 = lt;
//		p2 = mid + 1;
//		p3 = lt;
//
//		while (p1 <= mid && p2 <= rt)
//		{
//			if (array[p1] < array[p2])
//			{
//				tmpArray[p3] = array[p1];
//				p1++;
//				p3++;
//			}
//			else
//			{
//				tmpArray[p3] = array[p2];
//				p2++;
//				p3++;
//			}
//		}
//
//		while (p1 <= mid)
//		{
//			tmpArray[p3] = array[p1];
//			p1++;
//			p3++;
//		}
//
//		while (p2 <= rt)
//		{
//			tmpArray[p3] = array[p2];
//			p2++;
//			p3++;
//		}
//
//		for (int i = lt; i <= rt; i++)
//		{
//			array[i] = tmpArray[i];
//		}
//	}
//}
//
//int main()
//{
//	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
//	int length = _countof(array);
//
//	int* tmp = new int[length];
//
//	divide(0, length - 1, array, tmp);
//
//	for (int i = 0; i < length; i++)
//	{
//		std::cout << array[i] << " ";
//	}
//
//	delete[] tmp;
//}