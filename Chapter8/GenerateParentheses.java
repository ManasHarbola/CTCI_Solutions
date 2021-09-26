import java.util.List;
import java.util.LinkedList;
public class GenerateParentheses {
    private static void generateParentheses(String currStr, List<String> arrangements, int remainingLeft, int remainingRight) {
        //base case: no more parentheses left to insert
        if (remainingLeft == 0 && remainingRight == 0) {
            arrangements.add(currStr);
            return;
        }

        if (remainingLeft > 0) {
            generateParentheses(currStr + "(", arrangements, remainingLeft - 1, remainingRight);
        }
        if (remainingLeft < remainingRight) {
            generateParentheses(currStr + ")", arrangements, remainingLeft, remainingRight - 1);
        }
    }
    public static List<String> generateParentheses(int n) {
        List<String> result = new LinkedList<>();
        generateParentheses("", result, n, n);
        return result;
    }
    public static void main(String[] args) {
        System.out.println(generateParentheses(3));
        System.out.println(generateParentheses(5));
    }
}
