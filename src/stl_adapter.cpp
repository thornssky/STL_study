#include "stl_adapter.h"

stl_adapter::stl_adapter(stack<int> stack_values, queue<int> queue_values, priority_queue<int> priority_queue_values)
{
    this->priority_queue_values = priority_queue_values;
    this->queue_values = queue_values;
    this->stack_values = stack_values;
}

void stl_adapter::stl_adapter_creat()
{
    cout << "stl_adapter_creat" << endl;

    // stack，不可以直接使用列表初始化
    stack<string> svalues;                //使用deque
    stack<string, list<string>> ssvalues; //使用list
    list<int> lvalues{1, 2, 3};
    stack<int, list<int>> lsvalues(lvalues);  //使用基础容器初始化stack容器
    stack<int, list<int>> svalues1(lsvalues); //拷贝初始化

    // queue
    queue<int> qvalues;
    queue<int, list<int>> lqvalues;
    deque<int> devalues{1, 2, 3};
    queue<int> dqvalues(devalues);
    queue<int> dqvalues1(dqvalues);

    // priority_queue
    priority_queue<int> pqvalues;
    int values[]{4, 1, 3, 2};
    priority_queue<int> apqvalues(values, values + 4); //{4,2,3,1}
    array<int, 4> values1{4, 1, 3, 2};
    priority_queue<int> sapqvalues(values1.begin(), values1.end()); //{4,2,3,1}
    priority_queue<int, deque<int>, greater<int>> gdpqvalues(values1.begin(), values1.end());
}

void stl_adapter::stl_adapter_stack()
{
    cout << "stl_adapter_stack" << endl;

    //查看元素个数
    cout << "size of stack:" << this->stack_values.size() << endl;

    //判断是否为空，没有元素返回true
    if (this->stack_values.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
        cout << "stack is not empty" << endl;

    //返回栈顶元素
    cout << "stack top:" << this->stack_values.top() << endl;

    //入栈，push(const T&val)先复制，再压栈，push(T&&obj)移动压栈，emplace()在栈顶直接生成，效率高
    this->stack_values.push(9);
    this->stack_values.emplace(10);

    // pop出栈
    cout << "stack top:" << this->stack_values.top() << endl;
    this->stack_values.pop();

    //遍历
    while (!this->stack_values.empty())
    {
        cout << this->stack_values.top() << " ";
        this->stack_values.pop();
    }
    cout << endl;
}

void stl_adapter::stl_adapter_queue()
{
    cout << "stl_adapter_queue" << endl;

    // empty,没有元素返回true
    if (this->queue_values.empty())
    {
        cout << "queue is empty" << endl;
    }
    else
        cout << "queue is not empty" << endl;

    // size()
    cout << "size of queue:" << this->queue_values.size() << endl;

    //返回queue中的第一个元素front(),最后一个元素back()
    cout << "queue front:" << this->queue_values.front() << endl;
    cout << "queue back:" << this->queue_values.back() << endl;

    //入队，push(const T&obj)复制，push(T&&obj)移动，emplace()在栈顶直接生成，效率高
    this->queue_values.push(4);
    this->queue_values.emplace(6);

    // pop删除第一个元素
    cout << "queue top:" << this->queue_values.front() << endl;
    this->queue_values.pop();

    //遍历
    while (!this->queue_values.empty())
    {
        cout << this->queue_values.front() << " ";
        this->queue_values.pop();
    }
    cout << endl;
}

void stl_adapter::stl_adapter_priority_queue()
{
    cout << "stl_adapter_priority_queue" << endl;

    // empty,没有元素返回true
    if (this->priority_queue_values.empty())
    {
        cout << "priority queue is empty" << endl;
    }
    else
        cout << "priority queue is not empty" << endl;

    // size()
    cout << "size of queue:" << this->priority_queue_values.size() << endl;

    //返回priority_queue中优先级的第一个元素top()
    cout << "priority queue top:" << this->priority_queue_values.top() << endl;

    //入队，push(const T&obj)复制，push(T&&obj)移动，emplace()在栈顶直接生成，效率高
    this->priority_queue_values.push(5);
    this->priority_queue_values.emplace(7);

    // pop删除第一个元素
    cout << "priority queue top:" << this->priority_queue_values.top() << endl;
    this->priority_queue_values.pop();

    //遍历
    while (!this->priority_queue_values.empty())
    {
        cout << this->priority_queue_values.top() << " ";
        this->priority_queue_values.pop();
    }
    cout << endl;
}