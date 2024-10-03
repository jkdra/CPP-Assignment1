//
// Created by Jawad Khadra on 10/2/24.
//

#include "header.h"


/*
 * input
 *
 * This function will read in the input file and store the data in the parallel arrays.
 */
void input(string& fileName, Member members[]) {
    ifstream inFile(fileName); // IN - file name

    // Check if the file opened successfully
    if (inFile.fail()) {
        cerr << "Error: Could not open the input file." << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++) {
        getline(inFile, members[i].name);
        inFile >> members[i].id >> members[i].balance;
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
int searchBalance(Member members[], int findLargest, fstream& outFile) {
    int size = 10;  // Assuming the size of the array is 10

    // Sort the arrays based on the balances
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((findLargest == 1 && members[i].balance < members[j].balance) || (findLargest == 2 && members[i].balance > members[j].balance)) {
                // Swap balances
                float tempBalance = members[i].balance;
                members[i].balance = members[j].balance;
                members[j].balance = tempBalance;

                // Swap names
                string tempName = members[i].name;
                members[i].name = members[j].name;
                members[j].name = tempName;

                // Swap IDs
                int tempId = members[i].id;
                members[i].id = members[j].id;
                members[j].id = tempId;
            }
        }
    }

    // Output only the first result to the file
    outFile << "\n" << (findLargest == 1 ? "Higher Balance:\n" : "Lower Balance:\n")
            << "ID #     NAME                     BALANCE DUE\n"
            << "----     --------------------     -----------\n";

    outFile << members[0].id << "     " << setw(20) << members[0].name << "     $" << fixed << setprecision(2) << setw(10) << members[0].balance << "\n";

    // Return the index of either the largest or smallest element
    return findLargest == 1 ? 0 : size - 1;
}

/*
 * searchName
 * This function prompts the user to enter a name and searches for it in the parallel arrays.
 * If found, it will print the index of the name and also print the person to the output file.
 * If not found, it will print that the name was not found, and input nothing to the output file.
 */
int searchName(Member members[], fstream& outFile) {
    string searchName;    // IN - name to search for
    bool found = false;   // CALC - whether the name was found
    int index = -1;       // OUT - index of the found name

    outFile << "\nSearch Name:\n"
            << "ID #     NAME                     BALANCE DUE\n"
            << "----     --------------------     -----------\n";

    while (true) {
        cin.ignore(); // Ignore the newline character
        found = false;
        cout << "Who do you want to search for (enter done to exit): ";
        getline(cin, searchName);

        if (searchName == "done") {
            return index;  // Exit and return to the main menu
        }

        for (int i = 0; i < 10; i++) {
            if (members[i].name == searchName) {
                cout << "Found." << endl;
                found = true;

                outFile << members[i].id << "     " << setw(20) << members[i].name << "     $" << fixed << setprecision(2) << setw(10) << members[i].balance << "\n";

                index = i;  // Return the index of the found name
            }
        }

        if (!found) {
            cout << searchName << " was not found." << endl;
            index = -1;
        }
    }
}

/*
 * sumAverage
 *
 * This function prompts the user to either return the sum or the average of the balances, and returns a float.
 */
float sumAverage(Member members[], int returnSum, fstream& outFile) {

    float sum = 0;  // OUTPUT - sum of all balances

    for (int i = 0; i < 10; i++) sum += members[i].balance;

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