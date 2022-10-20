#include "stl_deque.h"
#include <array>
#include <iostream>
using namespace std;

stl_deque::stl_deque(deque<int> values)
{
    this->deq = values;
}

void stl_deque::stl_deque_createInit()
{
    //创建一个·没有任何元素的空deque容器
    deque<int> d_empty;

    //创建一个具有n个元素的deque容器,初始值为0
    deque<int> d_noinit(10);

    //创建一个具有n个元素的deque容器,初始值为5
    deque<int> d_init(10, 5);

    //拷贝生成新容器
    deque<int> d_copy(d_init); //必须保证与元容器存储的元素类型一致，但是可以是其他容器或数组
}

void stl_deque::stl_deque_iterator()
{
    cout << "stl_deque_iterator" << endl;
    //遍历deque中的每一个元素，可修改，cbegin()只能访问，不可修改
    // rbegin()反向迭代器，从右往左
    for (auto i = this->deq.begin(); i < this->deq.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    //cout << "初始为空的deque容器不可以通过迭代器向容器输入值,容器添加元素操作的时候需要重新生成迭代器" << endl;
    //初始为空的deque容器不可以通过迭代器向容器输入值,容器添加元素操作的时候需要重新生成迭代器
}

void stl_deque::stl_deque_traverse()
{
    cout << "stl_deque_traverse:" << endl;

    cout << "数组形式访问：" << endl;
    cout << this->deq[1] << " ";
    this->deq[1] = 3;
    cout << this->deq[1] << endl;

    cout << "at()形式访问：" << endl;
    cout << this->deq.at(1) << " ";
    this->deq.at(1) = 5;
    cout << this->deq.at(1) << endl;

    cout << "front() back()形式访问：" << endl;
    cout << this->deq.front() << " " << this->deq.back() << " ";
    this->deq.front() = 7;
    this->deq.back() = 9;
    cout << "new value:" << this->deq.front() << " " << this->deq.back() << endl;

    cout << "deque容器存储元素并不在连续的空间内，所以要使用迭代器去访问，而不要使用指针直接去访问" << endl;
    cout << "访问区域内元素：" << endl;
    auto first = this->deq.begin() + 1;
    auto last = this->deq.end() - 1;
    while (first < last)
    {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

void stl_deque::stl_deque_addDelete()
{
    cout << "stl_deque_addDelete:" << endl;
    cout << "元序列：" << endl;
    this->stl_deque_iterator();

    //调用push_back()向容器尾部添加数据
    this->deq.push_back(2);
    cout << "push_back:" << endl;
    this->stl_deque_iterator();
    //调用pop_back()移除容器尾部的一个元素
    this->deq.pop_back();
    cout << "pop_back:" << endl;
    this->stl_deque_iterator();
    //调用push_front()向容器头部添加数据
    this->deq.push_front(2);
    cout << "push_front:" << endl;
    this->stl_deque_iterator();
    //调用pop_front()移除容器头部的一个元素
    this->deq.pop_front();
    cout << "push_front:" << endl;
    this->stl_deque_iterator();

    //调用emplace系列函数，向容器中直接生成数据
    this->deq.emplace_back(20);
    cout << "emplace_back:" << endl;
    this->stl_deque_iterator();
    this->deq.emplace_front(10);
    cout << "emplace_front:" << endl;
    this->stl_deque_iterator();
    // emplace需要两个参数，第一个为指定插入位置的迭代器，第二个是插入的值
    this->deq.emplace(this->deq.begin() + 2, 30);
    cout << "emplace:" << endl;
    this->stl_deque_iterator();

    // erase()可以接受一个迭代器表示要删除元素所在的位置
    //也可以表示要删除元素的区域，输入两个参数
    this->deq.erase(this->deq.begin());
    cout << "erase:" << endl;
    this->stl_deque_iterator();
    this->deq.erase(this->deq.begin() + 1, this->deq.begin() + 4);
    cout << "erase:" << endl;
    this->stl_deque_iterator();

    // insert
    cout << "insert 1:" << endl;
    //插入一个元素在pos前
    this->deq.insert(this->deq.begin() + 1, 3);
    this->stl_deque_iterator();
    cout << "insert 2:" << endl;
    //插入n个相同的元素到pos前
    this->deq.insert(this->deq.end(), 2, 5);
    this->stl_deque_iterator();
    cout << "insert 3:" << endl;
    array<int, 3> test{7, 8, 9};
    //插入其他容器中位于[first,last]区域中的所有元素
    this->deq.insert(this->deq.end(), test.begin(), test.end());
    this->stl_deque_iterator();
    cout << "insert 4:" << endl;
    //插入初始化列表，在pos前
    this->deq.insert(this->deq.end(), {10, 11});
    this->stl_deque_iterator();
    cout << "!!!相比于其它功能函数，emplace系列函数都只用调用构造函数，而没有调用移动构造函数，提高代码效率。" << endl;
}
