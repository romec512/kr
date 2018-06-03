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
}

void Group::setNumber(int num)//установка номера
{
	this->number = num;
}

int Group::getNumber()//получение номера
{
	return this->number;
}
//NOTE: addStudent(Student *student)
void Group::addStudent(Student *student)//добавление студента
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

void Group::setStudent(Student *student)
{
	this->student = student;
}
Student* Group::getStudent()//получение списка студентов
{
	return this->student;
}

//NOTE: deleteStudent(char *lastName)
void Group::deleteStudent(char *lastName)
{
	if (lastName == NULL)
	{
		std::cout << "Необходимо указать фамилию студента." << std::endl;
	}
	else
	{
		Student *current = this->student;
		if (current == NULL)
		{
			return;
		}
		if (!strcmp(current->getLastName(), lastName))
		{
			this->student = current->getNext();
			delete(current);
		}
		while (current->getNext() != NULL)
		{
			if (!strcmp(current->getNext()->getLastName(), lastName))
			{
				Student *deleted = current->getNext();
				current->setNext(deleted->getNext());
				deleted->setNext(NULL);
				delete(deleted);
			}
			current = current->getNext();
		}
	}
}
