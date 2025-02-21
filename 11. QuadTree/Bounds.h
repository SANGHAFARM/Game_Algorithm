#pragma once

class Bounds
{
public:
	Bounds(float x, float y, float width = 1, float height = 1)
		: x(x), y(y), width(width), height(height)
	{
	}

	// Getter
	float X() const { return x; }
	float Y() const { return y; }
	float Width() const { return width; }
	float Height() const { return height; }

	float MaxX() const { return x + width; }
	float MaxY() const { return y + height; }

	// ��ħ ���� �Լ�
	bool Intersects(const Bounds& other) const;

private:
	// ���� ��� ����
	float x = 0.0f;
	float y = 0.0f;
	float width = 1.0f;
	float height = 1.0f;
};