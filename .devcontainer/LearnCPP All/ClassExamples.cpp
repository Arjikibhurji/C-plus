/* 

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

Q10. Write a program that generates 1000,000 random numbers and counts how many of
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

Q15. Enter the absolute value fo 5 products but should not exceed 1e10

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

A18.
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

Q19. • Find all prime numbers less than 1,000,000, store the primes in a array of length
80,000 with entries of type int. Rule for primes 2 < p < sqrt(n) 


        #include <iostream>
        #include <cmath>

        int main() {
            int count = 1;               // already one prime (2)
            bool isprime;
            int arr[80000];
            arr[0] = 2;

            for (int i = 3; i < 1000000; i += 2) {
                isprime = true;
                int num_sq = std::sqrt(i);

                for (int j = 0; j < count && arr[j] <= num_sq; j++) { // don't go beyond the count of found
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

            // Step 2: 0 and 1 are not primes
            arr[0] = arr[1] = false;

            // Step 3: Sieve process
            int sq_lim = std::sqrt(LIMIT);
            for (int i = 2; i <= sq_lim; i++) {
                if (arr[i]) {
                    for (int j = i * i; j <= LIMIT; j += i)
                        arr[j] = false;
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
    Node* left; // pointer to the left child
    Node* right; // pointer to the right child
};

Node* createNode(int val, Node* leftChild, Node* rightChild)
{
    Node* n = new Node; // dynamically allocate memory
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
    n1 = createNode(2, n1, NULL);

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

void visitTreeInPreOrder(Node *node, void(*action)(Node*, void*), void *args )
{
    if (node != nullptr) {
        action(node, args);                             // performs action
        visitTreeInPreOrder(node->left, action, args);  // visit left
        visitTreeInPreOrder(node->right, action, args); // visit right 
    }
}

void printNode(Node *n, void *)
{
    cout << n->value << " ";  // no end of line
}

void incrNode(Node *n, void *a)
{
    int *p = reinterpret_cast<int*>(a);
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
    cout << endl;

    
    return 0;
}
________________________________________________________________________________________

Q. Argument odd or even

A. bool isOdd(unsigned n) {
    return n % 2 != 0;
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

Q.

A.


bool isPrime(unsigned x) {
    if (x < 2) return false; // 0 and 1 are not prime numbers
    for (unsigned i = 2; i * i <= x; ++i) { // fastest way to check for prime trick, check if i*i has any perfect divisor
        if (x % i == 0) return false;
    }
    return true;
}

unsigned nthPrime(unsigned n){
    if (n==0) return 0;
    unsigned count = 0;
    unsigned candidate = 1;

    while (count < n){
        ++candidate;
        if (isPrime(candidate)){
            ++count;
        }
    }
    return candidate;
}
*/



        














