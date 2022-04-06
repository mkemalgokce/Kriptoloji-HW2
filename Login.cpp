#include "Login.h"

Login::Login() {
    GetValuesFromUser();
    if (m_answer == LOGIN) {
        CheckLogin();
    }else {
        CreateUser();
    }
    std::cout << "\n [!!!!!!!]  EXITING  [!!!!!!!] \n";
}

void Login::GetValuesFromUser() {
    int answer;
    std::cout << "\t \t Welcome \n |-----------------------------------| \n\n";
    std::cout << "Do you want to login or create user ?? \n (Type: 0 for Login, 1 for Create User) \n\n";
    std::cin >> answer;
    std::cout << "\nPlease Enter Your Username: \n";
    std::cin >> m_username;
    std::cout << "Please Enter Your Password: \n";
    std::cin >> m_password;
    if(answer == 0) {
        m_answer = LOGIN;
    }else {
        m_answer = CREATE_USER;
    }

}
void Login::CheckLogin() {
    std::ifstream my_file("login.txt");
    std::string satir;
    bool is_found = false;
    if (my_file.is_open()) { 
        while(std::getline(my_file, satir)) {
            int pos = satir.find(":");
            std::string username = satir.substr(0, pos);
            std::string password = satir.substr(pos+1, ((satir.length() - m_username.length()) + 1));
            
            if (m_username == username) {
                is_found = true;
                if (HashPassword() == password) { 
                    std::cout << "Login Completed [+] \n";
                }else { 
                    std::cout << "Invalid Password, Please Retry [!] \n";
                }
            }
        }

    }
    if (!is_found) {
        std::cout << "\nUsername cannot find [!] \n";
    }
    
}


void Login::CreateUser() {
    std::ofstream my_file("login.txt", std::ios::app);
    if (my_file.is_open()) {

        my_file << m_username << ":" << HashPassword() << "\n";
        std::cout << "\nUsername and Password Saved [+] \n";
        
    }
}


std::string Login::HashPassword() {
    std::hash <std::string> hash;

    unsigned long hashedPassword = hash(m_password);

    return std::to_string(hashedPassword);
}