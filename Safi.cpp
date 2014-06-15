/*
Safi Bahi Always add small comments, so someone else can also understand ur code :P it took me some time hehehe
also just use "" when u want to add a space in a file or on screen, just a bit easier to use one set of quotes
instead of '' and ""

also if u want to add a pause in ur code u can use:
1) cin.ignore();cin.get()
2) System("pause"); <-- this works sometimes

One more thing, i added a few more things:
1) made the cout statments print the messages nicely
2) added a few more cout statements so the Normal user can understand what is happening	
*/

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

	cout << "Choose from the following choices:\n\n1 for Admininstrator\n2 for Teacher\n3 for Student\n\nTypeHere: ";//just being a bit fancy :)
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
		cout << "Error: Invalid Input";
}

void admin() {
	
	string name, code, passcode, full;
	
	cout << endl << "Enter your name: ";
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
		cout << endl << "Welcome!!\n" << endl;

		cout << "Make enteries of the students: " << endl;
		strec std;

		ofstream B;
		B.open("data.txt");
		
		for(int i = 0; i < 3; i++)
		{
			cout << endl << "Student " << (i + 1) << endl;
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
		
		cout << endl << "All student records were successfully saved";
	}
	else
		cout << "Error: Invalid Entry";
}

void teacher() {

	string name, code, passcode, full;
	cout << endl << "Enter your name: ";
	cin >> name;
	
	cout << "Enter the code: ";
	cin >> code;

	passcode = name + " " + code;

	ifstream C;
	C.open("t.txt");

	getline(C, full);

	if (passcode == full)
	{
		cout << endl << "Welcome Teacher!!" << endl;
	}
}

void student() {

	cout << endl << "Hello Student!!";
}
