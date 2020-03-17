#include"fileManage.h"
#include"MD5.h"
#include"fileutil.h"
#include<iostream>
void FileManager::scannerDir(const std::string& path)
{
	//����
	_files.clear();
	searchDir(path,_files);
	//std::cout << "all file" << std::endl;
	//showAllFile();
	getMD5toFiles();
	//showCopyList();
	getCopyList();
	//std::cout << "copy list" << std::endl;
	//showCopyList();
	//showAllFile();
}
void FileManager::getMD5toFiles()
{
	_md5toFiles.clear();
	int count = 0;
	for (const auto& f : _files)
	{
		_md5.reset();//�������ļ�֮ǰҪ����
		//std::cout << _md5.getFileMD5(f.c_str()) << std::endl;
		//++count;
		_md5toFiles.insert(make_pair(_md5.getFileMD5(f.c_str()), f));
	}
}
//ֻ�����ظ��ļ��Ľ��
void FileManager::getCopyList()
{
	_filestoMD5.clear();
	//�����÷�Χfor�����ɾ����������Ҫ���µ�����
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		//����ÿһ��md5��Ӧ�������ļ����
		if (_md5toFiles.count(it->first) > 1)
		{
			//equal_range  ����ֵ��pair<beginIt,endIt>:[beginIt,endIt)
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second)
			{
				//ֻ����ظ��ļ���ӳ���ϵ
				_filestoMD5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//��һ����ͬ��MD5ֵ����ʼλ��
			it = pairIt.second;
		}
		else
		{
			_files.erase(it->second);
			it = _md5toFiles.erase(it);
		}
	}
}
void FileManager::deleteByName(const std::string& name)
{
	if (_filestoMD5.count(name) == 0)
	{
		std::cout << name << "not exist!" << std::endl;
		return;
	}
	std::string curMD5 = _filestoMD5[name];
	std::cout << name << "----->" << _md5toFiles.count(curMD5) << std::endl;	
	auto pairIt = _md5toFiles.equal_range(curMD5);
	auto curIt = pairIt.first;
	int count = 0;
	while (curIt != pairIt.second)
	{
		if (curIt->second != name)
		{
			_files.erase(curIt->second);
			_filestoMD5.erase(curIt->second);
			deleteFile(curIt->second.c_str());
			++count;
		}
		++curIt;
	}
	curIt = pairIt.first;
	while (curIt != pairIt.second)
	{
		if (curIt->second != name)
		{
			_md5toFiles.erase(curIt);
			pairIt = _md5toFiles.equal_range(curMD5);
			curIt = pairIt.first;
		}
		++curIt;
	}
	std::cout << "delete files��" << count << std::endl;
}
void FileManager::deleteByMD5(const std::string& md5)
{
	//md5   ---->   files
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	//Ҫ����һ�ݣ�������һ���ļ�
	auto pairIt = _md5toFiles.equal_range(md5);
	std::cout << md5 << "----->" << _md5toFiles.count(md5) << std::endl;
	auto curIt = pairIt.first;
	++curIt;
	int count = 0;
	while (curIt != pairIt.second)
	{
		_files.erase(curIt->second);
		_filestoMD5.erase(curIt->second);
		//���ļ��Ӵ�����ɾ��
		deleteFile(curIt->second.c_str());
		++count;
		++curIt;
	}
	//����md5--->files
	curIt = pairIt.first;
	++curIt;
	//erase(first,last) --->ɾ������ֵ[first,last)
	_md5toFiles.erase(curIt, pairIt.second);
	std::cout << "delete files��" << count << std::endl;
}
void FileManager::deleteByMD5V2(const std::string& md5)
{
	//md5   ---->   files
	if (_md5toFiles.count(md5) == 0)
	{
		std::cout << md5 << "not exist!" << std::endl;
		return;
	}
	auto it = _md5toFiles.find(md5);
	deleteByName(it->second);
}
//ÿ���ظ����ļ�ֻ����һ��
void FileManager::deleteAllCopy()
{
	std::unordered_set<std::string>md5set;
	//�ҳ������ļ���md5ֵ
	for (const auto& p : _md5toFiles)
	{
		md5set.insert(p.first);
	}
	for (const auto& md5 : md5set)
	{
		deleteByMD5(md5);
	}
}
//ɾ�����а������ļ������ļ��ĸ���
void FileManager::deleteByMatchName(const std::string& matchName)
{
	std::unordered_set<std::string>allFiles;
	for (const auto& f : _files)
	{
		if (f.find(matchName) != std::string::npos)
		{
			allFiles.insert(f);
		}
	}
	for (const auto& f : allFiles)
	{
		if (_filestoMD5.count(f) != 0)
		{
			deleteByName(f);
		}
	}
}
void FileManager::showCopyList()
{
	auto it = _md5toFiles.begin();
	int total = _md5toFiles.size();
	int count = 0;
	while (it != _md5toFiles.end())
	{
		//md5ֵ��ͬ����ʾ��һ��
		int idx = 1;
		auto paitIt = _md5toFiles.equal_range(it->first);
		auto curIt = paitIt.first;
		std::cout << "cur MD5��" << it->first << std::endl;
		while (curIt != paitIt.second)
		{
			std::cout << "\t��" << idx << "���ļ���";
			std::cout << curIt->second << std::endl;
			++curIt;
			++idx;
			count++;
		}
		it = paitIt.second;
	}
	std::cout << "�ļ�������" << total << "\t" << count << std::endl;
}
void FileManager::showAllFile()
{
	for (const auto& f : _files)
	{
		std::cout << f << std::endl;
	}
	std::cout << "file count��" << _files.size() << std::endl;
}