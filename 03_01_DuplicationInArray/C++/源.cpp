#include <vector>
#include <iostream>


// ���vec����
// ע���β���ʽ
void coutVec(const std::vector<int>& data)
{
    for (int j = 0; j < data.size(); ++j)
    {
        std::cout << data[j] << "\t";
    }
}

// ������3-�������ظ������֣����޸����飩
// δ���ñ߽籣��
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
