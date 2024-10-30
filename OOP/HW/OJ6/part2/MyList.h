#pragma once
#include <list>
#include <memory>
#include <iostream>

class MyList
{
	public:

	std::shared_ptr< std::list<int> > pt; // a pointer to the real container
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.

	std::list<int>::iterator forward(int pos) const{
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos--) now++;
		return now;
	}

	MyList(): pt(std::make_shared<std::list<int>>()){

		left = pt->begin();
		right = pt->end();

		// Actually, left = right = pt->end(), because there is no element in the list.
	}

	void append(int i) {

		pt->insert(right, i);

		
		if (left == right)
		{
			left--;
		}


		// insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		// DEBUG !! Why I can't insert i??

	}

	int operator[](int pos) const{
		return *forward(pos); // access the element at the 'pos'
	}

	int& operator[](int pos) {
		return *forward(pos);
	}

	MyList operator()(int a, int b) {
		MyList temp;
		temp.pt = pt;
		temp.left = forward(a);
		temp.right = forward(b);
		return temp;
	}

};

std::ostream& operator<<(std::ostream& out, const MyList &list)
{
	out << "[";
		if (list.left != list.right){
			// std::cout << "LEFT != RIGHT" << std::endl;
			auto now = list.left;
			out << *now;
			now ++;
			for(; now != list.right; now++){
				out << "," << *now;
			}
		}
	out << "]";
	return out;
}