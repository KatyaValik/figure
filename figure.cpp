#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Figure
{
public:
	virtual double get_square()=0;
	virtual ~Figure();
};

class Rectangle: public Figure
{
private:
	double width;
	double height;
public:

	Rectangle()
	{
		width = 0;
		height = 0;
	}


	virtual double get_square()
	{
		return width * height;
	}

	virtual ~Rectangle()
	{
		// что должен делать? все поля же интовые
	}

static	Figure * make(const string s) {
		Rectangle r;
		istringstream str;
		r.width>>str;
		r.height>>str;
		return r;
	}

	string to_string()
	{
		ostringstream str;

		str << "R " << width << " " << height;
		return str.str();
	}

};



class Circle: public Figure
{
private:
	double radius;

public:

	Circle() {
		radius=0;
	}
	virtual double get_square(){
		return radius*radius*3.14;//как сделать нормальное пи? в math.h нет похоже
	}
	virtual ~Circle() {
		//что делать?
	}

static	Figure* make(const string s){
		Circle c;
		istringstream str;
		c.radius>>str;
		return c;
	}

	string to_string(){
		ostringstream str;
		str<< "C "<<radius;
		return str.str();
	}
};

class Square: public Figure
{
private:
	double size;
public:
	Square(){
		size=0;
	}
	virtual double get_square(){
		return size*size;
	}
	virtual ~Square(){
		//чтооооо?
	}

static	Figure* make(const string s){
		Square sq;
		istringstream str;
		sq.size>>str;
		return sq;
	}

	string to_string(){
		ostringstream str;
		str<<"S "<<size;
		return str.str();
	}
};

Figure* makeFigure(const string s)
{
	if (s[0] == 'R')
	{
		return Rectangle::make(s);
	}
	if (s[0] == 'S')
	{
		return Square::make(s);
	}

	if (s[0] == 'C')
	{
		return Circle::make(s);
	}

}

int main(int argc, char** argv)
{
/*	Figure* fig;
	string str;
	cin>>str;
	fig = Rectangle::make(str);
	cout << fig->to_string();*/
}
