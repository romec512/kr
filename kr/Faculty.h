#pragma once
#include "Group.h"
class Faculty
{
public:
	Faculty();
	~Faculty();
	void addGroup(Group *group);
	void addStudent(int groupNumber, char *lastName, int year);
	Group** getMass();
	void deleteStudent();
	void addContent();
	void deleteGroup();
	void deleteContent();
	void LoadFromFile();
	void show();
	char* getName();
	void search();
	void saveInFile();
	void setName(char *name);
private:
	Group **mass;
	int count;//кол-во элементов массива
	int size; //размер массива
	char *name;
};

