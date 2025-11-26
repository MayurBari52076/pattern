int trap(vector<int>& h) {
    int i = 0, j = h.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (i < j) {
        if (h[i] <= h[j]) {
            leftMax = max(leftMax, h[i]);
            water += leftMax - h[i];
            i++;
        } else {
            rightMax = max(rightMax, h[j]);
            water += rightMax - h[j];
            j--;
        }
    }
    return water;
}
