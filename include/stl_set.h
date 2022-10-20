#pragma once

#include <set>
#include <iostream>

using namespace std;

class stl_set
{
private:
    // template < class T,                     //键key和值value 的类型
    //            class Compare = less<T>,     //指定set容器内部的排序规则
    //            class Alloc = allocator<T>   //指定分配器的类型
    //            > class set;
    set<string> values;
public : 
    stl_set(set<string> values);
    void stl_set_creat();
    void stl_set_iterator();
    void stl_set_insert();
    void stl_set_emplace();
    void stl_set_delete();
    void stl_set_multiset();
};
