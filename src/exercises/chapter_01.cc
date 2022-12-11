#include <exercises/chapter_01.hh>
#include <utils/utils.hh>

#include <cstdlib>
#include <iostream>

using namespace std;

void chapter_01::exercise_01()
{
    double n1, n2;

    cout << "Enter a real number (n1): ";
    cin >> n1;

    cout << "Enter a real number (n2): ";
    cin >> n2;

    cout << n1 << " + " << n2 << " = " << (n1 + n2) << endl;
    cout << n1 << " - " << n2 << " = " << (n1 - n2) << endl;
    cout << n1 << " * " << n2 << " = " << (n1 * n2) << endl;

    if (n2 != 0)
    {
        cout << n1 << " / " << n2 << " = " << (n1 / n2) << endl;
    }
    else
    {
        cout << "0 cannot be used as a divisor." << endl;
    }
}

void chapter_01::exercise_02()
{
    string first_name, last_name;

    cout << "Enter your first name and last name, separated by a space: ";
    cin >> first_name >> last_name;
    cout << "Hello there, " << first_name << " " << last_name << "!" << endl;
}

void chapter_01::exercise_03()
{
    double n;

    cout << "Enter a real number: ";
    cin >> n;
    cout << n << "^3 = " << (n * n * n) << endl;
}

void chapter_01::exercise_04()
{
    double r, A, C;

    cout << "Enter the radius of a circle: ";
    cin >> r;

    A = utils::pi * (r * r);
    cout << "The area A of a circle with radius " << r << " = " << A << endl;

    C = 2 * utils::pi * r;
    cout << "The circumference C of a circle with radius " << r << " = " << C << endl;
}

void chapter_01::exercise_05()
{
    const int amount_of_values = 5;
    double sum, average = 0;

    for (unsigned int i = 0; i < amount_of_values; i++)
    {
        double value;
        cout << "Enter a" << i << ": ";
        cin >> value;
        sum += value;
    }

    average = sum / amount_of_values;
    cout << "The average of the " << amount_of_values << " inputs a0...a" << (amount_of_values - 1) << " = " << average << endl;
}

void chapter_01::exercise_06()
{
    /*
    // this is the code they want fixed
    #include <iostream> #include <string>
    int mian()
    {
        string str = "Hello World!"
        cout << str << endl;
        cout << float x = 5.0f * str << end;
        int 65Num = 65;
        cout << "65Num = " < 65Num << endl;
    }

    // answer
    #include <iostream>
    #include <string>

    using namespace std;

    int main()
    {
        int num = 64;
        string str = "Hello, World!";

        cout << str << endl;
        cout << "num = " << num << endl;

        return 0;
    }
    */
    int num = 64;
    string str = "Hello, World!";

    cout << str << endl;
    cout << "num = " << num << endl;
}
