#include <iostream>
#include <fstream>
#include <cstdio>
class manager {
public:
    string username;
    string password;
    bool login() {
        ifstream file;
        file.open("password.txt",ios::app);
        if (file.is_open()){
            string user,pass;
            while (!file.eof()) {
                file >> user >> pass;
                if (this->username==user && this->password == pass) {
                    return true;
                }
            }
            file.close();

        }
        return false;
    }
    bool signup(){
       ofstream file;
       file.open("password.txt",ios::app);
       if (file.is_open()){
           file << this->username << endl;
           file << this->password << endl;
           return true;
       }
       file.close();
       return false;
    }
    bool usernames(){
        ifstream file;
        file.open("password.txt");
        if (file.is_open()){
            string user;
            while (!file.eof()){
                file >> user;
                if (this->username==user)
                    return false;
            }
        }
        file.close();
        return true;
    }
};
int main() {
}
