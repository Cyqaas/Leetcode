using namespace std;
#include <string>
#include <iostream>
#include <algorithm>

string addBinary(string a, string b)
{
    // initializing variables
    // temp will have two functions:
    // 1) Do the addition between two binary digits
    // 2) Act as the carry over from the addition of the two binary digits
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;
    string result = "";

    // iterate until a string is empty, b string is empty, and the temp value is 0
    while (size_a >= 0 || size_b >= 0 || temp == 1)
    {
        // get the decimal representation of a and b binary digits to perform modular action
        // 0 otherwise to not affect the result.
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);

        // char(temp % 2) + '0' is going to be either 0 or 1 depending on whether or not the variable
        // is even or odd. The + '0' is necessary in this case as we subtracted it before to get the
        // decimal value and need to add it back to get the character value
        result = char(temp % 2 + '0') + result;

        // dividing the temp variable (which is either 0 or 1) will add redundancy and ensure the
        // carry over is either 0 or 1.
        temp /= 2;
        size_a--;
        size_b--;
    }

    return result;
}

int main()
{
    int temp = 48 + 48;
    cout << char(temp % 2 + '0');
    return 0;
}