#include "Stack.h"

namespace stack 
{
	void Stack::Push(Item newItem)
	{
		iNode* tmp = new iNode; // pointer tmp points to the new iNode
		tmp->item = newItem;
		if (IsEmpty()) {
			tmp->next = nullptr;
			tmp->prev = nullptr;
		}
		else {
			tmp->prev = top;
			tmp->next = nullptr; // make the next pointer of the new SNode
		}
		top = tmp; // Point TopOfStack to the new SNode added
	}



	// method Pop()
   // To implement a Pop, advance top of stack to the second item (if there is one).

	Item Stack::Pop()
	{
		if (IsEmpty())
		{
			cout << "Error- stack is empty!" << endl;
		}
		else {

			iNode* tmp = top; // pointer tmp points to the Top of the stack
			Item item = top->item;
			top = top->prev; // point Top to the second element in the stack
			delete tmp; // delete the node pointed to by tmp.
			return item;
		}
	}




	// method MakeEmpty()
	// This method removes each element (iNode) from the stack
	// by calling Pop() within a loop until all elements have been
	// popped from the stack.

	void Stack::MakeEmpty()
	{
		while (!IsEmpty())
			Pop();
	}

	void Item::operator()(vector<int> _x, vector<int> _y, int n)
	{
		this->x = _x;
		this->y = _y;
		this->size = n;

	}
	
	void Item::operator=(const Item& other)
	{
		if (this != &other)
		{
			x = other.get_x();
			y = other.get_y();
			size = other.getsize();

			res_0 = other.get_res0();
			res_1 = other.get_res1();
			res_2 = other.get_res2();


			a = other.get_a();
			b = other.get_b();
			c = other.get_c();
			d = other.get_d();
			a_add_b = other.get_ab();
			c_add_d = other.get_cd();

			res0_add_res1 = other.get_res01();

			res_3 = other.get_res3();
			res_4 = other.get_res4();

			line = other.getline();
		}
	}

	Item::Item(const Item& other)
	{
		if (this != &other)
		{
			x = other.get_x();
			y = other.get_y();
			size = other.getsize();

			res_0 = other.get_res0();
			res_1 = other.get_res1();
			res_2 = other.get_res2();


			a = other.get_a();
			b = other.get_b();
			c = other.get_c();
			d = other.get_d();
			a_add_b = other.get_ab();
			c_add_d = other.get_cd();

			res0_add_res1 = other.get_res01();

			res_3 = other.get_res3();
			res_4 = other.get_res4();

			line = other.getline();
		}
	}

}