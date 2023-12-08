#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
using namespace std;
class Pipe;
class Ks
{
public:
	int idInit;
	Ks();
	std::map<Ks*, Pipe*> parents;
	std::set<Pipe*> tubes;
	static void ksInput();
	static void KsEdit();
	static void deleteKs();
	static void findKs();
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

