#pragma once
#include "Train.h"

class Interface
{
	Train* data;
	int size;
public:
	Interface();
	~Interface();
	void add();
	void del();
	void sort();
	void red();
	void sortup();
	void search();
	void searchArr();
	void print();
};