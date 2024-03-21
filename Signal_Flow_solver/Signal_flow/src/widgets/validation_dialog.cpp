#include "../../headers/widgets/validation_dialog.h"

ValidationDialog::ValidationDialog(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Validation Dialog");
    setStyleSheet(
        "QDialog {"
        "   background-color: #cacaca;"
        "   border: 1px solid #999999;"
        "   border-radius: 5px;"
        "   width: 60px;"
        "}"
        "QLabel {"
        "   color: red;"
        "   font-weight: bold;"
        "}"
    );

    QVBoxLayout* layout = new QVBoxLayout(this);
    label = new QLabel("", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    setLayout(layout);

    setMinimumWidth(200);
    setMaximumWidth(250);

    setMinimumHeight(100);
    setMaximumHeight(150);
}

void ValidationDialog::setLabelText(QString text)
{
    label->setText(text);
}
