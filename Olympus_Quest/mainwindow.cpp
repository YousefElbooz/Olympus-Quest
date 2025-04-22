// mainwindow.cpp (complete + organized)
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "FileHandler.h"
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QMap>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setButtonStyle(ui->LogOutBtn, "#c68f3b");
    setButtonStyle(ui->LogOutBtn_3, "#c68f3b");
    ui->FullWiedgit->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    setPixmapForWidgets();
    FileHandler::loadMembers("C:/Users/Yousef/Desktop/Olympus-Quest/Olympus_Quest/users.txt");
    FileHandler::loadStaff("C:/Users/Yousef/Desktop/Olympus-Quest/Olympus_Quest/staff.txt");
    FileHandler::loadAllClasses("C:/Users/Yousef/Desktop/Olympus-Quest/Olympus_Quest/classes.txt");
    QList<QTableWidget*> tablewidgets = {ui->tableWidget,ui->tableWidget_4};
    FileHandler::populateClassesTable(tablewidgets);
}

MainWindow::~MainWindow() {
    delete ui;
    FileHandler::saveMembers("C:/Users/Yousef/Desktop/Olympus-Quest/Olympus_Quest/users.txt");
    FileHandler::saveStaff("C:/Users/Yousef/Desktop/Olympus-Quest/Olympus_Quest/staff.txt");
    FileHandler::freeUsers();
    FileHandler::saveAllClasses();
    FileHandler::saveAllClasses();
}

//-------------------------------------- UI Helper Functions --------------------------------------//

void MainWindow::setButtonStyle(QPushButton* button, const QString& backgroundColor) {
    button->setStyleSheet(QString(R"(
        QPushButton {
            background-color: transparent;
            color: black;
            font: 18pt "Yeasty Flavors";
            text-align: left;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: %1;
        }
    )").arg(backgroundColor));
}

void MainWindow::setNotActiveSection() {
    QString defaultStyle = R"(
        QPushButton {
            background-color: transparent;
            color: black;
            font: 18pt "Yeasty Flavors";
            text-align: left;
            border-radius: 5px;
        }
        QPushButton:hover {
            background-color: #dcdcdc;
        }
    )";

    QPushButton* buttons[] = {
        ui->Dashboardbtn, ui->GymMangbtn, ui->TMbtn, ui->Aubtn, ui->AdminBtn,
        ui->Notibtn, ui->Billbtn, ui->ProfileBtn, ui->SettingBtn,
        ui->Dashboardbtn_3, ui->GymMangbtn_3, ui->TMbtn_3, ui->Aubtn_3, ui->Subscriptionbtn,
        ui->Notibtn_3, ui->Billbtn_3, ui->ProfileBtn_3, ui->Aubtn_4
    };

    for (QPushButton* btn : buttons) {
        btn->setStyleSheet(defaultStyle);
    }

    ui->logo->setStyleSheet("background-color: transparent;");
}

void MainWindow::setActiveSection(QPushButton* activeBtn, const QString& logoColor) {
    setNotActiveSection();
    activeBtn->setStyleSheet(R"(
        QPushButton {
            background-color: #c68f3b;
            color: white;
            font: bold 18pt "Yeasty Flavors";
            text-align: left;
            border-radius: 5px;
        }
    )");
    ui->logo->setStyleSheet("background-color: " + logoColor + "; border-radius: 10px;");
}

