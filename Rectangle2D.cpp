#pragma once

class Rectangle2D
{
private:
	double x, y;
	double width, height;
public:
	Rectangle2D();
	Rectangle2D(double p_x, double p_y, double p_width, double p_height);
	~Rectangle2D();
	double getX() const;
	double getY() const;
	void setX(double p_x);
	void setY(double p_y);
	double getWidth() const;
	double getHeight() const;
	void setWidth(double p_width);
	void setHeight(double p_height);
	double getArea() const;
	double getPerimeter() const;
	bool contains(double p_x, double p_y) const;
	bool contains(Rectangle2D& r) const;
	bool overlaps(Rectangle2D &r) const;
};
#include "Rectangle2D.h"
#include<cmath>
#include<iostream>

Rectangle2D::Rectangle2D()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rectangle2D::Rectangle2D(double p_x, double p_y, double p_width, double p_height)
{
	x = p_x;
	y = p_y;
	width = p_width;
	height = p_height;
}

Rectangle2D::~Rectangle2D()
{
}

double Rectangle2D::getX() const
{
	return this->x;
}

double Rectangle2D::getY() const
{
	return this->y;
}

void Rectangle2D::setX(double p_x)
{
	this->x = p_x;
}

void Rectangle2D::setY(double p_y)
{
	this->y = p_y;
}

double Rectangle2D::getWidth() const
{
	return width;
}

double Rectangle2D::getHeight() const
{
	return height;
}

void Rectangle2D::setWidth(double p_width)
{
	this->width = p_width;
}

void Rectangle2D::setHeight(double p_height)
{
	this->height = p_height;
}

double Rectangle2D::getArea() const
{
	return this->width * this->height;
}

double Rectangle2D::getPerimeter() const
{
	return 2 * (this->width + this->height);
}

bool Rectangle2D::contains(double p_x, double p_y) const
{
	return ((this->width / 2 >= abs(this->x - p_x)) && (this->height / 2 >= abs(this->y - p_y)));
}

bool Rectangle2D::contains(Rectangle2D& r) const
{
	if (Rectangle2D::contains(r.x, r.y))
	{
		//가운데 기준 왼쪽 오른쪽 모두 검사하는 코드
		return (((abs(this->x - r.x) + (r.width / 2)) <= this->width / 2) && ((abs(this->y - r.y) + (r.height / 2)) <= this->height / 2));
	}
	return false;
}

bool Rectangle2D::overlaps(Rectangle2D& r) const
{
	return ((abs(this->x - r.x) <= (r.width / 2) + (this->width / 2)) && (abs(this->y - r.y) <= (r.height / 2) + (this->height / 2)));
}


int main()
{
	using namespace std;
	Rectangle2D r1(2, 2, 5.5, 4.9); 
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D	r3(3, 5, 2.3, 5.4);

	cout << std::boolalpha << r1.contains(3, 3) << "\n" 
		<< std::boolalpha << r1.contains(r2) << "\n"
		<< std::boolalpha << r1.overlaps(r3);


	return 0;
}
