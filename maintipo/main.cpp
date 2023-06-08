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
	std::cout << "\n������� ���: ";
	std::getline(std::cin, temp.name); 
	std::cout << "������� ���� ��������: ";
	std::cin >> temp.birthDay[0];
	std::cout << "������� ����� ��������: ";
	std::cin >> temp.birthDay[1];
	std::cout << "������� ��� ��������: ";
	std::cin >> temp.birthDay[2];


	if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 3) || 
		(temp.birthDay[0] <= 19 && temp.birthDay[1] == 4))
	{
		temp.zodiak = "����";
	}
	else if ((temp.birthDay[0] >= 20 && temp.birthDay[1] == 4) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 5))
	{
		temp.zodiak = "�����";
	}
	else if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 5) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 6))
	{
		temp.zodiak = "��������";
	}
	else if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 6) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 7))
	{
		temp.zodiak = "���";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 7) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 8))
	{
		temp.zodiak = "���";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 8) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 9))
	{
		temp.zodiak = "����";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 9) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 10))
	{
		temp.zodiak = "����";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 10) ||
		(temp.birthDay[0] <= 21 && temp.birthDay[1] == 11))
	{
		temp.zodiak = "��������";
	}
	else if ((temp.birthDay[0] >= 22 && temp.birthDay[1] == 11) ||
		(temp.birthDay[0] <= 21 && temp.birthDay[1] == 12))
	{
		temp.zodiak = "�������";
	}
	else if ((temp.birthDay[0] >= 22 && temp.birthDay[1] == 12) ||
		(temp.birthDay[0] <= 19 && temp.birthDay[1] == 1))
	{
		temp.zodiak = "�������";
	}
	else if ((temp.birthDay[0] >= 20 && temp.birthDay[1] == 1) ||
		(temp.birthDay[0] <= 18 && temp.birthDay[1] == 2))
	{
		temp.zodiak = "�������";
	}
	else if ((temp.birthDay[0] >= 19 && temp.birthDay[1] == 2) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 3))
	{
		temp.zodiak = "����";
	}
	else
	{
		std::cerr << "������ ������ �������";
		temp.zodiak = "�� ���-�� �� �� ����� :0";
	}
	std::cin.ignore();
	data.push_back(temp);

}
void ShowAll(std::vector<InfoAboutHuman>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << "\n���: " << data.at(i).name << "\n"; //�������� 
		std::cout << "���� �������: " << data.at(i).zodiak << "\n"; 
		std::cout << "���� ��������: " << data.at(i).birthDay[0] << "." <<
			data.at(i).birthDay[1] << "." << data.at(i).birthDay[2] << "\n";

	}
}
int GetZodiak(std::string zodiak)
{
	if (zodiak == "����")
	{
		return 1;
	}
	else if (zodiak == "�����")
	{
		return 2;
	}
	else if (zodiak == "��������")
	{
		return 3;
	}
	else if (zodiak == "���")
	{
		return 4;
	}
	else if (zodiak == "���")
	{
		return 5;
	}
	else if (zodiak == "����")
	{
		return 6;
	}
	else if (zodiak == "����")
	{
		return 7;
	}
	else if (zodiak == "��������")
	{
		return 8;
	}
	else if (zodiak == "�������")
	{
		return 9;
	}
	else if (zodiak == "�������")
	{
		return 10;
	}
	else if (zodiak == "�������")
	{
		return 11;
	}
	else if (zodiak == "����")
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
