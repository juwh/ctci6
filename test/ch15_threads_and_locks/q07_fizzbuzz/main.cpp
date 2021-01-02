#pragma region Interview Question
/*
15.7 FizzBuzz: In the classic problem FizzBuzz, you are told to print the numbers from 1 to n. However,
when the number is divisible by 3, print "Fizz". When it is divisible by 5, print "Buzz". When it is divis-
ible by 3 and 5, print "FizzBuzz". In this problem, you are asked to do this in a multithreaded way.
Implement a multithreaded version of FizzBuzz with four threads. One thread checks for divisibility
of 3 and prints "Fizz". Another thread is responsible for divisibility of 5 and prints "Buzz". A third thread
is responsible for divisibility of 3 and 5 and prints "FizzBuzz". A fourth thread does the numbers. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#414. First implement the single-threaded FizzBuzz problem. 

#439. Don't try to do anything fancy on the single-threaded problem. Just get something that
is simple and easily readable. 

#447. Outline the structure for the threads without worrying about synchronizing anything. 

#458. Once you get the structure of each thread done, think about what you need to synchro-
nize. 
*/
#pragma endregion