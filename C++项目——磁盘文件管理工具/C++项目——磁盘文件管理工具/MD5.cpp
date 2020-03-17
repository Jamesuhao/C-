#include"MD5.h"
#include<math.h>
#include<iostream>
#include<fstream>
//��ʼ��static��Ա
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
	//��ʼ��k[i]
	for (int i = 0; i < 64; ++i)
	{
		_k[i] = static_cast<uint32>(abs(sin(i + 1)) * pow(2, 32));
	}
	reset();
}
void MD5::reset()
{
	//��ʼ��A��B��C��D
	_atemp = 0x67452301;
	_btemp = 0xefcdab89;
	_ctemp = 0x98badcfe;
	_dtemp = 0x10325476;
	//��ʼ��chunk
	memset(_chunk, 0, CHUNK_BYTE);
	//��ʼ�������Ϣ
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
	//4byteΪһ������Ԫ����ִ��64�β���
	for (int i = 0; i < 64; ++i)
	{
		//λ���㣺F,G,H,I
		//0-15��F
		if (i >= 0 && i <= 15)
		{
			g = i;
			f = F(b, c, d);
		}
		//16-31��G
		else if (i >= 16 && i <= 31)
		{
			g = (5 * i + 1) % 16;
			f = G(b, c, d);
		}
		//32-47��H
		else if (i >= 32 && i <= 47)
		{
			g = (3 * i + 5) % 16;
			f = H(b, c, d);
		}
		//48-64��I
		else
		{
			g = (7 * i) % 16;
			f = I(b, c, d);
		}
		//a,b,c,d����      �ӷ���+ѭ������
		int tmp = d;
		d = c;
		c = b;
		b = b + ringShiftLeft((a + f + chunk[g] + _k[i]), _ringShiftLeft[i]);
		a = tmp;
	}		
	//����A��B��C��D
	_atemp += a;
	_btemp += b;
	_ctemp += c;
	_dtemp += d;
}
//������䣬�ڽ���MD5����
void MD5::calFinalMd5()
{
	//��ȡ��һ��������λ��
	char* p = _chunk + _lastDataByte;
	//�������1byte��������Ϣ��1000 0000
	*p++ = 0x80;
	uint32 lastDataByte = CHUNK_BYTE - _lastDataByte - 1;
	//����������ݳ��ȣ��ȴ���ʣ��bitλ���ڹ���һ���µ�bitλ��ǰ448bitλ��0��ʣ��64bitλ��ԭʼ���ݳ���
	if (lastDataByte < 8)
	{		
		memset(p, 0, lastDataByte);
		calMD5((uint32*)_chunk);
		//�Ƚ�����λȫ����Ϊ0
		memset(_chunk, 0, CHUNK_BYTE);
	}
	else
	{
		memset(p, 0, lastDataByte);
	}
	//�����ݿ����64λ���ԭʼ��Ϣ����
	unsigned long long totalBits = _totalByte;
	totalBits *= 8;
	((unsigned long long*)_chunk)[7] = totalBits;
	calMD5((uint32*)_chunk);
}
std::string MD5:: changHex(uint32 n)
{
	static std::string strMap = "0123456789abcdef";
	std::string ret;
	//��ȡÿһ���ֽڵ�����
	for (int i = 0; i < 4; ++i)
	{
		//��ȡһ���ֽڵ�����
		int curByte = (n >> (i * 8)) & 0xff;
		//����ת��16�����ַ�
		std::string curRet;
		//��16ģ16
		curRet += strMap[curByte / 16];//��ȡ��λ
		curRet += strMap[curByte % 16];//��ȡ��λ
		ret += curRet;//�ֽ�֮������
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
	//1.ȫ����������seekg,tellg��ȡ�ļ���С���ռ任ʱ�䣬ʱ��Ч�ʸ�
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
		//2.ÿ��ֻ��ȡһ�����ݣ�ʱ�任�ռ�
		fin.read(_chunk, CHUNK_BYTE);
		//�ж��Ƿ��ȡ��64���ֽڵ�����
		if (CHUNK_BYTE != fin.gcount())
		{
			//˵��Ϊ���һ������
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