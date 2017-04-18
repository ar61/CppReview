//
//  BSTTrees.h
//  BasicC++
//
//  Created by Abhinav Rathod on 4/10/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef BSTTrees_h
#define BSTTrees_h


struct Node
{
    int val;
    Node* l;
    Node* r;
};


Node* CreateBST(int l, int r, std::vector<int> v)
{
    if(l > r){
        return nullptr;
    }
    
    Node* n = new Node;
    int mid = l + (r - l)/2;
    n->val = v[mid];
    n->l = CreateBST(l, mid - 1, v);
    n->r = CreateBST(mid + 1, r, v);
    return n;
}

void PrintBST(Node *n)
{
    if(n == nullptr){
        return;
    }
    
    PrintBST(n->l);
    std::cout << n->val << std::endl;
    PrintBST(n->r);
}

std::unordered_map<int, std::forward_list<int>> GetBTLL(Node *n, int depth){
    if(n == nullptr){
        return std::unordered_map<int, std::forward_list<int>>{};
    }
    
    std::unordered_map<int, std::forward_list<int>> res;
    auto m = GetBTLL(n->l, depth + 1);
    if(m.size() > 0)
    {
        res[depth].push_front(n->val);
    }
    m = GetBTLL(n->r, depth + 1);
    if(m.size() > 0)
    {
        res[depth].push_front(n->val);
    }
    res[depth].push_front(n->val);
    
    return res;
}

void GetBTLL(Node *n, int depth, std::unordered_map<int, std::forward_list<int>>& res){
    if(n == nullptr){
        return;
    }
    
    res[depth].push_front(n->val);
    
    GetBTLL(n->l, depth + 1, res);
    GetBTLL(n->r, depth + 1, res);
}

void Run(){
    
    std::unordered_map<int, std::forward_list<int>> res;
    Node *n = new Node;
    n->val = 4;
    n->l = nullptr;
    n->r = nullptr;
    
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7};
    
    Node *head = CreateBST(0, (int)v.size() - 1, v);
    
    //PrintBST(head);
    
    GetBTLL( head, 0, res);
    
    int i = (int)res.size();
    while(i != -1){
        for(auto &j:res[i]){
            std::cout << j << " ";
        }
        std::cout << std::endl;
        --i;
    }
    
}

#endif /* Trees_h */
