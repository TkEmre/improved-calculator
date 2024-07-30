#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<iostream>
#include<string>
using namespace std;
class Stack { 
private:
	int arr[256];
	int top;
public:
	Stack();
	void push(int x);
	int pop();
	int peek();
	bool Empty();

};

class Control:public Stack {
private:
	int arr[256];
	int top;
	string input;
	string output;
	int i;
public:
	bool isoperator(char op);
	int precedence(char op);
	bool Digit(char c);
	bool Space(char c);
	void format(char c);
	bool Parantheses(char c);
};

class Calculator : public Control {
public:
	double calculate(string& expression);
	void operations(Stack& num, char op);
	void applyOperation(Stack& num, char op);
};



#endif /*CALCULATOR_H_*/