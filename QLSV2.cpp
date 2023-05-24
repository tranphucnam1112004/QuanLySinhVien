#include<bits/stdc++.h>
#include<conio.h>
#include"windows.h"
using namespace std;
//-------------var------------------
string options_list[5] = {"1. Them sinh vien", "2. Xoa sinh vien", "3. Tim SV bang tuoi", "4. Sua thong tin SV", "5. Xuat danh sach SV"};
string danhmuc = "---DANH MUC---";
int x_border = 45, y_border = 8;
int border_width = 135, border_height = 25;
int op_bd_w = 80 , op_bd_h = 16;
int cs_bd_w = 83, cs_bd_h = 18;
int user_choose = 1;
int x_cur = x_border+5, y_cur = y_border+3;
int x_start = x_cur, y_start = y_cur;
int cnt_list = 0;
int x_show_list = x_border + 9, y_show_list = border_height + 1;
bool enter = false;
bool check_1 = false;

//---------struct/node--------------
struct sinhvien{
    string ten, ns, mssv;
    int tuoi;
};
struct node{
    sinhvien a;
    node *next;
};
node *makenode(sinhvien a){
    node *newnode = new node;
    newnode->a = a;
    newnode->next = NULL;
    return newnode;
}
//------------antimainfunc----------
void gotoXY(short x, short y){
    HANDLE posAt;
    posAt = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos_cur = {x, y};
    SetConsoleCursorPosition(posAt, pos_cur);
}
void draw_border(){
    char c;
    for(int i=y_border; i<=border_height; i++){
        for(int j=x_border; j<=border_width; j++){
            gotoXY(j ,i);
            if(i==y_border){
                if(j==x_border){
                    c = 201;
                }
                else if(j==border_width){
                    c = 187;
                }
                else{
                    c = 205;
                }
            }else if(i == border_height){
                if(j==x_border){
                    c = 200;
                }
                else if(j==border_width){
                    c = 188;
                }
                else{
                    c = 205;
                }
            }else{
                if(j==x_border || j==border_width){
                    c = 186;
                }else{
                    c = ' ';
                }
            }
            cout<<c;
        }
        cout<<endl;
    }
}
void draw_options_border(){
    char c;
    for(int i=y_border+1; i<=op_bd_h; i++){
        for(int j=x_border+2; j<=op_bd_w; j++){
            gotoXY(j ,i);
            if(i==y_border+1){
                if(j==x_border+2){
                    c = 201;
                }
                else if(j==op_bd_w){
                    c = 187;
                }
                else{
                    c = 205;
                }
            }else if(i == op_bd_h){
                if(j==x_border+2){
                    c = 200;
                }
                else if(j==op_bd_w){
                    c = 188;
                }
                else{
                    c = 205;
                }
            }else{
                if(j==x_border+2 || j==op_bd_w){
                    c = 186;
                }else{
                    c = ' ';
                }
            }
            cout<<c;
        }
        cout<<endl;
    }
}
void draw_input_border(){
    char c;
    for(int i=y_border+1; i<=cs_bd_h; i++){
        for(int j=cs_bd_w; j<=border_width-2; j++){
            gotoXY(j ,i);
            if(i==y_border+1){
                if(j==cs_bd_w){
                    c = 201;
                }
                else if(j==border_width-2){
                    c = 187;
                }
                else{
                    c = 205;
                }
            }else if(i == cs_bd_h){
                if(j==cs_bd_w){
                    c = 200;
                }
                else if(j==border_width-2){
                    c = 188;
                }
                else{
                    c = 205;
                }
            }else{
                if(j==cs_bd_w || j==border_width-2){
                    c = 186;
                }else{
                    c = ' ';
                }
            }
            cout<<c;
        }
    }
}
void options(){
    gotoXY(x_border+6, y_border+1+1);
    cout<<danhmuc;
    gotoXY(x_border+6, y_border+1+2);
    cout<<options_list[0];
    gotoXY(x_border+6, y_border+1+3);
    cout<<options_list[1];
    gotoXY(x_border+6, y_border+1+4);
    cout<<options_list[2];
    gotoXY(x_border+6, y_border+1+5);
    cout<<options_list[3];
    gotoXY(x_border+6, y_border+1+6);
    cout<<options_list[4];
}
void reset_data(){
    system("pause");
    cin.ignore();
    system("cls");
    x_cur = x_start, y_cur = y_start;
    user_choose = 1;
    gotoXY(x_start, y_start);
}

