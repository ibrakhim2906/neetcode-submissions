class TreeNode {
    int val;
    int key;
    TreeNode left;
    TreeNode right;

    public TreeNode(int key, int val) {
        this(null, key, val, null);
    }

    public TreeNode(TreeNode left, int key, int val, TreeNode right) {
        this.left=left;
        this.key=key;
        this.val=val;
        this.right=right;
    }
}

class TreeMap {

    private TreeNode root;

    public TreeMap() {
        root = null;
    }

    public void insert(int key, int val) {
        TreeNode newNode = new TreeNode(key,val);

        if (root==null) {
            root=newNode;
            return;
        }

        TreeNode curr = root;

        while (true) {
            
            if (key<curr.key) {
                if (curr.left==null) {
                    curr.left=newNode;
                    return;
                }
                curr=curr.left;
            } else if (key>curr.key) {
                if (curr.right==null) {
                    curr.right=newNode;
                    return;
                }
                curr=curr.right;
            } else {
                curr.val=val;
                return;
            }
        }
    }

    public int get(int key) {

        TreeNode curr = root;
        
        while (curr != null) {
            if (curr.key<key) {
                curr=curr.right;
            } else if (curr.key>key) {
                curr=curr.left;
            } else {
                return curr.val;
            }    
        }
        return -1;
    }

    public int getMin() {
        if(root==null) {
            return -1;
        }

        TreeNode curr = root;
        
        while (curr.left!=null) {
            curr=curr.left;
        }

        return curr.val;
    }

    public TreeNode minValueNode(TreeNode root) {
        if (root==null) {
            return null;
        }
        TreeNode curr = root;
        
        while (curr.left!=null) {
            curr=curr.left;
        }

        return curr;
    }

    public int getMax() {
        if (root==null) {
            return -1;
        }

        TreeNode curr = root;

        while (curr.right!=null) {
            curr=curr.right;
        }

        return curr.val;
    }

    public void remove(int key) {
        root = removeHelper(root, key);
    }

    public TreeNode removeHelper(TreeNode root, int key) {
        if (root==null) {
            return null;
        }

        if (key<root.key) {
            root.left = removeHelper(root.left, key);
        } else if (key>root.key) {
            root.right = removeHelper(root.right, key);
        } else {
            if (root.right==null) {
                root=root.left;
            } else if (root.left==null) {
                root=root.right;
            } else {
                TreeNode minNode = minValueNode(root.right);
                root.key=minNode.key;
                root.val=minNode.val;
                root.right=removeHelper(root.right, minNode.key);
            }
        }

        return root;
    }

    public List<Integer> getInorderKeys() {
        List<Integer> out = new ArrayList<>();
        TreeNode curr = root;
        inorderHelper(out, curr);

        return out;
    }

    public void inorderHelper(List<Integer> out, TreeNode root) {
        if (root==null) {
            return;
        }

        inorderHelper(out, root.left);
        out.add(root.key);
        inorderHelper(out, root.right);
}
}
