#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <algorithm>
struct InfoAboutHuman
{
	std::string name;
	std::string zodiak;
	int birthDay[3];
};

void AddNewPeople(std::vector<InfoAboutHuman> &data);
void ShowAll(std::vector<InfoAboutHuman> &data);
int GetZodiak(std::string zodiak);
void Sort(std::vector<InfoAboutHuman> &data);

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	std::vector <InfoAboutHuman> people;


	for (int i = 0; i < 3; i++)
	{
		AddNewPeople(people);
	}

	std::cout << std::endl;

	Sort(people);
	
	




	return 0;
}

void AddNewPeople(std::vector<InfoAboutHuman>& data)
{
	InfoAboutHuman temp;
	std::cout << "\nВведите имя: ";
	std::getline(std::cin, temp.name); 
	std::cout << "Введите день рождения: ";
	std::cin >> temp.birthDay[0];
	std::cout << "Введите месяц рождения: ";
	std::cin >> temp.birthDay[1];
	std::cout << "Введите год рождения: ";
	std::cin >> temp.birthDay[2];


	if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 3) || 
		(temp.birthDay[0] <= 19 && temp.birthDay[1] == 4))
	{
		temp.zodiak = "Овен";
	}
	else if ((temp.birthDay[0] >= 20 && temp.birthDay[1] == 4) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 5))
	{
		temp.zodiak = "Телец";
	}
	else if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 5) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 6))
	{
		temp.zodiak = "Близнецы";
	}
	else if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 6) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 7))
	{
		temp.zodiak = "Рак";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 7) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 8))
	{
		temp.zodiak = "Лев";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 8) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 9))
	{
		temp.zodiak = "Дева";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 9) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 10))
	{
		temp.zodiak = "Весы";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 10) ||
		(temp.birthDay[0] <= 21 && temp.birthDay[1] == 11))
	{
		temp.zodiak = "Скорпион";
	}
	else if ((temp.birthDay[0] >= 22 && temp.birthDay[1] == 11) ||
		(temp.birthDay[0] <= 21 && temp.birthDay[1] == 12))
	{
		temp.zodiak = "Стрелец";
	}
	else if ((temp.birthDay[0] >= 22 && temp.birthDay[1] == 12) ||
		(temp.birthDay[0] <= 19 && temp.birthDay[1] == 1))
	{
		temp.zodiak = "Козерог";
	}
	else if ((temp.birthDay[0] >= 20 && temp.birthDay[1] == 1) ||
		(temp.birthDay[0] <= 18 && temp.birthDay[1] == 2))
	{
		temp.zodiak = "Водолей";
	}
	else if ((temp.birthDay[0] >= 19 && temp.birthDay[1] == 2) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 3))
	{
		temp.zodiak = "Рыбы";
	}
	else
	{
		std::cerr << "Ошибка выбора зодиака";
		temp.zodiak = "Вы что-то не то ввели :0";
	}
	std::cin.ignore();
	data.push_back(temp);

}
void ShowAll(std::vector<InfoAboutHuman>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << "\nИмя: " << data.at(i).name << "\n"; //итерация 
		std::cout << "Знак зодиака: " << data.at(i).zodiak << "\n"; 
		std::cout << "Дата рождения: " << data.at(i).birthDay[0] << "." <<
			data.at(i).birthDay[1] << "." << data.at(i).birthDay[2] << "\n";

	}
}
int GetZodiak(std::string zodiak)
{
	if (zodiak == "Овен")
	{
		return 1;
	}
	else if (zodiak == "Телец")
	{
		return 2;
	}
	else if (zodiak == "Близнецы")
	{
		return 3;
	}
	else if (zodiak == "Рак")
	{
		return 4;
	}
	else if (zodiak == "Лев")
	{
		return 5;
	}
	else if (zodiak == "Дева")
	{
		return 6;
	}
	else if (zodiak == "Весы")
	{
		return 7;
	}
	else if (zodiak == "Скорпион")
	{
		return 8;
	}
	else if (zodiak == "Стрелец")
	{
		return 9;
	}
	else if (zodiak == "Козерог")
	{
		return 10;
	}
	else if (zodiak == "Водолей")
	{
		return 11;
	}
	else if (zodiak == "Рыбы")
	{
		return 12;
	}
	else
	{
		return 0;
	}
}
void Sort(std::vector<InfoAboutHuman>& data)
{
	InfoAboutHuman temp;

	for (int i = 0; i < data.size() - 1; i++)
	{
		for (int j = 0; j < data.size() - 1; j++)
		{
			if (GetZodiak(data.at(j + 1).zodiak) < GetZodiak(data.at(j).zodiak))
			{
				temp = data.at(j + 1);
				data.at(j + 1) = data.at(j);
				data.at(j) = temp;
			}
		}
	}
	ShowAll(data);
}
