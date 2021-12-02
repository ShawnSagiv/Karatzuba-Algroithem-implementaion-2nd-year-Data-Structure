#pragma once
#include "Header.h"

const int START = 10;
const int AFTER_FIRST = 20;
const int AFTER_SECOND = 30;
const int AFTER_THIRD = 40;

namespace stack {
	class Item {
	private:
		//Func parameters
		vector<int> x;
		vector<int> y;
		int size;

		//Func return values
		vector<int> res_0;
		vector<int> res_1;
		vector<int> res_2;

		// add locals
		vector<int > a;
		vector<int > b;
		vector<int > c;
		vector<int > d;
		vector<int> a_add_b;
		vector<int> c_add_d;
		vector<int>res0_add_res1;
		vector<int> res_3;
		vector<int> res_4;

		int line;

	public:
		Item() { line = START; size = 0; }
		Item(int n, vector<int> _x, vector<int> _y) : size(n), x(_x), y(_y) {line = START;}
		Item(const Item& other);
		void operator=(const Item& other);
		
		void operator()(vector<int> _x, vector<int> _y, int n);
		// get
		vector<int> get_x(void)const { return x; }
		vector<int> get_y(void)const { return y; }
		vector<int> get_res0(void)const { return res_0; }
		vector<int> get_res1(void)const { return res_1; }
		vector<int> get_res2(void)const { return res_2; }
		vector<int> get_res3(void)const { return res_3; }
		vector<int> get_res4(void)const { return res_4; }

		vector<int> get_a(void) const { return a; }
		vector<int> get_b(void)const { return b; }
		vector<int> get_c(void)const { return c; }
		vector<int> get_d(void)const { return d; }

		vector<int> get_ab(void) const { return a_add_b; }
		vector<int> get_cd(void) const { return c_add_d; }
		vector<int> get_res01(void) const { return res0_add_res1; }

		int getsize(void) const { return max(x.size(), y.size()); }
		int getline(void)const { return line; }
		int size_x(void)const { return x.size(); }
		int size_y(void) const { return y.size(); }
		vector<int>::iterator begin_x() { return x.begin(); }
		vector<int>::iterator begin_y() { return y.begin(); }

		// set
		void insert_x(vector<int>::iterator it) { x.insert(it, 0); }
		void insert_y(vector<int>::iterator it) { y.insert(it, 0); }
		bool set(vector<int>& _x, vector<int>& _y) { this->x = _x; this->y = _y; }
		bool set_res0(vector<int> res) { this->res_0 = res; return true;}
		bool set_res1(vector<int> res) { this->res_1 = res; return true; }
		bool set_res2(vector<int> res) { this->res_2 = res; return true; }

		bool set_a(vector<int>& _a) { a = _a; return true; }
		bool set_b(vector<int>& _b) { b = _b; return true; }
		bool set_c(vector<int>& _c) { c = _c; return true; }
		bool set_d(vector<int>& _d) { d = _d; return true; }
		bool setline(int _line) { line = _line; return true;}
		bool setsize(int _size) { size = _size; return true; }

		void sum_ab() { vector<int> temp; add(a, b, temp); this->a_add_b = temp; }
		void sum_cd() { vector<int> temp; add(c, d, temp); this->c_add_d = temp; }
		void sum_res01() { vector<int> temp; add(res_0, res_1, temp); this->res0_add_res1 = temp; }
		void sum_res01_4() { vector<int> temp; add(res_0, res_1, temp); this->res_4 = temp; }

		void sub_res201() { res_3 = subtract(res_2, res0_add_res1); }
		bool setZeros_res0()
		{
			for (int i = 0; i < 2 * (size - size / 2); i++)
				res_0.push_back(0);
			return true;
		}

		bool setZeros_res3()
		{
			for (int i = 0; i < (size - size / 2); i++)
				res_3.push_back(0);
			return true;
		}

	};

	
	typedef struct inode {
		Item item;
		inode* next;
		inode* prev;
	}iNode;

	class Stack {
	public:
		Stack() { top = nullptr; } //constructor
		~Stack() { MakeEmpty(); } // destructor

		void Push(Item newItem); // push element X onto the stack
		Item Pop(); // remove the top element
		int IsEmpty() { return top == nullptr; }
		void MakeEmpty();

	private:
		iNode* top; // top is a pointer to a node
	};

}