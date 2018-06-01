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

void Group::setNumber(int num)//установка номера
{
	this->number = num;
}

int Group::getNumber()//получение номера
{
	return this->number;
}

void Group::setStudent(Student *student)//установка студента
{
	this->student = student;
}

Student* Group::getStudent()//получение списка студентов
{
	return this->student;
}