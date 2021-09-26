import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.LinkedList;

public class RouteBetweenNodes {
    //conduct a BFS search for a path between the start and end nodes
    //use a hashset to judge whether has node has already visited
    public static boolean routeExists(Graph g, Node start, Node end) {
        if (start == null || end == null) {
            return false;
        }
        if (start == end) {
            return true;
        }
        Set<Node> visited = new HashSet<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(start);
        Node curr;
        while (!queue.isEmpty()) {
            curr = queue.poll();
            visited.add(curr);
            for (Node child : curr.getChildren()) {
                //to avoid cycles, only consider unvisited nodes in graph
                if (!visited.contains(child)) {
                    if (child == end) {
                        return true;
                    }
                    else {
                        queue.add(child);
                    }
                }
            }
        }
        
        return false;
    }
    public static void main(String[] args) {
        
    }
}

class Graph {
    private Node[] nodes;
    public Graph(List<Node> nodes) {
        this.nodes = new Node[nodes.size()];
        for (int i = 0; i < nodes.size(); i++) {
            this.nodes[i] = nodes.get(i);
        }
    }
    public Node[] getNodes() {
        return nodes;
    }
}
class Node {
    private int val;
    private Node[] children;
    public Node(int val, Node[] children){
        this.val = val;
        this.children = children;
    }
    public Node() {
        this(0, null);
    }
    public int getVal() {
        return val;
    }
    public Node[] getChildren() {
        return children;
    }
}
