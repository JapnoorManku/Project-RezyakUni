/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>, Kavya Patel <k.patel2@uleth.ca>
* @date 2024-10-14
*/

#include "gtest/gtest.h"
#include "Bet.hpp"

TEST(BetTest, ConstructorSetsAmount) {
    Bet bet(25);
    EXPECT_EQ(bet.get_amount(), 25);
}

TEST(BetTest, GetAmount) {
    Bet bet(50);
    EXPECT_EQ(bet.get_amount(), 50);
}

TEST(BetTest, CalculatePayout) {
    Bet bet(100);

    // Test various score cases
    EXPECT_EQ(bet.calculate_payout(10), 0);
    EXPECT_EQ(bet.calculate_payout(11), 0);
    EXPECT_EQ(bet.calculate_payout(12), 25);
    EXPECT_EQ(bet.calculate_payout(13), 50);
    EXPECT_EQ(bet.calculate_payout(14), 100);
    EXPECT_EQ(bet.calculate_payout(15), 125);
    EXPECT_EQ(bet.calculate_payout(16), 150);
    EXPECT_EQ(bet.calculate_payout(17), 200);
    EXPECT_EQ(bet.calculate_payout(18), 0);
}

TEST(BetTest, CalculatePayoutWithDifferentBetAmounts) {
    Bet betSmall(10);
    EXPECT_EQ(betSmall.calculate_payout(12), 2);
    EXPECT_EQ(betSmall.calculate_payout(17), 20);

    Bet betLarge(500);
    EXPECT_EQ(betLarge.calculate_payout(12), 125);
    EXPECT_EQ(betLarge.calculate_payout(17), 1000);
}

TEST(BetTest, CalculatePayoutBoundaryCases) {
    Bet bet(100);

    EXPECT_EQ(bet.calculate_payout(11), 0);
    EXPECT_EQ(bet.calculate_payout(12), 25);
    EXPECT_EQ(bet.calculate_payout(17), 200);
    EXPECT_EQ(bet.calculate_payout(18), 0);
}
