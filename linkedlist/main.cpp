/*
Coty Hamilton
*/

#include <iostream>

#include "list.h"

int main()
{
    List<int> mylist;
	List<int>::iterator it1, it2;

	// set some values:
	for (int i = 1; i<10; ++i) mylist.push_back(i * 10);

								// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin(); // ^^
	it2++; it2++; it2++; it2++; it2++; it2++;
	++it1;                      //    ^              ^

	it1 = mylist.erase(it1);   // 10 30 40 50 60 70 80 90
							   //    ^           ^

	it2 = mylist.erase(it2);   // 10 30 40 50 60 80 90
							   //    ^           ^

	++it1;                      //       ^        ^
	--it2;                      //       ^     ^

	mylist.erase(it1, it2);     // 10 30 60 80 90
								//        ^

	std::cout << "mylist contains:";
    it2 = mylist.end();
	for (it1 = mylist.begin(); it1 != it2; ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

    return 0;
}