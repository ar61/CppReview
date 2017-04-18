//
//  InitializerLists.h
//  BasicC++
//
//  Created by Abhinav Rathod on 3/28/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef InitializerLists_h
#define InitializerLists_h

template <typename T>
class initList{
public:
    initList(initializer_list<T> list){
        for(auto &item:list){
            cout << item << endl;
        }
    }
    void print(initializer_list<T> list){
        for(auto &item:list){
            cout << item << endl;
        }
    }
};

void callingInitializerLists(){
    initList<string> il = initList<string>{"a", "b", "c"};
    
    il.print({"d" , "e"});
}

#endif /* InitializerLists_h */
