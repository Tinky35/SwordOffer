#include <iostream>

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��

int getCount(int data[], int dataSize, int begain, int end = -1)
{
	int count = 0;
	for (size_t i = 0; i < dataSize ; ++i)
	{
		if (end != -1)
		{
			if (data[i] >= begain && data[i] <= end)
				++count;
		}
		else
		{
			if (data[i] == begain)
				++count;
		}
	}
	return count;
}

void findDuplication(int data[], int dataSize, int expectNum)
{
	//�߽���
	if (data == nullptr || dataSize <= 0)
	{
		std::cout << "The enter data is wrong!" << std::endl;
		return;
	}

	bool needSearch = true;
	int begain = 1;
	int end = dataSize - 1;
	int mid = (begain + end) / 2;
	int duplicationNum = 0;

	int forwardBegain = begain;
	int forwardEnd = mid;
	int backBegain = mid + 1;
	int backEnd = end;

	begain = forwardBegain;
	end = forwardEnd;
	while (needSearch)
	{
		int count = getCount(data, dataSize, begain, end);
		if (count > mid)
		{
			mid = (begain + end) / 2;
			forwardBegain = begain;
			forwardEnd = mid;
			backBegain = mid + 1;
			backEnd = end;

			end = forwardEnd;
		}
		else
		{
			begain = backBegain;
			end = backEnd;
		}

		if (mid == begain)
		{
			count = getCount(data, dataSize, begain);
			if (count >= 2)
			{
				duplicationNum = begain;
			}
			else
			{
				duplicationNum = end;
			}
			needSearch = false;
		}
	}

	if (duplicationNum == expectNum)
	{
		std::cout << "True\t" << duplicationNum << std::endl;
	}
	else
	{
		std::cout << "The result is wrong!\t" << "The duplication num is " << duplicationNum
			<< "\tThe expect is " << expectNum << std::endl;
	}
}


void main()
{
	int data[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	findDuplication(data, sizeof(data) / sizeof(int), 3);
	findDuplication(data, sizeof(data) / sizeof(int), 2);
}
