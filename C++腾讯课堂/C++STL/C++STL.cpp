/*
C++ STL  standard template libaray ��׼ģ���
һ����׼������ C++11 array forwaord_list
1.˳������
vector
deque
list
2.����������
stack
queue
priority_queue
3.��������
�����������--->��ʽ��ϣ�� ��ɾ��O(1)
unordered_set ���ؼ���
unordered_multiset   ���ؼ���
unordered_map   ����ӳ���
unordered_multimap  ����ӳ���
�����������--->����� ��ɾ��O(log2n)  2�ǵ���(���Ĳ��������ĸ߶�)
set
multiset
map
multimap
����������
���顢string��bitset(λ����)
����������
iterator��const iterator
reverse_iterator��const_reverse_iterator
�ġ���������
greater,less
�塢�����㷨
sort,find,find_if,binary_search,for_each
*/
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<list>
#include<stack>//stack
#include<queue>//queue��priority_queue(���ȼ�����)
//ʹ�������������������ͷ�ļ�
#include<set>//set multiset
#include<map>//map miltimap
//ʹ�������������������ͷ�ļ�
#include<unordered_set>
#include<unordered_map>
#include<string>
//1.˳��������
#if 0
/*

list:��������
�ײ����ݽṹ��˫��ѭ������ pre data next
list<int>mylist;
���ӣ�
mylist.push_back();��ĩβ���Ԫ�أ�ʱ�临�Ӷ�O(1)
mylist.push_front();���ײ����Ԫ�أ�ʱ�临�Ӷ�O(1)
mylist.insert(it,20);itָ���λ�����Ԫ�أ�ʱ�临�Ӷ�O(1)  ��

ɾ����
mylist.pop_back():��ĩβɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
mylist.pop_front();���ײ�ɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
mylist.earse();��itָ���λ��ɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)

�����н���insert/earse������ʱ����Ҫ����һ��query��ѯ����������������˵����ѯ������Ч�ʲ����ߡ�
��ѯ��
iterator(������insert��eraseһ��Ҫ���ǵ�����ʧЧ������)
���÷�����
size()
empty()
reverse():listԤ���ռ��   ֻ�������ײ㿪��ָ����С���ڴ�ռ䣬����������µ�Ԫ��
resize():���������õ�  �����������ײ㿪��ָ����С���ڴ�ռ䣬��������µ�Ԫ��0
swap()��������������Ԫ��
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
deque:˫�˶�������
�ײ����ݽṹ����̬���ٵĶ�ά���顣
���ݷ�ʽ��һά�����2��ʼ����2���ķ�ʽ�������ݣ�ÿ�����ݺ�ԭ���ڶ�ά�����飬���µĵ�һά������±�oldsize/2��ʼ��ţ�
               ���¶�Ԥ����ͬ�Ŀոۣ�����֧��deque����βԪ����ӡ�
deque<int>deq;
���ӣ�
deq.push_back();��ĩβ���Ԫ�أ�ʱ�临�Ӷ�O(1)
deq.push_front();���ײ����Ԫ�أ�ʱ�临�Ӷ�O(1)
deq.insert(it,20);itָ���λ�����Ԫ�أ�ʱ�临�Ӷ�O(N)

ɾ����
deq.pop_back():��ĩβɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
deq.pop_front();���ײ�ɾ��Ԫ�أ�ʱ�临�Ӷ�O(1)
deq.earse();��itָ���λ��ɾ��Ԫ�أ�ʱ�临�Ӷ�O(N)

��ѯ��
iterator(������insert��eraseһ��Ҫ���ǵ�����ʧЧ������)

���÷�����
size()
empty()
resize():���������õ�  �����������ײ㿪��ָ����С���ڴ�ռ䣬��������µ�Ԫ��0
swap()��������������Ԫ��
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
vector:��������
��ʼʱ����������û�п��ٿռ�ģ�ֻ�е��������ݵĲ���ʱ�ŻῪ������ռ�
�ײ����ݽṹ����̬���ٵ����飬ÿ����ԭ���ռ��С��2���������ݵ�
���������ص�����±���������
vector<int>vec;
���ӣ�
vec.push_back(20);ĩβ���Ԫ��,��ʱ�ᵼ������                                ʱ�临�Ӷ� O(1)
vec.insert(it,20);it������ָ���λ�����һ��Ԫ��20����ʱ�ᵼ������  ʱ�临�Ӷ�O(N)
ɾ����
vec.pop_back()��ĩβɾ��Ԫ��                                                           ʱ�临�Ӷ�O(1)
vec.erase(it);ɾ��itָ��λ�õ�Ԫ�أ�                                                   ʱ�临�Ӷ�O(N)
��ѯ��
operator[]���±���������vec[]                                                        ʱ�临�Ӷ�O(1)
iterator���������б���
find,for_each
foreach===>ͨ��iterator��ʵ�ֵ�

ע�⣺���������������������ɾ������(insert/earse),һ��Ҫ���µ�����������һ��insert/erase��ɺ󣬵�������ʧЧ��
���÷������ܣ�
size()
empty()
reserve(20):vectorԤ���ռ��   ֻ�������ײ㿪��ָ����С���ڴ�ռ䣬����������µ�Ԫ��
resize():���������õ�  �����������ײ㿪��ָ����С���ڴ�ռ䣬��������µ�Ԫ��0
swap()��������������Ԫ��
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
		//[]:vector��operator[]��������غ���
		cout << vec[i] << " ";
	}
	cout << endl;
	//��vec���������е�ż��ȫ��ɾ��
	auto it2 = vec.begin();
	while (it2 != vec.end())
	{
		if (*it2 % 2 == 0)
		{
			//����ɾ��ʱΪ��ֹ������ʧЧ����Ҫ���µ�����it2��λ��
			it2 = vec.erase(it2);
		}
		else
		{
			++it2;
		}
	}
	//ͨ������������vector����
	auto it1 = vec.begin();
	for (; it1 != vec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	//��vector���������е�����ǰ�涼���һ��С������1��ż��
	for (it1 = vec.begin(); it1 != vec.end(); ++it1)
	{
		if (*it1 % 2 == 1)
		{
			//��������ʱΪ��ֹ������ʧЧ����Ҫ���µ�����it1��λ��
			it1 = vec.insert(it1, *it1 - 1);
			++it1;
		}
	}
	//ͨ����Χfor����vector����
	for (auto a:vec)
	{
		cout << a << " ";
	}
	cout << endl;
	return 0;
}
/*
�ܽ�
vector���ص㣺��̬���飬�ڴ�ʱ�����ģ�2���ķ�ʽ��������; Ĭ�϶���vector<int>vecʱ���䲢û�п����ڴ棬ֻ�е����в������ʱ���ŻῪʼ����0-1-2-4-8...�����ݣ�reserve()����Ԥ���ռ䣬����ʼ��Ԫ��
deque�ص㣺��̬���ٵĶ�ά����ռ䣬�ڶ�ά�ǹ̶����ȵ�����ռ䣬���ݵ�ʱ��(��һά��������ж�������)

deque�ײ��ڴ��Ƿ��������ģ�
�𣺲����ǣ�ÿһ���ڶ�ά�������ģ�ÿһ���ڶ�ά������new������

vector��deque֮�������
1.�ײ����ݽṹ��
2.ǰ�к����ɾ��Ԫ�ص�ʱ�临�Ӷȣ�ĩβ����O(1)���ж���O(N)��ǰdeque O(1)��vector O(N)��
3.�����ڴ��ʹ��Ч��:vector��Ҫ���ڴ�ռ������������  deque���Էֿ�������ݴ洢������Ҫ�ڴ�ռ������һƬ������
4.���м����insert����earseʱ��vector��deque���ǵ�Ч��˭�ܺ�һ��(vector)��˭�ܲ�һ��(deque)��
����deque�ĵڶ�ά�ڴ�ռ䲻�������ģ���������deque�м����Ԫ�ص�insert��erase�����Ԫ���ƶ���ʱ���vectorҪ��

vector��list֮�������
���飺����ɾ��O(N)  ��ѯO(N)  �������O(1)
������������������ʱ�䣩����ɾ��O(1)   ��ѯO(N)
1.�ײ����ݽṹ��vector(����)��list(˫��ѭ������)
*/
#endif

