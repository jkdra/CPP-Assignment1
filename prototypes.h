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

void printHeader(fstream&);
void input(string&, string[], int[], float[]);
int searchBalance(float[], string[], int[], int, fstream&);
float sumAverage(float[], int, fstream&);
int searchName(float[], string[], int[], fstream&);