//-----------mainfunc------------
void choose(){
    char c;
    int tmp;
    HANDLE posAt;
    posAt = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoXY(x_cur-1, y_cur);
    if(!check_1){
        gotoXY(x_cur, y_cur);
        SetConsoleTextAttribute(posAt, 2);
        c = 175;
        cout<<c;
        int tmp = options_list[user_choose-1].size();
        gotoXY(x_cur + tmp + 1, y_cur);
        c = 174;
        cout<<c;
        SetConsoleTextAttribute(posAt, 7);
        gotoXY(x_cur-1, y_cur);
        check_1 = true;
    }
    char arrow;
    int check_input = 0;
    if(_kbhit()){
        check_input++;
        arrow = _getch();
        if(arrow == -32){
            arrow = _getch();
        }
    }
    if(arrow == 13){
        x_cur = x_start;
        y_cur = y_start;
        enter = true;
        check_1 = false;
        return;
    }else if(arrow == 72){
        if(y_cur - 1 >= y_start && check_input == 1){
            gotoXY(x_cur, y_cur);
            cout<<" ";
            tmp = options_list[user_choose-1].size();
            gotoXY(x_cur + tmp + 1, y_cur);
            cout<<" ";
            y_cur -= 1;
            user_choose-=1;
            gotoXY(x_cur, y_cur);
            SetConsoleTextAttribute(posAt, 2);
            c = 175;
            cout<<c;
            tmp = options_list[user_choose-1].size();
            gotoXY(x_cur + tmp + 1, y_cur);
            c = 174;
            cout<<c;
            SetConsoleTextAttribute(posAt, 7);
            gotoXY(x_cur-1, y_cur);
        }
    }else if(arrow == 80){
        if(y_cur + 1 <= y_start+4 && check_input == 1){
            gotoXY(x_cur, y_cur);
            cout<<" ";
            tmp = options_list[user_choose-1].size();
            gotoXY(x_cur + tmp + 1, y_cur);
            cout<<" ";
            y_cur += 1;
            user_choose+=1;
            gotoXY(x_cur, y_cur);
            SetConsoleTextAttribute(posAt, 2);
            c = 175;
            cout<<c;
            tmp = options_list[user_choose-1].size();
            gotoXY(x_cur + tmp + 1, y_cur);
            c = 174;
            cout<<c;
            SetConsoleTextAttribute(posAt, 7);
            gotoXY(x_cur-1, y_cur);
        }
    }
}
int getAges(string ns){
    int tmp = stoi(ns);
    return 2023 - tmp;
}
int cnt_node(node *head){
    node *tmp = head;
    int cnt = 0;
    while(tmp != NULL){
        ++cnt;
        tmp = tmp -> next;
    }
    return cnt;
}
void sort_ages(node **head){
    for(node *i = *head; i != NULL; i=i->next){
        node *min_pos = i;
        for(node *j = i->next; j != NULL; j=j->next){
            if((j->a).tuoi < (min_pos->a).tuoi){
                min_pos = j;
            }
        }
        sinhvien tmp = (*i).a;
        (*i).a = (*min_pos).a;
        (*min_pos).a = tmp;
    }
}
void input(sinhvien &a){
    while(_kbhit()){
        cin.ignore();
    }
    gotoXY(85, 10);
    cout<<"Nhap ten: ";
    getline(cin, a.ten);
    gotoXY(85, 11);
    cout<<"Nhap nam sinh: ";
    cin>>a.ns;
    gotoXY(85, 12);
    cout<<"Nhap ma so sinh vien: ";
    cin>>a.mssv;
    a.tuoi = getAges(a.ns);
}
void output(node *head){
    char c;
    HANDLE posAt;
    posAt = GetStdHandle(STD_OUTPUT_HANDLE);
    int cnt = 1;
    int line = 10;
    node *tmp = head;
    if(head == NULL){
        gotoXY(85, line++);
        SetConsoleTextAttribute(posAt, 4);
        cout<<"Danh sach rong!!!";
        SetConsoleTextAttribute(posAt, 7);
    }else{
        for(int i=y_show_list; i<=y_show_list+2*(cnt_list+1); i++){
            gotoXY(x_show_list, i);
            for(int j=x_show_list; j<=x_show_list+73; j++){
                if(i==y_show_list){
                    if(j==54){
                        c = 201;
                    }else if(j==58||j==63||j==76){
                        c = 203;
                    }else if(j==127){
                        c = 187;
                    }else{
                        c = 205;
                    }
                }else if(i==y_show_list+2*(cnt_list+1)){
                    if(j==54){
                        c = 200;
                    }else if(j==58||j==63||j==76){
                        c = 202;
                    }else if(j==127){
                        c = 188;
                    }else{
                        c = 205;
                    }
                }else if(i==y_show_list+1){
                    if(j==54||j==58||j==63||j==76||j==127){
                        c = 186;
                        cout<<c;
                    }else if(j==55){
                        cout<<"STT";
                    }else if(j==59){
                        cout<<"Tuoi";
                    }else if(j==64){
                        for(int i=1; i<=4; i++){
                            cout<<" ";
                        }
                        cout<<"MSSV";
                        for(int i=1; i<=4; i++){
                            cout<<" ";
                        }
                    }else if(j==77){
                        for(int i=1; i<=22; i++){
                            cout<<" ";
                        }
                        cout<<"Ten SV";
                        for(int i=1; i<=22; i++){
                            cout<<" ";
                        }
                    }
                    continue;
                }else if(i%2==0){
                    if(j==54){
                        c = 204;
                    }else if(j==58||j==63||j==76){
                        c = 206;
                    }else if(j==127){
                        c = 185;
                    }else{
                        c = 205;
                    }
                }else{
                    if(j==54||j==58||j==63||j==76||j==127){
                        c = 186;
                        cout<<c;
                    }else if(j==55){
                        cout<<setw(3)<<cnt++;
                    }else if(j==59){
                        cout<<setw(4)<<(tmp->a).tuoi;
                    }else if(j==64){
                        cout<<setw(12)<<(tmp->a).mssv;
                    }else if(j==77){
                        cout<<setw(50)<<(tmp->a).ten;
                        tmp=tmp->next;
                    }
                    continue;
                }
                cout<<c;
            }
        }
    }
    gotoXY(0,0);
}
void pushBack(node **head, sinhvien a){
    input(a);
    node *newnode = makenode(a);
    node *tmp = *head;
    if(tmp == NULL){
        *head = newnode;
    }else{
        while(tmp->next != NULL){
            tmp = tmp -> next;
        }
        tmp -> next = newnode;
    }
    sort_ages(head);
}
void popFront(node **head){
    node *tmp = *head;
    if(*head == NULL){
        return;
    }
    *head = (*head) -> next;
    delete tmp;
}
void popBack(node **head){
    node *tmp = *head;
    while(tmp -> next -> next != NULL){
        tmp = tmp -> next;
    }
    delete (tmp->next);
    tmp->next = NULL;
}
void popAtK(node **head, int k){
    if(k==1){
        popFront(head);
        return;
    }
    if(k==cnt_node(*head)){
        popBack(head);
        return;
    }
    node *tmp = *head;
    for(int i=1; i<=k-2; i++){
        tmp = tmp -> next;
    }
    node *del = tmp -> next;
    tmp->next = del->next;
    delete del;
}
void findAges(node *head, int ages){
    int line = 11;
    node *tmp = head;
    int cnt = 0;
    while(tmp != NULL){
        if((tmp->a).tuoi == ages){
            gotoXY(85, line++);
            cnt++;
            cout<<cnt++<<". "<<(tmp->a).mssv<<" "<<(tmp->a).ten<<" "<<(tmp->a).ns<<" "<<(tmp->a).tuoi;
        }
        tmp = tmp -> next;
    }
    if(cnt==0){
        gotoXY(85, line++);
        cout<<"KHONG TIM THAY!!!";
    }
    gotoXY(85, line++);
}
void fixInfor(node **head, int k, string ten, string ns, string mssv){
    node *tmp = *head;
    if(tmp == NULL){
        cout<<"Danh sach rong, khong co sinh vien de sua!!"<<endl;
        return;
    }
    if(k==1){
        ((tmp)->a).ten = ten;
        ((tmp)->a).ns = ns;
        ((tmp)->a).mssv = mssv;
        ((tmp)->a).tuoi = getAges(((tmp)->a).ns);
    }else{
        for(int i=1; i<=k-1; i++){
            tmp = tmp ->next;
        }
        ((tmp)->a).ten = ten;
        ((tmp)->a).ns = ns;
        ((tmp)->a).mssv = mssv;
        ((tmp)->a).tuoi = getAges(((tmp)->a).ns);
    }
}

