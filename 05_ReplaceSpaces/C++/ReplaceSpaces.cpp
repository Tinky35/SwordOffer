// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <iostream>

void replaceBlank(char str[], int maxLen)
{
    //�߽�����
    if (!str)
        return;

    int i = 0;
    int originalLen = 0;
    int blankCount = 0;
    while (str[i] != '\0')
    {
        ++originalLen;
        if (str[i] == ' ')
            ++blankCount;
        ++i;
    }
    int newLen = originalLen + blankCount * 3;
    int idxOriginal = originalLen;
    int idxNew = newLen;
    while (idxOriginal > idxNew && idxOriginal >= 0)
    {
        if (str[idxOriginal] != ' ')
        {
            str[idxNew--] = str[idxOriginal];
        }
        else
        {
            str[idxNew--] =  '0';
            str[idxNew--] =  '2';
            str[idxNew--] =  '%';
        }
        --idxOriginal;
    }
}

// ====================���Դ���====================
void Test(const char* testName, char str[], int length, const char expected[])
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    replaceBlank(str, length);

    if (expected == nullptr && str == nullptr)
        std::cout << "\tthe data is null!" << std::endl;
    else if (expected == nullptr && str != nullptr)
        std::cout << "\tthe data is null!" << std::endl;
    else if (strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        std::cout << "\tsomethind wrong!" << str <<"\t" << expected << std::endl;

}

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
