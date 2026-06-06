class Solution {
 public:
  bool wordBreak(std::string s, std::vector<std::string>& word_dict) {
    std::vector<uint8_t> breakable_until(s.size(), false);
    for (int i = 0; i < s.size(); ++i) {
      for (const auto& word : word_dict) {
        int start = i - word.size() + 1;
        if (start < 0) {
          continue;
        }
        if (start == 0 || breakable_until[start - 1]) {
          if (s.compare(start, word.size(), word) == 0) {
            breakable_until[i] = true;
            break;
          }
        }
      }
    }
    return breakable_until.back();
  }
};
