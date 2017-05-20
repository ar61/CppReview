//
//  BTrees.h
//  BasicC++
//
//  Created by Abhinav Rathod on 5/10/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef BTrees_h
#define BTrees_h

struct node
{
    int val;
    node* left;
    node* right;
    node(){ val = -1; left = nullptr; right = nullptr;}
};

void CreateBinaryTree(node **h, std::vector<std::pair<int, std::vector<int>>> v);
void PrintTree(node* h);
int getLargestDistinctPath(node *n);
void PrintAllPaths(node *n);
void DoubleTree(node **n);
int MaxWidthOfTree(node *n);

void CreateBinaryTree(node **h, std::vector<std::pair<int, std::vector<int>>> v)
{
    std::queue<node*> q;
    
    node *n = *h;
    auto p = v.begin();
    n->val = p->first;
    ++p;
    
    q.push(n);
    bool isl = true;
    
    while(!q.empty() && v.size() > 0){
        node *s = q.front();
        q.pop();
        isl = true;
        
        p = std::find_if(v.begin(), v.end(), [s](std::pair<int, std::vector<int>> it){
            return s->val == it.first;
        });
        
        if(p != v.end()){
            for(auto &i:p->second){
                node *t = new node;
                t->val = i;
                if(isl){
                    s->left = t;
                } else {
                    s->right = t;
                }
                isl = !isl;
                q.push(t);
            }
            v.erase(p);
        }
    }
}

void PrintTree(node* h)
{
    if(h == nullptr){
        return;
    }
    PrintTree(h->left);
    PrintTree(h->right);
    if(h->left == NULL && h->right == NULL)
        std::cout << " leaf " << h->val << std::endl;
    else
        std::cout << " parent " << h->val << " ";
}

std::unordered_map<int, int> check;


int getLargestDistinctPath(node *n)
{
    if(n == nullptr){
        return 0;
    }
    if(check.find(n->val) != check.end()){
        check[n->val] += 1;
        return -99;
    } else {
        check[n->val] = 1;
    }
    int l = getLargestDistinctPath(n->left);
    int r = getLargestDistinctPath(n->right);
    
    if(l < 0)
        return 0;
    else if(r < 0)
        return 0;
    std::cout << "node: " << n->val << " ";
    if(n->left != NULL){
        std::cout << "l: " << n->left->val << " ";
    }
    if(n->right != NULL){
        std::cout << "r: " << n->right->val << " ";
    }
    std::cout << std::endl;
    return 1 + std::max(l, r);
    
}

std::vector<int> printlist;
void PrintAllPaths(node *n)
{
    if(n == NULL){
        return;
    }
    // reach a leaf and print the list
    if(n->left == NULL && n->right == NULL){
        for(auto &i:printlist){
            std::cout << i << " -> ";
        }
        std::cout << n->val << std::endl;
        return;
    }
    printlist.push_back(n->val);
    PrintAllPaths(n->left);
    PrintAllPaths(n->right);
    printlist.erase(printlist.end() - 1);
}

void DoubleTree(node **n)
{
    auto t = *n;
    if(t == NULL){
        return;
    }
    // create duplicate node
    node *p = new node;
    p->val = t->val;
    
    if(t->left == NULL && t->right == NULL){
        t->left = p;
    } else {
        node *temp = t->left;
        t->left = p;
        p->left = temp;
    }
    
    DoubleTree(&(p->left));
    DoubleTree(&(t->right));
}

static std::vector<std::pair<int, int>> depthVec;

int MaxWidthOfTree(node *n)
{
    if(n == NULL){
        return 0;
    }
    
    int l = MaxWidthOfTree(n->left) + 1;
    int r = MaxWidthOfTree(n->right) + 1;
    
    if( count_if(depthVec.begin(), depthVec.end(), [=](pair<int, int> s){
        return s.first == l;
    }) ){
        
    }
    
    return 0;
}

void Run()
{
    node* n = new node;
    
    CreateBinaryTree(&n, { {4, {3, 1}}, {3, {5}}, {1, {6, 4}}, {5, {2}} , {2, {51}} } );
    
    
    node* n2 = new node;
    
    CreateBinaryTree(&n2, { {4, {3, 1}}, {3, {5, 3}}, {1, {6, 4}}, {5, {2, 9}} , {2, {5, 7}}, {4, {2, 12}} }  );
    
    //PrintTree(n);
    
    //PrintTree(n2);
    std::cout << std::endl;
    
    // Solve problems
    
    // Find the largest distinct depth till leaf node from root in Binary Tree
    
    /*
          4
         / \
        3   1
       /    /\
       5    6  4
      /
      2
     /
     5
     
     answer here: 4-1-6 = Length 3
     */
    
    //std::cout << "Largest distinct path length: " << getLargestDistinctPath(n2) << std::endl;
    
    // print all paths
    //PrintAllPaths(n2);
    
    // double the tree
    /*
        2
      /  \
     1    3
     
     to:
     
          2
         / \
        2   3
       /   /
       1   3
      /
     1
     
     &&
     
     And the tree
     
          1
        /   \
       2     3
      /  \
     4    5
     is changed to
     
               1
             /   \
            1     3
           /     /
          2     3
         /  \
        2    5
       /    /
      4    5
     /
     4
     
     */
    
    node *n3 = new node;
    
    CreateBinaryTree(&n3, { {2,{1,3}} });
    //CreateBinaryTree(&n3, { {1,{2,3}}, {2,{4,5}} });
    
    //DoubleTree(&n3);
    
    //PrintTree(n3);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    
    // max width of binary tree
    
    std::cout << "Max Width of Tree : " << MaxWidthOfTree(n3) << std::endl;
    
    // Merge two tree by root, by position
}

#endif /* BTrees_h */
