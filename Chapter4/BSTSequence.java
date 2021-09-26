import java.util.ArrayList;
import java.util.LinkedList;
public class BSTSequence {
    public static ArrayList<LinkedList<Integer>> getSequences(TreeNode root) {
        return sequencesHelper(root);
    }
    private static ArrayList<LinkedList<Integer>> sequencesHelper(TreeNode currNode) {
        ArrayList<LinkedList<Integer>> result = new ArrayList<>();
        if (currNode == null) {
            result.add(new LinkedList<Integer>());
            return result;
        }
        ArrayList<LinkedList<Integer>> leftResult = sequencesHelper(currNode.getLeft());
        ArrayList<LinkedList<Integer>> rightResult = sequencesHelper(currNode.getRight());
        if (leftResult.get(0).size() == 0 && rightResult.get(0).size() == 0) {
            LinkedList<Integer> l = new LinkedList<>();
            l.add(currNode.getVal());
            result.add(l);
            return result;
        }
        for (LinkedList<Integer> leftSeq : leftResult) {
            for (LinkedList<Integer> rightSeq : rightResult) {
                LinkedList<Integer> newSeq1 = new LinkedList<>();
                LinkedList<Integer> newSeq2 = new LinkedList<>();
                newSeq1.add(currNode.getVal());
                newSeq1.addAll(leftSeq);
                newSeq1.addAll(rightSeq);

                newSeq2.add(currNode.getVal());
                newSeq2.addAll(rightSeq);
                newSeq2.addAll(leftSeq);
                
                result.add(newSeq1);
                result.add(newSeq2);
            }
        }
        return result;
    }
    public static void main(String[] args) {
        TreeNode n1 = new TreeNode(5);
        TreeNode n2 = new TreeNode(3);
        TreeNode n3 = new TreeNode(4);
        TreeNode n4 = new TreeNode(7);
        TreeNode n5 = new TreeNode(6);
        TreeNode n6 = new TreeNode(9);
        TreeNode n7 = new TreeNode(8);

        n1.setLeft(n2);
        n1.setRight(n4);
        n2.setRight(n3);

        n4.setLeft(n5);
        n4.setRight(n6);
        n6.setLeft(n7);

        System.out.println(getSequences(n1));
    }
}
