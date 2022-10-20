#pragma once
#include <unordered_set>
#include <iostream>

using namespace std;

class stl_unordered_set
{
private:

    //容器模板
    /*作用与unordered_map类似，故不做赘诉
    template < class Key,
               class Hash = hash<Key>,
               class Pred = equal_to<key>,
               class Alloc = allocator<key>
               > class unordered_set;
    */
    unordered_set<string>values;
public:
    stl_unordered_set(unordered_set<string>values);
    void stl_unordered_set_creat();
    void stl_unordered_set_show();
    void stl_unordered_set_iterator();
    ~stl_unordered_set();
};

