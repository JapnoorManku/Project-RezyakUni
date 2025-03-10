/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>, 
*         Kavya Patel <k.patel2@uleth.ca>
* @date 2024-10-08
*/

#include <gtest/gtest.h>
#include "Player.hpp"

// Test Player initialization
TEST(PlayerTest, Initialization) {
    Player player(100);
    EXPECT_EQ(player.get_balance(), 100);
}

// Test placing a bet and deducting from balance
TEST(PlayerTest, PlaceBet) {
    Player player(100);
    player.place_bet(50);  // Bet 50 credits
    EXPECT_EQ(player.get_balance(), 50);
}

// Test placing a bet when balance is insufficient
TEST(PlayerTest, PlaceBetInsufficientFunds) {
    Player player(30);
    EXPECT_FALSE(player.can_place_bet(50));
    //Can't place a bet if insufficient funds
}

// Test placing a bet with exact balance
TEST(PlayerTest, PlaceBetExactBalance) {
    Player player(50);
    EXPECT_TRUE(player.can_place_bet(50));
    // Player can place a bet with exact balance
    player.place_bet(50);  // Place the bet
    EXPECT_EQ(player.get_balance(), 0);  // Balance should now be 0
}

// Test receiving a payout and updating balance
TEST(PlayerTest, ReceivePayout) {
    Player player(50);
    player.receive_payout(25);  // Receive a payout of 25 credits
    EXPECT_EQ(player.get_balance(), 75);  // Balance should now be 75
}

// Test multiple bets and payouts
TEST(PlayerTest, MultipleBetsAndPayouts) {
    Player player(100);

    // Place two bets
    player.place_bet(30);  // Bet 30
    EXPECT_EQ(player.get_balance(), 70);

    player.place_bet(20);  // Bet 20
    EXPECT_EQ(player.get_balance(), 50);

    // Receive two payouts
    player.receive_payout(40);  // Payout of 40
    EXPECT_EQ(player.get_balance(), 90);

    player.receive_payout(10);  // Payout of 10
    EXPECT_EQ(player.get_balance(), 100);
}

// Test can_place_bet when there is enough balance
TEST(PlayerTest, CanPlaceBet) {
    Player player(100);
    EXPECT_TRUE(player.can_place_bet(50));   // Enough balance to place the bet
    EXPECT_TRUE(player.can_place_bet(100));  // Exact balance to place the bet
    EXPECT_FALSE(player.can_place_bet(150));
    // Insufficient balance to place the bet
}
