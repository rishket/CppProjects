#include "noble.h"
#include <iostream>
using namespace std;

void Noble::displayBook(){
	cout << "Book Name: " << getName() << endl;
	cout << "Copies: " << getCopies() << endl
	if(getLibraryType() == 0)
		cout << "Library: Hayden" << endl << endl;
	else
		cout << "Library: Noble" << endl << endl;
}

// Q2b: Define displayBook() for Noble class (5 points)
// Define the function displayBook() that you declared within the Noble class in the header file
// See expected output in question file.

// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files
