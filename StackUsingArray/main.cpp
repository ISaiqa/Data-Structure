#include <iostream>
#include "Stack.h"
#include <ctype.h>
using namespace std;

void decimalToBinary(int num);
string stringReversal(string input);
void symbolBalancing(string seq);
void postfixEvaluation(string exp);//postfix expression
string infixToPostfix(string infix);// it will return postfix
int prec(char optr); // we will pass an operator it will return number indicating its precedance level
string infixToPrefix(string infix);// it will return prefix
string postfixToInfix(string postfix);//return an infix
string prefixToInfix(string prefix);
string postfixToPrefix(string postfix);
string prefixToPostfix(string prefix);
bool check (string input);


int main(int argc, char** argv) {
	
	int choice;
	int number;
	string input;
	
	do
	{/*
	cout<<"Press 1 to convert decimal to binary \n";
	cout<<"Press 2 to reverse a string \n";
	cout<<"Press 3 to match symbols \n";
	cout<<"Press 4 to evaluate postfix expression \n";
	cout<<"Press 0 to exit \n";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"Provide a number to convert \n";
			cin>>number;
			decimalToBinary(number);
			break;
		case 2:
			cout<<"Provide any string to reverse \n";
			cin>>input;
			cout<<stringReversal(input);
			break;
		case 3:
			cout<<"Provide sequence of brackets \n";
			cin>>input;
			symbolBalancing(input);
			break;
		case 4:
			cout<<"Provide postfix expression \n";
			cin>>input;
			postfixEvaluation(input);
			break;
		case 0:
			exit(-1);*/
//	}//switch



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
                cout << "Provide a number to convert\n";
                cin >> number;
                decimalToBinary(number);
                break;
            case 2:
                cout << "Provide any string to reverse\n";
                cin >> input;
                cout << stringReversal(input) << endl;
                break;
            case 3:
                cout << "Provide sequence of brackets\n";
                cin >> input;
                symbolBalancing(input);
                break;
            case 4:
                cout << "Provide postfix expression\n";
                cin >> input;
                postfixEvaluation(input);
                break;
            case 5:
                cout << "Provide infix expression\n";
                cin >> input;
                cout << infixToPostfix(input) << endl;
                break;
            case 6:
                cout << "Provide infix expression\n";
                cin >> input;
                cout << infixToPrefix(input) << endl;
                break;
            case 7:
                cout << "Provide postfix expression\n";
                cin >> input;
                cout << postfixToInfix(input) << endl;
                break;
            case 8:
                cout << "Provide prefix expression\n";
                cin >> input;
                cout << prefixToInfix(input) << endl;
                break;
            case 9:
                cout << "Provide postfix expression\n";
                cin >> input;
                cout << postfixToPrefix(input) << endl;
                break;
            case 10:
                cout << "Provide prefix expression\n";
                cin >> input;
                cout << prefixToPostfix(input) << endl;
                break;
            case 11:
                cout << "Provide string to check palindrome\n";
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
}//do
while(true);
	return 0;
}//main

void decimalToBinary(int num)
{
	Stack<int> s1(4);//0-15
	
	while(num!=0)
	{
		s1.push(num % 2);
		num=num/2;
	}
	
	while(!s1.isEmpty())//s1.isEmpty()!=true
	{
		cout<<s1.pop();
	}
	cout<<endl;
}//decimalToBinary

string stringReversal(string input)
{
	Stack<char> s1(input.length());
	string reverseInput="";
	for(int i=0;i<input.length();i++)//read string char by char
	{
		s1.push(input[i]);
	}//for
	while(!s1.isEmpty())//s1.isEmpty()!=true
	{
		reverseInput+=s1.pop();
	}
	return reverseInput;
	 
}//void stringReversal(string input)


void symbolBalancing(string input)
{
	Stack<char> s1(input.length());
	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='{' || input[i]=='[' || input[i]=='(')//opening 2.1
		{
			s1.push(input[i]);
		}
		else if(input[i]=='}' || input[i]==']' || input[i]==')')//closing 2.2
		{
			if(s1.isEmpty())//empty
			{
				cerr<<"Opening symbol missing \n"	;
				return;
			}
			else//non-empty
			{
				char p=s1.pop();
				if(( input[i]=='}' && p!='{') ||
				   ( input[i]==']' && p!='[')  ||
				   ( input[i]==')' && p!='('))
				   {
				   	 cerr<<"Symbol mismatch \n";
				   	 return;
				   }
			}
		}
	}//for
	if(!s1.isEmpty())//non-empty
	{
		cerr<<"Closing symbol missing \n";
		return;
	}
	else//empty
	{
		cout<<"Symbols are balanced \n";
	}
}//void symbolBalancing(string seq)

void postfixEvaluation(string exp)
{
	Stack<double> s1(exp.length());//1
	
	for(int i=0;i<exp.length();i++)//2
	{
		if(isdigit(exp[i]))//operand 2.1
		{
			char c=exp[i];
			double d= c - '0';// '9' - '0' (57 - 48 =9)
			s1.push(d);
		}
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')//operator 2.2
		{
			double p1=s1.pop();
			double p2=s1.pop();
			
			switch(exp[i])
			{
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
			}//switch
		}
	}//for
	
	cout<<s1.pop()<<endl;
	
}//void postfixEvaluation(string exp)


