#include "StatisticsThread.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include<stdlib.h>
#include <windows.h>
#include <fstream>
#include <io.h>
#include <QFileInfo>

StatisticsThread::StatisticsThread(QObject *parent)
	: QThread(parent)
{
	_validTypes.insert(".h");
	_validTypes.insert(".cpp");
	_validTypes.insert(".c");
	_validTypes.insert(".hpp");
	_validTypes.insert(".py");
	_validTypes.insert(".txt");
	_validTypes.insert(".cs");
	_validTypes.insert(".css");
	_validTypes.insert(".js");
	_validTypes.insert(".lua");
	_validTypes.insert(".html");
	_validTypes.insert(".htm");
	_validTypes.insert(".java");
	_validTypes.insert(".bat");
	_validTypes.insert("makefile");
}

StatisticsThread::~StatisticsThread()
{

}

void StatisticsThread::run()
{
	_mapAllCountLine.clear();
	for (int i = 0; i < _vecFilePath.size(); i++)
	{
		_mapCountLine.clear();
		StatisticCodeLines(_vecFilePath[i]);
		_mapAllCountLine[_vecFilePath[i]] = _mapCountLine;
		emit statisticeCount((double)(i + 1) / (double)_vecFilePath.size() * 100);
	}
	
}

const std::map<std::string, std::map<std::string, int>> StatisticsThread::getAllCountLineMap()
{
	return _mapAllCountLine;
}

void StatisticsThread::setFilePathVec(std::vector<std::string> vecFilePath)
{
	_vecFilePath = vecFilePath;
}

void StatisticsThread::StatisticCodeLines(const std::string &directoryPath)
{
	_vecfilesName.clear();
	QFileInfo fileInfo(QString::fromLocal8Bit(directoryPath.c_str()));
	if (fileInfo.isDir())
	{
		GetFilesFromDirectory(_vecfilesName, directoryPath.c_str());
	}
	else
	{
		_vecfilesName.push_back(directoryPath);
	}
	for (const std::string &fileName : _vecfilesName)
	{
		std::string fileExtention = GetFileExtention(fileName);
		if (!IfFileTypeValid(fileExtention)){ continue; }
		_mapCountLine[fileExtention] += GetFileLines(fileName);
	}
}

void StatisticsThread::GetFilesFromDirectory(std::vector<std::string> &files, const char *directoryPath)
{
	struct _finddata_t fileinfo;
	long hFile = 0;
	char tmpPath[MAX_PATH] = { 0 };
	sprintf_s(tmpPath, "%s\\*", directoryPath);
	if ((hFile = _findfirst(tmpPath, &fileinfo)) == -1){ return; }
	do
	{
		if ((fileinfo.attrib &  _A_SUBDIR))
		{
			if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
			{
				sprintf_s(tmpPath, "%s\\%s", directoryPath, fileinfo.name);
				GetFilesFromDirectory(files, tmpPath);
			}
		}
		else
		{
			sprintf_s(tmpPath, "%s\\%s", directoryPath, fileinfo.name);
			files.push_back(tmpPath);
		}
	} while (_findnext(hFile, &fileinfo) == 0);
	_findclose(hFile);
}

std::string StatisticsThread::GetFileExtention(const std::string &fileName)
{
	std::string localFileName = fileName;
	StringToLower(localFileName);
	int pos = localFileName.find_last_of('.');
	if (pos >= 0)
	{
		return localFileName.substr(pos);
	}
	return localFileName;
}

void StatisticsThread::StringToLower(std::string &str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 'a' - 'A';
		}
	}
}

bool StatisticsThread::IfFileTypeValid(const std::string &fileExtention)
{
	return _validTypes.find(fileExtention) != _validTypes.end();
}

int StatisticsThread::GetFileLines(const std::string &fileName)
{
	const int maxBufLen = 10240;
	static char buf[maxBufLen + 1];
	std::ifstream inFile(fileName, std::ios::in);
	if (!inFile){ return 0; }
	int counter = 0;
	while (!inFile.eof())
	{
		memset(buf, 0, maxBufLen);
		inFile.read(buf, maxBufLen);
		counter += CalculateCharShowTimesInBuf(buf, maxBufLen, '\n');
	}
	return counter;
}

int StatisticsThread::CalculateCharShowTimesInBuf(char buf[], const int len, char aim)
{
	int i = 0, counter = 0;
	while (i < len && buf[i] != '\0')
	{
		if (buf[i] == aim){ ++counter; }
		++i;
	}
	return counter;
}