/*
C++ STL  standard template libaray 标准模板库
一、标准容器： C++11 array forwaord_list
1.顺序容器
vector
deque
list
2.容器适配器
stack
queue
priority_queue
3.关联容器
无序关联容器--->链式哈希表 增删查O(1)
unordered_set 单重集合
unordered_multiset   多重集合
unordered_map   单重映射表
unordered_multimap  多重映射表
有序关联容器--->红黑树 增删查O(log2n)  2是底数(树的层数，树的高度)
set
multiset
map
multimap
二、近容器
数组、string、bitset(位容器)
三、迭代器
iterator和const iterator
reverse_iterator和const_reverse_iterator
四、函数对象
greater,less
五、泛型算法
sort,find,find_if,binary_search,for_each
*/
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<list>
#include<stack>//stack
#include<queue>//queue和priority_queue(优先级队列)
//使用有序关联容器包含的头文件
#include<set>//set multiset
#include<map>//map miltimap
//使用无序关联容器包含的头文件
#include<unordered_set>
#include<unordered_map>
#include<string>
//1.顺序容器：
#if 0
/*

list:链表容器
底层数据结构：双向循环链表 pre data next
list<int>mylist;
增加：
mylist.push_back();从末尾添加元素，时间复杂度O(1)
mylist.push_front();从首部添加元素，时间复杂度O(1)
mylist.insert(it,20);it指向的位置添加元素，时间复杂度O(1)  、

删除：
mylist.pop_back():从末尾删除元素，时间复杂度O(1)
mylist.pop_front();从首部删除元素，时间复杂度O(1)
mylist.earse();从it指向的位置删除元素，时间复杂度O(1)

链表中进行insert/earse操作的时候，先要进行一个query查询操作，对于链表来说，查询操作的效率并不高。
查询：
iterator(连续的insert和erase一定要考虑迭代器失效的问题)
常用方法：
size()
empty()
reverse():list预留空间的   只给容器底层开辟指定大小的内存空间，并不会添加新的元素
resize():容器扩容用的  不仅给容器底层开辟指定大小的内存空间，还会添加新的元素0
swap()：两个容器交换元素
*/
int main()
{
	list<int>lst;
	//lst.reverse();
	lst.resize(10);
	cout << lst.empty() << endl;
	cout << lst.size() << endl;
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	//cout << "push_back()" << endl;
	for (int i = 0; i < 10; ++i)
	{
		lst.push_back(rand() % 100 + 1);
	}
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	cout << lst.empty() << endl;
	cout << lst.size() << endl;
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	cout << "push_front" << endl;
	for (int i = 0; i < 10; ++i)
	{
		lst.push_front(rand() % 100 + 1);
	}
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		lst.pop_back();
	}
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		lst.pop_front();
	}
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	auto it1 = lst.begin();
	while (it1 != lst.end())
	{
		if (*it1 % 2 == 0)
		{
			it1 = lst.erase(it1);
		}
		else
		{
			++it1;
		}
	}
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	for (it1 = lst.begin(); it1 != lst.end(); ++it1)
	{
		if (*it1 % 2 != 0)
		{
			it1 = lst.insert(it1,*it1-1);
			++it1;
		}
	}
	for (auto a : lst)
	{
		cout << a << " ";
	}
	cout << endl;
	return 0;
}

