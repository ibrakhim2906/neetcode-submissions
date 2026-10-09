class TreeNode {
    
    int key;
    int val;
    TreeNode right;
    TreeNode left;

    public TreeNode(int key, int val) {
        
        this.key = key;
        this.val = val;
        this.right = null;
        this.left = null;
    }
}


class TreeMap {

    TreeNode root;

    public TreeMap() {
        root = null;
    }

    public void insert(int key, int val) {
        
        TreeNode newNode = new TreeNode(key, val);

        if (root==null) {

            root = newNode;
            return;
        }

        TreeNode curr = root;

        while (true) {

            if (curr.key < key) {
                if (curr.right == null) {
                    curr.right = newNode;
                    return;
                }
                curr = curr.right;
            } else if (curr.key > key) {
                if (curr.left == null) {
                    curr.left = newNode;
                    return;
                }

                curr = curr.left;
            } else {
                
                curr.val = val;
                return;
            }
        }

    }

    public int get(int key) {
        
        TreeNode curr = root;

        while (curr!=null) {
            if (curr.key<key) {

                curr = curr.right;
            } else if (curr.key>key) {
                
                curr = curr.left;
            } else {
                
                return curr.val;
            }
        }

        return -1;
    }

    public int getMin() {
        if (root == null) return -1;
        TreeNode curr = root;

        while (curr.left!=null) {
            
            curr = curr.left;
        }

        return curr.val;

    }

    public int getMax() {
        if (root == null) return -1;
        TreeNode curr = root;

        while (curr.right!=null) {

            curr = curr.right;
        }

        return curr.val;

    }

    public void remove(int key) {

       root = removeHelper(root, key);
    }

    private TreeNode removeHelper(TreeNode curr, int key) {
        
        if (curr == null) {
            return null;
        }

        if (curr.key < key) {
            curr.right = removeHelper(curr.right, key);
        } else if (curr.key > key) {
            curr.left = removeHelper(curr.left, key);
        } else {
            if (curr.left == null) {
                return curr.right;
            } else if (curr.right == null) {
                return curr.left;
            } else {
                
                TreeNode minNode = curr.right;

                while (minNode.left!=null) {
                    minNode = minNode.left;
                }

                curr.val = minNode.val;
                curr.key = minNode.key;

                curr.right = removeHelper(curr.right, minNode.key);
            }
        }

        return curr;
    }

    public List<Integer> getInorderKeys() {
        
        List<Integer> res = new ArrayList<>();

        TreeNode curr = root;

        inorderHelper(curr, res);

        return res;
    }

    private void inorderHelper(TreeNode root, List<Integer> res) {
        
        if (root==null) {
            return;
        }

        inorderHelper(root.left, res);
        res.add(root.key);
        inorderHelper(root.right, res);


}
}