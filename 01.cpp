#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include <cstdlib>

using namespace std;

void login();
void signup();
void forgot();

int main(){
    cout << "--------------LOGIN AND SIGNUP PAGE--------------"<< endl;
    int choice;
    cout << "              |1.LOGIN|\n";
    cout << "              |2.SIGNUP|\n";
    cout << "              |3.FORGOT PASSWORD|\n";
    cout << endl;
    cout << "              Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
        login();
        break;
        case 2:
        signup();
        break;
        case 3:
        forgot();
        break;
    }
    
}

 void signup() {
    system("clear");
    string username, existingUser, password;
    bool userExists = false;

    cout << "Enter username: ";
    cin >> username;

    // Check if username already exists
    ifstream read("username.txt");
    while (getline(read, existingUser)) {
        if (username == existingUser) {
            userExists = true;
            break;
        }
    }
    read.close();

    if (userExists) {
        cout << "Username already exists. Enter another username.\n";
        return signup();  
    }

    ofstream user("username.txt", ios::app);  // Append mode
    ofstream pass("password.txt", ios::app);
    
    user << username << endl;
    cout << "Enter password: ";
    cin >> password;
    pass << password << endl;

    user.close();
    pass.close();

    
        system("clear");  

    cout << "Signup successful!\n";
    main();
}

//login function

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void login();
void signup();

void login() {
        system("clear");
    string username, password, existingUser, existingPass;
    bool userExist = false;
    
    cout << "Enter your username: ";
    cin >> username;

    // Open username and password files
    ifstream userFile("username.txt");
    ifstream passFile("password.txt");

    if (!userFile || !passFile) {
        cout << "Error opening user database!\n";
        return;
    }

    // Check if user exists and get password
    while (getline(userFile, existingUser) && getline(passFile, existingPass)) {
        if (username == existingUser) {
            userExist = true;
            break;
        }
    }

    userFile.close();
    passFile.close();

    if (userExist) {
        string enteredPass;
        cout << "Enter password: ";
        cin >> enteredPass;

        if (enteredPass == existingPass) {
                system("clear");
            cout << "Login successful!\n";
            main();
        } else {
            cout << "Incorrect password! Try again.\n";
            login();  // Ask for login again
        }
    } else {
        cout << "User does not exist! Redirecting to signup...\n";
        signup();
    }
}
void forgot(){
    system("clear");

    string enteredUser , user , password;
    char* waste = new char;
    cout << "Enter your username: ";
    cin >> enteredUser;

    ifstream userFile("username.txt");
    ifstream passFile("password.txt");

    while(getline(userFile, user) && getline(passFile, password)){
        if(user == enteredUser){
            userFile.close();
            passFile.close();
            break;
        }
    }


    cout << "Your password: " << password << endl;

    cout << "\nPress any key to return to login and signup page.\n";
    cin >> *waste;
    delete waste;
    system("clear");
    main();

}