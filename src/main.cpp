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

void printError(string cmd, string message) {
  cout << cmd << ": " << message << endl;
}

void handleEcho(vector<string> tokens) {
  string statement = "";
  for (int i = 1; i < tokens.size(); i++) {
    statement += tokens[i];
    if (i != tokens.size() - 1) {
      statement += " ";
    }
  }

  cout << statement << endl;
}

void exit() { exit(0); }

void parser(vector<string> tokens) {
  string keyword = tokens[0];

  if (keyword == "echo") {
    handleEcho(tokens);
  } else if (keyword == "exit") {
    exit();
  } else {
    printError(keyword, "command not found");
  }
}

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
