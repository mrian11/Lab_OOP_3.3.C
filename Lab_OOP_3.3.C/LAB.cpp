#include <iostream>
#include "CharLine.h"

using namespace std;

int main()
{
    // Creating instances of CharLine
    CharLine line1(5, "Hello");
    CharLine line2(6, "World!");

    cout << "Count=" << CharLine::Count() << endl;

    // Testing output stream operator <<
    cout << "line1: " << line1 << endl;
    cout << "line2: " << line2 << endl;

    // Testing input stream operator >>
    cout << "Enter a new value for line1 (N and S): ";
    cin >> line1;
    cout << "New line1: " << line1 << endl;

    // Testing assignment operator =
    CharLine line3 = line2;
    cout << "line3 (assigned from line2): " << line3 << endl;

    // Testing comparison operator ==
    cout << "line1 == line2: " << (line1 == line2 ? "true" : "false") << endl;
    cout << "line1 >= line2: " << (line1 >= line2 ? "true" : "false") << endl;
    cout << "line1 <= line2: " << (line1 <= line2 ? "true" : "false") << endl;
    cout << "line1 > line2: " << (line1 > line2 ? "true" : "false") << endl;
    cout << "line1 < line2: " << (line1 < line2 ? "true" : "false") << endl;


    // Testing concatenation operator +
    CharLine line4 = line1 + line2;
    cout << "line1 + line2: " << line4 << endl;

    // Testing subscript operator []
    cout << "Character at position 2 in line1: " << line1[2] << endl;

    // Testing function call operator ()
    char targetChar = 'o';
    cout << "Is '" << targetChar << "' in line2? " << (line2(targetChar) ? "Yes" : "No") << endl;

    // Testing prefix increment and decrement operators ++ and --
    cout << "Before incrementing line1: " << line1 << endl;
    ++line1;
    cout << "After incrementing line1: " << line1 << endl;
    cout << "Before decrementing line1: " << line1 << endl;
    --line1;
    cout << "After decrementing line1: " << line1 << endl;

    // Testing postfix increment and decrement operators ++ and --
    cout << "Before post-incrementing line2: " << line2 << endl;
    CharLine temp1 = line2++;
    cout << "After post-incrementing line2: " << line2 << endl;
    cout << "Temporarily stored value after post-increment: " << temp1 << endl;
    cout << "Before post-decrementing line2: " << line2 << endl;
    CharLine temp2 = line2--;
    cout << "After post-decrementing line2: " << line2 << endl;
    cout << "Temporarily stored value after post-decrement: " << temp2 << endl;

    // Testing custom operator %
    CharLine substring(3, "llo");
    cout << "Is '" << substring.getS() << "' a substring of line1? " << (line1 % substring ? "Yes" : "No") << endl;


	return 0;
}
