#include "Group.h"
#include "Header.h"


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

void Group::setStudent(Student *student)//добавление студента
{
	if (this->student == NULL)
	{
		this->student = student;
	}
	else
	{
		Student *current = this->student;
		if (strcmp(current->getLastName(), student->getLastName()) == 1)
		{
				student->setNext(current);
				this->student = student;
				return;
		}
		while (current->getNext() != NULL && strcmp(current->getLastName(), student->getLastName()) == -1)
		{
			current = current->getNext();
		}
		student->setNext(current->getNext());
		current->setNext(student);
		return;
	}
}

Student* Group::getStudent()//получение списка студентов
{
	return this->student;
}
