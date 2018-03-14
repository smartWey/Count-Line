#pragma once

#include <vector>
#include <string>
#include <list>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

#  ifdef Dll_LIBRARY                                    // 重要:生成dll的工程属性中需要定义该宏;使用dll的工程,不能定义该宏
#    define EXPORT_SINFOTEK   __declspec(dllexport)
#  else
#    define EXPORT_SINFOTEK   __declspec(dllimport)
#  endif

/********************************************************************
* 创建时间:        2015-4-01
* 功能描述:        全局函数库
* 作者:            尚水研发部
*
* version：       v1.1.2.0 2015-12-15
* 历史修改信息:  
*               6.版本：v1.1.2 2015-12-22
*                 修改时间：2015-12-22 18:21
*                 修改者：纪红军
*                 修改说明：
*                     增加文件、文件夹的先关操作函数

*               5.版本：v1.1.2 2015-12-15
*                 修改时间：2015-12-15 15:21
*                 修改者：纪红军
*                 修改说明：
*                     增加获取文件夹中指定后缀的文件名称的函数findFilesByExtension
*
*               4.版本：v1.1.1 2015-11-20
*                 修改时间：2015-11-20 18:44
*                 修改者：纪红军
*                 修改说明：
*                     修改字符串转数值类函数，使其可以自动去掉字符中前面的占位符0
*                     增加了std::string extractNumber(const std::string& str)函数
*
*               3.版本：v1.1.0 2015-07-24
*                 修改时间：2015-07-24 09:21
*                 修改者：纪红军
*                 修改说明：增加以下函数
*                 1）std::wstring stdString2StdWstring(const std::string &str);
*                 2）std::string stdWstring2StdString(const std::wstring &wstr);
*                 3）std::string GetLocalIpAddress();
*
*               2.版本：v1.0.1 2015-07-03
*                 修改时间：2015-07-03 15:00
*                 修改者：纪红军
*                 修改说明：增加std::string int2StdString(int iValue, unsigned int iWidth);
*
*               1.版本：v1.0.1 2015-04-30
*                 修改时间：2015-04-30 14:00
*                 修改者：彭高领
*                 修改说明：基于公司以往函数成果进行全局函数库的整理
*
*********************************************************************/

namespace Sinfotek
{
    // 类型转换
    EXPORT_SINFOTEK int stdString2Int(const std::string &str);                                // string转为int
    EXPORT_SINFOTEK bool stdString2Int(const std::string &str, int &iReturn);                 // string转为int
    EXPORT_SINFOTEK double stdString2Double(const std::string &str);                          // string转为double
    EXPORT_SINFOTEK bool stdString2Double(const std::string &str, double &dReturn);           // string转为double
    EXPORT_SINFOTEK void stdString2StdWstring(const std::string &str, std::wstring &wstr);    // string转为wstring
    EXPORT_SINFOTEK std::wstring stdString2StdWstring(const std::string &str);                // string转为wstring
    EXPORT_SINFOTEK void stdWstring2StdString(const std::wstring &wstr, std::string &str);    // wstring转为string
    EXPORT_SINFOTEK std::string stdWstring2StdString(const std::wstring &wstr);               // wstring转为string
    EXPORT_SINFOTEK std::string double2StdString(double dValue, unsigned int precision = 6);  // double转为string，带有效位
    EXPORT_SINFOTEK std::string int2StdString(int iValue);                                    // int转为string  15 -> 15
    EXPORT_SINFOTEK std::string int2StdString(int iValue, unsigned int iWidth);               // int转为string  15 -> 0015

    // 字符串操作
    EXPORT_SINFOTEK std::vector<std::string> split(const std::string &strSource, const std::string &divKey);    // 分解字符串
    EXPORT_SINFOTEK std::string trimString(const std::string &strSource, const std::string &strTrim);           // 删除字符串中特定的字符串
    EXPORT_SINFOTEK std::string extractNumber(const std::string& str);                                          // 从str中提取出第一个完整的数字,"0739.16Kg/m3"输出739.16,"speed:-0.24m/s"输出-0.24.
    EXPORT_SINFOTEK std::string eatFrontAndRearSpace(const std::string &strInput);                              // 删除字符串的前、后空格 "  kj dk  " →"kj dk"
    // 字符串大小写转换
    EXPORT_SINFOTEK std::string stdString2Upper(const std::string &str);            // string转为大写的string
    EXPORT_SINFOTEK std::string stdString2Lower(const std::string &str);            // string转为小写的string

