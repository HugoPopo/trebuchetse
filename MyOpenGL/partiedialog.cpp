#include "partiedialog.h"
#include "ui_partiedialog.h"
#include <QDebug>

partieDialog::partieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::partieDialog)
{
    ui->setupUi(this);
}

partieDialog::~partieDialog()
{
    delete ui;
}

QString partieDialog::getName()
{
    return ui->lineEditNom->text();
}


int partieDialog::getDifficulty()
{
    return level;
}


void partieDialog::on_radioButtonF_clicked()
{
    level=1;
}

void partieDialog::on_radioButtonI_clicked()
{
    level=2;
}

void partieDialog::on_radioButtonD_clicked()
{
    level=3;
}
