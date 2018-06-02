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

void Faculty::deleteStudent()// int groupName - ����� ������, � ������� ����� ������ �������, char *lastName - ������� ���������� ��������
{
	int groupNumber;
	char *lastName = (char*)malloc(256*sizeof(char));
	std::cout << "������� ����� ������, � ������� ������ ������� ��������." << std::endl;
	std::cin >> groupNumber;
	std::cout << "������� ������� ��������, �������� ������ �������." << std::endl;
	std::cin >> lastName;
	Group **mass = this->getMass();
	for (int i = 0; i < this->size; i++)
	{//����� ����������� ������
		if (mass[i]->getNumber() == groupNumber)//������� ���������� ������
		{
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
				}
				student = student->getNext();
			}
		}
	}
}
