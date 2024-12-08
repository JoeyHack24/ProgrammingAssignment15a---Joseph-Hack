// ProgrammingAssignment15a - Joseph Hack.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Joseph Hack
// CIS1202
// December 8, 2024

#include <iostream>
#include <exception>
#include <string>

using namespace std;


//Custom Invalid Character Exception 
class InvalidCharacterException : public exception {

private:
    string message;
public:

    InvalidCharacterException(const char* msg) : message(msg) {}

    const char* what() const throw() {
        return message.c_str();
    }
};

//Custom Invalid Character Exception
class InvalidRangeException : public exception {

private:
    string message;
public: 

    InvalidRangeException(const char* msg) : message(msg) {}

    const char* what() const throw() {
        return message.c_str();
    }
};

char character(char start, int offset);


int main()
{
    try {
        cout << "character('a', 1) " << character('a', 1) << endl;
    }
    catch (InvalidCharacterException e) {
        cout << e.what();
    }
    catch (InvalidRangeException e) {
        cout << e.what();

    }

    try {
        cout << "character('a', -1) " << character('a', -1) << endl;
    }
    catch (InvalidCharacterException e) {
        cout << e.what();
    }
    catch (InvalidRangeException e) {
        cout << e.what();

    }

    try {
        cout << "character('Z', -1) " << character('Z', -1) << endl;
    }
    catch (InvalidCharacterException e) {
        cout << e.what();
    }
    catch (InvalidRangeException e) {
        cout << e.what();

    }

    try {
        cout << "character('?', 5) " << character('?', 5) << endl;
    }
    catch (InvalidCharacterException e) {
        cout << e.what();
    }
    catch (InvalidRangeException e) {
        cout << e.what();

    }

}

//Character function for starting at an alphabetic value and applying an offset to produce a new alphabetic value
char character(char start, int offset) {

    char target;

    //Checks if starting value is an alphabetic value
    if(!isalpha(start)) {
        throw InvalidCharacterException("Invalid Character\n");
    } 

    target = start + offset;

    //Checks if resulting value is an alphabetic value
    if (!isalpha(target)) {
        throw InvalidRangeException("Target out of range\n");
    }

    return target;

}