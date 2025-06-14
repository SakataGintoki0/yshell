#include "utils.h"
#include <string>
#include <vector>

using namespace std;

bool binarySearchString(vector<string> arr, string word) {
  bool isPresent = false;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == word)
      return true;
  }

  return isPresent;
}

string getArgument(vector<string> tokens) {
  string argument = "";
  for (int i = 1; i < tokens.size(); i++) {
    argument += tokens[i];
    if (i != tokens.size() - 1) {
      argument += " ";
    }
  }

  return argument;
}
