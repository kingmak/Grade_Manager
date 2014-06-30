#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

//rem funcs for student + teacher (2 more funcs) n Gpa Calc?

using namespace std;

//Management and Auth Funcs
void MasterAdmin();
void AdminAccess();
void AdminManager();
void TeacherAccess();
void TeacherManager();
void StudentManager();

//Modifications
void GradeManager();
void ViewTeachers();
void AddTeachers();
void AddStudent();
void ViewStudent(bool ask, string Reg);

int main(){
	system("title Grade Manger 0.1 by KingMak");
	system("color 1a");
	
	int Access;
	
	cout << "\tGrade Manager 0.1\n\n";
	cout << "Please Choose From The Given Choices\n\n";
	cout << "1 - Administrator\n2 - Teacher\n3 - Student\n\nType Here: ";// option zero will be reserved for Master Admin, option will not be displayed for security
	
	cin >> Access;
	
	if (! cin.fail()){
		if (Access == 0){
			MasterAdmin();
		}	
		else if (Access == 1){
			AdminAccess();
		}
		else if (Access == 2){
			TeacherAccess();
		}
		else if (Access == 3){
			StudentManager();
		}
		else{
			cout << "Error: Invalid Selection";	
		}
	}
	else{
		cout << "Error: Invalid Selection";	
	}	
}

void MasterAdmin(){
	system("cls");
	system("color 0a");
	
	string User, Pass, Token;
	
	cout << "\t\tWelcome Master Admin KingMak\n\n";
	
	cout << "UserName: ";
	cin >> User;
	
	cout << "PassCode: ";
	cin >> Pass;
	
	cout << "Access Token: "; 
	cin >> Token;
}

void AdminAccess(){
	system("cls");
	
	string User, Pass, Check, Line;
	bool Switch = false;
	
	cout << "\t\tAdministrator Manager\n\nPlease Provide your UserName and PassCode to Gain Access\n\n";
		
	cout << "UserName: ";
	cin >> User;
		
	cout << "PassCode: ";
	cin >> Pass;
	
	Check = User + ", " + Pass;

	ifstream AdminFile("Central/Access/Admin.txt");
  	while (! AdminFile.eof()){
      	getline (AdminFile, Line);
      	if (Line == Check){
      		Switch = true;
      		break;
      	}
    }
    AdminFile.close();
	if (Switch == false){
    	cout << "Error: Invalid Credentials";
    }
	else{
		AdminManager();
	}
}

void AdminManager(){
	system("cls");
	
	int Role, RoleOps;
	
	cout << "Access Granted\n\n";
	cout << "Please Choose From The Given Choices\n\n";
	cout << "1 - Teacher Manager\n2 - Student Manager\n\nType Here: ";
	cin >> Role;
	
	if (Role == 1){
		system("cls");
		
		while (true){
			cout << "\tTeacher Manager\n\n";
			cout << "Please Choose From The Given Choices\n\n";
			cout << "1 - Add Teacher\n2 - View Teacher\n3 - Remove Teacher\n";
			cout << "4 - Switch to Student Manager\n5 - Quit\n\n";
			cout << "Type Here: ";
			cin >> RoleOps;
		
			if (RoleOps == 1){
				AddTeachers();
				system("cls");
			}
			else if (RoleOps == 2){
				ViewTeachers();
				system("cls");
			}
			else if (RoleOps == 3){
				cout << "Call Remove Teacher Func";
			}
			else if (RoleOps == 4){
				TeacherManager();
				system("cls");
			}
			else if (RoleOps == 5){
				exit(1);
			}
			else {
				cout << "\nError: Ivalid Selection\n";
				system("pause");
				system("cls");
			}
		}	
	}
	else if (Role == 2){
		system("cls");
		
		while (true){
			cout << "\tStudent Manager\n\n";
			cout << "Please Choose From The Given Choices\n\n";
			cout << "1 - Add Student\n2 - View Student\n3 - Remove Student\n";
			cout << "4 - Switch to Teacher Manager\n5 - Quit\n\n";
			cout << "Type Here: ";
			cin >> RoleOps;
		
			if (RoleOps == 1){
				AddStudent();
			}
			else if (RoleOps == 2){
				StudentManager();
			}
			else if (RoleOps == 3){
				cout << "Call Remove Student Func";
			}
			else if (RoleOps == 4){
				TeacherAccess();
			}
			else if (RoleOps == 5){
				exit(1);
			}
			else{
				cout << "\nError: Ivalid Selection\n";
				system("pause");
				system("cls");
			}
		}			
	}
	else{
		cout << "Error: Ivalid Selection";
	}
}

