#pragma once
#include<unordered_set>
#include<string>
#include<iostream>
#include<io.h>
void searchDir(const std::string& path, std::unordered_set<std::string>& subFiles);

void deleteFile(const char* filename);