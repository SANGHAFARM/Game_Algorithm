#include <iostream>

// �� ���� ���� ��ȯ�ϴ� �Լ�
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ���� ���� �Լ�
void BubbleSort(int* array, int length)
{
	// ����
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			// �� ���� ��
			if (array[j] > array[j + 1])
			{
				// ��ȯ
				Swap(array[j], array[j + 1]);
			}
		}
	}
}

// ��� �Լ�
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}

	std::cout << "\n";
}

int main()
{
	// �迭
	int array[] = { 5, 3, 2, 8, 10, 11, 6, 4, 9 };

	// �迭 ����
	int length = sizeof(array) / sizeof(array[0]);

	// ���
	std::cout << "���� �� : ";
	PrintArray(array, length);

	// ����
	BubbleSort(array, length);

	// ���� �� ���
	std::cout << "���� �� : ";
	PrintArray(array, length);
}