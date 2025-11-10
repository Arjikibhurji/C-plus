/*
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
    and some other function innside the library if the names match

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
    This is a subtype of int. Usually starts with 0,1,2 assignment but you can assign 
    explicitly

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
    decltype(x) y;

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

13. Flow control statements
    Conditional structure: if-else, switch
    loops: for, while & do-while
    jump: break, continue, goto

14. IF ELSE:

    if(condition)
        statement1
    else
        statement2

    if (0){condition}: so if conditions are false and we skip the statements inside entirely

15. FOR LOOPS:

    for(initialization; condition; increment)
        statement

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

22. It is not efficient to have if statements within a for or while loops 
    so whenever can please rearrange

    EFFICIENT CODE

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

26. floo(): first import cmath and then use

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

        // Generate random numbers
        std::generate(arr, arr+10, std::rand);

        for (int i = 0; i < 10; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        return 0;
    }

5. Initializing an array: 

    int x[] = {2,3,4};

6. Arrays are dangerous so do not use them for more than 100K elements or big mem stack.
    Always remember, arrays are defined to the stack

    CANNOT DO int arr[5] = {0,1,2,34,6}; // DON'T GIVE LENGTH IF DEFINING

7. NEW RANEG METHOD within FOR in ARRAYS:

    for (auto i : x){ // this is given you have defined type and assigned array values
        cout << i <<endl;}

    Basically a range on whcih you want to iterate over

8. By default, array of type char sequence is always terminated with 0

9. In arrays, storing matrices as dimension is such that the right most dimension
    acts as the inner storage dimension

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

16. []: This operator i used for increment/decrement and dereference

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
    Sam == &Sam[0] or *Sam == Sam[0] //deref valuees

    - Here *(Sam + 2) == Sam [2] // star dereferences and moves it 2 elements ahead on the array

    You can now loop over without indices like:

    #include <iostream>
    int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;          // pointer to first element
    int *end = arr + 5;    // pointer past last element

    while (p != end) {
        std::cout << *p << " ";
        ++p;  // move to next element
    }
}

    In array, *p = arr; therefore p is the pointer i.e. if you print p, that will be memory addreess

    If you print *p, then that would be dereferenced and so would be values.
    
    
    Array names is a pointer to the first element in the array i.e. name of x then,  use *px = x [px contains mem add of x]
    
    *x gives out the first element of the array (dereferences)

    int main() {
        uint16_t x[3] = {5, 7, 9}; // allocate 3x2=6 bytes. x refers to the memory ad
        uint16_t *px = x; // px contains the memory address of x (note we did not use &)
        cout << sizeof(px) << endl; // this prints 8, the size of the variable px [idk how this calculated, but size of mem address]
        cout << sizeof(x) << endl; // this prints 6, the size of the array x [ 3*2]
        cout << x[1] << endl; // this prints 7
        cout << px[1] << endl; // this also prints 7 [dereferences]
        cout << *(px+1) << endl; // this also print 7 [dereferences]
        }

18. 
    n = sizeof(x) / sizeof (*x) // divide the total bytes within array by how much first element size
    
    POINTER LOOP

    for (uint16_t *p = x, *end = x+n; p != end; ++p) >>>>>> the end becomes x[n]

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
            std::cout << x[0]<<std::endl; // element 0 also changes in the x array


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
        int *p = x; // p points to 1st element


        int a = *p++; 
        std::cout << a <<std::endl; // prints 10, first element
        std::cout << *p<<std::endl; // prints 20, second element
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x stays the same
        std::cout<<"CHANGE HERE"<<std::endl;
        ////////////////////////////////////////////

        int *q = x; // q points to 1st element
        int b = *++q; 
        std::cout << b<<std::endl; // prints 20; second element
        std::cout << *q<<std::endl; // prints 20; second element
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x stays the same
        std::cout<<"CHANGE HERE"<<std::endl;

        ///////////
        int *r = x; // r points to 1st element
        int c = (*r)++; 
        std::cout << c<<std::endl; // prints 10; first element
        std::cout << *r<<std::endl; // prints 11; first element incremented by 1
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x's first element is changed to 11; c gets old value. NOTE POINTER HERE IS ALWAYS AT 1st elem
        std::cout<<"CHANGE HERE"<<std::endl;
        //////////////////////////////////////////////
        x[0] = 10; // changing back

        int *k = x; // k points to 1st element
        int d = ++*p; //
        std::cout << d<<std::endl; // prints 21; points to the second element which is increased by 1
        std::cout << *k<<std::endl; // prints 10, pointer remains at first element
        std::cout<<"LOOP HERE"<<std::endl;
        for (int i = 0; i < 9; i++){
            std::cout<<x[i]<<std::endl;} // x's second element is changed to 21; 
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

    1st file: foo.h >>>>>>>>> int foo(int);
    2nd file: foo.cpp >>>>>>>> int foo(int){//body}
    3rd file: main.cpp >>>>>>>>>> #include "foo.h"
                                int main(){}

    OR use inline

    1st file: foo.h >>>>>>>>>>> declare
                                inline int foo(int){}
    2nd file: main.cpp >>>>>>>>>> #inlcude "foo.h"

    Here only main.cpp is formed into object file

14. Defualt values: give in the function argument; can change later in the function

15. Passing as an argument

    a. By Values: Copy of value is created and changes inside function does not affect the value outside
    >>>>>>>>>>>> suppose function1(int x) and then you call function1 (y), where y=5

    b. By Reference: Opposite of by value, here reference to og variable is created and so the og variable also changes after
        function executed
    >>>>>>>>>>>> function1(int& x) and then you call function1 (y), where y=5; y will get modified according to the function1

    c. By Pointer: Similar to reference, any modification to the pointed object inside the function happens to the og variable
    >>>>>>>>>>>> function1(int *x) and call function1(&y)

16. Array as an argument:

    >>>>>>>>>>>>        
        // "const int x[]" is the same as "const int *x"

        void foo(const int x[], unsigned n) // x is a pointer to a const int
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

20. Function parameters are declared in the function argument or header, do not redeclare in body

21. DO NOT USE GLOBAL VARIABLES, can cause problems in multithreading applications (parallelization)

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

30. In loops, i would always start from the initializer that is 0, and so i++ and ++i have the same results
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

struct PolyCoeff {
    double a, b, c;   // coefficients of ax^2 + bx + c
};

struct Roots {
    double r1, r2;    // the two real roots
};

Roots compute(const PolyCoeff& p){ // we define the function compute which returns the type Roots (which is a struct)
    Roots r;                        // and utilizes the PolyCoeff as the argument 
    r.r1 = (-p.b + std::sqrt(p.b * p.b - 4 * p.a * p.c))/2*(p.a);
    r.r2 = (-p.b - std::sqrt(p.b * p.b - 4 * p.a * p.c))/2*(p.a);
    return r;                                 
}
int main()
    {
        PolyCoeff q = {1, -3, 2};
        Roots g = compute(q);
        std::cout << g.r1 << "\n";
        std::cout << g.r2;
    }

    int main(){
        std::cout << "Bhagwaan bacha lo" <<std::endl;
    }