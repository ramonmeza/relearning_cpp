#include <utils/utils.hh>

#include <cmath>
#include <ctime>
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

int utils::random(int low, int high)
{
    return low + (rand() % (high - low + 1)); // +1 to include high value
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

void utils::dice(int &die1, int &die2)
{
    die1 = utils::random(1, 6);
    die2 = utils::random(1, 6);
}

void utils::dice(int *die1, int *die2)
{
    *die1 = utils::random(1, 6);
    *die2 = utils::random(1, 6);
}

void utils::random_array_fill(int array[], int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = utils::random(0, 100);
    }
}

void utils::random_vector_fill(std::vector<int> &vec)
{
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        *itr = utils::random(0, 100);
    }
}

string utils::print_array(int array[], int size)
{
    ostringstream ss;
    for (unsigned int i = 0; i < size; i++)
    {
        ss << array[i];
        if (i != size - 1)
        {
            ss << ", ";
        }
    }
    return ss.str();
}

std::string utils::print_vector(std::vector<int> &vec)
{
    ostringstream ss;
    for (auto itr = vec.begin(); itr != vec.end(); itr++)
    {
        ss << *itr;
        if (itr < vec.end() - 1)
        {
            ss << ", ";
        }
    }
    return ss.str();
}

bool utils::quadratic_formula(float a, float b, float c, float &r1, float &i1, float &r2, float &i2)
{
    float s, x1, x2, i_num = 0;
    r1 = r2 = i1 = i2 = 0;

    s = pow(b, 2) - 4 * a * c;

    if (s < 0)
    {
        i_num = sqrt(abs(s));
        r1 = -b / (2 * a);
        i1 = i_num / (2 * a);
        r2 = -b / (2 * a);
        i2 = -i1;
        return false;
    }
    else
    {
        r1 = (-b + sqrt(abs(s))) / (2 * a);
        i1 = 0;
        r2 = (-b - sqrt(abs(s))) / (2 * a);
        i2 = 0;
        return true;
    }

    return false;
}
