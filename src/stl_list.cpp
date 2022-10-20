#include "stl_list.h"
#include <array>
#include <iostream>

using namespace std;

bool demo(int first, int second);

stl_list::stl_list(list<int> li)
{
    this->li = li;
}

void stl_list::stl_list_createInit()
{

    //创建一个空list容器
    list<int> values0;

    //创建一个包含n个元素的list容器,默认值0
    list<int> values1(10);

    //创建一个包含n个元素的list容器,默认值5
    list<int> values2(10, 5);

    //使用列表初始化
    list<int> values6{2,3,5,6,87,9,7};

    //拷贝
    list<int> values3(values2);

    //拷贝其他容器
    array<int, 5> arr{11, 12, 13, 14, 15};
    list<int> values4(arr.begin() + 2, arr.end());
}

void stl_list::stl_list_iterator()
{
    //这里需要注意的是list的迭代器为双向迭代器，而不是随机访问迭代器
    //支持++p1,p1++,p1--,--p1,*p1,p1==p2,p1!=p2
    //不支持p1[i],p1-=i,p1+=i,p1+i,p1-i,<,>,<=,>=等不支持
    //注意插入元素要重新更新迭代器，因为在首尾插入元素会对于旧迭代器的作用域产生影响
    for (auto it = this->li.begin(); it != this->li.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void stl_list::stl_list_traverse()
{
    cout << "stl_list_traverse:" << endl;
    int &first = this->li.front();
    int &last = this->li.back();
    cout << "first: " << first << " "
         << "last:" << last << endl;
    first = 10;
    last = 20;
    cout << "new first: " << first << " "
         << "new last:" << last << endl;

    cout << "遍历：" << endl;
    auto it = this->li.begin();
    while (it != this->li.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void stl_list::stl_list_add()
{
    cout << "stl_list_add:" << endl;

    cout << "元序列：";
    this->stl_list_iterator();

    this->li.push_back(4);
    this->li.push_front(3);
    this->stl_list_iterator();

    this->li.emplace_back(44);
    this->li.emplace_front(33);
    this->stl_list_iterator();

    // emplace(pos,value),其中pos表示指定位置的迭代器，在其之后添加元素
    this->li.emplace(this->li.end(), 6);
    this->stl_list_iterator();

    // insert()
    this->li.insert(this->li.begin(), 3);
    this->stl_list_iterator();

    this->li.insert(this->li.end(), 2, 5);
    this->stl_list_iterator();

    array<int, 3> test{7, 8, 9};
    this->li.insert(this->li.end(), test.begin(), test.end());
    this->stl_list_iterator();

    this->li.insert(this->li.end(), {10, 11});
    this->stl_list_iterator();

    // splice(),作用对象是其他list容器，将其添加到指定位置
    array<int, 3> arr{10, 20, 30};
    list<int> insertList(arr.begin(), arr.end());
    auto it = ++this->li.begin();

    //将insertList中的全部元素移动到li中it的位置上
    this->li.splice(it, insertList);
    this->stl_list_iterator();

    //将it指向的元素移动到insertList的pos处
    insertList.splice(insertList.begin(), this->li, it);
    auto firstIt = insertList.begin();
    while (firstIt != insertList.end())
    {
        cout << *firstIt << " ";
        firstIt++;
    }
    cout << endl;

    //将范围内[ , ]元素移动到pos处
    insertList.splice(insertList.begin(), this->li, ++this->li.begin(), --this->li.end());
    auto firstIt1 = insertList.begin();
    while (firstIt1 != insertList.end())
    {
        cout << *firstIt1 << " ";
        firstIt1++;
    }
    cout << endl;

    cout << "li中元素个数：" << this->li.size() << endl;
    cout << "insertList元素个数：" << insertList.size() << endl;
}

void stl_list::stl_list_delete()
{
    cout << "stl_list_delete:" << endl;

    //删除当前容器中首个元素
    this->li.pop_front();
    this->stl_list_iterator();

    //删除当前容器中最后一个元素
    this->li.pop_back();
    this->stl_list_iterator();

    //清空容器
    this->li.clear();
    this->stl_list_iterator();

    // erase
    array<int, 8> arr3{3, 2, 3, 4, 2, 6, 3, 8};
    list<int> init3(arr3.begin(), arr3.end());
    this->li.splice(this->li.begin(), init3);
    this->stl_list_iterator();

    auto del = this->li.begin();
    ++del;
    this->li.erase(del);
    this->stl_list_iterator();

    auto first = this->li.begin();
    ++first;
    auto last = this->li.end();
    --last;
    this->li.erase(first, last);
    this->stl_list_iterator();

    // remove 删除指定值的元素
    array<int, 8> arr2{3, 2, 3, 4, 2, 6, 3, 8};
    list<int> init2(arr2.begin(), arr2.end());
    this->li.splice(this->li.begin(), init2);
    this->stl_list_iterator();
    this->li.remove(3);
    this->stl_list_iterator();

    // unique() 去除list容器中相邻重复的元素
    array<int, 8> arr1{3, 2, 3, 4, 2, 6, 3, 8};
    list<int> init1(arr1.begin(), arr1.end());
    this->li.splice(this->li.begin(), init1);
    this->stl_list_iterator();

    this->li.unique();
    this->stl_list_iterator();

    this->li.unique(demo);
    this->stl_list_iterator();

    // remove_if()
    array<int, 8> arr{3, 2, 3, 4, 2, 6, 3, 8};
    list<int> init(arr.begin(), arr.end());
    this->li.splice(this->li.begin(), init);
    this->stl_list_iterator();

    this->li.remove_if([](int value)
                       { return (value < 10); });
    this->stl_list_iterator();
}

bool demo(int first, int second)
{
    if (abs(first - second) <= 1)
    {
        return true;
    }
    return false;
}

void stl_list::stl_list_forwardlist()
{
    // forward_list<int> fli;
    // forward_list<int> fli(10);
    // forward_list<int> fli(10,5);
    // forward_list<int> fli1(fli);
    int a[] = {1, 2, 3, 4, 5};
    forward_list<int> values(a, a + 5);
    // array<int,5>arr{1,2,3,4,5};
    // forward_list<int> values(arr.begin()+2,arr.end());

    // before+begin()返回第一个元素之前的位置
    values.emplace_front(4);                        //{4,1,2,3,4,5}
    values.emplace_after(values.before_begin(), 5); //{5,4,1,2,3,4,5}
    values.reverse();                               //{5,4,3,2,1,4,5}

    for (auto it = values.begin(); it != values.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //获取forward_list容器中元素的大小
    int count = distance(begin(values), end(values));
    cout << "values size:" << count << endl;

    // advance()
    auto advanceit = values.begin();
    cout << "begin:" << *advanceit;
    advance(advanceit, 2);
    cout << "advance,2:" << *advanceit;
    advance(advanceit, 2);
    cout << "advance,2,2:" << *advanceit << endl;
}