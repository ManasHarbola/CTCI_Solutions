import java.util.ArrayList;
public class BuildOrder {
    public static String[] buildOrder(String[] projects, String[][] dependencies) {
        Graph projectGraph = new Graph(projects, dependencies);
        String[] order = new String[projects.length];
        String[] error = new String[]{"error"};
        int nextOrderIdx = 0;
        ArrayList<Project> projectList = projectGraph.getProjects();
        
        //initial sweep
        for (Project p : projectList) {
            if (p.getDependencyCount() == 0) {
                order[nextOrderIdx] = p.getName();
                nextOrderIdx++;
            }
        }
        int toProcessIdx = 0;
        while (toProcessIdx < order.length) {
            if (order[toProcessIdx] == null) {
                return error;
            }
            Project currParent = projectGraph.getMap().get(order[toProcessIdx]);
            ArrayList<Project> children = currParent.getDependents();
            for (Project child : children) {
                if (child.getDependencyCount() > 0) {
                    child.decrementDependencyCount();
                    if (child.getDependencyCount() == 0) {
                        order[nextOrderIdx] = child.getName();
                        nextOrderIdx++;
                    }
                }
            }
            toProcessIdx++;
        }
        return order;
    }
    public static void main(String[] args) {
        String[] projects = new String[]{"a", "b", "c", "d", "e", "f"};
        String[][] dependencies = new String[][]{{"a", "d"}, {"f", "b"}, {"b", "d"},
                                                {"f", "a"}, {"d", "c"}};
        String[] order = buildOrder(projects, dependencies);
        for (String s : order) {
            System.out.print(s + " ");
        }
    }
}
