#include"fileManage.h"
#include"fileManageTool.h"
void FileManageTool::scanner()
{
	cout << "������Ҫɨ����ļ��У�" << endl;
	std::string path;
	getline(cin, path);
	_fm.scannerDir(path);
}
void FileManageTool::deleteByMD5()
{
	cout << "������Ҫɾ���ļ���MD5ֵ��" << endl;
	std::string md5;
	cin >> md5;
	_fm.deleteByMD5(md5);
}
void FileManageTool::deleteByName()
{
	cout << "������Ҫɾ�����ļ�����" << endl;
	std::string filename;
	getline(cin, filename);
	_fm.deleteByName(filename);
}
void FileManageTool::deleteAllCopy()
{
	_fm.deleteAllCopy();
}
//ɾ��ģ��ƥ�丱��
void FileManageTool::deleteFuzzMatchCopy()
{
	cout << "������ƥ���ļ�����" << endl;
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