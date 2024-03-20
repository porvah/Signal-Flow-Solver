#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QWidget>
#include <QLayout>
#include "../../headers/widgets/output.h"

class WorkspaceWidget : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout *workspaceLayout;
    OutputWidget *outputWidget;

public:
    WorkspaceWidget();
    ~WorkspaceWidget();
};

#endif
