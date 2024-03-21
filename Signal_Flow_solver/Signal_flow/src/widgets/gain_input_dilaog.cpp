#include "../../headers/widgets/gain_input_dialog.h"

GainInputDialog::GainInputDialog(QWidget* parent)
    : QDialog(parent)
{
    // The title of the window
    setWindowTitle("Gain");
    // Styling the dialog
    setStyleSheet(
        "QDialog {"
        "   background-color: #cacaca;"
        "   border: 1px solid #999999;"
        "   border-radius: 5px;"
        "   width: 60px;"
        "}"
        "QLabel {"
        "   color: black;"
        "   font-weight: bold;"
        "}"
    );

    // The main layout of the dialog
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel("Enter the gain:", this);
    label->setAlignment(Qt::AlignLeft);
    layout->addWidget(label);

    gainField = new QDoubleSpinBox(this);
    gainField->setRange(-1000000.0, 1000000);
    layout->addWidget(gainField);

    // Button Layout to make row of buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    // Buttons
    QPushButton* enterButton = new QPushButton("Enter", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(enterButton);

    connect(cancelButton, &QPushButton::clicked, this, &GainInputDialog::reject);
    connect(enterButton, &QPushButton::clicked, this, &GainInputDialog::accept);

    layout->addLayout(buttonLayout);
    setLayout(layout);

    // Constraints of the window size
    setMinimumWidth(300);
    setMaximumWidth(350);

    setMinimumHeight(100);
    setMaximumHeight(150);
}

void GainInputDialog::clearField()
{
    gainField->clear();
}

double GainInputDialog::getGain()
{
    return gainField->value();
}
