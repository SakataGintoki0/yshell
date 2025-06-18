#include "../utils.h"
#include <iostream>
#include <limits.h> // for PATH_MAX
#include <unistd.h> // for getcwd

using namespace std;

void pwd() {
  char cwd[PATH_MAX];

  if (getcwd(cwd, sizeof(cwd)) != nullptr) {
    cout << cwd << endl;
  } else {
    cerr << "getcwd() error" << endl;
  }
}
