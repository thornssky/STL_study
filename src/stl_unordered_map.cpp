#include "stl_unordered_map.h"

stl_unordered_map::stl_unordered_map(unordered_map<string, string> values)
{
    this->values = values;
}

unordered_map<string, string> retUmap()
{
    unordered_map<string, string> umap1{{"joy1", "man"}, {"mary1", "women"}, {"bob1", "man"}};
    return umap1;
}

void stl_unordered_map::stl_unordered_map_creat()
{
    cout << "stl_unordered_map_creat" << endl;
    unordered_map<string, string> umap;
    unordered_map<string, string> umap1{{"joy", "man"}, {"mary", "women"}, {"bob", "man"}};
    unordered_map<string, string> umap2(umap1);
    unordered_map<string, string> umap3(retUmap());
    unordered_map<string, string> umap4(++umap1.begin(), umap1.end());

    cout << "umap1" << endl;
    for (auto iter = umap1.begin(); iter != umap1.end(); iter++)
    {
        cout << iter->first << " " << iter->second;
    }
    cout << endl;

    cout << "umap2" << endl;
    for (auto iter = umap2.begin(); iter != umap2.end(); iter++)
    {
        cout << iter->first << " " << iter->second;
    }
    cout << endl;

    cout << "umap3" << endl;
    for (auto iter = umap3.begin(); iter != umap3.end(); iter++)
    {
        cout << iter->first << " " << iter->second;
    }
    cout << endl;

    cout << "umap4" << endl;
    for (auto iter = umap4.begin(); iter != umap4.end(); iter++)
    {
        cout << iter->first << " " << iter->second;
    }
    cout << endl;
}

//注意，当对容器添加元素操作时，当负载因子超过最大负载因子（默认最大为1.0）
//这个时候会适当增加桶的数量（通常是1倍），并进行重哈希，所以插入元素后需要重新定义迭代器，之前的迭代器可能会失效
void stl_unordered_map::stl_unordered_map_iterator()
{
    cout << "stl_unordered_map_iterator" << endl;

    for (auto iter = this->values.begin(); iter != this->values.end(); iter++)
    {
        cout << "<" << iter->first << "," << iter->second << ">";
    }
    cout << endl;
}

void stl_unordered_map::stl_unordered_map_visit()
{
    cout << "stl_unordered_map_visit" << endl;

    //在容器unordered_map中实现了对[]重载,当map中没有元素时则改变为向map中插入该元素
    string str = "tom";
    str = this->values[str];
    cout << str << endl;

    // at()功能类似，但是不会向容器中插入元素
    str = this->values.at("bob");
    cout << str << endl;

    // find(),返回的是一个正向迭代器，成功返回该键值对，失败返回.end()位置
    unordered_map<string, string>::iterator iter = this->values.find("mary");
    cout << iter->first << " " << iter->second << endl;
    iter = this->values.find("jack");
    if (iter == this->values.end())
    {
        cout << "当前容器中不存在该键值对" << endl;
    }

    //或者使用.begin(),.end()
}

void stl_unordered_map::stl_unordered_map_insert()
{
    cout << "stl_unordered_map_insert" << endl;
    /*
    //以普通方式传递参数
    pair<iterator,bool> insert(const value_type& val);
    //以右值引用方式传递参数
    template <calss P>
        pair<iterator,bool> insert(P&&val);
    */
    pair<string, string> mypair("jack", "man");
    pair<unordered_map<string, string>::iterator, bool> ret;
    ret = this->values.insert(mypair);
    cout << "bool:" << ret.second << endl;
    cout << "iter->" << ret.first->first << " " << ret.first->second << endl;

    //调用右值引用
    ret = this->values.insert(make_pair("jary", "man"));
    cout << "bool:" << ret.second << endl;
    cout << "iter->" << ret.first->first << " " << ret.first->second << endl;

    /*此外，insert还支持指定新建值对要添加到容器中的位置
    //以普通方式传递参数
    iterator insert(const_iterator hint,const value_type& val);
    //以右值引用方式传递参数
    template <calss P>
        iterator insert(const_iterator hint,P&&val);
    */
    //成功指向新添加的键值对
    //失败指向与其键相同的键值对
    //注意！！！最后决定其位置的还是由hash函数确定
    pair<string, string> mypair1("jack1", "man");
    unordered_map<string, string>::iterator iter;
    iter = this->values.insert(this->values.begin(), mypair);
    cout << "iter ->" << iter->first << " " << iter->second << endl;

    iter = this->values.insert(this->values.begin(), make_pair("jary1", "man"));
    cout << "iter ->" << iter->first << " " << iter->second << endl;

    //将指定区域的所有键值对插入
    /*
    template <class inputIterator>
        void insert(InputIterator first,InputIterator last);
    */
    unordered_map<string, string> umap{{"xiaoli", "women"}, {"xiaohon", "women"}, {"xiaolu", "women"}};
    this->values.insert(umap.begin(), umap.end());
    this->stl_unordered_map_iterator();

    // insert还支持列表添加
    this->values.insert({{"xiaobai", "man"}, {"xiaoqiang", "man"}});
    this->stl_unordered_map_iterator();
}

