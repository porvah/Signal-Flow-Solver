#include "../../headers/widgets/workspace.h"

WorkspaceWidget::WorkspaceWidget()
{
    workspaceLayout = new QHBoxLayout();
    outputWidget = new OutputWidget();
    workspaceLayout->addWidget(outputWidget, 0, Qt::AlignRight);
    this->setLayout(workspaceLayout);
}

WorkspaceWidget::~WorkspaceWidget()
{

}
