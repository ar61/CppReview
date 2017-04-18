//
//  Sets.h
//  BasicC++
//
//  Created by Abhinav Rathod on 1/22/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef Sets_h
#define Sets_h

#include <set>

class Test
{
public:
    Test(int x, std::string s){
        age = x;
        name = s;
    }
    
    void print() const{
        std::cout << age << ":" << name << std::endl;
    }
    
    bool operator<(const Test &t) const{
        return age < t.age;
    }
private:
    int age;
    std::string name;
};

void HavingFunWithSets()
{
    std::set<int> f = {4, 5, 5, 3, 3};
    
    
    
    for(auto &i: f)
    {
        //std::cout << i;
    }
    
    std::set<Test> t;
    
    t.insert(Test(29, "Abhi"));
    t.insert(Test(27, "Pari"));
    t.insert(Test(54, "Mom"));
    t.insert(Test(64, "Dad"));
    
    for(auto &i: t)
    {
        i.print();
    }
    
}

#endif /* Sets_h */
