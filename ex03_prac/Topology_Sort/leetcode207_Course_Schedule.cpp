// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/description/?utm_source=chatgpt.com
// Medium
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that
// you must take course bi first if you want to take course ai.
//
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
//
// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:
//
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
//
// Constraints:
//
// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> course_graph(numCourses);
        for (const auto& v : prerequisites) {
            course_graph[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }


        int numTake = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();

            numTake++;

            for (auto& next : course_graph[now]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return numTake == numCourses;

    }
};

int main()
{
    Solution s;
    cout << std::boolalpha;
    cout << s.canFinish(2, {{1, 0}});
    cout << s.canFinish(2, {{1, 0}, {0, 1}});
}