void MainWindow::setPixmapForWidgets() {
    QString imagePaths[] = {
        "C:/Users/Yousef/Pictures/newGym.png", // 0 - label image (skip or use elsewhere)
        "C:/Users/Yousef/Downloads/ChatGPT Image Apr 15, 2025, 10_53_31 PM.png", // 1 - logo (still used)
        "C:/Users/Yousef/Downloads/dashboard-svgrepo-com.svg", // 2
        "C:/Users/Yousef/Downloads/gym-dumbbell-svgrepo-com.svg", // 3
        "C:/Users/Yousef/Downloads/group-of-businessmen-svgrepo-com.svg", // 4
        "C:/Users/Yousef/Downloads/add-user-svgrepo-com.svg", // 5
        "C:/Users/Yousef/Downloads/user-admin-svgrepo-com.svg", // 6
        "C:/Users/Yousef/Downloads/notification-bell-1397-svgrepo-com.svg", // 7
        "C:/Users/Yousef/Downloads/invoice-bill-svgrepo-com.svg", // 8
        "C:/Users/Yousef/Downloads/profile-round-1342-svgrepo-com.svg", // 9
        "C:/Users/Yousef/Downloads/setting-4-svgrepo-com.svg", // 10
        "C:/Users/Yousef/Downloads/logout-svgrepo-com.svg", // 11
        "C:/Users/Yousef/Downloads/line-chart-up-02-svgrepo-com.svg", // 12
        "C:/Users/Yousef/Downloads/enter-svgrepo-com.svg", // 13
        "C:/Users/Yousef/Downloads/cancel-photo-svgrepo-com.svg", // 14
        "C:/Users/Yousef/Downloads/calendar-event-available-svgrepo-com.svg", // 15
        "C:/Users/Yousef/Downloads/home-workouts-svgrepo-com.svg", // 16
        "C:/Users/Yousef/Downloads/auto-renewal-2-circle-fill-svgrepo-com.svg", // 17
        "C:/Users/Yousef/Downloads/court-playground-svgrepo-com.svg",        // 18
        "C:/Users/Yousef/Downloads/user-admin-svgrepo-com.svg",     // 19
        "C:/Users/Yousef/Downloads/sand-clock-svgrepo-com.svg",     // 20
        "C:/Users/Yousef/Downloads/stretching-svgrepo-com.svg",     //21
        "C:/Users/Yousef/Downloads/coach-coaching-physical-trainer-svgrepo-com.svg", //22
        "C:/Users/Yousef/Downloads/money-bag-svgrepo-com.svg",      //23
        "C:/Users/Yousef/Downloads/line-chart-up-02-svgrepo-com.svg",       //24
        "C:/Users/Yousef/Downloads/enter-svgrepo-com.svg",                  //25
        "C:/Users/Yousef/Downloads/cancel-photo-svgrepo-com.svg",           //26
        "C:/Users/Yousef/Downloads/calendar-event-available-svgrepo-com.svg",   //27
        "C:/Users/Yousef/Downloads/home-workouts-svgrepo-com.svg",      //28
        "C:/Users/Yousef/Downloads/auto-renewal-2-circle-fill-svgrepo-com.svg",     //29
        "C:/Users/Yousef/Downloads/court-playground-svgrepo-com.svg"            //30
    };

    // Logo only (still QLabel)
    ui->logo->setPixmap(QPixmap(imagePaths[1]));
    ui->logo_3->setPixmap(QPixmap(imagePaths[1]));
    ui->label->setPixmap(QPixmap(imagePaths[0]));
    // Buttons with icons
    ui->Dashboardbtn->setIcon(QIcon(imagePaths[2]));
    ui->GymMangbtn->setIcon(QIcon(imagePaths[3]));
    ui->TMbtn->setIcon(QIcon(imagePaths[4]));
    ui->Aubtn->setIcon(QIcon(imagePaths[5]));
    ui->Notibtn->setIcon(QIcon(imagePaths[7]));
    ui->Billbtn->setIcon(QIcon(imagePaths[8]));
    ui->ProfileBtn->setIcon(QIcon(imagePaths[9]));
    ui->SettingBtn->setIcon(QIcon(imagePaths[10]));
    ui->LogOutBtn->setIcon(QIcon(imagePaths[11]));
    ui->AdminBtn->setIcon(QIcon(imagePaths[19]));

    // Member buttons
    ui->Dashboardbtn_3->setIcon(QIcon(imagePaths[2]));
    ui->GymMangbtn_3->setIcon(QIcon(imagePaths[3]));
    ui->TMbtn_3->setIcon(QIcon(imagePaths[4]));
    ui->Aubtn_3->setIcon(QIcon(imagePaths[5]));
    ui->Aubtn_4->setIcon(QIcon(imagePaths[5]));
    ui->Notibtn_3->setIcon(QIcon(imagePaths[7]));
    ui->Billbtn_3->setIcon(QIcon(imagePaths[8]));
    ui->ProfileBtn_3->setIcon(QIcon(imagePaths[9]));
    ui->LogOutBtn_3->setIcon(QIcon(imagePaths[11]));
    ui->Subscriptionbtn->setIcon(QIcon(imagePaths[29]));

    // Optional: set icon size (applies to all buttons)
    QList<QPushButton*> allButtons = {
        ui->Dashboardbtn, ui->GymMangbtn, ui->TMbtn, ui->Aubtn, ui->Notibtn, ui->Billbtn,
        ui->ProfileBtn, ui->SettingBtn, ui->LogOutBtn,
        ui->Dashboardbtn_3, ui->GymMangbtn_3, ui->TMbtn_3, ui->Aubtn_3, ui->Aubtn_4,
        ui->Notibtn_3, ui->Billbtn_3, ui->ProfileBtn_3, ui->LogOutBtn_3,ui->AdminBtn
    };

    for (auto* btn : allButtons) {
        btn->setIconSize(QSize(32, 32)); // Adjust size as needed
    }
    ui->TrainerNumICon->setPixmap(QPixmap(imagePaths[22]));
    ui->SandClockICon->setPixmap(QPixmap(imagePaths[20]));
    ui->SessionICon->setPixmap(QPixmap(imagePaths[21]));
    ui->NotificationDashIcon->setPixmap(QPixmap(imagePaths[7]));
    ui->TotalMemberIcon->setPixmap(QPixmap(imagePaths[9]));
    ui->CashIcon->setPixmap(QPixmap(imagePaths[22]));
    ui->Chart->setPixmap(QPixmap(imagePaths[23]));
}


