#include "Login.h"

Login::Login() {
    int answer;
    std::cout << "\t \t Welcome \n |-----------------------------------| \n\n";
    std::cout << "Do you want to login or create user ?? \n (Type: 0 for Login, 1 for Create User) \n\n";
    std::cin >> answer;
    std::cout << "\nPlease Enter Your Username: \n";
    std::cin >> m_username;
    std::cout << "Please Enter Your Password: \n";
    std::cin >> m_password;
    if (answer == LOGIN) {
        CheckLogin();
    }else {
        CreateUser();
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
                if (std::to_string(HashPassword())== password) { 
                    std::cout << "Login Completed [+] \n";
                }else { 
                    std::cout << "Invalid Password, Please Retry [!] \n";
                }
            }else { 
                
            }

        }

    }
    if (!is_found) {
        std::cout << "\nUsername cannot find [!] \n";
    }
    std::cout << "\nEXITING \n";
}


void Login::CreateUser() {
    std::ofstream my_file("login.txt", std::ios::app);
    if (my_file.is_open()) {

        my_file << m_username << ":" << HashPassword() << "\n";
        std::cout << "Username and Password Saved [+] \n";
        
    }
}


unsigned long Login::HashPassword() {
    std::hash <std::string> hash;

    unsigned long hashedPassword = hash(m_password);

    return hashedPassword;
}