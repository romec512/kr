#pragma once
#include "Group.h"
class Faculty
{
public:
	Faculty(int size);
	~Faculty();
	void addGroup(Group *group);
	Group** getMass();
	void deleteStudent();
private:
	Group **mass;
	int count;//���-�� ��������� �������
	int size; //������ �������
};