void stl_unordered_map::stl_unordered_map_emplace()
{ //效率高于insert
    cout << "stl_unorder_map_emplace" << endl;
    /*
    template <class...Args>
        pair<iterator,bool> emplace(Args&&...args);
    */
    //成功返回true，迭代器指向新键值对
    //失败返回false，指向与插入键值相等的键值对
    pair<unordered_map<string, string>::iterator, bool> ret;
    ret = this->values.emplace("xiaohui", "man");
    cout << "bool" << ret.second << endl;
    cout << "iter->" << ret.first->first << " " << ret.first->second << endl;

    // emplace_hint()
    /*
     template <class...Args>
         iterator emplace_hint(const_iterator postion,Args&&...args);
    */
    //传入参数的键值对，与emplace一样，需要注意的是要传入插入位置，返回值为一个迭代器而不是pair变量
    //成功为插入的新建值对，失败则为与插入键值相同的键值对，
    //注意！！！插入的位置和最终的位置还是不同的
    unordered_map<string, string>::iterator iter1;
    iter1 = this->values.emplace_hint(this->values.begin(), "xiaogou", "man");
    cout << "iter->" << iter1->first << " " << iter1->second << endl;
}

void stl_unordered_map::stl_unordered_map_delete()
{
    cout << "stl_unordered_map_delete" << endl;

    // iterator erase(const_iterator position);
    //返回被删除之后位置的迭代器
    this->stl_unordered_map_iterator();
    unordered_map<string, string>::iterator ret;
    ret = this->values.erase(++this->values.begin());
    this->stl_unordered_map_iterator();
    cout << "ret:" << ret->first << " " << ret->second << endl;

    // size_type erase(const key_type&k);
    //返回成功删除的键值对数量
    int delnum = this->values.erase("bob");
    cout << "delnum:" << delnum << endl;
    this->stl_unordered_map_iterator();

    // iterator erase(const_iterator first,const_iterator last)
    //删除范围内的键值对
    //返回被删除的最后一个键值对的后一个位置的键值对
    this->values.erase(++this->values.begin(), this->values.end());
    this->stl_unordered_map_iterator();

    // clear()删除所有元素
    this->values.clear();
    this->stl_unordered_map_iterator();
}

void stl_unordered_map::stl_unordered_map_multimap()
{
    cout << "stl_unordered_map_multimap" << endl;

    //容器模板
    /*
    template < class Key,                                   //键值(key)的类型
               class T,                                     //值(value)的类型
               class Hash = hash<Key>,                      //底层存储值对时采用的哈希函数
               class Pred = equal_to<Key>,                  //判断各个键值对的键相等的规则
               class Alloc = allocator< pair<const Key,T>   //指定分配器对象的类型
               > class unordered_multimap;
    */
    //创建声明unordered_multimap容器模板
    //unordered_multimap<string, string> myummap;//默认构造，未初始化
    //使用列表初始化
    unordered_multimap<string, string> myummap1{{"joy", "man"}, {"mary", "women"}, {"bob", "man"},{"joy", "woman"}, {"mary", "man"}};
    //unordered_multimap<string, string> myummap2(umap1);//拷贝构造
    //unordered_multimap<string, string> myummap3(retUmap());//移动构造函数
    //unordered_multimap<string, string> myummap4(++umap1.begin(), umap1.end());//区域拷贝构造


    //没有提供[]和at()，因为每个键可能对应多个键值
    //插入
    myummap1.emplace("roise","women");
    //size()
    cout << "myummap size:" << myummap1.size() << endl;
    //遍历
    for(auto iter = myummap1.begin();iter != myummap1.end();iter++){
        cout << iter->first << " " << iter->second;
    }
    cout << endl;
    //count(),给出对应键值的键值对个数
    cout << "joy count:" << myummap1.count("joy") << endl;
    //equl_range(),返回对应键值的范围，用一个pair对象接收的迭代器
    pair<unordered_multimap<string,string>::iterator,unordered_multimap<string,string>::iterator> ret;
    ret = myummap1.equal_range("mary");
    for(auto iter = ret.first;iter != ret.second;iter++){
        cout << iter->first <<  " " << iter->second;
    }
    cout << endl;

}