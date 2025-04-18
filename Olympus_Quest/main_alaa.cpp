// #include "Manager.h"
// #include "Member.h"
// #include <iostream>
// using namespace std;

// void displayManagerMenu() {
//     cout << "\nGym Management System - Manager Menu" << endl;
//     cout << "1. Add Course" << endl;
//     cout << "2. Remove Course" << endl;
//     cout << "3. Display Courses" << endl;
//     cout << "4. Track Workout" << endl;
//     cout << "5. Exit" << endl;
//     cout << "Enter your choice: ";
// }

// void displayMemberMenu() {
//     cout << "\nGym Management System - Member Menu" << endl;
//     cout << "1. Enroll in Course" << endl;
//     cout << "2. Cancel Course" << endl;
//     cout << "3. Display Available Courses" << endl;
//     cout << "4. Switch to Manager Menu" << endl;
//     cout << "5. Exit" << endl;
//     cout << "Enter your choice: ";
// }

// int main() {
//     manager gymManager;
//     Member member;
//     int choice;
//     int courseId;
//     int memberId;
//     string name, phone, email, gender, address, membership, payment, payment_date;
//     int age;

//     while (true) {
//         cout << "\nSelect User Type:" << endl;
//         cout << "1. Manager" << endl;
//         cout << "2. Member" << endl;
//         cout << "3. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         if (choice == 1) { // Manager Menu
//             while (true) {
//                 displayManagerMenu();
//                 cin >> choice;

//                 switch (choice) {
//                     case 1:
//                         gymManager.addCourse();
//                         break;
//                     case 2:
//                         cout << "Enter course ID to remove: ";
//                         cin >> courseId;
//                         gymManager.removeCourse(courseId);
//                         break;
//                     case 3:
//                         gymManager.displayCourses();
//                         break;
//                     case 4:
//                         cout << "Enter member ID: ";
//                         cin >> memberId;
//                         gymManager.workout_tracking(memberId,member);
//                         break;
//                     case 5:
//                         cout << "Exiting program. Goodbye!" << endl;
//                         return 0;
//                     default:
//                         cout << "Invalid choice. Please try again." << endl;
//                 }
//             }
//         }
//         else if (choice == 2) { // Member Menu
//             cout << "Enter your member ID: ";
//             cin >> memberId;
//             cout << "Enter your name: ";
//             cin.ignore();
//             getline(cin, name);
//             cout << "Enter your phone: ";
//             getline(cin, phone);
//             cout << "Enter your email: ";
//             getline(cin, email);
//             cout << "Enter your age: ";
//             cin >> age;
//             cout << "Enter your gender: ";
//             cin.ignore();
//             getline(cin, gender);
//             cout << "Enter your address: ";
//             getline(cin, address);
//             cout << "Enter your membership type: ";
//             getline(cin, membership);
//             cout << "Enter your payment status: ";
//             getline(cin, payment);
//             cout << "Enter your payment date: ";
//             getline(cin, payment_date);

//             member = Member(memberId, name, phone, email, age, gender, address, membership, payment, payment_date);

//             member_section:
//             while (true) {
//                 displayMemberMenu();
//                 cin >> choice;

//                 switch (choice) {
//                     case 1:
//                         cout << "Enter course ID to enroll: ";
//                         cin >> courseId;
//                         member.enroll(courseId, member);
//                         break;
//                     case 2:
//                         cout << "Enter course ID to cancel: ";
//                         cin >> courseId;
//                         member.cancel(courseId, member);
//                         break;
//                     case 3:
//                         member.display_enrolled_courses(memberId, member);
//                         break;
//                     case 4:
//                         cout << "Exiting program. Goodbye!" << endl;
//                         return 0;
//                     default:
//                         cout << "Invalid choice. Please try again." << endl;
//                 }
//             }
//         }
//         else if (choice == 3) {
//             cout << "Exiting program. Goodbye!" << endl;
//             return 0;
//         }
//         else {
//             cout << "Invalid choice. Please try again." << endl;
//         }
//     }

//     return 0;
// }
