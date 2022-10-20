#include "stl_map.h"

stl_map::stl_map(map<string, string> values)
{
    this->values = values;
}

void stl_map::stl_map_pair()
{

    cout << "stl_map_pair:" << endl;

    //调用构造函数1，默认构造函数
    pair<string, double> pair1;

    //调用构造函数2
    pair<string, string> pair2("江西", "南昌");

    //调用构造函数3，拷贝构造函数
    pair<string, string> pair3(pair2);

    //调用构造函数4，移动构造函数
    pair<string, string> pair4(make_pair("广东", "广州"));

    //调用构造函数5，右值引用参数构造
    pair<string, string> pair5(string("北京"), string("北京"));

    cout << "pair1:" << pair1.first << " " << pair1.second << endl;
    cout << "pair2:" << pair2.first << " " << pair2.second << endl;
    cout << "pair3:" << pair3.first << " " << pair3.second << endl;
    cout << "pair4:" << pair4.first << " " << pair4.second << endl;
    cout << "pair5:" << pair5.first << " " << pair5.second << endl;

    cout << "pair重载了>,<,<=,>=,==,!=这6个运算符，比较两个pair对象，";
    cout << "先比较first，相等则比较second，注意同类型才可以比较" << endl;

    // swap(),pair类模板还提供了swap()函数，用于交换两个pair对象的键值对
    pair4.swap(pair5);
    cout << "pair4:" << pair4.first << " " << pair4.second << endl;
    cout << "pair5:" << pair5.first << " " << pair5.second << endl;
}

map<string, int> disMap()
{
    map<string, int> tempMap{{"tony", 78}, {"tom", 99}};
    return tempMap;
}

void stl_map::stl_map_creat()
{
    cout << "stl_map_creat:" << endl;

    //默认构造函数
    map<string, int> myMap;

    //创建map容器的同时，使用列表进行初始化
    map<string, int> myMap2{{"tony", 78}, {"tom", 99}}; //也可以用make_pair()进行创建

    //拷贝构造函数
    map<string, int> myMap3(myMap2);

    //移动构造函数
    map<string, int> myMap4(disMap());

    //取已建容器中指定的区域中的键值对
    map<string, int> myMap5(++myMap4.begin(), myMap4.end());

    //指定map容器中的排序规制，默认为升序排列
    map<string, int> myMap6{{"tony", 78}, {"tom", 99}};
    map<string, int, greater<string>> myMap7{{"tony", 78}, {"tom", 99}};
}

void stl_map::stl_map_iterator() //双向迭代器
{
    cout << "stl_map_iterator:" << endl;

    //遍历
    for (auto iter = this->values.begin(); iter != this->values.end(); ++iter)
    {
        cout << iter->first << " " << endl;
    }

    // find(),返回值为迭代器
    cout << "find()" << this->values.find("江西")->first
         << " " << this->values.find("江西")->second << endl;

    // lower_bound(key)和upper_bound(key)更多的用于mulltimap
    // equal_range也是更多的用于mulltimap
}

