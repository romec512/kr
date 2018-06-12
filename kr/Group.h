#pragma once
#include "Student.h"
class Group
{
public:
	Group();
	~Group();
	void setNumber(int num);
	int getNumber();
	void addStudent(Student *student);
	void setStudent(Student *student);
	Student* getStudent();
	int deleteStudent(char *lastName);
private:
	int number;
	Student *student;
};

