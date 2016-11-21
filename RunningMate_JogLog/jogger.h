#ifndef JOGGER_H
#define JOGGER_H
#include<vector>

#include<iostream>
#include<string>
#include <stdlib.h> 
#include <fstream>
#include<ctype.h>
#include<boost\archive\text_oarchive.hpp>
#include<boost\archive\text_iarchive.hpp>

class Jogger {
public:
	Jogger();
	Jogger(float jdist, float jtime);	//	Class constructor
	
	void getJoggerName();
	void displayJoggerName();

	void getJoggingDistance();
	void getJoggingDistance(float);
	void displayJoggingDistance();

	void getJoggingTime();
	void getJoggingTime(float);
	void displayJoggingTime();
	
	void getInfo();		
	void displayInfo();

	void speedCalculator(float, float);
	void displayLatestSpeed();
	void maxValue(std::vector<float>);
	void sortDistances();
	void sortValues(std::vector<float>);
	void insertionSort(std::vector<float>);


	~Jogger();	//	Class destructor
	void tellJoggerNumber();	// Not used

private:
	char joggerName[71];
	static int joggerNumber;
	float joggingDistance, joggingTime;
	double joggingSpeed;

	std::vector<float> joggingDistanceList;
	std::vector<float> joggingTimeList;
	std::vector<double>joggingSpeedList;


	friend class boost::serialization::access;
	// When the class Archive corresponds to an output archive, the
	// & operator is defined similar to <<.  Likewise, when the class Archive
	// is a type of input archive the & operator is defined similar to >>.
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{	// Member values to serialize and save
		ar & joggingDistanceList;
		ar & joggingTimeList;
		ar & joggingSpeedList;
	}


};



#endif