#ifndef GAIN_INPUT_DIALOG_H
#define GAIN_INPUT_DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDoubleSpinBox>

class GainInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GainInputDialog(QWidget* parent = nullptr);

    void clearField();
    double getGain();

private:
    QDoubleSpinBox* gainField;
};

#endif // GAIN_INPUT_DIALOG_H
