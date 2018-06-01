#include "Group.h"



Group::Group()
{
	this->student = nullptr;
}


Group::~Group()
{
	while (this->student != nullptr)
	{
		Student *deleted = this->student;
		this->student = this->student->getNext();
		delete(deleted);
	}
	delete(this);
}

void Group::setNumber(int num)//��������� ������
{
	this->number = num;
}

int Group::getNumber()//��������� ������
{
	return this->number;
}

void Group::setStudent(Student *student)//��������� ��������
{
	this->student = student;
}

Student* Group::getStudent()//��������� ������ ���������
{
	return this->student;
}