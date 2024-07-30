#include "Calculator.h"

bool Control::isoperator(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}
int Control::precedence(char op) {
	if (op == '+' || op == '-')  return 1;
	else if (op == '*' || op == '/') return 2;
	return 0;
}
bool Control::Digit(char c) {
	return c >= '0' && c <= '9';
}
bool Control::Space(char c) {
	return c == ' ';
}
void Control::format(char c) {
	if (c >= 'a' && c <= 'z') {
		cout << "Please dont enter a z";
	}
}

Stack::Stack() : top(-1) {}

void Stack::push(int x) {
	if (top < 255) {
		arr[++top] = x;
	}
}
int Stack::pop() {
	if (top >= 0) {
		return arr[top--];
	}
}
int Stack::peek() {
	if (top >= 0) {
		return arr[top];
	}
}
bool Stack::Empty() {
	return top == -1;
}

double Calculator::calculate(string& expression) {
	Stack values;
	Stack ops;
	Control c1;
	Calculator e1;

	for (int i = 0; i < expression.length(); i++) {
		if (c1.Space(expression[i])) continue;

		if (c1.Digit(expression[i])) {
			int value = 0;
			while (i < expression.length() && isdigit(expression[i])) {
				value = value * 10 + (expression[i] - '0');
				i++;
			}
			values.push(value);
			i--;
		}
		else if (expression[i] == '(') { 
			ops.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while (!ops.Empty() && ops.peek() != '(') {
				e1.applyOperation(values, ops.pop());
			}
			ops.pop();
		}
		else if (c1.isoperator(expression[i])) {
			while (!ops.Empty() && c1.precedence(ops.peek()) >= c1.precedence(expression[i])) {
				e1.applyOperation(values, ops.pop());
			}
			ops.push(expression[i]);
		}
	}
	while (!ops.Empty()) {
		Calculator::applyOperation(values, ops.pop());
	}
	return values.pop();
}

void Calculator::applyOperation(Stack& values, char op) {
	int b = values.pop();
	int a = values.pop();
	switch (op) {
	case '+':values.push(a + b); break;
	case '-':values.push(a - b); break;
	case '*':values.push(a * b); break;
	case '/':values.push(a / b); break;
		if (b != 0) {
			values.push(a / b);
		}
		else {
			cout << "Division by zero error\n";
		}
		break;
	}
}




















