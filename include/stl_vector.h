#include<vector>
#include<array>
using namespace std;

class stl_vector
{
private:
    vector<double> values;
public:
    stl_vector(vector<double> values);
    void stl_vector_createInit();
    void stl_vector_iterator();
    void stl_vector_traverse();
    void stl_vector_pushbackEmplaceback();
    void stl_vector_insertEmplace();
    void stl_vector_popbackEraseRemoveClear();
};

