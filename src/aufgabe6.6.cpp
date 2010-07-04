/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe6.6.cpp
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

TEST(check_reference_counting)
{
	point3d origin(0,0,0);
	box* box1Ptr = new box(origin, 1, 1, 1);
	CHECK_EQUAL(box1Ptr->refCounter(), 0);
	box1Ptr->ref();
	CHECK_EQUAL(box1Ptr->refCounter(), 1);
	box1Ptr->unref();
	CHECK_EQUAL(box1Ptr->refCounter(), 0); // why is this working?
	// box1Ptr->unref();
}

int main()
{
	return UnitTest::RunAllTests();
}