void TeacherAccess(){
	system("cls");
	
	string User, Pass, Check, Line;
	bool Switch = false;
	
	cout << "\t\tTeacher Manager\n\nPlease Provide your UserName and PassCode to Gain Access\n\n";
			
	cout << "UserName: ";
	cin >> User;
		
	cout << "PassCode: ";
	cin >> Pass;
	
	Check = User + ", " + Pass;

	ifstream TeacherFile("Central/Access/Teacher.txt");
  	while (! TeacherFile.eof()){
      	getline (TeacherFile, Line);
      	if (Line == Check){
      		Switch = true;
      		break;
      	}
    }
    TeacherFile.close();
    
	if (Switch == false){
    	cout << "Error: Invalid Credentials";
    }
	else{
		TeacherManager();
	}
}

void TeacherManager(){
	system("cls");
	
	int RoleOps; string RegNum;
	
	while(true){
		cout << "\tStudent Manager\n\n";
    	cout << "Please Choose From The Given Choices\n\n";
    	cout << "1 - Add Student\n2 - View Student\n3 - Remove Student\n";
    	cout << "4 - Add Grades\n5 - Quit\n\n";
    	cout << "Type Here: ";
    	cin >> RoleOps;

    	if (RoleOps == 1){
    		AddStudent();
    	}
    	else if (RoleOps == 2){
    		StudentManager();
    	}
    	else if (RoleOps == 3){
			cout << "Call Remove Student Func";
    	}
    	else if (RoleOps == 4){
			GradeManager();
    	}
    	else if (RoleOps == 5){
    		exit(1);
    	}
    	else{
			cout << "\nError: Ivalid Selection\n";
			system("pause");
			system("cls");
    	}
	}		
}

void AddTeachers(){
	system("cls");
	
	string User, Pass, Length;
	int Count;
	
	cout << "How Many Teachers to Add: ";
	cin >> Count;
	cout << "\n";
	
	for (int i = 0; i < Count; i++){
		cout << "Teacher's UserName: ";
		cin >> User;
		
		cout << "Teacher's PassWord: ";
		cin >> Pass;
		
		Length = User + Pass;
		
		// acutally checking if input for how many teachers was right, dont want to add bad users: " , "
		if (Length.length() < 3){
			cout << "User and Password Length is too Short\n";
			system("pause");
			exit(1);
		}
		
		ofstream TeacherFile;
		TeacherFile.open("Central/Access/Teacher.txt", ios_base::app);
    	TeacherFile << User << ", " << Pass << "\n";
    	TeacherFile.close();
    	
    	cout << "\nTeacher with user '" << User << "' added with Success\n\n";	
	}	
	cout << "Press Enter to Exit";
	cin.get(); cin.ignore();
}

void ViewTeachers(){
	string Line;
	
	ifstream TeacherFile("Central/Access/Teacher.txt");
	
	system("cls");
	cout << "Teachers Info:\n\n";
	
  	while (! TeacherFile.eof()){
      	getline (TeacherFile, Line);
      	cout << ">> " << Line << endl;
    }
    TeacherFile.close();
	cout << "\nPress Enter to Exit";	
    cin.get(); cin.ignore();	
}

