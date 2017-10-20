class Solution {
public:
  bool isMatch(string s, string p) {
    return findMatch(s, p, 0, 0);
  }
  bool findMatch(string &s, string &p, int pos, int pos2) {
    int i = pos;
    for (; i < p.size() && pos2 < s.size(); i ++) {
      if (isAlphabet(p[i])) {
        if (s[pos2] != p[i]) return false;
          ++ pos2;
      } else if (p[i] == '?') {
        ++ pos2;
      } else if (p[i] == '*' && (i + 1 == p.size() || (i + 1 < p.size() && 
          p[i+1] != '*'))) {
        if (i + 1 == p.size()) return true;
        while (pos2 < s.size()) {
          if ((s[pos2] == p[i+1] || p[i+1] == '?') && 
              findMatch(s, p, i + 2, pos2 + 1)) return true;
          ++ pos2;
        } // end while
      } // end if
    } // end for
    while (i < p.size() && p[i] == '*') ++ i;
    if (i == p.size() && pos2 == s.size()) return true;
    else if (p[p.size()-1] == '*' && pos2 < s.size()) return true;
    return false; 
  }
  bool isAlphabet(char a) {
    if (a != '?' && a != '*')
      return true;
    return false;
  }
};