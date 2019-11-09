#include <iostream>
#include "list.h"

List::List() : size_(0), first(0), last(0) {}

List::~List()
{
	if (first)
	{
		Node *current = first;
		Node *tmp;

		while (current)
		{
			tmp = current;
			current = current->next;
			delete tmp;
		}
	}
}

void List::push_back(int value)
{
	Node *newNode = new Node(0, value, 0);

	if (!first)
	{
		first = last = newNode;
	}
	else
	{
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}

	++size_;
}

void List::push_front(int value)
{
	Node *newNode = new Node(0, value, 0);

	if (!first)
	{
		first = last = newNode;
	}
	else
	{
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}

	++size_;
}


void List::insert(node_wrapper nw, int value)
{
	if (first == last)
	{
		push_back(value);
	}
	else
	{
		_insert(nw.node, value);
		++size_;
	}
}

void List::_insert(Node *node, int value)
{
	Node *newNode = new Node(0, value, 0);

	newNode->next = node->next;
	node->next->prev = newNode;
	newNode->prev = node;
	node->next = newNode;
}

void List::pop_front()
{
	if (first == last && first)
	{
		delete first;
		last = 0;
	}
	else if (first)
	{
		Node *tmp = first;
		first = tmp->next;
		first->prev = 0;
		delete tmp;
		--size_;
	}
	else
	{
		std::cout << "List is empty. Nothing to delete" << std::endl;
	}
}

void List::pop_back()
{
	if (first == last && first)
	{
		delete first;
		last = 0;
	}
	else if (first != 0)
	{
		Node *tmp = last;
		last = tmp->prev;
		last->next = 0;
		delete tmp;
		--size_;
	}
	else
	{
		std::cout << "List is empty. Nothing to delete" << std::endl;
	}
}

void List::erase(node_wrapper nw)
{
	if (nw.node)
	{
		_erase(nw.node);
		--size_;
	}
	else
	{
		std::cout << "List is empty. Nothing to delete" << std::endl;
	}
}

void List::_erase(Node *node)
{
	if (node == first)
	{
		pop_front();
	}
	else if (node == last)
	{
		pop_back();
	}
	else
	{
		Node *tmp = node;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete tmp;
	}
}