#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Login{
public:
    enum LoginType{
        LOGIN = 0,
        CREATE_USER
    };
    void CreateUser();
    Login();
    void GetValuesFromUser();
    void CheckLogin();
    std::string HashPassword();

private:
    std::ofstream my_file;
    std::string m_username;
    std::string m_password;
    LoginType m_answer;
};