//-------------------------------------- Auth Handlers --------------------------------------//

void MainWindow::handleLogin(QString id, QString email, QString password) {
    QString userType;

    // First, try to match as a member
    if (FileHandler::getUsers().contains(id)) {
        Member* m = FileHandler::getUsers()[id];
        if (m->getEmail() == email && m->getPassword() == password) {
            currentMemberId = id;
            userType = m->getUserType();
        }
    }

    // If not a member, try staff (even if ID is same)
    if (userType.isEmpty()) {
        bool ok;
        int numericId = id.toInt(&ok);
        if (ok && FileHandler::getStaff().contains(numericId)) {
            Staff* staff = FileHandler::getStaff()[numericId];
            if (email == "placeholder@mail.com" && password == "123456") {
                userType = staff->getRole().toLower();
            }
        }
    }

    if (!userType.isEmpty()) {
        QMessageBox::information(this, "Login", "Login successful as " + userType);
        navigateBasedOnUserType(userType);
    } else {
        QMessageBox::warning(this, "Login", "Invalid ID or password");
    }
}


void MainWindow::handleSignUp(QString name, QString age, QString email, QString address,
                              QString password, QString paymentDate, QString phone,
                              QString duration, QString gender, QString userType) {
    if (name.isEmpty() || age.isEmpty() || email.isEmpty() || address.isEmpty() ||
        password.isEmpty() || paymentDate.isEmpty() || phone.isEmpty() ||
        duration.isEmpty() || gender.isEmpty() || userType.isEmpty()) {
        QMessageBox::warning(this, "Sign Up", "Please fill in all fields.");
        return;
    }

    if (FileHandler::userExists(email)) {
        QMessageBox::warning(this, "Sign Up", "A user with this email already exists.");
        return;
    }

    QStringList userData = {
        name, age, email, address, password, paymentDate, phone, duration, gender, userType
    };

    bool success = false;
    if (userType.toLower() == "member") {
        success = FileHandler::appendMember(userData);
    } else {
        success = FileHandler::appendStaff(userData);
    }

    if (success) {
        ui->stackedWidget_3->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Error", "Failed to create account.");
    }
}


