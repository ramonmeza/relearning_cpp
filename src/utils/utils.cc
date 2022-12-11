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

/// @brief Converts radians to degrees
/// @param rad Radians
/// @return Degrees
float utils::rad2deg(float rad)
{
    return rad * (180 / utils::pi);
}

/// @brief Converts degrees to radians
/// @param deg Degrees
/// @return Radians
float utils::deg2rad(float deg)
{
    return deg * (utils::pi / 180);
}

/// @brief Recursively determine the factorial of a given number
/// @param n The number to start with
/// @return The factorial of the given number, `!n`
double utils::factorial(double n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * utils::factorial(n - 1);
}

/// @brief Capitializes a given character
/// @param n The character to capitalize
/// @return The given character capitialized, if the character cannot be capitailized, return `NULL`
char utils::to_upper(char n)
{
    if (n < LOWER_CASE_START || n > LOWER_CASE_START + LETTERS)
    {
        return (char)NULL;
    }

    return n + (UPPER_CASE_START - LOWER_CASE_START);
}

/// @brief Lowercases a given character
/// @param n The character to lowercased
/// @return The given character lowercased, if the character cannot be lowercased, return `NULL`
char utils::to_lower(char n)
{
    if (n < UPPER_CASE_START || n > UPPER_CASE_START + LETTERS)
    {
        return (char)NULL;
    }

    return n - (UPPER_CASE_START - LOWER_CASE_START);
}

/// @brief Convert a `vec3` to its string representation
/// @param v The `vec3` object
/// @return The `vec3` in string representation
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

/// @brief Find the distance between two `vec3` objects
/// @param u The start point
/// @param v The end point
/// @return The distance between the two `vec3` objects
double utils::dist3(const vec3 &u, const vec3 &v)
{
    return sqrt(pow(v.x - u.x, 2) + pow(v.y - u.y, 2) + pow(v.z - u.z, 2));
}

/// @brief Arc-Tangent function of 2 inputs
/// @param y The Y-axis value
/// @param x The X-axis value
/// @return The arc-tangent of the two inputs
float utils::atan(float y, float x)
{
    return atan2f(y, x);
}

/// @brief Generate a random number between given low and high values
/// @param low The minimum value that can be generated, inclusive
/// @param high The maximum value that can be generated, inclusive
/// @param seed The seed for the random generator, defaults to -1. If -1 then seed won't be set
/// @return A random value between the given minimum and maximum values, inclusive
int utils::random(int low, int high, int seed)
{
    if (seed != -1)
    {
        srand(seed);
    }

    return (rand() % (high + 1)) - (rand() % (low - 1));
}
