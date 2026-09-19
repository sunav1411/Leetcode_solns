class Solution {
public:

    double distance (int x1,int x2,int y1,int y2) {
        return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    }

    bool checkOverlap(int radius, int xC, int yC, int x1, int y1, int x2, int y2) {
        int closestX = max(x1,min(x2,xC));
        int closestY = max(y1,min(y2,yC));
        return pow(closestX-xC,2) + pow(closestY-yC,2) <= radius*radius;
    }
};