#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Figure{
public:
	virtual double get_square()=0;
};


class Rectangle: public Figure{
public:
	virtual ~Rectangle();

	static Figure * make(const string s);

	virtual double get_square();

	string to_string()
	{
		ostringstream str;

		str << "R " << width << " " << height;
		return str.str();
	}

private:
	Rectangle()
{
		width = 0;
		height = 0;
}

	double width;
	double height;

};

static int Rectangle::size = 0;


Rectangle::~Rectangle()
{

}

Figure * makeFigure(const string s)
{
	if( s[0] == 'R' )
		return Rectange::make(s);
}

class Circle: public Figure{
	double width,height;
public:
	virtual double get_square();
};

class Square: public Figure{
	double width,height;
public:
	virtual double get_square();
};

int main(int argc, char** argv)
{
	Figure* fig;

	fig = Rectangle::make(str);
	cout << fig->to_string();
}
