#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Flush after every cout / std:cerr
  while (true) {

    cout << unitbuf;
    cerr << unitbuf;

    cout << "$ ";

    string input;
    getline(cin, input);

    vector<string> tokens = tokeniser(input);
    parser(tokens);
  }

  return 0;
}
