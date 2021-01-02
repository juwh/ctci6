#pragma region Interview Question
/*
12.9 Smart Pointer: Write a smart pointer class. A smart pointer is a data type, usually implemented with
templates, that simulates a pointer while also providing automatic garbage collection. It automati-
cally counts the number of references to a SmartPointer<T*> object and frees the object of type
T when the reference count hits zero. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#402. Focus on the concept firsts, then worry about the exact implementation. How should
SmartPointer look? 

#438. Think about tracking the number of references. What will this tell us? 

#453. What are all the different methods/operators we might want to override? 
*/
#pragma endregion