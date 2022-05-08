/*
    "fib_calc_c.cpp"

    Author: Jarod Graygo

    Gets the nth fibonacci number using the C++ programming language

    This program can be compiled using the command "clang++ fib_calc_c.cpp -o fib_calc"
    and subsequently run using "./fib_calc"

    C++ is an object-oriented, imperative programming language with some functional
    programming features. This means that computation is performed by using the state
    of the program. All objects and types are mutable by default unless specifically
    implemented otherwise (ex. using "const").
*/

#include <iostream>

using std::cin; using std::cout;

// C++ uses eager evaluation, meaning arguments are evaluated BEFORE the function is applied

// Recursively calculate the nth fibonacci number
int calc_fib(int index) {
    if (index <= 1)                                     // Terminating condition for the recursive function
        return index;
    return calc_fib(index - 1) + calc_fib(index - 2);   // Recursively add the previous two numbers together
                                                        // to calculate the result
}

// Arguments in C++ are passed either by-value or by-reference, and it is left to the programmer
// to decide which method to use. If something is passed by-reference any changes made to the object
// inside the function will also be reflected outside of the function, whereas if something is passed
// by value, one may freely modify the object inside the function without those changes appearing elsewhere.
// By-reference or by-value may also be chosen based on efficiency. For large/complex objects that are
// expensive to copy one may pass the object as const and by-reference to forego copying while avoiding
// side-effects

// Entry point to program
int main() {
    int *fib_num;                                       // Create a pointer to an integer
    cout << "Which number in the fibonacci sequence would you like the value of? ";
    cin >> *fib_num;                                    // Take user input
    cout << calc_fib(*fib_num);                         // Output the result
    delete fib_num;                                     // Delete the pointer when we're done using it

    return 0;                                           // Exit without error
}

// C++ has no built-in garbage collection, instead relying on the programmer for proper memory management.
// As seen above, one must manually delete a pointer to avoid memory leaks. Though for most objects in the
// STL library, as well as others, this memory management is done for you, if you must manually allocate
// memory, you must also manually deallocate this memory, otherwise the object will persist in memory while
// being completely inaccessible