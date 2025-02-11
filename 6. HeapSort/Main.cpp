#include <iostream>
#include <vector>

// 힙 만들기 (Heapify) 함수
void Heapify(std::vector<int>& array, int length, int idx)
{
    while (true)
    {
        // 힙 구성을 위한 인덱스 변수
        int largest = idx;

        // 왼쪽 자손 인덱스
        int left = 2 * idx + 1;

        // 오른쪽 자손 인덱스
        int right = 2 * idx + 2;

        if (left < length && array[left] > array[largest])
        {
            largest = left;
        }

        if (right < length && array[right] > array[largest])
        {
            largest = right;
        }

        if (largest == idx)
        {
            break;
        }

        std::swap(array[idx], array[largest]);
        idx = largest;
    }    
}

// 힙 정렬 함수 (HeapSort)
void HeapSort(std::vector<int>& array)
{
    // 전체 크기
    int length = (int)array.size();

    // 힙 구성
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        // 힙 만들기
        Heapify(array, length, i);
    }

    // 정렬
    for (int i = length - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]);
        Heapify(array, i, 0);
    }
}


// 배열 출력 함수.
void PrintArray(std::vector<int>& array)
{
    for (int ix = 0; ix < (int)array.size(); ++ix)
    {
        std::cout << array[ix] << (ix < (int)array.size() - 1 ? ", " : "");
    }

    std::cout << "\n";
}

int main()
{
	// 배열.
	std::vector<int> array = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

    // 정렬 전 출력
    std::cout << "정렬 전 : ";
    PrintArray(array);

    // 정렬
    HeapSort(array);

    // 정렬 후 출력
    std::cout << "정렬 후 : ";
    PrintArray(array);
}