/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe6.7.cpp
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
#include "shape_container.hpp"
#include "box.hpp"
#include "sphere.hpp"

using namespace std;

SUITE(ref_counting_testsuite)
{
	point3d origin(0,0,0);
	color white(255, 255, 255);
	box* box1Ptr = new box(origin, 1, 1, 1, "box1Ptr", white);
	sphere* sphr1Ptr = new sphere(origin, 1, "sphr1Ptr", white);
	shape_container cont1, cont3, cont4;
	shape_container* cont2 = new shape_container;


	TEST(check_add)
	{
		cout << "adding box1Ptr to cont1:" << endl;
		cont1.add(box1Ptr);
		CHECK_EQUAL(box1Ptr->refCounter(), 1);
	}

	TEST(check_clone_shallow)
	{
		cout << endl << "shallow-cloning cont1 to cont2:" << endl;
		*cont2 = cont1.clone_shallow();
		CHECK_EQUAL(box1Ptr->refCounter(), 2);
	
	}

	TEST(check_assignment)
	{
		cout << endl << "adding sphr1Ptr to cont2:" << endl;
		cont2->add(sphr1Ptr);
		

		cout << endl << "adding box1Ptr to cont3:" << endl;
		cont3.add(box1Ptr);
		
		cout << endl << "assigning cont3 to cont2:" << endl;
		cont3 = *cont2;

		CHECK_EQUAL(box1Ptr->refCounter(), 3);
		CHECK_EQUAL(sphr1Ptr->refCounter(), 2);
	}
	
	TEST(check_clone_deep)
	{
		cout << endl << "deep-cloning cont3 to cont1:" << endl;
		// problem here: shapes get ref'd once for cloning and a second time for
		// the assignment!
		cont1 = cont3.clone_deep();
		CHECK_EQUAL(box1Ptr->refCounter(), 2);  // unref'd once
		CHECK_EQUAL(sphr1Ptr->refCounter(), 2); // not in cont1
	}
	
	TEST(check_remove)
	{
		cout << endl << "removing sphr1Ptr from cont2:" << endl;
		cont2->remove(sphr1Ptr);
		CHECK_EQUAL(sphr1Ptr->refCounter(), 1);
	}
	
	TEST(check_dtor)
	{
		cout << endl << "adding sphr1Ptr to cont2:" << endl;
		cont2->add(sphr1Ptr);
		
		cout << endl << "removing cont2:" << endl;
		delete cont2;
		CHECK_EQUAL(box1Ptr->refCounter(), 1);
		CHECK_EQUAL(sphr1Ptr->refCounter(), 1);
	}
}

int main()
{
	return UnitTest::RunAllTests();
}
