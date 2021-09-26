public class CheckBalance {
    public static boolean checkBalance(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (Math.abs(getBalance(root)) > 1) {
            return false;
        }
        return true;
    }
    public static int getBalance(TreeNode node) {
        if (node == null) {
            return -1;
        }
        int leftBalance = getBalance(node.getLeft());
        if (Math.abs(leftBalance) > 1) {
            return leftBalance;
        }
        int rightBalance = getBalance(node.getRight());
        if (Math.abs(rightBalance) > 1) {
            return rightBalance;
        }
        return leftBalance - rightBalance;
    }
    public static void main(String[] args) {
        TreeNode n1 = new TreeNode(1);
        System.out.println(checkBalance(n1));
    }
}

public class TreeNode {
    private int val;
    private TreeNode left;
    private TreeNode right;
    
    public TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    public void setVal(int val) {this.val = val;}
    public void setLeft(TreeNode left) {this.left = left;}
    public void setRight(TreeNode right) {this.right = right;}

    public int getVal() {return val;}
    public TreeNode getLeft() {return left;}
    public TreeNode getRight() {return right;}

    public String toString() {
        return "(" + val + ")";
    }
}