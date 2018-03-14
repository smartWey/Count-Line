#ifndef SELECTMULTIFOLDERS_H
#define SELECTMULTIFOLDERS_H

#include <QFileDialog>

class SelectMultiFolders : public QFileDialog
{
	Q_OBJECT

public:
	SelectMultiFolders(QObject *parent);
	~SelectMultiFolders();

public:
	explicit SelectMultiFolders(QWidget *parent = 0);

public slots :
	void on_clicked_btn_open();
	
};

#endif // SELECTMULTIFOLDERS_H
