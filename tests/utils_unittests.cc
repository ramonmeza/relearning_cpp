#include <utils/utils.hh>
#include <gtest/gtest.h>

namespace
{
    /// @brief Positive test case for rad2deg
    TEST(rad2deg, Positive)
    {
        EXPECT_EQ(0, utils::rad2deg(0));
        EXPECT_NEAR(57.2958, utils::rad2deg(1), 0.5);
    }
}
