#pragma once
#include <list>
#include <forward_list>
//双向列表容器
//应用场景，大量添加和删除的操作，访问需求较少
using namespace std;

class stl_list
{
private:
    list<int> li;
public:
    stl_list(list<int> li);
    void stl_list_createInit();
    void stl_list_iterator();
    void stl_list_traverse();
    void stl_list_add();
    void stl_list_delete();
    void stl_list_forwardlist();
};


