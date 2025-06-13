#include <iostream>
#include <string>

using namespace std;

int main() {
  // Flush after every cout / std:cerr
  while (true) {

    cout << unitbuf;
    cerr << unitbuf;

    cout << "$ ";

    string input;
    getline(cin, input);

    if (input == "exit 0") {
      exit(0);
    } else {
      cout << input << ": command not found" << endl;
    }
  }

  return 0;
}
