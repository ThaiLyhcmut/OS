#include "calc_functions.h"
#include <stdio.h>
double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    if (num2 != 0)
        return num1 / num2;
    else {
        printf("Error: Division by zero\n");
        return 0;
    }
}
