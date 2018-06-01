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
	delete(this);
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
