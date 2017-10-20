class Solution {
public:
  string simplifyPath(string path) {
    vector<string> pathS;
    int pre = 0;
    for (int i = 0; i < path.size(); ++ i) {
      if (path[i] == '/') {
        if (i - pre > 0) pathS.emplace_back(path.substr(pre, i - pre));
        pre = i + 1;
      } else if (path[i] == '.') {
        if (i > 0 && path[i-1] == '.') {
          if (!pathS.empty()) pathS.pop_back();
        }
        pre = i + 1;
      }
    }
    if (path[path.size() - 1] != '.' && path[path.size() - 1] != '/')
      pathS.emplace_back(path.substr(pre, path.size() - pre));
    string ans = "";
    for (int i = 0; i < pathS.size(); ++ i)
      if (!pathS[i].empty()) ans += "/" + pathS[i];
    if (ans.empty()) return "/";
    return ans;
  }
};