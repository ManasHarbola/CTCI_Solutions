#include <iostream>
#include <vector>

using namespace std;

class point {
    private:
        int i, j;
    public:
        Point(int r, int c) {i = r; j = c;}
        int getRow() {return i;}
        int getCol() {return j;}
};

vector<point> getPath(bool grid[][]) {
    int c = sizeof(grid[0])/sizeof(bool);
    int r = sizeof(grid)/sizeof(grid[0]);

    vector<point> path;

}

bool pathExists(int r, int c, bool grid[][], vector<point> &path) {

}