//2.��׼���� - ���������� => ���ģʽ֮һ ����������
#if 0
/*
1.�������ײ�û���Լ������ݽṹ����������һ�������ķ�װ�����ķ���ȫ���ɵײ���������������ʵ�ֵ�
2.û��ʵ���Լ��ĵ�����
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

stack��push��ջ     pop��ջ    top�鿴ջ��Ԫ��     empty�ж�ջ��     size
queue��push���   pop����     front�鿴��ͷԪ��   back�鿴��βԪ�� empty�ж϶ӿ� size���ض���Ԫ�صĸ���
stack => deque   Ϊʲô������vector?
queue => deque  Ϊʲô������vector��
1.vector�ĳ�ʼ�ڴ�ʹ��Ч��̫���ˣ�û��deque�á�queue<int> stack<int> ��ʼ�ڴ�vector 0-1-2-4-8 deque 4096/sizeof(int)=1024.��ʼʱ��deque���ݲ��ϵ�ȥ����
2.����queue��˵����Ҫ֧��β�����룬ͷ��ɾ����deque��������ʱ�临�Ӷȶ���O(1)����vector��ͷ������ʱ�临�Ӷ���O(N),���queue����vector������Ч�ʺܵ�
3.vector��Ҫ��Ƭ�������ڴ棬��dequeֻ��Ҫ�ֶε��ڴ棬���洢��������ʱ����Ȼdeque�����ڴ�������ʸ���һЩ

priority_queue��push���       pop����    top�鿴�Ӷ�Ԫ��     empty�ж϶ӿ�     size����Ԫ�ظ���  Ĭ�ϣ������
priority_queue => vector    Ϊʲô������vector����������deque��
priority_queue�ײ�Ĭ�ϰ��������һ������ѽṹ��
��һ���ڴ������������Ϲ���һ������ѻ���С����(���еĽ��������Һ��ӵĹ�ϵ��ͨ���±�����)
�����Ϳ���ͨ���±�����������һ���������ڴ�ռ䣬��deque�ĵڶ�ά�ǲ������ġ�
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

//3.��������
#if 0
/*
�����������
1.���������ײ�����ݽṹ  ��ʽ��ϣ��O(1)    �����O(log2n)
2.������ɾ�鷽��:
���ӣ�insert(val)
������iterator�Լ�����������find��Ա����
ɾ����erase(key)  erase(it)
*/
int main()
{

	/*
	set
	*/
	unordered_set<int>set1;//����洢keyֵ�ظ���Ԫ��
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

	set1.erase(20); //��Keyֵɾ��Ԫ��
	for (it1 = set1.begin(); it1 != set1.end();)
	{
		if (*it1 == 30)
		{
			it1 = set1.erase(it1); //����erase��it1��������ʧЧ��
		}
		else
			++it1;
	}
	it1 = set1.find(20);
	if (it1 != set1.end())
	{
		set1.erase(it1);
	}
	//��Χfor���
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
	map��operator[]:
	V& operator(const K &key)
	{
		insert( { key, V( ) } );
	}
	���ܣ�
	1.��ѯ
	2.���key�����ڣ��������һ������[key,string()]
	*/
	unordered_map<int, string>map1;
	//map������Ԫ��
	map1.insert(make_pair(1000, "����"));
	map1.insert({ 1010,"����" });
	map1.insert({ 1020,"����" });
	map1.insert({ 1030,"����" });
	//map��ɾ��Ԫ��
	map1.erase(1020);//{ 1020,"����" }ɾ����
	auto it1 = map1.find(1030);
	if (it1 != map1.end())
	{
		//it1->pair����
		cout << "key��" << it1->first << "value��" << it1->second << endl;
	}
	cout << map1.size() << endl;
	//map1[2000];//������key = 2000������string�Ĺ��캯������һ���յĶ��󣬲��Ҳ���key=2000���Ԫ��
	map1[2000] = "��˶";//�൱��һ����ӹ���map1.insert( { 2000, "��˶"} )��
	map1[1000] = "����2";//�൱��һ���޸ĵĹ���
	cout << map1.size() << endl;

	//ʹ��[]��������غ�����ѯԪ��
	//map operator[](key)==>val
	cout << map1[1000] << endl;

	/*
	set��mapʹ�ó�����
	���������ݲ��ظ���ȥ�ظ���ʱ��
	*/
	const int ARR_LEN = 100;
	int arr[ARR_LEN] = { 0 };
	for (int i = 0; i < ARR_LEN; ++i)
	{
		arr[i] = rand() % 20+ 1;
	}

	//���أ�
	//�����10���������ͳ����Щ�����ظ��ˣ�����ͳ�������ظ��Ĵ���
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
	//��Χfor����
	/*for (auto &p : map1)
	{
		if (p.second > 1)
		{
			cout << "key:" << p.first << "  count:" << p.second << endl;
		}
	}*/
	//����������
	auto it1 = map1.begin();
	for (; it1 != map1.end(); ++it1)
	{
		if (it1->second > 1)
		{
			cout << "key:" << it1->first << "  count:" << it1->second << endl;
		}
	}

	//ȥ�أ�
	//�����10��������У������ֽ���ȥ�ش�ӡ
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