#include <iostream>
#include <cctype>
#include "LinkedStack.h"
using namespace std;

void decimalToBinary(int num);
string stringReversal(string input); // Changed to return string
void symbolBalancing(string seq);
void postfixEvaluation(string exp);
string infixToPostfix(string infix);
string infixToPrefix(string infix);
string postfixToInfix(string postfix);
string prefixToInfix(string prefix);
string postfixToPrefix(string postfix);
string prefixToPostfix(string prefix);
bool check(string input);
int prec(char optr);

int main(int argc, char** argv) {
    int choice;
    int number;
    string input;

    do {
        cout << "Press 1 to convert decimal to binary\n";
        cout << "Press 2 to reverse a string\n";
        cout << "Press 3 to match symbols\n";
        cout << "Press 4 to evaluate postfix expression\n";
        cout << "Press 5 to convert infix to postfix\n";
        cout << "Press 6 to convert infix to prefix\n";
        cout << "Press 7 to convert postfix to infix\n";
        cout << "Press 8 to convert prefix to infix\n";
        cout << "Press 9 to convert postfix to prefix\n";
        cout << "Press 10 to convert prefix to postfix\n";
        cout << "Press 11 to check if string is palindrome\n";
        cout << "Press 0 to exit\n";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Provide a number to convert: ";
                cin >> number;
                decimalToBinary(number);
                break;
            case 2:
                cout << "Provide any string to reverse: ";
                cin >> input;
                cout << stringReversal(input) << endl; // Updated to print returned string
                break;
            case 3:
                cout << "Provide sequence of brackets: ";
                cin >> input;
                symbolBalancing(input);
                break;
            case 4:
                cout << "Provide postfix expression: ";
                cin >> input;
                postfixEvaluation(input);
                break;
            case 5:
                cout << "Provide infix expression: ";
                cin >> input;
                cout << infixToPostfix(input) << endl;
                break;
            case 6:
                cout << "Provide infix expression: ";
                cin >> input;
                cout << infixToPrefix(input) << endl;
                break;
            case 7:
                cout << "Provide postfix expression: ";
                cin >> input;
                cout << postfixToInfix(input) << endl;
                break;
            case 8:
                cout << "Provide prefix expression: ";
                cin >> input;
                cout << prefixToInfix(input) << endl;
                break;
            case 9:
                cout << "Provide postfix expression: ";
                cin >> input;
                cout << postfixToPrefix(input) << endl;
                break;
            case 10:
                cout << "Provide prefix expression: ";
                cin >> input;
                cout << prefixToPostfix(input) << endl;
                break;
            case 11:
                cout << "Provide string to check palindrome: ";
                cin >> input;
                if (check(input))
                    cout << "String is a palindrome\n";
                else
                    cout << "String is not a palindrome\n";
                break;
            case 0:
                exit(-1);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);

    return 0;
}

void decimalToBinary(int num) {
    LinkedStack<int> s1;
    while (num != 0) {
        s1.push(num % 2);
        num = num / 2;
    }
    while (!s1.isEmpty()) {
        cout << s1.pop();
    }
    cout << endl;
}

string stringReversal(string input) {
    LinkedStack<char> s1;
    string reversed = "";
    for (int i = 0; i < input.length(); i++) {
        s1.push(input[i]);
    }
    while (!s1.isEmpty()) {
        reversed += s1.pop();
    }
    return reversed;
}

void symbolBalancing(string input) {
    LinkedStack<char> s1;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
            s1.push(input[i]);
        } else if (input[i] == '}' || input[i] == ']' || input[i] == ')') {
            if (s1.isEmpty()) {
                cerr << "Opening symbol missing\n";
                return;
            } else {
                char p = s1.pop();
                if ((input[i] == '}' && p != '{') ||
                    (input[i] == ']' && p != '[') ||
                    (input[i] == ')' && p != '(')) {
                    cerr << "Symbol mismatch\n";
                    return;
                }
            }
        }
    }
    if (!s1.isEmpty()) {
        cerr << "Closing symbol missing\n";
    } else {
        cout << "Symbols are balanced\n";
    }
}

void postfixEvaluation(string exp) {
    LinkedStack<double> s1;
    for (int i = 0; i < exp.length(); i++) {
        if (isdigit(exp[i])) {
            double d = exp[i] - '0';
            s1.push(d);
        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            double p1 = s1.pop();
            double p2 = s1.pop();
            switch (exp[i]) {
                case '+':
                    s1.push(p2 + p1);
                    break;
                case '-':
                    s1.push(p2 - p1);
                    break;
                case '*':
                    s1.push(p2 * p1);
                    break;
                case '/':
                    s1.push(p2 / p1);
                    break;
            }
        }
    }
    cout << s1.pop() << endl;
}

