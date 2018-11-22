#include "global.h"

Global::Global()
{

}

pthread_mutex_t Global::sMutex=PTHREAD_MUTEX_INITIALIZER;

QStandardItemModel* Global::model=new QStandardItemModel();

QStringList Global::tableTitleLabels = QObject::trUtf8("IP地址,请求文件,响应状态码,请求时间").simplified().split(",");

QStandardItem* Global::item=0;

int Global::i=0;
