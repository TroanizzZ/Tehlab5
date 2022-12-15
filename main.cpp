#include <iostream>
#include <fstream>
#include "Interface.h"
#include <cstring>

int getWords();

int main()
{
	setlocale(LC_ALL, "Russian");
	Interface Table;
	char menu;
	int iCount;
	do
	{
		system("cls");
		cout << "----------| MENU |----------" << endl;
		cout << "1. Add train" << endl
			<< "2. Extract train" << endl
			<< "3. Sort trains by alphabet" << endl
			<< "4. Sort by word length" << endl
			<< "5. Redacting" << endl
			<< "6. Bring a list of trains" << endl
			<< "7. Search for trains by time" << endl
			<< "8. Search for trains by arrival location" << endl
			<< "9. Count the number of words in a file" << endl
			<< "0. Exit" << endl
			<< "Choise: ";
		cin >> menu;
		if (!(cin.peek() == '\n' || cin.peek() == EOF))
		{
			cin.ignore(INT_MAX, '\n');
			cout << "[Error] Enter the menu item within [0-7]" << endl;
			system("pause");
			continue;
		}
		cin.ignore(INT_MAX, '\n');
		switch (menu)
		{
		case '1':
			Table.add();
			break;
		case '2':
			Table.del();
			break;
		case '3':
			Table.sort();
			break;
		case '4':
			Table.sortup();
			break;
		case '5':
			Table.red();
		case '6':
			Table.print();
			break;
		case '7':
			Table.search();
			break;
		case '8':
			Table.searchArr();
			break;
		case '9':
			iCount = getWords();
			if (!(iCount == -1))
				cout << "The number of words : " << iCount << endl;
			break;
		case '0':
			return 0;
		default:
			cout << "[Error] Enter the menu item within [0-8]" << endl;
			break;
		}
		system("pause");
	} while (true);
	system("pause");
	return 0;
}

int getWords()
{
	try
	{
		ifstream file("Text.txt");
		int wordsCount = 0;
		int lengthWord;
		string word;
		if (!file)
			throw (string)"Ошибка открытия файла";
		while (!file.eof())
		{
			file >> word;
			lengthWord = 0;
			for (int i = 0; i < word.length(); i++)
				if (word[i] >= 'a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z')
					lengthWord++;
			if (lengthWord < 5 && lengthWord)
				wordsCount++;
		}
		return wordsCount;
	}
	catch (string err)
	{
		cout << "[Error] " + err << endl;
		return -1;
	}
}