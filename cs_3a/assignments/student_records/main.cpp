#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

struct Student
{
	char *last_name = NULL;
	char *first_name = NULL;
	char course;
	int test1_score;
	int test2_score;
	int final_score;
	double test_average;
};
	
int main()
{
	ifstream infile;
	string line;
	int size;


	infile.open("input.txt");
//	getline(infile, line);
//	size = stoi(line);

	Student student[size];
	int count = 0;
	int idx = 0;
	double avg;

	char ch[0];
	while (infile.peek() != EOF)
	{

		while (ch != "\n")
		{
			infile.read(ch, 1);
			cout << ch << endl;
		}
	}
	// fill in array
//	while (infile.peek() != EOF)
//	{
//
//		getline(infile, line, '\n');
//		stringstream ss(line);
//		while (ss.good())
//		{
//			string x;
//			getline(ss, x ,',');
//			
//			if (count == 0)
//			{
//				student[idx].last_name = new char[x.size()];
//				for (int i = 0; i < x.size(); i++)
//					student[idx].last_name[i] = x[i];
//			}
//
//			else if (count == 1)
//			{
//				student[idx].first_name = new char[x.size()];
//				for (int i = 0; i < x.size(); i++)
//					student[idx].first_name[i] = x[i];
//			}
//
//			else if (count == 2)
//			{
//				student[idx].course = x[0];
//			}
//
//			else if (count == 3)
//			{
//				student[idx].test1_score = stoi(x);
//			}
//
//			else if (count == 4)
//			{
//				student[idx].test2_score = stoi(x);
//			}
//
//			else if (count == 5)
//			{
//				student[idx].final_score = stoi(x);
//				student[idx].test_average = (student[idx].test1_score * 0.3 + 
//						                     student[idx].test2_score * 0.3 +
//											 student[idx].final_score * 0.6) /
//					                         (0.3 + 0.3 + 0.6);
//			}
//			count++;
//		}
//		idx++;
//		count = 0;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		cout << student[i].last_name << endl;
//		cout << student[i].first_name << endl;
//		cout << student[i].course << endl;
//		cout << student[i].test1_score << endl;
//		cout << student[i].test2_score << endl;
//		cout << student[i].final_score << endl;
//		cout << student[i].test_average << endl;
//		cout << endl;
//	}

}