void MainWindow::navigateBasedOnUserType(QString userType) {
    if (userType == "manager") {
        ui->FullWiedgit->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(0);
        setActiveSection(ui->Dashboardbtn, "#f1c27d");
    } else if (userType == "receptionist") {
        ui->FullWiedgit->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(1);
        setActiveSection(ui->GymMangbtn, "#aad1e6");
    } else if (userType == "coach") {
        ui->FullWiedgit->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(2);
        setActiveSection(ui->TMbtn, "#f1c27d");
    } else if (userType == "member") {
        ui->FullWiedgit->setCurrentIndex(2);
        ui->stackedWidget_3->setCurrentIndex(0);
        setActiveSection(ui->Dashboardbtn_3, "#f1c27d");
        if (currentMemberId.isEmpty()) {
            QMessageBox::warning(this, "Error", "No member is currently logged in.");
            return;
        }
        FileHandler::populateMemberAttendedClasses(ui->tableWidget_3, currentMemberId);
    }
}

//-------------------------------------- Form Utilities --------------------------------------//

QString MainWindow::getUserType() {
    if (ui->MemberRadio->isChecked()) return "member";
    if (ui->MangerrRadio->isChecked()) return "manager";
    if (ui->StaffRadio->isChecked()) return "coach";
    if(ui->StaffRadio_2->isChecked()) return "receptionist";
    QMessageBox::warning(this, "Error", "Please select a user type.");
    return "";
}

QString MainWindow::getGender() {
    if (ui->MaleRadio->isChecked()) return "male";
    if (ui->FemaleRadio->isChecked()) return "female";
    return "";
}

QString MainWindow::getSubscriptionDuration() {
    if (ui->mont3->isChecked()) return "3 months";
    if (ui->month6->isChecked()) return "6 months";
    if (ui->month9->isChecked()) return "9 months";
    if (ui->month12->isChecked()) return "12 months";
    return "";
}

//-------------------------------------- File-based Class Handling --------------------------------------//



void MainWindow::on_Dashboard_15_clicked() {
    QStringList filters = {
        ui->lineEdit->text().trimmed(),
        ui->lineEdit_2->text().trimmed(),
        ui->lineEdit_3->text().trimmed(),
        ui->lineEdit_4->text().trimmed(),
        ui->lineEdit_5->text().trimmed()
    };
    FileHandler::filterClasses(ui->tableWidget,filters);
}



void MainWindow::on_Dashboard_16_clicked() {

    QStringList filters = {
        ui->lineEdit_11->text().trimmed(),
        ui->lineEdit_12->text().trimmed(),
        ui->lineEdit_13->text().trimmed(),
        ui->lineEdit_14->text().trimmed(),
        ui->lineEdit_15->text().trimmed()
    };

    if (FileHandler::requestClassesForMember(currentMemberId, filters)) {
        QMessageBox::information(this, "Success", "Class(es) added to your schedule.");
        FileHandler::populateMemberAttendedClasses(ui->tableWidget_3, currentMemberId);
        QList<QTableWidget*> tablewidgets = {ui->tableWidget,ui->tableWidget_4};
        FileHandler::populateClassesTable(tablewidgets);
    } else {
        QMessageBox::warning(this, "No Match", "No classes matched your filters.");
    }
}

//-------------------------------------- UI Event Handlers (Dashboard and Navigation) --------------------------------------//

void MainWindow::on_Dashboardbtn_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
    setActiveSection(ui->Dashboardbtn, "#f1c27d");
}

void MainWindow::on_GymMangbtn_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
    setActiveSection(ui->GymMangbtn, "#aad1e6");
}

