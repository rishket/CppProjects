/*
Author: Rishi Vadrevu
Date: 10/26/21
Description: Creating and using particle roll algorithm to generate island
based off of user input
Language: C++
*/

#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
using namespace std;

//forward declarations
void makeParticleMap(int** map, int width, int height, int windowX, int windowY, int winWidth, int winHeight, int numParticles, int maxLife);
bool moveExists(int** map, int width, int height, int x, int y);
int findMax(int** map, int width, int height);
void normalizeMap(int** map, int width, int height, int maxVal, int waterLineValue);

int main(int argc, char** argv){
    int gridWidth;
    int dropWidth;
    int gridHeight;
    int dropHeight;
    int xCoor;
    int yCoor;
    int numParticles;
    int waterLineVal;
    int maxLife;
    int** arrayGenerated;

    srand(time(NULL));

    cout << "Welcome to Rishi's CSE240 island generator!" << endl;
    cout << "Enter grid width: " << endl;
    cin >> gridWidth;
    cout << "Enter grid height: " << endl;
    cin >> gridHeight;
    cout << "Enter drop-window x-coordinate (0 - " << gridWidth << "): ";
    cin >> xCoor;
    cout << "Enter drop-window y-coordinate (0 - " << gridHeight << "): ";
    cin >> yCoor;
    cout << "Enter drop-window width (>= 1): ";
    cin >> dropWidth;
    while((dropWidth + xCoor) > gridWidth){
        cout << "Invalid Input. Please enter an integer between 1 and " << gridWidth - xCoor << ": ";
        cin >> dropWidth;
    }
    cout << "Enter drop-window height (>= 1): ";
    cin >> dropHeight;
    while((dropHeight + yCoor) > gridHeight){
        cout << "Invalid Input. Please enter an integer between 1 and " << gridHeight - yCoor << ": ";
        cin >> dropHeight;
    }
    cout << "Enter number of particles to drop: ";
    cin >> numParticles;
    cout << "Enter max life of particles: ";
    cin >> maxLife;
    cout << "Enter value for waterline (40-200): ";
    cin >> waterLineVal;
    while(waterLineVal < 40 || waterLineVal > 200){
        cout << "Invalid Input. Please input a number between 40 and 200";
        cin >> waterLineVal;
    }
    //initializing arrayGenerated and filling in values as 0
    arrayGenerated = new int* [gridHeight];
    for(int row = 0; row < gridHeight; row++){
        arrayGenerated[row] = new int[gridWidth];
        for(int col = 0; col < gridWidth; col++){
            arrayGenerated[row][col] = 0;
        }
    }

    int max = findMax(arrayGenerated, gridWidth, gridHeight);

    //makeParticleMap(arrayGenerated, xCoor, yCoor, dropWidth, dropHeight, numParticles, maxLife, gridWidth, gridHeight);
    //normalizeMap(arrayGenerated, gridWidth, gridHeight, max, waterLineVal);

    

    
}

int findMax(int** map, int width, int height){
    int max = 0;
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            if(map[row][col] > max){
                max = map[row][col];
            }
        }
    }
    return max;
}

void normalizeMap(int** map, int width, int height, int maxVal, int waterLineValue){
    int value;
    int landZone = 255 - waterLineValue;
    for(int row = 0; row < height; row++){
        
        for(int col = 0; col < width; col++){
            value = (map[row][col]/maxVal) * 255;
        }
    }
}

bool moveExists(int** map, int width, int height, int x, int y){

}

