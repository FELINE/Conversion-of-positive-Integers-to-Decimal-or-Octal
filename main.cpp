//
//  main.cpp
//  Conversion of a positive integers to Decimal, Octal, Hexadecimal and Binary - CPSC1155 Lab 6
//
//  Created by Tomás González on 2016-10-20.
//  Copyright © 2016 Tomás González. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <iomanip>
//#include <AppKit/AppKit.h> //To allow the kit to play sound in OSX
using namespace std;
int number;
void announce ();
void instruction ();
void convertion (int);
void decimal (int);
void octal (int);
void hex (int);
void binary (int);

// First of all we greet the user
void announce () {
    cout << "Welcome to Conversion of a positive integers to Decimal, Octal, Hexadecimal and Binary - CPSC1155 Lab 6" << endl;
}

// Then we print the instructions for the user
void instruction () {
    cout << "Enter a positive Decimal Integer (<=65,535, -1 quits): ";
}

void convertion (int number) {
    cout << "Input:" << setw(14) << number << endl;
    decimal(number);
    octal(number);
    hex(number);
    binary(number);
}

void decimal(int number) {
    /* Here we are gonna transform the number into a string, then we will grab this decimal string and we will declare an int variable who will have the first 3 digits of variable number, a string "," and then the rest of the number all concatenated using the insertion method to rewrite it. E.g.: 1000 is now 1,000 (1 + "," + 000) */
        string decimal = to_string(number);
        int insertComma = decimal.length() - 3;
        while (insertComma > 0) {
            decimal.insert(insertComma, ",");
            insertComma-=3;
        }
        cout << "Decimal-10:" << setw(10) << decimal << endl;
}
    // here we are gonna transform our decimal value into octal dividing the number by 8 subsequently till we get a number that is less than 0.
void octal (int number) {
    int octal = 0;
    int remainder;
    int i=1;
    while(number > 0)
    {
            // In this section while the number is bigger than 0 we will divide it by 8 to get a sequence of reminders. Then we will save that value to get it alligned from left to right considering the last reminder the starting value, again from left to right.
        remainder = number % 8;
        number /= 8;
        octal+=remainder*i;
        i*=10;
    }
    cout << "Octal-8:" << setw(12) << octal << endl;
}

// Here basically we will repeat the process but also we will transform the result into a character so we can have a different approach than the switch version in where we assign temporal values and then we add numbers so we can get the letters (from A to F) we need. At the end we create a inverse counter-display to put every part of the hexadecimal number in order
void hex (int number) {
    int quotient;
    int i=1,j,temp;
    char hexNumber[100];

    quotient = number;

    while(quotient!=0)
    {
        temp = quotient % 16;

        //To convert integer into character
        if( temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;

            hexNumber[i++]= temp;
            quotient = quotient / 16;
    }
        cout << "Hexadecimal-16: ";
        for(j = i -1 ;j> 0;j--) //to display the right value cause the algorithm actually writes it backwards
            cout << hexNumber[j];
        cout << endl;
}

void binary (int number) {
    int binary = 0;
    int remainder;
    int i=1;
    while(number != 0)
    {
        // In this section while the number is bigger than 0 we will divide it by 2 to get a sequence of reminders. Then we will save that value to get it alligned from left to right considering the last reminder the starting value, again from left to right giving a result of 0 and 1s.
        remainder = number % 2;
        number /= 2;
        binary += remainder * i;
        i *= 10;
    }
    cout << "Binary-2: " << setw(11) << binary << endl; //I noticed when I go further than 1000 in my input number this function behaves in a weird manner. Probably cause the number is way too long.
}

int main() {

    // We call our functions to greet and give the instructions
    announce();
    instruction();
    // Here we are gonna ask the user to enter a the value
    cin >> number;

    // In this step we gave the chance to exit the program as first evaluation
    if (number == -1) {
        cout << "Quitting on user request" << endl;
    }

    // The next is to evaluate if its a valid input asking if the values are in the right range. As long as they are outside (less than -1 and bigger than 65,535 integer values) the program will keep asking the user to enter a valid input
    if ((number < -1) && (number > 65535)) {
            //void NSBeep (void); //This will enable a Beep from default from the API
            do {
                cout << "Please enter a number between 0 and 65,535: ";
                cin >> number;
            }
        while ((number < 0) && (number > 65535));}

    // If the input is valid then we proceed to do the convertion
    else {
        convertion(number); //we will call convertion who actually calls the transformation functions and passes the input by value
    }

    return 0;
}
