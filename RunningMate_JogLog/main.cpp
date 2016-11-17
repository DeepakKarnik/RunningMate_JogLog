// RunningMate_JogLog.cpp : Defines the entry point for the console application.
// An application to accept user jogging info and perform analysis

#include"jogger.h"
#include<iostream>
#include <stdlib.h> 
#include<string>
//#include <fstream>
#include<boost\archive\text_oarchive.hpp>
#include<boost\archive\text_iarchive.hpp>
using namespace std;

int main()
{
	/*Jogger jogger1(1500.25,25.3);
	ofstream myfile("samplefile.dat", ios::binary | ios::out);
	
	boost::archive::text_oarchive oa(myfile);
	oa << jogger1;*/
	
	//Jogger jogger2;
	//std::ifstream ifs("samplefile.dat", ios::binary | ios::in);
	//boost::archive::text_iarchive ia(ifs);
	//// read class state from archive
	//ia >> jogger2;
	//jogger2.displayJoggingDist();


	Jogger jogger1(3500.25, 25.2);
	jogger1.getJoggingDistance(2600.5);
	jogger1.getJoggingDistance(5305.24);
	jogger1.getJoggingDistance(215.45);
	jogger1.sortDistances();

	return 0;
}