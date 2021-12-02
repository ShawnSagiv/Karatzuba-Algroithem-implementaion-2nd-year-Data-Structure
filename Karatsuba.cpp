#include "Stack.h"

using namespace stack;



vector<int> Karatsuba(vector<int> x, vector<int> y, int size)
{
	Stack S;
	Item Curr(size, x, y);
	Item Next;
	vector<int> returnValue;
	
	
	S.Push(Curr);
	while (!S.IsEmpty())
	{
		Curr = S.Pop();
		if (Curr.getline() == START)
		{
			if (Curr.getsize() == 1)
			{
				vector<int> result;
				int resNum = Curr.get_x()[0] * Curr.get_y()[0];
				while (resNum > 0)
				{
					vector<int>::iterator it = result.begin();
					result.insert(it, resNum % 10);
					resNum = resNum / 10;
				}
				returnValue = result;
			}
			else {
				while (Curr.size_x() < Curr.getsize())
				{
					vector<int>::iterator it = Curr.begin_x();
					Curr.insert_x(it);
				}
				while (Curr.size_y() < Curr.getsize())
				{
					vector<int>::iterator it = Curr.begin_y();
					Curr.insert_y(it);
				}

				vector<int>::iterator x_front = Curr.begin_x();
				vector<int>::iterator y_front = Curr.begin_y();

				auto x_mid = x_front + (Curr.getsize() / 2);
				auto x_last = x_front + Curr.getsize();
				auto y_mid = y_front + (Curr.getsize() / 2);
				auto y_last = y_front + Curr.getsize();

				vector<int > _a(x_front, x_front + (Curr.getsize() / 2));
				vector<int > _b(x_mid, x_last);
				vector<int > _c(y_front, y_front + (Curr.getsize() / 2));
				vector<int > _d(y_mid, y_last);

				Curr.set_a(_a);
				Curr.set_b(_b);
				Curr.set_c(_c);
				Curr.set_d(_d);

				Curr.setline(AFTER_FIRST);
				S.Push(Curr);
				Next(Curr.get_a(), Curr.get_c(), (Curr.getsize())/2); // כמו אתחול בCURR
				S.Push(Next);
			}
		}
		else if (Curr.getline() == AFTER_FIRST) 
		{
			Curr.set_res0(returnValue);
			Curr.setline(AFTER_SECOND);
			S.Push(Curr);
			Next(Curr.get_b(), Curr.get_d(), (Curr.getsize()) / 2); // כמו אתחול בCURR
			S.Push(Next);
			
		}
		else if (Curr.getline() == AFTER_SECOND)
		{
			Curr.set_res1(returnValue);
			Curr.sum_ab();
			Curr.sum_cd();
			Curr.setline(AFTER_THIRD);
			S.Push(Curr);
			Next(Curr.get_ab(), Curr.get_cd(), (Curr.getsize()) / 2); // כמו אתחול בCURR
			S.Push(Next);


		}
		else if (Curr.getline() == AFTER_THIRD)
		{
			Curr.set_res2(returnValue);
			Curr.sum_res01();
			Curr.sub_res201();
			//int tempSize = Curr.getsize();
			Curr.setZeros_res0();
			Curr.setZeros_res3();

			Curr.sum_res01_4();

			vector<int> result;
			add(Curr.get_res4(), Curr.get_res3(), result);
			returnValue = result;
		}
	}
	return returnValue;
}