//
//  Classes.h
//  BasicC++
//
//  Created by Abhinav Rathod on 5/12/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef Classes_h
#define Classes_h

class Polygon {
protected:
    int width, height;
public:
    Polygon() { cout << "Polygon Constructor" << endl; }
    void set_values (int a, int b)
    { width=a; height=b; }
    virtual ~Polygon() { cout << "Polygon destructor" << endl; }
    virtual int area (void) = 0;
};

class Rectangle: public Polygon {
public:
    Rectangle() { cout << "Rectangle Constructor" << endl; }
    int area (void)
    { return (width * height); }
    ~Rectangle() { cout << "Rectangle destructor" << endl; }
};

class Triangle: public Polygon {
public:
    Triangle() { cout << "Triangle Constructor" << endl; }
    int area (void)
    { return (width * height / 2); }
    ~Triangle() { cout << "Triangle destructor" << endl; }
};

class Square: public Polygon {
public:
    Square() { cout << "Square Constructor" << endl; }
    int area (void)
    { return width * height; }
    ~Square() { cout << "Square destructor" << endl; }
};


class Widget {
public:
    void isProcessDone(){};
    void isDone(){};
private:
    virtual void isProcess1Done() { cout << "Widget IsProcess1Done" << endl; };
    virtual void is1Done(){};
};

class UserUI : public Widget {
    virtual void isProcess1Done() override { cout << "UserUI IsProcess1Done" << endl; };
    virtual void is1Done() override{};
};


void Run() {
    Rectangle rct;
    Triangle tri;
    Square sq;
    
    Polygon *ppoly1 = &rct;
    Polygon *ppoly2 = &tri;
    Polygon *ppoly3 = &sq;
    
    ppoly1->set_values(4, 5);
    ppoly2->set_values(4, 5);
    ppoly3->set_values(4, 4);
    
    cout << "rect area: " << ppoly1->area() << endl;
    cout << "tri area: " << ppoly2->area() << endl;
    cout << "sq area: " << ppoly3->area() << endl;
    
    // virtual destructor needed as Rectangle's destructor will not get called upon delete of Polygon
    Polygon *ppoly4 = new Rectangle();
    ppoly4->set_values(5,5);
    cout << "rect area: " << ppoly4->area() << endl;
    
    delete ppoly4;
}
        
#endif /* Classes_h */
