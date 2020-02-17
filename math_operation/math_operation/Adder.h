#pragma once
//Creating the adder.
class adder {
	//Setting the answers and variables to private.
private:
	double num1, num2;
	double sum, difference, product, quotient;
public:
	//Creating the functions
	double add();
	double subtract();
	double multiply();
	double divide();
	void get(int);
	void set();
};