#include "SLL_Class.h"
#include <iostream>
using namespace std;
list::list()
{
	head = NULL;
}
bool list::empty()
{
	if (head == 0)
		return true;
	return false;
}
void list::add_begin(int el)
{
	if (empty())
		head = new node(el);
	else
		head = new node(el, head);
}
void list::print()
{
	node* t=head;
	for (;t!=0;t=t->next)
		cout << t->data << " ";
	cout << endl;
}
int list::size()
{
	node* t=head;
	int count = 0;
	for (; t != 0; t = t->next)
		++count;
	return count;
}
void list::add_end(int el)
{
	if (empty())
		head = new node(el);
	else
	{
		node* t = head;
		for (; t != 0; t = t->next)
			if (t->next == 0)
			{
				t->next = new node(el,0);
				t = t->next;
				//or t=t->next=new node(el,0);
			}
	}
}
bool list::add_pos(int el, int pos)
{
	if (pos<1 || pos>size() + 1)
		return false;
	else
	{
		if (pos == size() + 1)
			add_end(el);
		else
		{
			node* t1=head;
			for (int c = 1; c < pos - 1; ++c)
				t1 = t1->next;
			t1->next = new node(el, t1->next); //add element to the position t->next, were t->next points to this element(t->next=....)
		}
		return true;
	}
}
void list::addAFzero(int el)
{
	node *t = head;
	for (int c = 1; c < size() + 1; ++c)
	{
		if (t->data == 0)
			t->next = new node(el, t->next);
		t = t->next;
	}
}
bool list::del_begin()
{
	if (size()==1)
	{
		delete head;
		head = 0;
		return true;
	}
	else if (empty())
		return false;
	else
	{
		node* t = head;
		head = head->next;
		delete t;
		return true;
	}
}
bool list::del_end()
{
	if (empty())
		return false;
	else if (size() == 1)
		del_begin();
	else
	{
		node* t = head;
		for (; t->next->next != 0; t = t->next);
		delete t->next;
		t->next = 0;
	}
}
error list::del_pos(int pos)
{
	if (pos<1 || pos>size() + 1)
		return out;
	if (empty())
		return underflow;
	if (pos == 1)
		del_begin();
	else
	{
		if (pos == size())
			del_end();
		else
		{
			node* t1 = head, * t2;
			for (int c = 1; c < pos - 1; ++c)
				t1 = t1->next;
			t2 = t1->next->next;
			delete t1->next;
			t1->next = t2;
		}
	}
	return success;
}
int list::search(int el)
{
	node* t=head;
	int c = 1;
	for (; t->next != 0; t = t->next, ++c)
		if (t->data == el)
			return c;
	return -1;
}
error list::del_el(int el)
{
	int index = search(el);
	if (empty())
		return underflow;
	if (index == -1)
		return out;
	return del_pos(index);
}
list::~list()
{
	while (!empty())
		del_begin();
	cout << "NO LIST\n";
}
void list::operator=(list& o)
{
	while (!empty())
		del_end();
	if (!o.empty())
	{
		node* t1 = o.head, * t2;
		t2 = head = new node(t1->data, 0);
		while (t1->next != 0)
		{
			t1 = t1->next;
			t2 = t2->next = new node(t1->data);
		}
	}
	else
		head = 0;
}
list::list(list& o)
{
	if (!o.empty())
	{
		node* t1 = o.head, * t2;
		t2 = head = new node(t1->data);
		while (t1->next != 0)
		{
			t1 = t1->next;
			t2 = t2->next = new node(t1->data);
		}
	}
	else
		head = 0;
}