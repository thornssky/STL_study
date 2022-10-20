#pragma once
#include <array>
#include <iostream>
using namespace std;

class stl_array
{
private:
    array<double, 10> values; // array不提供默认初始化操作
public:
    stl_array();
    void stl_array_init();
    void stl_array_init(array<double, 10> arr);
    void stl_array_at();
    void stl_array_get();
    void stl_array_traverse();
    void stl_array_beginEnd();
    void stl_array_cbeginEnd();
    void stl_array_rbeginEnd();
};