/*
deque:双端队列容器
底层数据结构：动态开辟的二维数组。
扩容方式：一维数组从2开始，以2倍的方式进行扩容，每次扩容后，原来第二维的数组，从新的第一维数组的下标oldsize/2开始存放，
               上下都预留相同的空港，方便支持deque的首尾元素添加。
deque<int>deq;
增加：
deq.push_back();从末尾添加元素，时间复杂度O(1)
deq.push_front();从首部添加元素，时间复杂度O(1)
deq.insert(it,20);it指向的位置添加元素，时间复杂度O(N)

删除：
deq.pop_back():从末尾删除元素，时间复杂度O(1)
deq.pop_front();从首部删除元素，时间复杂度O(1)
deq.earse();从it指向的位置删除元素，时间复杂度O(N)

查询：
iterator(连续的insert和erase一定要考虑迭代器失效的问题)

常用方法：
size()
empty()
resize():容器扩容用的  不仅给容器底层开辟指定大小的内存空间，还会添加新的元素0
swap()：两个容器交换元素
*/
int main()
{
	deque<int>deq;
	deq.resize(20);
	cout<<deq.empty()<<endl;
	cout << deq.size() << endl;
	for (auto a : deq)
	{
		cout << a << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; ++i)
	{
		deq.push_back(rand() % 100 + 1);
	}
	for (auto a : deq)
	{
		cout << a << " ";
	}
	cout << endl;
	cout << deq.empty() << endl;
	cout << deq.size() << endl;

	cout << "push_back()" << endl;

	for (auto a : deq)
	{
		cout << a << " ";
	}
	cout << endl;
	for (int i = 10; i < 20; ++i)
	{
		deq.push_front(rand() % 100 + 1);
	}
	cout << "push_front()" << endl;
	for (int i = 0; i < 20; ++i)
	{
		cout << deq[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		deq.pop_back();
	}
	for (auto a : deq)
	{
		cout << a << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; ++i)
	{
		deq.pop_front();
	}
	for (auto a : deq)
	{
		cout << a << " ";
	}
	cout << endl;
	auto it1 = deq.begin();
	while (it1 != deq.end())
	{
		if (*it1 % 2 == 0)
		{
			it1 = deq.erase(it1);
		}
		else
		{
			++it1;
		}
	}
	for (auto a : deq)
	{
		cout << a << " ";
	}
	cout << endl;
	for (it1 = deq.begin(); it1 != deq.end(); ++it1)
	{
		if (*it1 % 2 != 0)
		{
			it1 = deq.insert(it1, *it1 - 1);
			++it1;
		}
	}
	auto it2 = deq.begin();
	for (; it2 != deq.end(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << endl;

	return 0;
}

/*
vector:向量容器
初始时向量容器是没有开辟空间的，只有当进行数据的插入时才会开辟所需空间
底层数据结构：动态开辟的数组，每次以原来空间大小的2倍进行扩容的
数组最大的特点就是下标的随机访问
vector<int>vec;
增加：
vec.push_back(20);末尾添加元素,有时会导致扩容                                时间复杂度 O(1)
vec.insert(it,20);it迭代器指向的位置添加一个元素20，有时会导致扩容  时间复杂度O(N)
删除：
vec.pop_back()；末尾删除元素                                                           时间复杂度O(1)
vec.erase(it);删除it指向位置的元素，                                                   时间复杂度O(N)
查询：
operator[]：下标的随机访问vec[]                                                        时间复杂度O(1)
iterator迭代器进行遍历
find,for_each
foreach===>通过iterator来实现的

注意：对容器进行连续插入或者删除操作(insert/earse),一定要更新迭代器，否则一次insert/erase完成后，迭代器就失效了
常用方法介绍：
size()
empty()
reserve(20):vector预留空间的   只给容器底层开辟指定大小的内存空间，并不会添加新的元素
resize():容器扩容用的  不仅给容器底层开辟指定大小的内存空间，还会添加新的元素0
swap()：两个容器交换元素
*/
int main()
{

	vector<int>vec;
	//vec.reserve(20);
	vec.resize(20);         //int()
	cout << vec.empty() << endl;
	cout << vec.size() << endl;
	for (auto it : vec)
	{
		cout << it << " ";
	}
	cout << endl;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100 + 1);
	}
	cout << vec.empty() << endl;
	cout << vec.size() << endl;
	for (auto it : vec)
	{
		cout << it << " ";
	}
	cout << endl;

	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		//[]:vector的operator[]运算符重载函数
		cout << vec[i] << " ";
	}
	cout << endl;
	//把vec容器中所有的偶数全部删除
	auto it2 = vec.begin();
	while (it2 != vec.end())
	{
		if (*it2 % 2 == 0)
		{
			//连续删除时为防止迭代器失效，需要更新迭代器it2的位置
			it2 = vec.erase(it2);
		}
		else
		{
			++it2;
		}
	}
	//通过迭代器遍历vector容器
	auto it1 = vec.begin();
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	//给vector容器中所有的奇数前面都添加一个小于奇数1的偶数
	for (it1 = vec.begin(); it1 != vec.end(); ++it1)
	{
		if (*it1 % 2 == 1)
		{
			//连续插入时为防止迭代器失效，需要更新迭代器it1的位置
			it1 = vec.insert(it1, *it1 - 1);
			++it1;
		}
	}
	//通过范围for遍历vector容器
	for (auto a:vec)
	{
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
/*
总结
vector的特点：动态数组，内存时连续的，2倍的方式进行扩容; 默认定义vector<int>vec时，其并没有开辟内存，只有当进行插入操作时，才会开始按照0-1-2-4-8...来扩容；reserve()，仅预留空间，不初始化元素
deque特点：动态开辟的二维数组空间，第二维是固定长度的数组空间，扩容的时候(第一维的数组进行二倍扩容)

deque底层内存是否是连续的？
答：并不是，每一个第二维是连续的，每一个第二维是重新new出来的

vector和deque之间的区别？
1.底层数据结构：
2.前中后插入删除元素的时间复杂度：末尾都是O(1)，中都是O(N)，前deque O(1)、vector O(N)，
3.对于内存的使用效率:vector需要的内存空间必须是连续的  deque可以分块进行数据存储，不需要内存空间必须是一片连续的
4.在中间进行insert或者earse时，vector和deque他们的效率谁能好一点(vector)？谁能差一点(deque)？
由于deque的第二维内存空间不是连续的，所以所在deque中间进行元素的insert和erase，造成元素移动的时候比vector要慢

vector和list之间的区别？
数组：增加删除O(N)  查询O(N)  随机访问O(1)
链表：（不考虑搜索的时间）增加删除O(1)   查询O(N)
1.底层数据结构：vector(数组)、list(双向循环链表)
*/
#endif

//2.标准容器 - 容器适配器 => 设计模式之一 ——适配器
#if 0
/*
1.适配器底层没有自己的数据结构，它是另外一个容器的封装，它的方法全部由底层依赖的容器进行实现的
2.没有实现自己的迭代器
template <typename T,typename Container=deque<T>>
class Stack
{
public:
	void push(const T& val) { con.push_back(val); }
	void pop() { con.pop_back(); }
	T top()const { return con.back(); }
private:
	Container con;
};

stack：push入栈     pop出栈    top查看栈顶元素     empty判断栈空     size
queue：push入队   pop出队     front查看队头元素   back查看队尾元素 empty判断队空 size返回队列元素的个数
stack => deque   为什么不依赖vector?
queue => deque  为什么不依赖vector？
1.vector的初始内存使用效率太低了！没有deque好。queue<int> stack<int> 初始内存vector 0-1-2-4-8 deque 4096/sizeof(int)=1024.初始时，deque不容不断地去扩容
2.对于queue来说，需要支持尾部插入，头部删除，deque两个操作时间复杂度都是O(1)，而vector的头部操作时间复杂度是O(N),如果queue依赖vector，出队效率很低
3.vector需要大片的连续内存，而deque只需要分段的内存，当存储大量数据时，显然deque对于内存的利用率更好一些

priority_queue：push入队       pop出队    top查看队顶元素     empty判断队空     size返回元素个数  默认：大根堆
priority_queue => vector    为什么又依赖vector，而不依赖deque？
priority_queue底层默认把数据组成一个大根堆结构。
在一个内存连续的数组上构建一个大根堆或者小根堆(堆中的结点和它左右孩子的关系是通过下标计算的)
这样就可以通过下标快速随机访问一块连续的内存空间，而deque的第二维是不连续的。
*/
int main()
{
	stack<int>s1;
	for (int i = 0; i < 20; ++i)
	{
		s1.push(rand() % 100 + 1);
		cout << s1.top() << " ";
	}
	cout << endl;
	cout << s1.size() << endl;
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}

	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	queue<int>que;
	for (int i = 0; i < 20; ++i)
	{
		que.push(rand() % 100 + 1);
		cout << que.back() << " ";
	}
	cout << endl;
	cout << que.size() << endl;
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}

	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	priority_queue<int>pque;
	for (int i = 0; i < 20; ++i)
	{
		pque.push(rand() % 100 + 1);
	}
	cout << pque.size() << endl;
	while (!pque.empty())
	{
		cout << pque.top()<< " ";
		pque.pop();
	}
	cout << endl;
	return 0;
}
#endif

