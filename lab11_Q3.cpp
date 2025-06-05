#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    int X_Coordinate;
    int Y_Coordinate;

public:
    
    Point() : X_Coordinate(0), Y_Coordinate(0) {}
    Point(int x, int y) : X_Coordinate(x), Y_Coordinate(y) {}    
    Point(const Point &p) : X_Coordinate(p.X_Coordinate), Y_Coordinate(p.Y_Coordinate) {}
    int getX_Coordinate() const {
        return X_Coordinate;
    }

    int getY_Coordinate() const {
        return Y_Coordinate;
    }
    void setX_Coordinate(int x) {
        X_Coordinate = x;
    }
    void setY_Coordinate(int y) {
        Y_Coordinate = y;
    }
    void display() const {
        cout << "(" << X_Coordinate << ", " << Y_Coordinate << ")";
    }
};

class Line {
private:
    Point Point_1;
    Point Point_2;

public:
    
    Line() : Point_1(4, 6), Point_2(2, 4) {}
    Line(int x1, int y1, int x2, int y2) : Point_1(x1, y1), Point_2(x2, y2) {}
    Line(const Point &p1, const Point &p2) : Point_1(p1), Point_2(p2) {}
    float findSlope() {
        int x1=Point_1.getX_Coordinate();
        int y1=Point_1.getY_Coordinate();
        int x2=Point_2.getX_Coordinate();
        int y2=Point_2.getY_Coordinate();

        if (x2-x1==0) {
            throw runtime_error("Slope is undefined (division by zero).");
        }

        return static_cast<float>(y2-y1)/(x2-x1);
    }


    float findLength() {
        int x1=Point_1.getX_Coordinate();
        int y1=Point_1.getY_Coordinate();
        int x2=Point_2.getX_Coordinate();
        int y2=Point_2.getY_Coordinate();

        return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    }
    Point& findMidPoint() {
        int x1=Point_1.getX_Coordinate();
        int y1=Point_1.getY_Coordinate();
        int x2=Point_2.getX_Coordinate();
        int y2=Point_2.getY_Coordinate();

        Point* midPoint=new Point((x1+x2) /2, (y1+y2)/2);
        return *midPoint;
    }
    ~Line() {   
    }
};


int main() {
    Line line(0, 0, 4, 4);

    try {
        cout<<"Slope: "<<line.findSlope()<<endl;
    } catch (runtime_error &e) {
        cout<<e.what()<<endl;
    }

    cout<<"Length: "<<line.findLength()<<endl;

    Point& midpoint=line.findMidPoint();
    cout<<"Midpoint: ";
    midpoint.display();
    cout<<endl;

    
    delete &midpoint;

    return 0;
}
