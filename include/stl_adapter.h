#pragma once
#include <stack>
#include <queue>
#include <iostream>
#include <list>
#include <array>

using namespace std;

class stl_adapter
{
private:
    stack<int> stack_values;//默认使用deque
    queue<int> queue_values;//先进先出，默认使用deque
    priority_queue<int> priority_queue_values;//按优先级先出，默认使用vector
public:
    stl_adapter(stack<int> stack_values,queue<int> queue_values,priority_queue<int> priority_queue_values);
    void stl_adapter_creat();
    void stl_adapter_stack();
    void stl_adapter_queue();
    void stl_adapter_priority_queue();

};

