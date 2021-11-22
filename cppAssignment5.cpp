// cppAssignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Nedim Basic
//CPP Assignment 5
//21st of November, 2021

#include <iostream>

//define constants
const float xxxsmallcost = 10.0f;
const float smallCost = 175.0f;
const float mediumCost = 190.0f;
const float largeCost = 200.0f;

//use the standard namespace
using namespace std;

//this function displays the menu
void ShowUsage() {
    cout << "[S] - display program usage" << endl;
    cout << "[P] - purchase a surfboard" << endl;
    cout << "[C] - display current purchases" << endl;
    cout << "[T] - display total amount due" << endl;
    cout << "[Q] - quit the program" << endl;
    cout << endl;
}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS) {
    //declare variables
    char userSelection = 0;
    unsigned int userQuantity = 0; //use an unsigned int to make sure the user enters a positive number

    //display the menu
    cout << "[X] - Extra Extra Extra Small" << endl;
    cout << "[S] - Small"  << endl;
    cout << "[M] - Medium" << endl;
    cout << "[L] - Large" << endl;
    cout << "Please enter the type of surfboard you want to purchase" << endl;
    cin >> userSelection; //get input from the user

    //using a switch statement, determine the user's selection
    switch (userSelection) {
    case 'X':
    case 'x':
        cout << "Please enter the quantity" << endl;
        cin >> userQuantity;
        iTotalXXXS += userQuantity; //add to the total small count
        break;
    case 'S':
    case 's':
        cout << "Please enter the quantity" << endl;
        cin >> userQuantity;
        iTotalSmall += userQuantity; //add to the total small count
        break;
    case 'M':
    case 'm':
        cout << "Please enter the quantity" << endl;
        cin >> userQuantity;
        iTotalMedium += userQuantity; //add to the total medium count
        break;
    case 'L':
    case 'l':
        cout << "Please enter the quantity" << endl;
        cin >> userQuantity;
        iTotalLarge += userQuantity; //add to the total large count
        break;
    default:
        cout << "Unknown selection, no purchase was made" << endl;
        return;
    }

    cout << "Thank you for your purchase!" << endl;
}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int& iTotalXXXS) {
    //if no purchases were made, then return
    if (iTotalSmall + iTotalMedium + iTotalLarge + iTotalXXXS == 0) {
        cout << "No purchases were made yet." << endl;
        return;
    }

    //if the total is not 0, then display the amount of surfboards were purchased
    //Since this is a one line command, you do not need the curley brackets for the 'if' statement
    if (iTotalXXXS != 0) cout << "The total number of xxx-small surfboards is: " << iTotalXXXS << endl;
    if (iTotalSmall != 0) cout << "The total number of small surfboards is: " << iTotalSmall << endl;
    if (iTotalMedium != 0) cout << "The total number of medium surfboards is: " << iTotalMedium << endl;
    if (iTotalLarge != 0) cout << "The total number of large surfboards is: " << iTotalLarge << endl;
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int& iTotalXXXS) {
    //if the total number of boards is zero, then display no purchases were made
    if (iTotalSmall + iTotalMedium + iTotalLarge + iTotalXXXS == 0) {
        cout << "No purchases were made yet." << endl;
        return;
    }

    float totalCost = 0.0f;

    //display the total cost of each type of board purchased.
    if (iTotalXXXS != 0) cout << "The total number of xxx-small surfboards is " << iTotalXXXS << " at a total of $" << (iTotalXXXS * xxxsmallcost) << endl;
    if (iTotalSmall != 0) cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << (iTotalSmall * smallCost) << endl;
    if (iTotalMedium != 0) cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << (iTotalMedium * mediumCost) << endl;
    if (iTotalLarge != 0) cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << (iTotalLarge * largeCost) << endl;

    //calculate totalcost
    totalCost += iTotalXXXS * xxxsmallcost;
    totalCost += iTotalSmall * smallCost;
    totalCost += iTotalMedium * mediumCost;
    totalCost += iTotalLarge * largeCost;

    //display the totalcost
    cout << "Total Amount Due: $" << totalCost << endl;
}

int main()
{
    //declare variables
    int xxxsmallPurchases = 0;
    int smallPurchases = 0;
    int mediumPurchases = 0;
    int largePurchases = 0;
    char userSelection = ' ';

    //display the welcoming message
    cout << "****************************************************" << endl;
    cout << "***Welcome to Johnny Utah's Point Break Surf Shop***" << endl;
    cout << "****************************************************" << endl;
    cout << endl;

    //show the usage
    ShowUsage();

    //while the user's input is not 'Q' or 'q', keep the loop running
    while (userSelection != 'Q' && userSelection != 'q') {
        cout << "Please enter your selection: ";
        cin >> userSelection;

        //using a switch statement, find out what the user selected and run the appropriate command
        switch (userSelection) {
        case 'S':
        case 's':
            ShowUsage();
            break;
        case 'P':
        case 'p':
            MakePurchase(smallPurchases, mediumPurchases, largePurchases, xxxsmallPurchases);
            break;
        case 'C':
        case 'c':
            DisplayPurchase(smallPurchases, mediumPurchases, largePurchases, xxxsmallPurchases);
            break;
        case 'T':
        case 't':
            DisplayTotal(smallPurchases, mediumPurchases, largePurchases, xxxsmallPurchases);
            break;
        case 'Q':
        case 'q':
            break;
        default:
            cout << "Unknown selection" << endl;
            //if the user enters an unknown selection, then do nothing and run the next iteration of the loop
        }
    }

    //display the exiting message
    cout << "Thank you for using this program!" << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
