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
        string input;
        int totalPaper = 0;
        int totalRibbon = 0;

        ifstream myfile("input.txt");
        int l;
        int w;
        int h;

        while (getline (myfile, input)) {
            size_t x1 = input.find('x');
            size_t x2 = input.find('x', x1+1);

            l = stoi(input.substr(0, x1));
            w = stoi(input.substr(x1+1, x2-(x1+1)));
            h = stoi(input.substr(x2+1, input.length()-(x2+1)));

            totalPaper += (2*l*w + 2*w*h + 2*h*l) + min(l*w, min(w*h, h*l));
            totalRibbon += (l*w*h) + min(2*(l+w), min(2*(w+h), 2*(h+l)));
        }

        cout << totalPaper << endl;
        cout << totalRibbon << endl;

        myfile.close();
        return 0;
    }
};

int main() {
    DayTwo::two();
}