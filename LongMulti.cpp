#include "Header.h"
#include <vector>

int* LongMulti(int* x, int* y, int n)
{

	vector<int> reverseRes(2 * n, 0);
	int* res;
	int digit_x, digit_y;
	int xi = 0, yi;
	int carry, sum;
	if (n == 0)
		return nullptr;

	for (int i = n - 1; i >= 0; i--)
	{
		carry = 0;
		digit_x = x[i];
		yi = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			digit_y = y[j];
			sum = digit_x * digit_y + reverseRes[xi + yi] + carry;
			reverseRes[xi + yi] = sum % 10;
			carry = sum / 10;
			yi++;
		}

		if (carry > 0)
			reverseRes[xi + yi] += carry;
		xi++;
	}

	// מתעלם מאפסים
	int i = reverseRes.size() - 1;
	while (i >= 0 && reverseRes[i] == 0)
		i--;

	if (i == -1) // הכפל יצא אפס
	{
		res = new int[1];
		res[0] = 0;
		return res;
	}

	res = new int[i + 1];
	int k = 0;
	while (i >= 0) //הופך את הוקטור
	{
		res[k++] = static_cast<int>(reverseRes[i--]);
	}

	return res;
}