#include "utils.h"
#include <cstdlib> // for setenv or _putenv
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void load_env_file(const string &filepath) {
  ifstream file(filepath);
  if (!file.is_open()) {
    cerr << "Could not open .env file: " << filepath << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    // Skip comments and empty lines
    if (line.empty() || line[0] == '#')
      continue;

    size_t delimiter = line.find('=');
    if (delimiter == string::npos)
      continue;

    string key = line.substr(0, delimiter);
    string value = line.substr(delimiter + 1);

#ifdef _WIN32
    // _putenv requires a single string like "KEY=VALUE"
    string env_string = key + "=" + value;
    _putenv(env_string.c_str());
#else
    setenv(key.c_str(), value.c_str(), 1); // overwrite = true
#endif
  }

  file.close();
}