//-----------------main---------------------
int main(){
    node *head = NULL;
    system("cls");
    while(true){
        draw_border();
        draw_options_border();
        draw_input_border();
        options();
        while(!enter){
            choose();
        }
        switch (user_choose){
            case 1:{
                HANDLE posAt;
                posAt = GetStdHandle(STD_OUTPUT_HANDLE);
                sinhvien a;
                pushBack(&head, a);
                gotoXY(85, 13);
                SetConsoleTextAttribute(posAt, 2);
                cout<<"Da them sinh vien thanh cong!!";
                cnt_list++;
                SetConsoleTextAttribute(posAt, 7);
                gotoXY(85,14);
                reset_data();
                break;
            }
            case 2:{
                HANDLE posAt;
                posAt = GetStdHandle(STD_OUTPUT_HANDLE);
                int line = 10;
                if(head == NULL){
                    gotoXY(85, line++);
                    SetConsoleTextAttribute(posAt, 4);
                    cout<<"Danh sach dang rong, khong the xoa!!";
                    SetConsoleTextAttribute(posAt, 7);
                    gotoXY(85, line++);
                    reset_data();
                    break;
                }
                int k;
                gotoXY(85, line++);
                SetConsoleTextAttribute(posAt, 2);
                cout<<"Nhap vao STT cua sinh vien muon xoa: ";
                SetConsoleTextAttribute(posAt, 7);
                cin>>k;
                if(k<1 || k>cnt_node(head)){
                    gotoXY(85, line++);
                    SetConsoleTextAttribute(posAt, 4);
                    cout<<"Vi tri xoa khong hop le!";
                    SetConsoleTextAttribute(posAt, 7);
                    gotoXY(85, line++);
                    reset_data();
                    break;
                }
                popAtK(&head, k);
                gotoXY(85, line++);
                SetConsoleTextAttribute(posAt, 2);
                cout<<"Da xoa.....";
                cnt_list--;
                SetConsoleTextAttribute(posAt, 7);
                gotoXY(85, line++);
                reset_data();
                break;
            }
            case 3:{
                int line = 10;
                HANDLE posAt;
                posAt = GetStdHandle(STD_OUTPUT_HANDLE);
                if(head == NULL){
                    gotoXY(85, line++);
                    SetConsoleTextAttribute(posAt, 4);
                    cout<<"Danh sach rong!!!";
                    SetConsoleTextAttribute(posAt, 7);
                    gotoXY(85,line++);
                    reset_data();
                    break;
                }
                int tuoi;
                SetConsoleTextAttribute(posAt, 2);
                gotoXY(85, line++);
                cout<<"Nhap tuoi cua sinh vien can tim: ";
                SetConsoleTextAttribute(posAt, 7);
                cin>>tuoi;
                if(tuoi < 0 || tuoi > 100){
                    gotoXY(85, line++);
                    SetConsoleTextAttribute(posAt, 4);
                    cout<<"Tuoi nhap vao khong hop le!!";
                    SetConsoleTextAttribute(posAt, 7);
                    gotoXY(85,line++);
                    reset_data();
                    break;
                }
                findAges(head, tuoi);
                reset_data();
                break;
            }
            case 4:{
                int line = 10;
                HANDLE posAt;
                posAt = GetStdHandle(STD_OUTPUT_HANDLE);
                if(head ==NULL){
                    gotoXY(85,line++);
                    SetConsoleTextAttribute(posAt, 4);
                    cout<<"Danh sach rong!!!";
                    SetConsoleTextAttribute(posAt, 7);
                    gotoXY(85,line++);
                    reset_data();
                    break;
                }
                int k;
                string tenmoi, nsmoi, mssvmoi;
                gotoXY(85,line++);
                SetConsoleTextAttribute(posAt, 2);
                cout<<"Nhap STT cua SV can sua thong tin: ";
                SetConsoleTextAttribute(posAt, 7);
                cin>>k;
                if(k<1 || k>cnt_node(head)){
                    gotoXY(85,line++);
                    cout<<"Vi tri nhap vao khong hop le!!";
                    gotoXY(85,line++);
                    reset_data();
                    break;
                }
                cin.ignore();
                gotoXY(85,line++);
                cout<<"Nhap ten moi: ";
                getline(cin, tenmoi);
                gotoXY(85,line++);
                cout<<"Nhap nam sinh moi: ";
                cin>>nsmoi;
                gotoXY(85,line++);
                cout<<"Nhap mssv moi: ";
                cin>>mssvmoi;
                fixInfor(&head, k, tenmoi, nsmoi, mssvmoi);
                gotoXY(85,line++);
                reset_data();
                break;
            }
            case 5:{
                output(head);
                reset_data();
            }
        }
        enter = false;
    }
    gotoXY(0, 0);
    return 0;
}