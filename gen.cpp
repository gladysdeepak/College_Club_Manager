#include "newclub.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Constructor for General class
General::General(string name, string pic, string head, int c_size, int found_yr, int expenses, string main_focus)
	: Tech(name, pic, head, c_size, found_yr, expenses, main_focus) {
	cout << "General Technical Club constructed." << endl;
}

void General::print_members() const{
	if (members.empty())
    	cout << "List of members is empty." << endl;
	else {
    	cout << endl << "List of members: " << endl;
    	for (const string &i : members)
        	cout << i << endl;
	}
}

void General::modify_members() {
	cout<<"Choose member operations :"<<endl;
	bool b = true;
	while (b) {
    	cout << "1. Add member" << endl;
    	cout << "2. Remove member" << endl;
    	cout << "3. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	switch (choice) {
        	case 1: {
            	string name;
            	cout << "Enter the name of the member to be added: ";
            	getline(cin, name);
            	members.insert(name);
            	cout << "Updated." << endl;
            	print_members();
            	c_size = members.size();
            	break;
        	}
        	case 2: {
            	string name;
            	cout << "Enter the name of the member to be removed: ";
            	getline(cin, name);
            	members.erase(name);
            	cout << "Updated." << endl;
            	print_members();
            	c_size = members.size();
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

void General::print_projects() const {
	cout << endl << "List of projects: " << endl;
	for (const auto &project : projects)
    	cout << "Project: " << project.first << ", Creator: " << project.second << endl;
}

void General::modify_projects() {
	cout<<"Choose project operations :"<<endl;
	bool b = true;
	while (b) {
    	cout << "1. Add project" << endl;
    	cout << "2. Delete project" << endl;
    	cout << "3. Display projects"<< endl;
    	cout << "4. Exit" << endl;
    	cout << "Enter your choice: ";
    	int choice;
    	cin >> choice;
    	cin.ignore();
    	string project;
    	switch (choice) {
        	case 1: {
            	cout << "Enter the project to be added: ";
            	getline(cin, project);
            	*this += project;
            	break;
        	}
        	case 2:
            	cout << "Enter the project to be deleted: ";
            	getline(cin, project);
            	*this -= project;
            	break;
        	case 3:
            	print_projects();
            	break;
        	case 4:
            	b = false;
            	break;
        	default:
            	cout << "Invalid choice!" << endl;
		b=false;
            	break;
    	}
	}
}

ostream &operator<<(ostream &out, const General &c) {
	out << "Club Name: " << c.name << endl;
	out << "Club Head: " << c.head << endl;
	out << "Professor in charge: " << c.pic << endl;
	out << "Founded Year: " << c.found_yr << endl;
	out << "Club Size: " << c.c_size << endl;
	out << "Club Expenses: " << c.expenses << endl;
	out << "Main Focus: " << c.main_focus << endl;
	c.print_members();
	c.print_projects();
for (const auto &ach : c.achievements) {
    	out << " - " << ach << endl;
	}
	return out;
}

istream &operator>>(istream &in, General &c) {
	in.ignore();
	cout << "Enter Club Name: ";
	getline(in,c.name);
	cout << "Enter Club Head: ";
	getline(in,c.head);
	cout << "Enter Professor in Charge: ";
	getline(in,c.pic);
	cout << "Enter Club Founding Year: ";
	in >> c.found_yr;
	cout << "Enter Club Size: ";
	in >> c.c_size;
	cout << "Enter Club Expenses: ";
	in >> c.expenses;
	c.modify_members();
	c.modify_projects();
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

General & General :: operator+=(const string &proj){
string creator;
cout << "Enter the creator of the project: ";
getline(cin, creator);
projects[proj] = creator;
cout<<"Succesfully added project."<<endl;
return *this;
}
General & General :: operator-=(const string &proj){
projects.erase(proj);
cout<<"Succesfully deleted project."<<endl;
return *this;
}

