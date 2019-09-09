#include <iostream>
#include <cstring>
#include <fstream>
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
		cout << student[i].last_name << endl;
	}
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		min = i;
		current = student[i].last_name[0];
		if (i + 1 < size)
		{
			for (int j = i+1; j < size; j++) 
			{
				next = student[j].last_name[0];
				if (current > next)
				{
					min = j;
				}
			}
		}
		int temp = ordered_index[i];
		ordered_index[i] = ordered_index[min];
		ordered_index[min] = temp;
	}

	int idx;
	for (int i = 0; i < size; i++)
	{
		
		idx = ordered_index[i];
		cout << idx << endl;
		cout << student[idx].last_name << endl;
	}
}

void print_array(Student student[], int size)
{
	double class_avg = 0;
	int count = 0;
	
	for (int i = 0; i < size; i++)
	{
		char course = student[i].course;

		if (course == 'M')
		{
			cout << student[i].last_name << ", " << student[i].first_name;
			cout << "\t" << student[i].test_average << " ";
			cout << convert_grade(student[i].test_average) << endl;
			class_avg += student[i].test_average;
			count++;
		}
	}
	cout << "Class Average: " << class_avg / count << endl;
}

void create_array(Student student[], char buffer[], int size)
{
	int j = 2;				// start after first line
	int count = 0;			// word in between ","

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
	for (int i = 0; i < 8; i++)
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
	ifstream infile ("input.txt");	// input text
	int size;						// number of students

	// PROCESSING - transfer contents of input file to buffer
	infile.seekg(0, infile.end);
	int length = infile.tellg();
	infile.seekg(0, infile.beg);

	char *buffer = new char[length];	 
	infile.read(buffer, length);
	infile.close();
	
	size = buffer[0] - '0';	
	Student student[size];

	create_array(student, buffer, size);
	// print_array(student, size);
	
	int ordered_index[size] = {};
	alphabetize(student, size, ordered_index);


}
