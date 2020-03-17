#pragma once
#include<iostream>

typedef unsigned int uint32;
#define CHUNK_BYTE 64

class MD5
{
private:
	static int _ringShiftLeft[CHUNK_BYTE];//循环左移的位数
	uint32  _k[CHUNK_BYTE]; //k[i]
	char _chunk[CHUNK_BYTE];//数据块：64byte

	//填充变量
	uint32 _lastDataByte;//最后一块数据的字节数
	uint32 _totalByte;//总字节数

	//MD5信息
	uint32 _atemp;
	uint32 _btemp;
	uint32 _ctemp;
	uint32 _dtemp;
public:
	MD5();
	//四个变换函数，F,G,H,I
	/*
	F(x,y,z) = (x & y) | ((~x) & z)
	G(x,y,z) = (x & z) | ( y & (~z))
	H(x,y,z) = x ^ y ^ z
	I(x,y,z) = y ^ (x | (~z))
	*/
	uint32 F(uint32 b, uint32 c, uint32 d)
	{
		return (b & c) | ((~b) & d);
	}
	uint32 G(uint32 b, uint32 c, uint32 d)
	{
		return (b & d) | (c & (~d));
	}
	uint32 H(uint32 b, uint32 c, uint32 d)
	{
		return b ^ c ^ d;
	}
	uint32 I(uint32 b, uint32 c, uint32 d)
	{
		return c ^ (b | (~d));
	}
	//循环左移
	//shift((a + F + k[i] + chunk[g]), _ringShiftLeft[i])
	uint32 ringShiftLeft(uint32 number, int shiftNumber)
	{
		return (number << shiftNumber) | (number >> (32 - shiftNumber));
	}
	void init();//初始化MD5信息函数
	void reset();//重置函数
	void calMD5(uint32* chunk);//一个chunk的MD5运算
	void calFinalMd5();//最后一块数据的填充
	std::string changHex(uint32 n);//将4个整型值转换位16进制字符串
	std::string getStringMD5(const std::string& str);
	std::string getFileMD5(const char* filePath);
};
//不能在这里对static静态成员初始化：因为如果多个.cpp文件包含这个头文件的话，会出现该变量重定义
 /*int MD5:: _ringShiftLeft[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };*/