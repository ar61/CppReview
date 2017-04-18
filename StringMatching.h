//
//  StringMatching.h
//  BasicC++
//
//  Created by Abhinav Rathod on 2/4/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef StringMatching_h
#define StringMatching_h

class Problem
{
public:
    static int first_repeated_pos(const char* a, const char* b)
    {
        if(*a == '\0' || *b == '\0')
            return -1;
        
        unordered_map<char, int> map;
        
        int pos = 0, min = -1;
        while(*a != '\0')
        {
            if(map.find(*a) == map.end())
            {
                map[*a] = pos;
            }
            ++a;
            ++pos;
        }
        pos = 0;
        while(*b != '\0')
        {
            if(map.find(*b) != map.end())
            {
                if(map[*b] >= pos){
                    if(pos < min || min == -1)
                        min = pos;
                } else{
                    if(map[*b] < min || min == -1)
                        min = map[*b];
                }
            }
            ++pos;
            ++b;
        }
        
        return min;
    }
};

#endif /* StringMatching_h */
