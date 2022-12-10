#include <string>

namespace utils
{
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

    double factorial(double n);
    char to_upper(char n);
    char to_lower(char n);
    std::string print_vec3(const vec3 &v);
    double dist3(const vec3 &from, const vec3 &to);
}
