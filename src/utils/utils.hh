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

    float rad2deg(float rad);
    float deg2rad(float deg);
    float atan(float y, float x);

    double factorial(double n);
    double dist3(const vec3 &from, const vec3 &to);

    char to_upper(char n);
    char to_lower(char n);

    std::string print_vec3(const vec3 &v);

    int random(int low, int high, int seed = -1);
}
