#include <iostream>
#include "set.h"

void set::insert(const int value)
{
	Node *newNode = new Node(value);
	if (!root)
	{
		root = newNode;
	}
	else
	{
		Node *current = root;
		Node *last = current;
		while (current)
		{
			last = current;
			if (value < current->data)
			{
				current = current->left;
			}
			else if (value > current->data)
			{
				current = current->right;
			}
		}
		newNode->parent = last;
		if (value < last->data)
		{
			last->left = newNode;
		}
		else if (value > last->data)
		{
			last->right = newNode;
		}
		else
		{
			// ???
		}
	}
}

bool set::find(const int value) const
{
	if (!root)
	{
		return false;
	}
	if (value == root->data)
	{
		return true;
	}
	Node *current = root;
	Node *last = current;
	while (current)
	{
		last = current;
		if (value < current->data)
		{
			current = current->left;
		}
		else if (value > current->data)
		{
			current = current->right;
		}
		else if (value == current->data)
		{
			return true;
		}
	}
	return value == last->data;
}

node_wrapper set::begin() const
{
	if (!root)
	{
		return end();
	}

	Node *current = root;
	while (current->left)
	{
		current = current->left;
	}

	return node_wrapper(current);
}

node_wrapper &node_wrapper::operator++()
{
	if (node->right)
	{
		node = node->right;
		//if(node->left) {
		while (node->left)
		{
			node = node->left;
		}
		//return *this;
	  //}
	  //return *this;
	}
	else
	{
		while (node->parent && node->parent->data < node->data)
		{
			node = node->parent;
		}
		node = node->parent;
		return *this;
	}
}

node_wrapper &node_wrapper::operator--()
{
	if (node->left)
	{
		node = node->left;
		if (node->right)
		{
			while (node->right)
			{
				node = node->right;
			}
			return *this;
		}
		return *this;
	}
	else
	{
		while (node->parent && node->parent->data > node->data)
		{
			node = node->parent;
		}
		node = node->parent;
		return *this;
	}
}

node_wrapper set::rbegin() const
{
	if (!root)
	{
		return rend();
	}

	Node *current = root;
	while (current->right)
	{
		current = current->right;
	}

	return node_wrapper(current);
}