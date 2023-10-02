
#ifndef ERROR_H
#define ERROR_H


#include <QWidget>

namespace Ui{
  class ErrorDialog;
}

class Error : public QWidget
{
    Q_OBJECT
public:
    explicit Error(QWidget *parent = nullptr);
    ~Error();
    Ui::ErrorDialog* errorImage;

signals:


};

#endif // ERROR_H
