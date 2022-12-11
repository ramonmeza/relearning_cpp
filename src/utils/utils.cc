#include <utils/utils.hh>

#include <cmath>
#include <sstream>

using namespace std;

/// @brief Index at which lowercase letters start in ASCII
const int LOWER_CASE_START = 97;

/// @brief Index at which uppercase letters start in ASCII
const int UPPER_CASE_START = 65;

/// @brief The amount of letters in the alphabet
const int LETTERS = 26;

float utils::rad2deg(float rad)
{
    return rad * (180 / utils::pi);
}

float utils::deg2rad(float deg)
{
    return deg * (utils::pi / 180);
}

float utils::atan(float y, float x)
{
    return atan2f(y, x);
}

double utils::factorial(double n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * utils::factorial(n - 1);
}

double utils::dist3(const vec3 &u, const vec3 &v)
{
    return sqrt(pow(v.x - u.x, 2) + pow(v.y - u.y, 2) + pow(v.z - u.z, 2));
}

char utils::to_upper(char n)
{
    if (n < LOWER_CASE_START || n > LOWER_CASE_START + LETTERS)
    {
        return (char)NULL;
    }

    return n + (UPPER_CASE_START - LOWER_CASE_START);
}

char utils::to_lower(char n)
{
    if (n < UPPER_CASE_START || n > UPPER_CASE_START + LETTERS)
    {
        return (char)NULL;
    }

    return n - (UPPER_CASE_START - LOWER_CASE_START);
}

string utils::print_vec3(const vec3 &v)
{
    ostringstream ss;
    ss << "(";
    ss << v.x;
    ss << ", ";
    ss << v.y;
    ss << ", ";
    ss << v.z;
    ss << ")";
    return ss.str();
}

int utils::random(int low, int high, int seed)
{
    if (seed != -1)
    {
        srand(seed);
    }

    return (rand() % (high + 1)) - (rand() % (low - 1));
}

int utils::binary_search(int data[], int num_elements, int search_key)
{
    if (num_elements == 1)
    {
        if (data[0] == search_key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    int split = (int)(num_elements / 2);
    if (data[split] == search_key)
    {
        return split;
    }
    else if (data[split] < search_key)
    {
        // upper half
        return split + utils::binary_search(data + split, num_elements - split, search_key);
    }
    else
    {
        // lower half
        return utils::binary_search(data, num_elements - split, search_key);
    }

    return -1;
}

void utils::bubble_sort(int data[], int num_elements)
{
    int next_end, temp = 0;
    int sub_array_end = num_elements - 1;

    while (sub_array_end > 0)
    {
        next_end = 0;
        for (unsigned int j = 0; j < sub_array_end; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                next_end = j;
            }
        }
        sub_array_end = next_end;
    }
}
