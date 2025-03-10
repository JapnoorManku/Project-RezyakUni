/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>, Owen Zgurski <owen.zgurski@uleth.ca>, Kavya Patel <k.patel2@uleth.ca>
* @date 2024-10-10
*/

#include "Player.hpp"
#include "Spinner.hpp"
#include "Bet.hpp"
#include "Game.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int get_choice(int min, int max) {
    int choice;
    while (true) {
        std::cout << "Choice > ";
        std::cin >> choice;
        if (choice >= min && choice <= max) break;
        std::cout << "Invalid choice, try again.\n";
    }
    return choice;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    std::cout << "=====Welcome to Rezyak=====" << std::endl;

    // Calling Player Constructor method
    Player player(50);  // A Player starts with 50 Zephy
    // FirstSpinner firstSpinner;
    // SecondSpinner secondSpinner;

    while (true) {
        try {
            std::cout << "\nYour current total is ";
            std::cout << player.get_balance() << " credits.\n";
            std::cout << "How much do you want to bet?\n";
            std::cout << "0) 0 credits (exit game).\n";
            std::cout << "1) 5 credits.\n";
            std::cout << "2) 25 credits.\n";
            std::cout << "3) 50 credits.\n";

            int bet_choice = get_choice(0, 3);

            // Exit game if the player chooses 0
            if (bet_choice == 0) {
                std::cout << "Your total winnings is ";
                std::cout << player.get_balance() << " credits.\n";
                std::cout << "Thanks for playing!\n";
                break;
            }

            int bet_amount;
            if (bet_choice == 1) bet_amount = 5;
            else if (bet_choice == 2) bet_amount = 25;
            else
                bet_amount = 50;

            // Check if player has enough balance to place the bet
            if (!player.can_place_bet(bet_amount)) {
                std::cout << "You don't have enough credits";
                std::cout << " to place this bet.\n";
                continue;
            }

            // Bet placed
            Bet* bet = new Bet(bet_amount);

            // Spinner selection
            std::cout << "\nWhat do you want to do?\n";
            std::cout << "1) Spin 2-5 spinner (Low stakes).\n";
            std::cout << "2) Spin 0-7 spinner (High stakes).\n";
            std::cout << "3) Stop spinning.\n";

            Spinner* spinner;
            int spinner_choice = get_choice(1, 2);

            if (spinner_choice == 1) {
                spinner = new LowStakesSpinner();  // Low stakes spinner
            } else {
                spinner = new HighStakesSpinner();  // High stakes spinner
            }

            // Initialize game with chosen spinner
            Game game(&player, spinner, bet);
            game.start();

            // Play turns until player decides to stop or exceeds limit of 17
            while (true) {
                std::cout << "\nWhat do you want to do?\n";
                std::cout << "1) Spin 2-5 spinner.\n";
                std::cout << "2) Spin 0-7 spinner.\n";
                std::cout << "3) Stop spinning.\n";

                int choice = get_choice(1, 3);

                if (choice == 3) {
                    break;
                }

                if (choice == 1 || choice == 2) {
                    game.play_turn();
                    if (game.is_game_over()) {
                        std::cout << "Game over!";
                        std::cout << "You exceeded the limit of 17.\n";
                        break;
                    }
                } else {
                    break;
                }
            }

            // End the game and reset score for next round
            game.end_game();
            game.reset_score();

            delete spinner;  // Free allocated memory for spinner
            delete bet;
        } catch (const bad_input& e) {
            std::cerr << "Error: " << e.what() << "\n";
            continue;  // Loop back and allow the player to retry
        } catch (const std::exception& e) {
            std::cerr << "Unexpected error: " << e.what() << "\n";
            break;  // Exit on unexpected error
        }
    }
}
