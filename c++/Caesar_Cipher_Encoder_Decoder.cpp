#include <iostream>
#include <string>

using namespace std;

// Function to perform Caesar Cipher encoding
string caesarCipher(string str, long long key, bool encode) {
    string result;
    for (char ch : str) {
        char base = isupper(ch) ? 'A' : (islower(ch) ? 'a' : ch);
        if (isalpha(ch)) {
            int offset = encode ? key : -key; // Determine whether to encode or decode
            char newChar = (ch - base + offset + 26) % 26 + base; // Wrap around using modulo
            result += newChar;
        } else {
            result += ch; // Non-alphabetic characters remain unchanged
        }
    }
    return result;
}

// Function to decode the input string
void decode() {
    string in_str;
    cout << "Enter the string to decode: ";
    cin >> in_str;

    char check;
    cout << "Do you have a key? (Y/n): ";
    cin >> check;

    if (tolower(check) == 'y') {
        long long key;
        cout << "Enter key for decryption: ";
        cin >> key;

        if (key < 0) {
            cout << "Key has to be positive!" << endl;
            return;
        }
        cout << "Decoded string is --> " << caesarCipher(in_str, key, false) << endl;
    } else {
        cout << "Bruteforcing all 26 combinations..." << endl;
        for (long long key = 0; key < 26; key++) {
            cout << "Key " << key << " --> " << caesarCipher(in_str, key, false) << endl;
        }
    }
}

// Function to encode the input string
void encode() {
    string str;
    cout << "Enter the string to encode: ";
    cin >> str;

    long long key;
    cout << "Enter key for encryption: ";
    cin >> key;

    if (key < 0) {
        cout << "Key has to be positive!" << endl;
        return;
    }

    cout << "Encoded string is --> " << caesarCipher(str, key, true) << endl;
}

// Main function
int main() {
    cout << "Caesar Cipher Encoder and Decoder" << endl;
    long long option;
    cout << "Modes:\n1. Decode\n2. Encode\n3. Exit\nChosen Mode: ";
    cin >> option;

    switch (option) {
        case 1:
            decode();
            break;
        case 2:
            encode();
            break;
        case 3:
            cout << "Thanks for using! Exiting now." << endl;
            break;
        default:
            cout << "Invalid option! Please choose 1, 2, or 3." << endl;
    }
    
    return 0;
}
