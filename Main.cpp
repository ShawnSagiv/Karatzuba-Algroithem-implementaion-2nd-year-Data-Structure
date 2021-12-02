#include "Header.h"
#include "Stack.h"




int main()
{
 
	int n;
	int* x;
	int* y;
	int* res;
	string str1, str2;

	// Input From User:
	while (!(cin >> n)) {
		cout << "Error, please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the buffer before taking a new line
	
	getline(cin, str1);
	getline(cin, str2);

	// Checking valid input:
	while (!checkInput(str1, str2, n))
	{
		cout << "Wrong Input" << endl;
		while (!(cin >> n)) {
			cout << "Error, please try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new line
		//cout << "enter first number (max size is " << n << " ) :\n";
		getline(cin, str1);
		//cout << "enter second number (max size is " << n << " ) :\n";
		getline(cin, str2);
	}
	
	
	// converting input string into integer arrays:
	x = stringToNumber(str1, n);
	y = stringToNumber(str2, n);
	vector<int> vx(x, x + n);
	vector<int> vy(y, y + n);
	if (isZreo(x, n) || isZreo(y, n))
	{
		cout << "0";
	}
	else {
		// Question 1:
		res = LongMulti(x, y, n);
		print(res, n);
		cout << endl;

		// Question 2:
		vector<int> res_v = KaratsubaRec(vx, vy, n);
		print(res_v);
		cout << endl;

		// Question 3:
		res_v = Karatsuba(vx, vy, n);
		print(res_v);
	}

	//
	////////////////////////////////////////////////////////////////////////////////
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	LongMulti(x, y, n);
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure1.txt"); // The name of the file
	myfile << "Time taken by function <LongMulti> is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
	////////////////////////////////////////////////////////////////////////////////

	auto start1 = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	KaratsubaRec(vx, vy, n);
	auto end1 = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken1 =
		chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
	time_taken1 *= 1e-9;
	ofstream myfile1("Measure2.txt"); // The name of the file
	myfile1 << "Time taken by function <KaratsubaRec> is : " << fixed
		<< time_taken1 << setprecision(9);
	myfile1 << " sec" << endl;
	myfile1.close();
	////////////////////////////////////////////////////////////////////////////////

	auto start2 = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	Karatsuba(vx, vy, n);	auto end2 = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken2 =
		chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
	time_taken2 *= 1e-9;
	ofstream myfile2("Measure3.txt"); // The name of the file
	myfile2 << "Time taken by function <Karatsuba> is : " << fixed
		<< time_taken2 << setprecision(9);
	myfile2 << " sec" << endl;
	myfile2.close();
	return 0;
}

bool isZreo(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] != 0)
			return false;
	return true;
}
void print(int* res, int size)
{
	if (size == 0)
		cout << 0;
	else {
		for (int i = 0; i < 2 * size; i++)
		{
			if ((res[i] >= 0) && (res[i] <= 9)) //מתעלם מאפסים
				cout << res[i];
		}
	}
}
bool checkInput(string str1, string str2, int size)
{
	int len1, len2;
	len1 = str1.size();
	len2 = str2.size();

	/*
	for (int i = 0; i < len_n; i++) {
		if (!IS_NUM(nsize[i]))
			return WRONG_INPUT;
		if ((nsize[i] == '0') && (i < (len_n - 1))) // there are leading 0's in n.
			return WRONG_INPUT;
	}
	*/
	if (size < 0)
		return false;
	if((!isNumber(str1)) || (!isNumber(str2)))
			return false;

	if ((len1 > size) || (len2 > size) || (len1 < size) || (len2 < size))
		return false;
}
int* stringToNumber(string str, int n)
{
	int len = str.size();
	int i = 0;
	int temp = n - len;
	
		
	int* arr = new int[n];

	// Loop to extract string elements into the array one by one 
	while (i != len)
	{	
		arr[i + temp] = str[i] - '0'; // Convert each character into a digit 
		i++;
	}
	return arr;
}
int arrayToNum(string arr, int size)
{
	int mult = 1;
	int num=0;
	for (int i = size-1; i >=0; i--)
	{
		num += (arr[i]-'0') * mult;
		mult *= 10;
	}
	return num;
		
}
bool isNumber(string str)
{
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (!IS_NUM(str[i]))
			return false;
	}
	return true;
}