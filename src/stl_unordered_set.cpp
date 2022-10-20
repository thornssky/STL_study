#include "stl_unordered_set.h"

stl_unordered_set::stl_unordered_set(unordered_set<string> values)
{
    this->values = values;
}

void stl_unordered_set::stl_unordered_set_creat()
{
    cout << "stl_unordered_set_creat" << endl;

    unordered_set<string> uset;
    unordered_set<string> uset1{"dog", "cat", "chicken", "duck"};
    unordered_set<string> uset2(uset1);
    // unordered_set<string> uset3(usetret());
    unordered_set<string> uset4(++uset2.begin(), uset2.end());

    cout << "uset:" << endl;
    for (auto iter = uset.begin(); iter != uset.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "uset1:" << endl;
    for (auto iter = uset1.begin(); iter != uset1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "uset2:" << endl;
    for (auto iter = uset2.begin(); iter != uset2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "uset4:" << endl;
    for (auto iter = uset4.begin(); iter != uset4.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void stl_unordered_set::stl_unordered_set_iterator(){
    for(auto iter = this->values.begin();iter != this->values.end();iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

void stl_unordered_set::stl_unordered_set_show(){
    cout << "stl_unordered_set_show" << endl;

    //插入常用
    this->values.emplace("Ox");
    this->stl_unordered_set_iterator();

    //size()
    cout << "size:" << this->values.size() << endl;

    //删除
    this->values.erase("dog");//常用的一种，可以有其他的方式格式和操作
    this->stl_unordered_set_iterator();

    cout << "大多数操作和undered_map操作相同" << endl;

}