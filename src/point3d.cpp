/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * point3d.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 *
 */

#include "point3d.hpp"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// default constructor sets point to (0,0,0)
point3d::point3d() :
coordinates_()
{
	/*
	coordinates_[0] = 0;
	coordinates_[1] = 0;
	coordinates_[2] = 0;
	*/
}

// constructor sets points
point3d::point3d(double x, double y, double z)
{
	coordinates_[0] = x;
	coordinates_[1] = y;
	coordinates_[2] = z;
}

// copy c'tor
point3d::point3d(point3d const& point)
{
	coordinates_[0] = point[0];
	coordinates_[1] = point[1];
	coordinates_[2] = point[2];
	
}

double& point3d::operator[](int index)
{
	assert(index <= 2);
	return coordinates_[index];
}

double const& point3d::operator[](int index) const
{
	assert(index <= 2);
	return coordinates_[index];
}

bool point3d::operator==(point3d const& other) const
{
	return (coordinates_[0] == other[0] && coordinates_[1] == other[1] &&
		coordinates_[2] == other[2]);
}

double point3d::distanceTo(point3d const& other) const
{
	// calculate distance to another point3d
	// d = sqrt((x1 - x2)^2 * (y1 - y2)^2 * (z1 - z2)^2)
	double squareX = (coordinates_[0] - other[0]) * (coordinates_[0] - other[0]);
	double squareY = (coordinates_[1] - other[1]) * (coordinates_[1] - other[1]);
	double squareZ = (coordinates_[2] - other[2]) * (coordinates_[1] - other[2]);
	return sqrt(squareX + squareY + squareZ);
}

point3d::~point3d()
{}

ostream& operator<<(std::ostream& os, point3d const& point)
{
	os << "point3d(" << point[0] << ", " << point[1] << ", " << point[2] << ")";
	return os;
}
