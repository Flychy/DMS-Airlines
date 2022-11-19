#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<math.h>
#include<bits/stdc++.h>
#define AN_MAX  9999
#define AN_MIN  2021

using namespace std;

int global_login;
int x, y, n, t, i, flag;
long int e[50], d[50], temp[50], j;
char en[50], m[50];
//int prime(long int);
//void encryption_key();
//long int cd(long int);
//void encrypt();
//void decrypt();

class Operator
{
public:
    string op_username;
    string op_password;
    string op_passw_conf;
    string op_name_check;
    string op_usr, op_line, op_pass, op_em;
    string zbor;
    string data;
    int zi, luna, an;
    string fly_check;
    string op_bio;

    int checker;

    ofstream fileroo;
    ifstream fileroi;

    void op_login()
    {
        int optiune;
        cout<<"\nNume de operator: ";
        cin>>op_username;
        cout<<"\nParola: ";
        cin>>op_password;
        op_name_check = op_username + "_op.txt";
        fileroi.open(op_name_check.c_str());
        if(!fileroi.is_open() && fileroi.fail())
        {
            throw"\nLogin nereusit!\n";
            fileroi.close();
            // continue;
        }
        getline(fileroi,op_usr);
        getline(fileroi,op_line);
        getline(fileroi,op_pass);
        if(op_usr == op_username && op_pass == op_password)
        {
            cout<<"\n V-ati logat cu succes!\n Profilul dumneavoastra: ";
            cout<<"\n Nume de operator: " << op_usr;
            getline(fileroi,op_line);
            fileroi.close();
            global_login = 1;

        }
        else
        {
            throw"\n Login incorect, user sau parola gresite!\n";
        }
    }

    void add_Fly()
    {
        int i;
        int counter = 0;

        cout << "\n\n Introduceti un zbor : ";
        cin >> zbor;

        for (i = 0; i < zbor.length(); i++)
        {
            if(!((zbor[i]<= 'z' && zbor[i] >= 'a') || (zbor[i] <= 'Z' && zbor[i] >= 'A')))
            {
                counter++;
            }
        }
        if(counter > 0)
        {
            throw "\n Caractere neexistente in numele zborului!";
        }

        cout << "\n Introduceti o data valida pentru zbor : ";
        cout << "\n Ziua: ";
        cin >> zi;
        cout << "\n Luna: ";
        cin >> luna;
        cout << "\n An: ";
        cin >> an;
        // consideram ziua curenta 13.12.2021
        if(zi < 13 && (luna <= 12 && an <= 2021))
        {
            throw "\n Ne pare rau, zborul a plecat catre destinatie!";
        }
        else
        {
            if((luna == 1 || luna == 3 || luna == 5 || luna == 7 || luna == 8 || luna == 10 || luna == 12) && (zi < 1 || zi > 31))
            {
                throw "\n Format data, invalida! Zi inexistenta!";
            }
            if(luna == 2 && (zi > 28 || zi < 1))
            {
                throw "\n Format data invalida! Zi inexistenta!";
            }
            if(luna > 12 || luna < 1)
            {
                throw "\n Format data invalida! Luna inexistenta!";
            }
        }


        fly_check = zbor + "_fly.txt";
        fileroo.open(fly_check.c_str());
        fileroo<<zbor<<"\n\n"<<data<<"\n";

        cout <<"\n Zborul a fost introdus cu succes!";
        cout <<"\n Adaugati cateva detalii legate de zbor(daca este necesar): ";
        cin.ignore();
        getline(cin,op_bio);
        fileroo<<op_bio<<"\n";
        cout<<"\n Detaliile: "<<op_bio;
        fileroo.close();
    }
    void delete_Fly()
    {
        int status;
        char fileName[60];
        cout<< "\nIntroduceti numele fisierului: ";
        cin >>fileName;
        status = remove(fileName);
        if(status == 0)
        {
            cout<<"\nFisier eliminat cu succes!";
        }
        else
        {
            throw "\n Eroare!";
        }
    }

};


