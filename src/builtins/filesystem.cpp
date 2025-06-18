#include "../utils.h"
#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void pwd() {
  fs::path cwd = fs::current_path();
  cout << cwd.string() << endl;
}

// /home/username

void changeDir(string pathname) {
  if (pathname[0] == '~') {
    string appendUser = "/" + getHome() + "/" + getUser();
    pathname.replace(0, 1, appendUser);
  }

  if (!fs::exists(pathname)) {
    cout << "cd: " << pathname << ": No such file or directory" << endl;
  } else {
    fs::current_path(pathname);
  }
}
