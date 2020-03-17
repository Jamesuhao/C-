#include"fileManage.h"
#include"fileManageTool.h"
void FileManageTool::scanner()
{
	cout << "请输入要扫描的文件夹：" << endl;
	std::string path;
	getline(cin, path);
	_fm.scannerDir(path);
}
void FileManageTool::deleteByMD5()
{
	cout << "请输入要删除文件的MD5值：" << endl;
	std::string md5;
	cin >> md5;
	_fm.deleteByMD5(md5);
}
void FileManageTool::deleteByName()
{
	cout << "请输入要删除的文件名：" << endl;
	std::string filename;
	getline(cin, filename);
	_fm.deleteByName(filename);
}
void FileManageTool::deleteAllCopy()
{
	_fm.deleteAllCopy();
}
//删除模糊匹配副本
void FileManageTool::deleteFuzzMatchCopy()
{
	cout << "请输入匹配文件名：" << endl;
	std::string match;
	getline(cin, match);
	_fm.deleteByMatchName(match);
}
void FileManageTool::showCopy()
{
	_fm.showCopyList();
}
void FileManageTool::showAllFile()
{
	_fm.showAllFile();
}