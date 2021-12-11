#include<iostream>
#include<vector>
#include<cmath>

#define PI 3.14

using namespace std;

class Shape
{
public:
	virtual double getArea()const = 0;
	virtual double getVolume()const = 0;
	virtual string getShapeType()const = 0;
	virtual void print()const = 0;
};

//------------Two dimensional shapes------------
class TwoDimensionalShape :public Shape
{
public:
	virtual double getArea()const = 0;
	double getVolume()const { return 0; }//This function shouldn't be called
	virtual string getShapeType()const = 0;
	void print()const
	{
		cout << getShapeType() << "\n"
			<< "area: " << getArea() << "\n\n";
	}
};

class Circle:public TwoDimensionalShape
{
public:
	Circle(double _radius)
	{
		radius = _radius;
	}
	double getArea()const
	{
		return PI * radius * radius;
	}
	string getShapeType()const
	{
		return "Circle";
	}
private:
	double radius;
};

class Square :public TwoDimensionalShape
{
public:
	Square(double _a)
	{
		a = _a;
	}
	double getArea()const
	{
		return (a * a);
	}
	string getShapeType()const
	{
		return "Square";
	}
private:
	double a;
};

class Triangle :public TwoDimensionalShape
{
public:
	Triangle(double _height, double _base)
	{
		height = _height;
		base = _base;
	}
	double getArea()const
	{
		return height * base * 0.5;
	}
	string getShapeType()const
	{
		return "Triangle";
	}
private:
	double height;
	double base;
};

//-----------Three dimensional shapes-----------
class ThreeDimensionalShape :public Shape
{
public:
	virtual double getArea()const = 0;
	virtual double getVolume()const = 0;
	virtual string getShapeType()const = 0;
	void print()const
	{
		cout << getShapeType() << "\n"
			<< "area: " << getArea() << "\n"
			<< "volume: " << getVolume() << "\n\n";
	}
};

class Sphere :public ThreeDimensionalShape
{
public:
	Sphere(double _radius)
	{
		radius = _radius;
	}
	double getArea()const
	{
		return 4 * PI * radius * radius;
	}
	double getVolume()const
	{
		return (4 * PI * pow(radius, 3) / 3);
	}
	string getShapeType()const
	{
		return "Sphere";
	}
private:
	double radius;
};

class Cube :public ThreeDimensionalShape
{
public:
	Cube(double _a)
	{
		a = _a;
	}
	double getArea()const
	{
		return 6 * a * a;
	}
	double getVolume()const
	{
		return a * a * a;
	}
	string getShapeType()const
	{
		return "Cube";
	}
private:
	double a;
};

class Tetrahedron :public ThreeDimensionalShape
{
public:
	Tetrahedron(double _a)
	{
		a = _a;
	}
	double getArea()const
	{
		return (sqrt(3.0) * a * a);
	}
	double getVolume()const
	{
		return (pow(a, 3) / (6 * sqrt(2)));
	}
	string getShapeType()const
	{
		return "Tetrahedron";
	}
private:
	double a;
};

int main()
{
	vector <Shape*> s ;
	s.push_back(new Circle(2.0));
	s.push_back(new Square(2.0));
	s.push_back(new Triangle(2.0, 2.0));
	s.push_back(new Sphere(2.0));
	s.push_back(new Cube(2.0));
	s.push_back(new Tetrahedron(2.0));

	for (auto const& value : s)
		value->print();
}