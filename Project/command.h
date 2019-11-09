#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <stack>
#include <iostream>
#include "shape.h"


shape *shape_ptrs[100];
int shape_index = 0;

class u;
class r;
std::stack<u *> undo_ptrs;
std::stack<r *> redo_ptrs;

class command
{
public:
	virtual void execute() = 0;
	virtual ~command() {}
};


class r :public command
{
public:
	r() { std::cout << "r constructor\n"; }
	~r() { std::cout << "~r\n"; }
	void execute()
	{
		if (!redo_ptrs.empty())
		{
			redo_ptrs.top()->redo_execute();
			redo_ptrs.pop();
		}
		else
		{
			std::cerr << "nothing to redo\n";
		}
	}
	virtual void redo_execute() {}
};

class r_c :public r
{
public:
	r_c(int i, shape *ptr) :index(i), shape_ptr(ptr->clone()) { /*std::cout << "r_c constructor\n";*/ }
	void redo_execute();
	~r_c() { std::cout << "~r_c\n"; delete shape_ptr; }
private:
	int index;
	shape *shape_ptr;
	r_c(const r_c &);
	r_c &operator=(const r_c &);
};

class r_d : public r
{
public:
	r_d(int i, shape *ptr) :index(i), shape_ptr(ptr) { std::cout << "r_d constructor\n"; }
	void redo_execute();
	~r_d() { std::cout << "~r_d\n"; delete shape_ptr; }
private:
	int index;
	shape *shape_ptr;
	r_d(const r_d &);
	r_d &operator=(const r_d &);
};

class r_m :public r
{
public:
	r_m(int i, int x, int y) :index(i), dx(x), dy(y) { std::cout << "u_c constructor\n"; }
	void redo_execute();
	~r_m() { std::cout << "~r_m\n"; }
private:
	int index;
	int dx;
	int dy;
	r_m(const r_m &);
	r_m &operator=(const r_m &);
};


class u :public command
{
public:
	u() { std::cout << "u constructor\n"; }
	~u() { std::cout << "~u\n"; }
	void execute()
	{
		if (shape_index)
		{
			undo_ptrs.top()->undo_execute();
			undo_ptrs.pop();
		}
		else
		{
			std::cerr << "nothing to undo\n";
		}
	}
	virtual void undo_execute() {}
};

class u_c :public u
{
public:
	u_c(int i, shape *ptr) :index(i), shape_ptr(ptr) { std::cout << "u_c constructor\n"; }
	void undo_execute();
	~u_c() { std::cout << "~u_c\n"; delete shape_ptr; }
private:
	int index;
	shape *shape_ptr;
	u_c(const u_c &);
	u_c &operator=(const u_c &);
};

class u_d :public u
{
public:
	u_d(int i, shape *ptr) :index(i), shape_ptr(ptr) { std::cout << "u_d constructor\n"; }
	void undo_execute();
	~u_d() { std::cout << "~u_d\n"; delete shape_ptr; }
private:
	int index;
	shape *shape_ptr;
	u_d(const u_d &);
	u_d &operator=(const u_d &);
};

class u_m :public u
{
public:
	u_m(int i, int x, int y) :index(i), dx(x), dy(y) { std::cout << "u_m constructor\n"; }
	void undo_execute();
	~u_m() { std::cout << "~u_m\n"; }
private:
	int index;
	int dx;
	int dy;
	u_m(const u_m &);
	u_m &operator=(const u_m &);
};

void u_c::undo_execute()
{
	std::cout << "u_c\n";
	redo_ptrs.push(new r_c(index, shape_ptr));
	shape_ptrs[index] = 0;
}

void u_d::undo_execute()
{
	std::cout << "u_d\n";
	redo_ptrs.push(new r_d(index, shape_ptr));
	shape_ptrs[index] = shape_ptr;
}

void u_m::undo_execute()
{
	std::cout << "u_m\n";
	redo_ptrs.push(new r_m(index, dx, dy));
	shape_ptrs[index]->move(-dx, -dy);
}

void r_c::redo_execute()
{
	std::cout << "r_c\n";
	undo_ptrs.push(new u_c(index, shape_ptr));
	shape_ptrs[index] = shape_ptr->clone();
}

void r_d::redo_execute()
{
	std::cout << "r_d\n";
	undo_ptrs.push(new u_d(index, shape_ptr));
	delete shape_ptrs[index];
	shape_ptrs[index] = 0;
}

void r_m::redo_execute()
{
	std::cout << "r_m\n";
	undo_ptrs.push(new u_m(index, dx, dy));
	shape_ptrs[index]->move(dx, dy);
}


class c :public command
{
public:
	c() { std::cout << "c constructor\n"; }
	~c()
	{
		for (std::map<char, shape *>::iterator it = shapes.begin(); it != shapes.end(); ++it)
		{
			delete it->second;
		}
		std::cout << "~c\n";
	}
	void execute()
	{
		shapes['t'] = new triangle();
		shapes['c'] = new circle();
		shapes['r'] = new rect();

		char c;
		std::cout << "ob type (t, c, r) = ";
		std::cin >> c;

		if (shapes.find(c) != shapes.end())
		{
			shape_ptrs[shape_index] = shapes[c];
			shapes[c]->create();
			undo_ptrs.push(new u_c(shape_index, shape_ptrs[shape_index]));
			++shape_index;
		}
		else
		{
			std::cerr << "'" << c << "' is not a type\n";
		}
	}
private:
	std::map<char, shape *> shapes;
};


class p :public command
{
public:
	p() { std::cout << "p constructor\n"; }
	~p() { std::cout << "~p\n"; }
	void execute()
	{
		int i;
		std::cout << "ob id = ";
		std::cin >> i;

		if (shape_ptrs[i])
		{
			shape_ptrs[i]->print();
		}
		else
		{
			std::cerr << "no object at index " << i << '\n';
		}
	}
};


class m :public command
{
public:
	m() { std::cout << "m constructor\n"; }
	~m() { std::cout << "~m\n"; }
	void execute()
	{
		int i;
		std::cout << "ob id = ";
		std::cin >> i;

		if (shape_ptrs[i])
		{
			int dx, dy;
			std::cout << "dx = ";
			std::cin >> dx;
			std::cout << "dy = ";
			std::cin >> dy;
			shape_ptrs[i]->move(dx, dy);
			undo_ptrs.push(new u_m(i, dx, dy));
		}
		else
		{
			std::cerr << "no object at index " << i << '\n';
		}
	}
};


class d :public command
{
public:
	d() { std::cout << "d constructor\n"; }
	~d() { std::cout << "~d\n"; }
	void execute()
	{
		int i;
		std::cout << "ob id = ";
		std::cin >> i;
		if (shape_ptrs[i])
		{
			undo_ptrs.push(new u_d(i, shape_ptrs[i]));
			shape_ptrs[i] = 0;
		}
		else
		{
			std::cerr << "no object at index " << i << '\n';
		}
	}
};


#endif
