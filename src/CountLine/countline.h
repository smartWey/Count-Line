#ifndef COUNTLINE_H
#define COUNTLINE_H

#include <QtWidgets/QMainWindow>
#include "ui_countline.h"
#include "StatisticsThread.h"
#include <QMenu>

class CountLine : public QMainWindow
{
	Q_OBJECT

public:
	CountLine(QWidget *parent = 0);
	~CountLine();

	void allCountLineSum();

public slots:
	void on_pushButton_add_clicked();
	void on_pushButton_count_clicked();
	void onProgressLabel(int iProgress);
	void onDeleteActionTrigger();
	void onClearActionTrigger();
	void on_tableWidget_filePath_customContextMenuRequested(QPoint);

private:
	QMenu* _pRightMenu;
	QAction* _pDeleteAction;
	QAction* _pClearAction;
	StatisticsThread* _pStatisticsThread;
	std::vector<std::string> _vecFilePath;
	std::map<std::string, int> _mapCountLine;									//合计
	std::map<std::string, std::map<std::string, int>> _mapAllCountLine;				//统计结果

private:
	Ui::CountLineClass ui;
};

#endif // COUNTLINE_H
