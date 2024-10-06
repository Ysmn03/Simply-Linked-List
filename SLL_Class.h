struct node
{
	int data;
	node* next;
	node(int d,node *n=0)
	{
		data = d;
		next = n;
	}
};
enum error{underflow,out,success};
class list
{
	node* head;
public:
	list();
	bool empty();
	void print();
	int size();
	void add_begin(int el);
	void add_end(int el);
	bool add_pos(int el, int pos);
	bool del_begin();
	bool del_end();
	error del_pos(int pos);
	error del_el(int el);
	int search(int el);
	list(list& o); //copy constructor to solve shallow copy
	void operator=(list& o); //to solve shallow copy
	~list(); //to solve memory leak
	void addAFzero(int el);
};