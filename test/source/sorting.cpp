#include <doctest/doctest.h>
#include <sorting/sorting.h>
#include <sorting/version.h>

#include <string>
#include <vector>

TEST_CASE("Sorter - basic sort") {
  using namespace sorting;

  const std::vector<int> unsorted = {5, 3, 1, 4, 2};
  const std::vector<int> expected = {1, 2, 3, 4, 5};

  CHECK(Sorter::sort(unsorted, Algorithm::BUBBLE) == expected);
  CHECK(Sorter::sort(unsorted, Algorithm::SELECTION) == expected);
  CHECK(Sorter::sort(unsorted, Algorithm::INSERTION) == expected);
}

TEST_CASE("Sorter - edge cases") {
  using namespace sorting;

  CHECK(Sorter::sort({}) == std::vector<int>{});
  CHECK(Sorter::sort({42}) == std::vector<int>{42});
  CHECK(Sorter::sort({1, 2, 3}) == std::vector<int>{1, 2, 3});
  CHECK(Sorter::sort({3, 2, 1}) == std::vector<int>{1, 2, 3});
  CHECK(Sorter::sort({2, 2, 2}) == std::vector<int>{2, 2, 2});
  CHECK(Sorter::sort({-3, 0, -1, 2}) == std::vector<int>{-3, -1, 0, 2});
}

TEST_CASE("Sorter version") {
  static_assert(std::string_view(SORTING_VERSION) == std::string_view("1.0"));
  CHECK(std::string(SORTING_VERSION) == std::string("1.0"));
}
