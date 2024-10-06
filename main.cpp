#include <iostream>
#include "SLL_Class.h"
using namespace std;

/*int main()
{
    list l;
    l.add_begin(1);
    l.add_begin(2);
    l.add_begin(3);
    l.add_begin(4);
    l.add_begin(5);
    l.print();
    l.del_pos(3);
    l.print();
    cout<<l.search(3)<<endl;
}*/
/*void main()
{
	list l1, l2;
	l1.add_end(1);
	l1.add_end(2);
	l2.add_end(5);
	l2.add_end(6);
	l2.add_end(7);
	l1.print();
	l2.print();
	l1 = l2;
	l2.add_end(100);
	l1.print();
	l2.print();
}*/
void f(list x)
{
	cout << "begin of f" << endl;
	x.print();
	x.add_begin(100);
	x.del_end();
	x.print();
	cout << "end of f" << endl;
}
void main()
{
	list l;
	l.add_end(3);
	l.add_end(4);
	l.add_end(5);
	l.print();
	f(l);
	l.print();
}
