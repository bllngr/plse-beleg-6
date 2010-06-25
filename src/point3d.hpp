/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * point23.hpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#ifndef POINT3D_HPP
#define POINT3D_HPP

#include <iostream>

class point3d
{
public:
	point3d();
	point3d(double x, double y, double z);
	point3d(point3d const& point);
	double& operator[](int coordinate);
	double const& operator[](int coordinate) const;
	bool operator==(point3d const& other) const;
	double distanceTo(point3d const& other) const;
	~point3d();

private:
	double coordinates_[3];
};

std::ostream& operator<<(std::ostream& os, point3d const& point);

#endif
