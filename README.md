Age Calculator Readme
This simple C program calculates and displays a person's age based on their birth date. The user is prompted to enter the birth date in the format "Month Day YYYY". The program then converts the month string to an integer, calculates the age, and prints the result.

Table of Contents
Prerequisites
How to Use
Functions
Input Format
Error Handling
Example

Prerequisites
This program is written in C and requires a C compiler to build and run.

How to Use
Compile the program using a C compiler (e.g., gcc).
Run the compiled executable.
Enter the birth date when prompted.

Functions
monthStrToInt

int monthStrToInt(const char *monthStr);
Converts a month string (e.g., "January") to an integer representation (1 for January, 2 for February, etc.).

calculateAge

void calculateAge(int birthMonth, int birthDay, int birthYear);
Calculates the age based on the provided birth month, day, and year.

Input Format
The user is expected to input the birth date in the following format:


Month Day YYYY
For example:

March 15 1990

Error Handling
If the input format is invalid, an error message is displayed, and the program exits with an error code.
If the month string is invalid, an error message is displayed, and the program exits with an error code.

Example
Enter birth date (Month Day YYYY): March 15 1990
Current age: 32 years
