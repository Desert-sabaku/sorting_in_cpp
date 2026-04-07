#include <sorting/sorting.h>

using namespace sorting;

std::vector<int> Sorter::sort(std::vector<int> data, Algorithm algo) {
  switch (algo) {
    default:
    case Algorithm::BUBBLE: {
      for (std::size_t i = 0; i < data.size(); ++i) {
        for (std::size_t j = 0; j + 1 < data.size() - i; ++j) {
          if (data[j] > data[j + 1]) {
            std::swap(data[j], data[j + 1]);
          }
        }
      }
      break;
    }
    case Algorithm::SELECTION: {
      for (std::size_t i = 0; i < data.size(); ++i) {
        std::size_t min_idx = i;
        for (std::size_t j = i + 1; j < data.size(); ++j) {
          if (data[j] < data[min_idx]) {
            min_idx = j;
          }
        }
        std::swap(data[i], data[min_idx]);
      }
      break;
    }
    case Algorithm::INSERTION: {
      for (std::size_t i = 1; i < data.size(); ++i) {
        int key = data[i];
        std::size_t j = i;
        while (j > 0 && data[j - 1] > key) {
          data[j] = data[j - 1];
          --j;
        }
        data[j] = key;
      }
      break;
    }
  }
  return data;
}
