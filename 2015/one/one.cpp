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
            string input;

            ifstream myfile("input.txt");

            while (getline (myfile, input)) {
                int floor = 0;
                for (int i = 0; i < input.length(); i++) {
                    if(input[i] == '(') floor++;
                    if(input[i] == ')') floor--;
                    if(floor == -1) {
                        cout << i+1 << endl;
                    }
                }
                cout << floor << endl;
            }

            myfile.close();
            return 0;
        }
};

int main() {
    DayOne::one();
}