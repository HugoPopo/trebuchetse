#ifndef PARTIEDIALOG_H
#define PARTIEDIALOG_H

#include<QString>
#include <QDialog>
//La classe partieDialog permet de modifier les infos du joueur et de choisir le niveau
namespace Ui {
class partieDialog;
}

class partieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit partieDialog(QWidget *parent = 0);
    ~partieDialog();
    QString getName();
    int getDifficulty();

private slots:

    void on_radioButtonFacile_clicked();

    void on_radioButtonMoyen_clicked();

    void on_radioButtonDifficile_clicked();

    void on_closepushButton_clicked();
private:
    Ui::partieDialog *ui;
    int level;
    QString name;
};

#endif // PARTIEDIALOG_H
