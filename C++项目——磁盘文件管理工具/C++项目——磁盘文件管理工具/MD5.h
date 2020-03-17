#pragma once
#include<iostream>

typedef unsigned int uint32;
#define CHUNK_BYTE 64

class MD5
{
private:
	static int _ringShiftLeft[CHUNK_BYTE];//ѭ�����Ƶ�λ��
	uint32  _k[CHUNK_BYTE]; //k[i]
	char _chunk[CHUNK_BYTE];//���ݿ飺64byte

	//������
	uint32 _lastDataByte;//���һ�����ݵ��ֽ���
	uint32 _totalByte;//���ֽ���

	//MD5��Ϣ
	uint32 _atemp;
	uint32 _btemp;
	uint32 _ctemp;
	uint32 _dtemp;
public:
	MD5();
	//�ĸ��任������F,G,H,I
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
	//ѭ������
	//shift((a + F + k[i] + chunk[g]), _ringShiftLeft[i])
	uint32 ringShiftLeft(uint32 number, int shiftNumber)
	{
		return (number << shiftNumber) | (number >> (32 - shiftNumber));
	}
	void init();//��ʼ��MD5��Ϣ����
	void reset();//���ú���
	void calMD5(uint32* chunk);//һ��chunk��MD5����
	void calFinalMd5();//���һ�����ݵ����
	std::string changHex(uint32 n);//��4������ֵת��λ16�����ַ���
	std::string getStringMD5(const std::string& str);
	std::string getFileMD5(const char* filePath);
};
//�����������static��̬��Ա��ʼ������Ϊ������.cpp�ļ��������ͷ�ļ��Ļ�������ָñ����ض���
 /*int MD5:: _ringShiftLeft[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10,
15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };*/