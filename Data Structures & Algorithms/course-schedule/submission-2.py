class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {i : [] for i in range(numCourses)}

        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        visiting = set()

        def dfs(src: int):
            
            if src in visiting:
                return False

            if preMap[src]==[]:
                return True

            visiting.add(src)
            
            for pre in preMap[src]:
                if not dfs(pre):
                    return False
            
            visiting.remove(src)
            preMap[src] = []

            return True

        for i in range(numCourses):
            if not dfs(i):
                return False

        return True