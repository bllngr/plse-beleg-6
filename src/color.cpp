/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * color.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include "color.hpp"

color::color() :
r_(255),
g_(25),
b_(255)
{}

color::color(unsigned short red, unsigned short green, unsigned short blue) :
r_(red),
g_(green),
b_(blue)
{}

bool color::operator==(color const& other) const
{
	return (r_ == other.r_ && g_ == other.g_ && b_ == other.b_);
}

color::~color()
{}

std::ostream& operator<<(std::ostream& os, color const& color)
{
	os << "color(" << color.r_ << ", " << color.g_ << ", " << color.b_ << ")";
	return os;
}
