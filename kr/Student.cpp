#include "Student.h"
#include "Header.h"


Student::Student()
{

}
Student::Student(char *lastName, int year)
{
	if (lastName != nullptr)
	{
		this->lastName = lastName;
	}
	else
	{
		return;
	}
	this->year = year;
	this->next = NULL;
}


Student::~Student()
{
}

char* Student::getLastName()
{
	return this->lastName;
}

void Student::setLastName(char* lastName)
{
	if (lastName != nullptr)
	{
		this->lastName = lastName;
	}
}

int Student::getYear()
{
	return this->year;
}

void Student::setYear(int year)
{
	this->year = year;
}
void Student::setNext(Student *student)
{
		this->next = student;
}

Student* Student::getNext()
{
	return this->next;
}
