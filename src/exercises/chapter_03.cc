#include "chapter_03.hh"
#include "../utils/utils.hh"

#include <cmath>
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
    cout << "utils::atan(4, 2) = " << utils::rad2deg(utils::atan(4, 2)) << endl;
    cout << "utils::atan(5, -1) = " << utils::rad2deg(utils::atan(5, -1)) << endl;
    cout << "utils::atan(-4, -6) = " << utils::rad2deg(utils::atan(-4, -6)) << endl;
    cout << "utils::atan(-6, 4) = " << utils::rad2deg(utils::atan(-6, 4)) << endl;
}

void chapter_03::exercise_05()
{
    float (*one_param_funcs[])(float) = {
        cos,
        sin,
        tan,
        sqrt,
        log,
        exp,
        abs,
        floor,
        ceil};

    float (*two_param_funcs[])(float, float) = {
        atan2,
        pow};

    int func_index;
    float x, y, result;

    do
    {
        cout << "List of operations:" << endl;
        cout << "\t1.) cos(x)" << endl;
        cout << "\t2.) sin(x)" << endl;
        cout << "\t3.) tan(x)" << endl;
        cout << "\t4.) sqrt(x)" << endl;
        cout << "\t5.) ln(x)" << endl;
        cout << "\t6.) e^x" << endl;
        cout << "\t7.) |x|" << endl;
        cout << "\t8.) floor(x)" << endl;
        cout << "\t9.) ceil(x)" << endl;
        cout << "\t10.) atan2(y, x)" << endl;
        cout << "\t11.) x^y" << endl;
        cout << "\t12.) Exit" << endl;
        cout << "Select an operation: ";
        cin >> func_index;

        if (func_index == 12)
        {
            break;
        }
        else if (func_index < 10)
        {
            cout << "Enter value for x: ";
            cin >> x;
            result = (*one_param_funcs[func_index - 1])(x);
        }
        else
        {
            cout << "Enter value for x: ";
            cin >> x;
            cout << "Enter value for y: ";
            cin >> y;
            result = (*two_param_funcs[func_index - 10])(x, y);
        }

        cout << "Result: " << result << endl;
    } while (func_index != 12);

    cout << "Exiting..." << endl;
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

void test_random()
{
    int rand_val = 0;
    int num_tests = 10000000;
    int report_rate = 100;
    int min = -10;
    int max = 10;

    for (unsigned int i = 0; i < num_tests; i++)
    {
        rand_val = utils::random(min, max);

        if (rand_val < min || rand_val > max)
        {
            cout << "BAD " << rand_val << endl;
            break;
        }

        if (i % (num_tests / report_rate) == 0)
        {
            cout << "We're still good! " << rand_val << endl;
        }
    }
}