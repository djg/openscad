#pragma once

#include <QObject>
#include <QFileOpenEvent>
#include "OpenSCADApp.h"
#include "launchingscreen.h"

class EventFilter : public QObject
{
	Q_OBJECT;
	
public:
	EventFilter(QObject *parent);
protected:
	bool eventFilter(QObject *obj, QEvent *event);
};
