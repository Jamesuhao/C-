#pragma once
#include"fileManage.h"
#include<string>
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class FileManageTool
{
private:
	FileManager _fm;
public:
	void scanner();
	void deleteByMD5();
	void deleteByName();
	void deleteAllCopy();
	//ɾ��ģ��ƥ�丱��
	void deleteFuzzMatchCopy();
	void showCopy();
	void showAllFile();
};