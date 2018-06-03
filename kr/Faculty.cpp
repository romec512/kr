#include "Faculty.h"
#include "Header.h"

Faculty::Faculty(int size)
{
	this->mass = (Group**)malloc(size*sizeof(Group*));
	for (int i = 0; i < size; i++)//�������������� NULL ��������
	{
		this->mass[i] = NULL;
	}
	this->count = 0;
	this->size = size;
}


Faculty::~Faculty()
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->mass[i] != NULL)
		{
			delete(this->mass[i]);
		}
	}
}
//NOTE: void Faculty::addGroup(Group *group)
void Faculty::addGroup(Group *group)//���������� ������
{
	if (this->count == this->size)
	{
		std::cout << "��������� ��������.\n" << std::endl;
		return;
	}
	if (mass[0] == NULL)
	{
		mass[0] = group;
		this->count++;
		return;
	}
	int i = 0;
	while(mass[i]->getNumber() < group->getNumber() && i < size)
	{
		i++;
		if (mass[i] == NULL)
		{
			break;
		}
	}
		for (int j = this->count; j >= i; j--)
		{
			mass[j+1] = mass[j];
		}
		mass[i] = group;
		this->count++;
}

Group** Faculty::getMass()//��������� ������� �����
{
	return this->mass;
}
//NOTE: void Faculty::deleteStudent(int groupNumber, char *lastName)
void Faculty::deleteStudent()
{
	int groupNumber;
	char *lastName = (char*)malloc(256*sizeof(char));
	std::cout << "������� ����� ������, � ������� ������ ������� ��������." << std::endl;
	while (!(std::cin >> groupNumber))
	{
		std::cout << "������ �����." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "������� ����� ������, � ������� ������ ������� ��������." << std::endl;
	}
	Group **mass = this->getMass();
	for (int i = 0; i < this->size; i++)
	{//����� ����������� ������
		if (mass[i]->getNumber() == groupNumber)//������� ���������� ������
		{
			std::cout << "������� ������� ��������, �������� ������ �������." << std::endl;
			std::cin >> lastName;
			Student *student = mass[i]->getStudent();
			if (!strcmp(student->getLastName(), lastName))//�������� ������� �������� � ������
			{
				Student *next = student->getNext();
				mass[i]->setStudent(next);//������� ������� - �������.
				delete(student);
				return;
			}
			while (student->getNext() != NULL) //����������� �������� ��� ��������� ���������
			{
				if (!strcmp(student->getNext()->getLastName(), lastName))
				{
					Student *deleted = student->getNext();
					student->setNext(deleted->getNext());
					delete(deleted);
					return;
				}
				student = student->getNext();
			}
		}
	}
	std::cout << "������� �� ������." << std::endl;
}

//NOTE: void Faculty::addStudent(int groupNumber, char *lastName, int year)
void Faculty::addStudent(int groupNumber, char *lastName, int year)//���������� ��������
{
	for (int i = 0; i < this->size; i++)
	{
		if (mass[i]->getNumber() == groupNumber)
		{
			Student *newStudent = new Student(lastName, year);
			mass[i]->addStudent(newStudent);
			return;
		}
	}
}
//ToDo: ������� ������ ����� ���������� ����-����(������, ���� ��������) � ������ Faculty.
//Doing: � ������� select == 1 �������� ������ �� �����

void Faculty::addContent()
{
	int select; 
	std::cout << "1)�������� �� �����.\n2)������ � ����������." << std::endl;
	while (!(std::cin >> select))
	{
		std::cout << "������ �����." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "1)�������� �� �����.\n2)������ � ����������." << std::endl;
	}
	if (select == 1)
	{

	}
	else if (select == 2)
	{
		std::cout << "1)�������� ������.\n2)�������� ��������." << std::endl;
		while (!(std::cin >> select))
		{
			std::cout << "������ �����." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "1)�������� ������.\n2)�������� ��������." << std::endl;
		}
		if (select == 1)
		{
			int number;
			std::cout << "������� ����� ������." << std::endl;
			while (!(std::cin >> number))
			{
				std::cout << "������ �����." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������� ����� ������." << std::endl;
			}
			Group *newGroup = new Group();
			newGroup->setNumber(number);
			newGroup->setStudent(NULL);
			this->addGroup(newGroup);
		}
		else if (select == 2)
		{
			int number;
			std::cout << "������� ����� ������, � ������� ������ �������� ��������." << std::endl;
			while (!(std::cin >> number))
			{
				std::cout << "������ �����." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������� ����� ������, � ������� ������ �������� ��������." << std::endl;
			}
			for (int i = 0; i < this->size; i++)
			{
				if (mass[i] == NULL)
				{
					continue;
				}
				if (this->mass[i]->getNumber() == number)
				{
					int year;
					char *lastName = (char*)malloc(256*sizeof(char));
					std::cout << "������� �������." << std::endl;
					std::cin >> lastName;
					std::cout << "������� ��� ��������.\n" << std::endl;
					while (!(std::cin >> year))
					{
						std::cout << "������ �����." << std::endl;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "������� ��� ��������." << std::endl;
					}
					Student *newStudent = new Student(lastName, year);
					mass[i]->addStudent(newStudent);
					return;
				}
			}
			std::cout << "������ �� �������." << std::endl;
		}
	}
}
//NOTE:void Faculty::deleteGroup()  �������� ������, ���� ������ ����� �������������� �� �������.
void Faculty::deleteGroup()
{
	int number;
	std::cout << "������� ����� ������, ������� ������ �������." << std::endl;
	while (!(std::cin >> number))
	{
		std::cout << "������ �����." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "������� ����� ������." << std::endl;
	}
	for (int i = 0; i < this->size; i++)
	{
		if (this->mass[i]->getNumber() == number)
		{
			delete(this->mass[i]);
			this->count--;
			for (int j = i; j < this->count; j++)
			{
				this->mass[j] = this->mass[j + 1];
			}
			this->mass[this->count] = NULL;
			return;
		}
	}
	std::cout << "������ �� �������." << std::endl;
}
//ToDo: ��� � ��� ���������� ������� ����� ����� �������� � ���� ������
void Faculty::deleteContent()
{
	int select;
	std::cout << "1)������� ������.\n2)������� ��������." << std::endl;
	while (!(std::cin >> select))
	{
		std::cout << "������ �����." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "1)������� ������.\n2)������� ��������." << std::endl;
	}
	if (select == 1)
	{
		this->deleteGroup();
	}
	else if (select == 2)
	{
		this->deleteStudent();
	}
}
//ToDo: ���������� ��������� ���������� �� ����� � �� �������