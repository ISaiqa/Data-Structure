#include <iostream>
#include "Stack.h"
#include <ctype.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void decimalToBinary(int number);
void stringReversal(string text);
bool symbolBalancing(string seq);
void postfixEvaluation(string exp);

int main(int argc, char** argv) {
	int choice;
	int number;
	string input;
	do
	{
	
	cout<<"Press 1 to convert decimal to binary \n";
	cout<<"Press 2 to reverse a string \n";
	cout<<"Press 3 to match symbols \n";
	cout<<"Press 4 to evaluate postfix expression \n";
	cout<<"Press 0 to exit \n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"Provide number to convert \n";
			cin>>number;
			decimalToBinary(number);
			break;
		case 2:
			cout<<"Provide string to reverse \n";
			cin>>input;
			stringReversal(input);
			break;
		case 3:
			cout<<"Provide sequence to match \n";
			cin>>input;
			cout<<"is sequence balance :"<<symbolBalancing(input);
			break;
		case 4:
			cout<<"Provide postfix expression \n";
			cin>>input;
			postfixEvaluation(input);
			break;
		case 0:
			exit(-1);
	}//switch
	
}//do
while(true);
	return 0;
}//main

void decimalToBinary(int number)
{
	Stack<int> s1(4);
	while(number!=0)
	{
		s1.push(number%2);
		number=number/2;
	}
	
	while(!s1.isEmpty())//keep on iterating if stack is non-empty
	{
	     cout<<s1.pop();	
	}
}//decimalToBinary

void stringReversal(string input)
{
	Stack<char> s1(input.length());
	
	for(int i=0;i<input.length();i++)
	{
		s1.push(input[i]);
	}
	
	while(!s1.isEmpty())//keep on iterating if stack is non-empty
	{
	     cout<<s1.pop();	
	}
	
}//void stringReversal(string input)


bool symbolBalancing(string text)
{
	Stack<char> s1(text.length());
	
	for(int i=0;i<text.length();i++)
	{
		if(text[i]=='(' || text[i]=='[' || text[i]=='{')
		{
			s1.push(text[i]);
		}
		else if(text[i]==')' || text[i]==']' || text[i]=='}')
		{
			if(s1.isEmpty())//non-empty
			{
				cout<<"Opening Symbol is Missing\n";
				return false;
			}
			else
			{
				char p1=s1.pop();
				if(
				(  p1=='(' && text[i]!=')'  ) ||
				(  p1=='{' && text[i]!='}'  ) ||
				(  p1=='[' && text[i]!=']'  )
				)
				{
					cout<<"Symbol Mismatch \n";
					return false;
				}//mismatch
				
			}//non-empty
			
		}//closing symbol
		
	}//loop
	if(s1.isEmpty())//non-empty
	{
			cout<<"Symbols are balanced \n";
			return true;
	}
	else
	{
		cout<<"Closing Symbol is missing\n";
		return false;	
	
	}
}//validateWords

void postfixEvaluation(string exp)
{
	Stack<double> s1(exp.length());//1
	
	for(int i=0;i<exp.length();i++)//2 to read char by char
	{
		if(isdigit(exp[i]))//operand 2.1
		{
			char c=exp[i]; //'5'
			double d= c-'0'; //'5'-'0' -> 53-48= 5
			s1.push(d);
		}
		else if(exp[i]=='*' || exp[i]=='/' || exp[i]=='+' || exp[i]=='-')//operator 2.2
		{
			double p1=s1.pop();
			double p2=s1.pop();
			
			switch(exp[i])
			{
				case '+':
					s1.push(p2 + p1);
					break;
				case '/':
					s1.push(p2 / p1);
					break;
				case '-':
					s1.push(p2 - p1);
					break;
				case '*':
					s1.push(p2 * p1);
					break;
			}//switch
			
		}
	}//for
	cout<<s1.pop()<<endl;//final asnwer
}//void postfixEvaluation(string exp)
