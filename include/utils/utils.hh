#include <string>
#include <vector>

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
    /// @return A random value between the given minimum and maximum values, inclusive
    int random(int low, int high);

    /// @brief Binary search for a value in a given array, returning the index of the element found
    /// @param data Array to search through
    /// @param num_elements The amount of elements in the given array
    /// @param search_key The value of the item to find
    /// @return The index of the value found, if the item is not found then `-1` is returned
    int binary_search(int data[], int num_elements, int search_key);

    /// @brief Use Bubble Sort algorithm to sort given array in ascending order
    /// @param data Array to sort
    /// @param num_elements The amount of elements in the given array
    void bubble_sort(int data[], int num_elements);

    /// @brief Roll dice and return their values through reference paramaeters
    /// @param die1 Reference to the int to put the result of the die 1 roll into
    /// @param die2 Reference to the int to put the result of the die 2 roll into
    void dice(int &die1, int &die2);

    /// @brief Roll dice and return their values through reference paramaeters
    /// @param die1 Pointer to the int to put the result of the die 1 roll into
    /// @param die2 Pointer to the int to put the result of the die 2 roll into
    void dice(int *die1, int *die2);

    /// @brief Fill an array with random values [0, 100]
    /// @param array Pointer to the array
    /// @param size Number of elements in the array
    void random_array_fill(int array[], int size);

    /// @brief Fill an array with random values [0, 100]
    /// @param array Reference to the vector to fill
    void random_vector_fill(std::vector<int> &array);

    /// @brief Print an array with comma separated elements
    /// @param array Pointer to the array
    /// @param size Number of elements in the array
    /// @return The vector elements (comma-separated)
    std::string print_array(int array[], int size);

    /// @brief Print a vector with comma separated elements
    /// @param vec Reference to the vector to print
    /// @return The vector elements (comma-separated)
    std::string print_vector(std::vector<int> &vec);

    /// @brief Solve for the quadratic equation, given coefficients
    /// @param a Coefficient of the quadratic equation
    /// @param b Coefficient of the quadratic equation
    /// @param c Coefficient of the quadratic equation
    /// @param r1 Denotes the real part of solution 1
    /// @param i1 Denotes the imaginary part of solution 1
    /// @param r2 Denotes the real part of solution 2
    /// @param i2 Denotes the imaginary part of solution 2
    /// @return If the function contains an imaginary part then return `false`, otherwise return `true`
    bool quadratic_formula(float a, float b, float c, float &r1, float &i1, float &r2, float &i2);
}
