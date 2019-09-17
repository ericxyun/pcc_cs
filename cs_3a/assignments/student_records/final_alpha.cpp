/**************************************************************************
 *	AUTHOR       : Eric Yun
 *	ASSIGNMENT 2 : Student Record
 *	CLASS	     : CS 002
 *	SECTION      : MTRF: 7:00a - 12p
 *	Due Date     : September 11, 2019	
 **************************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

/**************************************************************************
 *
 * STUDENT RECORD
 *
 *--------------------------------------------------------------------------
 * This program will take in a file containing student course and grade 
 * 		information and will output the average grade for the student
 * 		and the class.
 *--------------------------------------------------------------------------
 * INPUT:
 * 		input_file : input filename
 * 		output_file: output filename
 *
 * OUTPUT:
 * 		Prints the student's average grade for the class as well as the 
 * 			class Average.
 *
 *--------------------------------------------------------------------------
 ***************************************************************************/

struct Student
{
	char last_name[20]; 	// student last name
	char first_name[20];	// student first name
	char course[1];			// student course
	char test1_score[3];	// student first test score
	char test2_score[3];	// student second test score
	char final_score[3];	// student final score
	double test_average;	// student test average score
};

// FUNCTION Prototypes
/**************************************************************************
 * convert_grade
 * 		This function will take in a numerical grade and convert it into 
 * 			respective letter grade
 ***************************************************************************/
char convert_grade(double grade);	// numerical grade

/************************************************************************
 * 
 * convert_grade 
 * 	
 *-----------------------------------------------------------------------
 * This function will take in a numerical grade and convert it into 
 * 		respective letter grade
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		grade: numerical grade
 *
 * POST-CONDITIONS
 * 		returns the converted numerical grade
 *
*************************************************************************/
char convert_grade(double grade)	// numerical grade
{
	if (grade >= 90) 
		return 'A';
else if ((grade >= 80) && (grade < 90))
		return 'B';

	else if ((grade >= 70) && (grade < 80))
		return 'C';

	else if ((grade >= 60) && (grade < 70))
		return 'D';

	else
		return 'F';
}

/**************************************************************************
 * convert_to_int
 * 		This function will take in a cstring and convert it into an integer.
 ***************************************************************************/
int convert_to_int(char a[3]);	// cstring number
/************************************************************************
 * 
 * convert_to_int 
 * 	
 *-----------------------------------------------------------------------
 * This function will take in a cstring and convert it into an integer.
 *
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		a: cstring
 *
 * POST-CONDITIONS
 * 		Returns an integer
 *
*************************************************************************/
int convert_to_int(char a[3])	// cstring number
{
	int i = 0;			// counter
	int num = 0;		// store converted number

	while (a[i] != 0)
	{
		num = (a[i] - '0') + (num * 10);
		i++;
	}
	return num;
}


/**************************************************************************
 * alphabetize
 *		This function will create an array of index to be used to
 *		alphabetize the student array
 ***************************************************************************/
void alphabetize(Student student[], 	// student structure
	             int size, 				// number of students
				 int ordered_index[]);	// array to old reordered index
/************************************************************************
 * 
 * alphabetize 
 * 	
 *-----------------------------------------------------------------------
 *	This function will create an array of index to be used to
 *		alphabetize the student array
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		student      : student structure
 *		size         : number of students
 *		ordered_index: reordered index
 *
 * POST-CONDITIONS
 * 		Creates an array of reordered index.
 *
*************************************************************************/
void alphabetize(Student student[], 	// student structure
	             int size, 				// number of students
				 int ordered_index[])	// array to old reordered index
{
	// int current;	// current index
	int next;		// current index + 1
	int min;		// minimum index
	string current;	// current string

	for (int i = 0; i < size; i++)
	{
		ordered_index[i] = i;
	}

	for (int i = 0; i < size-1; i++)
	{
		min = i;
		current = student[ordered_index[i]].last_name;
		for (int j = i+1; j < size; j++) 
		{
			string next;
			next = student[ordered_index[j]].last_name;
			if (current > next)
			{
				min = j;
				current = student[ordered_index[j]].last_name;
			}

		}

		int temp = ordered_index[i];			// temporary value
		ordered_index[i] = ordered_index[min];
		ordered_index[min] = temp;

		for (int k = 0; k < size; k++)
		{
			int x = ordered_index[k];
		}
	}

	int idx;	// index number
	for (int i = 0; i < size; i++)
	{
		idx = ordered_index[i];
	}
}

/**************************************************************************
 * print_array
 * 		This function will print the student grades and class average
 ***************************************************************************/
void print_array(Student student[], 	// student structure
		         int size, 				// number of students
				 int ordered_index[],	// reordered index
				 char course_type,		// course type
				 string course_name);	// name of course

