/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * sphere.hpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include "point3d.hpp"

class sphere: public shape
{
public:
	// constructors and destructors
	sphere(); // def c'tor
	sphere(point3d const&, double);
	sphere(point3d const&, double, std::string const&, color const&);
	sphere(sphere const&); // copy c'tor
	/* virtual */ ~sphere(); // des'tor

	// getters
	double radius() const;
	point3d center() const;

	// inherited member functions from shape
	/* virtual */ double volume() const;
	/* virtual */ double surface() const;
	/* virtual */ bool is_inside(point3d const&) const;
	/* virtual */ void printOn(std::ostream&) const;
private:
	double radius_;
	point3d center_;
};

// ostream operator (external declaration)
std::ostream& operator<<(std::ostream&, sphere const&);

#endif // SPHERE_HPP
