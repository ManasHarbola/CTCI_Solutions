import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class Graph {
    private ArrayList<Project> projects = new ArrayList<>();
    private Map<String, Project> map = new HashMap<>();
    public Graph(String[] projects, String[][] dependencies) {
        for (String p : projects) {
            Project proj = new Project(p);
            this.projects.add(proj);
            this.map.put(p, proj);
        }
        for (String[] d : dependencies) {
            Project parent = map.get(d[0]);
            Project child = map.get(d[1]);
            //add dependent to parent node
            parent.getDependents().add(child);
            //add dependent to map
            parent.getMap().put(d[1], child);
            //increment child dependency count
            child.incrementDependencyCount();
        }
    }
    public ArrayList<Project> getProjects() {return projects;}
    public Map<String, Project> getMap() {return map;}
}