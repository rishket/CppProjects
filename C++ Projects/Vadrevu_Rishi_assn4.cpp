#include <fstream>
#include <algorithm>
#include <locale>
using namespace std;

/* 
Author: Rishi Vadrevu 
The main file that implements the BST and word entry classes
*/

//inlcuding header files
#include "Vadrevu_Rishi_node.hpp"
#include "Vadrevu_Rishi_BST.hpp"
#include "wordentry.hpp"

//this function uses the parsed input and determines if the parsed string is a letter or a number 
//which helps to differentiate words like best-selling into two words
//used in main 
bool alphanumeric(string input) 
{
    locale loc;
    bool isAlphanumericOrNot = false;
    for (std::string::iterator iterator = input.begin(); iterator != input.end(); ++iterator)
    {
        if (!std::isalpha(*iterator, loc)) {
            isAlphanumericOrNot = false; //not alphanumeric
        }
        isAlphanumericOrNot = true; //didn't pass through previous condiiton, so it is alphanumeric
    }
    return isAlphanumericOrNot; //return true or false
}

int main(int argc, char** argv)
{
    //variables used
    string choice;
    string line;
    string parseWord;
    int userChoice;
    int numWords = 0;
    BinaryTree<wordentry>* analyze = new BinaryTree<wordentry>(); //creation of binary tree
    char analyzeChoice;
    string analyzeUser;
    ifstream choiceFile(choice);
    char readUserYorNo; //reads the y or n the user chooses
    ofstream userFile;

    cout<<"Choose a text file to analyze: \n";
    cout<<"1. frankenstein.txt"<<endl;
    cout<<"2. frost_poems.txt"<<endl;
    cout<<"3. warpeace.txt"<<endl;
    cout<<"4. frostGhost.txt"<<endl;
    cin>>userChoice;

    //choose which file to analyze
    switch(userChoice)
    {
        case 1: 
        choice = "frankenstein.txt";
        break;

        case 2:
        choice = "frost_poems.txt";
        break;

        case 3:
        choice =  "warpeace.txt";
        break;

        case 4:
        choice = "frostGhost.txt";
        break;

    }

    /*
    Note: info on size_t and using alphanumeric behavior learned from cpp reference
    */

    while(getline(choiceFile, line))
    {
        for(size_t position = 0; ;)
        {
            size_t next = line.find_first_of(" -,.\r\n", pos);
            if (next == position) 
            {
                position = next++;
                continue;
            }
            if (next == string::npos) 
            {
                parseWord = line.substr(position, line.length() - position);
            } 
            else 
            {
                parseWord = line.substr(position, next - position);
            }
            if (alphanumeric(parseWord)) // this condition will pass if the 
            //string is alphanumeric and ready to be inserted into the templated BST class of type wordentry
            {
                //convert string to lowercase
                transform(parseWord.begin(), parseWord.end(), parseWord.begin(), ::tolower); 
                numWords++; //increment how many words
                analyze->insert( (wordentry) parseWord);
            }
            if (next == string::npos) //nothing else in line
            {
                break;
            }
            position = next + 1;
        }
    }

    cout<<"Analysis:"<<endl;
    cout<<"Total words: "<<numWords<<endl;
    cout<<"Total unique words: "<<analyze->getUnique()<<endl;
    cout<<"Would you like to analyze a word? (y for yes, n for no)"<<endl;
    cin>>readUserYorNo;
    
    switch(readUserYorNo)
    {
        case 'y':
        {
            cout<< "\nPlease enter a word you would like to find the frequency of: " <<endl;
            cin.ignore(1, '\n');
            getline(cin, analyzeUser);

            wordentry enterWordFromUser(analyzeUser);
            //create a BST node of type wordentry
            BinarySearchNode<wordentry>* found = analyze->find(enterWordFromUser); 

            cout << "Analysis of '" << analyzeUser << "' in " << choice << ":" << endl;

            if (found) { //the word was found and frequency is outputted
                cout << "Frequency is "<< found->getWord().getFrequency() << endl;
            } else { //word was not found
                cout << "Frequency is 0" << endl;
            }

            cout << "Would you like to output the analysis to a file? (y for yes, n for no)" << endl;
            cin >> analyzeChoice;

            if(analyzeChoice == 'y') //write info to file userFile
            {
                userFile.open("analysis.txt");
                userFile << "Analysis: \n";
                userFile << "The word " << analyzeUser << " occurs " << found->getWord().getFrequency() << " times\n";
                userFile.close();
                cout << "Your analysis file is ready to view." << endl;
            }           
            break;
        }
        case 'n': //user does not want to output to a file
            break;

    }

    cout << "\nThank you for using the program." << endl;

    return 0;

}

