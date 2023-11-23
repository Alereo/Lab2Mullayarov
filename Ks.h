#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Ks
{
public:
	Ks();
	void ksInput();
	void KsEdit();
	void findKs();
	Ks(string name, int amountWorkshops, int amountWorhshopsNow);
	void uptadeEff();
	std::string name;
	int amountWorkshops;
	int amountWorkshopsNow;
	int effectiveness;
	static int id;
	void cout();
	void cout(ofstream& file);
};

