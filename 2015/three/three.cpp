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
        list<pair<int,int> > lst; // use a list of pairs to store coordinates of houses already visited
        lst.push_front(coords); // add the origin to the list of visited coords

        ifstream myfile("input.txt"); // stream in the input file
        while (getline (myfile, input)) { // iterate through each line of the input
            for(char i : input) { // iterate through each character in the input line
                if (i == '^') { // check next character in input, update coordinate accordingly
                    coords.first += 1;
                } if (i == '>') {
                    coords.second += 1;
                } if (i == 'v') {
                    coords.first -= 1;
                } else if (i == '<') {
                    coords.second -= 1;
                }
                if(!contains(lst, coords)) { // if the coordinate is not already visited, increment total and
                    lst.push_front(coords); // add to list of visited coordinates
                    total++;
                }
            }
        }

        cout << total << endl; // output total houses visited

        myfile.close(); // close input file
        return 0;
    }

    static int part_two() {
        string input; // declare a string object to store input lines

        int total = 1; // store total houses receiving at least one present as an integer
        pair<int, int> santa_coords(0,0); // use a pair to store santas current coordinate
        pair<int, int> robot_coords(0,0); // use a pair to store robo-santas current coordinate
        list<pair<int,int> > lst; // use a list to store coordinates already visited
        lst.push_front(santa_coords); // add the origin to visited coordinates

        ifstream myfile("input.txt"); // stream in the input file
        while (getline (myfile, input)) { // iterate through each line of the input
            for(int i = 0; i < input.length(); i++) { // iterate through each character in the input line
                if (input[i] == '^') { // check next character of input string
                    if(i % 2 == 0) { // if it's santas turn to move
                        santa_coords.first += 1; // adjust santas coordinate
                    } else { // if it's robo-santas turn to move
                        robot_coords.first += 1; // adjust robo-santas coordinate
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
                if(i % 2 == 0) { // if it's santas turn
                    if(!contains(lst, santa_coords)) { // if santa's current coordinate has never been visited
                        total++; // increment total
                        lst.push_front(santa_coords); // add santas coordinate to list of visited coords
                    }
                } else { // if it's robo-santas turn
                    if(!contains(lst, robot_coords)) { // if robo-santa's coordinates have never been visited
                        total++; // increment total
                        lst.push_front(robot_coords); // add robo-santas coordinates to list of visited coords
                    }
                }
            }
        }

        cout << total << endl; // output total

        myfile.close(); // close input file
        return 0;
    }

    // function to determine whether a given coordinate has been visited
    static bool contains(list<pair<int,int> > lst, pair<int,int> val) {
        // turn the list of visited coords into an array for ease of use
        pair<int,int> arr[lst.size()];
        copy(lst.begin(), lst.end(), arr);
        // iterate through the list
        for(pair<int,int> i : arr) {
            // check if any array value matches our coordinate value, if so return true
            if(i == val) {
                return true;
            }
        }
        // otherwise return false
        return false;
    }
};

int main() {
    DayThree::part_one();
    DayThree::part_two();
}