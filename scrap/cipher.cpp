
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
 *
 * OUTPUT:
 * 	Bad operation error
 * 	Decrypted word
 * 	Encrypted word
 *
 ***************************************************************************/
void encrypt() {
		for (i = 0; i < word.size(); i++) {
			for (j = 0; j < default_string.size(); j++) {
				if (word.at(i) == default_string.at(j)) 
					count_letter++;
			}
		}
		if (count_letter == word.size()) 
			encryptable = 1;
		if (encryptable == 1) {
			for (i = 0; i < word.size(); i++) {
				word_letter = word.at(i);
				alphabet_idx = alphabet_map[word_letter];
				cout << default_map[alphabet_idx];
			}
		}
}

int main() {
	// for user input
	string word;							// user word input
	string method;		 			 		// method user input
	string translation;
	// for key, value map
	string default_string;
	string alphabet;
	map<int, char> default_map;				// default string map
	map<char, int> alphabet_map;
	// for for-loop
	int i;
	int j;
	int k;
	// for encryption/decryption validation
	bool encryptable;
	bool decryptable;
	int count_letter;
	char word_letter;
	int alphabet_idx;

	// ALPHABET MAP
	// key: letter, value: index
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (i = 0; i < alphabet.size(); i++)
		alphabet_map[alphabet.at(i)] = i;

	// DEFAULT MAP
	// key: index, value: letter
	default_string = "zyxwvutsrqponmlkjihgfedcba";
	for (i =0; i < default_string.size(); i++)
		default_map[i] = default_string.at(i);

	// INPUT
	method = "decryption";
	word = "xzg";
	cout << "What is the method (encryption or decryption)? ";
	cin >> method;
	cout << endl;
	cout << "What is the translation map (type 'default' to use default): ";
	cout << endl;
	cin >> translation;
	cout << endl;
	if (translation != "default")
		default_string = translation;
	cout << "What is the single word to translate: ";
	cin >> word;
	cout << endl;
		
	

	// ENCRYPTION
	count_letter = 0;
	encryptable = 0;

	if (method == "encryption") {
		// encryption validation
		for (i = 0; i < word.size(); i++) {
			for (j = 0; j < default_string.size(); j++) {
				if (word.at(i) == default_string.at(j)) 
					count_letter++;
			}
		}
		if (count_letter == word.size()) 
			encryptable = 1;
		if (encryptable == 1) {
			for (i = 0; i < word.size(); i++) {
				word_letter = word.at(i);
				alphabet_idx = alphabet_map[word_letter];
				cout << default_map[alphabet_idx];
			}
		}
		else 
			cout << "Error: encryption cannot be performed." << endl;
	}

	// DECRYPTION
	decryptable = 0;
	if (method == "decryption") {
		// decryption validation	
		for (i = 0; i < word.size(); i++) {
			for (j = 0; j < default_string.size(); j++) {
				if (word.at(i) == default_string.at(i))
						count_letter++;
			}
		}
		if (count_letter == word.size())
			decryptable = 1;
		if (decryptable == 1); {
			for (i =0; i < word.size(); i++) {
				word_letter = word.at(i);
				alphabet_idx = alphabet_map[word_letter];
				cout << default_map[alphabet_idx];
			}
		}
		else
			cout << "Hello" << endl;
		
	}
	
// End of main()
}

