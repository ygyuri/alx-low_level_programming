#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  // Initialize random seed
  std::srand(std::time(nullptr));
  
  // Generate random number between -100 and 100
  int n = std::rand() % 201 - 100;
  
  // Print the random number
  std::cout << "The number " << n << " ";
  
  // Check if the number is positive, negative, or zero
  if (n > 0) {
    std::cout << "is positive";
  } else if (n < 0) {
    std::cout << "is negative";
  } else {
    std::cout << "is zero";
  }
  
  // Print a new line
  std::cout << std::endl;
  
  return 0;
}

