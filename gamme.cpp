#include<iostream>
#include<cstdlib> 
#include<ctime>   

using namespace std;
const int N=30; // Width
const int M=20; // Height
const int MAX_SNAKE_LENGTH=100;

int dir,num=3;
bool gameOver=false;

class Snake { 
    private:
    int x, y; 
    public:
    int getX() 
    {return x;}
    int getY() 
    {return y;}
    void setX(int newX) 
    {x=newX;}
    void setY(int newY) 
    {y=newY;}
} ;
class Food:public Snake { 
    private:
     int x1, y1; 
     public:
     int getX1() 
     { return x1; }
     int getY1() 
     { return y1; }
     void setX1(int newX1)
      {x1=newX1;}
     void setY1(int newY1) 
     {y1=newY1;}
};

void Setup(Snake* s, Food* f) {
    srand(time(0));
    
    
    for (int i=0; i<num; i++) {
        s[i].setX(10-i);
        s[i].setY(10);
    }
    
    f->setX1(rand()%N);
    f->setY1(rand()%M);
    
    dir=2; // Start moving right
}

void Draw(Snake* s, Food* f) {
    
    
        system("cls");
   
    for (int i=0; i<N+2; i++) 
    cout<<"#";
    cout<<endl;
    
    for (int y=0; y<M; y++) {
        cout<<"#"; 
        
        for (int x=0; x<N; x++) {
            bool isSnake=false;
            bool isHead=(x==s[0].getX()&&y==s[0].getY());
            
            for (int i=0; i<num; i++) {
                if (s[i].getX()==x&&s[i].getY()==y) {
                    isSnake=true;
                    break;
                }
            }

            if (isHead)
         cout<<"O";
            else if (isSnake) 
            cout<<"o";
            else if 
            (x==f->getX1() && y == f->getY1()) cout<<"F";
            else 
            cout<< " ";
        }
        
        cout<<"#"<<endl; 
    }
    
  for (int i=0; i<N+2; i++) 
  cout<<"#";
    cout<<endl<<"Score: "<<num-3<<endl;
    cout<<"Controls: WASD to move, X to quit"<<endl;
}

void Input(Snake* s, Food* f) {
    
    char input;
    if (cin.peek()!=EOF) {
        cin>>input;
        cin.ignore(100, '\n'); 
        switch (tolower(input)) {
            case 'a': 
            if (dir!=2) dir = 1; 
            break;
            case 'd':
             if (dir != 1) dir = 2; 
            break;
            case 'w': 
            if (dir!=0) dir=3; 
            break;
            case 's':
             if (dir!=3) dir=0; 
            break;
            case 'x': 
            gameOver=true; 
            break;
        }
    }
}

void Logic(Snake* s, Food* f) {
   
    for (int i=num; i>0; i--) {
        s[i]=s[i-1];
    }
    
    
    switch (dir) {
        case 0:
         s[0].setY(s[0].getY()+1); 
        break; 
        case 1:
         s[0].setX(s[0].getX()-1); 
        break; 
        case 2: 
        s[0].setX(s[0].getX()+1);
         break; 
        case 3: 
        s[0].setY(s[0].getY()-1); 
        break; 
    }
    
    
    if (s[0].getX()==f->getX1() && s[0].getY()==f->getY1()) {
        num++;
        f->setX1(rand()%N);
        f->setY1(rand()%M);
    }
    

    if (s[0].getX()>=N) s[0].setX(0);
    else if (s[0].getX()<0) s[0].setX(N-1);
    if (s[0].getY()>=M) s[0].setY(0);
    else if (s[0].getY()<0) s[0].setY(M-1);
    
    
    for (int i=1; i<num; i++) {
        if (s[0].getX()==s[i].getX()&&s[0].getY()==s[i].getY()) {
            num=i;
            break;
        }
    }
}

int main() {

    Snake* s=new Snake[MAX_SNAKE_LENGTH];
    Food *f=new Food;
    Setup(s,f);
    
    while (!gameOver) {
        Draw(s,f);
        Input(s,f);
        Logic(s,f);
        
       
        
    }
    
    cout<<"Game Over! Final Score: "<<num-3<<endl;

    delete[] s; 
    delete f;
    return 0;
}