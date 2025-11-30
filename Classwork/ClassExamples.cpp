/*
Lec 2:

Read an integer x from the keyboard
Write down a logical expression which is true if and only if x
simultaneously satisfies the following conditions:
(i) 1000 < x ≤ 10000
(ii) x is odd
(iii) x is divisible by 7
(iv) x is divisible by 41 or 43
Declare a bool variable y. Set the value of y to the value of the
logical expression above
Print y to the screen
Find a value of x for which y becomes true (e.g. x=2009)

A.

        #include <iostream>
        int main(){
            int x;
            std::cout << "Enter your no." << std::endl;
            std::cin >> x;
            bool y = ((x > 1000 && x <=10000)&&(x%2!=0)&&(x%7==0)&&(x%41==0 || x%43==0));
            std::cout << "The y is " <<y<< std::endl;
            return 0;
        }

QQ. SUm of 1/3^n for n = 100
AA.
#include <iostream>

        int main() {
            double sum = 1.0;
            double term = 1.0/3.0;
            for (int i = 1; i <= 100; i++) {
                sum += term;
                term *= 1.0/3.0;
            }
            std::cout << "The sum is\n" << sum;
        }


QQQ. Read int from user and count until you get a divisible by 5 one

AAA.
        #include <iostream>
        int main(){
            int x;
            int count = 0;
            do{
                std::cout << "Enter your number\n";
                std::cin >> x;
                count++;
            } while (x % 5 != 0);
            std::cout << "Your count is " << count;
        }

________________________________________________________________________________________


Q1. What is the problem?

        #include<iostream>
        using namespace std;
        int main()
            {

                {
                int x=5;
                }

            cout << x << endl;
            }

A1. Variavle out of scope
________________________________________________________________________________________

Q2. What happens in the below?

        #include<iostream>

        int main(){
            int x;
            x = 1024 * 1024* 1024;
            std::cout << "X is " << x << std::endl;
            x = x*2;
            std::cout << "X is " << x << std::endl;
            return 0;
        }

A2. Case of integer overflow, it gives negative value of y since does not have positive
    memory and goes to negative
________________________________________________________________________________________

Q3. What does the below when you input x as 5 give?

        #include<iostream>

        int main(){
            bool x;
            std::cout << "Enter x " << std::endl;
            std::cin >> x;
            std::cout << "Value is " << x <<std::endl;
            return 0;
        }

A3. It gives us the value of x as 1. When you do char, it takes only 1 value
    i.e. if you put 12; it will give out 1 as the value if you put 200 it gives 2
________________________________________________________________________________________

Q4. What happens in below if we change from int x to double x?

        #include <iostream>
        using namespace std;
        int main()
        {
            double x = 10;
            int y = 3;
            cout << x * y << endl;
            cout << x + y << endl;
            cout << x / y << endl;
            cout << x - y << endl;
            cout << x % y << endl;
            return 0;
        }


A4. We cannot do modulus on a double float. It works only for integers. Use fmod(x,y)
    from cmath to do.

    Rest all same, except x/y now is 3.333 instead of 3
________________________________________________________________________________________

Q5. Understanding logical
        #include <iostream>
        int main(){
            int x;
            bool y;

            std::cout << "Enter x " << std::endl;
            std::cin >> x;
            y = (1000 < x <=10000) && (x % 2 == 1) && (x % 7 == 0) && ((x%41 == 0)||(x%43 == 0));
            std::cout << "Value of y " << y << std::endl;
            return 0;
        }

________________________________________________________________________________________

Q5. Understanding increment decrement

        #include <iostream>
        int main(){
            int x;
            x = 10;
            std::cout << "First Value " << x << std::endl << "x++ Value " <<x++ << std::endl<< "Final Value " << x<< std::endl;
            x = 10;
            std::cout << "First Value " << x << std::endl<< "++x Value " << ++x <<std::endl<< "Final Value " << x<< std::endl;
            return 0;
        }
 ________________________________________________________________________________________

Q6. Calculate sum of first n integers
A6.
    int main()
        {
        int n;
        cout << "enter N: ";
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        sum += i;
        cout << sum << endl;
        return 0;
        }
________________________________________________________________________________________

Q7. Sum 1/3^n

        #include <iostream>
        int main(){
            double series = 1.0;
            const double onethird = 1.0/3.0;
            double factor = onethird;
            for (int i=0; i <=100; i++){
                series += factor;
                factor *= onethird;

            }
            std::cout << "The value of sum " << series << std::endl;
            }
________________________________________________________________________________________

Q8. REMMEBER PRODUCT IS GIVEN BY THE SYMBOL OF PI
    PRODUCT of (n^3-1)/(n^3+1) upto unlimited values of n

        #include <iostream>
        int main(){
            double sum = 1.0;
            double num;
            double den;
            double fract;
            for (int i=2; i <=1000; i++){
                num = i*i*i -1;
                den = i*i*i + 1;
                fract = num / den;
                sum *= fract;
            }
            std::cout << "The value of sum " << sum <<  std::endl;
            }
________________________________________________________________________________________

Q9. Set an integer to 1000. Use a while-loop to decrease the integer successively by 13
    until it becomes negative. Print the final value of the integer to the screen
A9.
        #include <iostream>
        int main(){
            int x = 1000;
            while (x - 13 >= 0){
                x -= 13;
            }
            std::cout << "Final value of while loop " << x << std::endl;
            }
________________________________________________________________________________________

Q10. Write a program that generates 1,000,000 random numbers and counts how many of
these numbers are in the range 500,501,...,1000 and are divisible by 163

A10.

        #include <iostream>
        #include <cstdlib>   // for rand()
        #include <ctime>     // for time()
        int main() {
            std::srand(std::time(0)); // seed random number generator
            int count = 0;
            int i = 0;
            int num;

            do {
                num = std::rand();  // generate a random integer (range: 0 to RAND_MAX)
                if (num >= 500 && num <= 1000 && num % 163 == 0) {
                    count++;
                }
                i++;
            } while (i < 1000000); // loop 1,000,000 times

            std::cout << "Count of random numbers between 500 and 1000 divisible by 163: "
                    << count << std::endl;
            return 0;
        }
________________________________________________________________________________________

Q11. Write a program that reads an integer x from the keyboard and prints the sum of the
digits of x to the screen. For instance, if x=127, the sum of the digit is 1+2+7=10
(you can assume that x is nonnegative)

A11.

        #include <iostream>
        int main(){
            int x;
            int sum = 0;
            std::cout << "Write the number " << std::endl;
            std::cin >> x;
            do{
                sum += x % 10;
                x = x / 10;
            }
            while (x>0);
            std::cout << "Sum of the number " << sum << std::endl;
        }
________________________________________________________________________________________

Q12. Prime number check

A12.
        #include <iostream>
        using namespace std;

        int main() {
            int x;

            // Keep asking until x > 0
            do {
                cout << "Enter a positive integer: ";
                cin >> x;
                if (x <= 0)
                    cout << "Invalid input. Please enter a positive number.\n";
            } while (x <= 0);   // repeat until user enters a positive number

            int i = 1, count_p = 0;

            // Prime check using do-while
            do {
                if (x % i == 0) {
                    count_p++;
                    cout << x << " is divisible by " << i << endl;
                }
                i++;
            } while (i <= x);

            if (count_p == 2)
                cout << "This is a prime number" << endl;
            else
                cout << "This is not a prime number" << endl;

            return 0;
        }
________________________________________________________________________________________

Q13. Tuples of a!=b for a and b are 10

A13.

        #include <iostream>
        using namespace std;

        int main() {
            for (int a = 1; a <= 10; a++) {          // outer loop for 'a'
                for (int b = 1; b <= 10; b++) {      // inner loop for 'b'
                    if (a != b) {                    // only print if a ≠ b
                        cout << "(" << a << ", " << b << ")" << endl;
                    }
                }
            }
            return 0;
        }
________________________________________________________________________________________

Q14. Print non-multiples of 7 & 11

A14.

        #include <iostream>
        using namespace std;

        int main() {
            for (int a = 1; a <= 100; a++) {
                if ((a % 7 == 0) || (a % 11 == 0)) {
                    continue;  // skip numbers divisible by 7 or 11
                }
                cout << a << endl;  // only executes if continue did not trigger
            }
            return 0;
        }
________________________________________________________________________________________

Q15. Enter the absolute value of 5 products but should not exceed 1e10

A15.
        #include <iostream>
        #include <cmath>   // for std::abs

        int main() {
            double a;
            double prod = 1.0;

            for (int i = 1; i <= 5; i++) {
                std::cout << "Enter number " << i << ": ";
                std::cin >> a;

                prod *= a;

                if (std::abs(prod) > 1e10) {  // if product magnitude too large
                    std::cout << "Error: absolute value of product exceeded 1e10." << std::endl;
                    break;  // stop the loop immediately
                }
            }

            // This part always runs, whether or not break was triggered
            std::cout << "Final product value: " << prod << std::endl;

            return 0;
        }
________________________________________________________________________________________

Q16. Sum of first smaller than n numbers which are multiples of 3

A16.

        #include <iostream>
        int main(){
            int n, sum;
            std::cout << "Enter your positive integer " << std::endl;
            std:: cin >> n;
            sum = 0;
            for (int i = 3; i <=n; i+=3){
                sum += i;
            }
            std::cout << "The sum is " << sum << std::endl;
        }
________________________________________________________________________________________

Q17. Sum of first n Fibonacci series

A17.

        #include <iostream>
        int main() {
            int n;
            std::cout << "Enter the number of terms: ";
            std::cin >> n;

            int a = 0, b = 1;  // first two terms

            std::cout << "Fibonacci Sequence: " << std::endl;
            std::cout << a << " " << b << " ";

            for (int i = 2; i < n; i++) {
                int next = a + b;
                std::cout << next << " ";
                a = b;
                b = next;
            }

            std::cout << std::endl;
            return 0;
        }
________________________________________________________________________________________

Q18. Make an array of ranndom 100 numbers and get min, max and avg

Method 1: std::fill(std::begin(array),std::begin(array)+10,'r');

Method 2: std::generate(arr, arr+10, std::rand);

Method 4: std::generate(a.begin(), a.end(), []() {return std::rand() % 100;}); //random between 0-99

Method 5.
        #include <iostream>
        #include <algorithm>
        #include <cmath>
        int main(){
            double min, max, avg;
            double Sam[100];
            for (int i = 0; i<100; i++){
                Sam[i] = std::rand();
            }
            min = Sam[0];
            max = Sam[0];
            double sum = 0;

            for (int i=0; i<100; i++){
                if (Sam[i] < min){
                    min = Sam[i];
                }
                if (Sam[i] > max){
                    max = Sam[i];
                }
                sum += Sam[i];
            }
            avg = sum / 100;
            std::cout << "The max value is " << max << std::endl;
            std::cout << "The min value is " << min << std::endl;
            std::cout << "The avg value is " << avg << std::endl;
            return 0;
        }
________________________________________________________________________________________

int main(){
    int n = 80000
    int primearray[n];
    primearray[0] = 2;
    for (int i = 3; i <= 1000000; i+=2){
        pow
    }
}

Q19. • Find all prime numbers less than 1,000,000, store the primes in a array of length
80,000 with entries of type int. Rule for primes 2 < p < sqrt(n)


        #include <iostream>
        #include <cmath>

        int main() {
            int count = 1;               // already one prime (2)
            bool isprime;
            int arr[80000];
            arr[0] = 2;

            for (int i = 3; i < 1000000; i += 2) { // what number are we taking
                isprime = true;
                int num_sq = std::sqrt(i);

                for (int j = 0; j < count && arr[j] <= num_sq; j++) { // don't go beyond the count of found, j would tell all prime number indices in array uptil count-1 and numsq is i whih is the number
                    if (i % arr[j] == 0) {
                        isprime = false;
                        break;
                    }
                }

                if (isprime) {
                    arr[count++] = i;
                }
            }

            std::cout << "Found " << count << " primes below 1000000 " << std::endl;
            std::cout << "Last prime: " << arr[count - 1] << std::endl;

            return 0;
        }

        USING SIEVE of ERASTENUS [VERY IMP SEE CODE PSEUDO ON WIKI]

        #include <iostream>
        #include <cmath>

        int main() {
            const int LIMIT = 1000000;
            bool arr[LIMIT + 1];

            // Step 1: Assume all numbers are prime
            for (int i = 0; i <= LIMIT; i++)
                arr[i] = true;

            // Step 2: 0 and 1 are not primes; so start by making not primes as false
            arr[0] = arr[1] = false;

            // Step 3: Sieve process
            int sq_lim = std::sqrt(LIMIT);
            for (int i = 2; i <= sq_lim; i++) {
                if (arr[i]) { // if i is still marked prime i.e. true
                    for (int j = i * i; j <= LIMIT; j += i)
                        arr[j] = false; // mark all multiples of i as composite as So when we reach a prime i, all composites below i² have already been marked by smaller primes.
                }
            }

            // Step 4: Count primes and find last one
            int count = 0;
            int last_prime = 0;
            for (int i = 2; i <= LIMIT; i++) {
                if (arr[i]) {
                    count++;
                    last_prime = i;
                }
            }

            std::cout << "Found " << count << " primes below " << LIMIT << std::endl;
            std::cout << "Last prime: " << last_prime << std::endl;

            return 0;
        }
________________________________________________________________________________________

Q19. Matrix multiplication in arrays

        #include <iostream>
        int main(){
        double A[3][2] = { { 1.2, 2.3 }
                        , { 2.3, 1.0 }
                        , { 1.0, 5.0 }};

        double B[2][3] = { { 1.0, 2.0, 3.0 }
                            ,{ 4.0, 5.0, 6.0 }};

        double C[3][3];

        for (unsigned n = 0; n<3; ++n) {
            for (unsigned m = 0; m<3; ++m) {
                C[n][m] = 0; //initialize everything to 0
                for (unsigned k = 0; k<2; ++k){
                    C[n][m] += A[n][k] * B[k][m];
        }
        }}}
________________________________________________________________________________________

Q. Sum up using pointers and then by using normal loops on a random array

A.

        #include <iostream>
        using namespace std;
        int main() {
        int A[100];
        int sum_n = 0;
        int sum_p = 0;
        for (int i =0; i <100; i++){
            A[i] = std::rand();
            sum_n += A[i];
        }
        std::cout << "The sum through pointer arithematic is " << sum_n << std::endl;
        const auto n = sizeof(A)/sizeof(*A);
        for (int *p = A, *end = A + n; p!=end; p++){
            sum_p += *p;
        }
        std::cout << "The sum through pointer arithematic is " << sum_p << std::endl;
        }
________________________________________________________________________________________

Q. Read sequence of +ve integers from console, store them in dynamic array and resize on the fly. If anything
    is invalid then ignore, if anything is negative then break and print all the entered numbers on screen
#include <iostream>
int main(){
    unsigned int capacity = 10; // this is the starting capacity which i will increase gradually
    unsigned int stored = 0; // currently 0 stored values from the user console
    unsigned int *numbers = new unsigned int[capacity]; //allocate memory
    bool invalid_input;
    int userinput;
    bool non_ngt;

    while (true){
        do {
            invalid_input = false;
            std::cout << "Enter your number" << std::endl;
            std::cin >> userinput; // Entering the inputs

            if (!std::cin){ // keeping out the non-rational inputs
                std::cout << "Invalid Interger\n";
                std::cin.clear();
                std::cin.ignore(10,'!n'); // clearing any old input from the user which was irrational
                invalid_input = true;
            } }
        while (invalid_input);

        if (userinput < 0){
            break;
        }

        if (stored == capacity){
            capacity *= 2;
            unsigned int *temp = new unsigned int [capacity];

            /// copy from previous array to this

            for (auto i = 0u; i < stored; i++){
                temp[i] = numbers[i];
            }

            delete [] numbers; // deallocate the memory

            numbers = temp; // this is very important to get the old storage space deleted and point to new storage space
            // basically numbers here after getting deleted and released from memory now points to a new block
        }

        //now that everything is valid on our integers used, simply add the user input to the stored count

        numbers[stored++] = userinput; // what this does is firstly the number that we have as valid gets added at the
                                        // correct place and secondly increases the stored value by 1 after it does.

    }

    for (auto i = 0u; i < stored; ++i) // note the use of 'auto' and of suffix 'u'
        std::cout << numbers[i] << " "<<std::endl;

    // release memory
    delete[] numbers;

    return 0;
}
________________________________________________________________________________________

Q. Define an array of size 10 containing the sequence of characters “hello”
    Print the elements of the array as integers
     Print the array interpreting it as a null-terminated string
      Print the size of the array in bytes (use sizeof)
       Compute and print to the string the size of the null-terminated string contained in the array in two alternative ways
        using the CRT function strlen (requires #include <cstring>) and print it to the string
         use a loop to find the position of the first null character

A.

        const char msg[10] = "Hello"; // can define the array like this, all rest characters get value as 0
        // print all elements of the array, converted to integers
        cout << "Binary content: ";
        for (int i = 0; i < sizeof(msg); ++i)
            cout << static_cast<int>(msg[i]) << " ";
        cout << endl;

        // print array interpreted as a null-terminated string
        cout << "String: " << msg << endl;

        // print size of the array in bytes
        cout << "Size in bytes: " << sizeof(msg) << endl;

        // print length of array computed with the CRT function strlen
        cout << "String length: " << strlen(msg) << endl;
        // print length of array computed with a loop
        for (int i = 0; i < sizeof(msg); ++i)
            if (msg[i] == 0) {
                cout << "String length: " << i << endl;
                break;}
________________________________________________________________________________________

Q. Add the absolute sum of all elements of the array

A.

        int addArr(int *v, unsigned int n){
            int sum = 0;
            for (int i = 0; i < n; i++){
                sum += std::abs(v[i]);
                return sum;
________________________________________________________________________________________

Q. Write down the definition of a function that checks if two integers have the same parity (both even or both odd) and returns
the answer as a bool value

A.
        bool parity() {
            int a, b;
            std::cout << "Write the first integer: ";
            std::cin >> a;
            std::cout << "Write the second integer: ";
            std::cin >> b;

            // Return true if both are even or both are odd
            return (a % 2 == b % 2);
        }
________________________________________________________________________________________

Q. Fill array with random numbers between a & b [a,b]. By default, a vector of random numbers in [0,1] should be returned

A.

        void RandVector(int n, double *result, double a = 0.0, double b = 1.0) {
            double max = RAND_MAX;

            for (int i = 0; i < n; i++) {
                // cast rand() to double to avoid integer division
                double x = (static_cast<double>(rand()) / max) * (b - a) + a;
                result[i] = x;
            }
        }

        int main() {

            int n = 6;
            double *result = new double[n]; // allocate array

            RandVector(n, result, 0.0, 1.0); // fill array with random numbers in [4,5]

            std::cout << "Random numbers: ";
            for (int i = 0; i < n; i++) {
                std::cout << result[i] << " ";
            }
            std::cout << std::endl;

            delete[] result; // free allocated memory
            return 0;
        }
________________________________________________________________________________________

Q. Write scalarProduct

A.

    double scalarProduct(const double* x, const double* y, size_t n)
    {
        double s = 0.0;
        // implement the loop using pointer arithmetic
        for (const double* end = x + n; x != end; )
            s += (*x++) * (*y++);
        return s;
    }


    OR

    double scalarProduct(const double *v1, const double *v2, size_t n){
    double sum=0;
    for (int i = 0; i < n; i++){
        sum += v1[i] * v2[i];
    }
    return sum;
}
________________________________________________________________________________________

Q. Compute the roots and solutions of complex number

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
________________________________________________________________________________________
Q.  Prompt the user to repeadetly input positive integers numbers from the console.  A negative number cause termination
of the input phase. Upon termination of the input phase, all inputed numbers are output to the console. Data structure used
is a dynamic array
A.

#include <iostream>
int getInteger(){
    int userinput;
    bool invalid_input;

    do {
        invalid_input = false;
        std::cout << "Add the new number"<<std::endl;
        std::cin >> userinput;
        if (!std::cin){
            std::cin.clear();
            std::cin.ignore(10, '\n');
            invalid_input = true;
        }
    }
    while (invalid_input);

    return userinput;
    }

    // Function called when everything is all right and we are adding
unsigned int *growArray(const unsigned int *current, unsigned& capacity){ //here i return a pointer to an array of unsigned int
    unsigned size = capacity;
    capacity *= 2;
    unsigned int *temp = new unsigned int[capacity];
    for (auto i = 0u; i < capacity; i++){ // 0u refers to unsigned literal
        temp[i] = current[i]; // copy all elements from current pointer to temp
    }
    delete [] current;
    return temp;}

void addNewNumber(unsigned& size, unsigned int *current, unsigned int userinput){
    current[size++] = userinput; // stores at index 0 and then increements it to 1. SO size++ needed
}

void printArray(const unsigned int *current, unsigned int size){
    for (auto i = 0u; i < size; i++){
        std::cout<<current[i]<<std::endl;
    }
}

int main(){
    unsigned int capacity = 10;
    unsigned int size = 0;
    unsigned int *number = new unsigned int[capacity]; // LHS:Declares a pointer variable named number that can point to an unsigned int
        // (or the start of an array of them). RHS: Dynamically allocates an array of capacity elements of type unsigned int on the  heap (not the stack).
    while (true){
        int userinput = getInteger();
        if (userinput < 0){
            break;
        }

        if (size == capacity){
            number = growArray(number,capacity);
        }

        addNewNumber(size, number, userinput);
    }

    printArray(number, size);
    delete [] number;
    return 0;
}

HAVE PUT ONE IN HEADER FILE ALSO

________________________________________________________________________________________

Q. Factorial

A. Recursive

    unsigned factorial(unsigned n)
        {
        if (n > 1)
        return n*factorial(n-1);
        return 1;
        }

    ITERATIVE

    unsigned factorial(unsigned n)
    {
        unsigned f = 1;
        while(n > 1)
        f *= n--;
        return f;
    }
________________________________________________________________________________________

Q. Build the binary tree in pre-order

A.


#include <iostream>
using namespace std;

struct Node
{
    int value; // value of the node
    Node* left; // pointer to the left child >>> a self-referential struct, I only put a pointer isnide the node not another struct; cannot put anther struct but can put a node
    Node* right; // pointer to the right child >>> a self-referential struct, I only put a pointer isnide the node not another struct
}; // you do this to create 8 bytes pointer

Node* createNode(int val, Node* leftChild, Node* rightChild)  //It fills the fields of that new node using the arguments you passed.
//here Node* i.e. the memory address is the returntype; left and right are pointers
{
    Node* n = new Node; // dynamically allocate memory on the heap
    n->value = val; // set value
    n->left = leftChild; // set the left pointer
    n->right = rightChild; // set the right pointer
    return n; // return pointer
}

Node* buildTree()
{
    Node *n1, *n2, *n3; // declaring 3 pointers, n1, n2, and n3 and each of these points to a specific node
    // each node represents a tree node with val, left and right given

    n1 = createNode(4, NULL, NULL);
    n1 = createNode(2, n1, NULL); // you overwrote the pointer however node 4 exists and now is connected

    n2 = createNode(7, NULL, NULL);
    n2 = createNode(6, NULL, n2);

    n3 = createNode(5, NULL, NULL);
    n3 = createNode(3, n3, n2);

    n1 = createNode(1, n1, n3); // n1 is reused to hold the rootl; could have used n2 or n3 also does not matter, it is arbitrary


    return n1;
}

void preOrder(Node* root) // This is the desired function, on how to go
{
    if (root == NULL) // initially which means no tree
        return;

    cout << root->value << " "; // otherwise print out the value always right from the top
    preOrder(root->left); // next you go left, but then again you recurse on it till you reach null
    preOrder(root->right); // then you go right
}

int main()
{
    Node* root = buildTree();
    cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    return 0;
}

HOW IT WORKS

Step 5: Node 3 (right child of 1)

- root is not NULL → print 3

- Recurse left → node 5

- Recurse right → node 6

Step 6: Node 5

- Print 5

- Left & right → NULL → return

- Done with 5, backtrack to 3
________________________________________________________________________________________

Q.

A. BinTree2

void visitTreeInPreOrder(Node *node, void(*action)(Node*, void*), void *args ) // takes a node of tree, a function pointer called actiona nd a pointer to extra arguments called args
{
    if (node != nullptr) {
        action(node, args);                             // performs action
        visitTreeInPreOrder(node->left, action, args);  // visit left
        visitTreeInPreOrder(node->right, action, args); // visit right
    }
}

void printNode(Node *n, void *)
{
    cout << n->value << " ";  // no end of line; since there is no use of void just keep no pointer variable here
}

void incrNode(Node *n, void *a)
{
    int *p = reinterpret_cast<int*>(a); // here we use void however since we want it to work like an int; you can change void to int
    n->value += *p;
}

int main()
{
    Node *treeTop = buildTree();  // build your tree

    visitTreeInPreOrder(treeTop, &printNode, nullptr);  // print all nodes
    cout << endl;

    int x = 3;
    visitTreeInPreOrder(treeTop, &incrNode, &x);      // increment all node values by 3

    visitTreeInPreOrder(treeTop, &printNode, nullptr); // print again
    cout << endl;// understand callback is simply referencing the pointer of a function within another function's argument

    return 0;
}
________________________________________________________________________________________

Q. Argument odd or even

A. bool isOdd(unsigned n) {
    return n % 2 != 0;
}

________________________________________________________________________________________
Q. Write and test a function with function head below, that prints the n entries of the array v
separated by spaces

A.
#include <iostream>

void printVec(double v[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << v[i];
        if (i < n - 1) std::cout << " ";   // print space between entries
    }
    std::cout << std::endl;
}


________________________________________________________________________________________

Q. Write and test a function with function head below, that returns true if the elements of the
array are in increasing order, false otherwise


#include <iostream>
#include <cmath>
bool isOrdered(const int *v, unsigned n) {
    if (n <= 1) return true;  // 0 or 1 element is always ordered
    for (unsigned i = 0; i < n - 1; i++) { // very important that i < n-1 otherwise out of bounds
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}
________________________________________________________________________________________

Q. Write and test a function with function head below, which returns the n-th prime number. For
instance nthPrime(4) should return 7, which is the 4-th prime number (2,3,5,7,...)

A.

bool isPrime(unsigned x) {
    if (x < 2) return false; // 0 and 1 are not prime numbers
    for (unsigned i = 2; i * i <= x; ++i) { // fastest way to check for prime trick, check if i*i has any perfect divisor
        if (x % i == 0) return false;
    }

    // why the above works: for any number say 100 = 25 * 4; i.e. one factor is small and other is big than sqrt 100 i.e. 10; therefore if you
    // have considered the smaller divisor, then in any case the bigger would also have been considered so only check for underoot x
    return true;
}

unsigned nthPrime(unsigned n) {
    if (n == 0) return 0;

    unsigned count = 0;
    unsigned candidate = 1;

    while (count < n) {
        ++candidate;

        // simple prime test
        bool isprime = true;
        for (unsigned i = 2; i * i <= candidate; ++i) {
            if (candidate % i == 0) {
                isprime = false;
                break;
            }
        }

        if (isprime) {
            ++count;
        }
    }

    return candidate;   // this is the n-th prime
}

________________________________________________________________________________________

Q. Euclidean distance to get to GCD

A.
        #include <iostream>
        #include <cmath>


        unsigned int gcd(unsigned int *m, unsigned int *n) {
            if (*m == 0) return *n;
            if (*n == 0) return *m;

            if (*m > *n) {
                unsigned int temp = *m % *n;
                return gcd(&temp, n); // be careful here you would in a recursive way want a memory address
            } else {
                unsigned int temp = *n % *m;
                return gcd(m, &temp);
            }
        }

        int main() {
            unsigned int m, n;
            std::cin >> m >> n;

            std::cout << gcd(&m, &n);
            return 0;
        }

________________________________________________________________________________________

Q. Hanoi Tower >>> 2^n - 1 moves to solve

A.
        #include <iostream>
        using namespace std;

        struct Pole {
            unsigned disk_ids[5];  // indices of the disks (5 disks maximum) >>> array that stores disk id
            unsigned n_disks = 0;       // number of disks in the pole; top disk index is n_disks - 1
        };
        // top disk would be disk_ids[p.n_disks-1] where p is pole

        unsigned RemoveTopDisk(Pole& p)
        {
            return p.disk_ids[--p.n_disks];
        }
            /////If n_disks was 3: Disks at indices: 0, 1, 2 (top). --p.n_disks → becomes 2 (decrement n_disks 2 and return that also)
            ///// Return disk_ids[2] (the old top). Now the pole has 2 disks.

        void AddTopDisk(Pole& p, unsigned id)
        {
            p.disk_ids[p.n_disks++] = id;
        }
            ///If n_disks was 2: Assign disk_ids[2] = id. Increment → n_disks = 3

        // move n disks from one pole to the other
        void moveDisks(Pole poles[3], unsigned from, unsigned to, unsigned aux, unsigned n) {
            if (n == 1) {
                // move top disk
                auto disk_id = RemoveTopDisk(poles[from]);
                AddTopDisk(poles[to], disk_id);
                cout << "move disk " << disk_id << " from pole " << from << " to pole " << to << endl;
            }
            else {
                moveDisks(poles, from, aux, to, n - 1); // Move n−1 disks from from → aux (using to as auxiliary)
                moveDisks(poles, from, to, aux, 1);  // Move 1 disk from from → to. (That’s the biggest disk of this group.)
                moveDisks(poles, aux, to, from, n - 1); //Move n−1 disks from aux → to (using from as auxiliary).
            }
        }

        int main()
        {
            Pole poles[3]; // create 3 poles: pole[0], pole[1], pole[2]

            const unsigned nDisks = 3; // 3 disks for now

            // init pole[0] with 3 disks
            for (unsigned i = 0; i < nDisks; ++i)
                AddTopDisk(poles[0], nDisks - i); // so pole[0] now has 3 disks in the order bottom to top as 3,2,1

            // print moves
            moveDisks(poles, 0, 2, 1, nDisks);

            return 0;
        }

________________________________________________________________________________________

Q. Creating dynamic array based on userinput

#include <iostream>

int getInteger(const char *promptMsg);

using namespace std;

struct MyArray
{
    unsigned int m_capacity;   // storage capacity
    unsigned int m_size;       // how many numbers have been stored so far
    unsigned int *m_numbers;   // allocate memory storage

    void initialize()
    {
        m_capacity = 10;   // storage capacity
        m_size = 0;        // how many numbers have been stored so far
        m_numbers = new unsigned int[m_capacity];  // allocate memory storage
    }

    void addNewNumber(unsigned userInput)  // no need to pass size and and numbers
    {
        if (m_size == m_capacity)
            growArray();
        m_numbers[m_size++] = userInput;
    }

    void growArray()
    {
        unsigned size = m_capacity;

        // increase capacity variable
        m_capacity *= 2;

        unsigned int *tmp = new unsigned int[m_capacity];

        for (unsigned i = 0u; i < size; ++i)
            tmp[i] = m_numbers[i];

        delete[] m_numbers;
        m_numbers = tmp;
    }

    void printArray()
    {
        for (unsigned i = 0u; i < m_size; ++i)
            cout << m_numbers[i] << " ";
        cout << endl;
    }

    void release()
    {
        // release memory
        delete[] m_numbers;
    }
};


int main()
{
    MyArray v;

    v.initialize();

    // we start an infinite loop, which we will stop with 'break'
    // we keep asking the user to enter a number until a negative number is entered
    while (true) {

        int userInput = getInteger("Enter a non-negative integer or a negative to terminate: ");

        if (userInput < 0)
            break;

        // At this point we are sure have a valid integer input, we know it is positive
        // and we know we have enough storage space to add it
        // So we add the new number to the existing storage
        v.addNewNumber(userInput);
    }

    // we print the numbers
    v.printArray();

    // release memory
    v.release();

    return 0;
}

________________________________________________________________________________________

Q.

A.


#define _CRT_SECURE_NO_WARNINGS   // allows C functions like strcpy() without warnings

#include <iostream>   // for cout, ostream
#include <cstring>    // for strlen(), strcpy(), strncpy()

using namespace std;  // lets us write cout instead of std::cout


// ----------------------
//    STRING CLASS
// ----------------------
class String
{
    char* m_data = nullptr;   // Each String object stores its characters in HEAP memory.
                              // m_data points to the first character of this dynamically allocated C-string.

    // NOTE: Inside any member function of this class (like reset, operator+=, operator=),
    // there is an implicit pointer called "this" which points to the CURRENT String object.
    //  - "this"       → pointer to the current object
    //  - "*this"      → the current object itself (dereferenced)
    //  - this->m_data → the m_data of the current object


    // Private helper function that makes this object contain a NEW string "s".
    // It deletes old memory, allocates new memory, and copies the characters from s.
    void reset(const char* s)
    {
        if (s != m_data) {        // Avoid deleting and copying if "s" is already the same memory we hold.
            delete[] m_data;      // Free old memory (if any).

            // Allocate enough space for all characters of s PLUS the null terminator '\0'
            m_data = new char[strlen(s) + 1];

            // Copy the content of s into our newly allocated memory.
            strcpy(m_data, s);
        }
    }

    // operator<< needs access to private m_data to print the string.
    // Declaring it as a friend allows it to access private members directly.
    friend ostream& operator<<(ostream& os, const String& s);


public:

    // Default constructor: create an empty string ("")
    String()
    {
        reset("");   // m_data will point to a single '\0'
    }

    // Constructor from C-string (literal like "Hello")
    String(const char* s)
    {
        reset(s);    // Allocate memory and copy s
    }

    // Copy constructor: deep copy another String object
    // Called when we do: String s2 = s1;
    String(const String& s)
    {
        reset(s.m_data);   // Create a new copy of the other object's characters
    }


    // Destructor: runs when object goes out of scope
    // Frees the memory previously allocated for the characters
    ~String()
    {
        delete[] m_data;
    }


    // Return the number of characters (not counting the null terminator)
    size_t length() const
    {
        return strlen(m_data);
    }

    // Return the internal C-string (read-only)
    const char* c_str() const
    {
        return m_data;
    }


    // Operator += to append a C-string (const char*)
    String& operator+=(const char* rhs)
    {
        size_t n2 = strlen(rhs);   // Length of string to append

        if (n2 > 0) {              // If rhs is NOT empty
            size_t n1 = length();  // Current string length

            // Allocate space for old string + new string + null terminator
            char* tmp = new char[n1 + n2 + 1];

            // Copy current string into tmp
            strncpy(tmp, m_data, n1);

            // Append new string starting at position n1
            strcpy(tmp + n1, rhs);

            delete[] m_data;       // Free old memory
            m_data = tmp;          // Point to the new combined string
        }

        // "this" is a pointer to the current object, so "*this" is the current String object.
        // We return a reference to *this so that calls can be chained:
        // e.g. s1 += "a" += "b";
        return *this;
    }


    // Operator += to append another String object
    // Reuses the previous operator+= that accepts const char*
    String& operator+=(const String& rhs)
    {
        // "*this" is the current String object.
        // "*this += rhs.m_data" means:
        //   - call operator+=(const char*) on the current object,
        //   - append rhs.m_data (its C-string) to our current string,
        //   - that operator+= returns *this, so we return that same object reference.
        return *this += rhs.m_data;
    }


    // Assignment operator: assign from C-string (s = "Hello")
    String& operator=(const char* rhs)
    {
        reset(rhs);      // Replace contents with a new copy of rhs
        // Again, returning "*this" means "return a reference to the current object",
        // so we can chain assignments if we want: s1 = "A" = "B"; (even if weird).
        return *this;
    }

    // Assignment operator: assign from another String (s1 = s2)
    String& operator=(const String& rhs)
    {
        // "*this = rhs.m_data" calls the other assignment operator (the one that takes const char*)
        // on the CURRENT object.
        // That operator returns "*this", so we just return it again.
        return *this = rhs.m_data;
    }
};


// Operator<< to print the String using cout
ostream& operator<<(ostream& os, const String& s)
{
    os << s.m_data;   // Output the underlying C-string
    return os;        // Return stream for chaining (e.g., cout << s1 << s2)
}


// ----------------------
//      MAIN PROGRAM
// ----------------------
int main()
{
    String s1("Hello");   // Calls constructor with const char*
    String s2("World");   // Same

    cout << s1 << endl;   // Prints: Hello

    s1 += " ";            // Append space → "Hello "
    cout << s1 << endl;

    s1 += s2;             // Append "World" → "Hello World"
    cout << s1 << endl;

    String s3;            // Default constructor → empty string ""
    s3 = s1;              // Assignment → deep copy of "Hello World"
    cout << s3 << endl;

    return 0;             // Destructors run for s3, s2, s1
}


str copy works like
char src[] = "Hello";
char dest[10];

strcpy(dest, src);

dest: ['H','e','l','l','o','\0', ?, ?, ?, ?]

char* strcpy(char* dest, const char* src);
dest → pointer to the destination memory

src → pointer to the source memory

Important: Both are pointers, not arrays themselves.
char* m_data = "Hello";
m_data is a pointer to the first character ('H') in memory.

But because C-strings are null-terminated, this single pointer “represents the whole string.”

m_data → 'H' 'e' 'l' 'l' 'o' '\0'

this points to the object you are currently working with.

*this means "the actual object itself" (not a pointer).

String s1;
s1 += "Hello";
Here, the function operator+= is being called on s1.

Inside the function, this points to s1.

________________________________________________________________________________________

Q. Hanoi Tower:

#include <iostream>
#include <iomanip>

using namespace std;

const unsigned nMaxDiscs = 100; // max no. of disks a tower can hold


class Tower
{
    char     m_towerId;          // tower identifier, could be a,b,c
    unsigned m_size;             // number of non-empty slots so tells us how many disks are in the tower
    unsigned m_slots[nMaxDiscs]; // array storing disc id; slots for discs; 1 smallest size while 3 biggest and so on (LIFO)

public:
    Tower(char id) : m_towerId(id), m_size(0) {} // can create Tower p1('a')

    // push a disc at the top of the tower
    void push(unsigned discId)
    {
        m_slots[m_size++] = discId; // places disk at the top and then increases size
    }

    // pop a disc from the top of the tower
    unsigned pop()
    {
        return m_slots[--m_size]; // reduces both size and then array of m_slots also
    }

    char name() const { return m_towerId; } // simply return a, b or c
};

void move(unsigned nDiscs, Tower& p1, Tower& p2, Tower& p3, unsigned& nMoves)
{
    if (nDiscs > 1) {
        // recursion
        move(nDiscs-1, p1, p3, p2, nMoves);
        move(1, p1, p2, p3, nMoves);
        move(nDiscs-1, p3, p2, p1, nMoves);
    }
    else { // in case it is only 1 disk then simple
        // move one disc and print message
        unsigned discid = p1.pop();
        p2.push(discid);
        cout << setw(4) << ++nMoves << ".  "
             <<  p1.name() << " --> " << p2.name()
             << ": " << discid << endl;
    }
}


int main()
{
    Tower p1('a');
    Tower p2('b');
    Tower p3('c');

    const unsigned nDiscs = 4;

    // initialize, all discs on tower1
    for (unsigned i = 0; i < nDiscs; ++i)
        p1.push(nDiscs-i);

    // move nDiscs discs from tower1 to tower2 using tower3
    unsigned nMoves = 0;
    move(nDiscs, p1, p2, p3, nMoves); //“Move 4 discs from tower a to tower b using tower c as helper”
    cout << "Total number of moves: " << nMoves << endl;

    return 0;
}

________________________________________________________________________________________

class Matrix
{
    // -------------------------
    // DATA MEMBERS
    // -------------------------
    unsigned m_rows;   // how many rows the matrix has
    unsigned m_cols;   // how many columns the matrix has
    double*  m_data;   // pointer to a 1D dynamic array storing all elements

public:
    // -------------------------
    // 1) DEFAULT CONSTRUCTOR
    // -------------------------
    // Creates an "empty" matrix with no rows, no columns, and no allocated data.
    Matrix()
        : m_rows(0), m_cols(0), m_data(nullptr)  // member-initializer list
    {
        // Nothing else to do here.
        // m_data == nullptr means "no memory allocated yet".
    }

    // -------------------------
    // 2) CONSTRUCTOR WITH ROWS, COLS, AND INITIAL VALUE
    // -------------------------
    // This constructor creates a matrix with 'rows' rows and 'cols' columns,
    // and initializes every element to the value 'initVal'.
    Matrix(unsigned rows, unsigned cols, double initVal = 0.0)
        : m_rows(rows),    // store the requested number of rows
          m_cols(cols)     // store the requested number of columns
    {
        // If either dimension is zero, we treat this as an "empty" matrix.
        if (m_rows == 0 || m_cols == 0) {
            // No elements => no need to allocate memory.
            m_data = nullptr;
        } else {
            // We have at least 1 row and 1 column.
            // Allocate a 1D array of size rows * cols.
            // Storage layout is row-major: row0[col0..colN-1], row1[col0..], ...
            m_data = new double[m_rows * m_cols];

            // Fill every element with the same initial value 'initVal'.
            // Total number of elements = m_rows * m_cols.
            for (unsigned i = 0; i < m_rows * m_cols; ++i) {
                m_data[i] = initVal;
            }
        }
    }

    // -------------------------
    // 3) COPY CONSTRUCTOR (DEEP COPY)
    // -------------------------
    // This is called when we create a new Matrix from an existing one, e.g.:
    // Matrix m2(m1);
    // It must create its *own* copy of the data (no shared pointers).
    Matrix(const Matrix& other)
        : m_rows(other.m_rows),   // copy number of rows from 'other'
          m_cols(other.m_cols)    // copy number of columns from 'other'
    {
        // Again, if the other matrix has no size, we don't allocate memory.
        if (m_rows == 0 || m_cols == 0) {
            m_data = nullptr;
        } else {
            // Allocate our own separate storage with the same size.
            m_data = new double[m_rows * m_cols];

            // Copy each element from the 'other' matrix into our storage.
            for (unsigned i = 0; i < m_rows * m_cols; ++i) {
                m_data[i] = other.m_data[i];
            }
        }
    }

    // -------------------------
    // 4) DESTRUCTOR
    // -------------------------
    // Called automatically when a Matrix object goes out of scope or is deleted.
    // We must free the dynamic memory we allocated with 'new[]'.
    ~Matrix()
    {
        delete[] m_data;   // safe even if m_data == nullptr
    }

    // -------------------------
    // 5) ASSIGNMENT OPERATOR (DEEP COPY)
    // -------------------------
    // Handles assignments like:  m3 = m2;


    Matrix& operator=(const Matrix& other)
    {
        // Self-assignment check: "if I assign a matrix to itself, do nothing" like m3 =m3
        if (this == &other) {
            return *this;
        }

        // If the dimensions are different, we must reallocate.
        if (m_rows != other.m_rows || m_cols != other.m_cols) {
            // Free the old storage.
            delete[] m_data;

            // Copy the new dimensions.
            m_rows = other.m_rows;
            m_cols = other.m_cols;

            // Allocate new storage (or set to nullptr if empty).
            if (m_rows == 0 || m_cols == 0) {
                m_data = nullptr;
            } else {
                m_data = new double[m_rows * m_cols];
            }
        }

        // If there is valid storage, copy the data.
        if (m_data != nullptr) {
            for (unsigned i = 0; i < m_rows * m_cols; ++i) {
                m_data[i] = other.m_data[i];
            }
        }

        return *this;  // return reference to the current object to allow chaining
    }

    // -------------------------
    // 6) ACCESSORS FOR SIZE
    // -------------------------
    // Return the number of rows.
    unsigned nRows() const
    {
        return m_rows;
    }

    // Return the number of columns.
    unsigned nColumns() const
    {
        return m_cols;
    }

    // -------------------------
    // 7) ELEMENT ACCESS - NON-CONST VERSION
    // -------------------------
    // This allows syntax like:
    //   m(i, j) = 3.14;
    //
    // We return a reference to the element so it can appear on the left side
    // of an assignment.
    double& operator()(unsigned i, unsigned j)
    {
        // Convert 2D index (i, j) to 1D index using row-major order:
        // index = i * m_cols + j ; important calculation
        return m_data[i * m_cols + j];
    }

    // -------------------------
    // 8) ELEMENT ACCESS - CONST VERSION
    // -------------------------
    // This is used when the Matrix is const, e.g.:
    //   const Matrix& cm = m;
    //   double x = cm(i, j);
    //
    // We return by value here (a copy of the double) because we don't want
    // to allow modification through a const Matrix.
    double operator()(unsigned i, unsigned j) const
    {
        return m_data[i * m_cols + j];
    }
};



// Your main for testing
int main()
{
    // create a 3 by 2 matrix and initialize all elements to 0.0
    Matrix m1(3, 2, 0.0);
    Matrix m2(m1); // create copy of the matrix via copy constructor

    // requires methods nRows() and nColumns()
    for (unsigned i = 0, n = min(m2.nRows(), m2.nColumns()); i < n; ++i)
        m2(i,i) = 1; // requires ‘double &operator()(int,int)’

    Matrix m3; // invoke default constructor, make sure we set m_data=0
    m3 = m2;   // create copy of the matrix via assignment operator
    m3 = m3;   // self-assignment test

    const Matrix& cm = m3; // const reference to m3
    for (unsigned i=0; i < cm.nRows(); ++i)
        for (unsigned j=0; j < cm.nColumns(); ++j)
            cout << cm(i,j) << endl; // uses const operator()(int,int) const

    return 0;
}

OKAY ONE BIG DIFFERENCE:

1. Copy constructor and assignment operator does same thinsg but are diff

Copy constructor is >>>>>>> Matrix m2(m1);

Assignment is >>>>>>>>>>>>>>>>>>> Matrix m3; m3 = m2;

Therefore for deep copy you need to overload the assignment also, so implement both

Inside any non-static member function, 'this' is a pointer to the object on the left-hand side of the call.

So:
m3 = m2;
compiler sees >> m3.operator=(m2);

Always remember if doing const on the method, then please do not pass any reference only copies
________________________________________________________________________________________

Q. Create a 100 digit size array and then swap the values such that first with last, and so on

A.

Without std::swap

#include <iostream>
using namespace std;

template <typename T>
void swapValues(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int A[100];

    // 1) Fill array with 0,1,2,...,99
    for (int i = 0; i < 100; ++i) {
        A[i] = i;
    }

    // 2) Reverse using 50 swaps
    for (int i = 0; i < 50; ++i) {
        swapValues(A[i], A[99 - i]);   // A[i] <-> A[99-i]
    }

    // 3) Print to check
    for (int i = 0; i < 100; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}


With std::swap

#include <iostream>
#include <algorithm>   // for std::swap
using namespace std;

int main()
{
    int A[100];

    // 1) Fill array with 0,1,2,...,99
    for (int i = 0; i < 100; ++i) {
        A[i] = i;
    }

    // 2) Reverse using 50 swaps
    for (int i = 0; i < 50; ++i) { // only go till 50 otherwise will swap back again
        std::swap(A[i], A[99 - i]);   // Swap symmetric elements
    }

    // 3) Print all entries
    for (int i = 0; i < 100; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
________________________________________________________________________________________

Q. Write program that generates random permutation of 0-99

A. Shuffle using swap: Idea is create an array of integer length 100 with 0-99 as entries

    -- Now for every i= 99,98 ... 1 create a j such that:
        j = rand() % (i+1) // you always do i+1 since take i = 99; if you do it rand()%99 then it will give all numbers
                            // between 0 and 98, therefore always do i+1
        and then now you can simply swap the values between j and i so you are creating a random indice and then swapping values
        into the already made simple i array

#include <iostream>
#include <algorithm>   // for std::swap
#include <cstdlib>     // for rand()
#include <ctime>       // for time()
using namespace std;

int main()
{
    srand(time(nullptr));   // Seed RNG once, important for seed

    int Perm[100];

    // 1) Fill array with 0,1,2,...,99
    for (int i = 0; i < 100; ++i) {
        Perm[i] = i;
    }

    // 2) Fisher-Yates shuffle: i = 99, 98, ..., 1
    for (int i = 99; i > 0; --i) {
        int j = rand() % (i + 1);    // random number in [0..i]
        std::swap(Perm[i], Perm[j]); // swap the values
    }

    // 3) Print the result to verify randomness
    for (int i = 0; i < 100; ++i) {
        cout << Perm[i] << " ";
    }
    cout << endl;

    return 0;
}
________________________________________________________________________________________

Q. Generate 10,000 random permutations of 0,1,…,99 and determine how many of these permutations have no fixed point
i.e. perm[i] == i

Here a permuation So in code, a permutation is just an array like:

int perm[5] = {4, 1, 3, 0, 2};

so if 3 1 2 0 4
perm[1] = 1 → fixed point!

perm[4] = 4 → fixed point!

Now a 10,000 random perm means
Permutation 1 → perm[0..99]
Permutation 2 → perm[0..99]
Permutation 3 → perm[0..99]
...
Permutation 10000 → perm[0..99]

A permutation must contain all numbers between 0-n-1 that is why we use Fischer Yales tehorem of
    swapping indices and shuffling the order

A.
#include <iostream>
#include <cstdlib>  // for std::rand, std::srand
#include <ctime>    // for std::time
#include <algorithm> // for std::swap

// Template function to check if a permutation has no fixed point
template <typename T>
bool hasNoFixedPoint(const T perm[], int n) { // T perm[] is simply an array which will hold one permutation
    for (int i = 0; i < n; ++i) {
        if (perm[i] == i) {
            return false;
        }
    }
    return true; // no index i with Perm[i] == i
}

// Generate a random permutation of 0, 1, ..., n-1 into perm[]
void generateRandomPermutation(int perm[], int n) {
    // initialize as 0, 1, ..., n-1
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }

    // Fisher–Yates shuffle
    for (int i = n - 1; i > 0; --i) { // simply shuffle the order, this is useful since it ensures no duplication
                                        // you might shuffle the values multiple times however can't introduce the same value twice
        int j = std::rand() % (i + 1); // random index in [0, i]
        std::swap(perm[i], perm[j]);
    }
}

int main() {
    const int N = 100;          // size of each permutation: 0..99
    const int NUM_TRIALS = 10000; // number of permutations to test

    int perm[N];
    int countNoFixedPoint = 0;

    std::srand(static_cast<unsigned>(std::time(nullptr))); // seed RNG

    for (int t = 0; t < NUM_TRIALS; ++t) {
        generateRandomPermutation(perm, N);

        if (hasNoFixedPoint(perm, N)) {
            ++countNoFixedPoint;
        }
    }

    std::cout << "Out of " << NUM_TRIALS
              << " permutations, "
              << countNoFixedPoint
              << " have no fixed point."
              << std::endl;

    return 0;
}

*/




#include <iostream>
#include <cmath>


struct String{
    char* name;
    Struct() :name(NULL){};
    Struct(unsigned size) : name(new char[size]){};

    const String& operator+=(String i, String j) const {return ij}
}

unsigned int gcd(unsigned int *m, unsigned int *n) {
    if (*m == 0) return *n;
    if (*n == 0) return *m;

    if (*m > *n) {
        unsigned int temp = *m % *n;
        return gcd(&temp, n);
    } else {
        unsigned int temp = *n % *m;
        return gcd(m, &temp);
    }
}

int main() {
    unsigned int m, n;
    std::cin >> m >> n;

    std::cout << gcd(&m, &n);
    return 0;
}

















