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
    void handleLogin(QString id, QString email, QString password);
    void handleSignUp(QString username, QString age, QString email, QString address, QString password, QString paymentDate, QString phone, QString duration, QString gender, QString userType);
    void setActiveSection(QPushButton* activeBtn, const QString& logoColor);
    void setNotActiveSection() ;
    void setButtonStyle(QPushButton* button, const QString& backgroundColor);
    void setPixmapForWidgets();
    QString getUserType();
    QString getGender();
    QString getSubscriptionDuration();
    void navigateBasedOnUserType(QString userType);
    void loadClassesFromFile();
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
    void on_tableWidget_cellEntered(int row, int column);
    void on_Dashboardbtn_3_clicked();
    void on_GymMangbtn_3_clicked();
    void on_TMbtn_3_clicked();
    void on_Aubtn_3_clicked();
    void on_Dashboard_11_clicked();
    void on_Notibtn_3_clicked();
    void on_Billbtn_3_clicked();
    void on_ProfileBtn_3_clicked();
    void on_SettingBtn_3_clicked();
    void on_LogOutBtn_3_clicked();
    void on_SignUp_clicked();
    void on_toggleButton_3_clicked();
    void on_Dashboard_15_clicked();
    void on_Dashboard_13_clicked();
    void on_Dashboard_16_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
