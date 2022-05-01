#pragma once
class Helper
{

private:

	const char* strMessage = nullptr;
	int nMinimumRange = 0;
	int nMaximumRange = 0;

public:

	int GetValidatedInt(const char* strMessage, int nMinimumRange, int nMaximumRange);
	void GetIntPointer(const char* prompt, int* num);
	int GetInt(const char* prompt);
	void getText(char*& text);
};

