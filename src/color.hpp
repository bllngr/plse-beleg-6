/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * color.hpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>

struct color {
	color();
	color(unsigned short red, unsigned short green, unsigned short blue);
	~color();
	unsigned short r_, g_, b_;
	bool operator==(color const& other) const;
};

std::ostream& operator<<(std::ostream& os, color const& color);

#endif
