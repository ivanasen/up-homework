#include <iostream>

using namespace std;

enum Position { OUTSIDE, BORDER, INSIDE };

Position collides_rect(double point_x, double point_y, double x_rect, double y_rect, double w, double h)
{
	if ((point_x > x_rect) && (point_x < x_rect + w) && (point_y > y_rect) && (point_y < y_rect + h))
	{
		return INSIDE;
	}

	bool is_on_top_or_bottom_border = (point_x > x_rect && point_x < x_rect + w) &&
									  (point_y == y_rect || point_y == y_rect + h);
	bool is_on_left_or_right_border = (point_y >= y_rect && point_y <= y_rect + h) &&
									  (point_x == x_rect || point_x == x_rect + w);
	if (is_on_top_or_bottom_border || is_on_left_or_right_border)
	{
		return BORDER;
	}

	return OUTSIDE;
}

Position evaluate_point(double x, double y)
{
	// Check smallest inner rect
	short collideInnerSmall = collides_rect(x, y, 3, -0.5, 2.5, 2 / 5);
	if (collideInnerSmall == INSIDE)
	{
		return OUTSIDE;
	}
	if (collideInnerSmall == BORDER)
	{
		//If the point is on the left or top border of the smallest rect then it's outside
		if (x == 3 || y == -0.5 + 2.5)
		{
			return OUTSIDE;
		}
		return BORDER;
	}

	// Check medium inner rect
	short collideInnerMedium = collides_rect(x, y, 3, 2, 4, 2.5);
	if (collideInnerMedium == INSIDE)
	{
		return OUTSIDE;
	}
	if (collideInnerMedium == BORDER)
	{
		return BORDER;
	}

	// Chech biggest inner rect
	short collideInnerBig = collides_rect(x, y, -1, -2, 4, 4);
	if (collideInnerBig == INSIDE)
	{
		return OUTSIDE;
	}
	if (collideInnerBig == BORDER)
	{
		return BORDER;
	}

	return collides_rect(x, y, -4, -2.5, 13, 8.5); //Is it in the big rect
}

int main()
{
	double x, y;
	cin >> x >> y;

	Position result = evaluate_point(x, y);
	cout << result;

	return 0;
}
