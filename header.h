//
// Created by Jawad Khadra on 9/5/24.
//

#ifndef ASSIGNMENT1_PROTOTYPES_H
#define ASSIGNMENT1_PROTOTYPES_H

#endif //ASSIGNMENT1_PROTOTYPES_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * Member
 * This struct is used to store the name, id, and balance of each person.
 */
struct Member {
    string name;
    int id;
    float balance;
};

/*
 * printHeading
 *
 * This function will print the header of the program to the output file.
 */
void printHeading(fstream &outFile);

/*
 * input
 *
 * This function will read in the input file and store the data in the parallel arrays.
 */
void input(string&, Member[]);

/*
 * searchBalance
 *
 * this function will search for the larger or the smaller
 * balance and return the proper index (of type int) to the calling function. The
 * function uses an input parameter to determine whether it will search for the largest
 * or the smaller balance.
 */
int searchBalance(Member[], int, fstream&);

/*
 * sumAverage
 *
 * This function prompts the user to either return the sum or the average of the balances, and returns a float.
 */
float sumAverage(Member[], int, fstream&);

/*
 * searchName
 * This function prompts the user to enter a name and searches for it in the parallel arrays.
 * If found, it will print the index of the name and also print the person to the output file.
 * If not found, it will print that the name was not found, and input nothing to the output file.
 */
int searchName(Member[], fstream&);