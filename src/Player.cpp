/**
* @author Kavya Patel <k.patel2@uleth.ca>, Japnoor Manku <japnoor.manku@uleth.ca>
* @date 2024-09
*/

#include "Player.hpp"
#include <iostream>

Player::Player(int initial_balance) : zephy_balance(initial_balance) {}

void Player::place_bet(int amount) {
    zephy_balance -= amount;
    std::cout << "Placed bet of " << amount;
    std:: cout << " credits. Remaining balance: ";
    std::cout << zephy_balance << " credits.\n";
}

void Player::receive_payout(int amount) {
    zephy_balance += amount;
    std::cout << "Received payout of ";
    std::cout << amount << " credits. New balance: ";
    std::cout << zephy_balance << " credits.\n";
}

int Player::get_balance() const {
    return zephy_balance;
}

bool Player::can_place_bet(int amount) {
    return zephy_balance >= amount;
}
