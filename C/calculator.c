#include <stdio.h>

// Function declarations
void displayMenu();
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
int modulus(int num1, int num2);

int main() {
    double num1, num2, result;
    int choice;
    int intNum1, intNum2; // For modulus operation

    while (1) {
        displayMenu(); // Show the menu

        printf("\nEnter your choice (1-5) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Ensure modulus operation is done with integers
        if (choice == 5) {
            printf("Enter two integers for modulus operation:\n");
            printf("First number: ");
            scanf("%d", &intNum1);
            printf("Second number: ");
            scanf("%d", &intNum2);

            result = modulus(intNum1, intNum2);
            printf("Result: %d %% %d = %d\n", intNum1, intNum2, (int)result);
        } else {
            // For all other operations
            printf("Enter two numbers:\n");
            printf("First number: ");
            scanf("%lf", &num1);
            printf("Second number: ");
            scanf("%lf", &num2);

            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                    break;
                case 2:
                    result = subtract(num1, num2);
                    printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                    break;
                case 3:
                    result = multiply(num1, num2);
                    printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                    break;
                case 4:
                    if (num2 != 0) {
                        result = divide(num1, num2);
                        printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                    } else {
                        printf("Error! Division by zero is not allowed.\n");
                    }
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n\nSimple Calculator\n");
    printf("-------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("0. Exit\n");
}

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
    return num1 / num2;
}

// Function for modulus operation
int modulus(int num1, int num2) {
    return num1 % num2;
}
