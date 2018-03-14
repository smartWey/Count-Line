#ifndef STATISTICSTHREAD_H
#define STATISTICSTHREAD_H

#include <QThread>
#include <set>

class StatisticsThread : public QThread
{
	Q_OBJECT

public:
	StatisticsThread(QObject *parent);
	~StatisticsThread();

	void run();
	const std::map<std::string, std::map<std::string, int>> getAllCountLineMap();
	void setFilePathVec(std::vector<std::string> vecFilePath);
	void StatisticCodeLines(const std::string &directoryPath);
	void GetFilesFromDirectory(std::vector<std::string> &files, const char *directoryPath);
	std::string GetFileExtention(const std::string &fileName);
	void StringToLower(std::string &str);
	bool IfFileTypeValid(const std::string &fileExtention);
	int GetFileLines(const std::string &fileName);
	int CalculateCharShowTimesInBuf(char buf[], const int len, char aim);

signals:
	void statisticeCount(int count);

private:
	std::map<std::string, std::map<std::string, int>> _mapAllCountLine;			//����·���µ�����
	std::map<std::string, int> _mapCountLine;									//һ���ļ����µ�����
	std::vector<std::string> _vecFilePath;										//·���б�
	std::vector<std::string> _vecfilesName;										//·�����ļ���
	std::set<std::string> _validTypes;											//�ļ�����
	
};

#endif // STATISTICSTHREAD_H
