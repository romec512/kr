#include "Faculty.h"
#include "Header.h"

Faculty::Faculty(int size)
{
	this->mass = (Group**)malloc(size*sizeof(Group*));
	for (int i = 0; i < size; i++)//инициализируем NULL ссылками
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
void Faculty::addGroup(Group *group)//добавление группы
{
	if (this->count == this->size)
	{
		std::cout << "Факультет заполнен.\n" << std::endl;
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

Group** Faculty::getMass()//получение массива групп
{
	return this->mass;
}
//NOTE: void Faculty::deleteStudent(int groupNumber, char *lastName)
void Faculty::deleteStudent()
{
	int groupNumber;
	char *lastName = (char*)malloc(256*sizeof(char));
	std::cout << "Введите номер группы, в которой хотите удалить студента." << std::endl;
	while (!(std::cin >> groupNumber))
	{
		std::cout << "Ошибка ввода." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите номер группы, в которой хотите удалить студента." << std::endl;
	}
	Group **mass = this->getMass();
	for (int i = 0; i < this->size; i++)
	{//поиск необходимой группы
		if (mass[i]->getNumber() == groupNumber)//условие нахождения группы
		{
			std::cout << "Введите фамилию студента, которого хотите удалить." << std::endl;
			std::cin >> lastName;
			Student *student = mass[i]->getStudent();
			if (!strcmp(student->getLastName(), lastName))//проверка первого студента в списке
			{
				Student *next = student->getNext();
				mass[i]->setStudent(next);//фамилии совпали - удаляем.
				delete(student);
				return;
			}
			while (student->getNext() != NULL) //аналогичное удаление для остальных элементов
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
	std::cout << "Студент не найден." << std::endl;
}

//NOTE: void Faculty::addStudent(int groupNumber, char *lastName, int year)
void Faculty::addStudent(int groupNumber, char *lastName, int year)//добавление студента
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
//ToDo: сделать полный метод добавления чего-либо(группы, либо студента) в классе Faculty.
//Doing: в условие select == 1 добавить чтение из файла

void Faculty::addContent()
{
	int select; 
	std::cout << "1)Добавить из файла.\n2)Ввести с клавиатуры." << std::endl;
	while (!(std::cin >> select))
	{
		std::cout << "Ошибка ввода." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "1)Добавить из файла.\n2)Ввести с клавиатуры." << std::endl;
	}
	if (select == 1)
	{

	}
	else if (select == 2)
	{
		std::cout << "1)Добавить группу.\n2)Добавить студента." << std::endl;
		while (!(std::cin >> select))
		{
			std::cout << "Ошибка ввода." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "1)Добавить группу.\n2)Добавить студента." << std::endl;
		}
		if (select == 1)
		{
			int number;
			std::cout << "Введите номер группы." << std::endl;
			while (!(std::cin >> number))
			{
				std::cout << "Ошибка ввода." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Введите номер группы." << std::endl;
			}
			Group *newGroup = new Group();
			newGroup->setNumber(number);
			newGroup->setStudent(NULL);
			this->addGroup(newGroup);
		}
		else if (select == 2)
		{
			int number;
			std::cout << "Введите номер группы, в которую хотите добавить студента." << std::endl;
			while (!(std::cin >> number))
			{
				std::cout << "Ошибка ввода." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Введите номер группы, в которую хотите добавить студента." << std::endl;
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
					std::cout << "Введите фамилию." << std::endl;
					std::cin >> lastName;
					std::cout << "Введите год рождения.\n" << std::endl;
					while (!(std::cin >> year))
					{
						std::cout << "Ошибка ввода." << std::endl;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Введите год рождения." << std::endl;
					}
					Student *newStudent = new Student(lastName, year);
					mass[i]->addStudent(newStudent);
					return;
				}
			}
			std::cout << "Группа не найдена." << std::endl;
		}
	}
}
//NOTE:void Faculty::deleteGroup()  удаление группы, ввод номера групы осуществляется из консоли.
void Faculty::deleteGroup()
{
	int number;
	std::cout << "Введите номер группы, которую хотите удалить." << std::endl;
	while (!(std::cin >> number))
	{
		std::cout << "Ошибка ввода." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите номер группы." << std::endl;
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
	std::cout << "Группа не найдена." << std::endl;
}
//ToDo: как и для добавления сделать общий метод удаления в этом классе
void Faculty::deleteContent()
{
	int select;
	std::cout << "1)Удалить группу.\n2)Удалить студента." << std::endl;
	while (!(std::cin >> select))
	{
		std::cout << "Ошибка ввода." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "1)Удалить группу.\n2)Удалить студента." << std::endl;
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
//ToDo: необходимо продумать добавление из файла и из консоли