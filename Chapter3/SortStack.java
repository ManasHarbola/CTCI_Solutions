import java.util.Stack;
import java.util.LinkedList;

public class SortStack {
    public static void sortStack(Stack<Integer> stack) {
        Stack<Integer> tmpStack = new Stack<>();
        Integer tmpVar = null;

        while (!stack.isEmpty()) {
            if (tmpStack.isEmpty() || stack.peek().compareTo(tmpStack.peek()) >= 0) {
                tmpStack.push(stack.pop());
            } else {
                tmpVar = stack.pop();
                while (!tmpStack.isEmpty() && tmpStack.peek().compareTo(tmpVar) > 0) {
                    stack.push(tmpStack.pop());
                }
                tmpStack.push(tmpVar);
            }
        }
        while (!tmpStack.isEmpty()) {
            stack.push(tmpStack.pop());
        }
    }
    public static void main(String[] args) {
        Stack<Integer> test = new Stack<>();
        test.push(3);
        test.push(5);
        test.push(2);
        test.push(4);
        test.push(1);

        System.out.println(test);

        sortStack(test);

        System.out.println(test);
        System.out.println(test.peek());
    }
}
