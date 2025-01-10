#include <iostream>
#include <stack>

struct listNode
{
    int m_nValue = 0;
    listNode* m_pNext = nullptr;
};

// copy by author
void PrintList(listNode* pHead)
{
    printf("PrintList starts.\n");
    
    listNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    printf("\nPrintList ends.\n");
}

listNode* CreatelistNode(int value)
{
    listNode* pNode = new listNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

void ConnectlistNodes(listNode* pCurrent, listNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

void DestroyList(listNode* pHead)
{
    listNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

/// @brief main Code
/// @param pHead 
void printByStack(listNode* pHead)
{
    if (!pHead)
    {
        std::cout << "The pHead is empty!" << std::endl;
        return;
    }
    std::stack<listNode*> dataStack;
    listNode* pNode = pHead;
    while (pNode)
    {
        dataStack.push(pNode);
        pNode = pNode->m_pNext;
    }

    while (!dataStack.empty())
    {
        pNode = dataStack.top();
        std::cout << pNode->m_nValue << "\t";
        dataStack.pop();
    }
}

void printByRecrusion(listNode* pHead)
{
    if (pHead)
    {
        if (pHead->m_pNext)
        {
            printByRecrusion(pHead->m_pNext);
        }
        std::cout << pHead->m_nValue << "\t";
    }
    
}

/////// Test Code Copy By Author /////
void Test(listNode* pHead)
{
    PrintList(pHead);
    printf("printByStack:\n");
    printByStack(pHead);
    printf("printByRecrusion:\n");
    printByRecrusion(pHead);
    printf("\n");
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    listNode* pNode1 = CreatelistNode(1);
    listNode* pNode2 = CreatelistNode(2);
    listNode* pNode3 = CreatelistNode(3);
    listNode* pNode4 = CreatelistNode(4);
    listNode* pNode5 = CreatelistNode(5);

    ConnectlistNodes(pNode1, pNode2);
    ConnectlistNodes(pNode2, pNode3);
    ConnectlistNodes(pNode3, pNode4);
    ConnectlistNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

void Test2()
{
    printf("\nTest2 begins.\n");

    listNode* pNode1 = CreatelistNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}