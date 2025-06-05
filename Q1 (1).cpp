#include <iostream>
using namespace std;

class Vector2D {
private:
    float x, y;

public:
    
    Vector2D(float xVal=0, float yVal=0) {
        x=xVal;
        y=yVal;
    }
    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x+other.x,y+other.y);
    }
    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x-other.x, y-other.y);
    }
    Vector2D operator*(float scalar) {
        return Vector2D(x*scalar, y*scalar);
    }
    void display() {
        cout<<"("<<x<<", "<<y<< ")"<<endl;
    }
};


int main() {
   
    Vector2D v1(1.9,6.8);
    Vector2D v2(7.9,9.11);

    Vector2D sum=v1+v2;
    cout<<"v1 + v2 = ";
    sum.display();

    Vector2D diff=v1-v2;
    cout<<"v1 - v2 = ";
    diff.display();

    Vector2D scaled=v1*2.5;
    cout<<"v1 * 2.5 = ";
    scaled.display();

    return 0;
}

