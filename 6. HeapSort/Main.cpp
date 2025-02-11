#include <iostream>
#include <vector>

// �� ����� (Heapify) �Լ�
void Heapify(std::vector<int>& array, int length, int idx)
{
    while (true)
    {
        // �� ������ ���� �ε��� ����
        int largest = idx;

        // ���� �ڼ� �ε���
        int left = 2 * idx + 1;

        // ������ �ڼ� �ε���
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

// �� ���� �Լ� (HeapSort)
void HeapSort(std::vector<int>& array)
{
    // ��ü ũ��
    int length = (int)array.size();

    // �� ����
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        // �� �����
        Heapify(array, length, i);
    }

    // ����
    for (int i = length - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]);
        Heapify(array, i, 0);
    }
}


// �迭 ��� �Լ�.
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
	// �迭.
	std::vector<int> array = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

    // ���� �� ���
    std::cout << "���� �� : ";
    PrintArray(array);

    // ����
    HeapSort(array);

    // ���� �� ���
    std::cout << "���� �� : ";
    PrintArray(array);
}