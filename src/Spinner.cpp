/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>
* @date 2024-09
*/

#include "Spinner.hpp"
#include <cstdlib>
#include <ctime>
#include "MakeRandomInt.hpp"

int LowStakesSpinner::spin() {
    MakeRandomInt& randomGen = MakeRandomInt::getInstance();
    return 2 + randomGen.getValue(4);  // Random number between 2 and 5
}

int HighStakesSpinner::spin() {
    MakeRandomInt& randomGen = MakeRandomInt::getInstance();
    return randomGen.getValue(8);  // Random number between 0 and 7
}
