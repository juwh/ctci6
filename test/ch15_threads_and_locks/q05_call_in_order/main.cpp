#pragma region Interview Question
/*
15.5 Call In Order: Suppose we have the following code:
public class Foo {
    public Foo() { ... }
    public void first() { ... }
    public void second() { ... }
    public void third() { ... }
}
The same instance of Foo will be passed to three different threads. ThreadA will call first,
threadB will call second, and threadC will call third. Design a mechanism to ensure that
first is called before second and second is called before third. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#417. How can we ensure that first () has terminated before calling second ()? 

#433. Why would using boolean flags to do this be a bad idea? 

#446. Would semaphores be useful here? 
*/
#pragma endregion