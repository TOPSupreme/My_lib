
#include "error.h"
#include "ui_error.h"
#include <QPixmap>

Error::Error(QWidget *parent)
    : QWidget{parent},
    errorImage(new Ui::ErrorDialog)
{
    QPixmap error_image(":/game_resources/error(1).png");
    errorImage->error_image->setPixmap(error_image);
}

Error::~Error()
{
    delete errorImage;
}