bool isChar(char c);
bool isDigit(const char c);

class Utilizator
{
public:
    string username;
    string password;
    string passw_conf;
    string email;
    string name_check;
    string usr, line, pass,em;
    string bio;
    string zbor;
    string data;
    string zbr, dt;
    string fly_check;


    int level;
    int tm;

    ofstream fileo;
    ifstream filei;


    //functie ce verifica integritatea numelui de utilizator
    void valid(string str)
    {
        string dir, user;

        ifstream file;

        dir =str+".txt";
        file.open(dir.c_str());

        if(!file.is_open() && file.fail())
        {
            return;
        }
        else
        {
            tm++;
            if(tm == 3)
            {
                cout<<"\nNumele de utilizator este folosit!\nIncercati din nou...";
                return;
            }
            cout<<"\nNumele de utilizator este folosit!\nCreati un nume de utilizator: ";
            cin>>username;
            valid(username);
        }
    }
    void valid_database(string str)
    {
        string dir, eml;

        ifstream fisier;

        dir =str+".txt";
        fisier.open(dir.c_str());

        if(!fisier.is_open() && fisier.fail())
        {
            return;
        }
        else
        {
            tm++;
            if(tm == 2)
            {
                cout<<"\nEmailul a fost utilizat de catre o alta persoana, incercati din nou...";
                return;
            }
            cout<<"\nEmailul este utilizat!\n Introduceti o adresa de email:  ";
            cin>>email;
            valid_database(email);
        }
    }
    //functie ce verifica corectitudinea  adresei de email
    bool valid_email(string email)
    {
        //Verificam daca primul caracter se afla in alfabet sau nu
        if (!isChar(email[0]))
        {

            // In momentul in care caracterul nu se afla in alfabet
            // adresa de email e considerata nevalida
            return 0;
        }

        int arnd = -1, punct = -1;

        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@')
            {

                arnd = i;
            }

            else if (email[i] == '.')
            {

                punct = i;
            }
        }

        if (arnd == -1 || punct == -1)
        {
            return 0;
        }

        if (arnd > punct)
        {
            return 0;
        }


