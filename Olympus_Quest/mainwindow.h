#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool isLogin = true;
    void handleLogin(QString email, QString password);
    void handleSignUp(QString email, QString password);
    void setActiveSection(QPushButton* activeBtn, const QString& logoColor);
    void setNotActiveSection() ;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_toggleButton_clicked();

    void on_Dashboardbtn_clicked();

    void on_GymMangbtn_clicked();

    void on_TMbtn_clicked();

    void on_Aubtn_clicked();

    void on_Dashboard_5_clicked();

    void on_Notibtn_clicked();

    void on_Billbtn_clicked();

    void on_ProfileBtn_clicked();

    void on_SettingBtn_clicked();

    void on_LogOutBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