string infixToPostfix(string infix) 
{
    LinkedStack<char> s1;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) 
    {
        if (isalpha(infix[i]) || isdigit(infix[i])) 
        {
            postfix += infix[i];
        } else if (infix[i] == '(') 
        {
            s1.push(infix[i]);
        } else if (infix[i] == '+' || infix[i] == '/' || infix[i] == '*' || infix[i] == '-') 
        {
            if (s1.isEmpty()) 
            {
                s1.push(infix[i]);
            } else 
            {
                while (!s1.isEmpty() && s1.topValue() != '(' && prec(s1.topValue()) >= prec(infix[i])) 
                {
                    postfix += s1.pop();
                }
                s1.push(infix[i]);
            }
        } else if (infix[i] == ')') 
        {
            while (s1.topValue() != '(') 
            {
                postfix += s1.pop();
            }
            s1.pop();
        }
    }
    while (!s1.isEmpty()) 
    {
        postfix += s1.pop();
    }
    return postfix;
}

int prec(char optr) {
    if (optr == '^')
        return 3;
    else if (optr == '*' || optr == '/')
        return 2;
    else if (optr == '+' || optr == '-')
        return 1;
    return 0;
}

string infixToPrefix(string infix) 
{
    LinkedStack<char> s1;
    string prefix = "";
    infix = stringReversal(infix); 
    for (int i = 0; i < infix.length(); i++) 
    {
        if (isalpha(infix[i]) || isdigit(infix[i])) 
        {
            prefix += infix[i];
        } else if (infix[i] == ')') 
        {
            s1.push(infix[i]);
        } else if (infix[i] == '+' || infix[i] == '/' || infix[i] == '*' || infix[i] == '-') 
        {
            if (s1.isEmpty()) 
            {
                s1.push(infix[i]);
            } else {
                while (!s1.isEmpty() && s1.topValue() != ')' && prec(s1.topValue()) > prec(infix[i])) 
                {
                    prefix += s1.pop();
                }
                s1.push(infix[i]);
            }
        } else if (infix[i] == '(') 
        {
            while (s1.topValue() != ')') 
            {
                prefix += s1.pop();
            }
            s1.pop();
        }
    }
    while (!s1.isEmpty()) 
    {
        prefix += s1.pop();
    }
    return stringReversal(prefix); 
}

string postfixToInfix(string postfix) {
    LinkedStack<string> s1;
    for (int i = 0; i < postfix.length(); i++) {
        if (isalpha(postfix[i]) || isdigit(postfix[i])) {
            string s = "";
            s += postfix[i];
            s1.push(s);
        } else if (postfix[i] == '+' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '-') {
            string p1 = s1.pop();
            string p2 = s1.pop();
            s1.push("(" + p2 + postfix[i] + p1 + ")");
        }
    }
    return s1.pop();
}

string prefixToInfix(string prefix) {
    LinkedStack<string> s1;
    prefix = stringReversal(prefix); // Now works
    for (int i = 0; i < prefix.length(); i++) {
        if (isalpha(prefix[i]) || isdigit(prefix[i])) {
            string s = "";
            s += prefix[i];
            s1.push(s);
        } else if (prefix[i] == '+' || prefix[i] == '/' || prefix[i] == '*' || prefix[i] == '-') {
            string p1 = s1.pop();
            string p2 = s1.pop();
            s1.push(")" + p2 + prefix[i] + p1 + "(");
        }
    }
    return stringReversal(s1.pop()); // Now works
}

string postfixToPrefix(string postfix) {
    string infix = postfixToInfix(postfix);
    string prefix = infixToPrefix(infix);
    return prefix;
}

string prefixToPostfix(string prefix) {
    string infix = prefixToInfix(prefix);
    string postfix = infixToPostfix(infix);
    return postfix;
}


/*
bool check(string input) {
    LinkedStack s;
    string reversed = "";

    // Step 1: Push all characters of the input string onto the stack
    for (int i = 0; i < input.length(); i++) 
    {
        s.push(input[i]);
    }

    // Step 2: Pop characters from the stack to form the reversed string
    while (!s.isEmpty()) 
    {
        reversed += s.pop();
    }

    // Step 3: Compare the reversed string with the original input
    return input == reversed;
}
*/
bool check(string input) 
{
    string reversed = stringReversal(input); // Now works
    return reversed == input;
}