#pragma once

#include <map>
#include <utility>
#include <iostream>

using namespace std;

class stl_map
{
private:
    //map容器中存储的都是pair对象，且都是pair<const K,T>
    /*
    template < class Key,                                   //指定健（key）的类型
               class T,                                     //指定值（value）的类型
               class Compare = less<Key>,                   //指定排序规则
               class Alloc = allocator<pair<const Key,T> >  //指定分配器对象的类型
               > class map;
    */
    map < string, string>values;
public:
    stl_map(map < string, string>values);
    void stl_map_pair();
    void stl_map_creat();
    void stl_map_iterator();
    void stl_map_traverse();
    void stl_map_insert();
    void stl_map_emplace();
    void stl_map_multimap();
};