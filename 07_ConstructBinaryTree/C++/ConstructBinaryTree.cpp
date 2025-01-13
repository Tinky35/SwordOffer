#include <iostream>

struct BinaryTreeNode
{
    int m_nValue = 0;
    BinaryTreeNode* m_pLeft = nullptr;
    BinaryTreeNode* m_pRight = nullptr;
};

BinaryTreeNode* ConstructCore(int* pStartPreOrder, int* pEndPreOrder,
 int* pStartMidOrder, int* pEndMidOrder);

BinaryTreeNode* Construct(int* pPreOrder, int* pMidOrder, int len)
{
    if(pPreOrder == nullptr || pMidOrder == nullptr || len <= 0)
        return nullptr;

    return ConstructCore(pPreOrder, pPreOrder + len - 1,
        pMidOrder, pMidOrder + len - 1);
}

BinaryTreeNode* ConstructCore
(
    int* pStartPreOrder, int* pEndPreOrder, 
    int* pStartMidOrder, int* pEndMidOrder
)
{
    // find the root: the first val in preOreder is the root node
    int value = pStartPreOrder[0];
    BinaryTreeNode* pRootNode = new BinaryTreeNode();
    pRootNode->m_nValue = value;

    if (pStartPreOrder == pEndPreOrder &&
        pStartMidOrder == pEndMidOrder &&
        *pStartPreOrder == *pEndMidOrder)
    {
        return pRootNode;
    }

    // find root in MidOrder
    int offset = 0;
    while ((pStartMidOrder + offset) <= pEndMidOrder
            && *(pStartMidOrder + offset) != pRootNode->m_nValue)
    {
        ++offset;
    }
    
    if (offset == 0 && *(pStartMidOrder + offset) != pRootNode->m_nValue)
    {
        throw("The data is wrong!");
    }

    // find the left: the values to the left of root are the left tree in midOrder
    int* pPreOrdLeftEnd = pStartPreOrder + offset;
    int* pMidOrdLeftEnd = pStartMidOrder + offset;
    if (offset > 0)
    {
        // construc left trees
        pRootNode->m_pLeft = ConstructCore(pStartPreOrder + 1, pPreOrdLeftEnd,
                                            pStartMidOrder, pMidOrdLeftEnd);
    }

    if ((pEndPreOrder - pPreOrdLeftEnd) > 0)
    {
        // construct right tree
        pRootNode->m_pRight = ConstructCore(pPreOrdLeftEnd + 1, pEndPreOrder,
                                            pMidOrdLeftEnd + 1, pEndMidOrder);
    }
    
    return pRootNode;
}

// copy by the author
void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is nullptr.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ====================测试代码====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
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

    return 0;
}