#include "countline.h"
#include "selectmultifolders.h"
#include <QMessageBox>

CountLine::CountLine(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.label_progress->setText(QString::fromLocal8Bit("空闲"));
	ui.label_progress->setAlignment(Qt::AlignCenter);
	ui.tableWidget_filePath->verticalHeader()->setHidden(true);
	ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
	ui.tableWidget_filePath->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_filePath->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_countLine->verticalHeader()->setHidden(true);
	ui.tableWidget_countLine->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	ui.tableWidget_filePath->setContextMenuPolicy(Qt::CustomContextMenu);

	_pRightMenu = new QMenu(ui.tableWidget_filePath);
	_pDeleteAction = new QAction(QString::fromLocal8Bit("删除"), _pRightMenu);
	_pClearAction = new QAction(QString::fromLocal8Bit("清空"), _pRightMenu);
	_pRightMenu->addAction(_pDeleteAction);
	_pRightMenu->addAction(_pClearAction);
	connect(_pDeleteAction, SIGNAL(triggered()), this, SLOT(onDeleteActionTrigger()));
	connect(_pClearAction, SIGNAL(triggered()), this, SLOT(onClearActionTrigger()));

	_pStatisticsThread = new StatisticsThread(this);
	connect(_pStatisticsThread, SIGNAL(statisticeCount(int)), this, SLOT(onProgressLabel(int)));
}

CountLine::~CountLine()
{

}

void CountLine::on_pushButton_add_clicked()
{
	QStringList listFilePath;
	SelectMultiFolders smfs;
	if (smfs.exec())
	{
		listFilePath = smfs.selectedFiles();
	}
	int iRow = ui.tableWidget_filePath->rowCount();
	for (int i = 0; i < listFilePath.size(); i++)
	{
		ui.tableWidget_filePath->setRowCount(++iRow);
		ui.tableWidget_filePath->setItem(iRow - 1, 0, new QTableWidgetItem(listFilePath.at(i)));
		ui.tableWidget_filePath->setItem(iRow - 1, 1, new QTableWidgetItem(""));
	}
	ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
}

void CountLine::on_pushButton_count_clicked()
{
	_vecFilePath.clear();
	for (int i = 0; i < ui.tableWidget_filePath->rowCount(); i++)
	{
		std::string strPath = ui.tableWidget_filePath->item(i, 0)->text().toLocal8Bit();
		_vecFilePath.push_back(strPath);
	}
	if (_vecFilePath.size() == 0)
	{
		QMessageBox::about(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("文件列表为空"));
		return;
	}
	_pStatisticsThread->setFilePathVec(_vecFilePath);
	_pStatisticsThread->start();
	setBtnEnable(false);
}

void CountLine::onProgressLabel(int iProgress)
{
	ui.label_progress->setText(QString::number(iProgress) + "%");
	if (iProgress == 100)
	{
		setBtnEnable(true);
		ui.label_progress->setText(QString::fromLocal8Bit("完成"));
		allCountLineSum();
		ui.tableWidget_countLine->clearContents();
		ui.tableWidget_countLine->setRowCount(0);
		int iRow = 0;
		for (std::map<std::string, int>::iterator itr = _mapCountLine.begin(); itr != _mapCountLine.end(); itr++)
		{
			ui.tableWidget_countLine->setRowCount(++iRow);
			ui.tableWidget_countLine->setItem(iRow - 1, 0, new QTableWidgetItem(QString::fromLocal8Bit(itr->first.c_str())));
			ui.tableWidget_countLine->setItem(iRow - 1, 1, new QTableWidgetItem(QString::number(itr->second)));
			ui.tableWidget_countLine->item(iRow - 1, 0)->setFlags(Qt::NoItemFlags);
			ui.tableWidget_countLine->item(iRow - 1, 0)->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget_countLine->item(iRow - 1, 1)->setTextAlignment(Qt::AlignCenter);
		}
	}
}

void CountLine::allCountLineSum()
{
	_mapCountLine.clear();
	_mapAllCountLine.clear();
	_mapAllCountLine = _pStatisticsThread->getAllCountLineMap();
	std::map<std::string, std::map<std::string, int>>::iterator itr = _mapAllCountLine.begin();
	for (; itr != _mapAllCountLine.end(); itr++)
	{
		for (std::map<std::string, int>::iterator itrLine = itr->second.begin(); itrLine != itr->second.end(); itrLine++)
		{
			_mapCountLine[itrLine->first] += itrLine->second;
		}
	}
}

void CountLine::onDeleteActionTrigger()
{
	ui.tableWidget_filePath->removeRow(ui.tableWidget_filePath->currentRow());
	if (ui.tableWidget_filePath->rowCount() == 0)
	{
		ui.tableWidget_countLine->clearContents();
		ui.tableWidget_countLine->setRowCount(0);
		ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
		ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
	}
}

void CountLine::onClearActionTrigger()
{
	ui.tableWidget_filePath->clearContents();
	ui.tableWidget_filePath->setRowCount(0);
	ui.tableWidget_countLine->clearContents();
	ui.tableWidget_countLine->setRowCount(0);
	ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_filePath->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Interactive);
}

void CountLine::on_tableWidget_filePath_customContextMenuRequested(QPoint pos)
{
	QPoint qpos = QCursor::pos();
	_pRightMenu->exec(qpos);
}

void CountLine::on_tableWidget_filePath_itemClicked(QTableWidgetItem *item)
{
	int iCurRow = ui.tableWidget_filePath->currentItem()->row();
	if (_mapAllCountLine.size() != 0)
	{
		std::map<std::string, std::map<std::string, int>>::iterator itrLine = _mapAllCountLine.find(ui.tableWidget_filePath->item(iCurRow, 0)->text().toLocal8Bit().data());
		if (itrLine != _mapAllCountLine.end())
		{
			ui.tableWidget_countLine->clearContents();
			ui.tableWidget_countLine->setRowCount(0);
			int iRow = 0;
			for (std::map<std::string, int>::iterator itr = itrLine->second.begin(); itr != itrLine->second.end(); itr++)
			{
				ui.tableWidget_countLine->setRowCount(++iRow);
				ui.tableWidget_countLine->setItem(iRow - 1, 0, new QTableWidgetItem(QString::fromLocal8Bit(itr->first.c_str())));
				ui.tableWidget_countLine->setItem(iRow - 1, 1, new QTableWidgetItem(QString::number(itr->second)));
				ui.tableWidget_countLine->item(iRow - 1, 0)->setFlags(Qt::NoItemFlags);
				ui.tableWidget_countLine->item(iRow - 1, 0)->setTextAlignment(Qt::AlignCenter);
				ui.tableWidget_countLine->item(iRow - 1, 1)->setTextAlignment(Qt::AlignCenter);
			}
		}
		else
		{
			ui.tableWidget_countLine->clearContents();
			ui.tableWidget_countLine->setRowCount(0);
		}
	}
}

void CountLine::setBtnEnable(bool bEnable)
{
	ui.pushButton_add->setEnabled(bEnable);
	ui.pushButton_count->setEnabled(bEnable);
	ui.tableWidget_filePath->setEnabled(bEnable);
	ui.tableWidget_countLine->setEnabled(bEnable);
}
