// #include "Manager.h"
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// manager::manager()
// {
//     id = 0;
//     name = "";
//     // Initialize the file if it doesn't exist
//     ofstream file(filename, ios::app);
//     file.close();
// }

// manager::manager(int id, string name)
// {
//     this->id = id;
//     this->name = name;
// }

// manager::~manager()
// {
   
// }

// void manager::addCourse()
// {
//     Gym_classes course;
//     int id;
//     string name;
//     string teacher;
//     int capacity;
//     int enrolled;

//     cout << "Enter the id of the course: ";
//     cin >> id;
    
//     // Check if course ID already exists
//     ifstream checkFile(filename);
//     string line;
//     bool fileExists = checkFile.good();
//     checkFile.close();
    
//     if (fileExists) {
//         ifstream inFile(filename);
//         while (getline(inFile, line)) {
//             if (!line.empty()) {
//                 size_t pos = line.find('|');
//                 if (pos != string::npos) {
//                     try {
//                         int existingId = stoi(line.substr(0, pos));
//                         if (existingId == id) {
//                             cout << "Error: Course ID " << id << " already exists. Please use a different ID." << endl;
//                             inFile.close();
//                             return;
//                         }
//                     } catch (...) {
//                         continue; // Skip invalid lines
//                     }
//                 }
//             }
//         }
//         inFile.close();
//     }
    
//     course.setid(ida);
    
//     cout << "Enter the name of the course: ";
//     cin.ignore(); // Clear the input buffer
//     getline(cin, name);
//     course.setname(name);
    
//     cout << "Enter the teacher of the course: ";
//     getline(cin, teacher);
//     course.setteacher(teacher);
    
//     cout << "Enter the capacity of the course: ";
//     cin >> capacity;
//     course.setcapacity(capacity);
    
//     cout << "Enter the enrolled of the course: ";
//     cin >> enrolled;
//     course.setenrolled(enrolled);

//     // Open file in append mode
//     ofstream outFile(filename, ios::app);
//     if (outFile.is_open()) {
//         outFile << course.getid() << "|"
//                 << course.getname() << "|"
//                 << course.getteacher() << "|"
//                 << course.getcapacity() << "|"
//                 << course.getenrolled() << endl;
//         outFile.close();
//         cout << "Course added successfully." << endl;
//     } else {
//         cout << "Error opening file for writing." << endl;
//     }
// }

// void manager::removeCourse(int courseId)
// {
//     ifstream inFile(filename);
//     ofstream tempFile("temp.txt");
//     bool found = false;

//     if (inFile.is_open() && tempFile.is_open()) {
//         string line;
//         while (getline(inFile, line)) {
//             size_t pos = line.find('|');
//             if (pos != string::npos) {
//                 int id = stoi(line.substr(0, pos));
//                 if (id != courseId ) {
//                     tempFile << line << endl;
//                 }
//                  else {
//                     found = true;
//                 }
//             }
//         }

//         inFile.close();
//         tempFile.close();

//         // Remove the original file and rename temp file
//         remove(filename.c_str());
//         rename("temp.txt", filename.c_str());

//         if (found) {
//             cout << "Course removed successfully." << endl;
//         } else {
//             cout << "Course not found." << endl;
//         }
//     } else {
//         cout << "Error opening files." << endl;
//     }
// }

// void manager::displayCourses() const
// {
//     ifstream inFile(filename);
//     if (!inFile.is_open()) {
//         cout << "No courses available or error opening file." << endl;
//         return;
//     }

//     cout << "\n=== Available Courses ===" << endl;
//     string line;
//     int count = 0;
//     bool hasData = false;

//     while (getline(inFile, line)) {
//         if (line.empty()) continue; // Skip empty lines
        
//         hasData = true;
//         count++;
        
//         try {
//             // Split the line by '|' delimiter
//             size_t pos1 = line.find('|');
//             size_t pos2 = line.find('|', pos1 + 1);
//             size_t pos3 = line.find('|', pos2 + 1);
//             size_t pos4 = line.find('|', pos3 + 1);

//             if (pos1 == string::npos || pos2 == string::npos ||
//                 pos3 == string::npos || pos4 == string::npos) {
//                 cout << "Error: Invalid data format in line " << count << endl;
//                 continue;
//             }

