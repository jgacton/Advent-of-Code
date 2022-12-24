//
// Created by Joshua Acton on 17/12/2022.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DayOne {
public:
    static int partOne() {
        string input; // declare a string object to store input lines

        ifstream myfile("input.txt"); // stream in the input file

        while (getline (myfile, input)) { // iterate through each line of the input
            cout << input << endl;
        }

        myfile.close(); // close the file
        return 0;
    }
};

int main() {
    DayOne::partOne();
}