#include "utils.hh"

#include <cmath>
#include <sstream>

using namespace std;

const int LOWER_CASE_START = 97;
const int UPPER_CASE_START = 65;
const int LETTERS = 26;

double utils::factorial(double n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * utils::factorial(n - 1);
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

double utils::dist3(const vec3 &u, const vec3 &v)
{
    return sqrt(pow(v.x - u.x, 2) + pow(v.y - u.y, 2) + pow(v.z - u.z, 2));
}