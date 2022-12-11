#include <cmath>
#include <utils/utils.hh>
#include <gtest/gtest.h>

namespace
{
    /// @brief Positive test case for rad2deg
    TEST(rad2deg, Positive)
    {
        float tolerance = 0.01;

        EXPECT_EQ(utils::rad2deg(0), 0);
        EXPECT_NEAR(utils::rad2deg(1), 57.2958, tolerance);
    }

    /// @brief Positive test case for deg2rad
    TEST(deg2rad, Positive)
    {
        float tolerance = 0.01;

        EXPECT_EQ(utils::deg2rad(0), 0);
        EXPECT_NEAR(utils::deg2rad(57.2958), 1, tolerance);
    }

    /// @brief Positive test case for factorial
    TEST(factorial, Positive)
    {
        EXPECT_EQ(utils::factorial(0), 1);
        EXPECT_EQ(utils::factorial(1), 1);
        EXPECT_EQ(utils::factorial(2), 2);
        EXPECT_EQ(utils::factorial(3), 6);
        EXPECT_EQ(utils::factorial(4), 24);
        EXPECT_EQ(utils::factorial(5), 120);
        EXPECT_EQ(utils::factorial(6), 720);
        EXPECT_EQ(utils::factorial(7), 5040);
        EXPECT_EQ(utils::factorial(8), 40320);
        EXPECT_EQ(utils::factorial(9), 362880);
        EXPECT_EQ(utils::factorial(10), 3628800);
    }

    /// @brief Positive test case for to_upper
    TEST(to_upper, Positive)
    {
        EXPECT_EQ(utils::to_upper('a'), 'A');
        EXPECT_EQ(utils::to_upper('e'), 'E');
        EXPECT_EQ(utils::to_upper('g'), 'G');
        EXPECT_EQ(utils::to_upper('n'), 'N');
        EXPECT_EQ(utils::to_upper('t'), 'T');
        EXPECT_EQ(utils::to_upper('z'), 'Z');
    }

    /// @brief Positive test case for to_lower
    TEST(to_lower, Positive)
    {
        EXPECT_EQ(utils::to_lower('A'), 'a');
        EXPECT_EQ(utils::to_lower('E'), 'e');
        EXPECT_EQ(utils::to_lower('G'), 'g');
        EXPECT_EQ(utils::to_lower('N'), 'n');
        EXPECT_EQ(utils::to_lower('T'), 't');
        EXPECT_EQ(utils::to_lower('Z'), 'z');
    }

    /// @brief Positive test case for print_vec3
    TEST(print_vec3, Positive)
    {
        utils::vec3 v1 = {1, 2, 3};
        utils::vec3 v2 = {0, 5, -1};
        utils::vec3 v3 = {123, -456, 789};

        EXPECT_EQ(utils::print_vec3(v1), "(1, 2, 3)");
        EXPECT_EQ(utils::print_vec3(v2), "(0, 5, -1)");
        EXPECT_EQ(utils::print_vec3(v3), "(123, -456, 789)");
    }

    /// @brief Positive test case for dist3
    TEST(dist3, Positive)
    {
        float tolerance = 0.01;

        utils::vec3 v1 = {0, 0, 0};
        utils::vec3 v2 = {7, 4, 3};
        utils::vec3 v3 = {17, 6, 2};

        EXPECT_NEAR(utils::dist3(v1, v2), 8.602325, tolerance);
        EXPECT_NEAR(utils::dist3(v1, v3), 18.138357, tolerance);
        EXPECT_NEAR(utils::dist3(v2, v3), 10.246951, tolerance);
    }

    /// @brief Positive test case for atan
    TEST(atan, Positive)
    {
        float tolerance = 0.01;

        EXPECT_NEAR(utils::atan(4, 2), atan2f(4, 2), tolerance);
        EXPECT_NEAR(utils::atan(5, -1), atan2f(5, -1), tolerance);
        EXPECT_NEAR(utils::atan(-4, -6), atan2f(-4, -6), tolerance);
        EXPECT_NEAR(utils::atan(-6, 4), atan2f(-6, 4), tolerance);
    }

    /// @brief Positive test case for random
    TEST(random, Positive)
    {
        int rand_val = 0;
        int num_tests = 10000000;
        int report_rate = 100;
        int min = -10;
        int max = 10;

        for (unsigned int i = 0; i < num_tests; i++)
        {
            rand_val = utils::random(min, max);

            EXPECT_GE(rand_val, min);
            EXPECT_LE(rand_val, max);
        }
    }

    /// @brief Positive test case for binary_search
    TEST(binary_search, Positive)
    {
        int values[] = {1, 4, 5, 6, 9, 14, 21, 23, 28, 31, 35, 42, 46, 50, 53, 57, 62, 63, 65, 74, 79, 89, 95};
        int num_elements = sizeof(values) / sizeof(int);

        EXPECT_EQ(utils::binary_search(values, num_elements, 21), 6);
        EXPECT_EQ(utils::binary_search(values, num_elements, 50), 13);
        EXPECT_EQ(utils::binary_search(values, num_elements, 0), -1);
    }
}
