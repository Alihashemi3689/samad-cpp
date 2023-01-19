#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
struct user
{
    char *username = new char[100];
    char *password = new char[100];
    char fullname[100];
    char telephone[20];
    char maghta[100];
    char reshte[100];
    int etebar = 0;
};
struct food
{
    char name[100];
    char price[100];
    int count;
    
};
food foods[100];
user *users = new user[10];

int number_of_users = 1, j = 0;

void print_users();

int compare(char a[], char b[])
{
    for (int k = 0; k < 100; k++)
    {

        if (a[k] != b[k])
            return -1;
        if (a[k] == '\0')
            break;
    }
    return 1;
}
void adduser(user new_user)
{
    user *temp = new user[number_of_users + 1];
    for (int i = 0; i < number_of_users; i++)
        temp[i] = users[i];
    temp[number_of_users] = new_user;
    delete[] users;
    users = temp;
    number_of_users++;
}
int isvalid(char c[100])
{
    for (int u = 0; u < number_of_users; u++)
    {
        if (compare(c, users[j].username) == 1)
            return -1;
    }
    return 1;
}
void Exit()
{
    cout << "Good bye" << endl;
    exit(0);
}
void menu();
void user_menu();
void admin_menu()
{
    int x, y = 0;
    while (true)
    {
        cout << "1.add food" << endl;
        cout << "2.logout" << endl;
        cin >> x;
        if (x == 2)
        {
            menu();
            break;
        }
        if (x == 1)
        {
            cout << "add food:" << endl;
            cout << "food : ";
            cin >> foods[y].name;
            cout << "price : ";
            cin >> foods[y].price;
            cout << "count : ";
            cin >> foods[y].count;
        }
        y++;
    }
}
void profile();
void change_password();
void hesab_karbari()
{
    int h;
    cout << "1.profile" << endl;
    cout << "2.change password" << endl;
    cout << "3.user menu" << endl;
    cin >> h;
    if (h == 1)
        profile();
    if (h == 2)
        change_password();
    if (h == 3)
        user_menu();
}
void change_password()
{
    int n;
    char *current_password = new char[100];
    cout << "change password :" << endl;
    cout << "enter current password : ";
    cin.getline(current_password, 100);
    cin.getline(current_password, 100);
    if (compare(current_password, users[j].password) == 1)
    {
        cout << "enter new password : ";
        cin.getline(users[j].password, 100);
        cout << "password changed" << endl;
    }
    if (compare(current_password, users[j].password) == -1)
    {
        cout << "incorrect password" << endl;
    }
    hesab_karbari();
}
void profile()
{
    cout << "username : " << users[j].username << endl;
    cout << "fullname : " << users[j].fullname << endl;
    cout << "telephone : " << users[j].telephone << endl;
    cout << "maghta tahsili : " << users[j].maghta << endl;
    cout << "reshte tahsili : " << users[j].reshte << endl;
    hesab_karbari();
}
void print_users()
{
    for (int i = 0; i < number_of_users; i++)
    {
        cout << "user" << i << ": " << users[i].username << endl;
    }
}
void user_menu()
{
    int x, y;
    while (true)
    {
        cout << "1.hesab karbari" << endl;
        cout << "2.samane taghzie" << endl;
        cout << "3.logout" << endl;
        cin >> x;
        if (x == 3)
        {
            menu();
            break;
        }
        if (x == 1)
            hesab_karbari();
        if (x == 2)
        {
            cout << "1.reserve ghaza" << endl;
            cout << "2.afzayesh etebar" << endl;
            cout << "3.kod faramooshi" << endl;
            cout << "4.enteghal etebar" << endl;
            cout << "5.gozaresh amalkard" << endl;
            cout << "6.gozaresh amaliyat" << endl;
            cout << "7.gozarsh mali" << endl;
        }
    }
}

void signup()
{
    user newuser;
    cout << "username : ";
    cin.getline(newuser.username, 100);
    cin.getline(newuser.username, 100);
    while (isvalid(newuser.username) == -1)
    {
        cout << "unavailable username" << endl;
        cout << "username : ";
        cin.getline(newuser.username, 100);
    }
    cout << "password : ";
    cin.getline(newuser.password, 100);
    cout << "fullname : ";
    cin.getline(newuser.fullname, 100);
    cout << "telephone : ";
    cin >> newuser.telephone;
    cout << "maghta tahsili : ";
    cin >> newuser.maghta;
    cout << "reshte : ";
    cin >> newuser.reshte;
    adduser(newuser);
    cout << "signup completed now you can login" << endl;
    menu();
}
void login()
{
    user temp;
    cout << "login :" << endl;
    cout << "username : ";
    cin.getline(temp.username, 100);
    cin.getline(temp.username, 100);
    int number;
    for (j = 0; j < number_of_users; j++)
    {
        cout << users[j].username << " $ " << temp.username << endl;
        if (compare(users[j].username, temp.username) == 1)
            break;
    }
    if (j != number_of_users)
    {
        cout << "password : ";
        cin.getline(temp.password, 100);
        if (compare(temp.password, users[j].password) == 1)
        {
            cout << "login succesful" << endl;
            if (j == 0)
                admin_menu();
            else
                user_menu();
        }
        else
        {
            cout << "incorrect password" << endl;
            cout << "1.login" << endl;
            cout << "2.exit" << endl;
            cin >> number;
            if (number == 1)
                login();
            if (number == 2)
                Exit();
        }
    }
    else
    {
        cout << "user not found" << endl;
        cout << "1.signup" << endl;
        cout << "2.login" << endl;
        cout << "3.exit" << endl;
        cin >> number;
        if (number == 1)
            signup();
        if (number == 2)
            login();
        if (number == 3)
            Exit();
    }
}
void menu()
{
    print_users();
    int x;
    cout << "1.signup" << endl;
    cout << "2.login" << endl;
    cout << "3.exit" << endl;
    cin >> x;
    if (x == 1)
        signup();
    if (x == 2)
        login();
    if (x == 3)
        Exit();
}
int main()
{
    users[0].username[0] = 'a';
    users[0].username[1] = 'd';
    users[0].username[2] = 'm';
    users[0].username[3] = 'i';
    users[0].username[4] = 'n';
    users[0].username[5] = '\0';

    users[0].password[0] = 'a';
    users[0].password[1] = 'd';
    users[0].password[2] = 'm';
    users[0].password[3] = 'i';
    users[0].password[4] = 'n';
    users[0].password[5] = '1';
    users[0].password[6] = '2';
    users[0].password[7] = '3';
    users[0].password[8] = '4';
    users[0].password[9] = '\0';

    menu();
    return 0;
}
