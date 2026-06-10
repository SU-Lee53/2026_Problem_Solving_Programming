// 1462. Course Schedule IV
// Medium
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
//
// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect.
// If course a is a prerequisite of course b, and course b is a prerequisite of course c,
// then course a is a prerequisite of course c.
//
// You are also given an array queries where queries[j] = [uj, vj].
// For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
//
// Return a boolean array answer, where answer[j] is the answer to the jth query.
//
// Example 1:
//
// Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
// Output: [false,true]
// Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
// Course 0 is not a prerequisite of course 1, but the opposite is true.
// Example 2:
//
// Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
// Output: [false,false]
// Explanation: There are no prerequisites, and each course is independent.
// Example 3:
//
//
// Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
// Output: [true,true]
//
//
// Constraints:
//
// 2 <= numCourses <= 100
// 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
// prerequisites[i].length == 2
// 0 <= ai, bi <= numCourses - 1
// ai != bi
// All the pairs [ai, bi] are unique.
// The prerequisites graph has no cycles.
// 1 <= queries.length <= 104
// 0 <= ui, vi <= numCourses - 1
// ui != vi

// 다른 Course Schedule 과 문제는 비슷한데 위상정렬 문제가 아님
// 수업간의 선후관계를 넘어 한 수업에서 다른 수업까지 도달할수 있는가를 묻기 때문에 위상정렬이 아닌 Floyd-Warshall 이 맞음

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, const vector<vector<int>>& prerequisites, const vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));
        for (const auto& v : prerequisites) {
            reachable[v[0]][v[1]] = true;
        }

        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        vector<bool> answer(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            const auto& v = queries[i];
            answer[i] = reachable[v[0]][v[1]];
        }
        return answer;
    }

};


int main()
{
    Solution s;
    s.checkIfPrerequisite(2, {{1, 0}}, {{0, 1}, {1, 0}});
    s.checkIfPrerequisite(2, {}, {{1, 0}, {0, 1}});
    s.checkIfPrerequisite(3, {{1, 0}, {1, 2}, {2, 0}}, {{1, 0}, {1, 2}});
    s.checkIfPrerequisite(3, {{1, 0}, {2, 0}}, {{0,1}, {2,0}});

    s.checkIfPrerequisite(
        6,
        {{0,1},{1,2},{2,4},{3,2},{5,3}},
        {{0,3},{1,4},{1,3},{2,3},{3,2},{5,4}}
        );
}