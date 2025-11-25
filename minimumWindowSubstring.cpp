string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";

    vector<int> need(128, 0);
    for (char c : t) need[c]++;

    int required = 0;
    for (int x : need) if (x > 0) required++;

    vector<int> have(128, 0);
    int formed = 0;

    int n = s.size();
    int bestLen = INT_MAX, bestStart = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        char c = s[end];
        have[c]++;

        // check if this char's count just matched the need
        if (need[c] > 0 && have[c] == need[c]) {
            formed++;
        }

        // try to shrink while window is valid
        while (formed == required) {
            if (end - start + 1 < bestLen) {
                bestLen = end - start + 1;
                bestStart = start;
            }

            char leftChar = s[start];
            have[leftChar]--;
            if (need[leftChar] > 0 && have[leftChar] < need[leftChar]) {
                formed--;
            }
            start++;
        }
    }

    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}
