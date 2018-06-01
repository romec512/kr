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

void Group::setNumber(int num)//��������� ������
{
	this->number = num;
}

int Group::getNumber()//��������� ������
{
	return this->number;
}

void Group::setStudent(Student *student)//���������� ��������
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

Student* Group::getStudent()//��������� ������ ���������
{
	return this->student;
}
