#include "stl_iterator.h"

stl_iterator::stl_iterator(vector<int> v)
{
    this->v = v;
}

void stl_iterator::no_1_iterator()
{
    cout << "第一种遍历方法：" << endl;
    // size返回元素个数
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " "; //普通数组引用
    }
}

void stl_iterator::no_2_iterator()
{
    cout << endl
         << "第二种遍历方法：" << endl;
    vector<int>::iterator i;
    //用！=比较两个迭代器
    for (i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
}

void stl_iterator::no_3_iterator()
{
    cout << endl
         << "第三种遍历方法：" << endl;
    vector<int>::iterator i;
    //用<比较两个迭代器
    for (i = v.begin(); i < v.end(); ++i)
    {
        cout << *i << " ";
    }
}

void stl_iterator::no_4_iterator()
{
    cout << endl
         << "第四种遍历方法：" << endl;
    vector<int>::iterator i;
    //用！=比较两个迭代器
    i = v.begin();
    while (i < v.end())
    { //间隔一个访问
        cout << *i << " ";
        i += 2;
    }
    cout << endl;
}