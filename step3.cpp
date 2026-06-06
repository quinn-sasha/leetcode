class Solution {
 public:
  bool wordBreak(std::string s, std::vector<std::string>& word_dict) {
    if (s.empty()) {
      return true;
    }
    std::vector<uint8_t> visited(s.length(), false);
    std::queue<int> reached_positions;
    reached_positions.push(0);
    while (!reached_positions.empty()) {
      int index = reached_positions.front();
      reached_positions.pop();
      for (const auto& word : word_dict) {
        if (s.compare(index, word.length(), word) != 0) {
          continue;
        }
        int next_index = index + word.length();
        if (next_index == s.length()) {
          return true;
        }
        if (!visited[next_index]) {
          visited[next_index] = true;
          reached_positions.push(next_index);
        }
      }
    }
    return false;
  }
};
