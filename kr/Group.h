#pragma once
#include "Student.h"
class Group
{
public:
	Group();
	~Group();
	void setNumber(int num);
	int getNumber();
	void setStudent(Student *student);
	Student* getStudent();
private:
	int number;
	Student *student;
};

