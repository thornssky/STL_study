#pragma once
#include <unordered_map>
#include <iostream>

using namespace std;

class stl_unordered_map
{
private:
    //unordered_map 容器模板定义如下
    /*
    template < class Key,                                   //键值对中键的类型
               class T,                                     //键值对中值的类型
               //当无序容器中存储的键值对为自定义类型时，默认的Hash和Pred将不再适用，需要自己进行重新构造
               class Hash = hash<Key>,                      //容器内部存储键值对所用的哈希函数
               class Pred = equal_to<Key>,                  //判断各个键值对键相同的规则
               class Alloc = allocator< pair<const Key,T> > //指定分配器对象类型
               > class unordered_map;   
    */
   unordered_map<string,string> values;
public:
    stl_unordered_map(unordered_map<string,string> values);
    void stl_unordered_map_creat();
    void stl_unordered_map_iterator();
    void stl_unordered_map_visit();
    void stl_unordered_map_insert();
    void stl_unordered_map_emplace();
    void stl_unordered_map_delete();
    void stl_unordered_map_multimap();
};
