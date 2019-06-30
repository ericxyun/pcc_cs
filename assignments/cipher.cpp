
/**************************************************************************
 *	AUTHOR	 : Eric Yun
 *	Lab #5	 : Ciper
 *	CLASS	 : CS 002
 *	SECTION  : MTRF: 7:00a - 12p
 *	Due Date : June 20, 2019	
 **************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
/**************************************************************************
 *
 * CIPHER
 *
 *--------------------------------------------------------------------------
 * This program will decrypt and encrypt a single word that is entered by 
 * 		the user.
 *--------------------------------------------------------------------------
 * INPUT:
 * 		method: encryption or decryption
 * 		translation: type of translation map
 * 		word: word to encrypt/decrypt
 *
 * OUTPUT:
 * 		Decrypted word
 * 		Encrypted word
 * 		Errors:
 * 			EncryptionError: if letters in words are not lowercase
 * 			DecryptionError: if letters in words are not in translation map
 * 			TranslationMapError: numbers of letters is no at least 26
 * 			MethodError: method is not "encryption" or "decryption"
 *
 ***************************************************************************/
// global variables
int i;									// for loop
int j;									// for loop
int k;									// for loop
int alphabet_idx;						// get index of alphabet
int count_letter;						// to compare translation map size	
char word_letter;						// used to isolate letters
bool check_encrypt_decrypt_bool; 		// used to check if word is
										// encryptable/decryptable
string word;							// INPUT: user word
string method;		 			 		// INPUT: method
string translation;						// INPUT: translation map
string alphabet;						// constant alphabet 
string default_string;					// constant default string
map<int, char> default_map;				// default string key, value map
map<char, int> alphabet_map;			// alphabet key, value map


// FUNCTIONS
void EncryptError() 
{
	cout << "Error: encryption cannot be performed." << endl;
}

void DecryptError() 
{
	cout << "Error: decryption cannot be performed." << endl;
}

void TranslationMapError() 
{
	cout << "Error: invalid translation map size." << endl;
}

void MethodError() 
{
	cout << "Error: invalid method choice." << endl;
} 

// function to check is word is encryptable/decryptable
void check_encrypt_decrypt()
{
	int letter_count; 					// counts number of letters
	letter_count = 0; 					// initialize letter counter	
	check_encrypt_decrypt_bool = 0;		// initialize method checker

	// check if all letters in the word are lowercase.
	if (method == "encryption")
	{
		for (i = 0; i < word.size(); i++)
		{
			if (!(isdigit(word.at(i))))
			{
				if (islower(word.at(i)))
				{
					letter_count++;
				}
			}		
		}
		if (word.size() == letter_count)
			check_encrypt_decrypt_bool = 1;
	}

	// check if all letters in word input are in translation map
	else if (method == "decryption")
	{
		for (i = 0; i < word.size(); i++) 
		{
			for (j = 0; j < default_string.size(); j++) 
			{
				if (word.at(i) == default_string.at(j)) 
					letter_count++;
			}
		}
		if (letter_count == word.size()) 
			check_encrypt_decrypt_bool = 1;
	}
}


// function to print encrypted/decrypted word or errors
void cipher() 
{
	// prints encrypted/decrypted word if conditions are met
	if (check_encrypt_decrypt_bool == 1) 
	{
		if (method == "encryption") 
			cout << "Encrypted word: ";
		else if (method == "decryption") 
			cout << "Decrypted word: ";
		for (i = 0; i < word.size(); i++) 
		{
			word_letter = word.at(i);
			alphabet_idx = alphabet_map[word_letter];
			cout << default_map[alphabet_idx];
		}
		cout << endl;
	}

	else 
	{
		if (method == "encryption")
			EncryptError();
		else if (method == "decryption")
			DecryptError();
	}
}

// creates two maps: alphabet_map, default_string_map
void translation_map()
{
	if (translation != "default") 
		default_string = translation;

	// create key-value pairs
	for (i = 0; i < alphabet.size(); i++)      // alphabet map  
		alphabet_map[alphabet.at(i)] = i;      // key: letter, value: index
	for (i =0; i < default_string.size(); i++) // default map  
	default_map[i] = default_string.at(i);     // key: index, value: letter

}

int main() 
{

	// data
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	default_string = "zyxwvutsrqpomnlkjihgfedcba";


	// INPUT -- Get user inputs and check for valid inputs
	// get method 
	cout << "What is the method (encryption or decryption)? ";
	cin >> method;
	cout << endl;

	// get translation map
	if (method == "encryption" || method == "decryption") 
	{
		cout << "What is the translation map "
			 << "(type 'default' to use default): ";
		cin >> translation;
		cout << endl;

		if (translation == "default" || translation.size() == 26) 
		{
			// created key, value pair maps
			translation_map();

			//get word
			cout << "What is the single word to translate: ";
			cin >> word;
			cout << endl;

			// create boolean to check if word is encryptable/decryptable
			// boolean will be used inside the cipher fucntion and will 
			// 		provide an error if 0.
			check_encrypt_decrypt();

			// OUTPUT -- prints the encrypted/decrypted word.
			cipher();
		}
		else
			TranslationMapError();

	}
	else
		MethodError();

// End of main()
}

