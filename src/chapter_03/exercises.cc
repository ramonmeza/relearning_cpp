#include "exercises.hh"
#include "utils.hh"

#include <cstdlib>
#include <iostream>

using namespace std;

void chapter_03::exercise_01()
{
    cout << "5! = " << utils::factorial(5) << endl;
    cout << "0! = " << utils::factorial(0) << endl;
    cout << "9! = " << utils::factorial(9) << endl;
    cout << "3! = " << utils::factorial(3) << endl;
}

void chapter_03::exercise_02()
{
    for (unsigned char i = 97; i < 97 + 26; i++)
    {
        cout << "to_upper(" << i << ") = " << utils::to_upper(i) << endl;
    }

    for (unsigned char i = 65; i < 65 + 26; i++)
    {
        cout << "to_lower(" << i << ") = " << utils::to_lower(i) << endl;
    }
}

void chapter_03::exercise_03()
{
    utils::vec3 u = {1, 2, 3};
    utils::vec3 v = {0, 0, 0};
    cout << "Distance between " << utils::print_vec3(u) << " and " << utils::print_vec3(v) << " = " << utils::dist3(u, v) << endl;

    v = {1, 2, 3};
    cout << "Distance between " << utils::print_vec3(u) << " and " << utils::print_vec3(v) << " = " << utils::dist3(u, v) << endl;

    v = {7, -4, 5};
    cout << "Distance between " << utils::print_vec3(u) << " and " << utils::print_vec3(v) << " = " << utils::dist3(u, v) << endl;
}

void chapter_03::exercise_04()
{
}

void chapter_03::exercise_05()
{
}

void chapter_03::exercise_06()
{
}

void chapter_03::exercise_07()
{
}

void chapter_03::exercise_08()
{
}
