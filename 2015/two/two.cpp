//
// Created by Joshua Acton on 09/12/2022.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DayTwo {
public:
    static int two() {
        string input; // declare a string object to store input lines
        int totalPaper = 0; // assign an int to store the required amount of paper
        int totalRibbon = 0; // assign an int to store the required amount of ribbon

        ifstream myfile("input.txt"); // stream in the input file
        int l; // declare an int to store the length of the present
        int w; // declare an int to store the width of the present
        int h; // declare an int to store the height of the present

        while (getline (myfile, input)) { // iterate through each line of the input
            size_t x1 = input.find('x'); // find the index of the first 'x' character in the input line
            size_t x2 = input.find('x', x1+1); // find the index of the second 'x' character in the input line

            l = stoi(input.substr(0, x1)); // length is int val of substring up to 1st 'x'
            w = stoi(input.substr(x1+1, x2-(x1+1))); // width is int val of substring between 1st, 2nd 'x'
            h = stoi(input.substr(x2+1, input.length()-(x2+1))); // height is int val of 2nd 'x' to end

            totalPaper += (2*l*w + 2*w*h + 2*h*l) + min(l*w, min(w*h, h*l)); // calculate total paper for present
            totalRibbon += (l*w*h) + min(2*(l+w), min(2*(w+h), 2*(h+l))); // calculate total ribbon for present
        }

        cout << totalPaper << endl; // return total required wrapping paper (part 1)
        cout << totalRibbon << endl; // return total required ribbon (part 2)

        myfile.close();
        return 0;
    }
};

int main() {
    DayTwo::two();
}