#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to convert month string to integer
int monthStrToInt(const char *monthStr) {
    const char *months[] = {"january", "february", "march", "april", "may", "june", "july",
                            "august", "september", "october", "november", "december"};

    for (int i = 0; i < 12; ++i) {
        if (strcasecmp(monthStr, months[i]) == 0) {
            return i + 1;  // Months are 1-indexed
        }
    }

    return -1;  // Invalid month string
}

// Function to calculate age
void calculateAge(int birthMonth, int birthDay, int birthYear) {
    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Calculate age
    int currentYear = tm.tm_year + 1900;
    int age = currentYear - birthYear;

    // Adjust age based on birth month and day
    if (tm.tm_mon + 1 < birthMonth || (tm.tm_mon + 1 == birthMonth && tm.tm_mday < birthDay)) {
        age--;
    }

    // Print the result
    printf("Current age: %d years\n", age);
}

int main() {
    // Input birth date
    char monthStr[20];
    int birthDay, birthYear;

    printf("Enter birth date (Month Day YYYY): ");
    if (scanf("%s %d %d", monthStr, &birthDay, &birthYear) != 3) {
        printf("Invalid input format. Please enter a valid input.\n");
        return 1;  // Exit with error code
    }

    // Convert month string to lowercase
    for (int i = 0; monthStr[i]; i++) {
        monthStr[i] = tolower(monthStr[i]);
    }

    // Convert month string to integer if necessary
    int birthMonth;
    if (isdigit(monthStr[0])) {
        birthMonth = atoi(monthStr);
    } else {
        birthMonth = monthStrToInt(monthStr);
        if (birthMonth == -1) {
            printf("Invalid month string. Please enter a valid month.\n");
            return 1;  // Exit with error code
        }
    }

    // Calculate and display age
    calculateAge(birthMonth, birthDay, birthYear);

    return 0;
}
