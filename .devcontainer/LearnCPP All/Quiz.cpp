/*
Q1. What is the difference between initialization and assignment? 
    How many times can a variable be initialized or assigned a value?
A1. Initialization provides a variable with an initial value 
    (at the point of creation). Assignment gives a variable a new value after the variable has already 
    been defined. Since a variable is only created once, it can only be initialized once. 
    A variable can be assigned a value as many times as desired.

Q2. Write a program that asks the user to enter a number, and then enter a second number. 
    The program should tell the user what the result of adding and subtracting the two numbers is.
A2. 
#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << x << " + " << y << " is " << x + y << ".\n";
	std::cout << x << " - " << y << " is " << x - y << ".\n";

	return 0;
}

Q3. Write program readnumber and writenumber, store in diff files and access through forward declaration
A3.
-- First within your terminal go to the appropriate space by cd .devcontainer [one level back do cd ..]
-- Next, keep goinng within
-- Now type the following: 
    g++ main.cpp functions.cpp -o myProgram
-- Lastly run: ./myProgram


#include <iostream>
#include "io.h"
int main(){
	int x{readNumber()};
	int y{readNumber()};
	writeAnswer(x + y);
	return 0;
}

-- CHECK IO.cpp and IO.h

--------------

Q. What does the call stack look for the below?

	#include <iostream>

	void d()
	{ // here
	}

	void c()
	{
	}

	void b()
	{
		c();
		d();
	}

	void a()
	{
		b();
	}

	int main()
	{
		a();

		return 0;
	}

A. d 
	b
	a
	main

*/