/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>, Kavya Patel <k.patel2@uleth.ca>
* @date 2024-09
* @file Bet.hpp
* @brief it has the declaration for the bet
*/

#ifndef BET_H
#define BET_H

/**
 * @class Bet
 * @brief player puts the bet in the game
 */

class Bet {
 private:
    int amount;

 public:
 /**
  * @brief construct a bet object
  * @param amt is the amount of bet
  */

    Bet(int amt);

 /**
  * @brief it gets the amount of bet
  * @return the bet amount
  */

    int get_amount() const;

 /**
  * @brief calculates the payout based on the score provided
  * @param score is the score obtained by the player
  * @return calculated payout based on the score
  */

    int calculate_payout(int score);
};

#endif // BET_HPP
