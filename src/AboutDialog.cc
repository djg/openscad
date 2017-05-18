#include "AboutDialog.h"

AboutDialog::AboutDialog(QWidget *) {
    setupUi(this);
    this->setWindowTitle( QString(_("About OpenSCAD")) + " " + openscad_shortversionnumber.c_str());
    QString tmp = this->aboutText->toHtml();
    tmp.replace("__VERSION__", openscad_detailedversionnumber.c_str());
    this->aboutText->setHtml(tmp);
}
