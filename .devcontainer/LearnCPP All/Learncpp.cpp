/*


---------------------
Start lessons: Basic Definitions
- Workspace or solution is a container that can hold one or more related projects
- IDEs by default adds projects to the workspace
- A compiler is a program that translates your C++ code into machine code your computer can run.
- Examples: g++ (GNU C++), clang++, MSVC (Microsoft Visual C++).
- Without a compiler, your .cpp files are just text

- To produce executable, each code file is compiled into an object file and then each
    object files are linked to an executable


- Build compiles all modified code files in the project or workspace/solution, and then links the 
    object files into an executable. If no code files have been modified since the last build, 
    this option does nothing.
- Clean removes all cached objects and executables so the next time the project is built, all files will 
    be recompiled and a new executable produced.
- Rebuild does a “clean”, followed by a “build”.
- Compile recompiles a single code file (regardless of whether it has been cached previously). 
    This option does not invoke the linker or produce an executable.
- Run/start executes the executable from a prior build. Some IDEs (e.g. Visual Studio) will invoke a 
    “build” before doing a “run” to ensure you are running the latest version of your code. 
    Otherwise (e.g. Code::Blocks) will just execute the prior executable.
---------------------

Q. Configuring your compiler:
A. 
-- Build configuration: Settings that tell the compiler how to 
    build your program (e.g., which files, compiler flags, paths).
-- Debug configuration: Build that includes extra debug info so you 
    can step through code, inspect variables, and find errors.
-- Release configuration: Optimized build without debug info, meant for fast, final execution.
    (needed for sending data to public and performance testing)

-- Disable all compiler extensions as they are not necessary but enforce useless things
-- Keep warnings levels on and treat warnings as errors as it is dependent on compiler to 
    compiler to classify one as warning and other as error
-- Typically default is C++14 

-- Sometimes compiler might direct to a line after where the actual error had occured so please check the
    prior lines

---------------------

Q. First Program Hello World.
A.

#include <iostream>  
using namespace std;  

int main() {  
    //cout << "Hello, World!" << endl;  
    std::cout << __cplusplus << std::endl;
    return 0;  
}

---------------------

Quick Defn:

-- Function: Collection of statements which executes sequentially
-- Statement: Set of commands given to the computer for an action
-- When you run the program, statements inside main and executed sequentially
-- Semicolon is a statement in C++
-- RAM: Random Access Memory is within a computer which is used for loading the program into 
    the RAM. Simply they are a series of numbered boxes that can be accessed when program is running.
    So earlier old language you could do a direct memory access by asking to going to numbered box xx
    and get value but in C++ you do it indirectly through objects
-- Objects: These represent a region of storage that can hold a value. These are utilized to store 
    and retrieve value from the memory
-- Variable: Object with a name
-- Allocation: Process of reserving storage of an object's use. Post allocation, object is created
-- Data Type: What kind of value the object will store
-- Identifier: name that the variable is accessed by
-- Assignment Operator: '=' , also called copy assignment and copies the value on RHS to LHS
-- Equality Operation: '==' , test if two values are equal or not
-- Initialized = The object is given a known value at the point of definition.
-- Assignment = The object is given a known value beyond the point of definition.
-- Uninitialized = The object has not been given a known value yet.
-- Literal: Fixed value that is directly inserted into the code; value of the literal is fixed 
    unlike the variable
-- Expression: an expression is a non-empty sequence of literals, variables, operators, and 
    function calls that calculates a value


---------------------

Q. Multiple Variable defining

A. int a,b ; // this is correct way

---------------------

Q. Different types of initialization
A.
-- Default initialization: int a; performs no initialization and gives an indeterminate (garbage value)
-- Copy initialization: int a = 5; normal, some regarded as inefficient but widely used
-- Direct initialization: int a (5) ; value inside parenthesis; more efficient than above but less than below
-- List initialization: int width {5}; or int width = {5}; this is used for initializating with a list of value

---------------------

Q. Why list initialization?
A. Use of narrow conversions

int main()
{
    // An integer can only hold non-fractional values.
    // Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold.
    // Such a conversion is a narrowing conversion, since the fractional part of the value will be lost.

    int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion

    int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
    int w3 (4.5);   // compiles: w3 direct-initialized to value 4

    return 0;
}

 -- As you can see above, you cannot put 4.5 at all in list initialization but would work with rest
    and put it equal to 4

---------------------

-- Value Initialization: int width {}; Utilized using the empty sets of braces and initializes the variable to 0
    Utilize this when the object's value is temporary and would be replaced i.e.:

    int x {};      // value initialization
    std::cin >> x; // we're immediately replacing that value so an explicit 0 would be meaningless

-- Important: If a variable is not being used, it will give out variable unused warning. So either remove 
    or use. You can also do a (Only for C++17 & onwards):

    [[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused

---------------------

INPUT-OUTPUT LIBRARY (IOSTREAM)

-- This deals with basic input and output [#include <iostream>]
-- std::cout : helps in sending data to the console to be printed. It is called character output. However
    it does not send directly, the output first gets in the line, then is collected in buffer and finally
    the buffer is flushed (given out at the console). So when program crashes, buffered material does not 
    get displayed

-- endl >> This also uses the buffer technique hence makes the code inefficient. INSTEAD USE \n eg:

    std::cout << "x is equal to: " << x << '\n'; 
    OR
    std::cout << "And that's all, folks!\n";     

Q. Input the user number
A. 

#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{};       // define variable x to hold user input (and value-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}

-- You can if you want to within cin, input all at once since all inputs also get buffered and then the program
    won't be asking for more inputs later on but totally not recommended.

---------------------

Q. What happens when you input different values in the below code?
A.

1. Input = 'h' or string like 'hello' >>>>>>> This assigns the value of the number to 0
2. Input = 3.2 or 3.8 >>>>>>>>>>>>>>> Value gets assigned to 3 i.e. without the decimal
3. A very big number trillions >>>>>>>>>>>>>> cannot hold greater than 2^31-1 so last biggest val
4. Number with letter = 123abc >>>>>>>>>>> 123; here abc will remain in buffer for future extraction attempts
#include <iostream>  // for std::cout and std::cin

    int main()
    {
        std::cout << "Enter a number: "; // ask user for a number
        int x{}; // define variable x to hold user input
        std::cin >> x; // get number from keyboard and store it in variable x
        std::cout << "You entered " << x << '\n';

        return 0;
    }

---------------------

UNINITIALIZED VALUE: In my C++ version gets default = 0, but could get any in previous versions. BUT 
IN GENERAL ALWAYS INITIALIZE VARIABLES

#include <iostream>

int main()
{
    // define an integer variable named x
    int x; // this variable is uninitialized because we haven't given it a value

    // print the value of x to the screen
    std::cout << x << '\n'; // who knows what we'll get, because x is uninitialized

    return 0;
}

---------------------

NEW LINES ARE NOT ALLOWED WITHIN QUOTED TEXTS
std::cout << "Hello "
     "world!"; // prints "Hello world!"

---------------------

VARIABLE vs LITERAL: Editable vs fixed

#include <iostream>

int main()
{
    std::cout << 5 << '\n'; // print the value of a literal

    int x { 5 };
    std::cout << x << '\n'; // print the value of a variable
    return 0;
}

-- Here, for the literal directly get 5 and fixed
-- In variable, we first create a variable named x, then copy the literal value 5 into the memory location
    of x. Then when we access, we simply get the memory location of x (which is 5)

-- VERY IMP: OBJECTS AND VARIABLES REPRESENT MEMORY LOCATIONS THAT HOLD VALUES.

EG:
// five() is a function that returns the value 5
int five()
{
    return 5;
}

int main()
{
    int a{ 2 };             // initialize variable a with literal value 2
    int b{ 2 + 3 };         // initialize variable b with computed value 5
    int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d{ b };             // initialize variable d with variable value 5
    int e{ five() };        // initialize variable e with function return value 5

    return 0;
}


-- Side effects in C++ are the changes to program state caused by 
    evaluating an expression (like modifying a variable, writing to a file, printing output).

---------------------

INSERTION OPERATOR is >> (greater)
OUTPUT OPERATOR is << (lesser)

---------------------

BAD PRACTICE
-- Removed the user's input

#include <iostream>

// worst version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	num = num * 2; // double num's value, then assign that value back to num

	std::cout << "Double that number is: " << num << '\n';

	return 0;
}

BEST PRACTICES

#include <iostream>

// preferred version
int main()
{
	std::cout << "Enter an integer: ";

	int num{ };
	std::cin >> num;

	std::cout << "Double that number is: " <<  num * 2 << '\n'; // use an expression to multiply num * 2 at the point where we are going to print it

	return 0;
}

---------------------

FUNCTIONS

-- You can call another function from inside a function i.e.:

    #include <iostream>

    void doPrint()
    {
        std::cout << "In doPrint()\n";
    }

    // Definition of function main()
    int main()
    {
        std::cout << "Starting main()\n";
        doPrint(); // doPrint() called for the first time
        doPrint(); // doPrint() called for the second time
        std::cout << "Ending main()\n";

        return 0;
}

-- BUT C++ does not support nested functions.
    #include <iostream>

    int main()
    {
        void foo() // Illegal: this function is nested inside function main()
        {
            std::cout << "foo!\n";
        }

        foo(); // function call to foo()

        return 0;
    }

---------------------

RETURN VALUES

-- Function does not return on the console unless and until you have explicitly mentioned std::cout
-- So use another function in main's std::cout
-- Return statements are needed in every programs as you have defined the type of function ahead only
    so needed return else useless
-- Do not repeat yourself so if multiple times same thing just make one function and use it within 
    different variables
-- In case of multiple return statements, only the first return statement will execute and next one will
    never execute

---------------------

Q. How do you get value from user and double it using functions?
A.
    #include <iostream>

    int getValueFromUser() // this function now returns an integer value
    {
        std::cout << "Enter an integer: ";
        int input{};
        std::cin >> input;

        return input; // return the value the user entered back to the caller
    }

    int main()
    {
        int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()

        std::cout << num << " doubled is: " << num * 2 << '\n';

        return 0;
    }

---------------------

VOID

-- To tell the compiler that a function does not return a value, a return type of void is used

    #include <iostream>

    // void means the function does not return a value to the caller
    void printHi()
    {
        std::cout << "Hi" << '\n';

        // This function does not return a value so no return statement is needed
    }

    int main()
    {
        printHi(); // okay: function printHi() is called, no value is returned

        return 0;
    }

-- Here the function will execute the code inside the printHi body and on terminal will print Hi. However,
    the function through void does not have to return any type prespecified as we see in normal functions

    #include <iostream>

    // void means the function does not return a value to the caller
    void printHi()
    {
        std::cout << "Hi" << '\n';
    }

    int main()
    {
        printHi(); // okay: function printHi() is called, no value is returned

        std::cout << printHi(); // compile error

        return 0;
}

---------------------
USING RETURN VALUE OF A FN WITH ARGUMENTS AND PARAMETERS

-- You can have unnamed parameters and that would not generate warnings but unreferenced one does. 

    #include <iostream>

    int getValueFromUser()
    {
        std::cout << "Enter an integer: ";
        int input{};
        std::cin >> input;

        return input;
    }

    void printDouble(int value)
    {
        std::cout << value << " doubled is: " << value * 2 << '\n';
    }

    int main()
    {
        printDouble(getValueFromUser());

        return 0;
    }

---------------------

VARIABLES:

-- Local Variable: Defined within the body of the function
-- Within scope: Identifiers which exists since the point of definition to destruction (curly brackets)
-- Temporary objects (i.e. functions passed at std::cout without storage) have no scope as scope
    is a property of identifier and temporary objects do not have that
-- Forward Declaration: If you define a function below but try to call above, you should either reorder or
    use this. VERY USEFUL IF YOU ARE ON COMPLETELY DIFFERENT FILES AND CANNOT REORDER.
    Forward declaration without actually defining function ahead would cause linker problem but 
    will compile. Make sure to have same number of parameters in FD as in function and defn.


    #include <iostream>

    int add(int x, int y); // forward declaration of add() (using a function declaration)

    int main()
    {
        std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
        return 0;
    }

    int add(int x, int y) // even though the body of add() isn't defined until here
    {
        return x + y;
    }

-- A declaration tells the compiler about the existence of an identifier and 
    its associated type information.
-- A definition is a declaration that actually implements (for functions and types) 
    or instantiates (for variables) the identifier.

---------------------

Forward Declarations: Check FWD Declation folder.
-- First within your terminal go to the appropriate space by cd .devcontainer [one level back do cd ..]
-- Next, keep goinng within
-- Now type the following: 
    g++ main.cpp functions.cpp -o myProgram

-- Here myProgram is the name of the compiled file that you will get
-- Lastly, run: ./myProgram and the program will work

---------------------

-- Global Namespace: In C++, any name that is not defined inside a class, function, or a 
    namespace is considered to be part of an implicitly-defined namespace called the global namespace 
-- The :: symbol is an operator called the scope resolution operator.
-- So when we say std::cout we’re saying “the cout that is declared in namespace std“.
-- Alternatively, you can put on the top: using namespace std;
    HIGHLY DISCOURAGE
---------------------

-- Before compiling, file goes through preprocessor which basically strips out comments and 
    makes sure the #include are inserted [# is called preprocessor directives]
-- The entire process of preprocessing, compiling, and linking is called translation

---------------------

DIRECTIVES

-- #define: directive which can be used to create a macro. Two kinds: function like macros and 
    object like macros
-- Function like macros unsafe to use and can do whatever a normal function does
-- Object like macros with substitution text: Only used in legacy, not recommended. 

    #include <iostream>

    #define MY_NAME "Alex"

    int main()
    {
        std::cout << "My name is: " << MY_NAME << '\n';

        return 0;

-- Post preprocessing, it will look like std::cout << "My name is: " << Alex << '\n';
}


-- Conditional Compilation: Uses #ifdef, #ifndef (opp of ifdef) and #endif. Basically ask the preprocessor
    to check if the identifier has been previously defined and only then execute. 

    #include <iostream>

    #define PRINT_JOE

    int main()
    {
    #ifdef PRINT_JOE
        std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
    #endif

    #ifdef PRINT_BOB
        std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
    #endif

    #ifndef PRINT_BOB
        std::cout << "Bob\n"; // This will print Bob
    #endif

        return 0;
    }   



-- Common way to comment out things: Use if 0 (for not getting the block compiled till endif) and if 1 (when
    considering to get the block compiled)

    #include <iostream>

    int main()
    {
        std::cout << "Joe\n";

    #if 0 // Don't compile anything starting here, change to if 1 if you want compiling
        std::cout << "Bob\n";
        std::cout << "Steve\n";
    #endif // until this point

        return 0;
}


-- Combining both macro substitution with ifdef:

    #define FOO 9 // Here's a macro substitution

    #ifdef FOO // This FOO does not get replaced with 9 because it’s part of another preprocessor directive
        std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
    #endif

-- Lastly, the scope of defines are from top to bottom of the file. You can also do a multi-file basis
    where you include other header files to your main file. In such a case please add the #include file.h

---------------------

HEADER Files: 
-- To augment the painful thousands of forward declaration from one file to another, we use header
    files
-- Consider the hello world problem, you see in that std::cout, how do we get the contents? We get through
    #include <iostream>. So we are expecting the preprocessor to copy the contents from iostream to our 
    current file
-- DO NOT PUT FUNCTION AND DEFINITIONS IN HEADER FILES. Header files are typically used to put all forward
    declarations in there not for functions. Since if we put functions then the One definition rule would
    not work
-- <>: These brackets are used to tell for iostream or other files to tell that these files we did not write 
    ourselves and so it searches in include directories
-- "": These are used to tell that these files we have written ourselves
-- Avoid doing #include to .cpp files. So now the flow is:

    >> ADD.h:

    // We really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)

    // This is the content of the .h file, which is where the declarations go
    int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!

    >> MAIN.cpp

    #include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
    #include <iostream>

    int main()
    {
        std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
        return 0;
    }

    >> ADD.cpp
    #include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.

    int add(int x, int y)
    {
        return x + y;
    }


-- HEADER GUARDS: To avoid duplicating of include directives across multiple header files, use header
    guards

    EG: 

    #ifndef SOME_UNIQUE_NAME_HERE
    #define SOME_UNIQUE_NAME_HERE

    // your declarations (and certain types of definitions) here

    #endif

-- However, if you have multiple cpp files compiling and calling on same header files with definitions,
    that will cause linker error since ifdef works on each compilation of file separately.
    Hence, you should only put declarations in header files and defines and variables in source files


---------------------

ERRORS

-- C++ errors are of two types: Syntax Error and Sematic Error
-- Syntax Error: Statement invalid as per the grammar of C++
-- Semantic Error: Error in meaning i.e. division by 0, syntax is correct but meaning wrong. hard to debug

-- Resolving errors:
--- Commenting out code to see which works
--- Use std::cerr instead of std::cout, simply because cout gives a buffer and so program crashes
    without you knowing where but cerr gives unbuffered output and you know which place it crashed
--- You can add the function called to see debugging like below:

    #include <iostream>

    int getValue()
    {
    std::cerr << "getValue() called\n";
        return 4;
    }

    int main()
    {
    std::cerr << "main() called\n";
        std::cout << getValue() << '\n'; // added parenthesis here

        return 0;
}


-- Best way to add debugging statements is by using conditional directives:

    #include <iostream>

    #define ENABLE_DEBUG // comment out to disable debugging

    int getUserInput()
    {
    #ifdef ENABLE_DEBUG
    std::cerr << "getUserInput() called\n";
    #endif
        std::cout << "Enter a number: ";
        int x{};
        std::cin >> x;
        return x;
    }

    int main()
    {
    #ifdef ENABLE_DEBUG
    std::cerr << "main() called\n";
    #endif
        int x{ getUserInput() };
        std::cout << "You entered: " << x << '\n';

        return 0;
    }

-- However, this also creates a lot of clutter within the code

ALTERNATIVE: USING LOG FILES 

-- You can use log files and create a separate log file so that it doesn't show within your execution 
    and can be shared easily
-- Here example of using with plog (one of third-party). You would need to download the clog library
    first

    #include <plog/Log.h> // Step 1: include the logger headers
    #include <plog/Initializers/RollingFileInitializer.h>
    #include <iostream>

    int getUserInput()
    {
        PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

        std::cout << "Enter a number: ";
        int x{};
        std::cin >> x;
        return x;
    }

    int main()
    {
        plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

        PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

        int x{ getUserInput() };
        std::cout << "You entered: " << x << '\n';

        return 0;
    }

-- For unbuffered output during debugging use: 

    This below is the universal code

    #if defined(DEBUG) || defined(_DEBUG)
    std::cout << std::unitbuf; // enable auto-flushing in debug mode
    #endif
 
---------------------
DEBUGGING AND IDE

-- The call stack is a list of all the active functions that have been called to get to the current 
    point of execution. Whenever a new function is called, that function is added to the top of the 
    call stack. When the current function returns to the caller, it is removed from the top of the 
    call stack, and control returns to the function just below it
-- The call stack is useful in conjunction with breakpoints, when your breakpoint is hit and you want 
    to know what functions were called to get to that specific point in the code

-- Watching Window: Watching a variable is the process of inspecting the value of a variable while the 
    program is executing in debug mode. Most debuggers provide several ways to do this

-- A log file is a file that records events that occur in a program. The process of writing information 
    to a log file is called logging

-- The process of restructuring your code without changing how it behaves is called refactoring.

-- Unit testing is a software testing method by which small units of source code are tested to 
    determine whether they are correct
*/


#include <iostream>
#include <string>
int main(){
    std::string name, surname;
    std::cout << "Enter name" << std::endl;
    std::cin >> name;
    std::cout << "Enter surname" << std::endl;
    std::cin >> surname;
    std::string fullname = name + " " + surname;
    std::cout << "Fullname:" << fullname << std::endl;
    return 0; 
}


