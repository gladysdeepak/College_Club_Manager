#include "newclub.h"
#include <iostream>
#include <set>
#include <string>
#include<vector>
#include<map>

using namespace std;

// Constructor for Competitive class
Competitive::Competitive(string name, string pic, string head, int c_size, int found_yr, int expenses, string main_focus)
	: Tech(name, pic, head, c_size, found_yr, expenses, main_focus) {
	cout << "Competitive Technical Club constructed." << endl;
}

void Competitive::print_interns() const {
	if (interns.empty())
    	cout << "List of interns is empty." << endl;
	else {
    	cout << endl << "List of interns: " << endl;
    	for (const string &i : interns)
        	cout << i << endl;
	}
}

void Competitive::modify_interns() {
	cout << "Choose intern operations :" << endl;
	bool b = true;
	while (b) {
    	cout << "1. Add intern" << endl;
    	cout << "2. Remove intern" << endl;
    	cout << "3. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	switch (choice) {
        	case 1: {
            	string name;
            	cout << "Enter the name of the intern to be added: ";
            	getline(cin, name);
            	interns.insert(name);
            	cout << "Updated." << endl;
            	print_interns();
            	c_size = interns.size();
            	break;
        	}
        	case 2: {
            	string name;
            	cout << "Enter the name of the intern to be removed: ";
            	getline(cin, name);
            	interns.erase(name);
            	cout << "Updated." << endl;
            	print_interns();
            	c_size = interns.size();
            	break;
        	}
        	case 3:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!" << endl;
            	b = false;
            	break;
    	}
	}
}

void Competitive::print_competitions() const {
	cout << endl << "List of competitions: " << endl;
	for (const auto &competition : competitions)
    	cout << "Competition: " << competition.first << ", Place: " << competition.second << endl;
}

void Competitive::modify_competitions() {
	cout << "Choose competition operations :" << endl;
	bool b = true;
	while (b) {
    	cout << "1. Add competition" << endl;
    	cout << "2. Delete competition" << endl;
    	cout << "3. Display competitions" << endl;
    	cout << "4. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	string comp;
    	switch (choice) {
        	case 1: {
            	cout << "Enter the competition to be added: ";
            	getline(cin, comp);
            	*this += comp;
            	break;
        	}
        	case 2:
            	cout << "Enter the competition to be deleted: ";
            	getline(cin, comp);
            	*this -= comp;
            	break;
        	case 3:
            	print_competitions();
            	break;
        	case 4:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!" << endl;
		b = false;
            	break;
    	}
	}
}

ostream &operator<<(ostream &out, const Competitive &c) {
	out << "Club Name: " << c.name << endl;
	out << "Club Head: " << c.head << endl;
	out << "Professor in charge: " << c.pic << endl;
	out << "Founded Year: " << c.found_yr << endl;
	out << "Club Size: " << c.c_size << endl;
	out << "Club Expenses: " << c.expenses << endl;
	out << "Main Focus: " << c.main_focus << endl;
	c.print_interns();
	c.print_competitions();
	for (const auto &ach : c.achievements) {
    	out << " - " << ach << endl;
	}
	return out;
}

istream &operator>>(istream &in, Competitive &c) {
	in.ignore();
	cout << "Enter Club Name: ";
	getline(in, c.name);
	cout << "Enter Club Head: ";
	getline(in, c.head);
	cout << "Enter Professor in Charge: ";
	getline(in, c.pic);
	cout << "Enter Club Founding Year: ";
	in >> c.found_yr;
	cout << "Enter Club Size: ";
	in >> c.c_size;
	cout << "Enter Club Expenses: ";
	in >> c.expenses;
	c.modify_interns();
	c.modify_competitions();
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

Competitive & Competitive::operator+=(const string &comp) {
	string place;
	cout << "Enter the place of the competition: ";
	getline(cin, place);
	competitions[comp] = place;
	cout << "Successfully added competition." << endl;
	return *this;
}

Competitive & Competitive::operator-=(const string &comp) {
	competitions.erase(comp);
	cout << "Successfully deleted competition." << endl;
	return *this;
}
