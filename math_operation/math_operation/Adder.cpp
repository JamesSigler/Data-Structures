//including the header
#include "Adder.h"
#include <iostream>
using namespace std;



double adder::add()
{
	//putting addition into sum variable
	sum = num1 + num2;
	return sum;
}

double adder::subtract()
{
	//putting subtraction into the difference variable
	difference = num1 - num2;
	return difference;
}

double adder::multiply()
{
	//putting multiplication into the product variable
	product = num1 * num2;
	return product;
}

double adder::divide()
{
	//putting division into the quotient variable
	quotient = num1 / num2;
	return quotient;
}

void adder::get(int operation)
{
	//taking user choice and printing the answer for that choice
	if (operation == 1)
	{
		adder::set();
		cout << "Sum is: " << add() << endl << endl;

		//pausing console output and clearing previous output
		system("pause");
		system("CLS");
	}
	else if (operation == 2)
	{
		adder::set();
		cout << "Difference is: " << subtract() << endl << endl;
		system("pause");
		system("CLS");
	}
	else if (operation == 3)
	{
		adder::set();
		cout << "Product is: " << multiply() << endl << endl;
		system("pause");
		system("CLS");
	}
	else if (operation == 4)
	{
		adder::set();
		cout << "Quotient is: " << divide() << endl << endl;
		system("pause");
		system("CLS");
	}
	else if (operation == 5)
	{
		//creating a default option with both variables as 2
		num1 = 2;
		num2 = 2;
		cout << "Sum is: " << add() << endl;
		cout << "Difference is: " << subtract() << endl;
		cout << "Product is: " << multiply() << endl;
		cout << "Quotient is: " << divide() << endl << endl;
		system("pause");
	}
}

void adder::set()
{
	//asking the user for their numeric inputs
	cout << "Enter a number:";
	cin >> adder::num1;
	cout << "Enter a second number:";
	cin >> adder::num2;
}

