#include "newclub.h"
#include <iostream>
#include <set>
#include <string>
#include<vector>
#include<map>

using namespace std;

// Constructor for Tech class
Tech::Tech(string name, string pic, string head, int c_size, int found_yr, int expenses, string focus)
	: Club(name, pic, head, c_size, found_yr, expenses), main_focus(focus) {}

// Overloaded output operator
ostream &operator<<(ostream &out, const Tech &c) {
	out << "Club Name : " << c.name << endl;
	out << "Club Head : " << c.head << endl;
	out << "Professor in charge : " << c.pic << endl;
	out << "Founded Year : " << c.found_yr << endl;
	out << "Club Size : " << c.c_size << endl;
	out << "Club expenses : " << c.expenses << endl;
	out << "Main focus: " << c.main_focus << endl;
	c.print_cores();
	c.print_jcores();
	return out;
}

// Overloaded input operator
istream &operator>>(istream &in, Tech &c) {
	cout << "Enter Club Name: ";
	in >> c.name;
	cout << "Enter Club Head: ";
	in >> c.head;
	cout << "Enter Professor in charge of Club: ";
	in >> c.pic;
	cout << "Enter Club Founded year: ";
	in >> c.found_yr;
	cout << "Enter Club Size: ";
	in >> c.c_size;
	cout << "Enter Club Expenses: ";
	in >> c.expenses;
	cout << "Enter the main focus: ";
	in.ignore();
	getline(in, c.main_focus);

	int a;
	cout << "Enter 1 to add achievements, 0 to stop adding achievements." << endl;
	in >> a;
	in.ignore();  // Clear the newline for the following getline
	while (a != 0) {
    	switch (a) {
        	case 1: {
            	string achievement;
            	cout << "Enter achievement: ";
            	getline(in, achievement);
            	c.add_achievements(achievement);
            	break;
        	}
        	case 0:
            	break;
        	default:
            	cout << "Invalid Operation.." << endl;
            	break;
    	}
    	cout << "Enter 1 to add achievements, 0 to stop adding achievements." << endl;
    	in >> a;
    	in.ignore();
	}
	c.modify_cores();
	c.modify_jcores();
	return in;
}

// Print cores
void Tech::print_cores() const {
	cout << endl << "List of cores: " << endl;
	for (const auto &n : cores)
    	cout << n << " ";
	cout << endl;
}

// Modify cores
void Tech::modify_cores() {
	bool b = true;
	while (b) {
    	cout << "1. Add core" << endl;
    	cout << "2. Remove core" << endl;
    	cout << "3. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	switch (choice) {
        	case 1: {
            	string name;
            	cout << "Enter the name of the core to be added: ";
            	getline(cin, name);
            	cores.insert(name);
            	cout << "Updated...";
            	print_cores();
            	c_size = cores.size();  // Update size based on cores
            	break;
        	}
        	case 2: {
            	string name;
            	print_cores();
            	cout << "Enter the name to be removed: ";
            	getline(cin, name);
            	cores.erase(name);
            	cout << "Updated ";
            	print_cores();
            	c_size = cores.size();
            	break;
        	}
        	case 3:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!!!" << endl;
    	}
	}
}

// Print joint cores
void Tech::print_jcores() const {
	cout << endl << "List of joint cores: " << endl;
	for (const auto &n : joint_cores)
    	cout << n << " ";
	cout << endl;
}

// Modify joint cores
void Tech::modify_jcores() {
	bool b = true;
	while (b) {
    	cout << "1. Add joint core" << endl;
    	cout << "2. Remove joint core" << endl;
    	cout << "3. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	switch (choice) {
        	case 1: {
            	string name;
            	cout << "Enter the name of the joint core to be added: ";
            	getline(cin, name);
            	joint_cores.insert(name);
            	cout << "Updated...";
            	print_jcores();
            	c_size = joint_cores.size();
            	break;
        	}
        	case 2: {
            	string name;
            	print_jcores();
            	cout << "Enter the name to be removed: ";
            	getline(cin, name);
            	joint_cores.erase(name);
            	cout << "Updated...";
            	print_jcores();
            	c_size = joint_cores.size();
            	break;
        	}
        	case 3:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!!!" << endl;
    	}
	}
}
