public class ValidateBST {
    public static boolean isBST(TreeNode root) {
        return isBSTHelper(root, null, null);
    }
    private static boolean isBSTHelper(TreeNode currNode, Integer min, Integer max) {
        if (currNode == null) {
            return true;
        }
        if (min != null && currNode.getVal() < min) {
            return false;
        }
        if (max != null && currNode.getVal() > max) {
            return false;
        }
        if (!isBSTHelper(currNode.getLeft(), min, currNode.getVal()) || !isBSTHelper(currNode.getRight(), currNode.getVal(), max)) {
            return false;
        }
        return true;
    }
    public static void main(String[] args) {

    }

}