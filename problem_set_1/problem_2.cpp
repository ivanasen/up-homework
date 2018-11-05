#include <iostream>

using namespace std;

enum class Position
{
	OUTSIDE,
	BORDER,
	INSIDE
};

Position collides_rect(double point_x, double point_y, double x_rect, double y_rect, double w, double h)
{
	if ((point_x > x_rect) && (point_x < x_rect + w) && (point_y > y_rect) && (point_y < y_rect + h))
	{
		return Position::INSIDE;
	}

	bool is_on_top_or_bottom_border = (point_x > x_rect && point_x < x_rect + w) &&
									  (point_y == y_rect || point_y == y_rect + h);
	bool is_on_left_or_right_border = (point_y >= y_rect && point_y <= y_rect + h) &&
									  (point_x == x_rect || point_x == x_rect + w);
	if (is_on_top_or_bottom_border || is_on_left_or_right_border)
	{
		return Position::BORDER;
	}

	return Position::OUTSIDE;
}

Position evaluate_point(double x, double y)
{
	// Check smallest inner rect
	Position collideInnerSmall = collides_rect(x, y, 3, -0.5, 2.5, 2 / 5);
	if (collideInnerSmall == Position::INSIDE)
	{
		return Position::OUTSIDE;
	}
	if (collideInnerSmall == Position::BORDER)
	{
		//If the point is on the left or top border of the smallest rect then it's outside
		if (x == 3 || y == -0.5 + 2.5)
		{
			return Position::OUTSIDE;
		}
		return Position::BORDER;
	}

	// Check medium inner rect
	Position collideInnerMedium = collides_rect(x, y, 3, 2, 4, 2.5);
	if (collideInnerMedium == Position::INSIDE)
	{
		return Position::OUTSIDE;
	}
	if (collideInnerMedium == Position::BORDER)
	{
		return Position::BORDER;
	}

	// Chech biggest inner rect
	Position collideInnerBig = collides_rect(x, y, -1, -2, 4, 4);
	if (collideInnerBig == Position::INSIDE)
	{
		return Position::OUTSIDE;
	}
	if (collideInnerBig == Position::BORDER)
	{
		return Position::BORDER;
	}

	return collides_rect(x, y, -4, -2.5, 13, 8.5); //Is it in the big rect
}

int main()
{
	double x, y;
	cin >> x >> y;

	Position result = evaluate_point(x, y);
	cout << (int)result;

	return 0;
}
