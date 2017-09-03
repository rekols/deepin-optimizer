#include "load_page.h"

LoadPage::LoadPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    label = new QLabel("Loading...");

    QFont font;
    font.setPointSize(12);
    label->setFont(font);

    QStringList seq;
    for (int i(1); i != 91; ++i)
        seq.append(QString(":/images/Spinner/Spinner%1.png").arg(i, 2, 10, QChar('0')));

    view = new DPictureSequenceView(this);
    view->setPictureSequence(seq);
    view->setFixedSize(50, 50);
    view->setSpeed(30);

    layout->addStretch();
    layout->addWidget(view, 0, Qt::AlignCenter);
    layout->addSpacing(5);
    layout->addWidget(label, 0, Qt::AlignCenter);
    layout->addStretch();
}

void LoadPage::play()
{
    view->play();
}
