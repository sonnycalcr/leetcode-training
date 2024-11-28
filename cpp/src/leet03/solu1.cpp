#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (!s.length() || s.length() == 1)
      return s.length();
    unordered_set<char> char_set;
    int res = 1;
    for (int i = 0; i < s.length() - 1; i++) {
      char_set.clear();
      char_set.insert(s[i]);
      for (int j = i + 1; j < s.length(); j++) {
        if (char_set.count(s[j]) > 0)
          break;
        char_set.insert(s[j]);
      }
      if (char_set.size() > res)
        res = char_set.size();
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution solu;
  int res;
  res = solu.lengthOfLongestSubstring("abcabcbb");
  res = solu.lengthOfLongestSubstring("bbbbb");
  std::cout << res << "\n";
  return 0;
}
