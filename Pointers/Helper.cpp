#include "Helper.h"
#include <iostream>

int Helper::GetValidatedInt(const char* prompt, int nMinRange, int nMaxRange)
{
	while (true)
	{
		int num = GetInt(prompt);
		if (nMinRange == 0 && nMaxRange == 0)
		{
			break;
		}
		if (num >= nMinRange && num <= nMaxRange)
		{
			return num;
		}
		else
		{
			std::cout << "Sorry " << num << " was not within range" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
	system("cls");
}


void Helper::GetIntPointer(const char* prompt, int* num)
{


	while (true)
	{
		std::cout << prompt << std::endl;
		std::cin >> (*num);
		if (!std::cin.fail())
		{
			std::cin.ignore(INT_MAX, '\n');
			break;
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	system("cls");


}


int Helper::GetInt(const char* prompt)
{

	int num;
	std::cout << prompt << std::endl;
	while (true)
	{
		std::cin >> num;
		if (!std::cin.fail())
		{
			std::cin.ignore(INT_MAX, '\n');
			break;
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}



	return num;
}



void Helper::getText(char*& text)
{
	char buffer[1024];
	std::cin.getline(buffer, sizeof(buffer));
	// find how many bytes actualy in char array
	// add one for null terminator
	int length = strlen(buffer) + 1;
	// created space on heap with newly stored char array
	text = new char[length];
	// strcpy do not use, strcpy_s do use
	strcpy_s(text, length, buffer);
	


}