//             int id = stoi(line.substr(0, pos1));
//             string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
//             string teacher = line.substr(pos2 + 1, pos3 - pos2 - 1);
//             int capacity = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
//             int enrolled = stoi(line.substr(pos4 + 1));

//             cout << "\nCourse " << count << ":" << endl;
//             cout << "ID: " << id << endl;
//             cout << "Name: " << name << endl;
//             cout << "Teacher: " << teacher << endl;
//             cout << "Capacity: " << capacity << endl;
//             cout << "Enrolled: " << enrolled << endl;
//         }
//         catch (const exception& e) {
//             cout << "Error reading course " << count << ": " << e.what() << endl;
//         }
//     }

//     if (!hasData) {
//         cout << "No courses available." << endl;
//     }

//     cout << "\n=======================" << endl;
//     inFile.close();
// }

// void manager::workout_tracking(int memberId, Member member) {
//     // First load member data
//     ifstream memberFile("members.txt");
//     bool memberFound = false;
//     if (memberFile.is_open()) {
//         string memberLine;
//         while (getline(memberFile, memberLine)) {
//             size_t pos1 = memberLine.find('|');
//             if (pos1 != string::npos) {
//                 try {
//                     int currentId = stoi(memberLine.substr(0, pos1));
//                     if (currentId == memberId) {
//                         memberFound = true;
//                         size_t pos2 = memberLine.find('|', pos1 + 1);
//                         Qstring name = memberLine.substr(pos1 + 1, pos2 - pos1 - 1);
//                         member.setName(name);
//                         break;
//                     }
//                 } catch (const invalid_argument&) {
//                     continue;
//                 }
//             }
//         }
//         memberFile.close();
//     }

//     if (!memberFound) {
//         cout << "Member ID " << memberId << " not found in the system." << endl;
//         return;
//     }

//     cout << "\n=== Workout Tracking for Member ===" << endl;
//     cout << "Member Name: " << member.getName() << endl;
//     cout << "Member ID: " << memberId << endl;
//     cout << "\nEnrolled Courses:" << endl;

//     ifstream enrollFile("enrollments.txt");
//     if (!enrollFile.is_open()) {
//         cout << "Error opening enrollments file." << endl;
//         return;
//     }

//     string line;
//     bool found = false;
//     while (getline(enrollFile, line)) {
//         if (line.empty()) continue;

//         try {
//             size_t firstPipe = line.find('|');
//             if (firstPipe != string::npos) {
//                 size_t secondPipe = line.find('|', firstPipe + 1);
//                 if (secondPipe != string::npos) {
//                     string memberIdStr = line.substr(firstPipe + 1, secondPipe - firstPipe - 1);
//                     try {
//                         int currentMemberId = stoi(memberIdStr);
//                         if (currentMemberId == memberId) {
//                             found = true;
//                             string courseIdStr = line.substr(secondPipe + 1);
//                             int courseId = stoi(courseIdStr);
                            
//                             // Look up course details
//                             ifstream courseFile("courses.txt");
//                             string courseLine;
//                             while (getline(courseFile, courseLine)) {
//                                 size_t cpos1 = courseLine.find('|');
//                                 if (cpos1 != string::npos) {
//                                     try {
//                                         int cid = stoi(courseLine.substr(0, cpos1));
//                                         if (cid == courseId) {
//                                             size_t cpos2 = courseLine.find('|', cpos1 + 1);
//                                             string courseName = courseLine.substr(cpos1 + 1, cpos2 - cpos1 - 1);
//                                             cout << "- " << courseName << " (ID: " << courseId << ")" << endl;
//                                         }
//                                     } catch (const invalid_argument&) {
//                                         continue; // Skip invalid course IDs
//                                     }
//                                 }
//                             }
//                             courseFile.close();
//                         }
//                     } catch (const invalid_argument&) {
//                         continue; // Skip invalid member IDs
//                     }
//                 }
//             }
//         } catch (const exception& e) {
//             cout << "Error processing enrollment record: " << e.what() << endl;
//             continue;
//         }
//     }

//     if (!found) {
//         cout << "No courses found for this member." << endl;
//     }

//     cout << "===============================" << endl;
//     enrollFile.close();
// }


