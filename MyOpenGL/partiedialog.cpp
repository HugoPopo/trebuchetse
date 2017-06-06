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

void partieDialog::on_radioButtonFacile_clicked()
{
    level=1;
}

void partieDialog::on_radioButtonMoyen_clicked()
{
    level=2;
}


void partieDialog::on_radioButtonDifficile_clicked()
{
    level=3;
}

void partieDialog::on_closepushButton_clicked()
{
    close();
}
