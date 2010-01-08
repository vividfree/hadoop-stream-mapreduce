// Author: yi.wang.2005@gmail.com (Yi Wang)

#include <set>
#include <vector>
#include <string>

using namespace std;

void SplitStringUsing(const string& full, const char* delim,
                      vector<string>* res);
void SplitStringToSetUsing(const string& full, const char* delim,
                           set<string>* result);
