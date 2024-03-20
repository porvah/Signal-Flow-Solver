#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QToolBar>

class ToolBarWidget : public QWidget
{
    Q_OBJECT
public:
    ToolBarWidget();
    ~ToolBarWidget();
    QToolBar* getPtr();
private:
    QToolBar* toolbar;
    void setupToolbar();
};

#endif
