/**
* @author Japnoor Manku <japnoor.manku@uleth.ca>
* @date 2024-09
* @class Spinner Spinner.hpp "Spinner.hpp"
* @brief Abstract class representing a spinner
* @details The Spinner class provides a basic interface for spinning functionality
* The `spin` method must be implemented by any derived class
*/

#ifndef SPINNER_HPP
#define SPINNER_HPP

#include <vector>

/**
 * @class Spinner Spinner.hpp "Spinner.hpp"
 * @brief Spinner class implementing the Spinner interface
 */

class Spinner {
 public:
    virtual int spin() = 0;
    virtual ~Spinner() = default;
};

/**
 * @class LowStakesSpinner Spinner.hpp "Spinner.hpp"
 * @brief LowStakesSpinner class implementing the Spinner interface
 * @details This class defines a specific type of spinner with its own spinning mechanism
 */

class LowStakesSpinner : public Spinner {
 public:
    int spin() override;
};

/**
 * @class MediumStakesSpinner Spinner.hpp "Spinner.hpp"
 * @brief MediumStakesSpinner class implementing the Spinner interface
 * @details This class defines a different type of spinner with its own spinning mechanism
 */

class MediumStakesSpinner : public Spinner {
 public:
    int spin() override;
};

/**
 * @class HighStakesSpinner Spinner.hpp "Spinner.hpp"
 * @brief HighStakesSpinner class implementing the Spinner interface
 * @details This class defines a specific type of spinner with its own spinning mechanism
 */

class HighStakesSpinner : public Spinner {
 public:
    int spin() override;
};
#endif
