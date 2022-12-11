#include <cmath>
#include <vector>
#include <utils/utils.hh>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;
using namespace std;

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

    /// @brief Positive test case for bubble_sort
    TEST(bubble_sort, Positive)
    {
        int values[] = {12, 5, 21, 1, 15, 17};
        int num_elements = sizeof(values) / sizeof(int);
        utils::bubble_sort(values, num_elements);
        ASSERT_THAT(values, ElementsAre(1, 5, 12, 15, 17, 21));
    }

    /// @brief Positive test case for dice(int&, int&)
    TEST(dice_by_reference, Positive)
    {
        int num_tests = 10000000;

        int die1, die2 = 0;

        for (unsigned int i = 0; i < num_tests; i++)
        {
            utils::dice(&die1, &die2);
            EXPECT_GE(die1, 1);
            EXPECT_LE(die1, 6);
            EXPECT_GE(die2, 1);
            EXPECT_LE(die2, 6);
        }
    }

    /// @brief Positive test case for dice(int*, int*)
    TEST(dice_by_pointer, Positive)
    {
        int num_tests = 10000000;

        int die1, die2 = 0;

        for (unsigned int i = 0; i < num_tests; i++)
        {
            utils::dice(die1, die2);
            EXPECT_GE(die1, 1);
            EXPECT_LE(die1, 6);
            EXPECT_GE(die2, 1);
            EXPECT_LE(die2, 6);
        }
    }

    /// @brief Positive test case for random_array_fill
    TEST(random_array_fill, Positive)
    {
        int values[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        int num_elements = sizeof(values) / sizeof(int);

        utils::random_array_fill(values, num_elements);

        for (unsigned int i = 0; i < num_elements; i++)
        {
            EXPECT_NE(values[i], -1);
        }
    }

    /// @brief Positive test case for random_vector_fill
    TEST(random_vector_fill, Positive)
    {
        vector<int> values = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

        utils::random_vector_fill(values);

        for (auto itr = values.begin(); itr != values.end(); itr++)
        {
            EXPECT_NE(*itr, -1);
        }
    }

    /// @brief Positive test case for print_array(int[], int)
    TEST(print_array, Positive)
    {
        int values1[] = {1, 2, 3};
        int values2[] = {0, 5, -1, -46};
        int values3[] = {123, -456, 789, 22, 5};

        EXPECT_EQ(utils::print_array(values1, sizeof(values1) / sizeof(int)), "1, 2, 3");
        EXPECT_EQ(utils::print_array(values2, sizeof(values2) / sizeof(int)), "0, 5, -1, -46");
        EXPECT_EQ(utils::print_array(values3, sizeof(values3) / sizeof(int)), "123, -456, 789, 22, 5");
    }

    /// @brief Positive test case for print_vector
    TEST(print_vector, Positive)
    {
        vector<int> values1 = {1, 2, 3};
        vector<int> values2 = {0, 5, -1, -46};
        vector<int> values3 = {123, -456, 789, 22, 5};

        EXPECT_EQ(utils::print_vector(values1), "1, 2, 3");
        EXPECT_EQ(utils::print_vector(values2), "0, 5, -1, -46");
        EXPECT_EQ(utils::print_vector(values3), "123, -456, 789, 22, 5");
    }

    /// @brief Positive test case for quadratic_formula
    TEST(quadratic_formula, Positive)
    {
        float r1, i1, r2, i2 = -1;
        EXPECT_TRUE(utils::quadratic_formula(1, -1, -6, r1, i1, r2, i2));
        EXPECT_EQ(r1, 3);
        EXPECT_EQ(i1, 0);
        EXPECT_EQ(r2, -2);
        EXPECT_EQ(i2, 0);

        r1 = i1 = r2 = i2 = -1;
        EXPECT_TRUE(utils::quadratic_formula(1, -2, 1, r1, i1, r2, i2));
        EXPECT_EQ(r1, 1);
        EXPECT_EQ(i1, 0);
        EXPECT_EQ(r2, 1);
        EXPECT_EQ(i2, 0);

        r1 = i1 = r2 = i2 = -1;
        EXPECT_FALSE(utils::quadratic_formula(1, 2, 5, r1, i1, r2, i2));
        EXPECT_EQ(r1, -1);
        EXPECT_EQ(i1, 2);
        EXPECT_EQ(r2, -1);
        EXPECT_EQ(i2, -2);
    }
}
