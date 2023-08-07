#include <iostream>
#include <string>
#include <vector>
using namespace std;

//forward declaration of classes
class Student;
class QuestionSet;
class User;
class ExamManagement;

//Functions used
//displayStudentInfo
//setScore1
//setScore2
//displayInfoByRoll
//displaySet1
//displaySet2
//getUsername
//getPassword
//giveExam1
//giveExam2
//displayInfo
//nextStudent

class Student {
public:
    string name;
    int roll;
    int score1;
    int score2;

    Student() {}
    Student(string Name, int Roll) {
        name = Name;
        roll = Roll;
        score1 = 0;
        score2 = 0;
    }

    void displayStudentInfo() const {
        cout << "Name : " << name << endl;
        cout << "Roll : " << roll << endl;
        cout << "Score 1 : " << score1 << endl;
        cout << "Score 2 : " << score2 << endl;
    }

    void setScore1(int Score1) {
        score1 = Score1;
    }

    void setScore2(int Score2) {
        score2 = Score2;
    }

    friend void displayInfoByRoll(const ExamManagement& Kuet, int Roll);
};

class QuestionSet {
    vector<string> question;
    vector<char> correct_answer;

public:
    void displaySet1() {
        cout << "\n1. What is the implicit return type of constructor? "
             << "\nA) No return type \tB) A class object in which it is defined \nC) Void \tD) None \n"
             << endl;

        cout << "2. When is the object created with a new keyword? "
             << "\nA) At run time \tB) At compile time \nC) Depends on the code \tD) None \n"
             << endl;

        cout << "3. Identify the scope resolution operator. "
             << "\nA) : \tB) :: \nC) ?: \tD) None \n"
             << endl;
    }

    void displaySet2() {
        cout << "\n1. Total types of constructors in C++ are? "
             << "\nA) 1 \tB) 2 \nC) 3 \tD) 4 \n"
             << endl;

        cout << "2. What is the number of parameters that a default constructor requires? "
             << "\nA) 0 \tB) 1 \nC) 2 \tD) 3 \n"
             << endl;

        cout << "3. Identify the operators which cannot be overloaded? "
             << "\nA) ?: \tB) .(dot operator) \nC) >> \tD) Both A and B\n"
             << endl;
    }
};

class User {
    string username;
    string password;

public:
    User() {}
    User(string Username, string Password) {
        username = Username;
        password = Password;
    }

    string getUsername() const {
        return username;
    }

    string getPassword() const {
        return password;
    }
};

class ExamManagement {
    vector<Student> students;
    vector<User> users;
public:
    int loggedInUserIndex = -1;
    void registerUser(string Username, string Password) {
        users.push_back(User(Username, Password));
        cout << "Registration successful!" << endl;
    }
    
    bool login(string Username, string Password) {
        for (size_t i = 0; i < users.size(); ++i) {
if (users[i].getUsername() == Username && users[i].getPassword() == Password) {
        loggedInUserIndex = i;
            cout << "Login successful!" << endl;
            return true;
            }
        }
    cout << "Login failed! Invalid credentials." << endl;
        return false;
    }

    bool isUserLoggedIn() const {
        return loggedInUserIndex != -1;
    }

    int getLoggedInUserIndex() const {
        return loggedInUserIndex;
    }

    void setStudent(string Name, int Roll) {
        students.push_back(Student(Name, Roll));
    }

    void giveExam1() {
        int count = 0;
        char chosen_answer;

        cout << "\n1. What is the implicit return type of constructor? "
             << "\nA) No return type \tB) A class object in which it is defined \nC) Void \tD) None" << endl;
        cout << "Your Answer : ";
        cin >> chosen_answer;
        if (chosen_answer == 'B' || chosen_answer == 'b') {
            cout << "Correct!\n" << endl;
            count++;
        } else {
            cout << "Wrong! Correct Answer : B\n" << endl;
        }

        cout << "2. When is the object created with a new keyword? "
             << "\nA) At run time \tB) At compile time \nC) Depends on the code \tD) None" << endl;
        cout << "Your Answer : ";
        cin >> chosen_answer;
        if (chosen_answer == 'A' || chosen_answer == 'a') {
            cout << "Correct!\n" << endl;
            count++;
        } else {
            cout << "Wrong! Correct Answer : A\n" << endl;
        }

        cout << "3. Identify the scope resolution operator. "
             << "\nA) : \tB) :: \nC) ?: \tD) None" << endl;
        cout << "Your Answer : ";
        cin >> chosen_answer;
        if (chosen_answer == 'B' || chosen_answer == 'b') {
            cout << "Correct!\n" << endl;
            count++;
        } else {
            cout << "Wrong! Correct Answer : B\n" << endl;
        }

        students[loggedInUserIndex].setScore1(count);
    }

    void giveExam2() {
        int count = 0;
        char chosen_answer;

                cout << "\n1. Total types of constructors in C++ are? "
             << "\nA) 1 \tB) 2 \nC) 3 \tD) 4" << endl;
        cout << "Your Answer : ";
        cin >> chosen_answer;
        if (chosen_answer == 'C' || chosen_answer == 'c') {
            cout << "Correct!\n" << endl;
            count++;
        } else {
            cout << "Wrong! Correct Answer : C\n" << endl;
        }

        cout << "2. What is the number of parameters that a default constructor requires? "
             << "\nA) 0 \tB) 1 \nC) 2 \tD) 3" << endl;
        cout << "Your Answer : ";
        cin >> chosen_answer;
        if (chosen_answer == 'A' || chosen_answer == 'a') {
            cout << "Correct!\n" << endl;
            count++;
        } else {
            cout << "Wrong! Correct Answer : A\n" << endl;
        }

        cout << "3. Identify the operators which cannot be overloaded? "
             << "\nA) ?: \tB) .(dot operator) \nC) >> \tD) Both A and B" << endl;
        cout << "Your Answer : ";
        cin >> chosen_answer;
        if (chosen_answer == 'D' || chosen_answer == 'd') {
            cout << "Correct!\n" << endl;
            count++;
        } else {
            cout << "Wrong! Correct Answer : D\n" << endl;
        }

        students[loggedInUserIndex].setScore2(count);
    }

