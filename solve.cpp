#include <cmath>
bool is_inside(double v1x, double v1y,
	double v2x, double v2y,
	double v3x, double v3y,
	double px, double py)
{
	double expression_1 = (v1x - px)*(v2y - v1y) - (v2x - v1x)*(v1y - py);
	double expression_2 = (v2x - px)*(v3y - v2y) - (v3x - v2x)*(v2y - py);
	double expression_3 = (v3x - px)*(v1y - v3y) - (v1x - v3x)*(v3y - py);
	if ((expression_1 > 0 && expression_2 > 0 && expression_3 > 0) || (expression_1 < 0 && expression_2 < 0 && expression_3 < 0))
		return true;
	else
		return false;
}

unsigned char median(const unsigned char arr[], int N)
{
	if (N % 2 != 0)
		return arr[(N / 2)+1];
	else
	{
		if (arr[N / 2 - 1] <= arr[N / 2])
			return arr[(N / 2) - 1];
		else
			return arr[(N / 2)];
	}
}
