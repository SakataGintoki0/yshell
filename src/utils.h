#pragma once
#include <string>
#include <vector>

using namespace std;

vector<string> tokeniser(string input);
void parser(vector<string> tokens);

// builtins
void handleEcho(string argument);
void exit();
void printError(string cmd, string message);
void type(string argument);

// helpers
bool binarySearchString(vector<string> arr, string word);
string getArgument(vector<string> tokens);
vector<string> getPath();
bool isPathExecutable(string path, string cmd);
string executablePath(vector<string> paths, string cmd);
