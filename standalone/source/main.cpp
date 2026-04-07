#include <sorting/sorting.h>
#include <sorting/version.h>

#include <cxxopts.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

auto main(int argc, char** argv) -> int {
  const std::unordered_map<std::string, sorting::Algorithm> algorithms{
      {"bubble", sorting::Algorithm::BUBBLE},
      {"selection", sorting::Algorithm::SELECTION},
      {"insertion", sorting::Algorithm::INSERTION},
  };

  cxxopts::Options options(*argv, "A program to sort a list of integers!");

  std::string algorithm;
  std::string input;

  // clang-format off
  options.add_options()
    ("h,help", "Show help")
    ("v,version", "Print the current version number")
    ("i,input", "Comma-separated list of integers to sort", cxxopts::value(input)->default_value("5,3,1,4,2"))
    ("a,algo", "Sorting algorithm (bubble, selection, insertion)", cxxopts::value(algorithm)->default_value("bubble"))
  ;
  // clang-format on

  auto result = options.parse(argc, argv);

  if (result["help"].as<bool>()) {
    std::cout << options.help() << std::endl;
    return 0;
  }

  if (result["version"].as<bool>()) {
    std::cout << "Sorting, version " << SORTING_VERSION << std::endl;
    return 0;
  }

  auto algoIt = algorithms.find(algorithm);
  if (algoIt == algorithms.end()) {
    std::cerr << "unknown algorithm: " << algorithm << std::endl;
    return 1;
  }

  std::vector<int> data;
  std::istringstream ss(input);
  std::string token;
  while (std::getline(ss, token, ',')) {
    try {
      data.push_back(std::stoi(token));
    } catch (const std::exception&) {
      std::cerr << "invalid integer value: " << token << std::endl;
      return 1;
    }
  }

  auto sorted = sorting::Sorter::sort(data, algoIt->second);
  for (std::size_t i = 0; i < sorted.size(); ++i) {
    if (i > 0) std::cout << " ";
    std::cout << sorted[i];
  }
  std::cout << std::endl;

  return 0;
}