    // 时间相关的操作
    EXPORT_SINFOTEK bool time_t2SystemTime(const time_t &time, SYSTEMTIME &sysTime);        // 将时间转换为系统时间的类型
    EXPORT_SINFOTEK time_t systime2Time_t(const SYSTEMTIME &st);                            // 将系统时间转换为time_t
    EXPORT_SINFOTEK SYSTEMTIME systemTimeAddOrSubtract(const SYSTEMTIME &systemtime, const double& dSecond);     // 加减法函数,参数为秒数
    EXPORT_SINFOTEK std::string systemTime2FileName(const SYSTEMTIME &sysTime);             // 将系统时间转换为形如：2012-01-03 23-56-45的格式
    EXPORT_SINFOTEK std::string systemTime2DataString(const SYSTEMTIME &sysTime);           // 将系统时间转换为形如：2012-01-03 23:56:45.123的格式
    EXPORT_SINFOTEK std::string time_t2StdString(const time_t &timet);                      // 将时间转换为形如：133060998的格式(时间总秒数)
    EXPORT_SINFOTEK std::string time_t2DataTimeString(const time_t &timet);                 // 将时间转换为形如：2012-01-03 23:56:45.123的格式
    EXPORT_SINFOTEK std::string time_t2FileString(const time_t &timet);                     // 将时间转换为形如：2012-01-03 23-56-45的格式
    EXPORT_SINFOTEK std::string getSystemTimeHMS(std::string str = ":");                    // 获取特殊格式的时间
    EXPORT_SINFOTEK std::string getSystemDataYMD();                                         // 输出形如：2013-02-06格式的时间字符串
    EXPORT_SINFOTEK std::string getSystemDataTime();                                        // 输出形如： 2013-02-06 15:13:11格式的时间字符串
    EXPORT_SINFOTEK std::string getSystemTimeShort();                                       // 获得系统时间 ,简介模式

    // bool相关的判断
    EXPORT_SINFOTEK bool isAlphaString(const std::string &str);                  // 判断字符串是否为英文字符
    EXPORT_SINFOTEK bool isDigitalString(const std::string &str);                // 判断是否全部为数字（包括判断正负，小数）
    EXPORT_SINFOTEK bool isFileExist(const std::string &strFullPath);            // 判断文件是否存在

    // 获取文件路径、文件夹路径及文件名等操作
    EXPORT_SINFOTEK std::string getFloderPath(const std::string &strFileFullPath);       // 获取文件完整路径（形参）的最后一级文件夹路径，含'/'或'\'
    EXPORT_SINFOTEK std::string getFileNameAndExtension(const std::string &strFullPath); // 获取文件全路径strFullPath对应文件包含后缀的文件名
    EXPORT_SINFOTEK std::string getFileName(const std::string &strFullPath);             // 获取文件全路径strFullPath对应文件不包含后缀的文件名
    EXPORT_SINFOTEK std::string getExeFloder(void);                                      // 获取本dll所在的文件夹路径
    EXPORT_SINFOTEK std::string getFileExtension(const std::string &strFilePath);        // 从文件路径中获取文件的后缀名

    // 文件、文件夹相关操作
    EXPORT_SINFOTEK bool createFolder(const std::string &strFolderFullPath);                                                // 根据参数路径，逐级创建文件夹
    
    EXPORT_SINFOTEK bool deleteFile(const std::string &strFilePath);                                                        // 删除文件
    EXPORT_SINFOTEK bool deleteFolder(const std::string &strFolderPath);                                                    // 删除文件夹或者文件    
    
    EXPORT_SINFOTEK bool copyFile(const std::string &strSourcePath, const std::string &strTargetPath);                      // 复制文件
    EXPORT_SINFOTEK bool copyFolder(const std::string &strSourceFloderPath, const std::string &strTargetFloderPath);        // 复制文件夹
   
    EXPORT_SINFOTEK bool moveFile(const std::string &strSourcePath, const std::string &strTargetPath);                      // 移动文件
    EXPORT_SINFOTEK bool moveFloder(const std::string &strSourceFloderPath, const std::string &strTargetFloderPath);                      // 移动文件
    
    EXPORT_SINFOTEK bool renameFileByName(const std::string &strSourceFilePath, const std::string &strNewFileName);                         // 文件重命名
    EXPORT_SINFOTEK bool renameFileByNameAndExtention(const std::string &strSourceFilePath, const std::string &strNewFileNameAndExtention); // 文件重命名
    EXPORT_SINFOTEK bool renameFolder(const std::string &strSourceFloderPath, const std::string & strNewFloderName);        // 复制文件夹
    
    EXPORT_SINFOTEK std::vector<std::string> findFilesByExtension(std::string strSourceFolder, std::string strExtendName);  // 获取指定文件夹中指定后缀的文件列表
    EXPORT_SINFOTEK bool deleteFilebyExtension(const std::string &folderPath,const std::string &fileExtension);             // 删除指定文件夹下某类型的文件

    // 获取本机IP地址
    EXPORT_SINFOTEK std::string GetLocalIpAddress();    
}