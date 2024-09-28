#include "wordEntry.h"

/*
Author: Aditi Rai
This file contains the definitions for a wordEntry class 

*/


wordEntry::wordEntry()
{
    this->frequency = 0;
    this->word = " ";
}

wordEntry::wordEntry(string analyzedWord)
{
    this->frequency = 0;
    this->word = analyzedWord;

}

string wordEntry::getWord()
{
    return this->word;
}

void wordEntry::setWord(string read)
{
    this->frequency++;
    this->word = read;
}

int wordEntry::getFrequency()
{
    return this->frequency;
}

void wordEntry::incrementFrequency()
{
    this->frequency++;
}
