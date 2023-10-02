
#ifndef FAILURE_H
#define FAILURE_H


#include <QWidget>

namespace Ui{
class FailurePanel;
}

class Failure : public QWidget
{
    Q_OBJECT
public:
    explicit Failure(QWidget *parent = nullptr);
    ~Failure();
    Ui::FailurePanel* failpanel;
signals:

};

#endif // FAILURE_H
