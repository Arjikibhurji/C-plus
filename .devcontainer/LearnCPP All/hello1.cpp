
#include <iostream>

using namespace std;
/*
int main() {
{ // begin of a statement
int x; // create a variable of type x local to this code block
x=10; // initialize the value 10 to the variable x
std::cout << x << "\n"; // print the value of x
x=2*x; // destructive update: the previous values of x is discarded
cout << x << "\n"; // print the value of x
}} // end of a statement
// here the variable x does not exits anymore, i.e. it is out of scope


int main(){
    int x, y;
    std::cout << "Input the variable x & y";
    std::cin >> x >> y;
    std::cout << "The entered number is x:" << x << ", and y is:" << y << endl;
    return 0;
}

int main(){
    int len, wid;
    std::cout << "Input the leng & wid ";
    std::cin >> len >> wid;
    int area = len * wid;
    std::cout << "The area of the rectangle is " << area << endl;
    return 0;
}
// Leave space and write two numbers

#include <cmath>
int main(){
    double Ax, Ay, Bx, By;
    std::cout << "Input the A coordinates x & y ";
    std::cin >> Ax >> Ay;
    std::cout << "Input the B coordinates x & y ";
    std::cin >> Bx >> By;
    double dx = Ax - Bx;
    double dy = Ay - By;
    double distance = std::sqrt(dx*dx + dy*dy);
    std::cout << "The distance between: " << 
     '('<< Ax << ',' << Bx << ')' <<
     '('<< Ay << ',' << By << ')' <<
     " is " << distance << "\n";

    return 0;
}



// OVERFLOW EXERCISE

int main(){
    int x = 1024*1024*1024;
    std::cout<<x<<":"<<(2*x)<<endl;
    return 0;
}
// here we see that value becomes negative so out of range

int main(){
    std::cout<<"char "<< sizeof(char)<<endl;
    return 0;
} // tells size in bytes, by default int = signed int so change to unsigned int if only positive
// you can put specific memory types like int64_t which is 64 bits

int main()
{
enum Seasons : uint16_t { Spring, Summer, Fall, Winter }; // type definition
Seasons x = Fall; // variable declaration and initialization
cout << x << endl; // print out variable value
cout << sizeof(Summer) << endl; // print out variable size
}

// use parenthesis to overdo the priority problems

int main()
{
    int x;
    std::cout << "input x: ";
    std::cin >> x;

    bool e = (1000<x && x<=10000) && (x % 2 != 0) && (x%7==0) && (x % 41 == 0 || x % 43 == 0);
    std::cout << e << endl;
    return 0;
}


int main(){
    for (int i = 0; i<10;++i)
        std::cout <<i<<endl;
}

----------------------------------
3. Why they behave the same in a loop

Example with i++:

Iteration 1: i = 0 → check condition → body runs → i++ makes i = 1
Iteration 2: i = 1 → check condition → body runs → i++ makes i = 2
… continues the same way.

Example with ++i:

Iteration 1: i = 0 → check condition → body runs → ++i makes i = 1
Iteration 2: i = 1 → check condition → body runs → ++i makes i = 2
… continues the same way.

So in a for loop with i = 0, there’s no difference between i++ and ++i because the 
loop doesn’t care about the returned value, only about the side effect (incrementing i by 1)

int i = 0;
int x = i++;   // x = 0, i = 1
int y = ++i;   // i = 2, y = 2
Here, the value returned is used, so there’s a difference.

----------------------------------
Q. Sum of n cube - 1 / n cube + 1 for n = 2 to 1000

int main(){
    double series =  0.0;
    for (int n = 2; n <= 1000; ++n) {
        double nd = static_cast<double>(n); // cast as double to avoid overflow of int 2^31-1
        double nd3 = (nd*nd*nd);
        int num = nd3-1;
        int den = nd3+1;
        if (n<10){
            std::cout <<num <<"/"<<den <<endl;
        }
        series+= (nd3-1)/(nd3+1);
    }
    std::cout<<"The sum of the first 1000 terms is "<<series<<endl;
    return 0;
}
----------------------------------
Q. Compute till n^2 from 1 to 100

int main(){
    double series =  0.0;
    for (int n = 1; n <= 100; ++n) {
        double nd = static_cast<double>(n); // cast as double to avoid overflow of int 2^31-1
        double nd2 = (nd*nd);
        series+= (nd2);
    }
    std::cout<<"The sum of the first 100 terms is "<<series<<endl;
    return 0;
}

----------------------------------
Set an integer to 1000. Use a while-loop to decrease
the integer successively by 13 until it becomes
negative. Print the final value of the integer to the
screen.

int main()
{
    int x = 1000;

    int n = 0;
    while(x > 0) {
        x -= 13;
        n++;
    }

    std::cout << "After removing 13" << n << " times what number till negative: " << x <<"\n";

    return 0;
}
----------------------------------


#include <cstdio>

int main()
{
    int n = 0;
    for (int i = 0; i < 1000000; ++i) {
        static_assert(std::is_same_v<int, decltype(rand())>); // max value 2^32-1, 4 byte number
        unsigned r = rand() & 0xFFFF; // number in the range 0-2^16-1 = 65000
        if (r <= 1000 && r >= 500 && (r % 163 == 0))
            n ++;
    }

    std::cout << "found " << n << " numbers\n";

    return 0;
}
----------------------------------
Q. Sum of digits

#include <cstdio>

int main()
{
    int n = 3481;
    int nsave = n;

    int sumDigits = 0;

    while(n) {
        auto digit = n % 10;
        std::cout << "lowest digit: " << digit << "\n";
        std::cout << "residual:  (" << n << "-" << digit << ")/10 : " << (n /= 10) << "\n";

        sumDigits += digit;
    }

    std::cout << "sum of digits for " << nsave << " is " << sumDigits << "\n";

    return 0;
}
----------------------------------
Q. Prime Numbers


#include <cstdio>
#include <cmath>

int main()
{
    int n = 9;
    
    // check if n is prime
    int divisor = 0;
    if (n > 2 && n % 2 == 0) {
        divisor = 2;
    }
    else {
        for (int i = 3, m = (int)std::sqrt(n); i <= m; i += 2) {
            if (n % i == 0) { // is n divisible by i ?
                divisor = i;
                break;
            }
        }
    }

    std::cout << "the number " << n << " is ";
    if (divisor==0)
        std::cout << "prime\n";
    else {
        std::cout << "divisible by " << divisor << "\n";
    }
    return 0;
}
----------------------------------
Q. Print numbers when skipping multiple of 13

#include <cstdio>
#include <cmath>

int main()
{
    const int maxvals = 40;

    // print all numbers in the range from 1 to 100, skipping those multiple of 13
    // we use `continue` to skip multiple of 13
    for (int i=1; i <= maxvals; ++i)
    {
        if (i % 13 == 0)
            continue; // skips multiples of 13
        std::cout << i << ",";
    }
    std::cout << "\n";

    // print all numbers in the range from 1 to 100, skipping those multiple of 13
    // we do not use continue, we use instead a double loop
    for (int i = 1; i <= maxvals; ++i)
    {
        for (int last = std::min(i + 12, maxvals+1); i < last; ++i)
            std::cout << i << ",";
    }
    std::cout << "\n";

    return 0;
}

----------------------------------
ARRAYS

Q. Get the max, minimum and average from a set of random numbers


#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    
    const size_t n = 10;
    int x[n];

    for (int i = 0; i < n; ++i)
        x[i] = rand();
    
    for (int i = 0; i < n; ++i)
        cout << x[i] << ",";
    
    cout << "\n";

    double mi = x[0], ma = x[0], su = 0;

    for (int i = 0; i < n; ++i) {
        // you can replace for with the range function such as:
        // for (int xi : x) {}
        mi = x[i] < mi ? x[i] : mi;
        ma = x[i] > ma ? x [i] : ma;
        su += x[i];

    cout << "min: " << mi << "\n"
        << "max: " << ma << "\n"
        << "avg: " << su / n << "\n";
        // you can maniupulate data by std::setprecision

        // look at all these from the library header <iomanip>

    return 0;
    }

}
----------------------------------
Q. Find all primes within 1,000,000 and set the primes in a length of array 


#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    
    int x[] = {1,2,3};
    for (int i: x)
        cout << i << endl;
    int x[] = {4};
    for (int i: x)
        cout << i << endl;
}
----------------------------------
Q. Transform the array to lines 
*/

#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    const int nr = 3;
    const int nc = 3;

    int M[nr*nc] = {1,2,3,4,5,6,7,8,9};

    // interpretation of the matrix as a row major
    for (int r = 0; r < nr; ++r){
        for (int c = 0; c < nc; ++c) 
            std::cout << M[r*nc + c] << ", ";
        std::cout << endl;

    }
    std::cout << endl;
    return 0;
}