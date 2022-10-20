#include "stl_iterator_extend.h"

stl_iterator_extend::stl_iterator_extend(){
    cout << "构造函数" << endl;
}

void stl_iterator_extend::stl_iterator_extend_init()
{
    this->reIter = this->myvector.rbegin(); //指向最后一个元素
}

void stl_iterator_extend::stl_iterator_reverse()
{
    cout << "stl_iterator_reverse" << endl;

    cout << "最后一个元素(*this->reIter):" << *this->reIter << endl;
    cout << "倒数第四个元素(*(this->reIter+3)):" << *(this->reIter + 3) << endl;
    cout << "*(++this->reIter):" << *(++this->reIter) << endl;
    cout << "this->reIter[4]:" << this->reIter[4] << endl;

    //指向第一个元素之前的位置
    reverse_iterator<vector<int>::iterator> begin(myvector.begin());
    //指向最后一个元素的位置
    reverse_iterator<vector<int>::iterator> end(myvector.end());

    // base()返回iu底层对应的迭代器
    for (auto iter = begin.base(); iter != end.base(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void stl_iterator_extend::stl_iterator_insert()
{
    cout << "stl_iterator_insert" << endl;
    vector<int> ve;
    back_insert_iterator<vector<int>> back_it(ve);
    back_it = 5;
    back_it = 4;
    back_it = 3;
    back_it = 2;
    back_it = 1; //都是插入到末尾
    for (auto it = ve.begin(); it != ve.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    forward_list<int> foo;
    front_insert_iterator<forward_list<int>> front_it = front_inserter(foo);
    front_it = 5;
    front_it = 4;
    front_it = 3;
    front_it = 2;
    front_it = 1; //头部插入
    for (auto it = foo.begin(); it != foo.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    list<int> li(2, 5);
    list<int>::iterator insertit = ++li.begin(); //指定位置
    insert_iterator<list<int>> insert_it = inserter(li, insertit);
    insert_it = 1;
    insert_it = 2;
    insert_it = 3;
    for (auto it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void stl_iterator_extend::stl_iterator_assist(){
    cout << "stl_iterator_assist" << endl;
    forward_list<int> mylist{1,2,3,4};
    forward_list<int>::iterator it = mylist.begin();

    advance(it,2);//将it迭代器前进两个位置
    cout << "*it:" << *it << endl;
    //it = mylist.end();//这个是forward_list容器所以不可以后退，后退报错
    vector<int> myvector{1,2,3,4};
    auto it1 = myvector.end();
    advance(it1,-3);//后退一个位置
    cout << "*it1:" << *it << endl;

    //distance(first,last),计算last到first的位置距离
    cout << "distance():" << distance(it1,myvector.end()) << endl;

    //prev,next
    auto newit = prev(it1,1);//获得一个在it左边的第一个元素
    cout << "prev(it1,1):" << *newit << endl;
    auto newit1 = next(it1,1);//获得一个在it右边第一个元素
    cout << "next(it1,1)" << *newit1 << endl;

}