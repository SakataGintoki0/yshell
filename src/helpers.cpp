#include "utils.h"
#include <cstdlib> // for PATH
#include <cstdlib> // for system()
#include <cstring> // for strlen()
#include <iostream>
#include <string>
#include <unistd.h> // for access()
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

vector<string> getPath() {
  const char *path = getenv("PATH");
  vector<string> pathArr;

  if (path) {
    string individualPath = "";
    for (int i = 0; i < strlen(path); i++) {
      if (path[i] == ':') {
        pathArr.push_back(individualPath);
        individualPath = "";
      } else if (i == strlen(path) - 1) {
        individualPath += path[i];
        pathArr.push_back(individualPath);
      } else {
        individualPath += path[i];
      }
    }
  } else {
    cout << "PATH not set!" << endl;
  }

  return pathArr;
}

bool isPathExecutable(string path, string cmd) {
  bool isExecutable = false;
  string fullPath = path + '/' + cmd;

  if ((access(fullPath.c_str(), X_OK) == 0)) {
    return true;
  }

  return isExecutable;
}

string executablePath(string cmd) {
  string path = "";
  vector<string> paths = getPath();
  for (int i = 0; i < paths.size(); i++) {
    if (isPathExecutable(paths[i], cmd)) {
      path = paths[i] + '/' + cmd;
      break;
    }
  }

  return path;
}

void execute(string keyword, string argument) {
  string path = executablePath(keyword);

  if (path.size() == 0) {
    printError(keyword, "command not found");
    return;
  }
  string cmdStr = keyword + ' ' + argument;
  int ret = system(cmdStr.c_str());

  if (ret == -1) {
    cerr << "Failed to execute command!" << endl;
  }
}
