import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class ListDepths {
    public static ArrayList<LinkedList<TreeNode>> getListOfDepths(TreeNode root) {
        ArrayList<LinkedList<TreeNode>> lists = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root != null) {
            q.add(root);
        }
        while (!q.isEmpty()) {
            LinkedList<TreeNode> currDepth = new LinkedList<>();
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode tmp = q.poll();
                currDepth.add(tmp);
                if (tmp.getLeft() != null) {
                    q.add(tmp.getLeft());
                }
                if (tmp.getRight() != null) {
                    q.add(tmp.getRight());
                }
            }
            lists.add(currDepth);
        }
        return lists;
    }
    public static void main(String[] args) {
        TreeNode n1 = new TreeNode(0);
        TreeNode n2 = new TreeNode(1);
        TreeNode n3 = new TreeNode(2);
        TreeNode n4 = new TreeNode(3);
        TreeNode n5 = new TreeNode(4);

        n1.setLeft(n2);
        n1.setRight(n3);
        n2.setLeft(n4);
        n4.setLeft(n5);
        
        ArrayList<LinkedList<TreeNode>> result = getListOfDepths(n1);
        System.out.println(result);
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