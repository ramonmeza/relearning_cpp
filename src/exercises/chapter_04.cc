#include <exercises/chapter_04.hh>
#include <utils/utils.hh>

#include <iostream>

using namespace std;

void chapter_04::exercise_01()
{
    cout << "1.) Explain in your own words and using complete sentences what the following terms are:" << endl;
    cout << "\ta.) References:" << endl;
    cout << "\t\tReferences are aliases for variables and allow us to manipulate and access the variable they are referring to." << endl;

    cout << "\tb.) Constant References:" << endl;
    cout << "\t\tConstant References allow us to reference a variable, but we cannot change the value of the variable being referenced." << endl;

    cout << "\tc.) Pointers:" << endl;
    cout << "\t\tPointers allow us point to an address in memory. Used for dealing with dynamic memory." << endl;

    cout << "\td.) Constant Pointers:" << endl;
    cout << "\t\tConstant Pointers allow us to keep an immutable pointer to an address in memory." << endl;

    cout << "\te.) Pointer arithmetic:" << endl;
    cout << "\t\tWe can add and subtract from pointers, which allows us to access memory relative to the pointer." << endl;

    cout << "\tf.) Static Memory:" << endl;
    cout << "\t\tMemory that is allocated during compile time is said to be static." << endl;

    cout << "\tg.) Dynamic Memory:" << endl;
    cout << "\t\tMemory that is allocated during runtime is said to be dynamic." << endl;

    cout << "\th.) Runtime:" << endl;
    cout << "\t\tRuntime refers to the time during which the application is running." << endl;

    cout << "2.) State three benefits of pointers." << endl;
    cout << "\tPointers allow us to create dynamic objects during runtime, pass objects to functions by their address rather than copying the entire object, and " << endl;

    cout << "3.) What is the symbol for the \"address of\" operator and what does it do?" << endl;
    cout << "\t& is the \"address of\" operator and it returns the address of a variable." << endl;

    cout << "4.) What is the symbol of the \"indirection operator\" and when is it used?" << endl;
    cout << "\t* is the \"indirection operator\" and is used to define pointers." << endl;

    cout << "5.) How are references probably implemented \"behind the scenes?\"" << endl;
    cout << "\tReferences are probably implemented by the compiler by replacing each reference with the variable being referenced." << endl;

    cout << "6.) Why is dynamic memory useful?" << endl;
    cout << "\tDynamic memory allows us to allocate memory at runtime. This provides the possible benefit of highly efficient memory manager to boost performance of our application." << endl;

    cout << "7.) Explain how arrays are passed into functions." << endl;
    cout << "\tArrays can be passed into functions by value or by reference. If the array is passed by value, the entire contents of the array are copied and given to the function. If passed by reference, the array will provide it's first element to be iterated over by the function." << endl;

    cout << "8.) What is a safer (i.e., avoids memory leaks and easier alternative to dynamic memory?" << endl;
    cout << "\tWe can utilize the standard library to create vectors, which automatically handles dynamically sized arrays. We can also use smart pointers." << endl;

    cout << "9.) Explain a situation where function pointers might be useful." << endl;
    cout << "\tWe can use function pointers to handle events that spawn from UI libraries. For example, a UI library might provide a way to register listeners to events that the library raises. We register a function via a function pointer so when an event happens, our function is automatically called." << endl;
}

void chapter_04::exercise_02()
{
}

void chapter_04::exercise_03()
{
}

void chapter_04::exercise_04()
{
}
