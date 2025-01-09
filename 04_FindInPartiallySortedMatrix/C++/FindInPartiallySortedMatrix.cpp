// 面试题4：二维数组中的查找
// 题目：在一c个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。
#include <iostream>
bool isFind(int* matrix, int rowCount, int columnCount, int number)
{
    //边界检查
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
        // 这里使用高性能低可读性性的二维数组访问方式来进行访问
        // matrix[row * columnCount + column] = matrix[row][column]
        value = matrix[row * columnCount + column];
        if (value == number)
        {
            return true;
        }
        else if (value > number)
        {
            // 剔除所在列
            --column;
        }
        else
        {
            // 剔除所在行
            ++row;
        }
    }
    return result;
}

// ====================测试代码====================
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
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
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