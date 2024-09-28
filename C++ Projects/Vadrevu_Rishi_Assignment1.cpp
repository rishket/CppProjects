/*

Author: Rishi Vadrevu

Date: 10/12/21

Description: A program to convert file contents to english or morse code

Usage: C++

*/

//import libraries
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

//forward declarations
const char* englishToMorse(char englishChar);
char morseToEnglish(const char* letter);

/*
Hi baby, 
I started the assignment for you I finished the enlish to morse code function
and the morse code to english function and I opened some links that should make the 
file reading stuff easier. ily u got this
*/

int main(int argc, char** argv)
{
    char translateLine[256]; //create charcter array to store getline output
    
    //open file for reading
    ifstream input;
    input.open(argv[1]); //the first index command line argument is the file being opened
    //create and open file for output
    ofstream output;
    output.open(argv[3]); //file being outputted to file name given as third index command line argument


    //if user wants to do -mc
    if(strcmp(argv[2], "-mc") == 0)
    {
    
        while(!input.eof())
        {
            input.getline(translateLine, 256);

            for(int i = 0; translateLine[i] != '\0'; i++)
            {

                output<<englishToMorse(translateLine[i]);
                if(translateLine[i+1] == '\0')
                {
                    output<<"\n";
                }
            }
        }

    }else if(strcmp(argv[2], "-e") == 0) //if user wants to do -e
    {
        while(!input.eof())
        {
            input.getline(translateLine, 256);
            const char* splitWords = strtok(translateLine, "|");

            while(splitWords != NULL)
            {
                output<<morseToEnglish(splitWords);
                splitWords = strtok(NULL, "|");
            }

        }
        
    }else //if user inputs something other than -mc or -e
    {
        cout<<"Error. Incorrect command line input. Input command in form <exe> <input file> <-mc|-e> <output file>"<<endl;
    }

}
//function to convert english to morse
const char* englishToMorse(char englishChar)
{
    const char* morseCode; //var returned
    switch(englishChar) //switch statement comaparing input and other cases
    {
        case 'A': case 'a': 
            morseCode = "._";
            break;
        case 'B': case 'b':
            morseCode = " -...";
            break;
        case 'C': case 'c':
            morseCode = "-.-.";
            break;
        case 'D': case 'd':
            morseCode = "-..";
            break;
        case 'E': case 'e':
            morseCode = ".";
            break;
        case 'F': case 'f':
            morseCode = "..-.";
            break;
        case 'G': case 'g':
            morseCode = "--.";
            break;
        case 'H': case 'h':
            morseCode = "....";
            break;
        case 'I': case 'i':
            morseCode = "..";
            break;
        case 'J': case 'j':
            morseCode = ".---";
            break;
        case 'K': case 'k':
            morseCode = "-.-";
            break;
        case 'L': case 'l':
            morseCode = ".-..";
            break;
        case 'M': case 'm':
            morseCode = "--";
            break;
        case 'N': case 'n':
            morseCode = "-.";
            break;
        case 'O': case 'o':
            morseCode = "---";
            break;
        case 'P': case 'p':
            morseCode = ".--.";
            break;
        case 'Q': case 'q':
            morseCode = "--.-";
            break;
        case 'R': case 'r':
            morseCode = ".-.";
            break;
        case 'S': case 's':
            morseCode = "...";
            break;
        case 'T': case 't':
            morseCode = "-";
            break;
        case 'U': case 'u':
            morseCode = "..-";
            break;
        case 'V': case 'v':
            morseCode = "...-";
            break;
        case 'W': case 'w':
            morseCode = ".--";
            break;
        case 'X': case 'x':
            morseCode = "-..-";
            break;
        case 'Y': case 'y':
            morseCode = "-.--";
            break;
        case 'Z': case 'z':
            morseCode = "--..";
            break;
        case ' ':
            morseCode = "/";
            break;
        case '\0':
            morseCode = "\n";
            break;
        default:
            morseCode = "eeee";
            break;
    }

    return morseCode;
}

//converting morse to english using strcmp function.
char morseToEnglish(const char* letter)
{
    char english;

    if(strcmp(letter, ".-") == 0)
    {
        english = 'a';
        return english;
    }
    if(strcmp(letter, "-...") == 0)
    {
        english = 'b';
        return english;
    }
    if(strcmp(letter, "-.-.") == 0)
    {
        english = 'c';
        return english;
    }
    if(strcmp(letter, "-..") == 0)
    {
        english = 'd';
        return english;
    }
    if(strcmp(letter, ".") == 0)
    {
        english = 'e';
        return english;
    }
    if(strcmp(letter, "..-.") == 0)
    {
        english = 'f';
        return english;
    }
    if(strcmp(letter, "--.") == 0)
    {
        english = 'g';
        return english;
    }
    if(strcmp(letter, "....") == 0)
    {
        english = 'h';
        return english;
    }
    if(strcmp(letter, "..") == 0)
    {
        english = 'i';
        return english;
    }
    if(strcmp(letter, ".---") == 0)
    {
        english = 'j';
        return english;
    }
    if(strcmp(letter, "-.-") == 0)
    {
        english = 'k';
        return english;
    }
    if(strcmp(letter, ".-..") == 0)
    {
        english = 'l';
        return english;
    }
    if(strcmp(letter, "--") == 0)
    {
        english = 'm';
        return english;
    }
    if(strcmp(letter, "-.") == 0)
    {
        english = 'n';
        return english;
    }
    if(strcmp(letter, "---") == 0)
    {
        english = 'o';
        return english;
    }
    if(strcmp(letter, ".--.") == 0)
    {
        english = 'p';
        return english;
    }
    if(strcmp(letter, "--.-") == 0)
    {
        english = 'q';
        return english;
    }
    if(strcmp(letter, ".-.") == 0)
    {
        english = 'r';
        return english;
    }
    if(strcmp(letter, "...") == 0)
    {
        english = 's';
        return english;
    }
    if(strcmp(letter, "-") == 0)
    {
        english = 't';
        return english;
    }
    if(strcmp(letter, "..-") == 0)
    {
        english = 'u';
        return english;
    }
    if(strcmp(letter, "...-") == 0)
    {
        english = 'v';
        return english;
    }
    if(strcmp(letter, ".--") == 0)
    {
        english = 'w';
        return english;
    }
    if(strcmp(letter, "-..-") == 0)
    {
        english = 'x';
        return english;
    }
    if(strcmp(letter, "-.--") == 0)
    {
        english = 'y';
        return english;
    }
    if(strcmp(letter, "--..") == 0)
    {
        english = 'z';
        return english;
    }
    if(strcmp(letter, "/") == 0)
    {
        english = ' ';
        return english;
    }
    if(strcmp(letter, "\n") == 0)
    {
        english = '\0';
        return english;
    }

    return english;

}


