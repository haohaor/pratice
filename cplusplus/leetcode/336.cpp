class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<pair<unsigned long long, unsigned long long>> hash;
    int maxLen = 0;
    const int base = 111;
    for (int i = 0; i < words.size(); ++ i) {
      unsigned long long sum1 = 0, sum2 = 0;
      for (int j = 0; j < words[i].size(); ++ j) {
        sum1 = sum1 * base + words[i][j];
        sum2 = sum2 * base + words[i][words[i].size() - j - 1];
      }
      maxLen = max(maxLen, int(words[i].size()));
      hash.push_back({sum1, sum2});
    }
    vector<unsigned long long> p(maxLen + 1, 0);
    p[0] = 1;
    for (int i = 1; i <= maxLen; ++ i)
      p[i] = p[i-1] * base;
    vector<vector<int>> ans;
    for (int i = 0; i < words.size(); ++ i) {
      for (int j = 0; j < words.size(); ++ j) {
        if (i == j) continue;
        unsigned long long hashCode = hash[i].first * p[words[j].size()] + hash[j].first,
            hashCode2 = hash[j].second * p[words[i].size()] + hash[i].second;
        if (hashCode2 == hashCode) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
};