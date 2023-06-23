#include <iostream>
void sep(){
    system("Color 07");
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
bool thirdpage();
bool firstpage(){
    system("Color 07");
    cout << "1.books list" << endl;
    cout << "2.managers department" << endl;
    cout << "enter your choice:" ;
    int a;
    cin >> a;
    if (a==1){
        booklist view;
        view.printlist();
        sep();
        system("Color 04");
        cout << "do you wanna exit?(y=previos page/n=buy book)";
        char order;
        cin >>order;
        if (order=='y')
            firstpage();
        else {
            system("Color 07");
            booklist buy;
            exchange b;
            string name;
            int num;
            cout << "enter book name:";
            cin >> name;
            float sumt=0;
            int sumb=0;
            ofstream out;
            out.open("factorlist.csv",ios::app);
            out << "book name,book number,price in toman,price in dollar,price in euro,\n";
            out.close();
            while (name!="finish"){
                cout << "enter the number of book that you want:";
                cin >> num;
                sumt+=buy.savefactor(name, num);
                sumb+=num;
                cout << "enter book name(type finish for print factor):";
                cin >> name;
            }
            float sumd=b.convert_dollar(sumt);
            float sume=b.convert_euro(sumt);
            out.open("factorlist.csv",ios::app);
            out << "TOTAL," << sumb << "," << sumt << "," << sumd << "," << sume << endl;
            out << "_____,_____,_____,_____,_____" << endl;
            out.close();
            system("Color 05");
            cout << "FACTOR:" << endl;
            cout << "book name | book number | price in toman | price in dollar | price in euro" << endl;
            buy.printfactor();
            cout << "TOTAL | " << sumb << " | " << sumt << " | " << sumd << " | " << sume << endl;
            sep();
            char ordr;
            system("Color 04");
            cout << "do you wanna go to previous page?(y=previous page/n=complete exit)";
            cin >> ordr;
            if (ordr == 'y')
                firstpage();
            else
                return false;
        }}
        if (a == 2) {
            system("Color 07");
            cout << "1.login" << endl;
            cout << "2.signup" << endl;
            cout << "enter your choice:";
            int d;
            cin >> d;
            if (d == 1) {
                manager y;
                cout << "enter your username:";
                cin >> y.username;
                cout << "enter your password:";
                cin >> y.password;
                while (!y.login()) {
                    system("Color 04");
                    cout << "error!try again." << endl;
                    system("Color 07");
                    cout << "enter your username:";
                    cin >> y.username;
                    cout << "enter your password:";
                    cin >> y.password;
                }
                if (y.login())
                    system("Color 02");
                    cout << "you've logged in successfully!" << endl;
                sep();
                thirdpage();
                return true;
            }
            if (d == 2) {
                system("Color 07");
                manager x;
                cout << "enter username:";
                cin >> x.username;
                while (!x.usernames()) {
                    system("Color 04");
                    cout << "this username have been used.pick a new one :";
                    cin >> x.username;
                }
                system("Color 07");
                cout << "pick a password between (8-16) characters:";
                cin >> x.password;
                while (x.password.length() < 8 || x.password.length() > 16) {
                    system("Color 04");
                    cout << "password is unacceptable.try a new on:";
                    cin >> x.password;
                }
                if (x.signup()) {
                    system("Color 02");
                    cout << "you've logged in successfully!" << endl;
                    sep();
                    thirdpage();
                } return true;
            }
            return false;
        }
    return false;
}
bool thirdpage() {
    system("Color 07");
    cout << "1.add book" << endl;
    cout << "2.edit book" << endl;
    cout << "3.delete book" << endl;
    cout << "4.edit axchange rate"<< endl;
    system("Color 04");
    cout << "5.previous page" << endl;
    system("Color 07");
    cout << "enter your choice:" ;
    int u;
    cin >> u;
    if (u==1){
        system("Color 07");
        string name;
        int number,price;
        booklist b;
        cout << "enter book's name:" ;
        cin >> name;
        cout << "enter book's number:";
        cin >> number;
        cout << "enter book's price in toman:";
        cin >> price;
        b.addbook(name,number,price);
        system("Color 02");
        cout << "book added successfully" << endl;
        sep();
        char order;
        system("Color 04");
        cout << "do you wanna go to previous page?(y=previous page/n=complete exit)";
        cin >>order;
        if (order=='y')
            thirdpage();
        else
            return false;
    }
    if (u==2){
        system("Color 07");
        sep();
        cout << "1.edit a book's name" << endl;
        cout << "2.edit a book's number" << endl;
        cout << "3.edit a book's price" << endl;
        cout << "enter your choise:";
        int r;
        cin >> r;
        if (r==1){
            booklist q;
            string newname,oldname;
            cout << "enter book's old name:";
            cin >> oldname;
            cout << "enter book's new name:";
            cin >> newname;
            q.editname(oldname,newname);
            system("Color 02");
            cout << "book edited successfully" << endl;
            sep();
        }
        if (r==2){
            system("Color 07");
            booklist q;
            string oldname,newnum;
            cout << "enter book's name:";
            cin >> oldname;
            cout << "enter book's new number:";
            cin >> newnum;
            q.editnumber(oldname,stoi(newnum));
            system("Color 02");
            cout << "book edited successfully" << endl;
            sep();
        }
        if (r==3){
            system("Color 07");
            booklist q;
            string oldname,price;
            cout << "enter book's name:";
            cin >> oldname;
            cout << "enter new price in toman:";
            cin >> price;
            q.editprice(oldname,stoi(price));
            system("Color 02");
            cout << "book edited successfully" << endl;
            sep();
        }
        char order;
        system("Color 04");
        cout << "do you wanna go to previous page?(y=previous page/n=complete exit)";
        cin >>order;
        if (order=='y')
            thirdpage();
        else
            return false;
    }
    if (u==3){
        system("Color 07");
        string name;
        cout << "enter name of book:";
        cin >> name;
        booklist b;
        b.deletebook(name);
        system("Color 02");
        cout << "book deleted successfully" << endl;
        char order;
        system("Color 04");
        cout << "do you wanna go to previous page?(y=previous page/n=complete exit)";
        cin >>order;
        if (order=='y')
            thirdpage();
        else
            return false;
    }
    if (u==4){
        system("Color 07");
        int dollar,euro;
        cout << "enter dollar price :";
        cin >> dollar;
        cout << "enter euro price :";
        cin >> euro;
        exchange rate;
        rate.change_rate(dollar,euro);
        system("Color 02");
        cout << "changed successfully!" << endl;
        sep();
        char order;
        system("Color 04");
        cout << "do you wanna go to previous page?(y=previous page/n=complete exit)";
        cin >>order;
        if (order=='y')
            thirdpage();
        else
            return false;
    }
    if (u==5){
        firstpage();
    }
    return false;
}
int main() {
    firstpage();
}