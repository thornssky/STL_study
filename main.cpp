#include "stl_iterator.h"
#include "stl_array.h"
#include "stl_vector.h"
#include "stl_deque.h"
#include "stl_list.h"
#include "stl_map.h"
#include "stl_set.h"
#include "stl_unordered_map.h"
#include "stl_adapter.h"
#include "stl_iterator_extend.h"

using namespace std;
void test_stl_iterator();
void test_stl_array();
void test_stl_vector();
void test_stl_deque();
void test_stl_list();
void test_stl_map();
void test_stl_set();
void test_stl_unordered_map();
void test_stl_adapter();
void test_stl_iterator_extend();

int main()
{
    test_stl_iterator_extend();
    return 0;
}

void test_stl_iterator()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    //这里构造函数带参数
    stl_iterator stlit(v);

    stlit.no_1_iterator();
    stlit.no_2_iterator();
    stlit.no_3_iterator();
    stlit.no_4_iterator();
}

void test_stl_array()
{
    //这里构造函数不带参数，不带参数不可以写括号，不然报错
    //表达式必须包含类 类型
    stl_array stlarr;

    stlarr.stl_array_traverse();

    //使用类指针就使用箭头引用成员函数，.只限制于结构体和对象而不是对象指针
    stl_array *stlarrp = new stl_array;
    stlarrp->stl_array_traverse();

    array<double, 10> value{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    stlarr.stl_array_init(value);
    stlarr.stl_array_beginEnd();
    stlarr.stl_array_cbeginEnd();
    stlarrp->stl_array_rbeginEnd();
}

void test_stl_vector()
{
    vector<double> ve{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    stl_vector stlvector(ve);
    stlvector.stl_vector_iterator();
    stlvector.stl_vector_traverse();
    stlvector.stl_vector_insertEmplace();
    stlvector.stl_vector_pushbackEmplaceback();
    stlvector.stl_vector_popbackEraseRemoveClear();
}

void test_stl_deque()
{
    deque<int> deq{2, 3, 5, 8, 9, 7, 6};
    stl_deque stldeque(deq);
    cout << "test_stl_deque:" << endl;
    stldeque.stl_deque_iterator();
    stldeque.stl_deque_traverse();
    stldeque.stl_deque_addDelete();
}

void test_stl_list()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> stlli(a, a + 8);
    stl_list stllist(stlli);
    stllist.stl_list_iterator();
    stllist.stl_list_traverse();
    stllist.stl_list_add();
    stllist.stl_list_delete();
    stllist.stl_list_forwardlist();
}

void test_stl_map()
{
    map<string, string> values{{"江西", "南昌"}, {"北京", "北京"}, {"广东", "广州"}};
    stl_map stlMap(values);
    stlMap.stl_map_pair();
    // stlMap.stl_map_creat();
    stlMap.stl_map_iterator();
    stlMap.stl_map_traverse();
    stlMap.stl_map_insert();
    stlMap.stl_map_emplace();
    stlMap.stl_map_multimap();
}

void test_stl_set()
{
    set<string> values{"january", "february", "march", "april", "september", "october", "november", "december"};
    stl_set stlSet(values);
    stlSet.stl_set_creat();
    stlSet.stl_set_iterator();
    stlSet.stl_set_insert();
    stlSet.stl_set_emplace();
    stlSet.stl_set_delete();
    stlSet.stl_set_multiset();
}

void test_stl_unordered_map()
{
    unordered_map<string, string> values{{"joy", "man"}, {"mary", "women"}, {"bob", "man"}};
    stl_unordered_map stlUnorderedMap(values);
    stlUnorderedMap.stl_unordered_map_creat();
    stlUnorderedMap.stl_unordered_map_iterator();
    stlUnorderedMap.stl_unordered_map_visit();
    stlUnorderedMap.stl_unordered_map_insert();
    stlUnorderedMap.stl_unordered_map_emplace();
    stlUnorderedMap.stl_unordered_map_delete();
    stlUnorderedMap.stl_unordered_map_multimap();
}

void test_stl_adapter(){
    deque<int> lvalues{1, 2, 3};
    stack<int, deque<int>> lsvalues(lvalues);  //使用基础容器初始化stack容器
    deque<int> devalues{1, 2, 3};
    queue<int> dqvalues(devalues);
    int values[]{4, 1, 3, 2};
    priority_queue<int> apqvalues(values, values + 4); //{4,2,3,1}

    stl_adapter stladapter(lsvalues,dqvalues,apqvalues);
    stladapter.stl_adapter_stack();
    stladapter.stl_adapter_queue();
    stladapter.stl_adapter_priority_queue();
}

void test_stl_iterator_extend(){
    stl_iterator_extend iterex;
    iterex.stl_iterator_extend_init();
    iterex.stl_iterator_insert();
    iterex.stl_iterator_reverse();
    iterex.stl_iterator_assist();
}