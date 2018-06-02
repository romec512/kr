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

void Faculty::deleteStudent()// int groupName - номер группы, в которой будет удален студент, char *lastName - фамилия удаляемого студента
{
	int groupNumber;
	char *lastName = (char*)malloc(256*sizeof(char));
	std::cout << "Введите номер группы, в которой хотите удалить студента." << std::endl;
	std::cin >> groupNumber;
	std::cout << "Введите фамилию студента, которого хотите удалить." << std::endl;
	std::cin >> lastName;
	Group **mass = this->getMass();
	for (int i = 0; i < this->size; i++)
	{//поиск необходимой группы
		if (mass[i]->getNumber() == groupNumber)//условие нахождения группы
		{
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
				}
				student = student->getNext();
			}
		}
	}
}
