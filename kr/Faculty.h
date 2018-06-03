#pragma once
#include "Group.h"
class Faculty
{
public:
	Faculty(int size);
	~Faculty();
	void addGroup(Group *group);
	void addStudent(int groupNumber, char *lastName, int year);
	Group** getMass();
	void deleteStudent();
	void addContent();
	void deleteGroup();
	void deleteContent();
private:
	Group **mass;
	int count;//кол-во элементов массива
	int size; //размер массива
};

