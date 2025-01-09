// ������4����ά�����еĲ���
// ��Ŀ����һc����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
// �մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
// �������ж��������Ƿ��и�������
#include <iostream>
bool isFind(int* matrix, int rowCount, int columnCount, int number)
{
    //�߽���
    if (!matrix || rowCount < 0 || columnCount <= 0)
    {
        std::cout << "The enter data is wrong!" << std::endl;
        return false;
    }

    bool result = false;
    int row = 0;
    int column = columnCount - 1;
    int value = 0;
    while (row < rowCount && column >= 0)
    {
        // ����ʹ�ø����ܵͿɶ����ԵĶ�ά������ʷ�ʽ�����з���
        // matrix[row * columnCount + column] = matrix[row][column]
        value = matrix[row * columnCount + column];
        if (value == number)
        {
            return true;
        }
        else if (value > number)
        {
            // �޳�������
            --column;
        }
        else
        {
            // �޳�������
            ++row;
        }
    }
    return result;
}

// ====================���Դ���====================
void Test(const std::string& testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if (testName.size() > 0)
        printf("%s begins: ", testName);

    bool result = isFind(matrix, rows, columns, number);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test1()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test7()
{
    Test("Test7", nullptr, 0, 0, 16, false);
}


int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0;
}