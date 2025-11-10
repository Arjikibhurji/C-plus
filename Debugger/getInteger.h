/*
 Author: Fabio Cannizzo
 NUS FE5226 Example Program

 GetInteger function head
*/

// We just state the head of the function, to tell the compiler that the function is in some other CPP file
// At link stage, the linker will search across all OBJ files for this funcion
int getInteger(const char *promptMsg);


/* 
TO GET INTO LINUX CODING ENV.

1. Check file directory with pwd
2. go to the respective folder with cd Debugger
3. g++ InputNumber.cpp getInteger.cpp -o main      // here write the files you wnat to compile
4. Run the project which here is stored in main. 
5. Run >>>>>>>>>>>>   ./main


*/