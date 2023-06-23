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
using namespace std;
class booknode{
public:
    string name;
    string number;
    string price;
};
class exchange{
public:
    int dollar;
    int euro;
    float convert_dollar (float t){
        ifstream in;
        in.open("exchange.txt");
        in >> dollar ;
        t=t/dollar;
        return t;
    }
    float convert_euro(float t){
        ifstream in ;
        in.open("exchange.txt");
        while ((!in.eof())){
            in >> euro;
        }
        t=t/euro;
        return t;
    }
    void change_rate(int dolar, int eur){
        ofstream out;
        out.open("exchange.txt");
        out << dolar << endl << eur << endl;
    }
};
class booklist : public exchange{
public:
    void addbook(string bookname, int number, int price) {
        ofstream file;
        file.open("booklist.txt", ios::app);
        file << bookname << endl << number << endl << price << endl;
        file.close();
    }
    void deletebook(string name) {
        ifstream in;
        ofstream out;
        in.open("booklist.txt");
        out.open("tmp.txt");
        booknode* a=new booknode;
        while (!in.eof()) {
            in >> a->name >> a->number >> a->price ;
            if (a->name!=name)
                out << a->name << endl << a->number << endl << a->price << endl;
        }
        in.close();
        out.close();
        remove("booklist.txt") ;
        rename("tmp.txt","booklist.txt");
    }
    bool checkfile(string path,string name){
        ifstream in(path);
        string temp;
        while(!in.eof()){
            getline (in,temp);
            if (temp==name)
                return false;
        }
        return true;
        in.close();
    }
    void editname(string oldname,string newname){
        booknode* tmp = new booknode;
        ifstream in;
        fstream out;
        in.open("booklist.txt");
        out.open("tmp.txt",ios::app);
        while(!in.eof()){
            in >> tmp->name >> tmp->number >> tmp->price;
            if (tmp->name==oldname) {
                if (checkfile("tmp.txt",newname))
                    out << newname << endl << tmp->number << endl << tmp->price << endl;
            }
            else {
                if (checkfile("tmp.txt",tmp->name))
                    out << tmp->name << endl << tmp->number << endl << tmp->price << endl;
            }
        }
        out.close();
        in.close();
        delete tmp;
        remove("booklist.txt") ;
        rename("tmp.txt","booklist.txt");
    }
    void editprice(string oldname,int newprice){
        booknode* tmp = new booknode;
        ifstream in;
        fstream out;
        in.open("booklist.txt");
        out.open("tmp.txt",ios::app);
        while(!in.eof()){
            in >> tmp->name >> tmp->number >> tmp->price;
            if (tmp->name==oldname) {
                if (checkfile("tmp.txt",tmp->name))
                    out << tmp->name << endl << tmp->number << endl << newprice << endl;
            }
            else {
                if (checkfile("tmp.txt",tmp->name))
                    out << tmp->name << endl << tmp->number << endl << tmp->price << endl;
            }
        }
        out.close();
        in.close();
        delete tmp;
        remove("booklist.txt") ;
        rename("tmp.txt","booklist.txt");
    }
    void editnumber(string oldname,int newnum){
        booknode* tmp = new booknode;
        ifstream in;
        fstream out;
        in.open("booklist.txt");
        out.open("tmp.txt",ios::app);
        while(!in.eof()){
            in >> tmp->name >> tmp->number >> tmp->price;
            if (tmp->name==oldname) {
                if (checkfile("tmp.txt",tmp->name))
                    out << tmp->name << endl << newnum << endl << tmp->price << endl;
            }
            else {
                if (checkfile("tmp.txt",tmp->name))
                    out << tmp->name << endl << tmp->number << endl << tmp->price << endl;
            }
        }
        out.close();
        in.close();
        delete tmp;
        remove("booklist.txt") ;
        rename("tmp.txt","booklist.txt");
    }
    void printlist(){
        ifstream in("booklist.txt");
        system("Color 05");
        int i=1;
        booknode* temp = new booknode;
        cout << "book's name" << " | " << "book's ID" << " | " << "book's number" << " | " << "book price in toman" << " | " << "book price in dollar" << " | " << "book price in euro" <<endl;
        while(!in.eof()) {
            getline(in,temp->name);
            if (temp->name.length()<2)
                break;
            getline(in,temp->number);
            getline(in,temp->price);
            cout << i << ")" << temp->name << " | " << temp->number << " | " << temp->price << " | " << convert_dollar(stof(temp->price)) << " | " << convert_euro(stof(temp->price)) << endl ;
            i++;
        }
        delete temp;
        in.close();
    }
    int savefactor(string name,int num){
        ofstream out;
        fstream temp;
        ifstream in;
        float t = 0,d=0,e=0;
        in.open("booklist.txt",ios::in);
        out.open("factorlist.csv",ios::app);
        temp.open("temp.csv",ios::app);
        booknode* tmp = new booknode;
        while(!in.eof()){
            in >> tmp->name >> tmp->number >> tmp->price;
                if (tmp->name == name) {
                    if (stoi(tmp->number) >= num) {
                        t = stof(tmp->price) * num;
                        d = convert_dollar(t);
                        e = convert_euro(t);
                        out << tmp->name << "," << num << "," << t << "," << d << "," << e << endl;
                        temp << tmp->name << "," << num << "," << t << "," << d << "," << e << endl;
                        temp.close();
                        in.close();
                        out.close();
                        if (stoi((tmp->number))-num>0)
                            editnumber(tmp->name,stoi(tmp->number)-num);
                        else if (stoi(tmp->number)-num==0)
                            deletebook(tmp->name);
                        break;
                    }
                    else {
                        cout << "not enough book in store!" << endl;
                        break;
                    }
            }
        }
        delete tmp;
        return t;
    }
    void printfactor(){
        system("Color 05");
        fstream temp;
        temp.open("temp.csv",ios::in);
        string line;

        while (!temp.eof()) {
            getline(temp, line, '\n');
            cout << line << endl;
        }
        cout << "---------------------------------------" << endl;
        temp.close();
        remove("temp.csv");
    }
};
int main() {
}
