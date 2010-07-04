/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe6.5.cpp
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
#include <UnitTest++.h>
#include "box.hpp"
#include "sphere.hpp"
#include "shape_container.hpp"

TEST(check_clone_shallow)
{
	point3d origin(0,0,0);
	color red(255,0,0);
	box* box1Ptr = new box(origin, 1, 1, 1, "testbox", red);
	shape_container cont1;
	cont1.add(box1Ptr);
	CHECK_EQUAL(cont1.size(), 1);

	shape_container cont2;
	CHECK_EQUAL(cont2.size(), 0);

	cont2 = cont1.clone_shallow();
	CHECK_EQUAL(cont2.size(), 1);
	CHECK(cont2.find("testbox") != NULL);
	CHECK_EQUAL(cont1.find("testbox"), cont2.find("testbox"));

	// box1Ptr->name("changed_name");

	// cont1.print();
	// std::cout << std::endl;
	// cont2.print();
	// std::cout << std::endl;
}
TEST(check_clone_deep)
{
	point3d origin(0,0,0);
	color red(255,0,0);
	box* box1Ptr = new box(origin, 1, 1, 1, "testbox", red);
	shape_container cont1;
	cont1.add(box1Ptr);
	CHECK_EQUAL(cont1.size(), 1);

	shape_container cont2;
	CHECK_EQUAL(cont2.size(), 0);

	cont2 = cont1.clone_deep();
	CHECK_EQUAL(cont2.size(), 1);
	CHECK(cont2.find("testbox") != NULL);
	// CHECK(cont1.find("testbox") != cont2.find("testbox"));
	// box1Ptr->name("changed_name");

	// cont1.print();
	// std::cout << std::endl;
	// cont2.print();
	// std::cout << std::endl;
}

int main()
{
	return UnitTest::RunAllTests();
}
