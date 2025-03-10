/**
* @author Kavya Patel <k.patel2@uleth.ca>, Japnoor.Manku <japnoor.manku@uleth.ca>
*       
* @date 2024-10-14
*/

#include "gtest/gtest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Spinner.hpp"
#include "Bet.hpp"

class TestSpinner : public Spinner {
 private:
    int fixed_value;

 public:
    explicit TestSpinner(int value) : fixed_value(value) {}

    int spin() override {
        return fixed_value;
    }
};

TEST(GameTest, StartGameDeductsBet) {
    Player player(100);
    Bet bet(25);
    TestSpinner spinner(4);

    Game game(&player, &spinner, &bet);

    game.start();

    EXPECT_EQ(player.get_balance(), 75);
}

TEST(GameTest, PlayTurnUpdatesScore) {
    Player player(100);
    Bet bet(25);
    TestSpinner spinner(3);

    Game game(&player, &spinner, &bet);
    game.start();

    EXPECT_EQ(game.get_player_score(), 0);

    game.play_turn();
    EXPECT_EQ(game.get_player_score(), 3);
}

TEST(GameTest, GameEndsWhenScoreExceedsLimit) {
    Player player(100);
    Bet bet(25);
    TestSpinner spinner(18);

    Game game(&player, &spinner, &bet);
    game.start();

    game.play_turn();

    EXPECT_TRUE(game.is_game_over());
}

TEST(GameTest, EndGamePayout) {
    Player player(100);
    Bet bet(25);
    TestSpinner spinner(5);

    Game game(&player, &spinner, &bet);
    game.start();

    game.play_turn();
    game.play_turn();
    game.play_turn();

    game.end_game();

    EXPECT_EQ(player.get_balance(), 106);
}

TEST(GameTest, ResetScore) {
    Player player(100);
    Bet bet(25);
    TestSpinner spinner(4);

    Game game(&player, &spinner, &bet);
    game.start();

    game.play_turn();
    EXPECT_EQ(game.get_player_score(), 4);

    game.reset_score();
    EXPECT_EQ(game.get_player_score(), 0);
}

TEST(GameTest, GameDoesNotEndBelowLimit) {
    Player player(100);
    Bet bet(25);
    TestSpinner spinner(5);

    Game game(&player, &spinner, &bet);
    game.start();

    game.play_turn();
    game.play_turn();
    game.play_turn();

    EXPECT_FALSE(game.is_game_over());
}
