/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe6.2.cpp
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
#include <cmath>
#include "box.hpp"
#include "sphere.hpp"
#include "shape_container.hpp"

using namespace std;

SUITE(container_testsuite)
{
	TEST(check_volume)
	{
		point3d origin(0,0,0);
		box* box1Ptr = new box(origin, 1, 1, 1);
		sphere* sphere1Ptr = new sphere(origin, 2);
		shape_container cont;
		cont.add(box1Ptr);
		cont.add(sphere1Ptr);
		CHECK_EQUAL((1 + 32/3. * M_PI), cont.volume());
	}
}

int main()
{
	box* box1Ptr = new box(point3d(0, 0, 0), 1, 1, 1);
	sphere* sphere1Ptr = new sphere(point3d(0, 0, 0), 2);

	shape_container cont;
	cont.add(box1Ptr);
	cont.add(sphere1Ptr);

	cont.print();	

	return UnitTest::RunAllTests();
}
