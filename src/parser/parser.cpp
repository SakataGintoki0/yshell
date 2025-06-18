#include "../utils.h"
#include <string>
#include <vector>

void parser(vector<string> tokens) {
  string keyword = tokens[0];
  string argument = getArgument(tokens);

  if (keyword == "echo") {
    handleEcho(argument);
  } else if (keyword == "exit") {
    exit();
  } else if (keyword == "type") {
    type(argument);
  } else if (keyword == "pwd") {
    pwd();
  } else {
    execute(keyword, argument);
  }
}
