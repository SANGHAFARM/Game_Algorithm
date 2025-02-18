#include <iostream>

// 삽입 정렬 함수
void InsertionSort(int* array, int length)
{
	// 배열 순회
	for (int i = 1; i < length; i++)
	{
		// 키 뽑기
		int keyValue = array[i];
		int j = i - 1;

		// 셔플링 (교환)
		while (j >= 0 && array[j] > keyValue)
		{
			array[j + 1] = array[j];
			j--;
		}

		// 값 삽입
		array[j + 1] = keyValue;
	}
}

// 배열 출력 함수
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << (i < length - 1 ? ", " : "");
	}

	std::cout << "\n";
}

// 메인 함수 (진입점)
int main()
{
	// 자료 집합
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	// 배열 길이
	int length = sizeof(array) / sizeof(int);

	// 정렬 전 출력
	std::cout << "정렬 전 : ";
	PrintArray(array, length);

	// 정렬
	InsertionSort(array, length);

	// 정렬 후 출력
	std::cout << "정렬 후 : ";
	PrintArray(array, length);
}