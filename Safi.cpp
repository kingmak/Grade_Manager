//Safi Bahi Always add small comments, so someone else can also understand ur code :P it took me some time hehehe

#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<array>
#include<cmath>

using namespace std;

void admin();
void teacher();
void student();

int main() {

	int y = 0;

	cout << "Press 1 for Admininstrator, 2 for Teacher or 3 for Student: " << endl;
	cin >> y;
	
	if (y == 1)
	{
	        admin();
	}		
	else if (y == 2)
	{
	        teacher();
	}	
	else if (y == 3)
	{
		student();
	}
	else
		cout << "Sorry: Invalid Input";
}

void admin() {
	
	string name, code, passcode, full;
	
	cout << "Enter your name: ";
	cin >> name;
	
	cout << "Enter the code: ";
	cin >> code;

	passcode = name + " " + code;

	class marks
	{
		float q1, q2, q3, q4, oht1, oht2, oht3, final, gpa;
	};

	class Studentrecord
	{
		public:
		string name, fname, lname, rollno, regno, password;
	
		typedef marks subjects[8];
	}
	
	typedef strec[3];

	ifstream A;
	A.open("admin.txt");

	getline(A, full);

	if (passcode == full)
	{
		cout << "Welcome!!" << endl;

		cout << "Make enteries of the students: \n";
		strec std;

		ofstream B;
		B.open("data.txt");

		for(int i = 0; i < 3; i++)
		{
			cout << "Enter first name: ";
			cin >> std[i].fname;

			cout << "Enter last name: ";
			cin >> std[i].lname;
		
			cout << "Enter registration number: ";
			cin >> std[i].regno;

			cout << "Enter password: ";
			cin >> std[i].password;

			B << std[i].fname << " " << std[i].lname << " " <<std[i].regno << " " <<std[i].password<<endl;
		}
	}
	else
		cout << "Invalid entry!!!";
}

void teacher() {

	string name, code, passcode, full;
	cout << "Enter your name: ";
	cin >> name;
	
	cout << "Enter the code: ";
	cin >> code;

	passcode = name + " " + code;

	ifstream C;
	C.open("t.txt");

	getline(C, full);

	if (passcode == full)
	{
		cout << "Welcome!!" << endl;
	}
}

void student() {

	cout << "Hello!! ";
}


