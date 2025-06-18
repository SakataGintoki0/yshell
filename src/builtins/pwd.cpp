#include "../utils.h"
#include <filesystem>
#include <iostream>

using namespace std;
using namespace filesystem;

void pwd() {
  path cwd = current_path();
  cout << cwd.string() << endl;
}
