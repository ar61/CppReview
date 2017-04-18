//
//  ExceptionBasics.hpp
//  BasicC++
//
//  Created by Abhinav Rathod on 1/21/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef ExceptionBasics_h
#define ExceptionBasics_h

#include <stdio.h>

void mightGoWrong(){
    
    bool error1 = false;
    bool error2 = true;
    
    if(error1){
        throw "Something went wrong";
    }
    
    if(error2){
        throw std::string("Something went wrong in string");
    }
}

void BasicException(){
    try{
        mightGoWrong();
    }
    catch(int e){
        std::cout << "error code: " << e << std::endl;
    }
    catch(char const* e){
        std::cout << "error " << e << std::endl;
    }
    catch(std::string &s){
        std::cout << "error " << s << std::endl;
    }
    
    std::cout << "Still Running" << std::endl;
}

#endif /* ExceptionBasics_h */