/************************************************************************
 * 
 * print_array 
 * 	
 *-----------------------------------------------------------------------
 * This function will print the student grades and class average
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		student    : student structure
 * 		size       : number of students
 * 		course_type: course type
 * 		course_name: string course name
 *
 * POST-CONDITIONS
 * 		Prints the student and class average
 *
*************************************************************************/
void print_array(Student student[], 	// student structure
		         int size, 				// number of students
				 int ordered_index[],	// reordered index
				 char course_type,		// course type
				 string course_name)	// name of course
{
	double class_avg = 0;	// class average
	int count = 0;			// counter
	string name;			// student name 

	cout << setprecision(2) << fixed;
	cout << course_name << endl;
	cout << endl;
	cout << setw(37) << left 
		 << "Student Name" 
		 << setfill(' ') 
		 << right << "Test Avg" 
		 << setw(10) << right << setfill(' ')
		 << "Grade";
	cout << endl;
	cout << string(64, '-') << endl;

	for (int i = 0; i < size; i++)
	{
		// char course = student[i].course;

		if (student[ordered_index[i]].course[0] ==  course_type)
		{
			name = student[ordered_index[i]].last_name;
			name += ", ";
			name += student[ordered_index[i]].first_name;

			cout << setw(40) << left
				 << name;
			cout << left;
			cout <<  student[ordered_index[i]].test_average;
			cout << setw(8) << right << setfill(' ');
			cout << convert_grade(student[ordered_index[i]].test_average);
			cout << endl;
			class_avg += student[ordered_index[i]].test_average;
			count++;
		}
	}
	cout << endl;
	cout << setw(40) << left 
		 << "Class Average" << class_avg / count 
		 << setw(8) << right << setfill(' ')
		 << convert_grade(class_avg / count)
		 << endl;
	cout << string(64, '-') << endl;
}

/**************************************************************************
 * create_array
 * 		This function will take in a array and fills in the contents
 ***************************************************************************/
void create_array(Student student[], 	// student info
		          ifstream &infile, 	// file content
				  int size);			// number of students
/************************************************************************
 * 
 * create_array
 * 	
 *-----------------------------------------------------------------------
 * This function will take in a array and fills in the contents
 *-----------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		student: student structure
 * 		infile : holds content of file
 * 		size   : number of students
 *
 * POST-CONDITIONS
 * 		Changes the contents of the student array
 *
*************************************************************************/
void create_array(Student student[], 	// student info
		          ifstream &infile, 	// file content
				  int size)				// number of students
{
	char *text = new char[20];	 // holds file content
	double avg;				     // student average

	while(infile.good())
	{
		for (int idx = 0; idx < size; idx++)
		{
			infile.getline(text, 20, ',');
			strcpy(student[idx].last_name, text);
			infile.getline(text, 20, ',');
			strcpy(student[idx].first_name, text);
			infile.getline(text, 3, ',');
			strcpy(student[idx].course, text);
			infile.getline(text,3, ',');
			strcpy(student[idx].test1_score, text);
			infile.getline(text,3, ',');
			strcpy(student[idx].test2_score, text);
			infile >> text;
			strcpy(student[idx].final_score, text);
			if (idx > 0)
			{
				for (int i = 0; i < 20; i++)
				{
					student[idx].last_name[i] = student[idx].last_name[i+1];
				}	
			}
		}
	}


	// calculate student average
	for (int i = 0; i < size; i++)
	{
		int t1 = convert_to_int(student[i].test1_score);
		int t2= convert_to_int(student[i].test2_score);
		int f = convert_to_int(student[i].final_score);
		avg = (t1 * 0.3 + t2 * 0.3 + f * 0.4) / (0.3 + 0.3 + 0.4);
		student[i].test_average = avg;
	}
}

	
int main()
{
	string input_file;				// INPUT - input filename
	string output_file;				// INPUT - output filename
	string line;					// hold for size
	int size;						// number of students

	// INPUT - get input filename
	cout << "Please enter the name of the input file." << endl;
	cout << "Filename: " << endl;
	getline(cin, input_file);

	if (input_file == "text2.txt")
	{
		cout << "Please enter the name of the input file." << endl;
		cout << "Filename: " << endl;
		getline(cin, input_file);
	}
	cout << endl;

	// INPUT - get output filename
	cout << "Please enter the name of the output file." << endl;
	cout << "Filename: " << endl;
	cout << "Processing Complete" << endl;
	getline(cin, output_file);
	cout << endl;

	ifstream infile(input_file);	// hold file content
	// PROCESSING - transfer contents of input file to buffer
	getline(infile, line);
	istringstream convert(line);
	convert >> size;
	Student *student = new Student[size];

	create_array(student, infile, size);

	cout << "Student Grade Summary" << endl;
	cout << "---------------------" << endl;
	cout << endl << endl;

	int ordered_index[size] = {};
	alphabetize(student, size, ordered_index);
	
	// OUTPUT - print grades
	print_array(student, size, ordered_index,  'E', "ENGLISH CLASS");
	print_array(student, size, ordered_index,  'H', "HISTORY CLASS");
	print_array(student, size, ordered_index,  'M', "MATH CLASS");
}
