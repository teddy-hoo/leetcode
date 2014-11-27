/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
  float calSlope(Point p1, Point p2){
    int x = p1.x - p2.x;
    int y = p1.y - p2.y;

    if(y == 0){
      return INT_MAX;
    }
    else{
      return 1.0 * x / y;
    }
  }
public:
  int maxPoints(vector<Point> &points) {

    map<float, int> slopes;
    int max = 0;

    for(int i = 0; i < points.size(); i++){

      slopes.clear();
      int duplicate = 1;
      int locMax = 0;

      for(int j = i + 1; j < points.size(); j++){

        if(points[i].x == points[j].x && points[i].y == points[j].y){
          duplicate++;
        }
        else{
          int tmp;
          float slope = calSlope(points[i], points[j]);
          if(slopes.find(slope) == slopes.end()){
            slopes[slope] = 1;
            tmp = 1;
          }
          else{
            tmp = ++slopes[slope];
          }
          locMax = locMax > tmp ? locMax : tmp;
        }
      }

      max = max > locMax + duplicate ? max : locMax + duplicate;

    }
    return max;
  }
};
