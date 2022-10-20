#include "stl_set.h"

stl_set::stl_set(set<string> values)
{
    cout << "construct!" << endl;
    this->values = values;
}

set<string> retSet()
{
    set<string> myset{"may", "june", "july", "august"};
    return myset;
}

void stl_set::stl_set_creat()
{
    cout << "stl_set_creat:" << endl;

    set<string> myset1;
    set<string> myset2{"january", "february", "march", "april"};
    set<string> myset3(myset2);   //拷贝构造函数
    set<string> myset4(retSet()); //移动构造函数
    set<string> myset5(++myset2.begin(), myset2.end());
    set<string, greater<string>> myset6{"september", "october", "november", "december"};

    for (auto iter = myset1.begin(); iter != myset1.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = myset2.begin(); iter != myset2.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = myset3.begin(); iter != myset3.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = myset4.begin(); iter != myset4.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = myset5.begin(); iter != myset5.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    for (auto iter = myset6.begin(); iter != myset6.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void stl_set::stl_set_iterator()
{
    cout << "stl_set_iterator:" << endl;

    // set未提供at(),也没有重载[],访问的方法只有迭代器（双向迭代器）
    //且迭代器去访问的时候不可以直接去修改容器中的值

    for (auto iter = this->values.begin(); iter != this->values.end(); ++iter)
    {
        cout << *iter;
    }
    cout << endl;
}

void stl_set::stl_set_insert()
{
    cout << "stl_set_insert:" << endl;

    /*
        //普通引用方式传参 pair <iterator,bool> insert(const value_type& val);
        //右值引用方式传参 pair <iterator,bool> insert(value_type&& val);
        返回值为pair类型
    */
    pair<set<string>::iterator, bool> ret;
    //采用普通引用传参
    string str = "may2";
    ret = this->values.insert(str);
    cout << "iter->" << *(ret.first) << " "
         << "bool = " << ret.second << endl;

    //采用右值引用传参
    ret = this->values.insert("july2");
    cout << "iter->" << *(ret.first) << " "
         << "bool = " << ret.second << endl;

    //将指定元素插入到指定位置，返回值为迭代器，指向新添加元素
    //注意！！！插入位置并不一定是最后位置，容器还会对其排序
    str = "june2";
    set<string>::iterator iter;
    //普通引用
    iter = this->values.insert(this->values.begin(), str);
    cout << "values size:" << this->values.size() << endl;

    //右值引用
    iter = this->values.insert(this->values.begin(), "thorns");
    cout << "values size:" << this->values.size() << endl;

    //插入其他容器区域内的元素，返回值为空
    set<string> otherset;
    otherset.insert(++this->values.begin(), this->values.end());
    for (auto iter1 = otherset.begin(); iter1 != otherset.end(); ++iter1)
    {
        cout << *iter1 << " ";
    }
    cout << endl;

    //出入元素列表，返回值为空
    this->values.insert({"one", "two", "three"});
    for (auto iter1 = this->values.begin(); iter1 != this->values.end(); ++iter1)
    {
        cout << *iter1 << " ";
    }
    cout << endl;
}

void stl_set::stl_set_emplace()
{ //效率比insert高
    cout << "stl_emplace:" << endl;

    /*
        template <class...Args>
        pair<iterator,bool> emplace(Args&&...args);
        这里的参数如果是结构体或者类，传入的是构建对象需要的数据
    */

    pair<set<string, string>::iterator, bool> ret = this->values.emplace("four");
    cout << "values:" << this->values.size() << endl;
    cout << "ret.iter=<" << *(ret.first) << "," << ret.second << ">" << endl;

    /*  emplace_hint()方法的功能和emplace()类似，其语法格式如下：
        template <class...Args>
        iterator emplace_hint(const_iterator position,Args&&...args);
        这里的参数需要额外传入一个迭代器，指向插入的位置插入指向元素的前一个位置，返回值为迭代器。
    */

    set<string>::iterator iter = this->values.emplace_hint(this->values.begin(), "five");
    cout << "values size :" << this->values.size() << endl;
    cout << *iter << endl;
}

void stl_set::stl_set_delete()
{
    cout << "stl_set_delete" << endl;
    /*
        //删除set容器中值为val的元素
        size_type erase(const value_type& val);
        //删除position迭代器指向的元素
        iterator erase(const_iterator position);
        //删除[first,last]区间内的所有元素
        iterator erase(const_iterator first,const_iterator last);
    */

    int num = this->values.erase("one");
    cout << "1、values size:" << this->values.size() << endl;
    cout << "num:" << num << endl;

    set<string>::iterator iter = this->values.erase(this->values.begin());
    cout << "2、values size:" << this->values.size() << endl;
    cout << "iter->:" << *iter << endl;

    set<string>::iterator iter1 = this->values.erase(this->values.begin(), ++this->values.begin());
    cout << "3、values size:" << this->values.size() << endl;
    cout << "iter1:" << *iter1 << endl;

    // clear()删除容器中的所有元素
    this->values.clear();
    cout << "4、values size:" << this->values.size() << endl;
}

multiset<string> retmultiset()
{
    multiset<string> tempmultiset{"q10", "q21"};
    return tempmultiset;
}

void stl_set::stl_set_multiset()
{
    cout << "stl_set_multiset:" << endl;
    // multiset容器模板如下
    /*
    template< class T,                      //存储元素的类型
              class Compare = less<T>,      //指定容器内部的排序规则
              class Alloc = allocator<T> >  //指定分配器对象的类型
              > class multiset;
    */
    //初始化创建容器
    multiset<string> mymultiset_default;                             //默认构造
    multiset<string> mymultiset{"ab", "cd", "ab", "cd", "ef", "gh"}; //列表初始化构造
    multiset<string> copymultiset(mymultiset);                       //拷贝构造
    multiset<string> movemultiset(retmultiset());                    //移动构造
    multiset<string> areacopymultiset(mymultiset.begin(), --mymultiset.end());

    cout << "mymultiset size:" << mymultiset.size() << endl;
    for (auto iter = mymultiset.begin(); iter != mymultiset.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    string a = "cd";
    cout << "mymultiset.count(cd):" << mymultiset.count("cd");

    mymultiset.insert("asd0");

    int num = mymultiset.erase("ab");

    cout << "删除了" << num << "个元素ab" << endl;
    for (auto iter = mymultiset.begin(); iter != mymultiset.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}