void MainWindow::on_TMbtn_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
    setActiveSection(ui->TMbtn, "#f1c27d");
}

void MainWindow::on_Aubtn_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
    setActiveSection(ui->Aubtn, "#f1c27d");
}

void MainWindow::on_AdminBtn_clicked() {
    ui->stackedWidget->setCurrentIndex(4);
    setActiveSection(ui->AdminBtn, "#f1c27d");
}

void MainWindow::on_Notibtn_clicked() {
    ui->stackedWidget->setCurrentIndex(5);
    setActiveSection(ui->Notibtn, "#f1c27d");
}

void MainWindow::on_Billbtn_clicked() {
    ui->stackedWidget->setCurrentIndex(6);
    setActiveSection(ui->Billbtn, "#f1c27d");
}

void MainWindow::on_ProfileBtn_clicked() {
    ui->stackedWidget->setCurrentIndex(7);
    setActiveSection(ui->ProfileBtn, "#f1c27d");
}

void MainWindow::on_SettingBtn_clicked() {
    ui->stackedWidget->setCurrentIndex(8);
    setActiveSection(ui->SettingBtn, "#f1c27d");
}

void MainWindow::on_LogOutBtn_clicked() {
    ui->FullWiedgit->setCurrentIndex(0);
}
//-------------------------------------- Toggle & Login Buttons --------------------------------------//

