class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (s.empty() || words.empty()) return ans;
    if (s.size() < words[0].size()) return ans;
    const int wordLen = words[0].size();
    vector<unsigned long long> hashSum(s.size(), 0);
    const unsigned long long base = 111;
    unsigned long long start = 0, t = 1;
    for (auto i = 1; i < wordLen; ++ i) t *= base;
    for (auto i = 0; i < wordLen; ++ i) {
      start = start * base + s[i];
    }
    hashSum[0] = start;
    for (auto i = 1; i + wordLen - 1 < s.size(); ++ i) {
      start = (start - s[i-1] * t) * base + s[i + wordLen - 1];
      hashSum[i] = start;
    }
    map<unsigned long long, int> hashWords;
    for (int i = 0; i < words.size(); ++ i) {
      unsigned long long tmp = words[i][0];
      for (auto j = 1; j < wordLen; ++ j) {
        tmp = tmp * base + words[i][j];
      }
      hashWords[tmp] ++;
    }
    map<unsigned long long, int> vis;
    for (auto i = 0; i + wordLen * words.size() - 1 < s.size(); ++ i) {
      if (hashWords.find(hashSum[i]) != hashWords.end()) {
        int j = i + wordLen, sum = 1;
        vis.clear();
        vis[hashSum[i]] ++;
        while (j + wordLen - 1 < s.size() && 
            hashWords.find(hashSum[j]) != hashWords.end() && 
            sum < words.size()) {
          if (vis[hashSum[j]] >= hashWords[hashSum[j]]) break;
          vis[hashSum[j]] ++;
          j += wordLen;
          sum ++;
        }
        if (sum == words.size()) {
          ans.emplace_back(i);
        }
      }
    }
    return ans;
  }
};