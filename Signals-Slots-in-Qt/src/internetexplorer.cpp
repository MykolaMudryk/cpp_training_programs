#include "../include/internetexplorer.h"
#include <QDebug>

InternetExplorer::InternetExplorer(QObject *parent)
    : QObject{parent}
{
    m_timer.setInterval(5000);
    m_timer.setSingleShot(true);

    connect(this, &InternetExplorer::browseRequsted, &m_timer, qOverload<>(&QTimer::start));
    connect(&m_timer, &QTimer::timeout, this, &InternetExplorer::browse);
}

void InternetExplorer::browse()
{
    qDebug() << "Internet explorer is not responding...";
}

