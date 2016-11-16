#include "jogger.h"
#include<iostream>
#include<string>
#include <stdlib.h> 
#include <fstream>
#include<boost\archive\text_oarchive.hpp>
#include<boost\archive\text_iarchive.hpp>
using namespace std;

void Jogger::getJoggingTime() {
	cout << "Enter jogging time (in mins): " << endl;
	cin >> joggingTime;
	joggingTimeList.push_back(joggingTime);
}

void Jogger::getJoggingTime(float jtime) {
	joggingTime = jtime;
	joggingTimeList.push_back(jtime);
}

void Jogger::maxValue(std::vector<float> inputVector) {
	//	function to find the maximum value within
	//	the given input vector.
	//	Good idea to sort first and simply
	//	call vectorList.back() method.
	sortValues(inputVector);
	inputVector.back();//Need to return value?
}

void Jogger::sortValues(std::vector<float> vectorToBeSorted) {
	insertionSort(vectorToBeSorted);//	function to sort values within
	//	given vector.
	//	Should not alter original vector.

}

void Jogger::insertionSort(std::vector<float> inputVector) {
	float value;
	int hole;

	for (unsigned int i = 1; i < inputVector.size();i++) {
		value = inputVector[i];
		hole = i;
		while (hole > 0 && inputVector[hole - 1] > value) {
			inputVector[hole] = inputVector[hole - 1];
			hole = hole - 1;
		}
		inputVector[hole] = value;
	}

	for (unsigned int j = 0;j < inputVector.size();j++)
		cout << inputVector[j] << endl;
}

void Jogger::sortDistances() {
	sortValues(joggingDistanceList);
}

void Jogger::speedCalculator(float jdist, float jtime) {
	joggingSpeed = jdist / (jtime*60.0f);
	joggingSpeedList.push_back(joggingSpeed);
}

void Jogger::displayLatestSpeed() {
	cout << "Speed for this run:" << joggingSpeedList.back()
		<< " m/sec" << endl;
}

void Jogger::tellJoggerNumber() {
	cout << "Total Joggers = " << joggerNumber << endl;
}

void Jogger::getJoggerName() {
	std::cout << "Enter jogger first name " << endl;
	std::cin >> joggerName;		// this gets a word
}

void Jogger::displayJoggerName() {
	std::cout << "Jogger name : ";
	for (unsigned int i = 0; i<joggerName.size(); ++i)
		std::cout << joggerName[i];
	std::cout << endl;
}

void Jogger::getJoggingDistance() {
	cout << "Enter jogging distance for this run (in meters):" << endl;
	cin >> joggingDistance;
	joggingDistanceList.push_back(joggingDistance);
}

void Jogger::getJoggingDistance(float jdist) {
	joggingDistance = jdist;
	
	joggingDistanceList.push_back(jdist);
}

void Jogger::displayJoggingDistance() {
	cout << "Jogging distance for this run was "
		<< joggingDistanceList.back() << " meters" << endl;
}

void Jogger::displayJoggingTime(){
	cout << "Jogging time for this run was "
		<< joggingTimeList.back() << "mins" << endl;
}

void Jogger::getInfo() {
	getJoggerName();
	getJoggingDistance();
	getJoggingTime();
}

void Jogger::displayInfo() {
	displayJoggerName();
	displayJoggingDistance();
	displayJoggingTime();
	displayLatestSpeed();
}

Jogger::Jogger() {
		
	//joggerNumber++;	//	Keeping track of objects created

	getInfo();			//	Taking user info
	speedCalculator(joggingDistance, joggingTime);
	displayInfo();	//	Displaying user info
	
}

Jogger::Jogger(float jdist, float jtime) {
	joggingDistance = jdist;
	joggingTime = jtime;	
	
	joggingDistanceList.push_back(jdist);
	joggingTimeList.push_back(jtime);
	speedCalculator(jdist, jtime);
}


Jogger::~Jogger() {
	cout << "Object being deleted" << endl;
}

int Jogger::joggerNumber = 0;	//	Object counter initialization