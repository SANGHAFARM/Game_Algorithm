#include <iostream>
#include <stack>
#include <vector>

// �̷� Ž���� ����� ��ǥ ����ü
struct Location2D
{
	Location2D(int row = 0, int col = 0)
		: row(row), col(col)
	{
	}

	// ��
	int row;
	// ��
	int col;
};

// �� �迭
int mapSize = 0;
std::vector<std::vector<char>> map;
//{
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};

// �̵� ���� ���� �Ǵ� �Լ�
bool IsValidLocation(int row, int col)
{
	if (row < 0 || row >= mapSize || col < 0 || col >= mapSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == 'x';
}

// ���� ���� �˻� �Լ�
void FindStartLocation(int& row, int& col)
{
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			// �� ���
			std::cout << map[i][j] << " ";

			// ���� ������ ��Ÿ���� ���� �˻�
			if (map[i][j] == 'e')
			{
				row = i;
				col = j;
			}
		}

		std::cout << "\n";
	}
}

// �̷� Ż�� �Լ�
void EscapeMaze()
{
	// �� ũ�� Ȯ��
	//mapSize = (int)map.size();

	// ��ġ ������ ���� ���� ����
	int row = 0;
	int col = 0;

	// Ž�� ������ ���� ���� ��ġ ã��
	FindStartLocation(row, col);

	// ���� ����
	std::stack<Location2D> stack;

	// Ž�� ������ ���� ���� ��ġ ���ÿ� ����
	stack.push(Location2D(row, col));

	// �̷� Ž��
	while (!stack.empty())
	{
		// ���� ��ġ ��ȯ
		Location2D current = stack.top();
		stack.pop();

		// Ž�� ��ġ ���
		std::cout << "(" << current.row << ", " << current.col << ") ";

		row = current.row;
		col = current.col;

		// Ż�� ���� Ȯ��
		if (map[current.row][current.col] == 'x')
		{
			std::cout << " \n�̷� Ž�� ����\n";
			return;
		}

		// Ž�� ����
		// �湮�� ���� ��ġ�� ��湮 ������ ���� �ٸ� ������ ǥ��
		map[row][col] = '.';
		
		// ��/��/��/�� ��ġ �� �̵� ������ ��ġ�� ���ÿ� ����
		if (IsValidLocation(row - 1, col))
		{
			stack.push(Location2D(row - 1, col));
		}
		if (IsValidLocation(row + 1, col))
		{
			stack.push(Location2D(row + 1, col));
		}
		if (IsValidLocation(row, col - 1))
		{
			stack.push(Location2D(row, col - 1));
		}
		if (IsValidLocation(row, col + 1))
		{
			stack.push(Location2D(row, col + 1));
		}
	}

	std::cout << " \n�̷� Ž�� ����\n";
}

//bool ParseMap(const char* path)
//{
//	char buffer[256] = {};
//	FILE* file = nullptr;
//	fopen_s(&file, path, "rt");
//
//	if (file == nullptr)
//	{
//		return false;
//	}
//	
//	if (fgets(buffer, 256, file) != nullptr)
//	{
//		char seps[] = " ,\n";
//		char* token;
//		char* nextToken;
//		token = strtok_s(buffer, seps, &nextToken);
//		if (strcmp(token, "size") == 0)
//		{
//			token = strtok_s(nullptr, seps, &nextToken);
//
//			mapSize = token[0] - '0';
//		}
//
//		while (true)
//		{
//			if (fgets(buffer, 256, file) == nullptr)
//			{
//				break;
//			}
//
//			std::vector<char> tmp;
//
//			token = strtok_s(buffer, seps, &nextToken);
//			while (token != nullptr)
//			{
//				if (token != nullptr)
//				{
//					tmp.emplace_back(token[0]);
//					token = strtok_s(nullptr, seps, &nextToken);
//				}
//			}
//
//			if (tmp.size() > 0)
//			{
//				map.emplace_back(tmp);
//			}
//		}
//	}
//
//	fclose(file);
//
//	return true;
//}

// ���� �ҷ��� �ؼ�(�Ľ�, Parsing)
bool ParseMap(const char* path)
{
	// ���� ����
	FILE* file = nullptr;
	fopen_s(&file, path, "r");
	if (file)
	{
		// ù�� �б�
		char buffer[256] = {};
		if (!fgets(buffer, 256, file))
		{
			fclose(file);
			return false;
		}

		// �� ũ�� ����
		sscanf_s(buffer, "size %d", &mapSize);

		// �� ������ ������ ���� �ӽ� �迭 ����
		std::vector<char> line;
		line.reserve(mapSize);

		// �� ������ �ؼ��� ���� ����
		while (fgets(buffer, 256, file))
		{
			// ùĭ ó��
			char* context = nullptr;
			char* splitString = strtok_s(buffer, ",", &context);

			if (splitString)
			{
				line.emplace_back(splitString[0]);
			}

			// ��° �ٺ��ʹ� ����
			while (context)
			{
				splitString = strtok_s(nullptr, ",", &context);
				if (!splitString)
				{
					break;
				}

				line.emplace_back(splitString[0]);
			}

			// ó���� ���� �����͸� �ʿ� �߰�
			map.emplace_back(line);
			line.clear();
		}

		fclose(file);
		return true;
	}
}

int main()
{
	if (ParseMap("../Assets/Map.txt"))
	{
		// �̷� Ž��
		EscapeMaze();
	}
}