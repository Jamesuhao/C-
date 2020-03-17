#pragma once
#include"MD5.h"
#include"fileutil.h"
#include<string>
#include<unordered_set>
#include<unordered_map>
class FileManager
{
private:
	//�����ظ����ļ�
	MD5 _md5;
	std::unordered_set<std::string>_files;
	//      files     ---->   md5
	std::unordered_map < std::string, std::string > _filestoMD5;
	//      md5   ----->   files
	std::unordered_multimap<std::string, std::string>_md5toFiles;
public:
	void scannerDir(const std::string& path);
	void getMD5toFiles();
	void getCopyList();
	void deleteByName(const std::string& name);
	void deleteByMD5(const std::string& md5);
	void deleteAllCopy();
	//ɾ�����а������ļ������ļ��ĸ���
	void deleteByMatchName(const std::string& matchName);
	void showCopyList();
	void deleteByMD5V2(const std::string& md5);
	void showAllFile();
	//void showMD5Map();
};
