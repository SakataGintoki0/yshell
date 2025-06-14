#include "../utils.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> tokeniser(string input) {
  vector<string> tokens;

  string token = "";
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == ' ') {
      tokens.push_back(token);
      token = "";
    } else if (i == input.size() - 1) {
      token += input[i];
      tokens.push_back(token);
    } else {
      token += input[i];
    }
  }

  return tokens;
}
