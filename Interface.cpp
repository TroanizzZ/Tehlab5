#include "Interface.h"

Interface::Interface()
{
	cout << "Interface class constructor called" << endl;
	data = nullptr;
	size = 0;
}

Interface::~Interface()
{
	if (data)
		delete[] data;
	cout << "Interface class destructor called" << endl;
}

void Interface::add()
{
	string sTmp;
	int iTmp;
	try
	{
		system("CLS");
		cout << "---------| Adding |---------" << endl;
		Train* tmp = new Train[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		cout << "Enter train number: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"Train number cannot be empty";
		tmp[size].setTrainNum(sTmp);
		cout << "Enter the train arrival location: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"The train arrival point cannot be empty";
		tmp[size].setEndPoint(sTmp);
		cout << "Enter the time of departure of the train:" << endl;
		cout << "Hours [0-23]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 23)
			throw (string)"Entering an hour should be in the range from 0 to 23!";
		tmp[size].setTimeStartHours(sTmp);
		cout << "Minutes[0-59]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 59)
			throw (string)"Entering minutes should be in the range from 0 to 59!";
		if (iTmp < 10)
			sTmp = '0' + sTmp;
		tmp[size].setTimeStartMinutes(sTmp);
		if (data)
			delete[] data;
		data = tmp;
		cout << "The element is successfully added" << endl;
		size++;
		system("pause");
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
		system("pause");
	}
}

void Interface::red()
{
	try
	{
		system("CLS");
		string sTmp;
		int iTmp;
		cout << "---------| Redacting |---------" << endl;
		int choise1;
		cout << "Enter what train do you want to change" << endl;
		cin >> choise1;
		if (choise1 < 0 || choise1 >size+1)
		{
			throw (string)"Those train doesn't exist";
		}
		int choise2;
		cout << "Enter what parametr do you want to redact" << endl
			<< "1. Train number" << endl
			<< "2. Arrival location" << endl
			<< "3. Time of departure" << endl;
		cin >> choise2;
		if (choise2<1 || choise2 >3)
		{
			throw (string)"Those parametr doesn't exist";
		}
		if (choise2 == 1) {
			cout << "Enter new train number: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"Train number cannot be empty";
			data[choise1].setTrainNum(sTmp);
		}
		if (choise2 == 2) {
			cout << "Enter new train arrival location: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"Train number cannot be empty";
			data[choise1].setEndPoint(sTmp);
		}
		if (choise2 == 3) {
			cout << "Enter new time of departure of the train:" << endl;
			cout << "Hours [0-23]: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			iTmp = stoi(sTmp);
			if (iTmp < 0 || iTmp > 23)
				throw (string)"Entering an hour should be in the range from 0 to 23!";
			data[choise1].setTimeStartHours(sTmp);
			cout << "Minutes[0-59]: ";
			getline(cin, sTmp);
			iTmp = stoi(sTmp);
			if (iTmp < 0 || iTmp > 59)
				throw (string)"Entering minutes should be in the range from 0 to 59!";
			if (iTmp < 10)
				sTmp = '0' + sTmp;
			data[choise1].setTimeStartMinutes(sTmp);
		}
		cout << "The element is successfully redact" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
		system("pause");
	}
}

void Interface::del()
{
	int index;
	system("CLS");
	cout << "---------| Extracting |---------" << endl;
	try
	{
		if (!size)
			throw (string)"No trains to extract";
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << data[i].getTrainNum() << endl;
		}
		cout << "Select the element for removal: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"The selected element does not exist";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "Item retrieved successfully" << endl;
			size--;
			system("pause");
			return;
		}
		Train* tmp = new Train[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			tmp[j] = data[i];
			j++;
		}
		delete[] data;
		data = tmp;
		size--;
		cout << "Item retrieved successfully" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}


void Interface::sort()
{
	system("CLS");
	cout << "---------| Sorting by alphabet |---------" << endl;
	try
	{
		if (!size)
			throw (string)"No trains to sort";
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (strcmp(data[j].getEndPoint().c_str() , data[j + 1].getEndPoint().c_str()) > 0) {
					swap(data[j], data[j + 1]);// меняем элементы местами
				}
			}
		}
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}

void Interface::sortup()
{
	system("CLS");
	cout << "---------| Sorting by length |---------" << endl;
	try
	{
		if (!size)
			throw (string)"No train to sort";
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (data[j].getEndPoint().length() > data[j + 1].getEndPoint().length()) {
					swap(data[j], data[j + 1]);// меняем элементы местами
				}
			}
		}
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}

void Interface::search()
{
	system("CLS");
	cout << "---------| Search |---------" << endl;
	try
	{
		if (!size)
			throw (string)"No trains to find";
		string sTime; // Время
		string sTimeFormat; // Время
		bool empty = false; // Флаг пустоты вывода
		int iTime;
		cout << "Enter hours [0-23]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 23)
			throw (string)"Entering an hour should be in the range from 0 to 24!";
		sTimeFormat = sTime;
		cout << "Enter minutes [0-59]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 59)
			throw (string)"Entering minutes should be in the range from 0 to 60!";
		for (int i = 0; i < size; i++) {
			if (stoi(sTimeFormat)<stoi(data[i].getTimeStartHours())) {
					!empty ? empty = true : false;
					cout << data[i];
			}
			else if (stoi(sTimeFormat) == stoi(data[i].getTimeStartHours())) {
				if (stoi(sTime) < stoi(data[i].getTimeStartMinutes())) {
					!empty ? empty = true : false;
					cout << data[i];
				}
			}
		}
		if (!empty)
			cout << "There are no suitable trains for your request!" << endl;
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}


void Interface::searchArr()
{
	system("CLS");
	cout << "---------| Search |---------" << endl;
	try
	{
		if (!size)
			throw (string)"No trains to find";
		string Arr; // Время
		bool empty = false; // Флаг пустоты вывода
		int iTime;
		cout << "Enter location of arriving: ";
		getline(cin,Arr);
		for (int i = 0; i < size; i++) {
			if (Arr==data[i].getEndPoint()) {
				!empty ? empty = true : false;
				cout << data[i];
			}
		}
		if (!empty)
			cout << "There are no suitable trains for your request!" << endl;
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}


void Interface::print()
{
	system("CLS");
	cout << "---------| List |---------" << endl << endl;
	try
	{
		if (!size)
			throw (string)"No trains to output";
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
	}
}