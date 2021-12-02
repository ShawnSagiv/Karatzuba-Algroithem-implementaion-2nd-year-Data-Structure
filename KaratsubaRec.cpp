#include "Header.h"
#include <vector>



vector<int> KaratsubaRec(vector<int> x, vector<int> y, int size)
{
	//int length = max(x.size(), y.size());

	if (size == 1)
	{
		vector<int> result;
		int resNum = x.at(0) * y.at(0); 
		while (resNum > 0)
		{
			vector<int>::iterator frnt = result.begin();
			result.insert(frnt, resNum % 10);
			resNum = resNum / 10;
		}
		return result;
	}

	while (x.size() < size)
	{
		vector<int>::iterator it = x.begin();
		x.insert(it, 0);
	}
	while (y.size() < size)
	{
		vector<int>::iterator it = y.begin();
		y.insert(it, 0);
	}
	vector<int>::iterator x_front = x.begin();
	vector<int>::iterator y_front = y.begin();

	auto x_mid= x_front + (size / 2);
	auto x_last = x_front + size;
	auto y_mid = y_front + (size / 2);
	auto y_last = y_front + size;


	vector<int > a(x_front, x_front + (size / 2));
	vector<int > b(x_mid, x_last);
	vector<int > c(y_front, y_front + (size / 2));
	vector<int > d(y_mid, y_last);


	vector<int> res_0 = KaratsubaRec(a, c, max(a.size(), c.size()));
	vector<int> res_1 = KaratsubaRec(b, d, max(b.size(), d.size()));

	vector<int> a_add_b;
	vector<int> c_add_d;

	add(a, b, a_add_b);
	add(c, d, c_add_d);

	vector<int> res_2 = KaratsubaRec(a_add_b, c_add_d, max(a_add_b.size(), c_add_d.size()));
	
	vector<int>res0_add_res1;
	add(res_0, res_1, res0_add_res1);
	vector<int> res_3 = subtract(res_2, res0_add_res1);

	for (int i = 0; i < 2 * (size - size / 2); i++)
		res_0.push_back(0);
	for (int i = 0; i < size - size / 2; i++)
		res_3.push_back(0);

	vector<int> res_4;
	vector<int> result;

	add(res_0, res_1, res_4);
	add(res_4, res_3, result);

	return result;
}


vector<int> subtract(vector<int> x, vector<int> y)
{
	int size = max(x.size(), y.size());

	 int dif = 0;
	vector<int> result(size, 0);
	while (x.size() < size)
	{
		vector<int>::iterator it = x.begin();
		x.insert(it, 0);
	}
	while (y.size() < size)
	{
		vector<int>::iterator it = y.begin();
		y.insert(it, 0);
	}
	vector<int>::iterator it = x.begin();
	vector<int> temp(it, it+size);

	for (int i = size - 1; i >= 0; i--)
	{
		if (temp.at(i) < y.at(i)) {
			temp.at(i - 1)--;
			dif = temp.at(i) + 10 - y.at(i);
		}
		else
			dif = temp.at(i) - y.at(i);
		result.at(i) = (dif % 10);
	}
	return result;
}
/*
vector<int> subtract(vector<int> x, vector<int> y)
{
	int size = max(x.size(), y.size());
	signed int dif;
	vector<int> result(size, 0);

	while (x.size() < size)
	{
		vector<int>::iterator it = x.begin();
		x.insert(it, 0);
	}
	while (y.size() < size)
	{
		vector<int>::iterator it = y.begin();
		y.insert(it, 0);
	}
	for (int i = size - 1; i >= 0; i--)
	{
		dif = (x[i]) - (y[i]);
		if (dif >= 0)
			result[i] = dif;
		else {
			int j = i - 1;
			while (j >= 0)
			{
				x[j] = (x[j] - 1) % 10;
				if (x[j] != 9)
					break;
				else
					j--;
			}
			result[i] = dif + 10;
		}

	}
	return result;
}
*/
void add(vector<int> x, vector< int> y, vector<int>& result)
{
	int carry = 0, sum = 0,size;

	size = max(x.size(), y.size());
	vector<int> res(size, 0);

	while (x.size() < size)
	{
		vector<int>::iterator it = x.begin();
		x.insert(it, 0);
	}

	while (y.size() < size)
	{
		vector<int>::iterator it = y.begin();
		y.insert(it, 0);
	}


	for (int i = size - 1; i >= 0; i--)
	{
		sum = x[i] + y[i] + carry;
		res[i] = sum % 10;
		carry = sum / 10;
	}

	if (carry > 0)
		res.insert(res.begin(), carry);

	result = res;
}

void print(vector<int> v)
{
	int size = v.size();
	int new_size = 0;

	while (v[new_size] == 0)
		new_size++;


	for (int i = new_size; i < size; i++)
		cout << v[i];
}