void MainWindow::on_toggleButton_clicked() {
    int currentIndex = ui->stackedWidget_2->currentIndex();
    if (currentIndex == 0) {
        ui->label->setPixmap(QPixmap("C:/Users/Yousef/Pictures/newPadel.png"));
        ui->stackedWidget_2->setCurrentIndex(1);
    } else {
        ui->label->setPixmap(QPixmap("C:/Users/Yousef/Pictures/newGym.png"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_toggleButton_3_clicked() {
    int currentIndex = ui->stackedWidget_2->currentIndex();
    if (currentIndex == 0) {
        ui->label->setPixmap(QPixmap("C:/Users/Yousef/Pictures/newPadel.png"));
        ui->stackedWidget_2->setCurrentIndex(1);
    } else {
        ui->label->setPixmap(QPixmap("C:/Users/Yousef/Pictures/newGym.png"));
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_clicked() {
    QString username = ui->LineEditUserName->text().trimmed();
    QString password = ui->LineEditPassword->text();
    QString id = ui->LineEditPassword_3->text();
    if (username.isEmpty() || password.isEmpty()||id.isEmpty()) {
        QMessageBox::warning(this, "Missing Input", "Please enter email and password.");
        return;
    }
    handleLogin(id,username, password);
}

//-------------------------------------- Table & Stack Slot Actions --------------------------------------//

//-------------------------------------- Member Dashboard UI Navigation --------------------------------------//

void MainWindow::on_Dashboardbtn_3_clicked() {
    ui->stackedWidget_3->setCurrentIndex(0);
    setActiveSection(ui->Dashboardbtn_3, "#f1c27d");
}

void MainWindow::on_GymMangbtn_3_clicked() {
    ui->stackedWidget_3->setCurrentIndex(1);
    setActiveSection(ui->GymMangbtn_3, "#f1c27d");
}

void MainWindow::on_Aubtn_4_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
    setActiveSection(ui->Aubtn_4, "#f1c27d");
}

void MainWindow::on_TMbtn_3_clicked() {
    ui->stackedWidget_3->setCurrentIndex(2);
    setActiveSection(ui->TMbtn_3, "#f1c27d");
}

void MainWindow::on_Aubtn_3_clicked() {
    ui->stackedWidget_3->setCurrentIndex(3);
    setActiveSection(ui->Aubtn_3, "#f1c27d");
}

void MainWindow::on_Subscriptionbtn_clicked() {
    ui->stackedWidget_3->setCurrentIndex(5);
    setActiveSection(ui->Subscriptionbtn, "#f1c27d");
}

void MainWindow::on_Notibtn_3_clicked() {
    ui->stackedWidget_3->setCurrentIndex(6);
    setActiveSection(ui->Notibtn_3, "#f1c27d");
}

void MainWindow::on_Billbtn_3_clicked() {
    ui->stackedWidget_3->setCurrentIndex(7);
    setActiveSection(ui->Billbtn_3, "#f1c27d");
}

void MainWindow::on_ProfileBtn_3_clicked() {
    ui->stackedWidget_3->setCurrentIndex(8);
    setActiveSection(ui->ProfileBtn_3, "#f1c27d");
}

void MainWindow::on_LogOutBtn_3_clicked() {
    ui->FullWiedgit->setCurrentIndex(0);
}

//-------------------------------------- Registration Slot --------------------------------------//

void MainWindow::on_SignUp_clicked() {
    QString username = ui->LineEditUserNameSignUp->text();
    QString age = ui->LineEditAge->text();
    QString email = ui->LineEditEmail->text();
    QString address = ui->LineEditAddress->text();
    QString password = ui->LineEditPassword_2->text();
    QString paymentDate = ui->LineEditPaymentDate->text();
    QString phone = ui->LineEditPhone->text();
    QString duration = getSubscriptionDuration();
    QString gender = getGender();
    QString userType = getUserType();

    handleSignUp(username, age, email, address, password, paymentDate, phone, duration, gender, userType);
}

void MainWindow::on_Dashboard_13_clicked() {
    ui->stackedWidget_3->setCurrentIndex(0);
    setActiveSection(ui->Dashboardbtn_3, "#f1c27d");
}
/*-------------------------------------- Function Order Summary --------------------------------------*

1. Constructor / Destructor
   - MainWindow::MainWindow
   - MainWindow::~MainWindow

2. UI Helper Functions
   - setButtonStyle
   - setNotActiveSection
   - setActiveSection
   - setPixmapForWidgets

3. Authentication
   - handleLogin
   - handleSignUp
   - navigateBasedOnUserType

4. Form Utilities
   - getUserType
   - getGender
   - getSubscriptionDuration

5. File-based Class Handling
   - loadClassesFromFile
   - on_Dashboard_15_clicked
   - on_Dashboard_16_clicked

6. Main Dashboard Navigation
   - on_Dashboardbtn_clicked
   - on_GymMangbtn_clicked
   - on_TMbtn_clicked
   - on_Aubtn_clicked
   - on_Dashboard_5_clicked
   - on_Notibtn_clicked
   - on_Billbtn_clicked
   - on_ProfileBtn_clicked
   - on_SettingBtn_clicked
   - on_LogOutBtn_clicked

7. Toggle & Login Buttons
   - on_toggleButton_clicked
   - on_toggleButton_3_clicked
   - on_pushButton_clicked

8. Table & Stack Interactions
   - on_tableWidget_cellEntered

9. Member Dashboard Navigation
   - on_Dashboardbtn_3_clicked
   - on_GymMangbtn_3_clicked
   - on_TMbtn_3_clicked
   - on_Aubtn_3_clicked
   - on_Dashboard_11_clicked
   - on_Notibtn_3_clicked
   - on_Billbtn_3_clicked
   - on_ProfileBtn_3_clicked
   - on_SettingBtn_3_clicked
   - on_LogOutBtn_3_clicked

10. Registration
   - on_SignUp_clicked
   - on_Dashboard_13_clicked

*-----------------------------------------------------------------------------------------------*/




void MainWindow::on_Dashboard_17_clicked()
{
    QStringList filters = {
        ui->lineEdit_6->text().trimmed(),
        ui->lineEdit_7->text().trimmed(),
        ui->lineEdit_8->text().trimmed(),
        ui->lineEdit_9->text().trimmed(),
        ui->lineEdit_10->text().trimmed()
    };
    FileHandler::filterMemberClasses(ui->tableWidget_3,currentMemberId,filters);
}






