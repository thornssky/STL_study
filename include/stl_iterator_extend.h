#pragma once
#include <iterator>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

using namespace std;

class stl_iterator_extend
{
private:
    vector<int> myvector{1,2,3,4,5,6,7,8,9};
    reverse_iterator<vector<int>::iterator> reIter;
public:
    void stl_iterator_extend_init();
    stl_iterator_extend();
    void stl_iterator_reverse();
    void stl_iterator_insert();
    void stl_iterator_assist();
};

