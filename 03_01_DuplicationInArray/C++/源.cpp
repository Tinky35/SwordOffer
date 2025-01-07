#include <vector>
#include <iostream>


// 输出vec数据
// 注意形参形式
void coutVec(const std::vector<int>& data)
{
    for (int j = 0; j < data.size(); ++j)
    {
        std::cout << data[j] << "\t";
    }
}

// 面试题3-数组中重复的数字（会修改数组）
// 未设置边界保护
void repeatNumFun()
{
    int data[] = { 2, 3, 1, 0, 2, 5, 3 };
    int dataSize = sizeof(data) / sizeof(data[0]);
    std::vector<int> repeatNum;
    for (int i = 0; i < dataSize; )
    {
        int value = data[i];
        if (i == value)
        {
            ++i;
        }
        else
        {
            int temp = data[value];
            if (value == temp)
            {
                repeatNum.push_back(value);
                ++i;
            }
            else
            {
                data[value] = value;
                data[i] = temp;
            }
        }
    }
    coutVec(repeatNum);
}

#ifndef RunTests
int main() {

   

    return 0;
}
#endif
