/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>
* @date 2024-09
*/


// Contains the implementation of the Bet class.
#include "Bet.hpp"
#include <stdexcept>

Bet::Bet(int amt) : amount(amt) {}

int Bet::get_amount() const {
    return amount;
}

// Payout table for scores between 12 and 17
int Bet::calculate_payout(int score) {
    int baseBet = get_amount();

    if (score < 11 || score > 17) {
        return 0;
    }
    switch (score) {
    case 12: return baseBet*0.25;
    case 13: return baseBet*0.5;
    case 14: return baseBet;
    case 15: return baseBet*1.25;
    case 16: return baseBet*1.5;
    case 17: return baseBet*2;
    default: return 0;
    }
    return 0;
}

