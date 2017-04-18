//
//  RingIterator.h
//  BasicC++
//
//  Created by Abhinav Rathod on 3/28/17.
//  Copyright © 2017 teest. All rights reserved.
//

#ifndef RingIterator_h
#define RingIterator_h

using std::string;

template <typename T>
class ring{
private:
    int m_size;
    int m_pos;
    T *m_pStr;
public:
    class iterator;
    
    ring(int size): m_pos(0), m_size(size), m_pStr(nullptr){
        m_pStr = new T[size];
    }
    
    ~ring(){
        delete [] m_pStr;
    }
    
    void add(T val){
        m_pStr[m_pos++] = val;
        if(m_pos == m_size){
            m_pos = 0;
        }
    }
    iterator begin(){
        return iterator(0, *this);
    }
    iterator end(){
        return iterator(m_size, *this);
    }
    T &get(int pos){
        return m_pStr[pos];
    }
};

template <typename T>
class ring<T>::iterator{
private:
    int m_pos;
    ring &m_r;
public:
    iterator(int pos, ring &r): m_pos(pos), m_r(r){}
    
    bool operator!=(const iterator &other) const {
        return m_pos != other.m_pos;
    }
    iterator &operator++(){
        ++m_pos;
        return *this;
    }
    iterator &operator++(int){
        ++m_pos;
        return *this;
    }
    T &operator*(){
        return m_r.get(m_pos);
    }
};

#endif /* RingIterator_h */
