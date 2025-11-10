#include <iostream>

int readNumber(){
	std::cout << "Enter number\n";
	int num{};
	std::cin >> num;
	return num;
}

void writeAnswer(int sum){
	std::cout<<"The answer is " << sum;
}