        return !(punct >= (email.length() - 1));
    }

    /*Ideea functiei de detectare a nivelului de securitate
    a parolei
    Sunt urmariti urmatorii indici:
    -trebuie sa contina 1 litera mica
    -trebuie sa contina 1 litera mare
    -trebuie sa contina o cifra
    -trebuie sa contina caractere speciale ex: ^, &, @ ,etc.

    In momentul in care parola contine toate aceste elemente
    este considerata puternia, daca contine doar litere mici
    este considerata slaba, iar in situatia in care contine
    elemente combinate ale listei este considerata avand un
    nivel mediu*/

    void nivel_parola(string& element)
    {

        int n = element.length();
        int i;

        bool hasLower = false, hasUpper = false;
        bool hasDigit = false, specialChar = false;

        string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

        for (i = 0; i < n; i++)
        {
            if (islower(element[i]))
            {
                hasLower = true;
            }
            if (isupper(element[i]))
            {
                hasUpper = true;
            }
            if (isdigit(element[i]))
            {
                hasDigit = true;
            }

            //am utilizat size_t pentru a returna dimensiunea maxima
            /*am utilizat find_first_not_of pentru a cauta primul caracter
            ce nu corespunde caracterelor de tipul normal declarate ceva
            mai sus*/
            size_t special = element.find_first_not_of(normalChars);
            if (special != string::npos)
            {
                specialChar = true;
            }
        }

        cout << " \nNivelul de securitate al parolei : ";
        if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8))
        {
            cout << " Puternic";
            level = 3;
        }
        else
        {
            if ((hasLower || hasUpper) && specialChar && (n >= 6))
            {
                cout << " Mediu";
                level = 2;
            }
            else
            {
                cout << " Slab";
                level = 1;
            }
        }

    }


    void login()
    {


        cout<<"\nNume de utilizator: ";
        cin>>username;
        cout<<"\nParola: ";
        cin>>password;
        name_check = username + ".txt";
        filei.open(name_check.c_str());
        if(!filei.is_open() && filei.fail())
        {
            throw"\nNumele de utilizator introdus nu apartine unui cont, pentru inregistrare apasati 1!\n";
            filei.close();
            // continue;
        }
        getline(filei,usr);
        getline(filei,line);
        getline(filei,pass);
        if(usr == username && pass == password)
        {
            cout<<"\n V-ati logat cu succes!\n Profilul dumneavoastra: ";
            cout<<"\n Nume de utilizator: " << usr;
            cout<<"\n email: " << line;
            getline(filei,line);
            cout<<"\n Zboruri: "<< line;
            filei.close();

        }
        else
        {
            throw"\n Nume de utilizator sau parola incorecte!\n Incercati din nou...\n";
        }
    }
    void register_user()
    {
        cout<<"\n Introduceti un email valid: ";
        cin>>email;
        tm = 0;
        valid_database(email);
        bool ver = valid_email(email);
        if(!ver)
        {
            throw "\n Adresa de email nu este valida!\n Selectiati optiunea de inregistrare si incercati din nou...  ";
        }


        cout<<"\n Introduceti un nume de utilizator: ";
        cin>>username;
        tm = 0;
        valid(username);
//        if(tm >= 3)
//        {
//            continue;
//        }
        cout<<"\n Introduceti o parola: ";
        cin>>password;

        cout<<"\n Introduceti confirmarea parolei: ";
        cin>>passw_conf;

        if(password != passw_conf)
        {
            throw "\n Confirmare a parolei gresite\n Selectati optiunea de inregistrare si incercati din nou...";
        }
        nivel_parola(password);
        if(level == 1)
        {
            throw "\n Parola este slaba! Va rugam, introduceti o parola mai puternica!";
        }
        take_Fly();

        name_check = username + ".txt";
        fileo.open(name_check.c_str());
        fileo<<username<<"\n"<<email<<"\n"<<password<<"\n"<<zbor<<"\n";

        cout<<"\n Te-ai inregistrat cu succes!";

        getline(cin,bio);
        fileo.close();


        cout<<"\n Parola criptata este: ";
        pseudo_main();
        fileo.close();

    }
    void take_Fly()
    {

        cout<<"\n\n Numele tarii catre care calatoriti: ";
        cin>>zbor;

        cout<<"\nData: ";
        cin>>data;

        name_check = zbor + "_fly.txt";
        filei.open(name_check.c_str());

        if(!filei.is_open() && filei.fail())
        {
            throw"\n Zbor inexistent!\n";
            filei.close();
            // continue;
        }
        getline(filei,zbr);
        getline(filei,line);
        getline(filei,dt);

        if(zbr == zbor && dt == data)
        {
            cout<<"\n Zbor inregistrat cu succes!\n Calatoria dumneavoastra: ";
            cout<<"\n Romania --->  " << zbr;
            getline(filei,line);
            filei.close();
        }
        else
        {
            throw"\n Detalii gresite la rezervarea zborului!\n";
        }
    }
    int pseudo_main()
    {

        x=7;


        flag = prime(x);
        if(flag == 0)
        {
            cout << "\nINVALID INPUT\n";
            exit(0);
        }


        y=13;
        flag = prime(y);
        if(flag == 0 || x == y)
        {
            cout << "\nINVALID INPUT\n";
            exit(0);
        }



        for(i = 0; passw_conf[i] != '\0'; i++)
            m[i] = passw_conf[i];
        n = x * y;
        t = (x - 1) * (y - 1);

        encryption_key();
        encrypt();
//   decrypt();
        return 0;
    }

    int prime(long int pr)
    {
        int i;
        j = sqrt(pr);
        for(i = 2; i <= j; i++)
        {
            if(pr % i == 0)
                return 0;
        }
        return 1;
    }

    void encryption_key()
    {
        int k;
        k = 0;
        for(i = 2; i < t; i++)
        {
            if(t % i == 0)
                continue;
            flag = prime(i);
            if(flag == 1 && i != x && i != y)
            {
                e[k] = i;
                flag = cd(e[k]);
                if(flag > 0)
                {
                    d[k] = flag;
                    k++;
                }
                if(k == 99)
                    break;
            }
        }
    }

    long int cd(long int a)
    {
        long int k = 1;
        while(1)
        {
            k = k + t;
            if(k % a == 0)
                return(k/a);
        }
    }


    void encrypt()
    {
        long int pt, ct, key = e[0], k, len;
        i = 0;
        len = passw_conf.length();

        while(i != len)
        {
            pt = m[i];
            pt = pt - 96;
            k = 1;
            for(j = 0; j < key; j++)
            {
                k = k * pt;
                k = k % n;
            }
            temp[i] = k;
            ct= k + 96;
            en[i] = ct;
            i++;
        }
        en[i] = -1;
        for(i=0; en[i] != -1; i++)
            cout << en[i];
    }
    void decrypt()
    {
        long int pt, ct, key = d[0], k;
        i = 0;
        while(en[i] != -1)
        {
            ct = temp[i];
            k = 1;
            for(j = 0; j < key; j++)
            {
                k = k * ct;
                k = k % n;
            }
            pt = k + 96;
            m[i] = pt;
            i++;
        }
        m[i] = -1;
        for(i = 0; m[i] != -1; i++)
            cout << m[i];

        cout << endl;
    }

};

