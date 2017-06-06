#ifndef PARTIEDIALOG_H
#define PARTIEDIALOG_H

#include<QString>
#include <QDialog>

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

    void on_radioButtonF_clicked();

    void on_radioButtonI_clicked();

    void on_radioButtonD_clicked();

private:
    Ui::partieDialog *ui;
    int level;
    QString name;
};

#endif // PARTIEDIALOG_H
