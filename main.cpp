//
//  Words.cpp
//  Assignment 4 Part D
//
//  I used selection sort. Only had to change from template to work with arrays of structs.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_OF_WORDS = 58110; //Change based on size of dictionary
struct Words
{
    string wordar;
    int valuear;
};

int NumValueOfChar(char input); //Prototype for func. that assigns values to chars
int SumOfValues(string word); //Prototype for summing word values
void selectionSort(struct Words A[], int N);
int binarySearch(int x, const Words A[], int N);

int main() {
    Words w[NUM_OF_WORDS]; //Array of structs
    string word; //To store current word in
    int findValue; //For user to enter value to find words
    int counter = 0; //For displaying words at end of program
    
    //Inputs file
    ifstream inFile;
    inFile.open("dictionary.txt");
    if (!inFile) {
        cout << "Error inputting file. Exiting." << endl;
        return -1;
    }
    
    //Populates word array in struct with words
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        getline (inFile,w[i].wordar); //gets the first word. puts it in the word array
        word = w[i].wordar;
        w[i].valuear = SumOfValues(word);
    }
    
    selectionSort(w, NUM_OF_WORDS); //Sorts array!
    
    //Following 6 lines are for printing example values
    /*
    cout << "Numeric value of 'N': " << NumValueOfChar('N') << endl;
    cout << "Numeric value of 'z': " << NumValueOfChar('z') << endl;
    cout << "Numeric value of 'e': " << NumValueOfChar('e') << endl;
    cout << "Numeric value of '#': " << NumValueOfChar('#') << endl;
    cout << "Numeric value of 'Words': " << SumOfValues("Words") << endl << endl;
    cout << "First 5 words: " << endl;
    
    
    //Following two if statements are for printing the first 5 (or if < 5, all) words after they've been sorted.
    if (NUM_OF_WORDS < 5) {
        for (int i = 0; i < NUM_OF_WORDS; i++) {
            cout << i + 1 << ':' << setw(6) << w[i].valuear << setw(9) << w[i].wordar << endl;
        }
    }
    if (NUM_OF_WORDS >= 5) {
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ':' << setw(6) << w[i].valuear << setw(9) << w[i].wordar << endl;
        }
    }
    
    cout << endl << endl; //Spaces
    */
    
    cout << "Please enter a search value: " << endl << "> "; //Prompt user to enter value.
    cin >> findValue;
    
    //Following while statement prints out all words associated with user's value.
    while (w[binarySearch(findValue, w, NUM_OF_WORDS) + counter].valuear == findValue) {
        cout << w[binarySearch(findValue, w, NUM_OF_WORDS) + counter].wordar << endl;
        counter++;
    }
    //If there are no words that match user's value, print message.
    if (counter == 0) {
        cout << "[NONE]" << endl;
    }
    
    return 0;
}

int binarySearch(int x, const Words A[], int N)
{
    //Finds middle value from a list of values from user's entered value. Checks 2 previous indexes to find when value changed (i.e. from 50 to 49). Sets flag when that change occurs. We are at the first position for that value.
    bool top = false;
    int counter = 0;
    int low = 0;
    int high = N - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x == A[mid].valuear) {
            while (top == false) {
                if ((A[mid - counter].valuear) == (A[mid - counter - 1].valuear)) {
                    counter++;
                } else if ((A[mid - counter].valuear) != (A[mid - counter - 1].valuear)) {
                    top = true;
                    return mid - counter;
                }
            }
        }
        else if (x < A[mid].valuear)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -2;
}



int SumOfValues(string word)
{
    //Uses .length to determind how many times to loop.
    int valueArray[word.length()]; //Crates array based on size of word passed to it.
    int sum = 0; //Creates a sum variable.
    
    //Loops as many times as there are letters in current word. Passes current letter (i) to NumValie function.
    //Fills each index of array with corresponding number as letters are passed.
    for (int i = 0; i < word.length(); i++) {
        valueArray[i] = NumValueOfChar(word.at(i));
    }
    
    //Loops as many times as there are letters in current word. Takes each index of valueArray and adds to sum variable.
    for (int i = 0; i < word.length(); i++) {
        sum += valueArray[i];
    }
    
    return sum;
}

void selectionSort(struct Words A[], int N)
{
    int i, j, search_min;
    Words temp;
    
    for (i = 0; i < N; i++) {
        search_min = i;
        for (j = i + 1; j < N; j++) {
            if (A[j].valuear < A[search_min].valuear) {
                search_min = j;
            }
        }
        temp = A[search_min];
        A[search_min] = A[i];
        A[i] = temp;
    }
    
}

int NumValueOfChar(char input){
    if (input == 'A' || input == 'a') { return 1; }
    if (input == 'B' || input == 'b') { return 2; }
    if (input == 'C' || input == 'c') { return 3; }
    if (input == 'D' || input == 'd') { return 4; }
    if (input == 'E' || input == 'e') { return 5; }
    if (input == 'F' || input == 'f') { return 6; }
    if (input == 'G' || input == 'g') { return 7; }
    if (input == 'H' || input == 'h') { return 8; }
    if (input == 'I' || input == 'i') { return 9; }
    if (input == 'J' || input == 'j') { return 10; }
    if (input == 'K' || input == 'k') { return 20; }
    if (input == 'L' || input == 'l') { return 30; }
    if (input == 'M' || input == 'm') { return 40; }
    if (input == 'N' || input == 'n') { return 50; }
    if (input == 'O' || input == 'o') { return 60; }
    if (input == 'P' || input == 'p') { return 70; }
    if (input == 'Q' || input == 'q') { return 80; }
    if (input == 'R' || input == 'r') { return 90; }
    if (input == 'S' || input == 's') { return 100; }
    if (input == 'T' || input == 't') { return 200; }
    if (input == 'U' || input == 'u') { return 300; }
    if (input == 'V' || input == 'v') { return 400; }
    if (input == 'W' || input == 'w') { return 500; }
    if (input == 'X' || input == 'x') { return 600; }
    if (input == 'Y' || input == 'y') { return 700; }
    if (input == 'Z' || input == 'z') { return 800; }
    else return 0;
}



