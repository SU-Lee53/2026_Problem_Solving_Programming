import sys

input = sys.stdin.readline

# DFS 재귀, 백트래킹, preorder traversal, root -> left subtree -> right subtree
def DFS(r, c, dist):
    global max_dist     # 전역 변수 사용
    if dist == 26:      # 최대 거리
        max_dist = dist
        return

    max_dist = max(max_dist, dist) # 최대 거리 갱신
    for dr, dc in [[-1, 0], [1, 0], [0, -1], [0, 1]]:   # 상하좌우 4방향 탐색
        nr, nc = r+dr, r+dc
        if 0 <= nr < R and 0 <= nc < C and not visited[board[nr][nc]]:   # 좌표가 유효하고, 아직 방문하지 않았다면
            visited[board[nr][nc]] = True   # 방문처리
            DFS(nr, nc, dist + 1)
            # 백트래킹 : 이전 방문 표시를 해제하면 됨
            visited[board[nr][nc]] = False




R, C = map(int, input().strip().split())    # R행 C열
#알파벳을 ord를 이용해서 아스키로 미리 저장한다. 탐색할 때 매번 ord 하는 것을 방지
board = [map(lambda x : ord(x) - 65, input.strip()) for i in range(R)]

visited = [False] * 26
max_dist = 0    # 최대 탐색 거리
visited[board[0][0]] = True     # 좌측 상단 알파벳 방문 처리
DFS(0,0,1)
