#include "selectmultifolders.h"  
#include <QDialogButtonBox>  
#include <QListView>  
#include <QTreeView>  

SelectMultiFolders::SelectMultiFolders(QWidget *parent) :
QFileDialog(parent)
{
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);
	this->setOption(QFileDialog::DontUseNativeDialog, true);
	//setFixedSize(g_MainWindow->_iWidth / 3, int(g_MainWindow->_iHeight / 2.5));

	//支持多选
	QListView *pListView = this->findChild<QListView*>("listView");
	if (pListView)
		pListView->setSelectionMode(QAbstractItemView::ExtendedSelection);

	QTreeView *pTreeView = this->findChild<QTreeView*>();
	if (pTreeView)
		pTreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
	QDialogButtonBox *btnbox = this->findChild<QDialogButtonBox*>("buttonBox");
	disconnect(btnbox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(btnbox, SIGNAL(accepted()), this, SLOT(on_clicked_btn_open()));
}

SelectMultiFolders::~SelectMultiFolders()
{

}

void SelectMultiFolders::on_clicked_btn_open()
{
	QDialog::accept();
}