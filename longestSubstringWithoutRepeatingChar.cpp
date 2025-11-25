int lengthOfLongestSubstring(string s) {
    vector<int> freq(256, 0);   // assuming ASCII
    int n = s.size();
    int start = 0, maxLen = 0;

    for (int end = 0; end < n; ++end) {
        char c = s[end];
        freq[c]++;

        // If duplicate appears, shrink from left
        while (freq[c] > 1) {
            freq[s[start]]--;
            start++;
        }

        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}
