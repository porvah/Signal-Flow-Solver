#ifndef VALIDATION_DIALOG_H
#define VALIDATION_DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>

class ValidationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ValidationDialog(QWidget* parent = nullptr);

    void setLabelText(QString text);

private:
    QLabel* label;
};

#endif // VALIDATION_DIALOG_H
