#ifndef LIST_H
#define LIST_H


struct Node
{
	Node *prev;
	int data;
	Node *next;
	Node(Node *p, int d, Node *n) :prev(p), data(d), next(n) {}
};

class node_wrapper
{
	friend class List;
public:
	node_wrapper(Node *ptr) :node(ptr) {}
	int operator*() const { return node->data; }
	node_wrapper &operator++() { node = node->next; return *this; }
	node_wrapper &operator--() { node = node->prev; return *this; }
	bool operator==(node_wrapper ob) const { return ob.node == node; }
	bool operator!=(node_wrapper ob) const { return ob.node != node; }
private:
	Node *node;
};

class List
{
public:
	List();
	~List();

	void push_back(int);
	void push_front(int);
	void insert(node_wrapper, int);

	void pop_front();
	void pop_back();
	void erase(node_wrapper);

	node_wrapper begin() { return node_wrapper(first); }
	node_wrapper end() { return node_wrapper(0); }

	int size() const { return size_; }
private:
	Node *first;
	Node *last;
	int size_;

	void _insert(Node *, const int);
	void _erase(Node *);
};

#endif 