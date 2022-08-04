#include <iostream>
#include<vector>
using namespace std;

class Person{
protected:
    string fname;
    string lname;
    string email;
    string phone_number;
    double password;

public:
   Person():fname("0"),lname("0"),email("0"),phone_number("0"),password(0){
   }
    Person(string n,string l,string e,string pn,double p){
       Set_FName(n);
       Set_LName(l);
       Set_Email(e);
       Set_Phone_Number(pn);
       Set_Password(p);
   }


       void Set_FName(string n){
        fname=n;
       }
       const string &Get_FName()const {
        return fname;
       }


        void Set_LName(string ln){
        lname=ln;
       }
       const string &Get_LName()const {
        return lname;
       }


       void Set_Email(string e){
        email=e;
       }
       const string &Get_Email()const {
        return email;
       }


       void Set_Phone_Number(string ph){
        phone_number=ph;
       }
       const string &Get_Phone_Number()const {
        return phone_number;
       }


        void Set_Password(double pw){
        password=pw;
       }
        double Get_Password()const {
        return password;
       }

};

class User:public Person{
private:

    double balance;

public:
    User():balance(0),Person("0","0","0","0",0){
    }

    User(string n,string l,string e,string pn,double p,double b):Person(n,l,e,pn,p){
    Set_Balance(b);
    }

      void Set_Balance(double b){
      balance=b;
      }
      double Get_Balance()const{
      return balance;
      }

      void Add_Account(){
          char t;
          do{
          system("cls");
          string str;
          cout<<"------------------------------ Enter Your Information -------------------------"<<endl<<endl;

          cout<<"Enter Your First Name: ";
          cin>>str;
         Set_FName(str);

          cout<<"Enter Your Last Name: ";
          cin>>str;
          Set_LName(str);

          cout<<"Enter Your Email: ";
          cin>>str;
          Set_Email(str);

          cout<<"Enter Your Phone Number: ";
          cin>>str;
          Set_Phone_Number(str);

          double num;
          cout<<"Enter Your Password: ";
          cin>>num;
          Set_Password(num);

          double num1;
          cout<<"Enter Your Net Balance: ";
          cin>>num1;
          Set_Balance(num1);

          system("cls");
          cout<<"\n\n\n\n\n\n\t\t\tYour Account Has Been Made Successfully"<<endl;
          cout<<"\n\n\n\n\n\n\t\t\tEnter t To Make A Edit To Your Account 3Or f To Return To Main Menu: ";
          cin>>t;
          }while(t=='t');

      }

      void Show_Account_Details(){
            cout<<"------------------------------ Your Account Information -------------------------"<<endl<<endl;

            cout<<"Name: "<<fname<<lname<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Phone No. :"<<phone_number<<endl;
            cout<<"Balance: "<<balance<<endl;
      }

      void Deposit(){
            double amount;
            cout<<"\nEnter The Amount That You Want To Deposit: ";
            cin>>amount;

            if(amount<=0){
                cout<<"\nInvalid Amount!!"<<endl;
                Deposit();
            }

           balance=Get_Balance()+amount;
      }


      void Withdraw(){
            double amount;
            cout<<"\nEnter The Amount That You Want To Withdraw: ";
            cin>>amount;

            if(amount>Get_Balance()){
                cout<<"\nInvalid Amount!!"<<endl;
                Withdraw();
            }

            balance=Get_Balance()-amount;
      }





};


class Manger{
private:

       vector<User> v;


public:

    void load_data(){
    /////// use a dommy data from your mind ////////////
    }

    void run(){

        int choice;
        system("cls");
        system("Color 9");

load_data();
        while(1){



        cout<<"\t\t------------------- Welcome To Our Bank Management System ------------------- "<<endl;
        cout<<"\n\n\n\t\t\tMAIN MENU";
        cout<<"\n\t\t\t 1) OPEN AN ACCOUNT";
        cout<<"\n\t\t\t 2) SHOW ACCOUNT DETAILS";
        cout<<"\n\t\t\t 3) DEPOSIT";
        cout<<"\n\t\t\t 4) WITHDRAW";
        cout<<"\n\t\t\t 5) SEARCH FOR AN ACCOUNT";
        cout<<"\n\t\t\t 6) EXIT";
        cout<<"\n\t\t\t  ENTER YOUR CHOICE: ";
        cin>>choice;

    switch(choice){

        case 1:

            Add_Account(v);
            break;

        case 2:

            Show_Account_Details();
            break;

        case 3:

            Deposit();
            break;

        case 4:

            Withdraw();
            break;

        case 5:

            search_by_first_name();
            break;

        case 6:
            exit(6);
            break;

        default:
            continue;
    }

}


}

     void Show_Account_Details(){

             for(int i=0;i<v.size();i++){
            v[i].Show_Account_Details();
             }


     }


     void search_by_first_name(){
            string str;
            cout<<"\nEnter Your First Name: ";
            cin>>str;

            for(int i=0;i<v.size();i++){
                if(v[i].Get_FName()==str)
                v[i].Show_Account_Details();
                }
      }


      void Add_Account(vector<User>&n){
          User q;
          q.Add_Account();
          n.push_back(q);
}


      void Deposit(){


            string str;
            cout<<"Enter Your First Name: ";
            cin>>str;

            double ps;
            cout<<"Enter Your Password: ";
            cin>>ps;


       for(int i=0;i<v.size();i++){
            if((v[i].Get_FName()==str )&&(v[i].Get_Password()==ps)){
                v[i].Deposit();
                return;
                }

            }
       }



      void Withdraw(){


            string str;
            cout<<"Enter Your First Name: ";
            cin>>str;

            double ps;
            cout<<"Enter Your Password: ";
            cin>>ps;


       for(int i=0;i<v.size();i++){
            if((v[i].Get_FName()==str )&&(v[i].Get_Password()==ps)){
                v[i].Withdraw();
                return;
                }


            }

       }





};

int main(){
    Manger a;
a.run();
}
