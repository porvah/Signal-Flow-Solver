#include "../../headers/widgets/validation_dialog.h"

ValidationDialog::ValidationDialog(QWidget* parent)
    : QDialog(parent)
{
    // The title of the window
    setWindowTitle("Validation Dialog");
    // Styling the dialog
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

    // The main layout of the dialog
    QVBoxLayout* layout = new QVBoxLayout(this);
    label = new QLabel("", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    // Ok Button
    QPushButton* okButton = new QPushButton("OK", this);
    layout->addWidget(okButton);
    connect(okButton, &QPushButton::clicked, this, &ValidationDialog::accept);

    setLayout(layout);

    // Constraints of the window size
    setMinimumWidth(200);
    setMaximumWidth(250);

    setMinimumHeight(100);
    setMaximumHeight(150);
}

void ValidationDialog::setLabelText(QString text)
{
    label->setText(text);
}
