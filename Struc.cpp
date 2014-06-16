#include <iostream>
#include <string>
 
using namespace std;
void PrintName(struct Name Person);

struct Name {
	
   string FirstName;
   string LastName;
};
 
int main() {
	
    struct Name Person;
	
    Person.FirstName = "Safiullah";
    Person.LastName = "Imtiaz";
	
    PrintName(Person);	
}
void PrintName(struct Name Person) {
	
   cout << "First Name: " << Person.FirstName << endl;
   cout << "Last Name: " << Person.LastName << endl;
}
