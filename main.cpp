/*
 * AUTHOR : Jawad Khadra
 * STUDENT ID : 1312092 (IVC)
 * ASSIGNMENT #1 : Functions & Arrays
 * CLASS : CS1B
 * SECTION : MW: 7:30p - 9:50p
 * DUE DATE : August 23, 2024
 */

#include "prototypes.h"

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
    string names[10];
    int ids[10];
    float balances[10];
    fstream outFile;

    cout
    << " * AUTHOR : Jawad Khadra\n"
    << " * STUDENT ID : 1312092 (IVC)\n"
    << " * ASSIGNMENT #1 : Functions & Arrays\n"
    << " * CLASS : CS1B\n"
    << " * SECTION : MW: 7:30p - 9:50p\n"
    << " * DUE DATE : August 23, 2024\n"
    << " \n";

    // Input
    string inFileName, outFileName;
    cout << "Enter the name of the input file:  ";
    cin >> inFileName;
    cout << "Enter the name of the output file: ";
    cin >> outFileName;

    // Open output file here
    outFile.open(outFileName, ios::out);
    input(inFileName, names, ids, balances);

    // Print the header on both the console and the output file
    printHeader(outFile);

    int choice;
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
                searchBalance(balances, names, ids, 1, outFile);
                break;
            case 2:
                cout << "Finding the smaller balance…" << endl;
                searchBalance(balances, names, ids, 2, outFile);
                break;
            case 3:
                cout << "Sum of balances: " << sumAverage(balances, 3, outFile) << endl;
                break;
            case 4:
                cout << "Average of balances: " << sumAverage(balances, 4, outFile) << endl;
                break;
            case 5:
                searchName(balances, names, ids, outFile);
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

/*
 * printHeader
 *
 * This function will print the header of the program to the output file.
 */
void printHeader(fstream& outFile) {

    outFile
    << " * AUTHOR : Jawad Khadra\n"
    << " * STUDENT ID : 1312092 (IVC)\n"
    << " * ASSIGNMENT #1 : Functions & Arrays\n"
    << " * CLASS : CS1B\n"
    << " * SECTION : MW: 7:30p - 9:50p\n"
    << " * DUE DATE : August 23, 2024\n";
}

/*
 * input
 *
 * This function will read in the input file and store the data in the parallel arrays.
 */
void input(string& fileName, string names[], int ids[], float balances[]) {
    ifstream inFile(fileName);

    // Check if the file opened successfully
    if (inFile.fail()) {
        cerr << "Error: Could not open the input file." << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++) {
        getline(inFile, names[i]);
        inFile >> ids[i] >> balances[i];
        inFile.ignore();
    }
    inFile.close();  // Close the file after reading
}

/*
 * searchBalance
 *
 * this function will search for the larger or the smaller
 * balance and return the proper index (of type int) to the calling function. The
 * function uses an input parameter to determine whether it will search for the largest
 * or the smaller balance.
 */
int searchBalance(float balances[], string names[], int ids[], int findLargest, fstream& outFile) {
    int size = 10;  // Assuming the size of the array is 10

    // Sort the arrays based on the balances
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((findLargest == 1 && balances[i] < balances[j]) || (findLargest == 2 && balances[i] > balances[j])) {
                // Swap balances
                float tempBalance = balances[i];
                balances[i] = balances[j];
                balances[j] = tempBalance;

                // Swap names
                string tempName = names[i];
                names[i] = names[j];
                names[j] = tempName;

                // Swap IDs
                int tempId = ids[i];
                ids[i] = ids[j];
                ids[j] = tempId;
            }
        }
    }

    // Output the sorted results to the file
    outFile << "\n" << (findLargest == 1 ? "Larger Balance:\n" : "Smaller Balance:\n")
    << "ID #     NAME                     BALANCE DUE\n"
    << "----     --------------------     -----------\n";

    for (int i = 0; i < size; i++) {
        outFile << ids[i] << "     " << setw(20) << names[i] << "     $" << fixed << setprecision(2) << setw(10) << balances[i] << "\n";
    }

    // Return the index of either the largest or smallest element
    return findLargest == 1 ? 0 : size - 1;
}

/*
 * searchName
 * This function prompts the user to enter a name and searches for it in the parallel arrays.
 * If found, it will print the index of the name and also print the person to the output file.
 * If not found, it will print that the name was not found, and input nothing to the output file.
 */
int searchName(float balances[], string names[], int ids[], fstream& outFile) {
    string searchName;
    bool found = false;

    while (true) {
        cin.ignore(); // Ignore the newline character
        cout << "Who do you want to search for (enter done to exit): ";
        getline(cin, searchName);

        if (searchName == "done") {
            return -1;  // Exit and return to the main menu
        }

        for (int i = 0; i < 10; i++) {
            if (names[i] == searchName) {
                cout << "Found." << endl;
                found = true;

                outFile << "\n"
                        << "Search Name:\n"
                        << "ID #     NAME                     BALANCE DUE\n"
                        << "----     --------------------     -----------\n"
                        << ids[i] << "     " << setw(20) << names[i] << "     $" << fixed << setprecision(2) << setw(10) << balances[i] << "\n";

                return i;  // Return the index of the found name
            }
        }

        if (!found) {
            cout << searchName << " was not found." << endl;
            return -1;
        }
    }
}

/*
 * sumAverage
 *
 * This function prompts the user to either return the sum or the average of the balances, and returns a float.
 */
float sumAverage(float balances[], int returnSum, fstream& outFile) {

    float sum = 0;

    for (int i = 0; i < 10; i++) sum += balances[i];

    if (returnSum == 3) {
        outFile << "\n"
        <<"Sum of balances for all persons:\n"
        << "$ " << fixed << setprecision(2) << setw(10) << sum << "\n";
        return sum;
    }
    else if (returnSum == 4) {
        outFile << "\n"
        <<"Average balance for all persons:\n"
        << "$ " << fixed << setprecision(2) << setw(10) << sum / 10 << "\n";
        return sum / 10;
    }
}