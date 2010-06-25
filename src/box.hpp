/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * box.hpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include "point3d.hpp"

class box: public shape
{
public:
	// constructors and destructors
	box(); // def c'tor
	box(point3d const&, double, double, double);
	box(point3d const&, double, double, double, std::string const&,
		color const&);
	box(box const&); // copy c'tor
	/* virtual */ ~box(); // des'tor

	// getters
	double length() const;
	double width() const;
	double height() const;
	point3d corner() const;

	// inherited member functions from shape
	/* virtual */ double volume() const;
	/* virtual */ double surface() const;
	/* virtual */ bool is_inside(point3d const&) const;
	/* virtual */ void printOn(std::ostream&) const;

private:
	point3d corner_;
	double length_;
	double width_;
	double height_;
};

// ostream operator (external declaration)
std::ostream& operator<<(std::ostream&, box const&);

#endif // BOX_HPP
