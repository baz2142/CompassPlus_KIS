#ifndef MARKSVIEW_HPP
#define MARKSVIEW_HPP

#include <QWidget>

namespace Ui {
class MarksView;
}

class MarksView : public QWidget
{
    Q_OBJECT

public:
    explicit MarksView(QWidget *parent = 0);
    ~MarksView();

private:
    Ui::MarksView *ui;
};

#endif // MARKSVIEW_HPP
