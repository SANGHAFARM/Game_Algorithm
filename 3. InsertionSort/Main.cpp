#include <iostream>

// ���� ���� �Լ�
void InsertionSort(int* array, int length)
{
	// �迭 ��ȸ
	for (int i = 1; i < length; i++)
	{
		// Ű �̱�
		int keyValue = array[i];
		int j = i - 1;

		// ���ø� (��ȯ)
		while (j >= 0 && array[j] > keyValue)
		{
			array[j + 1] = array[j];
			j--;
		}

		// �� ����
		array[j + 1] = keyValue;
	}
}

// �迭 ��� �Լ�
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << (i < length - 1 ? ", " : "");
	}

	std::cout << "\n";
}

// ���� �Լ� (������)
int main()
{
	// �ڷ� ����
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// �迭 ����
	int length = sizeof(array) / sizeof(int);

	// ���� �� ���
	std::cout << "���� �� : ";
	PrintArray(array, length);

	// ����
	InsertionSort(array, length);

	// ���� �� ���
	std::cout << "���� �� : ";
	PrintArray(array, length);
}