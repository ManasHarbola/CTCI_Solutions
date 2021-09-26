public class CheckSubtree {
    //bfs for matching t2, then use helper for comparing subtrees
    public static boolean checkSubtree(TreeNode t1, TreeNode t2) {
        if (t1 == null) {
            return false;
        }
        if (t1.getVal() == t2.getVal() && compareSubtrees(t1, t2)) {
            return true;
        }
        return checkSubtree(t1.getLeft(), t2) || checkSubtree(t1.getRight(), t2);
    }
    public static boolean compareSubtrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return true;
        } else if (t1 == null) {
            return false;
        } else if (t2 == null) {
            return false;
        }
        return (t1.getVal() == t2.getVal())
                && compareSubtrees(t1.getLeft(), t2.getLeft())
                && compareSubtrees(t1.getRight(), t2.getRight());
    }
    public static void main(String[] args) {
    }
}
