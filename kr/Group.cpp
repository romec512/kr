#include "Group.h"
#include "Header.h"


Group::Group()
{
	this->setStudent(NULL);
}


Group::~Group()
{
	while (this->getStudent() != nullptr)
	{
		Student *deleted = this->getStudent();
		this->setStudent(this->student->getNext());
		delete(deleted);
	}
}
//установка номера
void Group::setNumber(int num)
{
	this->number = num;
}
//получение номера
int Group::getNumber()
{
	return this->number;
}
//ƒобавление студента
void Group::addStudent(Student *student)
{
	if (this->getStudent() == NULL)
	{
		student->setNext(NULL);
		this->setStudent(student);
		return;
	}
	else
	{
		Student *current = this->getStudent();
		if (strcmp(this->getStudent()->getLastName(), student->getLastName()) == 1)
		{
			student->setNext(current);
			this->setStudent(student);
			return;
		}
		else if (current->getNext() == NULL)
		{
			current->setNext(student);
			return;
		}
		while (current->getNext()->getNext() != NULL && strcmp(current->getNext()->getLastName(), student->getLastName()) == -1)
		{
			current = current->getNext();
		}
		if (strcmp(current->getNext()->getLastName(), student->getLastName()) == 1)
		{
			student->setNext(current->getNext());
			current->setNext(student);
			return;
		}
		else
		{
			current->getNext()->setNext(student);
			return;
		}
	}
}

void Group::setStudent(Student *student)
{
	this->student = student;
}
//получение списка студентов
Student* Group::getStudent()
{
	return this->student;
}

//удалить студента
int Group::deleteStudent(char *lastName)
{
	if (lastName == NULL)
	{
		std::cout << "Ќеобходимо указать фамилию студента." << std::endl;
	}
	else
	{
		Student *current = this->student;
		if (current == NULL)
		{
			return 0;
		}
		if (!strcmp(current->getLastName(), lastName))
		{
			this->student = current->getNext();
			delete(current);
			return 1;
		}
		while (current->getNext() != NULL)
		{
			if (!strcmp(current->getNext()->getLastName(), lastName))
			{
				Student *deleted = current->getNext();
				current->setNext(deleted->getNext());
				deleted->setNext(NULL);
				delete(deleted);
				return 1;
			}
			current = current->getNext();
		}
	}
}
