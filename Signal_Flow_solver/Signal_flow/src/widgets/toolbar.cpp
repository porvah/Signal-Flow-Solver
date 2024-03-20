#include "../../headers/widgets/toolbar.h"
#include <QToolBar>


ToolBarWidget::ToolBarWidget()
{
    QToolBar toolbarWidget = QToolBar(tr("tool bar"));
    toolbar = &toolbarWidget;

}

ToolBarWidget::~ToolBarWidget()
{

}

QToolBar* ToolBarWidget::getPtr()
{
    return toolbar;
}

void ToolBarWidget::setupToolbar()
{
    toolbar->setFloatable(false);
    toolbar->setMovable(false);

}
