#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

#define IS_NUM(ch) ((ch>='0')&&(ch<='9'))?true:false 
vector<int> Karatsuba(vector<int> x, vector<int> y, int size);

int* LongMulti(int* x, int* y, int n);
vector<int> KaratsubaRec(vector<int> x, vector<int> y, int size);
void print(vector<int> v);
void add(vector<int> x, vector< int> y, vector<int>& result);
vector<int> subtract(vector<int> x, vector<int> y);

bool isZreo(int* arr, int size);

int* stringToNumber(string str, int n);
bool isNumber(string str);
bool checkInput(string str1, string str2, int size);
int arrayToNum(string arr, int size);
void print(int* res, int size);