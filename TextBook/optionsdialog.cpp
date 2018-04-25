#include "optionsdialog.h"
#include "ui_optionsdialog.h"
#include <QFileDialog>
#include <QDir>

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog)
{
    ui->setupUi(this);
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

QString OptionsDialog::dataFolder()
{
    return ui->edDataFolder->text();
}

void OptionsDialog::setDataFolder(const QString &value)
{
    ui->edDataFolder->setText(value);
}

void OptionsDialog::on_butDataFolder_clicked()
{
    QString currentDir = "";
    QDir dir(dataFolder());
    if (dir.exists())
        currentDir = dataFolder();
    QString folder = QFileDialog::getExistingDirectory(this, "Выберите папку", currentDir,
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (folder != "")
        setDataFolder(folder);
}

void OptionsDialog::on_edDataFolder_textEdited(const QString &arg1)
{
    QDir dir(arg1);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(dir.exists());
}
