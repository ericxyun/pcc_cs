#include "header.h" // need for g++
// NOTES to pass a pointer by reference, you'll need to 
// 		 add a "&" before the variable name, otherwise
// 		 it'll be passed by value
void readFile(StudentNode *&head, 
		      StudentNode *&student)
{
	string line;
	ifstream infile;
	infile.open("inFile.txt");
	head = new StudentNode;
	head->link = NULL;

	while (infile.good())
	{
		string blank;
		student = new StudentNode;
		getline(infile, student->name);
		infile >> student->age;
		infile.ignore(100, '\n');
		getline(infile, student->major);
		infile >> student->gpa;
		infile.ignore();
		getline(infile, blank);
		student->link = head;
		head = student;
	}
	// return head;
}

StudentNode *searchStudent(string student_name,
				   		   StudentNode *&head) 
{
	StudentNode *current = new StudentNode;
	current = head; 

	while (current->name != student_name)
	{
		current = current->link;
	}
	return current; 
}

void printStudents(StudentNode *&head)
{
	StudentNode *current = new StudentNode;
	current = head;
	cout << "Name\tAge\tMajor\tGPA";
	while (current->link != NULL)
	{
		cout << current->name << endl;	
		cout << current->age << endl;	
		cout << current->major << endl;	
		cout << current->gpa << endl;	
		cout << endl;
		current = current->link;
	}
}

void removeLastElem(StudentNode *&head)
{
	StudentNode *current = new StudentNode;
	current = head;
	cout << current->name << endl;	
	cout << current->age << endl;	
	cout << current->major << endl;	
	cout << current->gpa << endl;	
	cout << endl;
	head = head->link;
	delete current;

	cout << head->name << endl;	
	cout << head->age << endl;	
	cout << head->major << endl;	
	cout << head->gpa << endl;	
	cout << endl;
}

double calculateGPA(StudentNode *&head)
{
	double sum = 0;
	int count = 0;
	double avg;

	StudentNode *current = new StudentNode;
	current = head;

	while (current->link != NULL)
	{
		sum += current->gpa;
		current = current->link;
		count++;
	}

	avg = sum / count;

	return avg;
}
