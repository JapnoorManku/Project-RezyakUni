/**
* @author Owen Zgurski <owen.zgurski@uleth.ca>, Japnoor Manku <japnoor.manku@uleth.ca>
* @date 2024-10-03
*/


#include "Game.hpp"
//#include "PayoutRules.hpp"
#include "Bet.hpp"
#include <iostream>


Game::Game(Player* p, Spinner* s, Bet* b)
    : player(p), spinner(s), bet(b), player_score(0) {}

void Game::start() {
    player->place_bet(bet->get_amount());
}

void Game::play_turn() {
    int spin_result = spinner->spin();
    player_score += spin_result;
    std::cout << "You spun a " << spin_result;
    std::cout << ". Your current total is " << player_score << ".\n";
}

void Game::end_game() {
    int payout = bet->calculate_payout(player_score);
    std::cout << "You win " << payout << " credits!\n";
    player->receive_payout(payout);
    std::cout << "Your current balance: ";
    std::cout << player->get_balance() << " credits.\n";
}

int Game::get_player_score() const {
     return player_score;
}

void Game::reset_score() {
    player_score = 0;
}

bool Game::is_game_over() const {
    return player_score > 17;
    // Game over if score is less than 12 or score exceeds 17
}
