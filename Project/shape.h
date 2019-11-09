#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>


class shape
{
public:
	virtual void create() = 0;
	virtual void print() const = 0;
	virtual void move(int, int) = 0;
	virtual shape *clone() const = 0;
	virtual ~shape() {}
};


class triangle :public shape
{
public:
	triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {}
	shape *clone() const { return new triangle(*this); }
	void create()
	{
		std::cout << "input trianagle:\nx1 = ";
		std::cin >> x1;
		std::cout << "y1 = ";
		std::cin >> y1;
		std::cout << "x2 = ";
		std::cin >> x2;
		std::cout << "y2 = ";
		std::cin >> y2;
		std::cout << "x3 = ";
		std::cin >> x3;
		std::cout << "y3 = ";
		std::cin >> y3;
	}

	void print() const
	{
		std::cout << "triangle: x1=" <<
			x1 << ", y1=" << y1 << ", x2=" << x2 << ", y2=" << y2 << ", x3=" << x3 << ", y3=" << y3 << std::endl;
	}

	void move(int dx, int dy)
	{
		x1 += dx;
		x2 += dx;
		x3 += dx;
		y1 += dy;
		y2 += dy;
		y3 += dy;
	}
private:
	int x1, y1, x2, y2, x3, y3;
	//triangle(const triangle&);
	//triangle& operator=(const triangle&);
};


class circle :public shape
{
public:
	circle() : x(0), y(0), r(0) {}
	shape *clone() const { return new circle(*this); }
	void create()
	{
		std::cout << "input circle:\nx = ";
		std::cin >> x;
		std::cout << "y = ";
		std::cin >> y;
		std::cout << "r = ";
		std::cin >> r;
	}

	void print() const
	{
		std::cout << "circle: x=" << x << ", y=" << y << ", r=" << r << std::endl;
	}

	void move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}

private:
	int x, y, r;
	//circle(const circle&);
	//circle& operator=(const circle&);
};


class rect :public shape
{
public:
	rect() : x1(0), y1(0), x2(0), y2(0) {}
	shape *clone() const { return new rect(*this); }
	void create()
	{
		std::cout << "input rect:\nx1 = ";
		std::cin >> x1;
		std::cout << "y1 = ";
		std::cin >> y1;
		std::cout << "x2 = ";
		std::cin >> x2;
		std::cout << "y2 = ";
		std::cin >> y2;
	}

	void print() const
	{
		std::cout << "rect: x1=" << x1 << ", y1=" << y1 << ", x2=" << x2 << ", y2=" << y2 << std::endl;
	}

	void move(int dx, int dy)
	{
		x1 += dx;
		x2 += dx;
		y1 += dy;
		y2 += dy;
	}
private:
	int x1, y1, x2, y2;
	//rect(const rect&);
	//rect& operator=(const rect&);
};


#endif