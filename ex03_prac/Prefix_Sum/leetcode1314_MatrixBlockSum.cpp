// 1314. Matrix Block Sum
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
//
// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.
//
//
// Example 1:
//
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[12,21,16],[27,45,33],[24,39,28]]
// Example 2:
//
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
// Output: [[45,45,45],[45,45,45],[45,45,45]]
//
//
// Constraints:
//
// m == mat.length
// n == mat[i].length
// 1 <= m, n, k <= 100
// 1 <= mat[i][j] <= 100

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int BlockSum(int r1, int c1, int r2, int c2)
    {
        const auto& T = prefix_sum;
        r1++; c1++; r2++; c2++;
        return T[r2][c2] - T[r1-1][c2] - T[r2][c1-1] + T[r1-1][c1-1];
    }

    void CalcPrefixSum()
    {
        prefix_sum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int r = 1; r < matrix.size() + 1; ++r) {
            for (int c = 1; c < matrix[0].size() + 1; ++c) {
                prefix_sum[r][c] = prefix_sum[r-1][c] + prefix_sum[r][c-1] + matrix[r-1][c-1] - prefix_sum[r-1][c-1];
            }
        }
    }

    vector<vector<int>> matrixBlockSum(const vector<vector<int>>& mat, int k) {
        matrix = mat;
        CalcPrefixSum();
        vector<vector<int>> sum(mat.size(), vector<int>(mat[0].size(), 0));
        for (int r = 0; r < mat.size(); ++r) {
            for (int c = 0; c < mat[0].size(); ++c) {
                int r1 = ((r - k) >= 0) ? (r - k) : 0;
                int c1 = ((c - k) >= 0) ? (c - k) : 0;
                int r2 = ((r + k) < mat.size()) ? (r + k) : (mat.size() - 1);
                int c2 = ((c + k) < mat[0].size()) ? (c + k) : (mat[0].size() - 1);

                sum[r][c] = BlockSum(r1, c1, r2, c2);
            }
        }

        return sum;
    }

    vector<vector<int>> matrix;
    vector<vector<int>> prefix_sum;
};

int main()
{
    Solution s;
    s.matrixBlockSum(
        {{1,2,3}, {4,5,6}, {7,8,9}},
        1
    );
}