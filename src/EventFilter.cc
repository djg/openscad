#include "EventFilter.h"

EventFilter::EventFilter(QObject *parent)
    : QObject(parent)
{}

bool EventFilter::eventFilter(QObject *obj, QEvent *event) {
    // Handle Apple event for opening files, only available on OS X
    if (event->type() == QEvent::FileOpen) {
        QFileOpenEvent *foe = static_cast<QFileOpenEvent *>(event);
        const QString &filename = foe->file();
        if (LaunchingScreen *ls = LaunchingScreen::getDialog()) {
            // We need to invoke the method since, apparently, we receive
            // this event in another thread.
            QMetaObject::invokeMethod(ls, "openFile", Qt::QueuedConnection,
                                      Q_ARG(QString, filename));
        }
        else {
            scadApp->requestOpenFile(filename);
        }
        return true;
    } else {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}
