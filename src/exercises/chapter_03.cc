#include <exercises/chapter_03.hh>
#include <utils/utils.hh>

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
    int slot_values[3];
    int input, bet_amount, winnings;
    int player_bank = 1000;

    do
    {
        // get operation to perform
        cout << "Player Bank: $" << player_bank << endl;
        cout << "List of operations:" << endl;
        cout << "\t1.) Play slots" << endl;
        cout << "\t2.) Exit" << endl;
        cout << "Select an operation: ";
        cin >> input;

        if (input == 1)
        {
            // get player's bet amount
            do
            {
                cout << "Enter your bet: $";
                cin >> bet_amount;

                if (bet_amount > player_bank || bet_amount <= 0)
                {
                    cout << "You did not enter a valid bet." << endl;
                }
                else
                {
                    break;
                }
            } while (true);

            // calculate slot results
            slot_values[0] = utils::random(2, 7);
            slot_values[1] = utils::random(2, 7);
            slot_values[2] = utils::random(2, 7);
            cout << "Slot Results: " << slot_values[0] << " " << slot_values[1] << " " << slot_values[2] << endl;

            // calculate results
            if (slot_values[0] == slot_values[1] && slot_values[0] == slot_values[2])
            {
                // 3 matches
                if (slot_values[0] == 7)
                {
                    // big winnings
                    cout << "!JACKPOT!" << endl;
                    winnings = bet_amount * 10;
                }
                else
                {
                    // mid winnings
                    cout << "You Win: 3 of a kind!" << endl;
                    winnings = bet_amount * 5;
                }
            }
            else if (slot_values[0] == slot_values[1] || slot_values[0] == slot_values[2] || slot_values[1] == slot_values[2])
            {
                // 2 matches
                cout << "You Win: 2 of a kind!" << endl;
                winnings = bet_amount * 3;
            }
            else
            {
                cout << "You lost!" << endl;
                // take away bet amount
                winnings = -bet_amount;
            }

            // apply winnings
            player_bank += winnings;
        }
        else if (input == 2)
        {
            break;
        }
        else
        {
            cout << "Invalid selection, try again..." << endl;
        }
        cout << endl;
    } while (player_bank > 0);

    if (player_bank <= 0)
    {
        cout << "Better luck next time ;)" << endl;
    }

    cout << "Thanks for playing!" << endl;
    cout << "Exiting..." << endl;
}

void chapter_03::exercise_07()
{
    int values[] = {1, 4, 5, 6, 9, 14, 21, 23, 28, 31, 35, 42, 46, 50, 53, 57, 62, 63, 65, 74, 79, 89, 95};
    int num_elements = sizeof(values) / sizeof(int);
    int search_key, found_index;

    // print list
    cout << "{ ";
    for (unsigned int i = 0; i < num_elements; i++)
    {
        cout << values[i];
        if (i != num_elements - 1)
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;

    // user search loop
    do
    {
        cout << "Enter a search key (or '-1' to exit): ";
        cin >> search_key;

        if (search_key != -1)
        {
            found_index = utils::binary_search(values, num_elements, search_key);

            if (found_index < 0)
            {
                cout << search_key << " not found in list." << endl;
            }
            else
            {
                cout << search_key << " is in position " << found_index << endl;
            }
        }
    } while (search_key != -1);
}

void chapter_03::exercise_08()
{
    const int num_elements = 10;
    int values[num_elements];

    cout << "Enter ten unsorted integers..." << endl;
    for (unsigned int i = 0; i < num_elements; i++)
    {
        cout << "[" << i << "] = ";
        cin >> values[i];
    }

    cout << "Unsorted List = ";
    for (unsigned int i = 0; i < num_elements; i++)
    {
        cout << values[i];
        if (i < num_elements - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Sorting..." << endl;
    utils::bubble_sort(values, num_elements);
    cout << "Sorted List = ";
    for (unsigned int i = 0; i < num_elements; i++)
    {
        cout << values[i];
        if (i < num_elements - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}
