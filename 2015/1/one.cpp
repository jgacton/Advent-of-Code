//
// Created by Joshua Acton on 08/12/2022.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DayOne {
    public:
        static int one() {
            string input; // declare a string object to store input lines

            ifstream myfile("input.txt"); // stream in the input file

            while (getline (myfile, input)) { // iterate through each line of the input
                int floor = 0; // initially we are on the ground (zeroeth) floor
                for (int i = 0; i < input.length(); i++) { // iterate through each character of the input line
                    if(input[i] == '(') floor++; // increment the floor if '('
                    if(input[i] == ')') floor--; // decrement the floor if ')'
                    if(floor == -1) {
                        cout << i+1 << endl; // if the floor is -1 output the index we are up to (part 2)
                    }
                }
                cout << floor << endl; // output the final floor (part 1)
            }

            myfile.close(); // close the file
            return 0;
        }
};

int main() {
    DayOne::one();
}