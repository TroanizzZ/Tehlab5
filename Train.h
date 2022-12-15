#pragma once
#include <iostream>
#include <string>
using namespace std;

class Train
{
	string sEndPoint; //Названия пункта прибытия
	string sTrainNum; //Номер поезда
	string sTimeStartHours;//Время отъезда
	string sTimeStartMinutes;//Время отъезда
public:
	Train();
	Train(const Train& obj);
	~Train();

	//Seters
	void setEndPoint(string _sEndPoint);
	void setTrainNum(string _sTrainNum);
	void setTimeStartHours(string _sTimeStart);
	void setTimeStartMinutes(string _sTimeStart);

	//Geters
	string getEndPoint();
	string getTrainNum();
	string getTimeStartHours();
	string getTimeStartMinutes();

	//Metods
	friend ostream& operator<<(ostream& stream, Train& obj);
};