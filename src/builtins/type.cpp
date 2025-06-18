#include "../utils.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void type(string argument) {
  vector<string> builtins = {"echo", "pwd", "type", "exit", "cd"};
  string executablePathStr = executablePath(argument);

  if (binarySearchString(builtins, argument)) {
    cout << argument << " is a shell builtin" << endl;
  } else if (executablePathStr.size() > 0) {
    cout << executablePathStr << endl;
  } else {
    cout << argument << ": not found" << endl;
  }
}
