class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int res = (D - B) * (C - A) + (H - F) * (G - E);
        int A1 = max(A, E), B1 = max(B, F), C1 = min(C, G), D1 = min(D, H);
        if (D1 <= B1 || C1 <= A1) return res;
        return res - (D1 - B1) * (C1 - A1);
    }
};