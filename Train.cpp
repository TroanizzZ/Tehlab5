#include "Train.h"

ostream& operator<<(ostream& stream, Train& obj)
{
	stream << "----------| Train |-----------" << endl
		<< "Destination: " << obj.getEndPoint() << endl
		<< "Number: " << obj.getTrainNum() << endl
		<< "Departure time: " << obj.getTimeStartHours() << ":" << obj.getTimeStartMinutes() << endl;
	return stream;
}

Train::Train()
{
	cout << "Train class constructor called" << endl;
	sEndPoint = "";
	sTrainNum = "";
	sTimeStartHours = "";
	sTimeStartMinutes = "";
}

Train::Train(const Train& obj)
{
	cout << "Train copy constructor called" << endl;
	sEndPoint = obj.sEndPoint;
	sTrainNum = obj.sTrainNum;
	sTimeStartHours = obj.sTimeStartHours;
	sTimeStartMinutes = obj.sTimeStartMinutes;
}

Train::~Train()
{
	cout << "Train class destructor called" << endl;
}

void Train::setEndPoint(string _sEndPoint)
{
	sEndPoint = _sEndPoint;
}

void Train::setTrainNum(string _sTrainNum)
{
	sTrainNum = _sTrainNum;
}

void Train::setTimeStartHours(string _sTimeStart)
{
	sTimeStartHours = _sTimeStart;
}

void Train::setTimeStartMinutes(string _sTimeStart)
{
	sTimeStartMinutes = _sTimeStart;
}

string Train::getEndPoint()
{
	return sEndPoint;
}

string Train::getTrainNum()
{
	return sTrainNum;
}

string Train::getTimeStartHours()
{
	return sTimeStartHours;
}

string Train::getTimeStartMinutes()
{
	return sTimeStartMinutes;
}