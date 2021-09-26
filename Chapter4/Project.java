import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

public class Project {
    private String name;
    private int dependencyCount = 0;
    private ArrayList<Project> dependents;
    private Map<String, Project> map;

    public Project(String name) {
        this.name = name;
        dependents = new ArrayList<>();
        map = new HashMap<>();
    }

    public String getName() {return name;}
    public ArrayList<Project> getDependents() {return dependents;}
    public Map<String, Project> getMap() {return map;}

    public void incrementDependencyCount() {dependencyCount++;}
    public void decrementDependencyCount() {dependencyCount--;}
    public int getDependencyCount() {return dependencyCount;}
}