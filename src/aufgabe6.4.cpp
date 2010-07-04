/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe6.4.cpp
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <UnitTest++.h>
#include "box.hpp"
#include "shape_container.hpp"

using namespace std;

TEST(check_volume)
{
	point3d origin(0,0,0);
	box* box1Ptr = new box(origin, 1, 1, 1);
	box* box2Ptr = box1Ptr->clone();
	shape_container cont;
	cont.add(box1Ptr);
	cont.add(box2Ptr);
	CHECK_EQUAL(cont.volume(), 2);
}

int main()
{
	return UnitTest::RunAllTests();
}
