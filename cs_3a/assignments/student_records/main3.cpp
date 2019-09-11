#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student
{
//	char *last_name = NULL;
//	char *first_name = NULL;
	char last_name[20] = {}; 	// why is {} needed?
	char first_name[20] = {};
	char course;
	char test1_score[3] = {};
	char test2_score[3] = {};
	char final_score[3] = {};
	double test_average;
};

char convert_grade(double grade)
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

int convert_to_int(char a[3])
{
	int i = 0;
	int num = 0;
	while (a[i] != 0)
	{
		num = (a[i] - '0') + (num * 10);
		i++;
	}
	return num;
}


void alphabetize(Student student[], 
	             int size, 
				 int ordered_index[])
{
	int current;
	int next;
	int min;

	for (int i = 0; i < size; i++)
	{
		ordered_index[i] = i;
	}

	for (int i = 0; i < size-1; i++)
	{
		min = i;
		// current = student[ordered_index[i]].last_name[0];
		string current;
		current = student[ordered_index[i]].last_name;
		for (int j = i+1; j < size; j++) 
		{
			// next = student[ordered_index[j]].last_name[0];
			string next;
			next = student[ordered_index[j]].last_name;
			if (current > next)
			{
				min = j;
				// current = student[ordered_index[j]].last_name[0];
				current = student[ordered_index[j]].last_name;
			}

		}

		int temp = ordered_index[i];
		ordered_index[i] = ordered_index[min];
		ordered_index[min] = temp;

		for (int k = 0; k < size; k++)
		{
			int x = ordered_index[k];
		}
	}

	int idx;
	for (int i = 0; i < size; i++)
	{
		idx = ordered_index[i];
		cout << student[idx].last_name << endl;
	}
}

void print_array(Student student[], 
		         int size, 
				 char course_type,
				 string course_name)
{
	double class_avg = 0;
	int count = 0;
	string name;
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
		char course = student[i].course;

		if (course == course_type)
		{
			name = student[i].last_name;
			name += ", ";
			name += student[i].first_name;

			cout << setw(40) << left
				 << name;
			cout << left;
			cout <<  student[i].test_average;
			cout << setw(8) << right << setfill(' ');
			cout << convert_grade(student[i].test_average);
			cout << endl;
			class_avg += student[i].test_average;
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

void create_array(Student student[], char buffer[], int size)
{
	int j = 0;				// start after first line
	int count = 0;			// word in between ","
	int first = 0;

	for (int idx = 0; idx < size; idx++)
	{
		int word_idx = 0;
		while (buffer[j] != '\n')
		{
			if (buffer[j] != ',')
			{
				if (count == 0)
				{
					student[idx].last_name[word_idx] = buffer[j];
					word_idx++;
				}

				else if (count == 1)
				{
					student[idx].first_name[word_idx] = buffer[j];
					word_idx++;
				}

				else if (count == 2)
				{
					student[idx].course = buffer[j];
				}

				else if (count == 3)
				{
					student[idx].test1_score[word_idx] = buffer[j];
					word_idx++;
				}

				else if (count == 4)
				{
					student[idx].test2_score[word_idx] = buffer[j];
					word_idx++;
				}

				else if (count == 5)
				{
					student[idx].final_score[word_idx] = buffer[j];
					word_idx++;
				}
			}
			else
			{
				count++;
				word_idx = 0;
			}
			j++;

			if (buffer[j] == ',')
			{
				if (count == 0)
				{
					student[idx].last_name[word_idx + 1] = '\0';
				}

				else if (count == 1)
				{
					student[idx].first_name[word_idx + 1] = '\0';
				}

			}
		}
		count = 0;
		j++;
	}

	// calculate student average
	double avg;
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
	string input_file;
	string output_file;


	cout << "Please enter the name of the input file." << endl;
	cout << "Filename: " << endl;
	cin >> input_file;
	cout << endl;

	cout << "Please enter the name of the output file." << endl;
	cout << "Filename: " << endl;
	cout << "Processing Complete" << endl;
	cin >> output_file;
	cout << endl;
	
	// PROCESSING - transfer contents of input file to buffer
	string line;
	ifstream infile(input_file);
	int size;
	getline(infile, line);
	istringstream convert(line);
	convert >> size;
	char x;
	while (!infile.eof())
	{
		infile.get(x);
		cout << x;
	}
		
	// infile.seekg(infile.beg, infile.end);
	// int length = infile.tellg();
	// infile.seekg(infile.end, infile.beg);

	// char *buffer = new char[length];	 
	// infile.read(buffer, length);
	// infile.close();
	// 
	Student *student = new Student[size];

	create_array(student, buffer, size);

	// cout << "Student Grade Summary" << endl;
	// cout << "---------------------" << endl;
	// cout << endl << endl;
	// print_array(student, size, 'E', "ENGLISH CLASS");
	// print_array(student, size, 'H', "HISTORY CLASS");
	// print_array(student, size, 'M', "MATH CLASS");
	
	// int ordered_index[size] = {};
	// alphabetize(student, size, ordered_index);


}
