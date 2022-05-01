// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include <iostream>
#include "Helper.h"


//dynamic memory
struct Person_D {
	char* Name = nullptr;
	int Age;
};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int records = 0;
	int sameRecord = 1;

	Helper H;

	H.GetIntPointer("How many records would you like: ", &records);
	Person_D** recordStruct = new Person_D*[records];

	for (int i = 0; i < records; i++)
	{
		std::cout << "What is the name of record " << i + 1 << ": ";
		
		recordStruct[i] = new Person_D;
		H.getText(recordStruct[i]->Name);
		
		for (int j = 0; j < i; j++)
		{
			sameRecord = strcmp(recordStruct[i]->Name, recordStruct[j]->Name);
			if (sameRecord == 0)
			{
				std::cout << "Error! Same name of Record " << i + 1 << ": Try Again" << std::endl;
				delete[] recordStruct[i]->Name;
				H.getText(recordStruct[i]->Name);
				j--;
			}
		
		}


		H.GetIntPointer("What is the age of this person", &recordStruct[i]->Age);
		
		

		
	}
	
	for (int j = 0; j < records; j++)
	{
		std::cout << "Record " << j + 1 << "- Name: " << recordStruct[j]->Name << " Age: " << recordStruct[j]->Age << std::endl;
	}


	for (int i = 0; i < records; i++)
	{
		delete[] recordStruct[i]->Name;
		delete recordStruct[i];
		
	}

	delete[] recordStruct;

}









