#include <set>
#include <iostream>

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��


// �ȽϽ��
void compareResault(const std::set<int>& data, int expected[], int expectedSize)
{
    int size = data.size();
    if (size == 0)
    {
        std::cout << "There are no duplicate numbers!" << std::endl;
        return;
    }

    if (size != expectedSize)
    {
        std::cout << "The resault is wrong !" << std::endl;
        return;
    }

    int j = 0;
    for (int key : data)
    {
        if (key != expected[j])
        {
            std::cout << key << " is not accort for��" << expected[j] << false;
            return;
        }
        std::cout << key << "\t";
        ++j;
    }
    std::cout << "The task is end!" << std::endl;
}

void repeatNumFun(int data[], int dataSize, int expected[], int expectedSize)
{
    if (dataSize <= 0 || data == nullptr)
    {
        std::cout << "The enter data is wrong!" << std::endl;
        return;
    }

    std::set<int> repeatNum;
    for (int i = 0; i < dataSize; )
    {
        int value = data[i];
        if (value < 0 || value > dataSize - 1)
        {
            std::cout << "Data is wrong!" << std::endl;
            return;
        }

        if (i == value)
        {
            ++i;
        }
        else
        {
            int temp = data[value];
            if (value == temp)
            {
                repeatNum.insert(value);
                ++i;
            }
            else
            {
                data[value] = value;
                data[i] = temp;
            }
        }
    }
    compareResault(repeatNum, expected, expectedSize);
}

#ifndef RunTests
int main() {
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    repeatNumFun(numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));

    int numbers1[] = { 2, 4, 3, 1, 4 };
    int duplications1[] = { 4 };
    repeatNumFun(numbers1, sizeof(numbers1) / sizeof(int), duplications1, sizeof(duplications1) / sizeof(int));

    int numbers2[] = { 2, 4, 2, 1, 4 };
    int duplications2[] = { 2, 4 };
    repeatNumFun(numbers2, sizeof(numbers2) / sizeof(int), duplications2, sizeof(duplications2) / sizeof(int));

    int numbers3[] = { 2, 1, 3, 0, 4 };
    int duplications3[] = { -1 }; // not in use in the test function
    repeatNumFun(numbers3, sizeof(numbers3) / sizeof(int), duplications3, sizeof(duplications3) / sizeof(int));

    int* numbers4 = nullptr;
    int duplications4[] = { -1 }; // not in use in the test function
    repeatNumFun(numbers4, sizeof(numbers4) / sizeof(int), duplications4, sizeof(duplications4) / sizeof(int));

    return 0;
}
#endif
