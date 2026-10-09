/*
Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        Map<Node, Node> origToCopy = new HashMap<>();
        
        return clone(node, origToCopy);

    }

    public Node clone(Node node, Map<Node, Node> origToCopy) {
        if (node==null) {
            return null;
        }

        if (origToCopy.containsKey(node)) {
            return origToCopy.get(node);
        }

        Node copy = new Node(node.val);
        origToCopy.put(node, copy);

        for (Node nei : node.neighbors) {
            copy.neighbors.add(clone(nei, origToCopy));
        }

        return copy;
    }
}