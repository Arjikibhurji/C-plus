
#include <iostream>

using namespace std;

int main() {
{ // begin of a statement
int x; // create a variable of type x local to this code block
x=10; // initialize the value 10 to the variable x
std::cout << x << "\n"; // print the value of x
x=2*x; // destructive update: the previous values of x is discarded
cout << x << "\n"; // print the value of x
}} // end of a statement
// here the variable x does not exits anymore, i.e. it is out of scope