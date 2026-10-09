
class Graph:
    
    def __init__(self):
    
        self.edges={}

    def addEdge(self, src: int, dst: int) -> None:

        if src not in self.edges:
            self.edges[src] = []
        if dst not in self.edges:
            self.edges[dst] = []
        if dst not in self.edges[src]:
            self.edges[src].append(dst)

    def removeEdge(self, src: int, dst: int) -> bool:
        
        if src in self.edges:
            if dst in self.edges[src]:
                self.edges[src].remove(dst)
                if self.edges[dst]==[]:
                    del self.edges[dst]
                return True
            else:
                return False
        else:
            return False


    def hasPath(self, src: int, dst: int) -> bool:

        if src not in self.edges:
            return False

        visit = set()
        queue = deque()

        visit.add(src)
        queue.append(src)
        
        while queue:
            for i in range(len(queue)):

                src_1 = queue.popleft()

                for dst_1 in self.edges[src_1]:
                    
                    if dst_1 in visit:
                        continue
                    
                    if dst_1 == dst:
                        return True
                    
                    queue.append(dst_1)
                    visit.add(dst_1)

        return False
                    

        
        

