#include <iostream>
#include <fstream>
#include <string.h>
#include <locale>
#include <algorithm>

#include "wordFrequency.hpp"
#include "wordEntry.h"

using namespace std;

/*
Author: Aditi Rai
This file contains the main execution of the program 
*/


//forward declarations
bool isStringAlpha(string instring);

int main(int argc, char** argv)
{
    string textChosen;
    string oneLine;
    string oneWord;
    int userChoice;
    BinaryTree<wordEntry>* wordAnalysis = new BinaryTree<wordEntry>(); //creation of binary tree

    cout<<"Choose a text file to analyze: \n";
    cout<<"1. frankenstein.txt"<<endl;
    cout<<"2. frost_poems.txt"<<endl;
    cout<<"3. warpeace.txt"<<endl;
    cout<<"4. frostGhost.txt"<<endl;
    cin>>userChoice;

    switch(userChoice)
    {
        case 1: 
        textChosen = "frankenstein.txt";
        break;

        case 2:
        textChosen = "frost_poems.txt";
        break;

        case 3:
        textChosen =  "warpeace.txt";
        break;

        case 4:
        textChosen = "frostGhost.txt";
        break;

    }
    int numWords = 0;

    /*
    Note: info on size_t and using alphanumeric behavior learned from cpp reference
    */

    ifstream parseFile(textChosen);
    while(getline(parseFile, oneLine))
    {
        for(size_t pos = 0; ;)
        {
            size_t nextpos = oneLine.find_first_of(" -,.\r\n", pos);
            if (nextpos == pos) 
            {
                pos = nextpos + 1;
                continue;
            }
            if (nextpos == string::npos) 
            {
                oneWord = oneLine.substr(pos, oneLine.length() - pos);
            } 
            else 
            {
                oneWord = oneLine.substr(pos, nextpos - pos);
            }
            if (isStringAlpha(oneWord)) //string is alphanumeric and ready to be inserted into the BST of type wordEntry
            {
                //converts the text to lowercase, so do not need to worry about capitalization
                transform(oneWord.begin(), oneWord.end(), oneWord.begin(), ::tolower); 
                numWords++; //increment how many words
                wordAnalysis->insert( (wordEntry) oneWord);
            }
            if (nextpos == string::npos) 
            {
                break;
            }
            pos = nextpos + 1;
        }
    }
    char userAnalyze; //reads the y or n the user chooses

    cout<<"Analysis:"<<endl;
    cout<<"Total words: "<<numWords<<endl;
    cout<<"Total unique words: "<<wordAnalysis->howManyUnique()<<endl;
    cout<<"Top 5 most frequently used words: "<<endl;
    cout<<"Top 5 least frequently used words: "<<endl;
    cout<<"Would you like to analyze a word? (y for yes, n for no)"<<endl;
    cin>>userAnalyze;

    char fileYorNo;
    string wordUserAnalyzes;
    
    switch(userAnalyze)
    {
        case 'y':
        {
            cout<<"\nPlease enter a word you would like to find the frequency of: "<<endl;
            cin.ignore(1, '\n');
            getline(cin, wordUserAnalyzes);
            //cout<<"Entered "<<wordUserAnalyzes<<endl;
            wordEntry we(wordUserAnalyzes);
            BinarySearchNode<wordEntry>* foundNode = wordAnalysis->find(we);
            cout<<"Analysis of '"<<wordUserAnalyzes<<"' in "<<textChosen<<":"<<endl;
            if (foundNode) {
                cout<<"Frequency is "<<foundNode->getWord().getFrequency()<<endl;
            } else {
                cout<<"Frequency is 0"<<endl;
            }

            cout<<"Would you like to output the analysis to a file? (y for yes, n for no)"<<endl;
            cin>>fileYorNo;

            if(fileYorNo == 'y')
            {
                ofstream userAnalysisFile;
                userAnalysisFile.open("analysis.txt");
                userAnalysisFile<<"Analysis: \n";
                userAnalysisFile<<"The word "<<wordUserAnalyzes<<" occurs "<<foundNode->getWord().getFrequency()<<" times\n";
                userAnalysisFile.close();
                cout<<"Your analysis file is ready to view."<<endl;
            }
            else
            {
                break;               
            }            
            break;
        }
        case 'n':
            break;

    }

    cout<<"\nThank you for using this program!"<<endl;

    return 0;

}

//this function is used to parse the file and check if a string is alpha numeric
bool isStringAlpha(string instring) 
{
    locale loc;
    bool bRet = false;
    for (std::string::iterator it=instring.begin(); it!=instring.end(); ++it)
    {
        if (!std::isalpha(*it,loc)) {
            bRet = false;
        }
        bRet = true;
    }
    return bRet;
}