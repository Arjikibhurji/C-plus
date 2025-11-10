/*
The C++ environment has 3 sub spaces:
    a. Standard Libraries Section:
        #include <iostream>  (header file is iostream which contains 2 most commonly used objects cin & cout)
        Using namespace std; (namespace removes the ambiguity between similar function names, so C++ has similar libraries having same fn names)
                                (So here std is a predefined namespace in c++, functionality of cin and cout)
                                (std::cin/cout  the four dots are scope resolution objects)
    b. Main Function Section:
        int main(){} (starting function of the C++ programs)

    c. Function Body Section:
        contains all the body of the program as well as the return statement which will return the value
        value of return statement must match with the value type of the return type i.e. if using int then return 0 which is success

        See the example below
----------------------------------------------------
#include <iostream>
using namespace std;

void display(){
    cout << "hello";
    return;
}
int main(){
    display();
    return 0;
}
----------------------------------------------------
DISPLAYING STRING IN C++
----------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main(){
    string name = "Samarth";
    cout << name <<endl;
    return 0;
}
----------------------------------------------------
TAKING INPUT IN C++
----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cout << "Enter your name please." <<endl;
    cin >> name;
    cout << "Your name is: " + name;
    return 0;
}
----------------------------------------------------
TAKING NUMBERS
----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(){
    int num1;
    int num2;
    int sum;

    cout << "Enter first number" <<endl;
    cin >> num1;
    cout << "Enter second number" <<endl;
    cin >> num2;
    sum = num1 + num2;
    cout << "Your sum is " << sum <<endl;
    return 0;
}
----------------------------------------------------
- Each instruction is given of the form 1 or 0 which is called binary digits or bits for short. 
- Assembly language is programming lingo that makes human-readble machine lingo
- Assembler translates assembly lingo into machine lingo
- Compiler is a program that reads the source code of one lingo and translates it to the other lingo. C++ is compiled lingo
- Running the executable file doesn't require compiler to be installed
- Interpreter is a program that directly executes the instructions in the source code without requirement of compiled, it is less
efficient and requires interpreter to be installed on every machine
- High level languages like C++ allows to write programs without knowing much on which platform it would be run on.
This makes the program easier to write. Platforms are like x86 or Power PC or MIPS hardware, so it is cross-platform
- C++ is a high level but in comparison to modern lingo it is low level
----------------------------------------------------

Q. What is the need for compiler?
A. Compiler does two things:
-- Checks if all rules are followed in code
-- translates the C++ code into machine readable code and translates all the data into an OBJECT FILE
eg: hello.cpp >>>>> hello.o

Q. What is the role of linker?
A. Linker comes after and the job is to translate all the object files to output files and process is called linking
-- The linker files combine multiple object files along with the library files (C++ std library)
-- This helps in removing the cross dependancies across multiple files
-- This finally gives out the executable file

--- C++ standard library is important so iostream is most common in terms of printing text and getting text from input

--- Building is the whole process of converting source code files into an executable
*/

int add(int x, int y)
{
    return x + y;
}