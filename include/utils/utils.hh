#include <string>

namespace utils
{
    const float pi = 3.14159265358979323846f;

    struct vec2
    {
        int x;
        int y;
    };

    struct vec3
    {
        int x;
        int y;
        int z;
    };

    /// @brief Converts radians to degrees
    /// @param rad Radians
    /// @return Degrees
    float rad2deg(float rad);

    /// @brief Converts degrees to radians
    /// @param deg Degrees
    /// @return Radians
    float deg2rad(float deg);

    /// @brief Arc-Tangent function of 2 inputs
    /// @param y The Y-axis value
    /// @param x The X-axis value
    /// @return The arc-tangent of the two inputs
    float atan(float y, float x);

    /// @brief Recursively determine the factorial of a given number
    /// @param n The number to start with
    /// @return The factorial of the given number, `!n`
    double factorial(double n);

    /// @brief Find the distance between two `vec3` objects
    /// @param u The start point
    /// @param v The end point
    /// @return The distance between the two `vec3` objects
    double dist3(const vec3 &from, const vec3 &to);

    /// @brief Capitializes a given character
    /// @param n The character to capitalize
    /// @return The given character capitialized, if the character cannot be capitailized, return `NULL`
    char to_upper(char n);

    /// @brief Lowercases a given character
    /// @param n The character to lowercased
    /// @return The given character lowercased, if the character cannot be lowercased, return `NULL`
    char to_lower(char n);

    /// @brief Convert a `vec3` to its string representation
    /// @param v The `vec3` object
    /// @return The `vec3` in string representation
    std::string print_vec3(const vec3 &v);

    /// @brief Generate a random number between given low and high values
    /// @param low The minimum value that can be generated, inclusive
    /// @param high The maximum value that can be generated, inclusive
    /// @param seed The seed for the random generator, defaults to -1. If -1 then seed won't be set
    /// @return A random value between the given minimum and maximum values, inclusive
    int random(int low, int high, int seed = -1);

    /// @brief Binary search for a value in a given array, returning the index of the element found
    /// @param data Array to search through
    /// @param num_elements The amount of elements in the given array
    /// @param search_key The value of the item to find
    /// @return The index of the value found, if the item is not found then `-1` is returned
    int binary_search(int data[], int num_elements, int search_key);
}
