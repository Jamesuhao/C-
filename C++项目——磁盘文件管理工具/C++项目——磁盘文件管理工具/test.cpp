#include"MD5.h"
#include"fileutil.h"
#include"fileManage.h"
#include"fileManageTool.h"
#include<iostream>
using std::cout;
using std::endl;
void testHex()
{
	MD5 md5;
	uint32 n = 0x23456789;
	cout << md5.changHex(n) << endl;
}
void testGetStringMD5()
{
	MD5 md5;
	std::string str = "vhjg";
	cout << md5.getStringMD5(str) << endl;
	md5.reset();
	std::string str1 = "123";
	cout << md5.getStringMD5(str1) << endl;
}
void testFileMD5()
{
	MD5 md5;
	const char* filepath1 = "md5test2.txt";
	const char* filepath2 = "D:\\C++\\操作系统\\分区分配算法(双链表)\\分区分配算法(双链表)\\Debug\\link.13980.read.1.tlog";
	md5.reset();
	cout << md5.getFileMD5(filepath1) << endl;
	md5.reset();
	cout << md5.getFileMD5(filepath2) << endl;

}
void testSearch()
{
	std::string path;
	cout << "please input search dir：" << endl;
	getline(std::cin, path);
	std::unordered_set<std::string>subFiles;
	searchDir(path, subFiles);
	for (const auto& f : subFiles)
	{
		cout << f << endl;
	}
}
void testFM()
{
	FileManager fm;
	std::string path = "D:\\C++\\操作系统";
	fm.scannerDir(path);
}
void menu()
{
	cout << "*********************************************************"  << endl;
	cout << "1：scanner            2：show  all            3：show copy" << endl;
	cout << "4：delete name      5：delete md5         6：delete all" << endl;
	cout << "7：delete matched   0：eixt" << endl;
	cout << "*********************************************************" << endl;
}
void testFileManageTool()
{
	FileManageTool fmt;
	int input;
	do
	{
		menu();
		std::string garbage;
		cout << "请输入选项：" << endl;
		cin >> input;
		getline(cin, garbage);
		switch (input)
		{
		case 1:
			fmt.scanner();
			break;
		case 2:
			fmt.showAllFile();
			break;
		case 3:
			fmt.showCopy();
			break;
		case 4:
			fmt.deleteByName();
			break;
		case 5:
			fmt.deleteByMD5();
			break;
		case 6:
			fmt.deleteAllCopy();
			break;
		case 7:
			fmt.deleteFuzzMatchCopy();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input != 0);
}
int main()
{
	//testHex();
	//testGetStringMD5();
	//testFileMD5();
	//testSearch();
	//testFM();
	testFileManageTool();
	return 0;
}