/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>, Kavya Patel <k.patel2@uleth.ca>
* @date 2024-10-10
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Spinner.hpp"
#include "Bet.hpp"
#include <memory>

/**
 * @brief Class representing the game logic
 * @details This class manages the interaction between the player, spinners, and the bet
 * The game flow, calculates the player's score, and determines when the game ends
 */

class Game {
 private:
    Player* player;
    Spinner* spinner;
    Bet* bet;
    int player_score;

 public:
  /**
     * @brief Constructs a Game object.
     * @param[in] player Pointer to the player participating in the game
     * @param[in] bet Pointer to the bet placed by the player
     */

    Game(Player* p, Spinner* s, Bet* b);

    /**
     * @brief Starts the game
     * @details This method initiates the game and prepares all necessary components
     */

    void start();

    /**
     * @brief Plays a single turn in the game
     * @details This method handles the operations for each turn, including spinning the spinners and updating the score
     */

    void play_turn();

    /**
     * @brief Checks if the game exceeds the score limit
     * @return True if the game is over the score limit, false otherwise
     */

    bool is_over_limit() const;

    /**
     * @brief Ends the game and calculates the final score
     * @details This method finalizes the game, determining if the player has won or lost based on their score
     */

    void end_game();

    /**
     * @brief gets the players score
     * @details returns the players current score at the end and after turns if called
     */

    int get_player_score() const;

    /**
     * @brief resets score
     * @details sets players score to 0 at beginning and if a new game is played
     */

    void reset_score();

    /**
     * @brief returns the players score if they go over 17
     * @return The players score if they go over 17
     */

    bool is_game_over() const;
};

#endif // GAME_H
