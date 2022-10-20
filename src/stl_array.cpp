#include "stl_array.h"

void stl_array::stl_array_rbeginEnd()
{
    int h = 1;
    //指向的位置分别是最后一个元素元素位置和第一个位置的前一个位置，从后往前
    auto first = values.rbegin();
    auto last = values.rend();

    while (first != last)
    {
        *first = h;
        ++first;
        h++;
    }

    first = values.rbegin();
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

void stl_array::stl_array_beginEnd()
{
    int h = 1;
    //指向的位置分别是第一个元素位置和最后一个位置的后一个位置，从前向后
    auto first = values.begin();
    auto last = values.end();

    while (first != last)
    {
        *first = h;
        ++first;
        h++;
    }

    first = values.begin();
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
    cout << endl;
}

void stl_array::stl_array_cbeginEnd()
{
    //先将数据部分初始化
    stl_array_init();
    auto first = values.cbegin();
    auto last = values.cend();
    //因为使用的是cbegin()cend()所以只能读不能修改
    first = values.begin();
    while (first != last)
    {
        cout << *first << " ";
        ++first;
    }
}

void stl_array::stl_array_init(array<double, 10> arr)
{
    this->values = arr;
}

void stl_array::stl_array_traverse()
{
    array<double, 10> values1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (!values.empty())
    { // auto会自动识别变量类型
        for (auto val = values.begin(); val < values.end(); val++)
        {
            cout << *val << " ";
        }
    }
    cout << endl;
    stl_array_init(values1);

    cout << "values[0] is : " << values[0] << endl;
    cout << "values[1] is : " << values.at(1) << endl;
    cout << "values[2] is : " << get<2>(values) << endl;
}

void stl_array::stl_array_get()
{
    cout << get<3>(values) << endl;
}

//返回容器中指定位置的引用，会自动检查是否越界
void stl_array::stl_array_at()
{
    cout << "at():" << endl;
    for (int i = 0; i < values.size(); i++)
    {
        values.at(i) = i;
    }
}

//初始化部分
void stl_array::stl_array_init()
{
    cout << "init part:" << endl;
    array<double, 10> values_temp{0.5, 1.0, 1.5, 2.0};
    this->values = values_temp;
}

stl_array::stl_array()
{
    cout << "construct 1:" << endl;
    array<double, 10> values_temp{}; //初始化为0
    this->values = values_temp;
}
