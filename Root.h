//
//  Root.h
//  BasicC++
//
//  Created by Abhinav Rathod on 2/4/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef Root_h
#define Root_h

#include <sstream>
#include <vector>

//Path path("/a/b/c/d");
//std::cout << path.cd("../x").getPath();
//std::cout << path.cd("/foo").getPath();
//std::cout << path.cd("x").getPath(); // works
//std::cout << path.cd("../ ../r/ ../x").getPath();
using namespace std;

class Path
{
public:
    Path(std::string path)
    {
        currentPath = path;
    }
    
    std::string getPath() const
    {
        return currentPath;
    }
    
    Path cd(std::string newPath) const
    {
        stringstream path;
        // split the currentPath into different paths
        vector<string> folders = split(currentPath, '/');
        vector<string> newfolders = split(newPath, '/');
        int count = (int)folders.size();
        // single folder path
        if(newfolders.size() == 1)
        {
            for(int i = 0; i < folders.size() - 1; ++i)
            {
                path << "/"  << folders[i];
            }
            path << "/" << newPath;
            
        } else if(newfolders.size() == 2 && newfolders[0].empty()){ // single folder like "/foo"
            
            path << newPath;
            
        } else {
            
            // go up to parent feature
            // coutn points to present working folder
            for(int i = 0 ; i < newfolders.size(); ++i){
                
                if(newfolders[i] == ".." || newfolders[i] == " .."){
                    --count;
                    folders[count] = "";
                } else {
                    folders[count] = newfolders[i];
                    ++count;
                }
            }
            
            for(int i = 0; i < folders.size() - 1; ++i)
            {
                if(folders[i] != "")
                    path << "/" << folders[i];
            }
        }
        
        return path.str();
    }
private:
    vector<string> split(string s, char delimiter) const
    {
        vector<string> retstr;
        stringstream ss;
        ss.str(s);
        string item;
        while(getline(ss, item, delimiter)){
            retstr.push_back(item);
        }
        return retstr;
    }
    
private:
    std::string currentPath;
};

#endif /* Root_h */
