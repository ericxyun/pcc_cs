#include <iostream>
#include <vector>

using namespace std;


void printSizeCap(vector<int>&v);
void printVectorContents(vector<int> &v);
void testVector(vector<int> &v, string v_str);
void testPushBack(vector<int> &v);
void testPushBackPrint(vector<int> &v);
void testPopBack(vector<int> &v);
void testFrontBack(vector<int>&v);
void testInsert(vector<int> &v, int value, int position);
void testErase(vector<int> &v, int position);
void testResize(vector<int> &v, string v_str, int size);
void testAssign(vector<int> &v, int value, int position);
void testClear(vector<int> &v);

int main()
{
	vector<int> v1;
	vector<int> v2(5);
	vector<int> v3(5, 9);

	testVector(v1, "v1");
	cout << endl;
	testVector(v2, "v2");
	v2.clear();
	cout << endl;
	cout << endl;
	testVector(v3, "v3");
	v3.clear();
	cout << endl;
	cout << endl;


	cout << "Testing push back function" << endl;
	testPushBackPrint(v1);
	testPushBack(v2);
	testPushBack(v3);

	cout <<  endl;

	cout << "Testing pop back function" << endl;
	testPopBack(v1);
	cout << endl;

	cout << "Testing front and back functions" << endl;
	testFrontBack(v1);
	cout << endl;

	cout << "Testing insert() function by adding at position "
		 << 5 << endl;
	testInsert(v1, 100, 5);
	for (int i = 0; i < v1.size(); i++)
		cout << v1.at(i) << " ";
	cout << endl;
	testInsert(v2, 100, 5);
	testInsert(v3, 100, 5);
	cout << endl;

	cout << "Testing erase() function by erasing position "
		 << 6 << endl;
	testErase(v1, 6);
	printVectorContents(v1);
	testErase(v2, 6);
	testErase(v3, 6);
	cout << endl;

	testResize(v2, "v2", 10);
	cout << endl;
	
	testResize(v3, "v3", 10);
	cout << endl;

	testAssign(v2, 102, 5);
	cout << endl;
	
	testClear(v2);
	cout << endl;
}

void printSizeCap(vector<int>&v)
{
	cout << "size: "     << v.size() << " "
		 << "capacity: " << v.capacity() << endl;
}

void printVectorContents(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";
	cout << endl;
}

void testVector(vector<int> &v, string v_str)
{
	string v_name = v_str;
	if (v_name == "v1")
		cout << "Testing default constructor" << endl;
	else if (v_name == "v2")
		cout << "Testing One parameter constructor" << endl;
	else if (v_name == "v3")
		cout << "Testing Two parameter constructor" << endl;

	printSizeCap(v);

	cout << "Testing empty member function" << endl;
	if (v.empty())
		cout << "v is empty" << endl;
	else 
		cout << "v is not empty" << endl;
	if (v_name != "v1")
	{
		cout << "Testing at function by displaying "
			 << v_str << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v.at(i) << " ";
	}
}

void testPushBackPrint(vector<int> &v)
{
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		printSizeCap(v);
	}

}

void testPushBack(vector<int> &v)
{
	for (int i = 0; i < 8; i++)
	{
		v.push_back(i);
	}

}

void testPopBack(vector<int> &v)
{
	v.pop_back();
	printSizeCap(v);
	v.pop_back();
	printSizeCap(v);
}

void testFrontBack(vector<int>&v)
{
	cout << "front: " << v.front() 
		 << " "
		 << "back: " << v.back() 
		 << endl;
}

void testInsert(vector<int> &v, int value, int position)
{
	v.insert(v.begin() + position, value);
}

void testErase(vector<int> &v, int position)
{
	v.erase(v.begin() + position);
	
}

void testResize(vector<int> &v, string v_str, int size)
{
	string v_name = v_str;	

	cout << "Testing resize() function";
	if (v_name == "v2")
	{
		v.resize(20);
		cout << " (one parameter)" << endl; 
		printSizeCap(v);
		printVectorContents(v);
		v.resize(10);
	}
	else if (v_name == "v3")
	{
		v.push_back(0);
		v.push_back(0);
		v.resize(20, 101);
		cout << " (two parameter)" << endl; 
		printSizeCap(v);
		printVectorContents(v);
		v.resize(10, 20);
	}

	printSizeCap(v);
	printVectorContents(v);
	
}

void testAssign(vector<int> &v, int value, int position)
{
	cout << "Testing assign() function" << endl;
	v.assign(position, value);
	printSizeCap(v);
	printVectorContents(v);
}

void testClear(vector<int> &v)
{
	cout << "Testing clear() function" << endl;
	v.clear();
	printSizeCap(v);
}
