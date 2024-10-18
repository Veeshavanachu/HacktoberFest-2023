#include <iostream>
using namespace std;

bool checkKaprekar(int number, int base) {
    // Negative numbers or base <= 1 are invalid inputs
    if (number < 0 || base <= 1) {
        return false;
    }
    
    // Calculate the square of the number
    long long squared = static_cast<long long>(number) * number;
    
    // Initialize divisor as 1 and increase it based on the base
    long long divisor = 1;
    
    // Find the divisor such that squared/divisor gives us the left part
    while (squared / divisor >= base) {
        divisor *= base;
    }
    
    // Loop through all possible splits of the number
    while (divisor > 0) {
        long long left = squared / divisor;  // Left part of the split
        long long right = squared % divisor; // Right part of the split
        
        // Check if the left + right equals the original number and right part is non-zero
        if (left + right == number && right > 0) {
            return true;
        }
        
        // Reduce the divisor
        divisor /= base;
    }
    
    return false;
}

int main() {
    int number, base;
    
    // Input: Number and base from the user
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the base: ";
    cin >> base;
    
    // Check if the number is a Kaprekar number in the specified base
    if (checkKaprekar(number, base)) {
        cout << number << " is a Kaprekar number in base " << base << "." << endl;
    } else {
        cout << number << " is not a Kaprekar number in base " << base << "." << endl;
    }

    return 0;
}
