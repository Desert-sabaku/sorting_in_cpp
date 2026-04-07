#pragma once

#include <vector>

namespace sorting {

  /**  Sorting algorithm to use */
  enum class Algorithm { BUBBLE, SELECTION, INSERTION };

  /**
   * @brief A class for sorting vectors of integers using different algorithms
   */
  class Sorter {
  public:
    /**
     * @brief Sorts a vector of integers using the specified algorithm
     * @param data the vector to sort
     * @param algo the algorithm to use
     * @return a sorted copy of the vector
     */
    static std::vector<int> sort(std::vector<int> data,
                                 Algorithm algo = Algorithm::BUBBLE);
  };

}  // namespace sorting
