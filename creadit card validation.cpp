#include <iostream>
#include <cstring>
using namespace std;

int getLength(const char* cardNumber) {
    return strlen(cardNumber);
}

int toDigit(char ch) {
    return ch - '0';
}

bool isValidCreditCard(const char* cardNumber) {
    int n = getLength(cardNumber);
    int sum = 0;
    bool doubleDigit = false;

    for (int i = n - 1; i >= 0; i--) {
        int digit = toDigit(cardNumber[i]);
        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }
    return (sum % 10 == 0);
}

int main() {
    char cardNumber[20];
    cin >> cardNumber;

    if (isValidCreditCard(cardNumber)) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }

    return 0;
}
