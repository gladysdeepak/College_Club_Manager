#include"newclub.h"
#include<string>
#include<vector>
#include<iostream>
#include<map>
Cult::Cult(string name,string pic,string head,int c_size,int found_yr, int expenses,string culture_type):Club(name,pic,head,c_size,found_yr,expenses),culture_type(culture_type)
{
   cout<<"Cultural club "<<name<<" is created successfully"<<endl;
}

ostream &operator<<(ostream &out, const Cult &clt)
{
	out<<"Club Name : "<<clt.name<<endl;
	out<<"Club Head : "<<clt.head<<endl;
	out<<"Professor Incharge : "<<clt.pic<<endl;
	out<<"Founded Year : "<<clt.found_yr<<endl;
	out<<"Club Size : "<<clt.c_size<<endl;
	out<<"Club expenses : "<<clt.expenses<<endl;
	out<<"Type of cultural activity: "<<clt.culture_type<<endl;
	out<<"Achievements:\n";
	for(auto it=clt.achievements.begin();it!=clt.achievements.end();it++)
	{
	out<<*it<<endl;
	}
	out<<"Coordinators:\n";
	for(auto it=clt.coordinators.begin();it!=clt.coordinators.end();it++)
	{
	out<<*it<<endl;
	}
	return out;
}

istream &operator>>(istream &in, Cult &clt)
{
    	in.ignore();
	cout << "Enter Club Name: ";
	getline(in,clt.name);
	cout << "Enter Club Head: ";
	getline(in,clt.head);
	cout << "Enter Professor in Charge: ";
	getline(in,clt.pic);
	cout<<"Enter Founded Year : "<<endl;
	in>>clt.found_yr;
	in.ignore();
	cout<<"Enter Club Size : "<<endl;
	in>>clt.c_size;
	in.ignore();
	cout<<"Enter Club expenses : "<<endl;
	in>>clt.expenses;
	in.ignore();
	cout<<"Enter the type of cultural activity: "<<endl;
	getline(in,clt.culture_type);
	int a;
	cout << "Enter 1 to add achievements, 0 to stop: ";
	in >> a;
	in.ignore();
	while (a == 1) {
    	string achievement;
    	cout << "Enter achievement: ";
    	getline(in, achievement);
    	clt.add_achievements(achievement);

    	cout << "Enter 1 to add more achievements, 0 to stop: ";
    	in >> a;
    	in.ignore();
	}
	return in;
}

void Cult::modify_coords()
{

	bool b=true;
	while(b)
	{
    	cout<<"1. add coordinators"<<endl;
    	cout<<"2. remove coordinators"<<endl;
    	cout<<"3. exit"<<endl;
    	cout<<"enter your choice: ";
    	int choice;
    	cin>>choice;
    	cin.ignore();
    	switch(choice)
    	{
    	case 1:
        	{
            	string name;
            	cout<<"enter the name of the coordinator to be added: ";
            	getline(cin,name);
            	coordinators.insert(name);
            	cout<<"Updated...";
            	this->print_coords();
            	this->c_size++;
            	break;
        	}
    	case 2:
        	{
            	string name;
            	this->print_coords();
            	cout<<"enter the name to be removed: ";
            	getline(cin,name);
            	coordinators.erase(name);
            	cout<<"updated ";
            	this->print_coords();
            	this->c_size--;
            	break;
        	}
    	case 3:
        	{
            	b=false;
            	break;
        	}
    	default:
        	{
            	cout<<"Invalid choice!!!"<<endl;
            	b=false;
            	break;
        	}
    	}
	}

}
void Cult::print_coords()
{
	cout<<endl;
	cout<<"list of coordinators: "<<endl;
	for(auto &n: coordinators)
    	cout<<n<<" ";
	cout<<endl;
}



