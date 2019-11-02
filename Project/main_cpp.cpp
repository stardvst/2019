#include <iostream>
#include <vector>

struct Point
{
	Point(int x, int y) {}
};

class Polygon
{
public:
	Polygon() : area_(-1) {}
	void AddPoint(Point pt)
	{
		InvalidateArea();
		points_.push_back(pt);
	}
	const Point GetPoint(int i) const { return points_[i]; }
	int GetNumPoints() const { return points_.size(); }
	double GetArea() const
	{
		if (area_ < 0) // if not yet calculated and cached
			CalcArea(); // calculate now
		return area_;
	}

private:
	void InvalidateArea() const { area_ = -1; }
	void CalcArea() const
	{
		area_ = 0;
		std::vector<Point>::const_iterator i;
		for (i = points_.begin(); i != points_.end(); ++i)
			area_ += 5/* some work */;
	}

	std::vector<Point> points_;
	mutable double area_;
};

const Polygon operator+(const Polygon &lhs, const Polygon &rhs)
{
	Polygon ret = lhs;
	const int last = rhs.GetNumPoints();
	for (int i = 0; i < last; ++i) // concatenate
		ret.AddPoint(rhs.GetPoint(i));
	return ret;
}

void f(Polygon &poly)
{
	poly.AddPoint(Point(0, 0));
}

void g(Polygon &rPoly) { rPoly.AddPoint(Point(1, 1)); }
void h(Polygon *pPoly) { pPoly->AddPoint(Point(2, 2)); }

int main()
{
	Polygon poly;
	f(poly);
	g(poly);
	h(&poly);

	//poly.GetPoint(0) = Point(0, 0); // compile error

	Polygon p1, p2, p3;
	//(p1 + p2) = p3; // compile error

	std::cin.get();
}
