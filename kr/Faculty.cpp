#include "Faculty.h"
#include "Header.h"

Faculty::Faculty()
{
	this->mass = (Group**)malloc(10*sizeof(Group*));
	for (int i = 0; i < 10; i++)//�������������� NULL ��������
	{
		this->mass[i] = NULL;
	}
	this->count = 0;
	this->size = 10;
	//this->name = (char*)malloc(256 * sizeof(char));
	//std::cout << "������� �������� ����������:" << std::endl;
	//std::cin >> this->name;
	this->name = NULL;
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
	if (mass[i]->getNumber() == group->getNumber())
	{
		std::cout << "������ ��� ����������." << std::endl;
		delete(group);
		return;
	}
	while(mass[i]->getNumber() < group->getNumber() && i < size)
	{
		i++;
		if (mass[i] == NULL)
		{
			break;
		}else if (mass[i]->getNumber() == group->getNumber())
		{
			std::cout << "������ ��� ����������." << std::endl;
			delete(group);
			return;
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
		if (mass[i] == NULL)
		{
			std::cout << "������ ��� ������� �� �������." << std::endl;
			return;
		}
		if (mass[i]->getNumber() == groupNumber)//������� ���������� ������
		{
			std::cout << "������� ������� ��������, �������� ������ �������." << std::endl;
			std::cin >> lastName;
			Student *student = mass[i]->getStudent();
			if (student == NULL)
			{
				std::cout << "� ������ ��� ���������." << std::endl;
				return;
			}
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

void Faculty::addContent()
{
	if (this->name == NULL)
	{
		std::cout << "������� �������� ����������." << std::endl;
		this->name = (char*)malloc(256 * sizeof(char));
		std::cin >> this->name;
	}
	int select; 
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
					std::cout << "������� ��� ��������." << std::endl;
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
		if (this->mass[i] == NULL)
		{
			std::cout << "������ �� �������." << std::endl;
			return;
		}
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

// �������� ������ ��� ��������, ����� �������������� ������� �� ����������.
void Faculty::deleteContent()
{
	if (this->mass[0] == NULL)
	{
		std::cout << "��������� ����." << std::endl;
		return;
	}
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

//�������� ������ �� �����.
void Faculty::LoadFromFile()
{
	FILE *input = fopen("file.txt", "r");
	if (input == NULL)
	{
		std::cout << "������ �������� �����" << std::endl;
		return;
	}
	char *facultyName = (char*)malloc(256*sizeof(char));
	int groupNumber;
	int statusCode = 1;
	if (!fscanf(input, "���������: %[a-zA-Z�-��-�]", facultyName))
	{
		std::cout << "������ ������." << std::endl;
		fclose(input);
		return;
	}
	this->name = facultyName;
	int position = 0;
	int i = 0;
	while (i <= this->size)
	{
		i++;
		if (position != 0)
		{
			fseek(input, position, SEEK_SET);
		}
		statusCode = fscanf(input, "\t������: %d", &groupNumber);
		if (statusCode == 0)
		{
			std::cout << "������ ������ �����." << std::endl;
			fclose(input);
			return;
		}
		else if (statusCode == -1)
		{
			break;
		}
		Group *group = new Group();
		group->setNumber(groupNumber);
		while (true)
		{
			char *studentLastName = (char*)malloc(256 * sizeof(char));
			int studentYear;
			position = ftell(input);
			statusCode = fscanf(input, "\t\t�������: %[a-zA-Z�-��-�], ��� ��������: %d", studentLastName, &studentYear);
			if (statusCode == -1)
			{
				this->addGroup(group);
				fclose(input);
				return;
			}
			else if (statusCode == 0)
			{
				fseek(input, position, SEEK_SET);
				statusCode = fscanf(input, "\t������: %d", &groupNumber);
				if (statusCode != 1)
				{
					delete(group);
					std::cout << "������ ������ �����." << std::endl;
					fclose(input);
					return;
				}
				else if (statusCode == 1)
				{
					this->addGroup(group);
					break;
				}
			}
			else if (statusCode == 2)
			{
				Student *student = new Student(studentLastName, studentYear);
				group->addStudent(student);
			}
			else if (statusCode == 1)
			{
				delete(group);
				std::cout << "������ ������ �����." << std::endl;
				fclose(input);
				return;
			}
			
		}
	}
}

//����� ���� ��������� �� �����.
void Faculty::show()
{
	if (this->mass == NULL)
	{
		std::cout << "��������� ����." << std::endl;
		return;
	}
	std::cout << "���������: " << this->getName() << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		if (this->mass[i] != NULL)
		{
			std::cout << "\t������: " << this->mass[i]->getNumber() << std::endl;
			Student *current = this->mass[i]->getStudent();
			while (current != NULL)
			{
				std::cout << "\t\t�������: " << current->getLastName() << ", ��� ��������: " << current->getYear() << std::endl;
				current = current->getNext();
			}
		}
	}
}

char* Faculty::getName()
{
	return this->name;
}

//ToDo: ������� ���������� � ����.
void Faculty::saveInFile()
{
	if (this->mass == NULL)
	{
		std::cout << "��������� ����." << std::endl;
		return;
	}
	FILE *output = fopen("file.txt", "w");
	fprintf(output, "���������: %s\n", this->name);
	for (int i = 0; i < this->count; i++)
	{
		if (this->mass[i] != NULL)
		{
			fprintf(output, "\t������: %d\n", this->mass[i]->getNumber());
			Student *current = this->mass[i]->getStudent();
			while (current != NULL)
			{
				fprintf(output, "\t\t�������: %s, ��� ��������: %d\n", current->getLastName(), current->getYear());
				current = current->getNext();
			}
		}
	}
	fclose(output);
}
void Faculty::search()
{
	if (this->mass == NULL)
	{
		std::cout << "��������� ����." << std::endl;
	}
	int select;
	std::cout << "1)����� �������� � ������.\n2)����� �������� �� ����� ����������." << std::endl;
	while (!(std::cin >> select))
	{
		std::cout << "������ �����." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "1)����� �������� � ������.\n2)����� �������� �� ����� ����������.\n" << std::endl;
	}
	if (select == 1)
	{
		int groupNumber;
		std::cout << "������� ����� ������." << std::endl;
		while (!(std::cin >> groupNumber))
		{
			std::cout << "������ �����." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "������� ����� ������." << std::endl;
		}
		for (int i = 0; i < this->count; i++)
		{
			if (this->mass[i]->getNumber() == groupNumber)
			{
				char *lastName = (char*)malloc(256 * sizeof(char));
				std::cout << "������� ������� ��������, �������� ������ �����." << std::endl;
				std::cin >> lastName;
				Student *current = this->mass[i]->getStudent();
				while (current != NULL)
				{
					if (!strcmp(current->getLastName(), lastName))
					{
						std::cout << "������: " << this->mass[i]->getNumber() << std::endl;
						std::cout << "\t�������: " << current->getLastName() << ", ��� ��������: " << current->getYear() << std::endl;
						return;
					}
					current = current->getNext();
				}
			}
		}
	}
	else if (select == 2)
	{
		char *lastName = (char*)malloc(256 * sizeof(char));
		std::cout << "������� ������� ��������, �������� ������ �����." << std::endl;
		std::cin >> lastName;
		for (int i = 0; i < this->count; i++)
		{
			if (this->mass[i] != NULL)
			{
				Student *current = this->mass[i]->getStudent();
				while (current != NULL)
				{
					if (!strcmp(current->getLastName(), lastName))
					{
						std::cout << "������: " << this->mass[i]->getNumber() << std::endl;
						std::cout << "\t�������: " << current->getLastName() << ", ��� ��������: " << current->getYear() << std::endl;
					}
					current = current->getNext();
				}
			}
		}
	}
}

void Faculty::setName(char *name)
{
	this->name = name;
}