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
    LinkedStack<int> s1;
    s1.push(23);
    s1.push(230);
    s1.push(2);
    s1.removeAll();
    cout<<s1.pop();
    

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
/*
Stack Application-Postfix Evaluation 
1. Create an empty stack of type double 
2. Read input postfix expression char by char till the end of input 
• 2.1. If char is an operand, convert it into its double equivalent 
and then push it on the stack 
• 2.2. If char is an operator then pop two elements from the stack, 
perform the operation and push the result back on the stack. 
3. At the end of input, Pop the final result and display it

*/
void postfixEvaluation(string exp) 
{
    LinkedStack<double> s1;//1.create a stack double
    for (int i = 0; i < exp.length(); i++)//2.read input char by char 
	{
        if (isdigit(exp[i])) //2.1char is an operand
		{
            double d = exp[i] - '0';//convert it into double
            //because every digit has an ASCII value
            //the ASCII value will help us convert char into double
            /*	char c = exp[i];
				string str(1, c); // Create a string with one character
				double d = stod(str)
				*/
            s1.push(d);
        } 
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') 
		{//2.2if char is operator
            double p1 = s1.pop();//pop two operators
            double p2 = s1.pop();
            switch (exp[i]) 
			{//check what is the operator to perform specific operation
			//push the result to stack
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
    cout << s1.pop() << endl;//3
}
/*
Stack Application-(infix-to-postfix conversion) 
1.Create an empty stack of type char and 
string variable to store output postfix expession 
2.Read input expression char by char till the end of input
 2.1.Operand: display it or make it part of output 
 2.2.Opening Parenthesis: push 
 2.3.Operator: 
 2.3.1. If stack is empty then push it 
 2.3.2. If the stack is non-empty and there is no opening bracket,
  pop and display characters while the top operator's precedence is 
  greater than or equal to the current character. 
  After popping, push the current operator onto the stack.          
  2.4.Closing Parenthesis: Pop and display operators from the stack 
  until an opening parenthesis is encountered. 
  Pop the parenthesis but do not display it..
   3.At the end of input, if stack is non-empty, 
   pop operators from stack and display them until the stack becomes empty.
*/

string infixToPostfix(string infix) 
{
    LinkedStack<char> s1;//1.stack of char
    string postfix = "";//string to store output
    for (int i = 0; i < infix.length(); i++) //read input char by char
    {
        if (isalpha(infix[i]) || isdigit(infix[i])) //2.1 (operand)
        {
            postfix += infix[i];//add to output string
        } 
		else if (infix[i] == '(') //2.2(openeing parantheseis )
        {
            s1.push(infix[i]);
        } 
		else if (infix[i] == '+' || infix[i] == '/' || infix[i] == '*' || infix[i] == '-') 
        {//2.3
            if (s1.isEmpty()) //2.3.1(operator but stack is empty)
            {
                s1.push(infix[i]);
            } 
			else //2.3.2 operator but stack is not empty
            {
                while (!s1.isEmpty() && s1.topValue() != '(' 
				&& prec(s1.topValue()) >= prec(infix[i]))
                {
                    postfix += s1.pop();
                }
                s1.push(infix[i]);
            }
        } 
		else if (infix[i] == ')') //2.4 pop until openeing bracket
        {
            while (s1.topValue() != '(') 
            {
                postfix += s1.pop();
            }
            s1.pop();//do not add opening bracket to input string
        }
    }//for (end of input)
    while (!s1.isEmpty()) //3(pop characters from stack )
    {
        postfix += s1.pop();
    }
    return postfix;
}

int prec(char optr) 
{//to check precedence and return a value 
    if (optr == '^')
        return 3;
    else if (optr == '*' || optr == '/')
        return 2;
    else if (optr == '+' || optr == '-')
        return 1;
    return 0;
}
/*
Stack Application-(infix-to-prefix conversion) 
1.Create an empty stack of type char 
2.Create an output string 
3.Reverse the input expression 
4.Read the reversed input expression char by char till the end of input 
4.1.Operand: add to a output string 
4.2.Closing Parenthesis: push 
4.3.Operator: 
4.3.1.If stack is empty then push it 
4.3.2. If the stack is non-empty and there is no closing bracket, 
pop and display characters while the top operator's precedence is 
greater than the current character. 
After popping, push the current operator onto the stack. .
 4.4.Opening Parenthesis: Pop operators from stack and add them to 
 output string until we pop a closing parenthesis which will be popped but
  not be added to output string. 
  5.At the end of input, if stack is non-empty, pop operators from stack 
  and add them to output string until the stack becomes empty. 
  6.Reverse the output string and display it.*/

string infixToPrefix(string infix) 
{
    LinkedStack<char> s1;//1 create a char stack
    string prefix = "";//2 create an output string
    infix = stringReversal(infix);//3 reverse input
    for (int i = 0; i < infix.length(); i++)//read input char by char
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))//4.1:operand add to output
        {
            prefix += infix[i];
        } 
		else if (infix[i] == ')') //4.2:closing bracket push in stack
        {
            s1.push(infix[i]);
        } 
		else if (infix[i] == '+' || infix[i] == '/' || infix[i] == '*' 
		|| infix[i] == '-')//4.3 operator 
        {
            if (s1.isEmpty())//4.3.1 stack is empty push
            {
                s1.push(infix[i]);
            } 
			else 
			{//if stack is not empty 4.3.2
                while (!s1.isEmpty() && s1.topValue() != ')' 
				&& prec(s1.topValue()) > prec(infix[i])) 
                {
                    prefix += s1.pop();
                }
                s1.push(infix[i]);
            }
        } 
		else if (infix[i] == '(') //4.4if input is opening bracket
        {
            while (s1.topValue() != ')') //pop till closing so not add closing
            //bracket to output
            {
                prefix += s1.pop();
            }
            s1.pop();//but do pop closing bracket too
        }
    }
    while (!s1.isEmpty())//5. check and pop all char from stack
    {
        prefix += s1.pop();
    }
    return stringReversal(prefix); //reverse and return
}
/*
Stack Application-(postfix-to-infix conversion) 
1. Create an empty stack of type string 
2. Read the input postfix expression char by char till the end of input 
2.1.If the char is an operand: push it on the stack 
2.2.It the char is operator: Pop two operands from stack form an 
infix sub-expression () and push the sub-expression back on the stack. 
3. At the end of the input pop the resultant infix expression 
from the stack and display it
*/
string postfixToInfix(string postfix) 
{
    LinkedStack<string> s1;//1 create empty string stack
    for (int i = 0; i < postfix.length(); i++) //2.read input char by char
	{
        if (isalpha(postfix[i]) || isdigit(postfix[i])) //2.1
		{//if operand push to stack
            string s = "";
            s += postfix[i];
            s1.push(s);
            //to convert char to string
        } 
		else if (postfix[i] == '+' || postfix[i] == '/' || 
		postfix[i] == '*' || postfix[i] == '-') //2.2.if operator
		{
            string p1 = s1.pop();
            string p2 = s1.pop();
            s1.push("(" + p2 + postfix[i] + p1 + ")");
        }
    }
    return s1.pop();
}
/*Stack Application-(prefix-to-infix conversion) 
1. Create an empty stack of type string 
2.Reverse the input expression 
3.Read the reversed input prefix expression char by char till the end of input 
3.1.If the char is an operand: push it on the stack 
3.2.It the char is operator: 
Pop two operands from stack from an infix sub-expression )( and push the sub-expression back on the stack. 
4. At the end of the input pop the resultant expression from the stack, reverse and display it.*/
string prefixToInfix(string prefix) 
{
    LinkedStack<string> s1;//1.create string stack
    prefix = stringReversal(prefix);//2.reverse input
    for (int i = 0; i < prefix.length(); i++)//3.read reversed input char by char 
	{
        if (isalpha(prefix[i]) || isdigit(prefix[i]))//3.1
		{
            string s = "";
            s += prefix[i];
            s1.push(s);
        } 
		else if (prefix[i] == '+' || prefix[i] == '/' || prefix[i] == '*' 
		|| prefix[i] == '-') //3.2
		{
            string p1 = s1.pop();
            string p2 = s1.pop();
            s1.push(")" + p2 + prefix[i] + p1 + "(");
        }
    }
    return stringReversal(s1.pop()); //4
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