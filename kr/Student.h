#pragma once
class Student
{
public:
	Student(char *lastName, int year);
	Student();
	~Student();
	char* getLastName();
	void setLastName(char *lastName);
	int getYear();
	void setYear(int year);
	void setNext(Student *student);
	Student* getNext();
private:
	char *lastName;
	int year;
	Student *next;
};

