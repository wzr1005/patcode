#include <iostream>
#include <vector>
#include <algorithm>

const char *INSERT = "Insertion Sort";
const char *MERGE = "Merge Sort";

bool sorted(const std::vector<int> &ser, int end)
{
	while (end > 0)
	{
		if (ser.at(end) < ser.at(end - 1))
		{
			return false;
		}
		end--;
	}
	return true;
}

// 0: insert
// 1: merge
// 如果是插入排序, 序列排序是从左向右, 所以从右向左, 找到第一个与原序列不同的,
// 如果这个值之前都是有序的(前面的都排好了), 那就是插入, 否则就是merge
// 其实可以发现, merge第一轮做完, 最后三个(或两个)元素就发生位置变化了, 而在其前面的序列, 不一定有序.
int detectType(const std::vector<int> &ser, const std::vector<int> &raw)
{
	int last_index = ser.size() - 1;
	for (; last_index > 0; last_index--)
	{
		if (ser.at(last_index) != raw.at(last_index))
		{
			break;
		}
	}
	if (sorted(ser, last_index))
	{
		return 0;
	}
	return 1;
}

// 找到多长序列已有序, 比如 3 1 2 8 7 5 9 4 6 0 -> 1 2 3 7 8 5 9 4 6 0
// 前面 1 2 3 7 8 已有序, 返回 5, 即从左往右起第5(从0开始记)个已不再有序
// 对于插入排序而言, 也就是下一轮要处理的元素就是第5个
// 对于merge而言, 表明现在分段已经分到了5, 即原 序列被分为5(个)-5(个)-5(个)-..., 其中每5个已有序, 则下一轮, 应该是每10个
int sortedLength(const std::vector<int> &s)
{
	int index = 1;
	while (index < s.size() - 1)
	{
		if (s.at(index) < s.at(index - 1))
		{ // equal?
			break;
		}
		index++;
	}
	return index;
}
void insertNext(std::vector<int> &s)
{
	int index = sortedLength(s);
	std::sort(s.begin(), s.begin() + index + 1); // 已排序的序列延长1个
}
void mergeNext(std::vector<int> &s)
{
	int sorted_length = sortedLength(s);
	int offset = s.size() % (2 * sorted_length); // 不足一个分段的
	int index = 0;
	for (; index < s.size() - offset; index += 2 * sorted_length)
	{
		std::sort(s.begin() + index, s.begin() + index + 2 * sorted_length);
	}
	std::sort(s.begin() + index, s.end());
}

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> raw(N);
	std::vector<int> mid(N);

	for (auto i = 0; i < N; i++)
	{
		std::cin >> raw[i];
	}
	for (auto i = 0; i < N; i++)
	{
		std::cin >> mid[i];
	}

	int type = detectType(mid, raw);
	if (type == 0)
	{
		std::cout << INSERT << std::endl;
		insertNext(mid);
	}
	else
	{
		std::cout << MERGE << std::endl;
		mergeNext(mid);
	}
	for (auto i = mid.begin(); i != mid.end(); i++)
	{
		if (i != mid.begin())
		{
			std::cout << " ";
		}
		std::cout << *i;
	}
}