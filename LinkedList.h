//
//  LinkedList.h
//  BasicC++
//
//  Created by Abhinav Rathod on 3/28/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h


class LinkedListNode{
public:
    int val;
    LinkedListNode *next;
    LinkedListNode(int value){
        val = value;
        next = NULL;
    }
};



#endif /* LinkedList_h */
