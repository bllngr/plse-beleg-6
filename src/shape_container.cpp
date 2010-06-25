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

shape_container::shape_container(shape_container const&):
shapes_()
{

}

shape_container::~shape_container()
{}

void shape_container::add(shape* shapePtr)
{
	shapes_.push_back(shapePtr);
}

void shape_container::remove(shape* shapePtr)
{
	shapes_.remove(shapePtr);
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

void shape_container::items() const
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
