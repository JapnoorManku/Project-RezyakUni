/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>
* @date 2024-10-08
*/

#include <gtest/gtest.h>
#include "Spinner.hpp"
#include <cstdlib>
#include <ctime>

// Test LowStakesSpinner spin function
TEST(SpinnerTest, LowStakesSpinnerSpin) {
    LowStakesSpinner low_spinner;

    // Check that spin returns a value between 2 and 5
    for (int i = 0; i < 100; i++) {
        int result = low_spinner.spin();
        EXPECT_GE(result, 2);  // Should be >= 2
        EXPECT_LE(result, 5);  // Should be <= 5
    }
}

// Test HighStakesSpinner spin function
TEST(SpinnerTest, HighStakesSpinnerSpin) {
    HighStakesSpinner high_spinner;

    // Check that spin returns a value between 0 and 7
    for (int i = 0; i < 100; i++) {
        int result = high_spinner.spin();
        EXPECT_GE(result, 0);  // Should be >= 0
        EXPECT_LE(result, 7);  // Should be <= 7
    }
}
