//
//  LambdaFunctions.h
//  BasicC++
//
//  Created by Abhinav Rathod on 3/28/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef LambdaFunctions_h
#define LambdaFunctions_h


void test(void (*func)()){
    func();
}

void testName(void (*func)(string)){
    func("Abhi");
}

void divider(double (*func)(double a, double b)){
    auto rval = func(58.0, 5.0);
    cout << rval << endl;
}

void CallLambdas(){
    
    auto func = [](){ cout << "Hola!!" << endl; };
    
    func();
    
    test(func);
    
    test([](){ cout << "Hola Bola!!" << endl; });
    
    
    auto printName = [](string name){ cout << "Hey, " << name << endl; };
    
    printName("Pari");
    
    testName(printName);
    
    auto numDivide = [](double a, double b) -> double {
        if(b == 0.0)
        {
            return 0;
        }
        return a/b;
    };
    
    cout << numDivide(9.0, 2.0) << endl;
    
    divider(numDivide);
}

#endif /* LambdaFunctions_h */
