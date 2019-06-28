#include <iostream>
using namespace std;

int main ()
{
	int ex, i;
	bool count_e = 0;
	bool count_x = 0;
	cout << "Which exercise: ";
	cout << endl;
	cin >> ex;
	if (ex == 1)
	{
		string word;	
		cout << "Enter a word: " << endl;
		cin >> word;
		for (i = 0; i < word.size(); i++)
		{
			if (word.at(i) == 'e' && count_e == 0)	
			{ 
				count_e = 1;
			}	

			else if (word.at(i) == 'x' && count_x == 0)	
			{ 
				count_x = 1;
			}	
		}	
		if (count_e == 1)
		{
			cout << "Your word " 
			     << word << " contains the character 'e'";
			cout << endl;
		}
		if (count_x == 1)
		{
			cout << "Your word " 
			     << word << " contains the character 'x'";
			cout << endl;
		}
	}
	else if (ex == 2)
	{
		string word;
		int i, length;
		cout << "Enter a word: ";
		cin >> word;
		cout << "\n";
		
		length = word.size();
		cout << "Your word transformed is ";
		
		for (i=0; i < length; i++)
		{
		    if (word.at(i) =='e')
			cout << '3';
		    else if (word.at(i) =='i')
			cout << '1';
		    else if (word.at(i) =='x')
			cout << "*";
		    else
			cout << word.at(i) ;
		}
		cout << "\n";
	}
	else if (ex == 3)
	{
		string sentence;
		int dot_idx;
		int stop_idx = 0;
		bool track_dot = 0;
		bool track_stop = 0;
		cout << "Enter a sentence: "; 
		cout << endl;
		cin >> sentence;
		for (i = 0; i < sentence.size(); i++)
		{
			if (sentence.at(i) == '.')
			{
				
				dot_idx = i;
				track_dot = 1;
			}	
			if (sentence.at(i) == 's')
			{	
				stop_idx = i;
				if (sentence.at(i + 1) == 't' &&
				    sentence.at(i + 2) == 'o' &&
				    sentence.at(i + 3) == 'p')
					track_stop = 1;
			}
		}
		if (count_dot > 0)
			cout << "The character '.' is located at index " << dot_idx << endl;
		else 
			cout << "Your sentence does not contain the character '.'" << endl;

		if (track_stop == 1)
			cout << "The word \"stop\" is located at index " << stop_idx << endl;
		else (track_stop == 0)
			cout << "Your sentence does not contain the word \"stop\"" << endl;
	}	
}	

	
