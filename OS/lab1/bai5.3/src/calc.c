#include <stdio.h>
#include "calc_functions.h"

int main() {
    char operation;
    double num1, num2, result;

    printf("Enter an operation (+, -, *, /): ");
    scanf("%c", &operation);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    printf("Result: %.2lf\n", result);

    return 0;
}
