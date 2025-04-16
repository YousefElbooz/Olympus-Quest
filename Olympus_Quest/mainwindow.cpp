#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LogOutBtn->setStyleSheet(R"(
        QPushButton {
            background-color: transparent;
            color: black;
            font: 10pt "Yeasty Flavors";
            text-align: left;
            padding: 10px;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: #dcdcdc;
        }
        )");
    ui->FullWiedgit->setCurrentIndex(0);
    QPixmap pix("C:/Users/Yousef/Pictures/newGym.png");
    ui->label->setPixmap(pix);
    QPixmap logo("C:/Users/Yousef/Downloads/ChatGPT Image Apr 15, 2025, 10_53_31 PM.png");
    ui->logo->setPixmap(logo);
    QPixmap dashboardIcon("C:/Users/Yousef/Downloads/dashboard-svgrepo-com.svg");
    ui->DashBoardIcon->setPixmap(dashboardIcon);
    QPixmap gymmIcon("C:/Users/Yousef/Downloads/gym-dumbbell-svgrepo-com.svg");
    ui->GymManmentIcon->setPixmap(gymmIcon);
    QPixmap trainermIcon("C:/Users/Yousef/Downloads/group-of-businessmen-svgrepo-com.svg");
    ui->TrainerMangmentIcon->setPixmap(trainermIcon);
    QPixmap addUserIcon("C:/Users/Yousef/Downloads/add-user-svgrepo-com.svg");
    ui->AddUserIcon->setPixmap(addUserIcon);
    QPixmap adminIcon("C:/Users/Yousef/Downloads/user-admin-svgrepo-com.svg");
    ui->AdminIcon->setPixmap(adminIcon);
    QPixmap noti("C:/Users/Yousef/Downloads/notification-bell-1397-svgrepo-com.svg");
    ui->NotificattionIcon->setPixmap(noti);
    QPixmap bill("C:/Users/Yousef/Downloads/invoice-bill-svgrepo-com.svg");
    ui->BillingIcon->setPixmap(bill);
    QPixmap profile("C:/Users/Yousef/Downloads/profile-round-1342-svgrepo-com.svg");
    ui->BillingIcon_2->setPixmap(profile);
    QPixmap sett("C:/Users/Yousef/Downloads/setting-4-svgrepo-com.svg");
    ui->BillingIcon_3->setPixmap(sett);
    QPixmap logout("C:/Users/Yousef/Downloads/logout-svgrepo-com.svg");
    ui->BillingIcon_4->setPixmap(logout);


    QPixmap Dash_MemNom("C:/Users/Yousef/Downloads/profile-round-1342-svgrepo-com.svg");
    ui->TotalMemberIcon->setPixmap(Dash_MemNom);
    QPixmap NotIconDash("C:/Users/Yousef/Downloads/notification-bell-1397-svgrepo-com.svg");
    ui->NotificationDashIcon->setPixmap(NotIconDash);
    QPixmap sandClockIcon("C:/Users/Yousef/Downloads/sand-clock-svgrepo-com.svg");
    ui->SandClockICon->setPixmap(sandClockIcon);
    QPixmap sessionnumIcon("C:/Users/Yousef/Downloads/stretching-svgrepo-com.svg");
    ui->SessionICon->setPixmap(sessionnumIcon);
    QPixmap TrainerNUmIcon("C:/Users/Yousef/Downloads/coach-coaching-physical-trainer-svgrepo-com.svg");
    ui->TrainerNumICon->setPixmap(TrainerNUmIcon);
    QPixmap cashICon("C:/Users/Yousef/Downloads/money-bag-svgrepo-com.svg");
    ui->CashIcon->setPixmap(cashICon);
    QPixmap chartIcon("C:/Users/Yousef/Downloads/line-chart-up-02-svgrepo-com.svg");
    ui->Chart->setPixmap(chartIcon);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString email = ui->LineEditUserName->text().trimmed();
    QString password = ui->LineEditPassword->text();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please enter email and password.");
        return;
    }

    if (isLogin) {
        handleLogin(email, password);
    } else {
        handleSignUp(email, password);
    }
}


void MainWindow::handleSignUp(QString email, QString password) {
    QFile file("C:/Users/Yousef/Desktop/Olympus-Quest/Olympus_Quest/users.txt");

    // Check if user already exists
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith(email + ":")) {
                QMessageBox::warning(this, "Error", "User already exists!");
                file.close();
                return;
            }
        }
        file.close();
    }

    // Save new user
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << email << ":" << password << "\n";
        file.close();
        QMessageBox::information(this, "Success", "Account created!");
        on_toggleButton_clicked();
    } else {
        QMessageBox::critical(this, "Error", "Failed to write to file!");
    }
}


void MainWindow::handleLogin(QString email, QString password) {
    QFile file("C:/Users/Yousef/Desktop/Olympus-Quest/Olympus_Quest/users.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            QStringList parts = line.split(":");
            if (parts.size() == 2 && parts[0] == email && parts[1] == password) {
                QMessageBox::information(this, "Welcome", "Login successful!");
                file.close();
                // SecWindow app;
                // app.setModal(true);
                // app.exec();
                // secwin = new SecWindow(this);
                // secwin->show();
                // this->hide();

                ui->FullWiedgit->setCurrentIndex(1);
                ui->stackedWidget->setCurrentIndex(0);  // Open Dashboard
                setActiveSection(ui->Dashboardbtn, "#f1c27d"); // Update logo + btn color
                return;
            }
        }
        file.close();
        QMessageBox::warning(this, "Error", "Invalid email or password.");
    } else {
        QMessageBox::critical(this, "Error", "Unable to open user file.");
    }
}