void GradeManager(){
	system("cls");
	
	int Count, StdntNum;
	bool Match;
	string FilePath, Line, RegNum;
	string Fname, q1, q2, q3, q4, oht1, oht2, oht3, final, grade;
	
	cout << "Number of Student's whose Grades are being added: ";
	cin >> Count;
	
	for (int i = 0; i < Count; i++){
		
		StdntNum = i + 1;
		cout << "\nStudent " << StdntNum << "'s Registration Number: ";
		cin >> RegNum;
		
		ifstream StudentFile("Central/Access/Student.txt");
  		while (! StudentFile.eof()){
      		getline (StudentFile, Line);
      		if (Line == RegNum){
      			Match = true;
      			break;
      		}
    	}
    	StudentFile.close();
    
		if (Match == false){
    		cout << "Error: Invalid Registration Number\nPlease Add this Student First";
    		cin.get();cin.ignore();
    		system("cls");
    		GradeManager();
    	}
    	else{
    		cout << "Full Name of Student " << StdntNum << ": ";
    		cin.ignore();
			getline(cin, Fname);
    		
    		cout << "\n";
    		cout << "Enter Grades of Student '" << Fname << "' Below:\n";
    		cout << "- Quiz 1: "; cin >> q1;
    	 	cout << "- Quiz 2: "; cin >> q2;
    		cout << "- Quiz 3: "; cin >> q3;
    		cout << "- Quiz 4: "; cin >> q4;
    		cout << "- Oht 1: "; cin >> oht1;
    		cout << "- Oht 2: "; cin >> oht2;
    		cout << "- Oht 3: "; cin >> oht3;
    		cout << "- Final: "; cin >> final;
    		cout << "- Grade: "; cin >> grade;
    		
    		FilePath = "Central/Data/" + RegNum + ".txt";
    		
			ofstream RecordFile;
    		RecordFile.open(FilePath, ios_base::app);
    		
    		RecordFile << "Registration Number: " << RegNum << "\n"
					   << "Full Name: " << Fname << "\n"
					   << "Quiz1: " << q1 << "\n"
					   << "Quiz2: " << q2 << "\n"
					   << "Quiz3: " << q3 << "\n"
					   << "Quiz4: " << q4 << "\n"
					   << "Oht1: " << oht1 << "\n"
					   << "Oht2: " << oht2 << "\n"
					   << "Oht3: " << oht3 << "\n"
					   << "Final: " << final << "\n"
					   << "Grade: " << grade << "\n";
			RecordFile.close();
			
			cout << "\n> Grades For Student '" << Fname << "' Have been saved\n";
    	}		
	}
	cout << "\nIn Total Grades Have Been Added For " << StdntNum << " Students\n";
	cout << "Press Enter to Exit";
	cin.get();cin.ignore();
	system("cls");	
}

void StudentManager(){
	system("cls");
	
	string Line, RegNum, FilePath;
	bool Switch = false;
	
	cout << "\t\tStudent Manager\n\nPlease Provide Registration Number\n\nHere: ";
	cin >> RegNum;
	
	ifstream StudentFile("Central/Access/Student.txt");
  	while (! StudentFile.eof()){
      	getline (StudentFile, Line);
      	if (Line == RegNum){
      		Switch = true;
      		break;
      	}
    }
    StudentFile.close();
    
	if (Switch == false){
    	cout << "Error: Invalid Registration Number";
    	cin.get();cin.ignore();
    	system("cls");
    }
    else{
    	ViewStudent(false, RegNum);
    }
}

void AddStudent(){
	system("cls");
	
	string FilePathOne, FilePathTwo, RegNum;
	int Choice, Count;
	
	cout << "How Many Students to Add: ";
	cin >> Count;
	
	for (int i = 0; i < Count; i++){
		cout << "\nStudent Registration Number: ";
		cin >> RegNum;
	
		FilePathOne = "Central/Data/" + RegNum + ".txt";
		FilePathTwo = "Central/Access/Student.txt";
	
    	ofstream GradeFile;
    	GradeFile.open(FilePathOne);
    	GradeFile.close(); 
    
    	ofstream RecordFile;
    	RecordFile.open(FilePathTwo, ios_base::app);
    	RecordFile << RegNum << "\n";
    	RecordFile.close();
    
    	cout << "Student with Registration Number '" << RegNum << "' Added with Success\n";
	}
	cout << "\nPress Enter to Exit";
	cin.get();cin.ignore();
	system("cls");
}

void ViewStudent(bool ask, string Reg){
	system("cls");
	
	string FilePath, Line, RegNum;
	
	if (ask == true){
		cout << "Enter Registration Number: ";
		cin >> RegNum;
	}
	else{
		RegNum = Reg;
	}
	
	FilePath = "Central/Data/" + RegNum + ".txt";
	
    ifstream GradeFile(FilePath);
    cout << "\nGrades Are Listed Below:\n\n";
    
    while (!GradeFile.eof()){
    	getline (GradeFile, Line);
    	cout << ">> " << Line << endl;
    }
	cout << "\nPress Enter to Exit";	
    cin.get(); cin.ignore();
    system("cls");
}