    void displayInfo() {
        students[loggedInUserIndex].displayStudentInfo();
    }

    void nextStudent() {
        loggedInUserIndex = -1;
    }

    friend void displayInfoByRoll(const ExamManagement& Kuet, int Roll);

};

void displayInfoByRoll(const ExamManagement& Kuet, int Roll) {
    int k;
    for (k = 0; k < Kuet.students.size(); k++) {
        if (Kuet.students[k].roll == Roll) {
            Kuet.students[k].displayStudentInfo();
            break;
        }
    }
    if (k == Kuet.students.size()) {
        cout << "No match found!" << endl;
    }
}

int main() {
    int choice;
    ExamManagement kuet;

    while (true) {
        // First Interface: Register and Login
        cout << "\tWelcome to Test" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter a username: ";
            cin >> username;
            cout << "Enter a password: ";
            cin >> password;
            kuet.registerUser(username, password);
        } else if (choice == 2) {
            // Code for Login
            cout << "\nLogin" << endl;
            string username, password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;

            if (!kuet.login(username, password)) {
                cout << "Login failed! Invalid credentials." << endl;
                continue;
            }

            menu:
            // Main Menu
            while (kuet.isUserLoggedIn()) {
                cout << "\nChoose an option : " << endl;
                cout << "1. See questions" << endl;
                cout << "2. Give an exam" << endl;
                cout << "3. Your scores" << endl;
                cout << "4. Logout" << endl;
                cout << "0. Exit" << endl;

                cout << "Enter your choice : ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                question:
                {
                    cout << "\nChoose an option : " << endl;
                    cout << "1. Question set 1" << endl;
                    cout << "2. Question set 2" << endl;
                    cout << "3. Go to Menu" << endl;
                    cout << "0. Exit" << endl;

                    cout << "Enter your choice : ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            //function call to display question set 1
                            QuestionSet set1;
                            set1.displaySet1();

                            cout << "\nChoose an option : " << endl;
                            cout << "1. Go back" << endl;
                            cout << "2. Go to Menu" << endl;
                            cout << "0. Exit" << endl;
                            cout << "Enter choice : ";
                            cin >> choice;

                            if (choice == 1) {
                                goto question;
                            } else if (choice == 2) {
                                goto menu;
                            } else if (choice == 0) {
                                return 0;
                            } else {
                                cout << "Invalid choice!" << endl;
                                goto menu;
                            }

                            break;
                        }

                        case 2: {
                            //function call to display question set 2
                            QuestionSet set2;
                            set2.displaySet2();

                            cout << "\nChoose an option : " << endl;
                            cout << "1. Go back" << endl;
                            cout << "2. Go to Menu" << endl;
                            cout << "0. Exit" << endl;
                            cout << "Enter choice : ";
                            cin >> choice;

                            if (choice == 1) {
                                goto question;
                            } else if (choice == 2) {
                                goto menu;
                            } else if (choice == 0) {
                                return 0;
                            } else {
                                cout << "Invalid choice!" << endl;
                                goto menu;
                            }

                            break;
                        }

                        case 3:
                            goto menu;
                            break;

                        case 0:
                            return 0;
                    }
                }
                break;
            }
            case 2: {
                //Get name and roll
                string name;
                int roll;
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter roll : ";
                cin >> roll;

                //function call to set name and roll
                kuet.setStudent(name, roll);

                //choose question set
                exam:
                {
                    cout << "Choose a question set (1/2): ";
                    cin >> choice;

                    if (choice == 1) {
                        kuet.giveExam1();
                    } else if (choice == 2) {
                        kuet.giveExam2();
                    }

                    //Show score
                    kuet.displayInfo();

                    cout << "\nChoose an option : " << endl;
                    cout << "1. Go Back" << endl;
                    cout << "2. Go to Menu" << endl;
                    cout << "0. Exit" << endl;

                    cout << "Enter choice : ";
                    cin >> choice;

                    if (choice == 1) {
                        goto exam;
                    } else if (choice == 2) {
                        //kuet.nextStudent();
                        goto menu;
                    } else if (choice == 0) {
                        return 0;
                    } else {
                       // kuet.nextStudent();
                        cout << "Invalid choice!" << endl;
                        goto menu;
                    }
                }
                break;
            }
            case 3: {
                int roll;
                cout << "Enter roll : ";
                cin >> roll;

                displayInfoByRoll(kuet, roll);

                cout << "\nChoose an option : " << endl;
                cout << "1. Go to Menu" << endl;
                cout << "0. Exit" << endl;

                cout << "Enter choice : ";
                cin >> choice;

                if (choice == 1) {
                    goto menu;
                } else if (choice == 0) {
                    return 0;
                } else {
                    cout << "Invalid choice!" << endl;
                    goto menu;
                }
                break;
            }
                    case 4: {
                        kuet.nextStudent();
                        cout << "Logged out successfully!" << endl;
                        goto login_interface;
                    }
                    case 0: {
                        kuet.nextStudent();
                        cout << "\n\tProgram finished!" << endl;
                        return 0;
                    }
                    default: {
                        cout << "Invalid choice!" << endl;
                        break;
                    }
                }
            }
        } else if (choice == 0) {
            return 0;
        } else {
            cout << "Invalid choice!" << endl;
        }

        login_interface: // Label to go back to the login/register interface
        continue;
    }
    return 0;
}