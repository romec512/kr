#include "Faculty.h"
#include "Header.h"

Faculty::Faculty()
{
	this->mass = (Group**)malloc(10*sizeof(Group*));
	for (int i = 0; i < 10; i++)//инициализируем NULL ссылками
	{
		this->mass[i] = NULL;
	}
	this->count = 0;
	this->size = 10;
	//this->name = (char*)malloc(256 * sizeof(char));
	//std::cout << "Введите название факультета:" << std::endl;
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
			if (student == NULL)
			{
				std::cout << "В группе нет студентов." << std::endl;
				return;
			}
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

void Faculty::addContent()
{
	if (this->name == NULL)
	{
		std::cout << "Введите название факультета." << std::endl;
		this->name = (char*)malloc(256 * sizeof(char));
		std::cin >> this->name;
	}
	int select; 
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
					std::cout << "Введите год рождения." << std::endl;
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

// удаление группы или студента, выбор осуществляется выбором из клавиатуры.
void Faculty::deleteContent()
{
	if (this->mass[0] == NULL)
	{
		std::cout << "Факультет пуст." << std::endl;
		return;
	}
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

//Загрузка данных из файла.
void Faculty::LoadFromFile()
{
	FILE *input = fopen("file.txt", "r");
	if (input == NULL)
	{
		std::cout << "Ошибка открытия файла" << std::endl;
		return;
	}
	char *facultyName = (char*)malloc(256*sizeof(char));
	int groupNumber;
	int statusCode = 1;
	if (!fscanf(input, "Факультет: %[a-zA-Zа-яА-Я]", facultyName))
	{
		std::cout << "Ошибка чтения." << std::endl;
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
		statusCode = fscanf(input, "\tГруппа: %d", &groupNumber);
		if (statusCode == 0)
		{
			std::cout << "Ошибка чтения файла." << std::endl;
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
			statusCode = fscanf(input, "\t\tСтудент: %[a-zA-Zа-яА-Я], год рождения: %d", studentLastName, &studentYear);
			if (statusCode == -1)
			{
				this->addGroup(group);
				fclose(input);
				return;
			}
			else if (statusCode == 0)
			{
				fseek(input, position, SEEK_SET);
				statusCode = fscanf(input, "\tГруппа: %d", &groupNumber);
				if (statusCode != 1)
				{
					delete(group);
					std::cout << "Ошибка чтения файла." << std::endl;
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
				std::cout << "Ошибка чтения файла." << std::endl;
				fclose(input);
				return;
			}
			
		}
	}
}

//вывод всей структуры на экран.
void Faculty::show()
{
	if (this->mass == NULL)
	{
		std::cout << "Факультет пуст." << std::endl;
		return;
	}
	std::cout << "Факультет: " << this->getName() << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		if (this->mass[i] != NULL)
		{
			std::cout << "\tГруппа: " << this->mass[i]->getNumber() << std::endl;
			Student *current = this->mass[i]->getStudent();
			while (current != NULL)
			{
				std::cout << "\t\tСтудент: " << current->getLastName() << ", год рождения: " << current->getYear() << std::endl;
				current = current->getNext();
			}
		}
	}
}

char* Faculty::getName()
{
	return this->name;
}

//ToDo: Сделать сохранение в файл.
void Faculty::saveInFile()
{
	if (this->mass == NULL)
	{
		std::cout << "Факультет пуст." << std::endl;
		return;
	}
	FILE *output = fopen("file.txt", "w");
	fprintf(output, "Факультет: %s\n", this->name);
	for (int i = 0; i < this->count; i++)
	{
		if (this->mass[i] != NULL)
		{
			fprintf(output, "\tГруппа: %d\n", this->mass[i]->getNumber());
			Student *current = this->mass[i]->getStudent();
			while (current != NULL)
			{
				fprintf(output, "\t\tСтудент: %s, год рождения: %d\n", current->getLastName(), current->getYear());
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
		std::cout << "Факультет пуст." << std::endl;
	}
	int select;
	std::cout << "1)Поиск студента в группе.\n2)Поиск студента по всему факультету." << std::endl;
	while (!(std::cin >> select))
	{
		std::cout << "Ошибка ввода." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "1)Поиск студента в группе.\n2)Поиск студента по всему факультету.\n" << std::endl;
	}
	if (select == 1)
	{
		int groupNumber;
		std::cout << "Введите номер группы." << std::endl;
		while (!(std::cin >> groupNumber))
		{
			std::cout << "Ошибка ввода." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Введите номер группы." << std::endl;
		}
		for (int i = 0; i < this->count; i++)
		{
			if (this->mass[i]->getNumber() == groupNumber)
			{
				char *lastName = (char*)malloc(256 * sizeof(char));
				std::cout << "Введите фамилию студента, которого хотите найти." << std::endl;
				std::cin >> lastName;
				Student *current = this->mass[i]->getStudent();
				while (current != NULL)
				{
					if (!strcmp(current->getLastName(), lastName))
					{
						std::cout << "Группа: " << this->mass[i]->getNumber() << std::endl;
						std::cout << "\tСтудент: " << current->getLastName() << ", год рождения: " << current->getYear() << std::endl;
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
		std::cout << "Введите фамилию студента, которого хотите найти." << std::endl;
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
						std::cout << "Группа: " << this->mass[i]->getNumber() << std::endl;
						std::cout << "\tСтудент: " << current->getLastName() << ", год рождения: " << current->getYear() << std::endl;
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