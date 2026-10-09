
class Graph {

    HashMap<Integer, List<Integer>> graph;

    public Graph() {
        graph = new HashMap<>();
    }

    public void addEdge(int src, int dst) {
        if (!graph.containsKey(src)) {
            graph.put(src, new ArrayList<>(List.of(dst)));
        } else {
            if (graph.get(src).contains(dst)) {
                return;
            }
            graph.get(src).add(dst);   
        }

        if (!graph.containsKey(dst)) {
            graph.put(dst, new ArrayList<>());
        } 
    }

    public boolean removeEdge(int src, int dst) {
        if (!graph.containsKey(src)) {
            return false;
        }

        if (!graph.get(src).contains(dst)) {
            return false;
        }

        graph.get(src).remove((Integer) dst);
        return true;
    }

    public boolean hasPath(int src, int dst) {
        
        return hasPathBFS(src, dst, graph);
    }

    private boolean hasPathBFS(int src, int dst, HashMap<Integer, List<Integer>> graph) {
        if (!graph.containsKey(src) || !graph.containsKey(dst)) {
            return false;
        }
        Set<Integer> visit = new HashSet<>();
        Deque<Integer> queue = new LinkedList<>();    
        
        queue.add(src);
        visit.add(src);

        while (!queue.isEmpty()) {
            int qSize = queue.size();
            for (int i=0; i<qSize; i++) {
                int curr = queue.poll();
                if (curr==dst) {
                    return true;
                }

                for (int currDST : graph.get(curr)) {
                    if (!visit.contains(currDST)) {
                        visit.add(currDST);
                        queue.add(currDST);
                    }
                }
            }
        }
        
        return false;
    }
}
