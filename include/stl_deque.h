#pragma once
#include <deque>
//当需要向序列两端频繁的添加或删除元素时应该首选deque容器
using namespace std;

class stl_deque
{
private:
    deque<int> deq;

public:
    stl_deque(deque<int> values);
    void stl_deque_createInit();
    void stl_deque_iterator();
    void stl_deque_traverse();
    void stl_deque_addDelete();
};
