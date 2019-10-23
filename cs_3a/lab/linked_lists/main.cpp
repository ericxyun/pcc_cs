#include <iostream>
#include "header.h"
// #include "functions.cpp"
using namespace std;

int main()
{
	StudentNode *head, *student;
	readFile(head, student);
	searchStudent("Paul Johnson", head);
	printStudents(head);
 	removeLastElem(head);
	calculateGPA(head);

}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
