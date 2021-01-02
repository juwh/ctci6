#pragma region Interview Question
/*
12.10 Malloc: Write an aligned malloc and free function that supports allocating memory such that the
memory address returned is divisible by a specific power of two.

EXAMPLE
align_malloc(1000,128) will return a memory address that is a multiple of 128 and that points
to memory of size 1000 bytes.
aligned_free() will free memory allocated by align_malloc. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#413. Typically, rna lloc will just give us an arbitrary block of memory. If we can't override this
behavior, can we work with it to do what we need? 

#432. Imagine we have a sequential set of integers (3, 4, 5, ...). How big does this set need to be
to ensure that one of the numbers is divisible by 16? 

#440. How will we free the memory? 
*/
#pragma endregion