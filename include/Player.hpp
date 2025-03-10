/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>, Kavya Patel <k.patel2@uleth.ca>
* @date 2024-09
* @brief Represents a player in the game, managing their balance and interactions with betting
* @details The Player class handles the player's zephy balance, placing bets, receiving payouts and retrieving the current balance
*/

// Contains the class declaration for Player
#ifndef PLAYER_HPP
#define PLAYER_HPP

/**
 * @brief Class representing a player with a balance used for placing bets
 * @details The Player class maintains the balance and provides methods for placing bets and receiving payouts
 */

class Player {
 private:
    int zephy_balance;

 public:
   /**
     * @brief Initializes the player
     * @param[in] initial_balance The amount of zephys the player starts with
     */

    Player(int initial_balance);

    /**
     * @brief Places the players bet
     * @param[in] amount The amount of zephys the player bet
     */

    void place_bet(int amount);

    /**
     * @brief Receives a payout by adding the payout amount to the balance
     * @param[in] amount The amount of zephys received as a payout
     */

    void receive_payout(int amount);

    /**
     * @brief Retrieves the player's current balance
     * @return The current balance in zephys
     */

    int get_balance() const;

    /**
     * @brief checks if player has enough zephy to place bet
     * @param[in] amount The amount of zephys availible for a bet
     */

    bool can_place_bet(int amount);
};
// PLAYER_HPP
#endif
