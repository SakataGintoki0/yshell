#include "../utils.h"
#include <iostream>

using namespace std;

string removeQuotes(string str) {
  string res = "";
  for (int i = 1; i < str.size() - 1; i++) {
    res += str[i];
  }

  return res;
}

string removeNullChar(string str) {
  string res = "";
  string tempStr = "";
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ' ' || i == str.size() - 1) {
      if (tempStr.size() == 0)
        continue;
      tempStr += str[i];
      res += tempStr;
      tempStr = "";
    } else {
      tempStr += str[i];
    }
  }

  return res;
}

void handleEcho(string statement) {
  if (statement[0] == '\'' && statement.back() == '\'') {
    string statementWithoutQuotes = removeQuotes(statement);
    cout << statementWithoutQuotes << endl;
  } else {
    cout << removeNullChar(statement) << endl;
  }
}