string infixToPostfix(string infix)
{
	Stack<char> s1(infix.length());
	string postfix=""; //output
	
	for(int i=0;i<infix.length();i++)// 2
	{
		if(isalpha(infix[i]) || isdigit(infix[i]))//operand 2.1
		{
			//postfix=postfix+infix[i]; i=i+1=> i+=1
			postfix+=infix[i];
		}//2.1
		else if(infix[i]=='(')//opening bracket 2.2
		{
			s1.push(infix[i]);
		}//2.2
		else if(infix[i]=='+' || infix[i]=='/' || infix[i]=='*' || infix[i]=='-')//operator 2.3
		{
			if(s1.isEmpty())//empty 2.3.1
			{
				s1.push(infix[i]);// +, -, *, /
			}
			else //non-empty 2.3.2
			{
				while( !s1.isEmpty() && s1.topValue()!='(' && prec(s1.topValue()) >= prec(infix[i]) )
				{
					postfix+=s1.pop();
				}//while
				s1.push(infix[i]);
			}
		}//2.3
		else if(infix[i]==')')//closing 2.4
		{
			while(s1.topValue()!='(')
			{
				postfix+=s1.pop();
			}
			s1.pop();
		}//2.5
	}// for 2
	
	//if(!s1.isEmpty())//there are 1 or more than one char in s1
	//{
		while(!s1.isEmpty())//terminate when s1 will become empty
		{
			postfix+=s1.pop();
		}
	//}
	
	return postfix;
}//string infixToPostfix(string infix)

int prec(char optr)
{
	if(optr=='^')
		return 3;
	else if(optr=='*' || optr=='/')
		return 2;
	else if(optr=='+' || optr=='-')
		return 1;
}//prec


string infixToPrefix(string infix)
{
	Stack<char> s1(infix.length());
	string prefix=""; //output
	
	infix=stringReversal(infix);
	
	
	for(int i=0;i<infix.length();i++)// 2
	{
		if(isalpha(infix[i]) || isdigit(infix[i]))//operand 2.1
		{
			//postfix=postfix+infix[i]; i=i+1=> i+=1
			prefix+=infix[i];
		}//2.1
		else if(infix[i]==')')//opening bracket 2.2
		{
			s1.push(infix[i]);
		}//2.2
		else if(infix[i]=='+' || infix[i]=='/' || infix[i]=='*' || infix[i]=='-')//operator 2.3
		{
			if(s1.isEmpty())//empty 2.3.1
			{
				s1.push(infix[i]);// +, -, *, /
			}
			else //non-empty 2.3.2
			{
				while( !s1.isEmpty() && s1.topValue()!=')' && prec(s1.topValue()) > prec(infix[i]) )
				{
					prefix+=s1.pop();
				}//while
				s1.push(infix[i]);
			}
		}//2.3
		else if(infix[i]=='(')//closing 2.4
		{
			while(s1.topValue()!=')')
			{
				prefix+=s1.pop();
			}
			s1.pop();
		}//2.5
	}// for 2
	
	//if(!s1.isEmpty())//there are 1 or more than one char in s1
	//{
		while(!s1.isEmpty())//terminate when s1 will become empty
		{
			prefix+=s1.pop();
		}
	//}
	
	return stringReversal(prefix);
}//string infixToPrefix(string infix)


string postfixToInfix(string postfix)
{
	Stack<string> s1(postfix.length());
	
	for(int i=0;i<postfix.length();i++)
	{
		if(isalpha(postfix[i]) || isdigit(postfix[i]))//operand
		{
			string s;// s=empty
			s+=postfix[i];// s=epmty+postfix[i]=>postfix[i]
			s1.push(s);
		}
		else if(postfix[i]=='+' || postfix[i]=='/' || postfix[i]=='*' || postfix[i]=='-')//operator
		{
			string p1=s1.pop();
			string p2=s1.pop();
			
			s1.push("("+p2 + postfix[i]+p1+")");
		}
	}//for
	
	return s1.pop();
}//string postfixToInfix(string postfix)

string prefixToInfix(string prefix)
{
	Stack<string> s1(prefix.length());
	
	prefix=stringReversal(prefix);
	
	for(int i=0;i<prefix.length();i++)
	{
		if(isalpha(prefix[i]) || isdigit(prefix[i]))//operand
		{
			string s;// s=empty
			s+=prefix[i];// s=epmty+postfix[i]=>postfix[i]
			s1.push(s);
		}
		else if(prefix[i]=='+' || prefix[i]=='/' || prefix[i]=='*' || prefix[i]=='-')//operator
		{
			string p1=s1.pop();
			string p2=s1.pop();
			
			s1.push(")"+p2 + prefix[i]+p1+"(");
		}
	}//for
	
	return stringReversal(s1.pop());
}//string prefixToInfix(string prefix)


/*string postfixToPrefix(string postfix)
{
	string infix=postfixToInfix(postfix);
	string prefix=infixToPrefix(infix);
	retrun prefix;
}//*/

string postfixToPrefix(string postfix)
{
	string infix=postfixToInfix(postfix);
	string prefix=infixToPrefix(infix);
	return prefix;
}
string prefixToPostfix(string prefix)
{
	string infix=prefixToInfix(prefix);
	string postfix=infixToPostfix( infix);
	return postfix;
}
bool check(string input)
{
	string reversed=stringReversal(input);
	if(reversed==input)
	{
		return true;
	}
	else 
		return false;
}

