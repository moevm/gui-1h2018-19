#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();

    QString dataFolder();
    void setDataFolder(const QString &value);

private slots:
    void on_butDataFolder_clicked();

    void on_edDataFolder_textEdited(const QString &arg1);

private:
    Ui::OptionsDialog *ui;
};

#endif // OPTIONSDIALOG_H
