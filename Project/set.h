#ifndef SET_HPP
#define SET_HPP

struct Node
{
	Node *parent;
	Node *left;
	Node *right;
	int data;
	Node(int d) :parent(0), left(0), right(0), data(d) {}
};

class node_wrapper
{
public:
	node_wrapper(Node *ptr) :node(ptr) {}
	int operator*() const { return node->data; }
	node_wrapper &operator++();
	node_wrapper &operator--();
	bool operator==(node_wrapper ob) const { return ob.node == node; }
	bool operator!=(node_wrapper ob) const { return ob.node != node; }
private:
	Node *node;
};

class set
{
public:
	set() :root(0) {}

	void insert(const int);
	bool find(const int) const;

	node_wrapper begin() const;
	node_wrapper end() const { return node_wrapper(0); }

	node_wrapper rbegin() const;
	node_wrapper rend() const { return node_wrapper(0); }
private:
	Node *root;
};

#endif