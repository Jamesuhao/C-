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
1.各个容器底层的数据结构  链式哈希表O(1)   
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
/*
有序关联容器
底层数据结构： 红黑树O(log2n)
在对于自定义类型使用set时，需要提供"<"运算符重载函数
而在使用map表时，则不用提供"<"运算符重载函数，它是用key值来排序的
*/
class Student
{
public:

	Student(int id = 0, string name = "")
		:_id(id)
		,_name(name)
	{ }
	//bool operator<(const Student& stu)const
	//{
	//	return _id < stu._id;
	//}
	friend ostream& operator<<(ostream& out, const Student& stu);
private:
	int _id;
	string _name;
};
ostream& operator<<(ostream& out, const Student& stu)
{
	out << "id:" << stu._id << " name:" << stu._name << endl;
	return out;
}
int main()
{
	/*
	set<int>set1;
	for (int i = 0; i < 20; ++i)
	{
		set1.insert(rand() % 20 + 1);
	}
	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;
	
	multiset<Student>set1;
	set1.insert(Student(1020, "张雯"));
	set1.insert(Student(1000, "李广"));
	set1.insert(Student(1020, "张雯"));
	for (auto it = set1.begin(); it != set1.end(); ++it)
	{
		cout << *it << endl;
	}
	*/
	map<int, Student>stuMap;
	stuMap.insert({ 1000,Student(1000,"张雯") });
	stuMap.insert({ 1020,Student(1020,"李广") });
	stuMap.insert({ 1030,Student(1030,"高洋") });

	//删除：stuMap.erase(it)  stuMap.erase(1020)
	//查询：
	//stuMap[key]
	cout << stuMap[1020] << endl;
	auto it = stuMap.find(1030);
	cout << "key:" << it->first << " value:" << it->second << endl;
	//迭代器：
	for (auto it = stuMap.begin(); it != stuMap.end(); ++it)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	return 0;
}
#endif

//4.容器的迭代器iterator
#if 0
/*
====》常量正向迭代器：const_iterator
只能读不能写
const_iterator                           <=                   iterator
		|                                                                      |
class const iterator{};基类          <=               class itreator:public const_iterator{};派生类
class const_iterator
{
public:
	const T& operator*(){ return *_ptr ; }
};
class iterator
{
public:
	T& operator*(){ return *_ptr ; }
};
====》普通正向迭代器：iterator
可读可写
====》常量反向迭代器：const_reverse_iterator
与常量正向迭代器同理
====》普通反向迭代器  reverse_iterator
可读可写
*/
int main()
{
	//正向迭代器
	vector<int>vec;
	for (int i = 0; i < 20; ++i)
	{
		vec.push_back(rand() % 100);
	}
	//标准写法：
	//vector<int>::iterator it1 = vec.begin();
	//简写法： 
	//auto it1 = vec.begin();  //可读可写的正向迭代器
	vector<int>::const_iterator it1 = vec.begin();//只读迭代器
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";
		//if (*it1 % 2 == 0)
		//{
		//	*it1 = 0;
		//}
	}
	cout << endl;
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	//反向迭代器
	//rbegin():返回的时最后一个元素的反向迭代器表示
	//rend():返回的是首元素前驱位置的迭代器的表示
	//普通反向迭代器：可读可写
	//标准写法：
	//vector<int>::reverse_iterator rit = vec.rbegin();
	//简写：
	//auto rit = vec.rbegin();
	//常量反向迭代器
	vector<int>::const_reverse_iterator rit = vec.rbegin();
	for (; rit != vec.rend(); ++rit)
	{
		cout << *rit << " ";
		//if (*rit % 2 == 0)
		//{
		//	*rit = 0;
		//}
	}
	cout << endl;
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << endl;
	return 0;
}
#endif

//5.函数对象
#if 0
/*
拥有（）小括号运算符重载函数的对象，称作函数对象或者仿函数
即就是C语言里面的函数指针。
小括号运算符重载函数中，参数有两个，叫做二元函数对象，参数有1个，叫做一元函数对象。
函数对象的好处：
1.通过函数对象调用operator()，可以省略函数的调用，比通过函数指针调用函数(不能inline内联调用)效率高
2.因为函数对象是用类生成的，所以可以添加相关的成员变量，用来记录对象使用时更多的信息。

问题：如何解决比较时需求改变的问题？
使用C语言函数指针解决方案：
template<typename T>
bool mygreater(T a, T b)
{
	return a > b;
}
template<typename T>
bool myless(T a, T b)
{
	return a < b;
}
*/
//使用C++函数对象解决方案：
template<typename T>
class mygreater
{
public:
	bool operator()(T a, T b)
	{
		return a > b;
	}
};
template<typename T>
class myless
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};
//compare是C++的库函数模板
template<typename T, typename Compare>
bool compare(T a, T b,Compare comp)
{
	//通过函数指针调用函数，是没有办法内敛的，效率很低，因为有函数调用开销
	return comp(a,b);//
}
int main()
{
	//cout << compare(10, 20, mygreater<int>) << endl;
	//cout << compare(10, 20, myless<int>) << endl;
	cout << compare(10, 20,mygreater<int>()) << endl;
	cout << compare(10, 20, myless<int>()) << endl;
	return 0;
}
//使用函数对象的示例1：
int main()
{
	priority_queue<int>que;//vector
	for (int i = 0; i < 10; ++i)
	{
		que.push(rand() % 100);
	}
	while (!que.empty())
	{
		cout << que.top() << " ";
		que.pop();
	}
	cout << endl;

	priority_queue<int, vector<int>, greater<int>>que1;
	for (int i = 0; i < 10; ++i)
	{
		que1.push(rand() % 100);
	}
	while (!que1.empty())
	{
		cout << que1.top() << " ";
		que1.pop();
	}
	cout << endl;
	return 0;
}
//使用函数对象的示例2：
int main()
{
	multiset<int>set1;
	for (int i = 0; i < 10; ++i)
	{
		set1.insert(rand() % 100 );
	}
	for (int v : set1)
	{
		cout << v << " ";
	}
	cout << endl;

	multiset<int, greater<int>>set2;
	for (int i = 0; i < 10; ++i)
	{
		set2.insert(rand() % 100);
	}
	for (int v : set2)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
#endif

//6.泛型算法和