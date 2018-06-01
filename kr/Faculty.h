#pragma once
#include "Group.h"
class Faculty
{
public:
	Faculty(int size);
	~Faculty();
	void addGroup(Group *group);
	Group** getMass();
private:
	Group **mass;
	int count;//кол-во элементов массива
	int size; //размер массива
};

