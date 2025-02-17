#include <iostream>
#include <queue>
#include <vector>
#include <string>

// �̷� Ž��
// ��ġ ����ü
struct Location
{
	Location(int row = 0, int col = 0)
		: row(row), col(col)
	{
	}

	int row;
	int col;
};

// �� ����
int mazeSize = 6;
char startMark = 'e';
char destinationMark = 'x';
std::vector<std::vector<char>> map;
//= {
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};

// �̵��Ϸ��� ��ġ�� �̵� ������ ��ġ���� Ȯ���ϴ� �Լ�
bool IsValid(int row, int col)
{
	// Out if index �˻�
	if (row < 0 || row >= mazeSize || col < 0 || col >= mazeSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == destinationMark;
}

// �� ��� �� ���� ��ġ �˻� �Լ�
void FindStartLocation(int& row, int& col)
{
	// ��
	for (int i = 0; i < mazeSize; i++)
	{
		// ��
		for (int j = 0; j < mazeSize; j++)
		{
			// ���� ��ġ�� ã������ ������ �Ķ���Ϳ� ���
			if (map[i][j] == startMark)
			{
				row = i;
				col = j;
			}

			// �� ���
			std::cout << map[i][j] << " ";
		}
		// ����
		std::cout << "\n";
	}
}

void EscapeMaze()
{
	// ���� ��ġ
	int row = 0;
	int col = 0;
	FindStartLocation(row, col);

	// Ž���� ����� ť ����
	std::queue<Location> queue;

	// ���� ��ġ �߰�
	queue.emplace(Location(row, col));

	// Ž��
	while (!queue.empty())
	{
		// ť���� ���� �տ� ��ġ�� ������ ����
		Location current = queue.front();
		queue.pop();

		// ���Ǹ� ���� ����
		row = current.row;
		col = current.col;

		// Ž���� ��ġ ���
		std::cout << "(" << current.row << ", " << current.col << ") ";

		// Ż�� ���� (��ǥ ������ ������ ���)
		if (map[current.row][current.col] == destinationMark)
		{
			std::cout << "\n�̷� Ž�� ����\n";
			return;
		}

		// �湮�� ��ġ�� �ٸ� ���ڷ� ����
		map[current.row][current.col] = '.';

		// Ž���� ��ġ�� ť�� �ֱ�
		// ��/��/��/��
		if (IsValid(row - 1, col))
		{
			queue.emplace(Location(row - 1, col));
		}
		if (IsValid(row + 1, col))
		{
			queue.emplace(Location(row + 1, col));
		}
		if (IsValid(row, col - 1))
		{
			queue.emplace(Location(row, col - 1));
		}
		if (IsValid(row, col + 1))
		{
			queue.emplace(Location(row, col + 1));
		}
	}

	// Ž�� ����
	std::cout << "\n�̷� Ž�� ����\n";
}

//bool ParseMap(const char* path, char& startMark, char& destnationMark)
//{
//	FILE* file = nullptr;
//	fopen_s(&file, path, "r");
//
//	if (file == nullptr)
//	{
//		return false;
//	}
//
//	char buffer[256] = {};
//	if (fgets(buffer, 256, file) == nullptr)
//	{
//		fclose(file);
//		return false;
//	}
//
//	map.clear();
//
//	sscanf_s(buffer, "size: %d start: %c destination: %c", &mazeSize, &startMark, (unsigned)sizeof(char), &destinationMark, (unsigned)sizeof(char));
//
//	fread_s(buffer, 256, sizeof(char), 256, file);
//
//	char seps[] = " ,\n";
//	char* token;
//	char* nextToken;
//	token = strtok_s(buffer, seps, &nextToken);
//
//	while (token != nullptr)
//	{	
//		std::vector<char> tmp;
//
//		while (token != nullptr)
//		{
//			if (tmp.size() == mazeSize)
//			{					
//				break;
//			}
//
//			if (token != nullptr)
//			{
//				tmp.emplace_back(token[0]);
//				token = strtok_s(nullptr, seps, &nextToken);
//			}
//		}
//	
//		if (tmp.size() > 0)
//		{
//			map.emplace_back(tmp);
//		}
//	}
//
//	fclose(file);
//	return true;
//}

// �� ������ ���� �ʿ��� ������ �����ϴ� �Լ�.
bool ParseMap(const char* path, char& startMark, char& destinationMark)
{
	// ���� ����.
	FILE* file = nullptr;
	fopen_s(&file, path, "r");
	if (file)
	{
		// ù �� �б�.
		char buffer[2048] = { };
		if (!fgets(buffer, 2048, file))
		{
			fclose(file);
			return false;
		}

		// �� ������ ����.
		map.clear();

		// �� ũ�� ���� �� ����/���� ���� ���� ����.
		sscanf_s(buffer, "size: %d start: %c destination: %c", &mazeSize, &startMark, 1, &destinationMark, 1);

		// �� ������ ������ ���� �ӽ� �迭 ����.
		std::vector<std::string> lines;
		lines.reserve(mazeSize);

		// ù ���� ������ ������ �����͸� �� ���� �б�.
		// ������ ���� ��ġ.
		auto currentPosition = ftell(file);
		// ������ ��ġ�� �̵�.
		fseek(file, 0, SEEK_END);
		// ��ġ ����.
		auto endPosition = ftell(file);
		// ũ�� ���.
		int size = (int)(endPosition - currentPosition);
		// rewind.
		fseek(file, currentPosition, SEEK_SET);

		// ������ �б�.
		fread_s(buffer, 2048, size, 1, file);

		// ���� �Ľ�.
		char* context = nullptr;
		char* splitString = strtok_s(buffer, "\n", &context);
		if (splitString)
		{
			lines.emplace_back(splitString);
		}

		while (context)
		{
			splitString = strtok_s(nullptr, "\n", &context);
			if (!splitString)
			{
				break;
			}

			lines.emplace_back(splitString);
		}

		// ���κ� �Ľ� ������ ����.
		std::vector<char> line;
		line.reserve(mazeSize);

		// ������ ���� null ����.
		splitString = nullptr;

		// ���� �迭�� ��ȸ�ϸ鼭 �Ľ� ó��.
		for (auto& item : lines)
		{
			// ������ ���� ����.
			context = nullptr;

			// ù ĭ ó��.
			splitString = strtok_s(const_cast<char*>(item.c_str()), ",", &context);
			if (splitString)
			{
				line.emplace_back(splitString[0]);
			}

			// �� ��° ĭ���ʹ� ����.
			while (context)
			{
				splitString = strtok_s(nullptr, ",", &context);
				if (!splitString)
				{
					break;
				}

				line.emplace_back(splitString[0]);
			}

			// ó���� ���� ������ �ʿ� �߰�.
			map.emplace_back(line);
			line.clear();
		}

		// ���� �ݱ�.
		fclose(file);
		return true;
	}

	return false;
}

int main()
{
	ParseMap("../Assets/Map2.txt", startMark, destinationMark);
	EscapeMaze();
}