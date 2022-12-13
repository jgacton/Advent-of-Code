//
// Created by Joshua Acton on 13/12/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <openssl/md5.h>
using namespace std;

class DayFour {
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
    DayFour::partOne();
}