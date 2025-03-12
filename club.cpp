#include "newclub.h"
#include <iostream>
#include <set>
#include <string>
#include<vector>
#include<map>

using namespace std;

// Constructor for Club
Club::Club(string n, string p, string h, int si, int yr, int exp)
	: name(n), pic(p), head(h), c_size(si), found_yr(yr), expenses(exp) {}
Club::~Club(){}

// Method to add achievements to the Club
void Club::add_achievements(string achievement) {
	achievements.push_back(achievement);
}

// Overload the << operator to output Club details
ostream &operator<<(ostream &out, const Club &c) {
	out << "Club Name : " << c.name << endl;
	out << "Club Head : " << c.head << endl;
	out << "Professor Incharge : " << c.pic << endl;
	out << "Founded Year : " << c.found_yr << endl;
	out << "Club Size : " << c.c_size << endl;
	out << "Club Expenses : " << c.expenses << endl;
	out << "Achievements: " << endl;
	for (const auto &ach : c.achievements) {
    	out << " - " << ach << endl;
	}
	return out;
}

// Overload the >> operator to input Club details
istream &operator>>(istream &in, Club &c) {
	cout << "Enter Club Name: ";
	in >> c.name;
	cout << "Enter Club Head: ";
	in >> c.head;
	cout << "Enter Professor Incharge of Club: ";
	in >> c.pic;
	cout << "Enter Club Founded Year: ";
	in >> c.found_yr;
	cout << "Enter Club Size: ";
	in >> c.c_size;
	cout << "Enter Club Expenses: ";
	in >> c.expenses;

	int a;
	cout << "Enter 1 to add achievements, 0 to stop: ";
	in >> a;
	in.ignore();
	while (a == 1) {
    	string achievement;
    	cout << "Enter achievement: ";
    	getline(in, achievement);
    	c.add_achievements(achievement);

    	cout << "Enter 1 to add more achievements, 0 to stop: ";
    	in >> a;
    	in.ignore();
	}

	return in;
}



