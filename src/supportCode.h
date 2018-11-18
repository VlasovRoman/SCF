//Here you can place any crap code you want that is not really in any container
//or some util function not trighly tied to any general topic

#pragma once
#include "startup.h"

template<class T> wstring towstring(const T& source)
{
	wostringstream oss;
	oss << source;
	return oss.str();
};