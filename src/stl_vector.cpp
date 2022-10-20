#include "stl_vector.h"
#include <iostream>
#include <algorithm>
#include <vector>

stl_vector::stl_vector(vector<double> values)
{
    this->values = values;
}

void stl_vector::stl_vector_createInit()
{
    cout << "stl_vector_createInit:" << endl;
    //创建容器大小为20，默认初始值为0
    vector<double> values_temp(20);

    //创建容器大小为20，默认初始值为1.0，这两个参数都可以使用变量表示
    vector<double> values_temp1(20, 1.0);

    int num = 20;
    double value = 1.0;
    vector<double> values_temp2(num, value);

    //创建的同时制定初始值及元素个数
    vector<double> values_temp3{2, 3, 5, 7, 11, 13, 17, 19};

    //通过其他vector创建新的vector
    vector<double> values_temp4(values_temp3);
    vector<double> values_temp5(values_temp3.begin() + 1, values_temp3.begin() + 5);
}

void stl_vector::stl_vector_iterator()
{
    cout << "stl_vector_iterator:" << endl;
    vector<int> values{1, 2, 3};
    cout << "values 容器的首个元素地址：" << values.data() << endl;
    auto first = values.begin();
    auto last = values.end();
    //增加values的容量
    values.resize(20);
    cout << "values 容器的首个元素地址：" << values.data() << endl;
    first = values.begin();
    last = values.end();
    while (first != last)
    {
        cout << *first;
        ++first;
    }
}

void stl_vector::stl_vector_traverse()
{
    cout << "stl_vector_traverse:" << endl;

    //下标访问
    //获取容器中首个位置元素
    cout << this->values[0] << endl;
    //修改容器中首个位置元素的值
    this->values[0] = this->values[0] + 1;
    cout << this->values[0] << endl;

    // at()访问
    //获取容器中首个位置元素
    cout << this->values.at(0) << endl;
    //修改容器中首个位置元素的值
    this->values.at(0) = this->values.at(0) + 1;
    cout << this->values.at(0) << endl;
    //下面这条语句发生访问越界
    // cout<<this->values.at(50)<<endl;

    // front() back() 返回首元素和最后元素的引用
    cout << "首元素为:" << this->values.front() << endl;
    cout << "尾元素为:" << this->values.back() << endl;
    this->values.front() = 10;
    this->values.back() = 10;
    cout << "新首元素为:" << this->values.front() << endl;
    cout << "新尾元素为:" << this->values.back() << endl;

    // data()返回指向容器的首个元素的指针
    //输出容器中的第三个元素
    cout << *(this->values.data() + 2) << endl;
    *(this->values.data() + 1) = 10;
    cout << *(this->values.data() + 1) << endl;

    //遍历
    for (auto &&value : this->values)
    {
        cout << value << " ";
    }
    cout << endl;

    for (auto first = this->values.begin(); first < this->values.end(); first++)
    {
        cout << *first << " ";
    }
    cout << endl;
}

void stl_vector::stl_vector_pushbackEmplaceback()
{
    // push_back()
    //底层实现繁琐，先创建元素，之后再将元素拷贝或移动到容器中，
    //优先选择调用移动构造函数，没有则调用拷贝构造函数
    values.push_back(1.0);
    values.push_back(2.0);
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;

    // emplace_back()
    //底层实现比较与push_back()要简单，c++11支持
    //直接在容器为不创建这个元素，省去了拷贝和移动过程，只调用构造函数
    values.emplace_back(1.0);
    values.emplace_back(2.0);
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

void stl_vector::stl_vector_insertEmplace()
{
    cout << "stl_vector_insertEmplace:" << endl;
    //这个插入与push_back()和emplace_back()类似的实现原理
    //主要和插入的方式有关，效率上面来说emplace高

    // insert()
    //在迭代器指定位置pos之前插入一个新元素elem，pos，elem
    values.insert(values.begin() + 1, 4);

    //在迭代器指定位置pos之前插入n个相同元素elem
    values.insert(values.end(), 2, 5);

    //在迭代器指定位置pos之前，插入其他容器(不限于vector)中位于[first,last]区域的所有元素
    array<double, 3> test{7, 8, 9};
    values.insert(values.end(), test.begin(), test.end());

    //在迭代器指定位置pos之前，·插入初始化表{elem...}
    values.insert(values.end(), {10, 11});

    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;

    // emplace(),c++11
    //每次只能插入一个元素
    values.emplace(values.begin(), 66);
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
}

void stl_vector::stl_vector_popbackEraseRemoveClear()
{
    cout << "stl_vector_popbackEraseRemoveClear:" << endl;

    cout << "size is :" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;

    // pop_back()
    //删除最后一个元素，大小(size)-1，容量(capacity)不变
    values.pop_back();
    cout << "size is :" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;

    // erase(pos)
    //删除pos位置元素，大小(size)-1，容量(capacity)不变
    auto iter=values.erase(values.begin());
    cout << "size is :" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
    cout<<*iter<<endl;

    // swap(beg)、popback()
    //先交换要删除的元素的位置到最后一个位置，再使用pop_back()删除
    swap(*(values.begin()+1),*(values.end()-1));
    //交换后的容器
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    values.pop_back();
    cout << "size is :" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;

    // erase(beg,end)
    //删除容器中位于[beg,end]区域的元素，大小(size)-1，容量(capacity)不变
    iter=values.erase(values.begin()+1,values.end()-2);
    cout << "size is :" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
    cout<<*iter<<endl;


    // remove()
    //删除容器中所有和指定元素相等的元素，不改变大小和容量
    //这里注意实现原理，经常搭配erase()一起使用
    auto iterRe =std::remove(values.begin(),values.end(),3);
    values.erase(iter,values.end());
    cout << "size is :" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;
    for (int i = 0; i < values.size(); i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;


    // clear()
    //删除容器中所有元素，大小(size)-1，容量(capacity)不变
    values.clear();
    cout << "size is :" << values.size() << endl;
    cout << "capacity is:" << values.capacity() << endl;
}
