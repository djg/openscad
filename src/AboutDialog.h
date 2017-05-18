#pragma once

#include "openscad.h"
#include "qtgettext.h"
#include "ui_AboutDialog.h"

class AboutDialog : public QDialog, public Ui::AboutDialog
{
	Q_OBJECT;
public:
	AboutDialog(QWidget *);

public slots:
        void on_okPushButton_clicked() { accept(); }
};
