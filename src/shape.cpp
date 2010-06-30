/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * shape.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <iostream>
#include <typeinfo>
#include "shape.hpp"

using namespace std;

// constructors and destructors
shape::shape() :
name_("shape"),
color_(color(0,0,0)),
refCounter_(0)
{
	// cout << "shape c'tor" << endl;
}

shape::shape(string const& name, color const& clr) :
name_(name),
color_(clr),
refCounter_(0)
{
	// cout << "shape c'tor" << endl;
}

shape::shape(shape const& other) :
name_(other.name()),
color_(other.Color()),
refCounter_(0)
{
	// cout << "shape c'tor" << endl;
}

/* virtual */ shape::~shape()
{
	// cout << "shape d'tor" << endl;
}

// getters
string const& shape::name () const
{
	return name_;
}

color const& shape::Color () const
{
	return color_;
}

// misc member functions
/* virtual */ void shape::printOn(std::ostream& os) const
{
	os << typeid(*this).name() << "(\"" << name_ << "\", " << color_ << ", ";
}

void shape::ref()
{
	++refCounter_;
}

void shape::unref()
{
	--refCounter_;
}

// ostream operator (external definition)
std::ostream& operator<<(std::ostream& os, shape const& shp)
{
	shp.printOn(os);
	return os;
}