void MainWindow::on_toggleButton_clicked()
{
    isLogin = !isLogin;

    if (isLogin) {
        ui->LabelSubHead->setText("Login");
        ui->pushButton->setText("Login");
        ui->label_5->setText("You don't have an account? ");
        ui->toggleButton->setText("Sign up");

        ui->label->setPixmap(QPixmap("C:/Users/Yousef/Pictures/newGym.png"));
        ui->LineEditUserName->setStyleSheet(R"(
            padding: 10px;
            border: 1px solid #ccc;
            background-color: #c68f3b;
            font: 12pt "Yeasty Flavors";
            border-radius: 20px;
            color: rgb(0, 0, 0);
        )");
        ui->LineEditPassword->setStyleSheet(R"(
            padding: 10px;
            border: 1px solid #ccc;
            background-color: #c68f3b;
            font: 12pt "Yeasty Flavors";
            border-radius: 20px;
            color: rgb(0, 0, 0);
        )");
        // ðŸ”µ Set button color for login
        ui->pushButton->setStyleSheet(R"(
            QPushButton {
                background-color: #c68f3b;
                color: white;
                border-radius: 25px;
                padding: 10px;
            }
            QPushButton:hover {
                background-color: #673AB7;
            }
        )");
    }
    else {
        ui->LabelSubHead->setText("Sign Up");
        ui->pushButton->setText("Sign Up");
        ui->label_5->setText("You have an account? ");
        ui->toggleButton->setText("Login");

        ui->label->setPixmap(QPixmap("C:/Users/Yousef/Pictures/newPadel.png"));
        ui->LineEditUserName->setStyleSheet(R"(
            padding: 10px;
            border: 1px solid #ccc;
            background-color: #008FC1;
            font: 12pt "Yeasty Flavors";
            border-radius: 20px;
            color: rgb(0, 0, 0);
        )");
        ui->LineEditPassword->setStyleSheet(R"(
            padding: 10px;
            border: 1px solid #ccc;
            background-color: #008FC1;
            font: 12pt "Yeasty Flavors";
            border-radius: 20px;
            color: rgb(0, 0, 0);
        )");

        // ðŸŸ£ Set button color for signup
        ui->pushButton->setStyleSheet(R"(
            QPushButton {
                background-color: #008FC1;
                color: white;
                border-radius: 25px;
                padding: 10px;
            }
            QPushButton:hover {
                background-color: #673AB7;
            }
        )");
    }
}


void MainWindow::on_Dashboardbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    setActiveSection(ui->Dashboardbtn, "#f1c27d");
}



void MainWindow::on_GymMangbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    setActiveSection(ui->GymMangbtn, "#aad1e6");
}
void MainWindow::setNotActiveSection() {
    QString defaultStyle = R"(
        QPushButton {
            background-color: transparent;
            color: black;
            font: 10pt "Yeasty Flavors";
            text-align: left;
            padding: 10px;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: #dcdcdc;
        }
    )";

    // Reset all section buttons
    ui->Dashboardbtn->setStyleSheet(defaultStyle);
    ui->GymMangbtn->setStyleSheet(defaultStyle);
    ui->TMbtn->setStyleSheet(defaultStyle);
    ui->Aubtn->setStyleSheet(defaultStyle);
    ui->Dashboard_5->setStyleSheet(defaultStyle);
    ui->Notibtn->setStyleSheet(defaultStyle);
    ui->Billbtn->setStyleSheet(defaultStyle);
    ui->ProfileBtn->setStyleSheet(defaultStyle);
    ui->SettingBtn->setStyleSheet(defaultStyle);

    // Reset logo background
    ui->logo->setStyleSheet("background-color: transparent;");
}


void MainWindow::setActiveSection(QPushButton* activeBtn, const QString& logoColor) {
    setNotActiveSection();  // Reset everything first

    activeBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #c68f3b;
            color: white;
            font: bold 10pt "Yeasty Flavors";
            text-align: left;
            padding: 10px;
            border-radius: 5px;
        }
    )");

    ui->logo->setStyleSheet("background-color: " + logoColor + "; border-radius: 10px;");
}

void MainWindow::on_TMbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setActiveSection(ui->TMbtn, "#f1c27d");
}


void MainWindow::on_Aubtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    setActiveSection(ui->Aubtn, "#f1c27d");
}


void MainWindow::on_Dashboard_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    setActiveSection(ui->Dashboard_5, "#f1c27d");
}


void MainWindow::on_Notibtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    setActiveSection(ui->Notibtn, "#f1c27d");
}


void MainWindow::on_Billbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    setActiveSection(ui->Billbtn, "#f1c27d");
}


void MainWindow::on_ProfileBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    setActiveSection(ui->ProfileBtn, "#f1c27d");
}


void MainWindow::on_SettingBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    setActiveSection(ui->SettingBtn, "#f1c27d");
}


void MainWindow::on_LogOutBtn_clicked()
{

    ui->FullWiedgit->setCurrentIndex(0);
}

