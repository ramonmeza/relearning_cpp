#include <exercises/chapter_04.hh>
#include <utils/utils.hh>

#include <iostream>
#include <memory>

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
    int die1 = 0;
    int die2 = 0;

    cout << "I don't know craps and really don't care about implementing a dice game..." << endl;
    cout << "Here's some pointer and reference parameters." << endl
         << endl;

    cout << "before die1: " << die1 << endl;
    cout << "before die2: " << die2 << endl;
    utils::dice(&die1, &die2);
    cout << "after die1: " << die1 << "(" << &die1 << ")" << endl;
    cout << "after die2: " << die2 << "(" << &die2 << ")" << endl;

    die1 = 0;
    die2 = 0;
    cout << "before die1: " << die1 << endl;
    cout << "before die2: " << die2 << endl;
    utils::dice(die1, die2);
    cout << "after die1: " << die1 << "(" << &die1 << ")" << endl;
    cout << "after die2: " << die2 << "(" << &die2 << ")" << endl;
}

void chapter_04::exercise_03()
{
    unsigned int num_elements = 0;
    int *values = nullptr;

    cout << "Enter the size of an array to create: ";
    cin >> num_elements;

    cout << "Creating array and filling it with random numbers..." << endl;
    values = new int[num_elements];
    utils::random_array_fill(values, num_elements);

    cout << "Array = " << utils::print_array(values, num_elements) << endl;

    delete values;
}

void chapter_04::exercise_04()
{
    float a, b, c, r1, i1, r2, i2 = 0;
    char imaginary_character = '\0';
    char operator_character = '+';

    cout << "Provide coefficients for quadratic equation:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    utils::quadratic_formula(a, b, c, r1, i1, r2, i2);

    cout << "Coefficients a=" << a << ", b=" << b << ", c=" << c << endl;

    imaginary_character = (i1 != 0) ? 'i' : '\0';
    operator_character = (i1 > 0) ? '+' : '-';
    cout << "Solution 1 = " << r1 << operator_character << abs(i1) << imaginary_character << endl;

    imaginary_character = (i2 != 0) ? 'i' : '\0';
    operator_character = (i2 > 0) ? '+' : '-';
    cout << "Solution 2 = " << r2 << operator_character << abs(i2) << imaginary_character << endl;
}