void stl_map::stl_map_traverse()
{
    cout << "stl_map_traverse:" << endl;

    // map重载了[]去访问map中的值，若是不存在，则插入值为0的新键值对
    string cValue = this->values["江西"];
    cout << cValue << endl;
    string cValue1 = this->values["湖北"];
    cout << this->values.find("湖北")->first << " " << this->values.find("湖北")->second << endl;

    //可以通过[]添加键值对，但是必须保证，新建值在map未出现
    for (auto i = this->values.begin(); i != this->values.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }
    this->values["福建"] = "厦门";
    this->values["湖北"] = "武汉";
    for (auto i = this->values.begin(); i != this->values.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    // at(),类似[]，但是没有插入新建值的作用
    cout << this->values.at("江西") << endl;

    // find(),返回的是一个迭代器，可以访问对应的键值对
}

void stl_map::stl_map_insert()
{
    //[]用法
    //获取已存键值对中，指定键对应的值
    cout << this->values["江西"] << endl;
    //添加新的键值对
    this->values["湖南"] = "长沙";
    //修改map容器中的值
    this->values["福建"] = "福州";
    for (auto i = this->values.begin(); i != this->values.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    // inert()
    pair<string, string> mapInsert = {"云南", "贵州"};
    //用于接受insert的返回值
    pair<map<string, string>::iterator, bool> ret;
    ret = this->values.insert(mapInsert);
    cout << "ret.iter=<{" << ret.first->first << "," << ret.first->second << "}," << ret.second << ">" << endl;

    //以右值引用方式传递临时的键值对变量
    ret = this->values.insert({"云南", "贵州"});
    cout << "ret.iter=<{" << ret.first->first << "," << ret.first->second << "}," << ret.second << ">" << endl;

    // insert()，向指定的位置插入值
    pair<string, string> mapInsert1 = {"广西", "南宁"};
    map<string, string>::iterator itPos = this->values.begin();
    auto iter1 = this->values.insert(itPos, mapInsert1);
    cout << iter1->first << " " << iter1->second << endl;

    //以右值引用的方式插入临时键值对
    auto iter2 = this->values.insert(itPos, pair<string, string>("山西", "太原"));
    cout << iter1->first << " " << iter1->second << endl;

    //决定新建值位置的不是指定的位置，他还是会重新排序，最大的区别在于，变为有序的时间复杂度

    // insert插入其他map容器中的指定区域的所有键值
    map<string, string> newMap{
        {"香港", "香港"}, {"澳门", "澳门"}, {"台湾", "台湾"}};
    this->values.insert(++newMap.begin(), newMap.end());
    for (auto iter = this->values.begin(); iter != this->values.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    // insert直接插入键值对列表
    this->values.insert({{"江苏", "南京"}, {"浙江", "杭州"}});
    for (auto iter = this->values.begin(); iter != this->values.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
}

void stl_map::stl_map_emplace()
{
    cout << "stl_map_emplace:" << endl;

    //插入键值对,emplace
    pair<map<string, string>::iterator, bool> ret = this->values.emplace("海南", "海口");
    cout << "1、ret.iter = <{" << ret.first->first << "," << ret.first->second << "}," << ret.second << ">" << endl;

    // emplace_hint(),向指定位置插入键值对,成功返回插入值迭代器，失败返回相同健的键值对
    map<string, string>::iterator iter = this->values.emplace_hint(this->values.begin(), "四川", "成都");
    cout << iter->first << " " << iter->second << endl;
    iter = this->values.emplace_hint(this->values.begin(), "江西", "南昌");
    cout << iter->first << " " << iter->second << endl;
}

void stl_map::stl_map_multimap()
{
    cout << "stl_map_multimap:" << endl;

    // multimap创建和初始化的方法类似，详情见上
    multimap<string, int, greater<string>> scoreMap{{"tony", 67}, {"joy", 78}, {"tom", 88}, {"tom", 98}, {"mary", 78}};

    // multimap未提供at(),也没有重载[]运算符，主要是因为容器中的键对应的键值不唯一
    //所以low_bound(),upper_bound(),equal_range()以及count()经常被使用
    cout << "socerMap size:" << scoreMap.size() << endl;

    cout << "tom size:" << scoreMap.count("tom") << endl;

    for (auto iter = scoreMap.begin(); iter != scoreMap.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    // lower_bound()
    cout << "lower_bound:" << endl;
    auto it = scoreMap.lower_bound("tom");
    while (it != scoreMap.end())
    {
        cout << it->second << " ";
        it++;
    }
    cout << endl;

    // upper_bound
    cout << "upper_bound:" << endl;
    it = scoreMap.upper_bound("tom");
    while (it != scoreMap.end())
    {
        cout << it->second << " ";
        it++;
    }
    cout << endl;

    // equal_range(),返回lower_bound-upper_bound范围内的pair对象，包含两个双向迭代器
    cout << "equal_range:" << endl;
    pair<map<string, int>::iterator, map<string, int>::iterator> ret = scoreMap.equal_range("tom");
    it = ret.first;
    while (it != ret.second)
    {
        cout << it->second << " ";
        it++;
    }
    cout << endl;
}