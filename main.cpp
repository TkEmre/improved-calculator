#include"Calculator.h"
#include<windows.h>

int main() {
	Calculator e1;
	string expression;
	//Objects


	system("color 0F");
	

	cout << "                                                 -------------------------\n";  
	cout << "                                                 | " << endl;
	cout << "                                                 |  IMPROVED CALCULATOR" << endl;
	

	for (int a = 0; a < 2; a++) {
		cout << "                                                 |\n";
	}
	for (int a = 0; a < 4; a++) {
		cout << "                                                                         |\n";
	}
	cout << "                                                 -------------------------\n";

	//menu design

	cout << "DO NOT WRITE ANY LETTERS\nFOR EXAMPLE : 5*(7+3/(3+2))\n";
	cout << endl <<"Enter an expression : ";
	getline(cin, expression);
	int result = e1.calculate(expression);
	int i;
	cout << "Result = " << result << endl;
	cout << "If you want to continue press 1, if you dont press any other key...    ";
	cin >> i;
	cin.clear();
	cin.ignore();
	//first step 

	if (i == 1) {
		while (i == 1) {
			cout << "\nEnter an expression : " << endl;
			getline(cin, expression);
			result = e1.calculate(expression);
			cout << "Result = " << result << endl;
			cout << "If you want to continue press 1, if you dont press any other key...     ";
			cin >> i;
			cin.clear();
			cin.ignore();

		}
	}
	else {
		cout << "End.." << endl;
	}
	//loop for continue to operations
	return 0;
}
