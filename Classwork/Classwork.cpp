/*
=====================================================================================
LECTURE 1:

1. Low level: Closer language to the machine, very verbose, long source code, slow
    development, requires memory allocation

2. High Level: Less control on optimization however compact & easy to maintain

3. Toolchain: Distinct development tools utilized in code i.e. Processor, Compiler, linker,
    libraries, debugger, editor etc

4. C++ files to be saved as .cpp or .h; text files to be saved as .txt

SAMPLE CODE:
            #include<iostream> // import library containing cout
            using namespace std; // import namespace AVOID
            int main() // main: start of program
            {
            cout << "hello" << endl; // print hello to screen
            return 0;
            }


5. using namespace std: this is standard library and you write this to say that i want
    everything to be imported from the standard library

6. AVOID STD DECLARATION: Basically you can have name clashes with you own made function
    and some other function innside the library if the names match (for example count if created yourself can match)

    Instead use std::cout and so on, a bit tedious but great to avoid bigger mess.

    Can also import just necessary things like using std::cout but still you cannot know
    which one you would be importing so don't use this.

7. Compilation: Translation of C++ into machine readable (or binary code)

8. C++ Source Files >>>> Assembler (lowest lingo) >>>>> Binary Codes (also known as object files)

9. Compiler vs Interpreter:

| Feature                | **Compiler**                                                                          | **Interpreter**                                                   |
| ---------------------- | ------------------------------------------------------------------------------------- | --------------------------------------------------------------------- |
| **Translation method** | Translates **entire program at once** into machine code (creates an executable file). | Translates and executes **line by line** — one instruction at a time. |
| **Output**             | Produces a separate **binary file**                                                   | Does **not** produce a separate file; executes directly.              |
| **Speed (execution)**  | Faster (since code is already compiled to machine language).                          | Slower (interprets every line during runtime).                        |
| **Error handling**     | Shows **all errors together** after compilation.                                      | Stops immediately at the **first error** it encounters.               |
| **Example languages**  | C, C++, Java (partly), Go, Rust                                                       | Python, JavaScript, PHP, Ruby                                         |

10. Executable file: Complete program which can be run by double clicking from console

    SO FLOW IS:
    hello.h >> [preprocessed] >> hello.cpp & main.cpp >> [compiled] >> hello.o & main.o
        >> [linker] >> executable file >> Load & CPU (part of run process)

    Linker is needed since compiler only converts the source code text into binary and
        not the library references, which the linker converts

11. Syntax Error the best as easily found by the compiler rest needs brainstorming

12. Even after getting executable errors could be there
    Runtime error: These arise due to memory problems and incorrect use of arrays
    Logical error: well you stupid wrote code stupid

13. Tokens: Keywords(int, double etc), Identifiers (std, cout etc), Literals (Hello, 24.3),
    Seperators ({} ;), Operators and Whitespaces

    Smallest meaningful symbols that makes sense to compiler

14. Keywords: Special words

    Type Names: int, double
    Qualifiers: const, static, volatile
    Control Flow Instruments: for, while

15. Command must end by semicolon and are instructions for program

16. Statement/statement block: Single/group of commands; statement block is also statement

17. Expression: Statement with value

18. Variable value: it is the data stored at associated memory address at a certain point
    during the execution of the program

19. Variables:

    Declared: Need to be created to be used
    Initialization: Value should be assigned when created
    Assignment: Value can be changed
    Accessed: Computation or displaying output
    Scope: Do not exists out of the curly bracket that they are created in

20. Initialization

    Variable name = value;

    Re-assignment: x = x*2

21. const int = 1;

    Mark the variable as constant and so value cannot change and initialize + declare
    at same time

22. Inputs can be concatenated: cin >> x >> y;

23. IMP on DATATYPES [1 byte = 8 bits]

| **Data Type**         | **Size (Bytes)**                 | **Typical Range**                                         | **Example**                           | **Comments**                       |
| --------------------- | -------------------------------- | --------------------------------------------------------- | ------------------------------------- | ---------------------------------- |
| `bool`                | 1 byte                           | `true` / `false`                                          | `bool flag = true;`                   | Only stores 0 or 1, values <> 0 are converted to 1 |
| `char`                | 1 byte                           | `-128 to 127` (signed) or `0 to 255` (unsigned)           | `'A'`, `'z'`                          | Stored according to their ASCII Code |
| `short` / `short int` | 2 bytes                          | `-32,768 to 32,767`                                       | `short a = 120;`                      | Smaller integer type               |
| `int`                 | 4 bytes                          | `-2^31 to 2^31-1`                                         | `int x = 100;`                        | Most commonly used integer type    |
| `long`                | 4 or 8 bytes (depends on system) | On 64-bit: [-2^31, 2^31         ]                         | `long n = 100000;`                    | Use `sizeof(long)` to confirm      |
| `long long`           | 8 bytes                          | `-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807` | `long long big = 1e12;`               | For very large integers            |
| `float`               | 4 bytes                          | ~ ±3.4 × 10³⁸ (6–7 decimal digits)                        | `float f = 3.14f;`                    | Single-precision floating point    |
| `double`              | 8 bytes                          | ~ ±1.7 × 10³⁰⁸ (15–16 decimal digits)                     | `double d = 3.1415926535;`            | Double-precision (more accurate)   |
| `long double`         | 12 or 16 bytes                   | ~ ±1.1 × 10⁴⁹³² (19+ digits, depends on compiler)         | `long double pi = 3.14159265358979L;` | For high precision math            |
| `wchar_t`             | 2 or 4 bytes                     | 0 to 65,535 (UTF-16) or 0 to 4,294,967,295 (UTF-32)       | `wchar_t ch = L'Ω';`                  | For wide character sets (Unicode)  |


unsigned int is [0, 2^31-1]

24. Overflow: When the values of the datatype exceeds the allowed range, we say overflow

25. Any integer can be represented by set of coefficients and bases i.e.
    in decimal (base 10): 123 = 3 * 10^0 + 2 * 10^1 = 1 * 10^2

26. Use sizeof() to know the size in bytes if the variable

27. Enum: convinient to describe set of constants with human friendly names
    This is a subtype of int.
    Usually starts with 0,1,2 assignment but you can assign explicitly

SAMPLE CODE

        int main()
        {
        enum Seasons { Spring, Summer, Fall, Winter }; // type definition
        Seasons x = Fall; // variable declaration and initialization
        cout << x << endl; // print out variable value
        cout << sizeof(Summer) << endl; // print out variable size
        }

Ans. Here it prints x as 2 and size as 4 bytes (which is of an int)

28. AUTO: auto inferred from type of expression assigned to it. you have to initialize
    and declare both at the same time

    int x = 5;
    auto y = x;

29. Typedef: want to custom name the keywords, though do not use

    typedef unsigned int uint;

30. using: another keyword like typedef

    using uint = unsigned int;

31. Decltype: inferring someone else's declaration type

    double x;
    decltype(x) y; // since x is a double, y also becomes a double

===============================================================================
LECTURE 2:

1. Logical Operators:

    AND: A&&B
    OR: A||B
    Not A: !A
    Assign to check: ==
    Not Equal: !=

    && has priority over ||

2. Short circuit: Simply if first expression of AND is false, won't evaluate whole

3. Bitwise Operators: Working directly with the bits and not integers. You go one by one
    on each position of the bits to get the final number

    3 is written as 0011; 9 is written as 1001

    &: if both bits are same, then same, otherwise 0
        3 & 9 : 0011 & 1001 >>>>>>>>>> 0001 which is 1
    |: if any position has a 1
        3 | 9 : 0011 | 1001 >>>>>>>>>> 1011 which is 11
    <<: This is left shift, go left of x (add 0 on right) by n positions eg: x << n
        3 << 1 : 0011 << 1 >>>>>>>>>> 0110 which is 6 [here we shift by 1 position only]
        Similarly we can do the same for right shift
    ~3: ~0011 becomes 1100
    ^: XOR, this means OR so gives 1 only when the digits of both positions are different
        3 ^ 9 : 0011 ^ 1001 >>>>>>>>>> 1010

4. Increment & Decrement:

    a = 2

    V. IMP::
    a++ : increases a by 1, but this prints out old value of a [2]
    ++a : increases a by 1, and also prints the new increased value of a [3]
    Similaryly for decrement --

5. Combined operations:

    x *= 3 + 2 >>>>>>>>>>> x = x * (3+2)

6. Conditional Assignment: If condition is true, then evaluate expression1 otherwise
    expression2

    Condition ? Expression1 : Expression2

    int x = (1>2) ? 1 : 3; // x takes the value 3

7. Literal: Value (any like string, bool etc) that you can type into C++ code

use library cstdlib for rand and use cmath for pow

8. You can get the type of luteral by typeid(literal)

whenever doing division very important if suppose writing for 1/3 then always write 1.0/3.0 otherwise by default integer division will yield 0

Always declare the variables to be used outside of loops within the global or outside envirnment first otherwise won't be able to use
8. Expression is everything before a semicolon, adding semicolon makes it a command

9. 7 / 3 returns 2 since it is integer division

10. A + 1 would give 66 since A has ASCII code as 65 and int is more complicated than char

    Basically a part of "promotion in data types" >>>>> converts a narrower data type
    to a wider data type for performing operation

    bool always becomes 0 or 1

    Always does computation on 32 or 64 bits, so 1 byte (8 bits) ones like char gets promoted
    to int which is 4 bytes (32 bits)

| Type                 | Relative Rank | Description              |
| -------------------- | ------------- | ------------------------ |
| `long double`        | 6️⃣ (widest)  | Extended precision float |
| `double`             | 5️⃣           | 64-bit floating point    |
| `float`              | 4️⃣           | 32-bit floating point    |
| `unsigned long long` | 3️⃣           | 64-bit unsigned integer  |
| `long long`          | 2️⃣           | 64-bit signed integer    |
| `unsigned long`      | 1️⃣           | 32-bit unsigned integer  |
| `long` / `int`       | 0️⃣           | 32-bit signed integer    |

11. Literal Modifiers:

Examples:
    auto x = 65; // x is of type int
    auto x = 65u; // x is of type unsigned int (note the suffix u)
    auto x = 'A'; // x is of type char
    auto x = 65.; // x is of type double (note the .)
    auto x = 65.f; // x is of type float (note the suffix f)

12. Escape Characters: Use \ (to add double quotes)

13. Flow control statements: In C++ execution is sequentially however flow ontrol structures allows us to jump through steps and thus faster efficient code
    Conditional structure: if-else, switch
    loops: for, while & do-while
    jump: break, continue, goto

14. IF ELSE:

    if(condition)
        statement1
    else
        statement2

    if (0){statement}: does not execute as 0 is false and so conditions are false and we skip the statements inside entirely


15. FOR LOOPS:

    for(initialization; condition; increment)
        {statement}

        for ending line always use '\n' as it is quicker than std whihc s buffered output

16. In the for loops, does not matter in initialization if you write i++ or ++i, given
    that you would be using i and so it is incremented in same way in both

17. In loops, any declaration outside would be assigned by the last value

    int i;
    for (i=0; i<10;i++)
        cout << "hello" << endl;
    cout << i << endl;

18. Always remember the 2^31 ~ 2147 * 10 ^ 6, so see overflow with respect to this

19. WHILE LOOP:

    while (condition)
        statement

20. DO WHILE LOOP:

    do
        statement
    while(condition);

    The statement is executed as long as it is true and atleast once

21. Continue interrupts the current iteration of do-while loops

        for (int i=1; i <= 100; ++i)
            {
            if (i % 13 == 0)
            continue; // skips multiples of 13
            cout << i << endl;
            }


22. It is not efficient to have if statements within a for or while loops
    so whenever can please rearrange into do while

    EFFICIENT CODE - use a do while loop and then implement ifs or for

    int begin = 1;
    do {
        int end = begin+11;
        end = end <= 100 ? end : 100;
        for (int i=begin; i <= end; ++i)
        cout << i << endl;
        begin = begin + 13;
    } while (begin < 100);

23. Break: breaks out of the loop that is designed

24. SWITCH: Easier way to deal with if else statements. A little complex

    When a matching case is found, execution starts from there and continues until
    we find a break, even if that means crossing another case

    using namespace std;
    int main()

        {
        int x;
        cout << "enter 0-6\n";
        cin >> x;
        switch (x) {
        case 0:
        cout << "sunday"; break;
        case 1:
        cout << "monday"; break;
        case 2:
        cout << "tuesday"; break;
        case 3:
        cout << "wednedsday"; break;
        case 4:
        cout << "thursday"; break;
        case 5:
        cout << "friday"; break;
        case 6:
        cout << "saturday"; break;
        default:
        cout << "NOT A VALID ENTRY"; break;};
        cout << endl; return 0;
        }

25. if you need multiple inputs std::cin >> day >> month >> year; and then input by
    spaces

26. floor(): first import cmath and then use

you can always write i+=3 for increements of a n number
===============================================================================
LECTURE 3:

1. Arrays are collection of values ***OF THE SAME TYPE*** having a fixed length defined
    at the time of compilation (no changes during execution). Size = length

    type arrayName[size]

2. Access >>>> arrayName [i], where indexing is 0 to n-1

3. Using negative or size > length gives out unpredictable results

4. Cannot initialize the whole list at an instant, best way to do this is by
    using loops. Efficient structure is import <algorithm> and use std::fill if same
    value you need:

    #include <iostream>
    #include <algorithm>
    int main(){
        char array[80];
        std::fill(std::begin(array),std::begin(array)+10,'r');
    }

    or use std:generate with other libraries to generate random numbers

    #include <iostream>
    #include <algorithm>
    #include <cstdlib>
    #include <ctime>

    int main() {
        int arr[10];
        //std::srand(std::time(0));  // seed RNG

        // Generate random numbers; calls gen repeatedly and assigns the generated value to each element in the range

        std::generate(arr, arr+10, std::rand);

        for (int i = 0; i < 10; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        return 0;
    }


    or

    #include <algorithm>
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> v(5);
        int next = 1;
        std::generate(v.begin(), v.end(), [&]() { return next++; }); // The lambda [&]() { return next++; } captures next by reference and increments it each call.

        for (int x : v) std::cout << x << ' ';
        std::cout << '\n';
    }


    or
    std::generate(a.begin(), a.end(), []() {
    return std::rand() % 100; // reduces any number to 0-99
    });

The square brackets [] tell C++: “Which variables from the outside can this lambda use?”

1. []

“No outside variables allowed.”

2. [&]

“Take all needed outside variables by reference.”

→ means the lambda can see and modify them.

3. [=]

“Take all outside variables by value (copy them).”

→ lambda sees them but cannot change the outside ones.

4. [&next]

“Take only the variable next by reference.”


5. Initializing an array:

    int x[] = {2,3,4};

6. Arrays are dangerous so do not use them for more than 100K elements or big mem stack. Results are unpredictable beyond indices given
    Always remember, arrays are defined to the stack

    CANNOT DO int arr[5] = {0,1,2,34,6}; // DON'T GIVE LENGTH IF DEFINING

7. NEW RANEG METHOD within FOR in RANGES like arrays:

    for (auto i : x){ // this is given you have defined type and assigned array values
        cout << i <<endl;}

    Basically a range on whcih you want to iterate over

8. By default, array of type char sequence is always terminated with 0
char x[] = "hello";
char y[] = {'h','e','l','l','o', 0}; both x & y are same things

9. In arrays, storing matrices as dimension is such that the right most dimension
    acts as the inner storage dimension

    double A[m][n]; or double A[m][n][k]; right most is inner dmension

    inner dimension is  the dimension contiguous in memory

    By row: Mi,j corresponds to A[(i-1)*n+j-1

10. All dimensions of the matrix should be known at compile time.

11. Memory allocation: You can get the memory address by "&x". 64 bits so 2^64 - 1 memory
    cells

12. Pointer: Memory address; Pointer variable: variables containing mem. address of something

13. Variable pointer:
    *px = &x
    so to print address just print px

    HOWEVER, if you want to dereference memory then print:
    *px >>>> This will print the value of x

14. Null pointer reference:

    *ptr = nullptr

    // simply means that ptr = NULL

    We can always initialize the pointers to null if we are later doing it o the code

15. Pointer arithematic: Any increment or decrement happens with [n * S] bytes. Eg: uint has 2 bytes storage [S]
    Now if ps = 0004 in memory address and we do px+=3 then the new address is at [0004 + 3 * 2]

16. []: This operator i used for increment/decrement and dereference; V IMP does both change & dereferencing

    Therefore something like px[0] simply prints x value as it is increased by 0

        uint16_t x = 6183; // x requires 2 bytes because sizeof(x)==2: 6183=24*255+63
        uint16_t *px = &x; // px contains the memory address of y (0004)
        cout << *px << endl; // this prints 6183
        cout << px[0] << endl; // this also prints 6183
        cout << px+3 << endl; // this prints the memory address of x + 6 bytes; since 3*2
        cout << &px[3] << endl; // this also prints the memory address of x + 6 bytes since & is there so mem address
        cout << (&px[3])[-3] << endl; // this prints 6183, last operation of [-3] so deferences and gives same

17. ARRAYS

    int Sam[] = {1,2,3}

    - Then the name of the array (Sam), decays into the memory pointer of the first element of the array (1)
    Sam == &Sam[0] (i.e. gives memory pointer of the first element of the array) or *Sam == Sam[0](dereferences the memory pointer) //deref valuees

    - Here *(Sam + 2) == Sam [2] // star dereferences and moves it 2 elements ahead on the array

    basically in even pointer you move by n*s but since arrays are consistent values it simply means moving across the variables within the array


    You can now loop over without indices like:

    #include <iostream>
    int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;          // pointer to first element
    int *end = arr + 5;    // pointer past last element

    while (p != end) { // so we are not going to the end but just one before it
        std::cout << *p << " ";
        ++p;  // move to next element
    }
}

    In array, *p = arr; therefore p is the pointer i.e. if you print p, that will be memory addreess

    If you print *p, then that would be dereferenced and so would be values.

    Very important in array you do not use & to give memory referenceing i.e.  *px = Sam


    Array names is a pointer to the first element in the array i.e. name of x then,  use *px = x

    *x gives out the first element of the array (dereferences)

    int main() {
        uint16_t x[3] = {5, 7, 9}; // allocate 3x2=6 bytes. x refers to the memory ad
        uint16_t *px = x; // px contains the memory address of x (note we did not use &)
        cout << sizeof(px) << endl; // this prints 8, the size of the variable px [this is size of x0225423 so irrelevant]
        cout << sizeof(x) << endl; // this prints 6, the size of the array x [ 3*2]
        cout << x[1] << endl; // this prints 7
        cout << px[1] << endl; // this also prints 7 [dereferences]
        cout << *(px+1) << endl; // this also print 7 [dereferences]
        }


        *x gives the first element so *x is the first element

        x is the array so that is the whole array
18.
    n = sizeof(x) / sizeof (*x) // divide the total bytes within array by how much first element size

    POINTER LOOP

    for (uint16_t *p = x, *end = x+n; p != end; ++p) >>>>>> the end becomes x[n]

DIFF

NORMAL POINTERS

#include <iostream>
int main() {
    int a = 10;        // normal variable
    int* p = &a;       // pointer p stores address of a

    std::cout << "a = " << a << "\n";       // prints 10
    std::cout << "&a = " << &a << "\n";     // prints address of a
    std::cout << "p = " << p << "\n";       // p stores same address
    std::cout << "*p = " << *p << "\n";     // dereference: gives value of a
}

ARRAU
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr; // arr "decays" to pointer to first element

std::cout << "arr = " << arr << "\n";    // address of arr[0]
std::cout << "p = " << p << "\n";        // same address
std::cout << "*arr = " << *arr << "\n";  // first element = 10
std::cout << "arr[0] = " << arr[0] << "\n"; // also 10

ALL

#include <iostream>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr; // pointer to first element

    std::cout << "First element: " << *p << "\n"; // 10
    std::cout << "Third element: " << *(p + 2) << "\n"; // 30
    std::cout << "Third element via index: " << p[2] << "\n"; // 30

    // move pointer and modify value
    *(p + 1) = 25; // change second element
    std::cout << "Updated second element: " << arr[1] << "\n"; // 25

    // Loop with pointers
    int* end = arr + 5;
    for (int* q = arr; q != end; q++) {
        std::cout << *q << " ";
    }
}


19. Pointer is diff for elements and arrays

    int main() {
        uint16_t x[3] = {5, 7, 9}; // allocate 3x2=6 bytes. x refers to the memory ad
        const auto n = sizeof(x)/sizeof(*x); // number of elements in the array

        // the usual way
        for (int i = 0; i < n; ++i)
        cout << x[i] << ',';
        cout << endl;

        // using pointer arithmetic
        for (uint16_t *p = x, *end = x+n; p != end; ++p)
        cout << *p << ',';
        cout << endl;
    }

    FOR ELEMENTS:

| Feature     | Description                                                                  |
| ----------- | ---------------------------------------------------------------------------- |
| Declaration | `int *p`                                                                     |
| Address-of  | `&x` gives the address of `x`                                                |
| Dereference | `*p` gives the value of `x` (10)                                             |
| Arithmetic  | Usually meaningless — `p+1` points to memory after `x`, which may be invalid |

    FOR ARRAYS:

| Feature            | Description                                                                                              |
| ------------------ | -------------------------------------------------------------------------------------------------------- |
| Base pointer       | `arr` itself **decays to a pointer** to the first element                                                |
| Access elements    | `*(p+i)` or `p[i]` gives element `i`                                                                     |
| Pointer arithmetic | `p+1` moves to the **next element** (scaled by sizeof(type))                                             |
| Size info          | `sizeof(p)` gives size of pointer, not array — need `sizeof(arr)/sizeof(*arr)` to get number of elements |



20.         // FIRST
            int x[2] = {1, 2};
            int * p1 = x; // non-const pointer to non-const int

            // 1.
            *p1 = 3;
            std::cout << *p1<<std::endl; // prints 3
            std::cout << p1<<std::endl; // prints the memory address of element 0 of array
            std::cout << x[0]<<std::endl; // element 0 also changes in the x array so 3


            // 2.
            p1 = p1 + 1;
            std::cout << *p1<<std::endl; // prints 2 ; simply goes to the net element on the list
            std::cout << p1<<std::endl; // memory address of the second elemnt


            // 3.
            const int *p2 = x; // non-constant pointer to a constant integer
            //* p2 = 3; // error, since the integer is constant so cannot modify
            p2 = p2 + 1; // ok: can modify the pointer

            //4. WRONG WAY TO CONSTANT THE POINTER

            int const * p5 = x; // non-const pointer to const int (same as p2)
            //*p5 = 3; // error: cannot modify the pointed object
            p5 = p5 + 1; // ok: can modified the pointer


            // 5. RIGHT WAY TO CONST THE POINTER

            int * const p3 = x; // const pointer to non-const int
            *p3 = 3; // ok: can modified the pointed object
            //p3 = p3 + 1; // error: cannot modify the pointer

            // 6. Cannot modify anything
            const int * const p4 = x; // const pointer to const int
            //*p4 = 3; // error: cannot modify the pointed object
            //p4 = p4 + 1; // error: cannot modify the pointer


21.


        int x[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        int *p = x; // p & x points to 1st element


        int a = *p++;
        // *p++ = post-increment Use *p first → *p = x[0] = 10 → assigned to a, Then increment p → p now points to x[1]
        std::cout << a <<std::endl; // prints 10, first element
        std::cout << *p<<std::endl; // prints 20, second element
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x stays the same
        std::cout<<"CHANGE HERE"<<std::endl;
        ////////////////////////////////////////////

        int *q = x; // q points to 1st element
        int b = *++q;
        // *++q = pre-increment, Increment pointer first → q points to x[1], Then dereference → *q = x[1] = 20 → assigned to b

        std::cout << b<<std::endl; // prints 20; second element
        std::cout << *q<<std::endl; // prints 20; second element
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x stays the same
        std::cout<<"CHANGE HERE"<<std::endl;


V IMP. int c just takes into a copy of whatever was dereferenced and does not point to anything

        ///////////
        int *r = x; // r points to 1st element
        int c = (*r)++; //
        std::cout << c<<std::endl; // prints 10; first element
        std::cout << *r<<std::endl; // prints 11; first element incremented by 1
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x's first element is changed to 11; c gets old value. NOTE POINTER HERE IS ALWAYS AT 1st elem
        std::cout<<"CHANGE HERE"<<std::endl;
        //////////////////////////////////////////////


        x[0] = 10; // changing back

        int *s = x; // s points to 1st element
        int d = ++*s; // now d is 11
        std::cout << d<<std::endl; // prints 11
        std::cout << *s<<std::endl; // prints 11, since it is pre increment
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x's first element is changed to 11;
        std::cout<<"CHANGE HERE"<<std::endl;

22. MATRX: In C++, arrays get stored in row major order i.e. A[0][0] and so on and not in 2D order or n-D order

    Declaration for first element: double *p = &A[0][0]

    Therefore to access any element say A[i][j], it is stored at p[i*m + j], m=no. of columns

    Say you want to access A[1][2] where n = 2 & m = 3, then location = 1*3 + 2 = 5

    Therefore pointer location is p+5

23. Variable Size: Dynamically change size during runtime as not known during compile

24. You cannot simply ask for a user input n and then assign the array length, you need to know it at compile time
    and has to be a literal or constant expression (integer)

25. CREATING A DYNAMIC ARRAY >>>>>>>>>>> use new and delete

    int *A = NULL; // initialize to null pointer
    int n;
    cin >> n; // input desired array size
    A=new int[n]; // allocate memory and assign to A
    delete [] A; // deallocate memory
    A = NULL; // reset to null pointer

    NEW WITH POINTER:

    int *A=new int[n]
    delete [] A;

26. In dynamic array you do not name the array however assign the pointer to it. So say *A is the pointer, then
    to access anything it is A[i] like before.

| Concept     | Stack Array          | Dynamic Array (`new`)        |
| ----------- | -------------------- | ---------------------------- |
| Syntax      | `int arr[5];`        | `int *A = new int[5];`       |
| Lifetime    | Automatically freed  | Must use `delete[]`          |
| Size        | Fixed (compile-time) | Variable (runtime)           |
| Access      | `arr[i]`             | `A[i]` or `*(A+i)`           |
| Location    | Stack                | Heap                         |
| Example use | Small, fixed arrays  | User-defined or large arrays |


    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    int *A = new int[n];   // dynamically allocate

    for (int i = 0; i < n; i++) {
        A[i] = i * 10;     // same as *(A + i) = i * 10;
    }

    std::cout <<  A << std::endl;// prints the memory address of the first element
    std::cout <<  *A << std::endl; // prints the first element
    std::cout <<  &A[0] << std::endl;// prints the memory address of the first element

    delete[] A; // release memory

27. Do not forget to delete the pointers:

    POINTERS ARE STORED ON THE STACK
    DYNAMIC ARRAY ARE STORED ON HEAP
    FIXED LENGTH ARRAY ARE STORED ON THE STACK

    Stack is small and only used to assign local variables, where allocation & deallocation is automatic & very fast

    Heap is tank of memory, allocation is slow and explicitly managed, need to request free memory with size to reserve

28. STruct: composite type aggregating multiple fundamental types into single structure

    Made contiguously in memory -

    SIMPLY A CONTAINER FR DIFFERENT TYPESOF DATA that belong together

    struct Student {
    int id;
    double gpa;
    std::string name;};



    struct ComplexNumber
    {
    double realPart;
    double imagPart;
    };

    ComplexNumber x;
    x.realPart = 3;
    x.imagPart = 2;

    OR

    ComplexNumber x = {2,3};

    OR

    struct ComplexNumber
    {
    double realPart;
    double imagPart;
    } x, y;
    // initialize x and y
    x.realPart = 3.0;
    x.imagPart = -2.2;
    y = x; // copies structure of x to y

    OR

    struct
    {
    double realPart;
    double imagPart;
    } x;
    // initialize x and y
    x.realPart = 3.0;
    x.imagPart = -2.2;

    To access, use the . operator

29. Pointers to Struct: use operator -> to access member of a pointer to struct

    ComplexNumber *ptr = &x; // a pointer to x
    cout << ptr->realPart << ", " << ptr->imagPart << endl;

30. Struct variables can also be dynamically allocated with new and delete

    CREATING JUST STRUCT DYNAMICALLY

    ComplexNumber *ptr = NULL;
    ptr = new ComplexNumber; // allocate memory (note no square brackets)
    ptr->realPart = 3.0;
    ptr->imagPart = -2.2;
    // print the data members of y
    cout << ptr->realPart << ", " << ptr->imagPart << endl;
    delete ptr; // de-allocate memory (note no square brackets)

    CREATING ARRAYS IN STRUCT: This would be needed if you want to store multiple objects  within a certain struct
    i.e. for struct student >>>>> different IDs within it so create an array

    ComplexNumber *ptr = NULL;
    ptr = new ComplexNumber[2];
    ptr[0].realPart = 2.0
    ptr[0].imagPart = 3.0
    prt[1].realPart = 14
    ....
    delete [] ptr; // deallocates and deletes the pointer variable

=======================================================================================================

LECTURE 4: FUNCTIONS

1. Core of Object Oriented Programming

    HEAD OF THE FUNCTION

    returnType FunctionName(arguments)>>>>>>>>>>>>>>>>>>> double pow(double a, double b)

2. No return value functions are called void

3. Libraries:
    Maths (cmath); String & Memory Manipulation (cstring); Input/Output (cstudio); Integer (cstdint);
    Number Conversion (cstdlib); Character Classification (ctype); Memory (cstdlib); Time (ctime)

4. Convert the type using: static_cast<target_type>(expression);

5. User defined function = function definition + function body

    returnType FunctionName(parameters) // function head
    {
    statements
    }


6. Vector vs Array

| Feature               | Dynamic Array (`new double[n]`)         | `std::vector<double>`     |
| --------------------- | --------------------------------------- | ------------------------- |
| Memory allocation     | You manage manually (`new`, `delete[]`) | Automatic                 |
| Resize                | ❌ Cannot resize                         | ✅ Can resize anytime      |
| Safety                | ❌ Easy to leak or crash                 | ✅ Very safe               |
| Syntax                | Low-level                               | High-level                |
| Passed to function as | `double *`                              | `vector<double>&`         |
| When used in class?   | Rarely                                  | Almost always             |
| Speed                 | Slightly more control                   | Usually similar or faster |
| Easy to use?          | ❌ No                                    | ✅ Yes                     |


array pass in function: void RandVector(int n, double *result, double a = 0.0, double b = 1.0)
vector pass in function: void RandVector(int n, vector<double> &res, double a=0, double b=1)

New vetor dynamic >>>>>>>> std::vector<double> v(n);   // size n, automatic memory
New array dynamic >>>>>>>>> you already know

6. Functions are defined at global, outside the main. They must have a return expression

7. If you have an if(expression) then there is a return expression on the if to get out

    and then you need another return expression for the function to stop

8. Function call: cout << function (parameters)

9. A void function might not be used to return values but if it has operations like for or anything in them like
    filling arrays, that can well be performed

10. Function declaration: Like how you declare variables, these are headers only without body i.e.

    int foo(int);
    int foo(int x);

    Both are same

11. Always declare the function before the main() function if using.

    you can do:         declaration void foo (int);
                                    main()
                        body        void foo(int x){//body}

12. Define smaller functions in separate files rather than having one big code for the whole file

13. So different files are compiled independently to object files post which the linker combines them to give executable.

    1st file: foo.h >>>>>>>>> int foo(int); // header file only says that there exists a function but search within all objects fuke (foo.cpp would be converted to object)
    2nd file: foo.cpp >>>>>>>> int foo(int){//body} // contains the actual code
    3rd file: main.cpp >>>>>>>>>> #include "foo.h"
                                int main(){}

    OR use inline

    1st file: foo.h >>>>>>>>>>> declare
                                inline int foo(int){}
    2nd file: main.cpp >>>>>>>>>> #inlcude "foo.h"

    Here only main.cpp is formed into object file

14. Defualt values: give in the function argument; can change later in the function

15. Passing as an argument [V.IMP]

    a. By Values: Copy of value is created and changes inside function does not affect the value outside
    >>>>>>>>>>>> suppose function1(int x) and then you call function1 (y), where y=5

    b. By Reference: Opposite of by value, here reference to og variable is created and so the og variable also changes after
        function executed
    >>>>>>>>>>>> function1(int& x) and then you call function1 (y), where y=5; y will get modified according to the function1

    c. By Pointer: Similar to reference, any modification to the pointed object inside the function happens to the og variable
    >>>>>>>>>>>> function1(int *x) and call function1(&y) // so get memory address to call and then in argument use the pointer

    So pass by pointer is good for dynamic arrays and so on as the address of the cell is passed

16. Array as an argument: // you use the pass by pointer method to do this

    >>>>>>>>>>>>
        // "const int x[]" is the same as "const int *x"

        void foo(const int x[], unsigned n) // x is a pointer to a const int value within the array so no modification within function
                {
                for (unsigned i = 0; i < n; ++i)
                cout << x[i] << " "; // x[i] is not modified
                cout << "\n";
                }
        int main()
                {
                int y[3] = {1, 2, 3};
                foo(y, 3); // y is a pointer
                }


17. Remember unsigned is a short form for unsigned int

18. Do not pass struct as a value in argument as it costly, try passing it as a reference or a constant reference

19. Struct: Example of multiplication of 2 complex numbers

    struct ComplexNumber // name of the struct
    {
        double r, i;
    };

// we pass the complex numbers by const reference, so we avoid the cost of copying them & no modification in function

    ComplexNumber mult(const ComplexNumber& a, const ComplexNumber& b) // here we have defined a function composition here
                                                                            // i.e. complexnumber mult is a function that uses
                                                                            two other complex numbers which are struct to
                                                                            get the multipliation done.
                                                                            ComplexNumber is actually the return type here
    {
        ComplexNumber c; // new defined struct which will contain the product (r,i) as parts of c
        c.r = a.r * b.r - a.i * b.i; // compute real part
        c.i = a.r * b.i + a.i * b.r; // compute imaginary part
        return c;
    }

    int main()
    {
        ComplexNumber x = {1, 2},
        y = {2, -3},
        z = mult(x, y);
        std::cout << z.r << "+" << z.i << "i\n";
    }

    With structs use different to pass as reference to your function and different to use within your computation i.e.

    Roots compute(const PolyCoeff& p){
        Roots r;
        //rest}

20. Function parameters are declared in the function argument or header, do not redeclare in body

21. DO NOT USE GLOBAL VARIABLES, can cause problems in multithreading applications (parallelization); safe way only to use in constant values

22. Issue: Returning an object is like copying and is expensive, rather you can return the value as an argument

    void mult(const ComplexNumber& a, const ComplexNumber& b, ComplexNumber& c) // pass c as an argument
        {
        c.r = a.r * b.r - a.i * b.i; // compute real part
        c.i = a.r * b.i + a.i * b.r; // compute imaginary part
        }
    int main()
        {
        ComplexNumber x = {1, 2},
        y = {2, -3},
        z; // do not put anything in z as it simply carries the value of c
        mult(x, y, z);
        std::cout << z.r << "+" << z.i << "i\n";
        }

23. Function Overloading: Using functions with same name but different parameters (different in type or no. of params)

    However if you have foo(int x) & foo (int x, int y =3); then cannot since you could still use anyone

    you can always lift int up to a double so be sure while using overloads

24. Using operator overloading: You can use operator* to multiply or operator+ to add etc. This is also efficient similar to
    the void + argument that we did ealrier. It is also like by reference so no copies made even though there is return.

    Basically in this case we are using multiply but then since our * has params, we are simply calling it through those params

    However, if you need to say multiply complex number x with 2 that would be a problem since it is complex, it will use the
    overloaded operator and cause hurdle

    See below:

    ComplexNumber operator *(const ComplexNumber& a, const ComplexNumber& b) // since multiply so add opertor *
        {
        ComplexNumber c;
        c.r = a.r * b.r - a.i * b.i; // compute real part
        c.i = a.r * b.i + a.i * b.r; // compute imaginary part
        return c;
        }
    int main()
        {
        ComplexNumber x = { 1, 2 },
        y = { 2, -3 },
        z = x * y; // here you use the function
        std::cout << z.r << "+" << z.i << "i\n";
        }

25. Recursion (or iteration): When a function directly/indirectly calls itself then called recursion

    unsigned factorial(unsigned n)
        {
        if (n > 1)
            return n*factorial(n-1);
        return 1;
        }

26. A recursive function has a call stack where the internal one always solves first. For example in the case of factorial,
    we have:

    factorial(3)
    factorial(2)
    factorial(1)

    Each recursive call gets its own stack frame and waits to return, these stack grows as calls grow and so too many calls
    lead to stack overflow. When a function finishes (i.e. a call), it pops off the stack

    Each call has own copy of variables and call stack is the structure where function calls are stored

27. Recursion 3 parts: conditions to stop, small action and then solution of small problem structurally identical to og problem

28. Pointers to a function:
                            int foo(int);
                            int (*p)(int); // p is a function pointer

                            Syntax: returntype (*namepointer)(argumenttype)

                            So it must match the function properly


                            int main()
                            {
                                // p is a pointer variable and points to
                                // the function foo
                                void (*p)(int) = &foo;
                                (*p)(3); // equivalent to a call to foo(3)
                                p = &bar; // now p points to bar
                                (*p)(3); // equivalent to a call to bar(3)
                                return 0;
                            }

29. Callback: Passing function pointers as arguments like

    int addTwo(int x)
        {
        return x + 2;
        }
    void printf_fun_x(int x, int(*f)(int)) // f is a function pointer
        {
        cout << (*f)(x) << endl; // invoke the function stored in f
        }
    int main()
        {
        printf_fun_x(10, &addTwo);
        }

callback with multiple arguments:
        int add(int a, int b) { return a + b; }
        int sub(int a, int b) { return a - b; }

        int (*f)(int, int)




30. In loops, i would always start from the initializer that is 0, and so i++ and ++i have the same results


31. Regular callback: void visit(Node* n, void (*f)(Node*))
however if the argumenst need extra you go with void*

        void callback(Node* node, void* arg); void id universal pointer type and allows extra arbitrary arguments to callback so use void* args

        void traverse(Node* n,
                    void (*callback)(Node*, void*),
                    void* arg)
        {
            if (!n) return;
            callback(n, arg);
            traverse(n->left, callback, arg);
            traverse(n->right, callback, arg);
        }

        void increment(Node* n, void* arg)
        {
            int* amount = (int*)arg;
            n->value += *amount;
        }

        int k = 10;
        traverse(root, increment, &k);  // increment every node by 10

32. Trignometric equations expect radians and not integers therefore to convert degrees to radians:
    degree * pi / 180 ;;;; good radian scale >> -10 to +10 radians

=======================================================================================================

Structs and Class

1. First major pillar of OOP: Encapsulation >> bundling of different data structures

2. Every function either has a methods or members

3. Data members: Variables that are part of the object i.e. m_width

        #include <iostream>
        using namespace std;

        struct Rectangle
        {
            int m_width, m_height;
            // These are MEMBER VARIABLES.
            // Every Rectangle object has its own width & height.

            void initialize(int, int);
            // This is a MEMBER FUNCTION (method).It is only declared here, not defined.
            // Because it is declared inside the struct, it automatically gains access to m_width and m_height.

            int area() {
                // This is another member function, defined inside the struct. It can directly access m_width and m_height because it also has the hidden pointer "this".
                return m_width * m_height;
            }
        };

        // ----------------------------------------------
        // Definition of the method initialize(); Rectangle:: tells the compiler:
        // "This method BELONGS to Rectangle". So it still has access to m_width and m_height.
        // ----------------------------------------------
        void Rectangle::initialize(int x, int y) // so this is a method
        {
            // You don't see it, but this function has: Rectangle* this   (secret invisible pointer)

            // So this is actually:
            // this->m_width  = x;
            // this->m_height = y;

            m_width = x;
            m_height = y;
        }

        // ----------------------------------------------
        // MAIN PROGRAM
        // ----------------------------------------------
        int main ()
        {
            Rectangle rect;           // Creates a Rectangle object (m_width & m_height exist now)

            rect.initialize(3, 4);    // Calls the member function. Secretly: initialize(&rect, 3, 4)

            cout << "area: " << rect.area() << endl;
            // Calls area(), which multiplies this->m_width * this->m_height

            return 0;
        }

4. Constructor: Special functions having no return type >>>>> called automatic when object created and no use post object created

    Function name should be same as struct name and cnstructors can be overloaded

    Syntax:

    constructName(parameters): commaSeparatedMemberInitializers // this is a constructir and construct name should be same as struct
    {
    //body
    }

5. Example:

    struct Rectangle
        {
        int m_width, m_height; //line 2

        Rectangle(int x,int y): m_width(x), m_height(y) // constructor, this should be written in the same order of how they are declared in line 2
            {
            // body
            }
        int area() {return m_width*m_height;}
        };

        int main ()
            {
            Rectangle rect(3,4); // constructor called at object creation
            cout << "area: " << rect.area() << endl;
            return 0;
}

6. Simply speaking, earlier you had to create a method initialize to initialize the members within the struct and use them in your functions however
    you do not do that with the use of constructors

7. A closer look at everything:

    struct A
        {
            int m_x;
            A() : m_x(0) {}      // constructor with no arguments; so you create A without giving any value i.e. m_x = 0; also known as default constructor
            A(int x) : m_x(x) {} // constructor with one argument; so you create the objecy of A with an integer i.e. A a(5); also known as parameterized constructor
        };

    -- A is a simple type (a struct) that represents “something that has an integer”.
    -- It has one data member: int m_x;

    So every A object would look like
    A
    └── m_x (an int)

    Here m_x() or anything after the colon (:) is known as an initializer list

    struct B
        {
            A m_a;
            B(int x) : m_a(x) // from the initializer list we can call the constructor of A
            { //body }
        };

    B
    └── m_a (which is an A)
        └── m_x (an int inside A)

    int main()
        {
            A a(1);
            B b(1);
            return 0;
        }

    1. This creates an object a of type A. It calls the constructor A(int x) with x = 1. Inside that constructor: m_x is initialized to 1
        so a.m_x = 1

    2. This creates an object b of type B. The constructor B(int x) is called with x = 1. Before the body runs, the member m_a must be constructed.
    Because we wrote : m_a(x), it calls A(int x) with x = 1. That sets b.m_a.m_x = 1. Then the (empty) body {} of B(int x) runs and does nothing.

    a.m_x      = 1
    b.m_a.m_x  = 1

8. If you omit the initializer list in struct B which uses a constructor to call on A; then B would be assigned a default constructor value of A (if provided)

    struct B
    {
        A m_a;

        B(int x)     // no initializer list
        {
            // no m_a.m_x = x; here
        }
    };

    In this case; m_a.m_x = 3 by default if you had  A() : m_x(3) {} in A

9. All data members are constructed before the constructor body runs

10. 2 types of special constructirs are added implicitly by the parameters if not defined explicitly:
    -- Default Constructor: this has empty parameter list
        struct A {
        int m_x;
        };

    -- Copy Constructor: Copies every data member, one by one, in the same order they are declared. and compier provides this
        Happens when you create a new object from an existing object

    A(const A& other) // make a new A that is copy of another A

    Use cases

    1. When you create an object from another object:
    A a1(10);
    A a2 = a1;   // copy constructor is called here

    2.


11. Constructor Overloading: define multiple constructors for a class as long as they have different param lists

    struct A {
    A() {}          // default constructor
    A(int x) {}     // constructor taking int
    A(double y) {}  // constructor taking double
    };

12. So basically if you copy then you create a 2 distinct things same for classes and same for integers i.e. int a = 5; int  b = a; so a and b are
    separate and we cannot by changing b chnage a (this same happens on the struct i.e. classes also).

13. A a1(10);
    A a2 = a1;

    Here we never called the constructor of a2;  however what copy constructor does is assign the values of the member variable of a1 to a2; therefore any value
    would also give it 10

    It does a memberwise assignment. You can override this default assignment thorugh your own assumptions

14.

struct Position
{
    double m_x, m_y;

    Position(const Position& p)        // <-- COPY CONSTRUCTOR
        : m_x(p.m_x)                   // copy p.m_x into my m_x
        , m_y(p.m_y)                   // copy p.m_y into my m_y
    {
    }

    Position(double x, double y)       // <-- normal constructor
        : m_x(x)
        , m_y(y)
    {
    }
};


Here if you see we have two constructors:
1. First constructor: This is what a copy constructor is basically create a new object from an existing objetc of the same type
Position → the type of the object being copied ; & → passed by reference ; const → cannot be modified

You cannot do Position (Position p) as that is a crash and recursive so in that case we do Position (const Position& p) i.e.
we pass the same object with no recursion and no extra copying

Very important the const is very important as you do not wnt changes in your original one i.e.

BAD COPYING:

    Position(Position& p)  // BAD VERSION
    {
        p.m_x = 1234;  // modifies original!!
        m_x = p.m_x;   // copies modified value
        m_y = p.m_y;
    }

    Position a(10, 20);
    Position b = a;   // copy constructor called

    now where all it is used also

A.  here foo wanted Position p object however you passed Position a therefore it simply copy constructs all the member variables from a and to p
    void foo(Position p) {
    // do something
    }

    Position a(10, 20);
    foo(a);

B.
    Position createPos() {
    Position temp(7, 8);
    return temp;
    }

    Position p = createPos();

here temp is destroyedin the function however if we need to give it to p we create a copy constructor so all this goes on in the background

16. Shallow Copy vs Deep Copy:

    Shallow >>>> Copies only top level values including pointersso it is usually dangerous as can lead to double deletion and so on

    struct A {
    int* ptr;
    };

    A a1;
    a1.ptr = new int(10);
    A a2 = a1;   // copy a1 into a2

    So shallow is a2.ptr = a1.ptr;   // just copies the pointer value however they would share the same memory address and so a probelm

    Deep copy you need to write it yourself

    A(const A& other) {
    ptr = new int(*(other.ptr));  // new memory and copy value
    }

    If your struct only contains ints, doubles, or other simple objects → shallow copy is fine (compiler default works)

        If your struct contains pointers, arrays, dynamic memory, or resources →
        ✔️ you MUST write a deep copy (copy constructor)
        ✔️ otherwise copying causes bugs


    so correct full class:

    struct A {
    int* data;

    A(int x) {
        data = new int(x);
    }

    // deep copy
    A(const A& other) {
        data = new int(*(other.data));
    }

    ~A() {
        delete data;
    }
};

Shallow copy is perfectly fine when your class contains only:

int

double

char

bool

std::string (it manages its own memory safely)

other classes that do deep copy internally

objects without raw pointers

18.
    struct Position
    {
        double m_x, m_y;
        Position() // default constructor
        : m_x(0) // set m_x to zero
        , m_y(0) // set m_y to zero
    {
    }
        Position(double x, double y) : m_x(x), m_y(y) // parametrized constructor
        {
        }
    };

and then in above there is a implicitly generated copy constructor also  Position(const Position& other); // implicitly generated

19. Implicit default constructor:

    struct A {
    int x;
    double y;
    };

    Since you did not define any constructor, here what happens by compiler:

    A() { }   // generated by compiler
    A a;   // calls implicit default constructor

    however in our case it then proceeds inside struct A:
    int x;      // built-in type → has NO default constructor
    double y;   // built-in type → has NO default constructor

    but nothing happens here as no default value so they remain uninitialized garbage
    a.x = garbage
    a.y = garbage

20. Below you craete your own customized constructor however there is no default value and so it will always throw error

struct B {
    int x;
    B(int n) : x(n) {}   // you wrote a constructor
};

B b;   // ❌ ERROR — no default constructor exists

21. Non constructor default types: int, double, char, bool, float etc so not automatically initialized to anything


22. const char* means: a pointer to a sequence of characters; BUT that sequence ends with a null character '\0'; this is called a C-string

so name is stored like 'n', 'a','m','e','\0' however the variable name points to the first character 'n'

const char* s = "hello";
int* p;
cout << s << endl;   // prints "hello"
cout << p << endl;   // prints memory address

basically char pointers are printed as text until we reach 0; anything is a string written in double quotes i.e. "p3"

so a cout << name where name is a pointer to the string "x", would only print x as it is stored 'x','0'


22. Encapsulations helps in abstraction information from the user i.e. what they can access and what they cannot

23. Public: methods or mebers which can be accessed by the user

24. Private: methods or members which are part of the implementation detail and can be used only isdie the struct

25. In struct, everything is public by default

26.

struct Position
{
// anything defined here is public
private:
// members m_x and m_y are declared as private
// they can only by used inside the methods of this struct
double m_x, m_y;
public:
// the constructors is defined as public
// and can be accessed outside of this struct
Position() : m_x(0), m_y(0) {} // m_x, m_y can be used from inside the struct
Position(double x, double y) : m_x(x), m_y(y) {}
};
int main()
{
Position x(1,2); // this is ok: the constructor can be used from here
cout << x.m_x << endl; // this is not ok: m_x is private and cannot be used here
}

so anything defined in private you cannot access that part outside the struct even if it is part of constructor

27. Class and struct are essentially same but class everything is private however in struct everything is public

28. Accessors: The way to see the private elements outside our struct

    class Position
        {
        double m_x, m_y;

        public:
            Position() : m_x(0), m_y(0) {} // m_x, m_y can be used from inside the struct
            Position(double x, double y) : m_x(x), m_y(y) {}
            double getX() { return m_x; } // read only public accessor
            double getY() { return m_y; } // read only public accessor
            void set(double x, double y) { m_x = x; m_y = y; } // set new coordinates
        };

    void print(const char *name, Position& p)
        {
        // getX and getY are public and const methods, so they can be accessed from here
        cout << name << "(" << p.getX() << "," << p.getY() << ")" << endl;
        }

So here getX and getY are simply the return values i.e. they help in giving out the data, you cannot modify based on these (read-only)

However, set(x,y) helps you to modify the private variables since the process works inside struct

29. Abstraction is such that internal implementation is hidden from user and so if we want to modify or change anything we just change the internal implementation
    and not the place or code which is using it

30. const methods: When you create a const object then you do not want for it to get changed. However, methods might change it so you need to create const method also

    const Position p(3, 4);
    so p here is read only and things likep.m_x=10 is not allowed

    however if there is any method like p.getX(m_x = 999;) so this is legal and it would then change the thing you did not want to change and so compiler assumes any non
    const method can modify

    class Position {
    public:
        double getX() { return m_x; }   // ❌ non-const method
    private:
        double m_x;
    };

    int main() {
        const Position p;
        p.getX();   // ❌ ERROR — cannot call non-const method on const object
    }


    Therefore, if an object is const, you call the methods that are also const otherwise compiler will throw error i.e.

    Use this double getX() const { return m_x; }

So below also i can only do getX from p and not setX since only get is const and my p object is const

        class Position
        {
        double m_x, m_y;
        public:
        Position() : m_x(0), m_y(0) {} // m_x, m_y can be used from inside the struct
        Position(double x, double y) : m_x(x), m_y(y) {}
        double getX() const { return m_x; } // tagged as const
        double getY() const { return m_y; } // tagged as const
        void set(double x, double y) { m_x = x; m_y = y; } // set new coordinates
        };
        void print(const char *name, const Position& p)
        {
        // getX and getY are public and const methods, so they can be accessed from here
        cout << name << "(" << p.getX() << "," << p.getY() << ")" << endl;
        }

void set(double x, double y) const { m_x = x; m_y = y; } // set new coordinates: This cannot do since you said you won't modify and then you are modifying
and so this will always throw an error


A& means:reference to an object of type A (not a copy not a pointer but a reference)
A obj;
A& ref = obj;

so ref is obj and share same memory, if you change ref.x then obj.x will also change
Passing by reference (const A&) is ONLY done to avoid unnecessary copying.

It does NOT determine whether the copy is shallow or deep.

What determines shallow vs deep is this:

✔ Does the class contain pointers or dynamic memory?


28. Friend: Keyword that allows another class or function to use the private members

class A
{
int x; // x is private
friend class B; // class B has access to private members
friend void foo(const A&); // function foo() has access to
private members
};
void foo(const A& a) { cout << a.x; } // this is ok
struct B
{
void zoo(const A& a) { cout << a.x; } // this is ok
};


here like foo(const A&) simply means there exists a function foo that takes a const A& and I want this to be my frined

if you have defined 2 constructors then you would have 3 constructors; 2 defined by you and 1 copy constructor


29.
// ==============================
// Class Position
// Represents a point (x, y)
// ==============================


class Position
{
private:
    double m_x, m_y;  // private coordinates

public:
    // Default constructor (optional)
    Position() : m_x(0), m_y(0) {}

    // Constructor taking x and y
    Position(double x, double y) : m_x(x), m_y(y) {}

    // Accessor methods — read-only
    double getX() const { return m_x; }
    double getY() const { return m_y; }

    // Modifier method — shifts the point by dx, dy
    void shift(double dx, double dy) {
        m_x += dx;
        m_y += dy;
    }
};


// ==============================
// Class Rectangle
// Defined by 2 Position objects:
// top-left corner and bottom-right corner
// ==============================
class Rectangle
{
private:
    Position m_topLeft;       // top-left position of rectangle
    Position m_bottomRight;   // bottom-right position of rectangle

public:

    // ----------------------------------------
    // 1️⃣ Constructor: GIVEN TWO CORNERS
    // ----------------------------------------
    Rectangle(const Position& topLeft, const Position& bottomRight)
        : m_topLeft(topLeft),            // copy-construct from argument
          m_bottomRight(bottomRight)     // copy-construct from argument
    {
        // No code needed here — initializer list already did the work
    }


    // ----------------------------------------
    // 2️⃣ Constructor: GIVEN TOP-LEFT + width & height
    // ----------------------------------------
    Rectangle(const Position& topLeft, int width, int height)
        : m_topLeft(topLeft),  // copy top-left corner
          m_bottomRight(       // construct bottom-right corner by calculation
              topLeft.getX() + width,
              topLeft.getY() + height
          )
    {
        // (x2, y2) = (x1 + width, y1 + height)
    }


    // ----------------------------------------
    // 3️⃣ Read-only method: compute width
    // const means: does not modify the rectangle
    // ----------------------------------------
    int width() const {
        return m_bottomRight.getX() - m_topLeft.getX();
    }


    // ----------------------------------------
    // 4️⃣ Read-only method: compute height
    // ----------------------------------------
    int height() const {
        return m_bottomRight.getY() - m_topLeft.getY();
    }


    // ----------------------------------------
    // 5️⃣ Compute area (read-only)
    // area = width × height
    // ----------------------------------------
    double area() const {
        return width() * height();
    }


    // ----------------------------------------
    // 6️⃣ Compute perimeter (read-only)
    // perimeter = 2 × (width + height)
    // ----------------------------------------
    double perimeter() const {
        return 2 * (width() + height());
    }


    // ----------------------------------------
    // 7️⃣ Modifier method: shift entire rectangle
    // Moves BOTH corners by dx, dy
    // ----------------------------------------
    void shift(int dx, int dy) {
        m_topLeft.shift(dx, dy);        // shift corner
        m_bottomRight.shift(dx, dy);    // shift opposite corner
    }
};


29. Destructor: ~StructName()
This is called when object  is deleted (if on heap) or the object is out of scope (on stack) andused for releasing resources

30.

    struct IntArray
    {
        int *m_p;
        IntArray () : m_p(NULL) {}
        IntArray (int size) : m_p(new int[size]) {}
        ~IntArray() { delete [] m_p; } // cleanup memory
    };
    void foo()
    {
        // x is a local variable, i.e. it is on the stack; it internally allocates memory from the heap, thus requiring at some point memory de-allocation
        IntArray x(100);
        ... // here do something with x
    } // here x goes out of scope, the destructor is automatically called, so releasing memory

31. If no destructor is explicitly defined, a default one is created by the compiler, which simply calls the destructors of all data members in reverse order.
    Objects with trivial data members like int,double etc do not have destructor only struct and class. A destructor is a special function that runs
    automatically when an object dies.

    struct IntArray
    {
        int *m_p;
        IntArray() : m_p(NULL) {}
        IntArray(int size) : m_p(new int[size]) {}
        ~IntArray() { delete [] m_p; }
    };
    struct MyObject
    {
        int m_x;
        IntArray m_p1, m_p2; // MyObject data members are instances of IntArray
    };

    So in the above; we have two int array objects m_p1 and m_p2 however we do not have a destructor of MyObject. So it uses compiler
    generated destructor

    ~MyObject() {
    // destruct in reverse order of declaration
    m_p2.~IntArray();
    m_p1.~IntArray();
    // m_x has no destructor (int)
}

    so here all members are destroyed in the reverse order; intarray will destroy m_p1 and Mm_p2


Compiler decides: “Time to destroy m_p2”

Compiler calls: m_p2.~IntArray()
→ THAT function frees memory

Compiler decides: “Now destroy m_p1”

Compiler calls: m_p1.~IntArray()
→ Frees memory again

So destruction of m_p1 and m_p2 is:

Compiler triggers → IntArray destructor executes

also m_x is int so no destructor for it as it is primitive type
If IntArray has no destructor, then any memory allocated by:

m_p = new int[size];


is never freed.

Now consider:

struct MyObject {
    int m_x;
    IntArray m_p1, m_p2;
};


When a MyObject object goes out of scope, the compiler still destroys its members in reverse order:

destroy m_p2

destroy m_p1

destroy m_x

But because IntArray has no destructor, this destruction does NOT free the dynamic memory (new int[size]). The compiler-generated destructor for IntArray is empty, so:

m_p2.m_p memory leaks

m_p1.m_p memory leaks

only m_x (an int) is trivially destroyed

👉 Final outcome:

MyObject is destroyed

m_p1 and m_p2 are destroyed

BUT their dynamically allocated arrays are NOT freed, leading to memory leaks every time MyObject is used.

By default, MyObject’s members ARE destroyed — including IntArray objects —
BUT if IntArray has no destructor, then NOTHING happens to its internal dynamic memory.
Even if IntArray has NO destructor, the compiler still destroys the IntArray objects.

But destroying an IntArray object means:

Only the object itself is removed

NOT the dynamic memory it allocated using new[].


30.

void foo(int n)
{
    IntArray x(n);     // x is created here
    if (someCondition)
        return;        // exit point 1 → x goes out of scope here
    doSomething();
    return;            // exit point 2 → x goes out of scope here
}
    Whenever a local object (like IntArray x(n);) reaches the end of its lifetime:

end of function

a return happens

an exception is thrown

the closing } of the scope is reached

the compiler inserts a destructor call automatically:

x.~IntArray();


You never write this manually.

31. For struct and class you can overload operators

32. Unary Operators: The operators that takes one operand (--, ++, !, ~, &)

33. Binary Operators: Intended to have LHS and RHS arguments in them

34. Now operators are a normal function so you need to overload them but also assign what value you would need it to give
    and when you overload you need to pass by reference otherwise you won't be able to do like changes to the element in the array
    since it is a copy

    struct IntArray
    {
        int *m_p;
        IntArray() : m_p(NULL) {}
        IntArray(unsigned size) : m_p(new int[size]) {}

        const int& operator[](unsigned i) const { return m_p[i]; } // const version
        int& operator[](unsigned i) { return m_p[i]; } // non const version

        ~IntArray() { delete [] m_p; }
    };
    void foo( const IntArray& a)
    {
        cout << a[0] << endl; // this use the const version, because a is const
    }
    void main()
    {
        IntArray x(100);
        x[0] = 4; // this uses the non const version (we are making changes)
    }


35. Part of confusion V. IMP:

    1️⃣ void foo(const IntArray& a); → pass-by-const-reference
    2️⃣ void foo(IntArray a); → pass-by-value
✅ 1. pass-by-value → makes a COPY
void foo(IntArray a)


When you call:

IntArray c(10);
foo(c);


This happens:

✔ A copy constructor runs

It creates a new IntArray object called a.

✔ A second dynamic array is allocated (via default copy semantics!)

You now have two different m_p pointers.

✔ Modifying a does NOT modify c

They are separate objects.

✔ Destructor runs twice

One for a (when foo ends),
one for c (at end of scope).

❌ And because your IntArray does NOT define a proper copy constructor,

this causes double-delete bugs.

✅ 2. pass-by-const-reference → NO copy, zero overhead
void foo(const IntArray& a)


When you call:

IntArray c(10);
foo(c);


This happens:

✔ NO copy constructor is called

(You can even delete the copy constructor — this still works.)

✔ NO new memory is allocated

a points directly to the SAME object as c.

✔ It is extremely efficient

No copy, no construction, no deletion.

✔ You CANNOT modify a

Because it’s const.

✔ Only 1 destructor runs

For c only.


36.

struct IntArray
{
    int *m_p;
    IntArray() : m_p(NULL) {} // default constructor
    IntArray(unsigned size) : m_p(new int[size]) {}

    const int& operator[](unsigned i) const { return m_p[i]; }  // const version
    int& operator[](unsigned i) { return m_p[i]; }              // non-const version

    ~IntArray() { delete [] m_p; }
};

void foo( const IntArray& a)
{
    cout << a[0] << endl; // this use the const version, because a is const
}
void main()
{
    IntArray x(100);
    x[0] = 4; // this uses the non const version (we are making changes)
}

Thesis:
IntArray is a struct that internally stores a pointer m_p to a dynamically allocated int array.

Default constructor: m_p is NULL.

Constructor with unsigned size: m_p points to new int[size].

You have two overloads of operator[]:

one for const objects

one for non-const objects

Destructor frees the dynamic memory with delete[]

37. Beware of the const

[ const int& ]   operator[]( … )   [ const ]
  ^ return type                      ^ function is const
The caller cannot modify the value they get from the array.

a[0] = 10 becomes illegal.

You return a reference, but read-only.
This member function will NOT modify the object.”

So basically you need both const otherwise problem could occur where you say function is not to modify but then you can!

38. This: keyword (pointer) to the current class inheritance

39.

struct A
{
    A(int n) : m_x(n) {}
    int m_x;
    // here this is a pointer of type A*
    // pointing to the current instance
    void foo() { cout << this->m_x << endl; }
};

39. Usually the assignment operator (=) is String& operator=(const String& rhs); however this won't work if you
    are doing dynamic through pointers and so you need to overload yours

40. Use std::string >>> that provides a lot of functionality built in

41. std::npos >> constnat that represnts not found i.e.e used if you want to see if the literal exists in the text

42. size_t is a datatype to represent size of things like how many characters in string

// possible implementation of the operator< for strings

bool operator<(const string& s1, const string& s2)
{
    const size_t n1 = s1.length();
    const size_t n2 = s2.length();
    const size_t n = min(n1, n2);
    for (size_t i = 0; i < n; ++i) { // this works for same size ones so cat vs bat
        if (s1[i] < s2[i])
            return true; // gets returned here these give out ASCII values in correct order so a is 97 but b is 98
        if (s1[i] > s2[i])
            return false;
}
    return n1 < n2; // this works when size mismatch and all same i.e. cat and cater so this
}

// 'J' < 'j'
string("Jim") < string("jim") // this is true, because 'J' < 'j'


43. When an object is constructed, all data members are also constructed in the same order in which they are
declared. When the object is destroyed, all data members are destroyed in reverse order

44. You can have nested structs and just define with A::B x (if B within A, and you need x)
    Otherwise you can have typedef and enum also and can call them the same way you call the nested ones.

struct A
{
// define a public subclass B
    struct B
    {
    };
        // define a public typedef
        typedef unsigned short mytype;
        enum DayOfWeek {Monday, Tuesday, ...};
    };

int main()
{
    A::B x; // declare x of type A::B
    A::mytype y; // declare y of type unsigned short
    A::DayOfWeek d = A::Monday; // declare d of type A::DayOfWeek
}

=====================================================================================
LECTURE 6: Templates

1. Templates: Simply if you have identical code for different data types, use this as a placeholder and work

2. Suppose, cube of a number for int, double and float

    Case a: Use overload (wastage of codes)

    int cube(int x) { return x*x*x; }
    float cube(float x) { return x*x*x; }
    double cube(double x) { return x*x*x; }

    Case b: Use template

    template <typename MyType>
    MyType cube(MyType x) { return x*x*x; } // this is a function with the return type of MyType and anme of function is cube

    Here, the template and typename are my keywords while mytype is a placeholder for type

    Can use keyword class also instead of typename

3.  Swap: within STL but use #include <algorithm>; is used to swap values of array between two variables

    You can use like std::swap(a, b);

4. What you call a constructor for a class like Temp t (int x) : (x), is actually for built-in types called as the default
    initialization. SImply int t. So basically what you do is initialize in constructor

5. srand(time(nullptr)); This is used for seed within the random (rand() function)

6. std::max: within algorithm library and returns max between two values; can also do std::max<double>

    template<class T>
    const T& max(const T& a, const T& b)
    {
        return (a < b) ? b : a;
    }


7. Template with a constructor:

template <typename T>
class Box { // class template
public:
    T value;

    // Constructor
    Box(T v) : value(v) {
        cout << "Constructor called for value = " << value << endl;
    }
};

8. Within template, it could be used for any type however only those determined in the main function would be instantiated

    i.e.
    int main()
        {
        int x = 2;
        double y = 3.0;
        cout << cube(x) << endl << cube(y) << endl;
        }
    here only T=int and T=double binary code isinstantiated

9. You can do multiple argument template through:

    template <typename T1, typename T2>
    void foo(T1 x, T2 y)
    {
        // do something with an object of type T1 and one of type T2
    }

10. In the below case of having int overload and template, the default compiler would be using the int one, since it is more specific

    int cube(int x) { return x*x*x; }
    template <typename MyType>
    MyType cube(MyType x) { return x*x*x; }

    int main()
    {
        int x = 2;
        double y = 2;
        cout << cube(x) << cube(y) << endl;
    }

11.  With multiple overload with template arguments, the overload which matches using as few as possible of the
    template arguments is the preferred match

12. Easy summary below:

// overload 1
void foo(double, double) { cout << "call 1\n"; }

// overload 2
template <typename T> void foo(double, T) { cout << "call 2\n"; }

// overload 3
template <typename T, typename U> void foo(T, U) { cout << "call 3\n"; }


int main() {

// 1 does not match (it requires type conversion); 2 does not match (it requires type conversion); 3 does match, using 2 template arguments
    foo(5, 5); // 3 is the best match

// 1 does not match (it requires type conversion); 2 does match, using 1 template argument; 3 does match, using 2 template arguments
    foo(5.0, 5); // 2 is the best match, because it uses less template arguments

// 1 does match (perfect match); 2 does match, using 1 template argument; // 3 does match, using 2 template arguments
    foo(5.0, 5.0); // 1 is the best match, because it is a perfect match


14. However if there is like a same level of match between two cases of overload then there would be compilation error

// overload 1
template <typename T> void foo(T, double) { cout << "call 1\n"; }

// overload 2
template <typename T> void foo(double, T) { cout << "call 2\n"; }

foo(5.0, 5.0); [here both 1 & 2 are equally good]

15. Templayte classes: You can have these; basically classes defined where you have unknown
    data type of your select variable i.e.

    template <typename T>
    class Box {
        T value;     // value is of type T
    };

    Box<int> b1;         // Box containing an int
    Box<double> b2;      // Box containing a double
    Box<string> b3;      // Box containing a string

    So unknown T is replaced by int, double, string respectively. Therefore templates help write one class
    for multiple data types

16.

// -------------------------------------------
// TEMPLATE CLASS: MyArray
// -------------------------------------------

// This tells the compiler that the class uses a *template type* T.
// T is a placeholder for any datatype (int, double, string, etc.).
template <class T>
struct MyArray
{
    // -------------------------------------------
    // DATA MEMBER
    // -------------------------------------------

    T *m_p;
    // m_p is a POINTER to type T.
    // In this class, it will point to a *dynamic array*
    // allocated using new T[size].


    // -------------------------------------------
    // DEFAULT CONSTRUCTOR
    // -------------------------------------------

    MyArray() : m_p(NULL)
    {
        // This constructor is used when MyArray is created with no size.
        // Example:
        //      MyArray<int> a;
        //
        // m_p = NULL means:
        //      There is no array allocated yet.
    }


    // -------------------------------------------
    // CONSTRUCTOR WITH SIZE
    // -------------------------------------------

    MyArray(int size) : m_p(new T[size])
    {
        // This constructor is used when MyArray is created with a size.
        // Example:
        //      MyArray<int> x(100);
        //
        // new T[size]:
        //      creates a *dynamic array* of T with 'size' elements.
        //
        // m_p(new T[size]):
        //      initializes m_p to point to the first element of this array.
    }


    // -------------------------------------------
    // READ-ONLY INDEXING OPERATOR
    // const at the end = works when the object is const
    // -------------------------------------------

    const T& operator[](unsigned i) const
    {
        // Called when accessing elements on a const object.
        // Returns a *const reference* so the user cannot modify the data.
        return m_p[i];
    }


    // -------------------------------------------
    // NORMAL INDEXING OPERATOR (modifiable)
    // -------------------------------------------

    T& operator[](unsigned i)
    {
        // This version is used when the object is NOT const.
        // It returns a reference so you can read or write:
        //      x[0] = 4;
        return m_p[i];
    }


    // -------------------------------------------
    // DESTRUCTOR
    // -------------------------------------------

    ~MyArray()
    {
        // The destructor runs AUTOMATICALLY when the object goes out of scope.
        // It frees the memory allocated by new T[size] in the constructor.
        //
        // This prevents memory leaks.
        delete[] m_p;
    }
};


// -------------------------------------------
// MAIN FUNCTION
// -------------------------------------------

int main()
{
    // Create a MyArray of 100 integers.
    // This calls: MyArray(int size)
    MyArray<int> x(100);

    // Access element 0 using the overloaded operator[].
    // Equivalent to: x.m_p[0] = 4;
    x[0] = 4;

    // When main() ends, 'x' goes out of scope.
    // Destructor ~MyArray() is called and delete[] m_p is executed.
    return 0;
}

// However this all is very rudimentary and copy semantic is not defined here and so if you do copy
//  then double deletion would occur since it is shallow copy

17. std::pair: within utility header and helps to store two values together, you can access them through .first and .second

    #include <utility> // for std::pair
    #include <string>
    #include <iostream>

    int main() {
        // Create a pair holding an int and a string
        std::pair<int, std::string> myPair;

        // Assign values to the pair
        myPair.first = 42;               // first element is an int
        myPair.second = "Hello, World!"; // second element is a string

        // Access and print the values
        std::cout << "First: " << myPair.first << std::endl;
        std::cout << "Second: " << myPair.second << std::endl;

        return 0;
    }

18.
Bracket         	    Example	                    Meaning
Angle brackets < >	    pair<int,string>	        Template type parameters
Round brackets ( )	    pair<int,string>            p(10,"hi")	Function or constructor call
Square brackets [ ]	    arr[3]	                    Array indexing

19. any class that uses a template is called a template class and values to be given in angle brackets <>

20. Building simple version of std::pair

template<class T1, class T2> // T1 is type of first element, T2 is type of second element

struct pair
{
    pair() {} // default constructor

    T1 first; // declare the variable first; we could have done T1 and T2 b however std::pair uses first and second and so better readability
    T2 second; // declare the variable second; you need to declare these after the constructor otherwise out of scope error

    pair(const T1& a, const T2& b) : first(a), second(b) // parametrized constructor; initialize 'first' with a and 'second' with b
    {
    }

};

template<class T1, class T2>

pair<T1,T2> make_pair(const T1& a, const T2& b) // function to create a pair, defining make_pair
{
    return pair<T1,T2>(a,b);
}


20. Very important: template <class T>
here class does not mean class as in struct or class however it simply means a placeholder for any data type
    i.e. int, double, string etc

    So the actual type is T and “T is a placeholder for ANY datatype.”

You can also replace class with typename

21. std::complex : within complex header and helps to store complex numbers and do operations on them; it is limited to
    double float and long double only; can do complex arithematic(+,- ) and has literals for complex numbers also (imaginary unit)

    add those with #include <complex> and using namespace std::complex_literals;

    // 1i is the imaginary unit i; 2i is 2 times i
    std::complex<double> z1 = 3.0 + 4.0i

    then can do:
    std::cout << z1.real() << ", " << z1.imag() << std::endl;

=====================================================================================

Lecture 7: IO

1. Stream: Simply a pipe that carries ordered sequence of characters from one place to another

2. Eg: cin (source is keyboard, destination is program) cout (source is program, destination is screen)

3. <<: Typically is binary shift operator however overloaded here to mean output to stream

    Binary shift: int x = 3 // 0b00000011
    int y = x << 2; // y = 0b00001100 = 1 ; so simply shifts bits to left by 2

4.
*/


