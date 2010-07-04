/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * shape_container.cpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>
#include "shape_container.hpp"

using namespace std;

double accumulateVolume(double a, shape* shapePtr)
{
	return a + shapePtr->volume();
}

shape_container::shape_container():
shapes_()
{}

shape_container::shape_container(shape_container const& other):
shapes_(other.shapes_)
{
	for_each(shapes_.begin(), shapes_.end(), mem_fun(&shape::ref));
}

shape_container::~shape_container()
{
	for_each(shapes_.begin(), shapes_.end(), mem_fun(&shape::unref));
}

shape_container& shape_container::operator=(shape_container const& other)
{
	for_each(shapes_.begin(), shapes_.end(), mem_fun(&shape::unref));
	shapes_ = other.shapes_;
	for_each(shapes_.begin(), shapes_.end(), mem_fun(&shape::ref));
	return *this;
}

shape_container shape_container::clone_deep() const
{
	shape_container cloned;

	for (list<shape*>::const_iterator it = shapes_.begin(); it != shapes_.end();
		++it)
	{
		cloned.add((*it)->clone());
	}
	cout << "end cloning" << endl;
	return cloned;
}

shape_container shape_container::clone_shallow() const
{
	return shape_container(*this);
}

void shape_container::add(shape* shapePtr)
{
	shapes_.push_back(shapePtr);
	shapePtr->ref();
}

void shape_container::remove(shape* shapePtr)
{
	if (shapePtr != 0 && shapePtr != NULL)
	{
		shapes_.remove(shapePtr);
		shapePtr->unref();
	}
}

shape* shape_container::find(string const& name) const
{
	list<shape*>::const_iterator it = shapes_.begin();
	for (; it != shapes_.end(); ++it)
	{
		if ((**it).name() == name)
		{
			return (*it);
		}
	}
	return NULL;
}

int shape_container::size() const
{
	return shapes_.size();
}

void shape_container::print() const
{
	// for (list<shape*>::const_iterator it = shapes_.begin(); it != shapes_.end(); ++it)
	// {
	//	cout << (*it)->name() << endl;
	// }
	for_each(shapes_.begin(), shapes_.end(), bind2nd(mem_fun(&shape::printOn), cout));
}

double shape_container::volume() const
{
	// double totalVolume = 0;
	// for (list<shape*>::const_iterator it = shapes_.begin(); it != shapes_.end(); ++it)
	// {
	//	totalVolume += (*it)->volume();
	// }
	
	double totalVolume = accumulate(shapes_.begin(), shapes_.end(), 0., accumulateVolume);

	return totalVolume;
}
