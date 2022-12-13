//
// Created by Joshua Acton on 12/12/2022.
//
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class DayThree {
public:
    static int part_one() {
        string input; // declare a string object to store input lines

        int total = 1; // store total houses receiving at least one present as an integer
        pair<int, int> coords(0, 0); // use a pair to store coordinates of each house
        list<pair<int,int> > lst;
        lst.push_front(coords);

        ifstream myfile("input.txt"); // stream in the input file
        while (getline (myfile, input)) { // iterate through each line of the input
            for(char i : input) { // iterate through each character in the input line
                if (i == '^') {
                    coords.first += 1;
                } if (i == '>') {
                    coords.second += 1;
                } if (i == 'v') {
                    coords.first -= 1;
                } else if (i == '<') {
                    coords.second -= 1;
                }
                if(!contains(lst, coords)) {
                    lst.push_front(coords);
                    total++;
                }
            }
        }

        cout << total << endl;

        myfile.close();
        return 0;
    }

    static int part_two() {
        string input; // declare a string object to store input lines

        int total = 1; // store total houses receiving at least one present as an integer
        pair<int, int> santa_coords(0,0);
        pair<int, int> robot_coords(0,0);
        list<pair<int,int> > lst;
        lst.push_front(santa_coords);

        ifstream myfile("input.txt"); // stream in the input file
        while (getline (myfile, input)) { // iterate through each line of the input
            for(int i = 0; i < input.length(); i++) { // iterate through each character in the input line
                if (input[i] == '^') {
                    if(i % 2 == 0) {
                        santa_coords.first += 1;
                    } else {
                        robot_coords.first += 1;
                    }
                } if (input[i] == '>') {
                    if(i % 2 == 0) {
                        santa_coords.second += 1;
                    } else {
                        robot_coords.second += 1;
                    }
                } if (input[i] == 'v') {
                    if(i % 2 == 0) {
                        santa_coords.first -= 1;
                    } else {
                        robot_coords.first -= 1;
                    }
                } else if (input[i] == '<') {
                    if(i % 2 == 0) {
                        santa_coords.second -= 1;
                    } else {
                        robot_coords.second -= 1;
                    }
                }
                if(i % 2 == 0) {
                    if(!contains(lst, santa_coords)) {
                        total++;
                        lst.push_front(santa_coords);
                    }
                } else {
                    if(!contains(lst, robot_coords)) {
                        total++;
                        lst.push_front(robot_coords);
                    }
                }
            }
        }

        cout << total << endl;

        myfile.close();
        return 0;
    }

    static bool contains(list<pair<int,int> > lst, pair<int,int> val) {
        pair<int,int> arr[lst.size()];
        copy(lst.begin(), lst.end(), arr);
        for(pair<int,int> i : arr) {
            if(i == val) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    DayThree::part_one();
    DayThree::part_two();
}