//3.关联容器
#if 0
/*
无序关联容器
1.各个容器底层的数据结构  链式哈希表O(1)    红黑树O(log2n)
2.常用增删查方法:
增加：insert(val)
遍历：iterator自己搜索，调用find成员方法
删除：erase(key)  erase(it)
*/
int main()
{

	/*
	set
	*/
	unordered_set<int>set1;//不会存储key值重复的元素
	for (int i = 0; i < 50; ++i)
	{
		set1.insert(rand() % 20 + 1);  //vector/deque/list insert(it,val)
	}
	cout << set1.size() << endl;
	cout << set1.count(15) << endl;
	
	auto it1 = set1.begin();
	for (; it1 != set1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	set1.erase(20); //按Key值删除元素
	for (it1 = set1.begin(); it1 != set1.end();)
	{
		if (*it1 == 30)
		{
			it1 = set1.erase(it1); //调用erase；it1迭代器就失效了
		}
		else
			++it1;
	}
	it1 = set1.find(20);
	if (it1 != set1.end())
	{
		set1.erase(it1);
	}
	//范围for输出
	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;

	/*
	map:
	[key,value]
	struct pair
	{
	private:
		first;==>key
		second;==>value
	};
	map的operator[]:
	V& operator(const K &key)
	{
		insert( { key, V( ) } );
	}
	功能：
	1.查询
	2.如果key不存在，它会插入一堆数据[key,string()]
	*/
	unordered_map<int, string>map1;
	//map表增加元素
	map1.insert(make_pair(1000, "张三"));
	map1.insert({ 1010,"李四" });
	map1.insert({ 1020,"王五" });
	map1.insert({ 1030,"王凯" });
	//map表删除元素
	map1.erase(1020);//{ 1020,"王五" }删除了
	auto it1 = map1.find(1030);
	if (it1 != map1.end())
	{
		//it1->pair对象
		cout << "key：" << it1->first << "value：" << it1->second << endl;
	}
	cout << map1.size() << endl;
	//map1[2000];//不存在key = 2000，调用string的构造函数构造一个空的对象，并且插入key=2000这个元素
	map1[2000] = "刘硕";//相当于一个添加功能map1.insert( { 2000, "刘硕"} )；
	map1[1000] = "张三2";//相当于一个修改的功能
	cout << map1.size() << endl;

	//使用[]运算符重载函数查询元素
	//map operator[](key)==>val
	cout << map1[1000] << endl;

	/*
	set、map使用场景：
	处理海量数据查重复；去重复的时候
	*/
	const int ARR_LEN = 100;
	int arr[ARR_LEN] = { 0 };
	for (int i = 0; i < ARR_LEN; ++i)
	{
		arr[i] = rand() % 20+ 1;
	}

	//查重：
	//上面的10万个整数中统计哪些数字重复了，并且统计数字重复的次数
	unordered_map<int, int>map1;
	for (int k : arr)
	{
		//auto it = map1.find(k);
		//if (it == map1.end())
		//{
		//	map1.insert({ k,1 });
		//}
		//else
		//{
		//	it->second++;
		//}
		map1[k]++; //map1[k]---->[k,0]--->++  => [k,1]
	}
	//范围for遍历
	/*for (auto &p : map1)
	{
		if (p.second > 1)
		{
			cout << "key:" << p.first << "  count:" << p.second << endl;
		}
	}*/
	//迭代器遍历
	auto it1 = map1.begin();
	for (; it1 != map1.end(); ++it1)
	{
		if (it1->second > 1)
		{
			cout << "key:" << it1->first << "  count:" << it1->second << endl;
		}
	}

	//去重：
	//上面的10万个整数中，把数字进行去重打印
	unordered_set<int> set;
	for (int v : arr) //O(N)
	{
		set.insert(v);
	}
	for (int v : set)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
#endif