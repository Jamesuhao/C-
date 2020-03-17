#include"MD5.h"
#include<math.h>
#include<iostream>
#include<fstream>
//初始化static成员
int MD5::_ringShiftLeft[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };
MD5::MD5()
{
	init();
}
void MD5::init()
{
	//初始化k[i]
	for (int i = 0; i < 64; ++i)
	{
		_k[i] = static_cast<uint32>(abs(sin(i + 1)) * pow(2, 32));
	}
	reset();
}
void MD5::reset()
{
	//初始化A、B、C、D
	_atemp = 0x67452301;
	_btemp = 0xefcdab89;
	_ctemp = 0x98badcfe;
	_dtemp = 0x10325476;
	//初始化chunk
	memset(_chunk, 0, CHUNK_BYTE);
	//初始化填充信息
	_lastDataByte = 0;
	_totalByte = 0;
}
void MD5::calMD5(uint32* chunk)
{
	int a = _atemp;
	int b = _btemp;
	int c = _ctemp;
	int d = _dtemp;
	int f, g;
	//4byte为一个处理单元，共执行64次操作
	for (int i = 0; i < 64; ++i)
	{
		//位运算：F,G,H,I
		//0-15：F
		if (i >= 0 && i <= 15)
		{
			g = i;
			f = F(b, c, d);
		}
		//16-31：G
		else if (i >= 16 && i <= 31)
		{
			g = (5 * i + 1) % 16;
			f = G(b, c, d);
		}
		//32-47：H
		else if (i >= 32 && i <= 47)
		{
			g = (3 * i + 5) % 16;
			f = H(b, c, d);
		}
		//48-64：I
		else
		{
			g = (7 * i) % 16;
			f = I(b, c, d);
		}
		//a,b,c,d更新      加法：+循环左移
		int tmp = d;
		d = c;
		c = b;
		b = b + ringShiftLeft((a + f + chunk[g] + _k[i]), _ringShiftLeft[i]);
		a = tmp;
	}		
	//更新A、B、C、D
	_atemp += a;
	_btemp += b;
	_ctemp += c;
	_dtemp += d;
}
//进行填充，在进行MD5计算
void MD5::calFinalMd5()
{
	//获取第一个待填充的位置
	char* p = _chunk + _lastDataByte;
	//首先填充1byte的冗余信息：1000 0000
	*p++ = 0x80;
	uint32 lastDataByte = CHUNK_BYTE - _lastDataByte - 1;
	//不够存放数据长度，先处理剩余bit位，在构建一个新的bit位，前448bit位填0，剩余64bit位填原始数据长度
	if (lastDataByte < 8)
	{		
		memset(p, 0, lastDataByte);
		calMD5((uint32*)_chunk);
		//先将所有位全部填为0
		memset(_chunk, 0, CHUNK_BYTE);
	}
	else
	{
		memset(p, 0, lastDataByte);
	}
	//给数据块最后64位填充原始信息长度
	unsigned long long totalBits = _totalByte;
	totalBits *= 8;
	((unsigned long long*)_chunk)[7] = totalBits;
	calMD5((uint32*)_chunk);
}
std::string MD5:: changHex(uint32 n)
{
	static std::string strMap = "0123456789abcdef";
	std::string ret;
	//获取每一个字节的数据
	for (int i = 0; i < 4; ++i)
	{
		//获取一个字节的数据
		int curByte = (n >> (i * 8)) & 0xff;
		//数据转成16进制字符
		std::string curRet;
		//除16模16
		curRet += strMap[curByte / 16];//获取高位
		curRet += strMap[curByte % 16];//获取低位
		ret += curRet;//字节之间逆序
	}	
	return ret;
}
std::string MD5::getStringMD5(const std::string& str)
{
	if (str.empty())
	{
		return changHex(_atemp).append(changHex(_btemp)).append(changHex(_ctemp)).append(changHex(_dtemp));
	}
	_totalByte = str.size();
	uint32 chunkNum = _totalByte / CHUNK_BYTE;
	const char* strPtr = str.c_str();
	for (uint32 i = 0; i < chunkNum; ++i)
	{
		memcpy(_chunk, strPtr + i * CHUNK_BYTE, CHUNK_BYTE);
		calMD5((uint32*)_chunk);
	}
	_lastDataByte = _totalByte % CHUNK_BYTE;
	memcpy(_chunk, strPtr + chunkNum * CHUNK_BYTE, _lastDataByte);
	calFinalMd5();
	return changHex(_atemp).append(changHex(_btemp)).append(changHex(_ctemp)).append(changHex(_dtemp));
}
std::string MD5::getFileMD5(const char* filePath)
{
	std::ifstream fin(filePath,std::ifstream::binary);
	if (!fin.is_open())
	{
		std::cout << filePath << std::endl;
		perror("file open failed!");
		return "";
	}
	/*
	//1.全部读进来：seekg,tellg获取文件大小：空间换时间，时间效率高
	fin.seekg(0, fin.end);
	uint32 length = fin.tellg();
	fin.seekg(0, fin.beg);
	char* totalData = new char[length];
	fin.read(totalData, length);
	uint32 chunkNum = length / CHUNK_BYTE;
	for (int i = 0; i < chunkNum; ++i)
	{
		memcpy(_chunk, totalData + i * CHUNK_BYTE, CHUNK_BYTE);
		calMD5((uint32*)_chunk);
	}
	_lastDataByte = length % CHUNK_BYTE;
	memcpy(_chunk, totalData + chunkNum * CHUNK_BYTE, _lastDataByte);
	calFinalMd5();
	*/
	while (!fin.eof())
	{
		//2.每次只读取一块数据：时间换空间
		fin.read(_chunk, CHUNK_BYTE);
		//判断是否读取到64个字节的内容
		if (CHUNK_BYTE != fin.gcount())
		{
			//说明为最后一块数据
			break;
		}
		_totalByte += CHUNK_BYTE;
		calMD5((uint32*)_chunk);
	}
	_lastDataByte = fin.gcount();
	_totalByte += _lastDataByte;
	calFinalMd5();
	return changHex(_atemp).append(changHex(_btemp)).append(changHex(_ctemp)).append(changHex(_dtemp));	
}