void main_menu()
{
    int first_choice;
    int op_choice;
    int choice;
    int optiune;
    int optiune_operator;
    int exit = 0;

    cout<<"\nAlegeti tipul profilului : \n"
        "\n [0] {OP} Operator"
        "\n [10] {USR} Utilizator ";
    cout<<"\n\n==> Introduceti o optiune (0/10) : ";
    cin >> first_choice;
    if(first_choice == 0)
    {
        cout << "\nTe afli in meniul de operator, introdu detaliile de logare.\n";

        Operator op_log;
        try
        {
            op_log.op_login();
        }
        catch(char const* msj)
        {
            cerr << msj;
        }
        if(global_login == 1)
        {
            cout << "\n\n<><><> Bun venit in meniul de operator <><><>"
                 "\n <1> Adaugare zboruri"
                 "\n <2> Stergere zboruri";
            cout << "\n Optiunea dvs: ";
            cin >> optiune_operator;
            switch (optiune_operator)
            {
            case 1:
            {
                try
                {
                    op_log.add_Fly();
                }
                catch(char const* err)
                {
                    cerr <<err;
                }
                break;
            }
            case 2:
            {
                try
                {
                    op_log.delete_Fly();
                }
                catch(char const* err)
                {
                    cerr <<err;
                }
                break;
            }

            }
        }

    }
    else
    {
        cout<<"\n -->Alegeti o optiune\n "
            "\n [1] Sing In"
            "\n [2] Sing up"
            "\n [3] Exit";
        while(exit == 0)
        {
            cout<<"\n\n -->Introduceti optiunea: ";
            cin >> choice;


            switch (choice)
            {
            case 1:
            {
                Utilizator user;
                try
                {
                    user.login();
                }
                catch(char const* msg)
                {
                    cerr << msg;
                }
                break;
            }
            case 2:
            {
                Utilizator regis;
                try
                {
                    regis.register_user();
                }
                catch(char const* ms)
                {
                    cerr << ms;
                }
                break;
            }
            case 3:
            {
                exit == 1;
                break;
            }
            }
        }
    }
}

int main ()
{
    cout<<"-----------";
    cout<<"\n Simy-air |";
    cout<<"\n-----------\n";

    cout<<"\n\n\t ---------->>BINE ATI VENIT!<<----------\n\n";
    main_menu();

    cout<<"\n\n\t ---------->>Va multumim pentru vizita!<<----------\n\n";
    return 0;
}

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}
