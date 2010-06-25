/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * shape.hpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>
#include "point3d.hpp"
#include "color.hpp"

class shape {
public:
	// constructors and destructors
	shape(); // def c'tor
	shape(std::string const&, color const&);
	shape(shape const&); // copy c'tor
	virtual ~shape(); // des'tor

	// getters
	std::string const& name() const;
	color const& Color() const;  // cannot be of the same name as the struct
	
	// misc member functions
	virtual double volume() const = 0;
	virtual double surface() const = 0;
	virtual bool is_inside(point3d const& point) const = 0;
	/*virtual*/ void printOn(std::ostream& os) const;

private:
	std::string name_;
	color color_;
};

// ostream operator (external declaration)
std::ostream& operator<<(std::ostream&, shape const&);

#endif // SHAPE_HPP