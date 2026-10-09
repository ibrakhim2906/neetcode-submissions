class Solution:
    def shortestPath(self, grid: List[List[int]]) -> int:
        return self.bfs(grid)

    def bfs(self, grid: list[list[int]]):
        
        ROWS = len(grid)
        COLS = len(grid[0])

        queue = deque()
        visit = set()

        length = 0
        queue.append((0,0))
        visit.add((0,0))

        while queue:
            for i in range(len(queue)):
                r, c = queue.popleft()
                
                if r==ROWS-1 and c==COLS-1:
                    return length

                neighbours=[[1,0], [-1, 0], [0, 1], [0, -1]]
                for dr, dc in neighbours:
                    if (min(r+dr, c+dc)<0 or r+dr==ROWS or c+dc==COLS or grid[r+dr][c+dc]==1 or (r+dr, c+dc) in visit):
                        continue
                    queue.append((r+dr,c+dc))
                    visit.add((r+dr, c+dc))
            length+=1

        return -1

        