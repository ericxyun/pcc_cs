#include <iostream>
#include <fstream>
using namespace std;

struct StudentNode
{
	string name;
	int age;
	string major;
	double gpa;
	StudentNode *link;
};

struct Node
{
	StudentNode info;
	Node *link;
};

void readFile(StudentNode *&head, 
		      StudentNode *&student);
void printStudents(StudentNode *&head);

StudentNode *searchStudent(string student_name,
				   		   StudentNode *&head);
void removeLastElem(StudentNode *&head);
double calculateGPA(StudentNode *&head);
