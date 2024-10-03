/*
 * AUTHOR : Jawad Khadra
 * STUDENT ID : 1312092 (IVC)
 * ASSIGNMENT #1 : Functions & Arrays
 * CLASS : CS1B
 * SECTION : MW: 7:30p - 9:50p
 * DUE DATE : August 23, 2024
 */

#include "header.h"

using namespace std;

/*
 * Functions & Arrays
 *
 * This program will first receive from the user as input the name of an input file and an output
 * file. It will then read in a list of names, id #s, and balances from the input file specified
 * (call it InFile.txt) and initialized the three parallel arrays. The input file will be created from the
 * data provided below. The program will then execute some tasks using the parallel arrays. The
 * user will interact with the program through menu that allows for the user to select the specific
 * tasks to be executed. Each task will be executed using functions.
 */

// main
int main() {

    // Variables
    Member members[10];  // IN - members of the game
    fstream outFile;     // OUT - output file

    // Print the header on the console for now, while we wait for the output file
    cout
    << " * AUTHOR : Jawad Khadra\n"
    << " * STUDENT ID : 1312092 (IVC)\n"
    << " * ASSIGNMENT #1 : Functions & Arrays\n"
    << " * CLASS : CS1B\n"
    << " * SECTION : MW: 7:30p - 9:50p\n"
    << " * DUE DATE : October 2, 2024\n"
    << " \n";

    // Input
    string inFileName, outFileName;
    cout << "Enter the name of the input file:  ";
    cin >> inFileName;
    cout << "Enter the name of the output file: ";
    cin >> outFileName;

    // Open output file here
    outFile.open(outFileName, ios::out);
    input(inFileName, members);

    // Print the header on both the console and the output file
    printHeading(outFile);

    int choice;  // IN - user choice
    do {
        // Display menu
        cout << "\nMENU OPTIONS\n";
        cout << "1 – Find the larger balance\n";
        cout << "2 – Find the smaller balance\n";
        cout << "3 – Obtain the sum of all balances\n";
        cout << "4 – Obtain the average of all balances\n";
        cout << "5 – Find person\n";
        cout << "0 - Exit\n";
        cout << "Enter an option (0 to exit): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Finding the larger balance…" << endl;
                searchBalance(members, 1, outFile);
                break;
            case 2:
                cout << "Finding the smaller balance…" << endl;
                searchBalance(members, 2, outFile);
                break;
            case 3:
                cout << "Obtaining the sum of all balances…" << endl;
                sumAverage(members, 3, outFile);
                break;
            case 4:
                cout << "Obtaining the average of all balances…" << endl;
                sumAverage(members, 4, outFile);
                break;
            case 5:
                searchName(members, outFile);
                break;
            case 0:
                cout << "Thank you for using my program." << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }

    } while (choice != 0);

    outFile.close();
    return 0;
}
