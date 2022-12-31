#include<bits/stdc++.h>
#include<conio.h>
#include <cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

void menuUtama(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "Silahkan Pilih Menu " << endl;
    cout << "1. Scholl Help\n";
    cout << "2. Volunteer\n";
    cout << "3. School Admin\n";
}

void menuSchoolHelp(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "\tMenu School Help" << endl;
    cout << "1. School Register\n";
    cout << "2. Admin School Register\n";
}

void menuVolunteer(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "\tMenu Volunteer" << endl;
    cout << "1. Register\n";
    cout << "2. Login\n";
}

void subMenuVolunteer(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "  Menu Volunteer [View Request]" << endl;
    cout << "1. Sorted by School\n";
    cout << "2. Sorted by City\n";
    cout << "3. Sorted by Date\n";
}

void menuSchoolAdmin(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "\tMenu School Admin" << endl;
    cout << "1. Request Help\n";
    cout << "2. Review Offers\n";
}

void subMenuSchoolAdmin(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "        Type of Request         " << endl;
    cout << "1. Tutorial Request\n";
    cout << "2. Resource Request\n";
}

void subMenuSchoolAdmin2(){
    cout << "================================"<<endl;
    cout << "==== WELCOME TO SCHOOL HELP ===="<<endl;
    cout << "================================"<<endl;
    cout <<endl;
    cout << "          Resource Type         " << endl;
    cout << "1. Sorted by Date\n";
    cout << "2. Sorted by Status\n";
}

class SchoolHelp {
public:
  bool login() {
    // Menyembunyikan input password dengan meminta user menekan tombol
    // setiap kali ingin memasukkan karakter
    string username;
    cout << "Masukan Username : ";cin >> username;
    string password = "";
    cin.ignore();
    cout << "Masukkan password : ";
    char ch;
    while ((ch = getch()) != '\n') { 
      password += ch;
      cout << "*";
    }
    if (username == "admin" && password == "root") {
      cout << "\nLogin success!" << endl;
      return true;
    } else {
      cout << "\nPeriksa username dan password" << endl;
      return false;
    }
  }
};

class School
{
private:
    int schoolID;
    string schoolName, address, city;
public:
    School(int sID, string sName, string alamat, string kota){
        this->schoolID = sID;
        this->schoolName = sName;
        this->address = alamat;
        this->city = kota;
    }

    int getschoolId(){
        return this->schoolID;
    }

    void setschoolId(int sId){
        this->schoolID = sId;
    }

    string getschoolName() const{
        return this->schoolName;
    }

    void setschoolName(string sName){
        this->schoolName = sName;
    }

    string getAddress(){
        return this->address;
    }

    void setAddress(string alamat){
        this->address = alamat;
    }

    string getCity() const{
        return this->city;
    }

    void setCity(string kota){
        this->city = kota;
    }

    void display(){
        cout << "School Id : " << this->schoolID << endl;
        cout << "Name Of School : " << this->schoolName << endl;
        cout << "Address of School : " << this->address << endl;
        cout << "City of School : " << this->city << endl;
    }

    // bool sortbyName(const School* a, const School* b){
    //     return a->schoolName < b->schoolName;
    // }
};

class User
{
private:
    string username, password, fullName, email, phone;
public:
    User(string Username, string Password, string FullName, string Email, string Phone){
        this->username = Username;
        this->password = Password;
        this->fullName = FullName;
        this->email = Email;
        this->phone = Phone;
    }

    string getUsername(){
        return username;
    }

    void setUsername(string Username){
        this->username = Username;
    }

    string getPassword(){
        return password;
    }

    void setPassword(string Password){
        this->password = Password;
    }

    string getFullname(){
        return fullName;
    }

    void setFullname(string FullName){
        this->fullName = FullName;
    }

    string getEmail(){
        return email;
    }

    void setEmail(string Email){
        this->email = Email;
    }

    string getPhone(){
        return phone;
    }

    void setPhone(string Phone){
        this->phone = Phone;
    }
    
};

class SchoolAdmin : public User
{
private:
    string staffID;
    string position;

public:
    SchoolAdmin(string username, string password, string fullName, string email, string phone, string staffID, string position) : User(username, password, fullName, email, phone)
    {
        this->staffID = staffID;
        this->position = position;
    }

    string getStaffID(){
        return staffID;
    }

    void setStaffID(string staffID){
        this->staffID = staffID;
    }

    string getPosition(){
        return position;
    }

    void setPosition(string position){
        this->position = position;
    }
    
    void regisSchoolAdmin(){
        
    }
    void display(){
        cout << "Username : " << this->getUsername() << endl;
        cout << "Password : " << this->getPassword() <<endl;
        cout << "FullName : " << this->getFullname() <<endl;
        cout << "Email : " << this->getEmail() <<endl;
        cout << "Phone : " << this->getPhone() << endl;
        cout << "Staff ID : " << this->staffID << endl;
        cout << "Position : " << this->position <<endl;
    }

    void showProfile(){
        cout << "Name : " << this->getFullname() <<endl;
        cout << "Position : " << this->getPosition() <<endl;
        
    }
    
};

class Volunteer : public User
{
private:
    string dateOfBirth, occupation;
public:
    Volunteer(string username, string password, string fullName, string email, string phone, string Date, string Occupation) : User(username, password, fullName, email, phone){
        this->dateOfBirth = Date;
        this->occupation = Occupation;
    }

    string getDateOfBirth(){
        return this->dateOfBirth;
    }

    void setDateOfBirth(string Date){
        this->dateOfBirth = Date;
    }

    string getOccupation(){
        return this->occupation;
    }

    void setOccupation(string Occupation){
        this->occupation = Occupation;
    }

    void display(){
        cout << "Username : " << this->getUsername() << endl;
        cout << "Password : " << this->getPassword() <<endl;
        cout << "FullName : " << this->getFullname() <<endl;
        cout << "Email : " << this->getEmail() <<endl;
        cout << "Phone : " << this->getPhone() << endl;
        cout << "Staff ID : " << this->dateOfBirth << endl;
        cout << "Position : " << this->occupation <<endl;
    }

    bool login(){
        string Username;
        cout << "Masukan Username : ";cin >> Username;
        string Password = "";
        cin.ignore();
        cout << "Masukkan password : ";
        char ch;
        while ((ch = getch()) != '\n') { 
        Password += ch;
        cout << "*";
        }
        if (Username == this->getUsername() && Password == this->getPassword()) {
        cout << "\nLogin success!" << endl;
        return true;
        } else {
        cout << "\nPeriksa username dan password" << endl;
        return false;
        }        
    }

};

class Request
{
private:
    int reqID, si;
    string reqDate, reqStatus, desc;
public:
    Request(int ID, int sid, string ReqDate, string ReqStatus, string Desc){
        this->reqID = ID;
        this->si = sid;
        this->reqDate = ReqDate;
        this->reqStatus = ReqStatus;
        this->desc = Desc;
    }

    int getReqID(){
        return this->reqID;
    }

    void setReqID(int ID){
        this->reqID = ID;
    }

    string getReqDate() const{
        return this->reqDate;
    }

    void setReqDate(string ReqDate){
        this->reqDate = ReqDate;
    }

    string getReqStatus() const{
        return this->reqStatus;
    }

    void setReqStatus(string ReqStatus){
        this->reqStatus = ReqStatus;
    }

    string getDesc(){
        return this->desc;
    }

    void setDesc(string Desc){
        this->desc = Desc;
    }

    int getSchoolID(){
        return this->si;
    }

    void setSchoolID(int NStudent){
        this->si = NStudent;
    }

};

class TutorialRequest: public Request
{
private:
    string propDate, propTime;
    int studentLevel, numStudent;
public:
    TutorialRequest(int ID, int sid, string ReqDate, string ReqStatus, string Desc, string PropDate, string PropTime, int StudentLevel, int NumStudent) : Request(ID, sid, ReqDate, ReqStatus, Desc){
        this->propDate = PropDate;
        this->propTime = PropTime;
        this->studentLevel = StudentLevel;
        this->numStudent = NumStudent;
    }

    string getPropDate(){
        return this->propDate;
    }
    void setPropDate(string PropDate){
        this->propDate = PropDate;
    }

    string getPropTime(){
        return this->propTime;
    }

    void setPropTime(string PropTime){
        this->propTime = PropTime;
    }

    int getStudentLevel(){
        return this->studentLevel;
    }

    void setStudentLevel(int SLevel){
        this->studentLevel = SLevel;
    }

    int getNumStudent(){
        return this->numStudent;
    }

    void setNumStudent(int NStudent){
        this->numStudent = NStudent;
    }

    void display(){
        cout << "Request Id : " << this->getReqID() <<endl;
        cout << "School ID : " << this->getSchoolID() <<endl;
        cout << "Request Status : " << this->getReqStatus() <<endl;
        cout << "Description : " << this->getDesc() <<endl;
        cout << "Proposed of Date : " << this->propDate <<endl;
        cout << "Proposed of Time : " << this->propTime <<endl;
        cout << "Level of Student : " << this->studentLevel <<endl;
        cout << "Sum of Student : " << this->numStudent <<endl;
    }

};

class ResourceRequest: public Request
{
private:
    string resourceType;
    int numRequired;
public:
    ResourceRequest(int ID, int sid, string ReqDate, string ReqStatus, string Desc, string RType, int NRequired): Request(ID, sid, ReqDate, ReqStatus, Desc){
        this->resourceType = RType;
        this->numRequired = NRequired;
    }

    string getResourceType(){
        return this->resourceType;
    }

    void setResourceType(string RType){
        this->resourceType = RType;
    }

    int getNumRequired(){
        return this->numRequired;
    }

    void setNumRequired(int NRequired){
        this->numRequired = NRequired;
    }

    void display(){
        cout << "Request Id : " << this->getReqID() <<endl;
        cout << "School ID : " << this->getSchoolID() <<endl;
        cout << "Request Status : " << this->getReqStatus() <<endl;
        cout << "Description : " << this->getDesc() <<endl;
        cout << "Proposed of Date : " << this->resourceType <<endl;
        cout << "Proposed of Time : " << this->numRequired <<endl;
    }
};

class Offers
{
private:
    string offersDate, remarks, offerStatus;
public:
    Offers(string OfferDate, string Remarks, string OfferStatus){
        offersDate = OfferDate;
        remarks = Remarks;
        offerStatus = OfferStatus;
    }

    string getOffersDate() const{
        return offersDate;
    }

    void setOffersDate(string OffersDate){
        offersDate = OffersDate;
    }

    string getRemarks(){
        return remarks;
    }

    void setRemarks(string Remarks){
        remarks = Remarks;
    }

    string getOfferStatus(){
        return offerStatus;
    }

    void setOfferStatus(string OfferStatus){
        offerStatus = OfferStatus;
    }
};

int main(){
    //variabel untuk menu dan sub menu
    int menuU, menuSH, menuV, menuV1, menuSA, menuSA1, menuSA2;
    char pilihU, pilihSH, pilihV, pilihV1, pilihSA, pilihSA1;

    //variable untuk akses konstruktor Admin School
    string date, job, User, Pass, Fullname, Email, Phone;

    //Variabel untuk akses kontruktor dari Volunteer
    string sID, Pos, user, pass, fullname, email, phone;

    //Variabel class School
    int ID;
    string NS, AS, C;

    //variabel untuk request Tutorial help
    string desc, pd, pt, reqStatus;
    int sl, ns, reqId, schoolID;

    //variable untuk REsource Help
    string rdate, rstatus, rdesc, rtype;
    int rid, rsid, rnum;

    //untuk login Volunteer
    bool loginV = false;
    string username, password = "";
    char ch;
    int k = 0;
    int view, view1, view2, view3;

    //untuk login School Admin
    bool loginSA= false;
    string usernameSA, passwordSA = "";
    bool loginSA1= false;
    string usernameSA1, passwordSA1 = "";
    int indexSA, indexSAr;
    char c, close, close1;
    int i = 1;

    //variabel untuk Offers Request
    int indexO;
    string OD, remark, OS;
    char submit, submit1, submit2;
    char submitO, submitO1;

    SchoolHelp* SH;
    SchoolAdmin* SA;
    School* S;
    Volunteer* V;
    TutorialRequest* TR;
    ResourceRequest* RR;
    Offers* O;

    vector<SchoolAdmin*> sa;
    vector<School*> s;
    vector<Volunteer*> v;
    vector<TutorialRequest*> tr;
    vector<ResourceRequest*> rr;
    vector<Offers*> o;

    //submit request
    vector<pair<School, TutorialRequest>> st;
    do
    {
        system("clear");
        menuUtama();
        cout << "Pilihan : "; cin >> menuU;

        switch (menuU)
        {
        case 1://DONE
            //Menu School Help
            if (SH->login()){
                do
                {
                    system("clear");
                    cout << "Login Succesfull!\n";
                    menuSchoolHelp();
                    cout << "Pilihan : "; cin >> menuSH;
                    
                    switch (menuSH)
                    {
                    case 1:
                        //School Register
                        cin.ignore();
                        cout << "Enter Name of School : "; getline(cin, NS);
                        cout << "Enter Address of School : "; getline(cin, AS);
                        cout << "Enter City of School : "; getline(cin, C);
                        
                        srand(time(NULL));
                        ID = 100000 + (rand() % 9000 + 1000);

                        S = new School(ID, NS, AS, C);
                        s.push_back(S);
                        cout << endl << "Successfully Register!" <<endl;
                        break;
                    case 2:
                        //Admin School Register
                        cin.ignore();
                        cout << "Enter Username: "; getline(cin, user);
                        cout << "Enter Password: "; getline(cin, pass);
                        cout << "Enter FullName: "; getline(cin, fullname);
                        cout << "Enter Email: "; getline(cin, email);
                        cout << "Enter Number Phone: "; getline(cin,phone);
                        cout << "Enter Staff ID: "; getline(cin, sID);
                        cout << "Enter Position: "; getline(cin, Pos);

                        SA = new SchoolAdmin(user, pass, fullname, email, phone, sID, Pos);
                        sa.push_back(SA);
                        cout << endl << "Successfully Register!" <<endl;
                        break;

                    default:
                        break;
                    }
                
                    cout << "Ulang Menjalankan Menu School Help ini? (y/n) : "; cin >> pilihSH;

                } while (pilihSH == 'y' || pilihSH == 'Y');
            }                       
            break;
        case 2://DONE
            //Menu Volunteer
            do
            {
                system("clear");
                menuVolunteer();
                cout << "Pilihan : "; cin >> menuV;
                switch (menuV)
                {
                case 1: //DONE
                    //Register
                    // Username, Password, fullname, email, phone, occupation, dateOfBirth
                    cin.ignore();
                    cout << "Enter Username: "; getline(cin, User);
                    cout << "Enter Password: "; getline(cin, Pass);
                    cout << "Enter FullName: "; getline(cin, Fullname);
                    cout << "Enter Email: "; getline(cin, Email);
                    cout << "Enter Number Phone: "; getline(cin,Phone);
                    cout << "Enter Date of Birth: "; getline(cin, date);
                    cout << "Enter Occupation: "; getline(cin, job);

                    V = new Volunteer(User, Pass, Fullname, Email, Phone, date, job);
                    v.push_back(V);

                    cout << endl << "Successfully Register!" <<endl;

                    break;
                case 2://DONE
                    //Login
                        //After Login, View Request
                            //sub menu View Request
                            //1.1 Sorted by School
                            //1.2 Sorted by City
                            //1.3 Sorted by Date
                        //2. Submit Request selected by RequestID -> Enter Remark -> Offer Status "PENDING"
                        cout << "Enter your Username : "; cin >> username;
                        cin.ignore();
                        cout << "Enter your Password : ";
                        while ((ch = getch()) != '\n') { 
                            password += ch;
                            cout << "*";
                        }
                        for (int i = 0; i < v.size(); i++){
                            if ( v[i]->getUsername() == username && v[i]->getPassword() == password){
                                loginV = true;
                                break;
                            }
                        }
                        if (loginV){
                            system("clear");
                            subMenuVolunteer();
                            cout << "Pilihan : "; cin >> menuV1;
                            cout <<endl;
                            switch (menuV1)
                            {
                            case 1:
                            
                                sort(s.begin(), s.end(), [](const School* a, const School* b){
                                    return a->getschoolName() < b->getschoolName();
                                });
                                
                                //show tutorial
                                for (int i = 0 ; i < tr.size(); i++){
                                    for (int j = 0; j < s.size(); j++){
                                        if (tr[i]->getSchoolID() == s[j]->getschoolId()){
                                            if (tr[i]->getReqStatus() == "NEW"){
                                                cout << ++k <<".  " << s[j]->getschoolName() <<endl;
                                                cout << "    Request ID : " << tr[i]->getReqID() <<endl;
                                                cout << "    City : " << s[j]->getCity() <<endl;
                                                cout << "    Description : " << tr[i]->getDesc() <<endl;
                                                cout << "    Status : " << tr[i]->getReqStatus() <<endl;
                                            }
                                        }
                                    }                                    
                                }

                                //show Resource Request
                                for (int i = 0 ; i < rr.size() ; i++){
                                    for (int j = 0; j < s.size(); j++){
                                        if (rr[i]->getSchoolID() == s[j]->getschoolId()){
                                            if (rr[i]->getReqStatus() == "NEW"){
                                                cout << ++k <<".  " << s[j]->getschoolName() <<endl;
                                                cout << "    Request ID : " << rr[i]->getReqID() <<endl;
                                                cout << "    City : " << s[j]->getCity() <<endl;
                                                cout << "    Description : " << rr[i]->getDesc() <<endl;
                                                cout << "    Status : " << rr[i]->getReqStatus() <<endl;
                                            }
                                        }
                                    }                                    
                                }

                                //view Tutorial
                                cout <<"\nPilih Request dengan input Request ID : "; cin >> view;
                                system("clear");
                                cout <<endl;
                                for (int i = 0; i < tr.size(); i++){
                                    if (view == tr[i]->getReqID()){
                                        cout << "\tRequest ID : " << tr[i]->getReqID() <<endl;
                                        cout << "\tDate and Time : " << tr[i]->getPropDate() << " " << tr[i]->getPropTime() <<endl;
                                        cout << "\tLevel of Student : " << tr[i]->getStudentLevel() <<endl;
                                        cout << "\tNumber of Student : " << tr[i]->getNumStudent() <<endl;
                                        indexO = i;
                                        break;
                                    }
                                }

                                for (int i = 0; i < rr.size(); i++){
                                    if (view == rr[i]->getReqID()){
                                        cout << "\tRequest ID : " << rr[i]->getReqID() <<endl;
                                        cout << "\tResource Type : " << rr[i]->getResourceType() <<endl;
                                        cout << "\tSum of Required : " << rr[i]->getNumRequired() <<endl;
                                        indexO = i;
                                        break;
                                    }
                                }
                                cout << "\nApakah Anda ingin Submit Request? (y/n) "; cin >> submit;
                                if (submit == 'y' || submit == 'Y'){
                                    OD = tr[indexO]->getReqDate();
                                    cout << "Offers Date : " << OD <<endl;
                                    cin.ignore();
                                    cout << "Remarks : "; getline(cin, remark);
                                    OS = "PENDING";
                                    cout << "Offers Status : " << OS <<endl;

                                    O = new Offers(OD, remark, OS);
                                    o.push_back(O);                                          
                                }
                                k = 0;
                                break;
                            case 2:
                                sort(s.begin(), s.end(), [](const School* a, const School* b){
                                    return a->getCity() < b->getCity();
                                });

                                //Show tutorial Request
                                for (int i = 0 ; i < tr.size(); i++){
                                    for (int j = 0; j < s.size(); j++){
                                        if (tr[i]->getSchoolID() == s[j]->getschoolId()){
                                            if (tr[i]->getReqStatus() == "NEW"){
                                                cout << ++k <<".  " << s[j]->getschoolName() <<endl;
                                                cout << "    Request ID : " << tr[i]->getReqID() <<endl;
                                                cout << "    City : " << s[j]->getCity() <<endl;
                                                cout << "    Description : " << tr[i]->getDesc() <<endl;
                                                cout << "    Status : " << tr[i]->getReqStatus() <<endl;

                                            }
                                        }
                                    }
                                }

                                //show Resource Request
                                for (int i = 0 ; i < rr.size() ; i++){
                                    for (int j = 0; j < s.size(); j++){
                                        if (rr[i]->getSchoolID() == s[j]->getschoolId()){
                                            if (rr[i]->getReqStatus() == "NEW"){
                                                cout << ++k <<".  " << s[j]->getschoolName() <<endl;
                                                cout << "    Request ID : " << rr[i]->getReqID() <<endl;
                                                cout << "    City : " << s[j]->getCity() <<endl;
                                                cout << "    Description : " << rr[i]->getDesc() <<endl;
                                                cout << "    Status : " << rr[i]->getReqStatus() <<endl;
                                            }
                                        }
                                    }                                    
                                }

                                //view Tutorial
                                cout <<"\nPilih Request dengan input Request ID : "; cin >> view2;
                                system("clear");
                                cout <<endl;
                                for (int i = 0; i < tr.size(); i++){
                                    if (view2 == tr[i]->getReqID()){
                                        cout << "\tRequest ID : " << tr[i]->getReqID() <<endl;
                                        cout << "\tDate and Time : " << tr[i]->getPropDate() << " " << tr[i]->getPropTime() <<endl;
                                        cout << "\tLevel of Student : " << tr[i]->getStudentLevel() <<endl;
                                        cout << "\tNumber of Student : " << tr[i]->getNumStudent() <<endl;
                                        indexO = i;
                                        break;
                                    }
                                }

                                for (int i = 0; i < rr.size(); i++){
                                    if (view2 == rr[i]->getReqID()){
                                        cout << "\tRequest ID : " << rr[i]->getReqID() <<endl;
                                        cout << "\tResource Type : " << rr[i]->getResourceType() <<endl;
                                        cout << "\tSum of Required : " << rr[i]->getNumRequired() <<endl;
                                        indexO = i;
                                        break;
                                    }
                                }

                                cout << "\nApakah Anda ingin Submit Request? (y/n) "; cin >> submit1;
                                if (submit1 == 'y' || submit1 == 'Y'){
                                    OD = tr[indexO]->getReqDate();
                                    cout << "Offers Date : " << OD <<endl;
                                    cin.ignore();
                                    cout << "Remarks : "; getline(cin, remark);
                                    OS = "PENDING";
                                    cout << "Offers Status : " << OS <<endl;

                                    O = new Offers(OD, remark, OS);
                                    o.push_back(O);                                          
                                }
                                k = 0;                  
                                break;
                            case 3:
                                sort(tr.begin(), tr.end(), [](const TutorialRequest* a, const TutorialRequest* b){
                                    return a->getReqDate() < b->getReqDate();           
                                });

                                //show Tutorial Request
                                for (int i = 0 ; i < tr.size(); i++){
                                    for (int j = 0; j < s.size(); j++){
                                        if (tr[i]->getSchoolID() == s[j]->getschoolId()){
                                            if (tr[i]->getReqStatus() == "NEW"){
                                                cout << ++k <<".  " << s[j]->getschoolName() <<endl;
                                                cout << "    Request ID : " << tr[i]->getReqID() <<endl;
                                                cout << "    City : " << s[j]->getCity() <<endl;
                                                cout << "    Description : " << tr[i]->getDesc() <<endl;
                                                cout << "    Status : " << tr[i]->getReqStatus() <<endl;
                                                
                                            }
                                        }
                                    }
                                }

                                //show Resource Request
                                for (int i = 0 ; i < rr.size() ; i++){
                                    for (int j = 0; j < s.size(); j++){
                                        if (rr[i]->getSchoolID() == s[j]->getschoolId()){
                                            if (rr[i]->getReqStatus() == "NEW"){
                                                cout << ++k <<".  " << s[j]->getschoolName() <<endl;
                                                cout << "    Request ID : " << rr[i]->getReqID() <<endl;
                                                cout << "    City : " << s[j]->getCity() <<endl;
                                                cout << "    Description : " << rr[i]->getDesc() <<endl;
                                                cout << "    Status : " << rr[i]->getReqStatus() <<endl;
                                            }
                                        }
                                    }                                    
                                }

                                cout <<"\nPilih Request dengan input Request ID : "; cin >> view3;
                                //view Tutorial
                                system("clear");
                                cout <<endl;
                                for (int i = 0; i < tr.size(); i++){
                                    if (view3 == tr[i]->getReqID()){
                                        cout << "\tRequest ID : " << tr[i]->getReqID() <<endl;
                                        cout << "\tDate and Time : " << tr[i]->getPropDate() << " " << tr[i]->getPropTime() <<endl;
                                        cout << "\tLevel of Student : " << tr[i]->getStudentLevel() <<endl;
                                        cout << "\tNumber of Student : " << tr[i]->getNumStudent() <<endl;
                                        indexO = i;
                                        break;
                                    }
                                }

                                for (int i = 0; i < rr.size(); i++){
                                    if (view3 == rr[i]->getReqID()){
                                        cout << "\tRequest ID : " << rr[i]->getReqID() <<endl;
                                        cout << "\tResource Type : " << rr[i]->getResourceType() <<endl;
                                        cout << "\tSum of Required : " << rr[i]->getNumRequired() <<endl;
                                        indexO = i;
                                        break;
                                    }
                                }

                                cout << "\nApakah Anda ingin Submit Request? (y/n) "; cin >> submit2;
                                if (submit2 == 'y' || submit2 == 'Y'){
                                    OD = tr[indexO]->getReqDate();
                                    cout << "Offers Date : " << OD <<endl;
                                    cin.ignore();
                                    cout << "Remarks : "; getline(cin, remark);
                                    OS = "PENDING";
                                    cout << "Offers Status : " << OS <<endl;

                                    O = new Offers(OD, remark, OS);
                                    o.push_back(O);                                       
                                }
                                k = 0;
                                break;
                            
                            default:
                                break;
                            }
                        }
                    break;
                
                default:
                    break;
                }

                cout << "Ulang Menjalankan Menu Volunteer ini? (y/n) : "; cin >> pilihV;

            } while (pilihV == 'y' || pilihV == 'Y');
                 
            break;
        case 3:
            //Menu School Admin
            //After Login Show Admin's Name & Position, schoolID & schoolName too
            cout << "Enter your Username : "; cin >> usernameSA;
            cin.ignore();
            cout << "Enter your Password : ";
            while ((ch = getch()) != '\n') { 
                passwordSA += ch;
                cout << "*";
            }
            for (int i = 0; i < sa.size(); i++){
                if (sa[i]->getUsername() == usernameSA && sa[i]->getPassword() == passwordSA){
                    indexSA = i;
                    loginSA = true;
                    break;
                }
            }
            if (loginSA){

                do
                {
                    system("clear");
                    menuSchoolAdmin();
                    cout <<endl;
                    cout << "Pilihan : "; cin >> menuSA;
                    switch (menuSA)
                    {
                    case 1: //DONE
                        //Request Help
                        // enter description of tutorial request
                        //enter proposed date and time of the tutorial -> status "NEW"
                        
                    
                            system("clear");
                            cout << "Name : " << sa[indexSA]->getFullname() <<endl;
                            cout << "Posistion : " << sa[indexSA]->getPosition() <<endl;
                            cout << "School ID : " << s[indexSA]->getschoolId() << endl;
                            cout << "Name of School : " << s[indexSA]->getschoolName() <<endl;
                            cout <<endl;
                            subMenuSchoolAdmin();
                            cout << "Pilihan : "; cin >> menuSA1;
                            switch (menuSA1)
                            {
                            case 1:
                                
                                cin.ignore(1);
                                cout << "Description of Tutorial Request : "; getline(cin, desc);
                                cout << "Proposed of Date : "; getline(cin, pd);
                                cout << "Proposed of Time : "; cin >> pt;
                                cout << "Level of Student : "; cin >> sl;
                                cout << "Sum of Student : "; cin >> ns;
                                
                                reqId = s[indexSA]->getschoolId() + i++;
                                cout << "ReqId : " << reqId <<endl;
                                reqStatus = "NEW";
                                schoolID = s[indexSA]->getschoolId();

                                TR = new TutorialRequest(reqId, schoolID, pd, reqStatus, desc, pd, pt, sl, ns);
                                tr.push_back(TR);                        
                                cout << endl;
                                break;
                            case 2:

                                cin.ignore();
                                cout << "Enter Request Date : "; getline(cin, rdate);
                                cout << "Enter Request Description : "; getline(cin, rdesc);
                                cout << "Enter Resource Type : "; getline(cin, rtype);
                                cout << "Enter Num of Resource Required : "; cin >> rnum;
                                rid = s[indexSA]->getschoolId() + i++;
                                rsid = s[indexSA]->getschoolId();
                                rstatus = "NEW";

                                RR = new ResourceRequest(rid, rsid, rdate, rstatus, rdesc, rtype, rnum);

                                rr.push_back(RR);

                                cout << endl;
                                break;
                            
                            default:
                                break;
                            }                        
                        break;
                    case 2:
                        //Review Offers
                        // Sorted by Status and Date -> select by RequestID -> offerDate, Remarks, Name, Age, Occupation of Volunteer is Shown
                        // if "Accept" -> status "ACCEPTED"
                        //if "Close" -> status "CLOSED"
                        //log out
                        system("clear");
                        cout << "Name : " << sa[indexSA]->getFullname() <<endl;
                        cout << "Posistion : " << sa[indexSA]->getPosition() <<endl;
                        cout << "School ID : " << s[indexSA]->getschoolId() << endl;
                        cout << "Name of School : " << s[indexSA]->getschoolName() <<endl;
                        cout <<endl;
                        subMenuSchoolAdmin2();
                        cout << "Pilihan : "; cin >> menuSA2;
                        switch (menuSA2)
                        {
                        case 1:
                            //Sorted by Date
                            sort(tr.begin(), tr.end(), [](const Request* a, const Request* b){
                                return a->getReqDate() < b->getReqDate();           
                            });

                            //show Tutorial Request
                            for (int i = 0 ; i < tr.size(); i++){
                                if (tr[i]->getSchoolID() == s[indexSA]->getschoolId()){
                                    if (tr[i]->getReqStatus() == "NEW"){
                                        cout << ++k <<".  " << s[indexSA]->getschoolName() <<endl;
                                        cout << "  Request ID : " << tr[i]->getReqID() <<endl;
                                        cout << "   City : " << s[indexSA]->getCity() <<endl;
                                        cout << "   Description : " << tr[i]->getDesc() <<endl;
                                        cout << "   Status : " << tr[i]->getReqStatus() <<endl;                                                
                                    }
                                }
                            }

                            //show Resource Request
                            for (int i = 0 ; i < rr.size() ; i++){
                                if (rr[i]->getSchoolID() == s[indexSA]->getschoolId()){
                                    if (rr[i]->getReqStatus() == "NEW"){
                                        cout << ++k <<".  " << s[indexSA]->getschoolName() <<endl;
                                        cout << "    Request ID : " << rr[i]->getReqID() <<endl;
                                        cout << "    City : " << s[indexSA]->getCity() <<endl;
                                        cout << "    Description : " << rr[i]->getDesc() <<endl;
                                        cout << "    Status : " << rr[i]->getReqStatus() <<endl;
                                    }
                                }                               
                            }
                                
                            //show Request yang dipilih
                            cout << "\nPilih berdasarkan Request ID : "; cin >> view1;
                            for (int i = 0; i < tr.size(); i++){
                                if (tr[i]->getReqID() == view1){
                                    for (int j = 0; j < o.size(); j++){
                                        cout << "Description : " << tr[i]->getDesc() <<endl;
                                        cout << "Date of Offers : " << o[j]->getOffersDate() <<endl;
                                        cout << "Remarks : " << o[j]->getRemarks() <<endl;
                                        cout << "Status of Offers : " << o[j]->getOfferStatus() <<endl;
                                    }
                                    cout << "Apakah anda akan menerima bantuan ini? y/n : "; cin >> submitO;
                                    if (submitO == 'y' || submitO == 'Y'){
                                        for (int j = 0; j < o.size(); j++){
                                            o[j]->setOfferStatus("ACCEPTED");
                                        }
                                    }
                                    break;
                                }
                            }

                            for (int i = 0; i < rr.size(); i++){
                                if (rr[i]->getReqID() == view1){
                                    for (int j = 0; j < o.size(); j++){
                                        cout << "Description : " << tr[i]->getDesc() <<endl;
                                        cout << "Date of Offers : " << o[j]->getOffersDate() <<endl;
                                        cout << "Remarks : " << o[j]->getRemarks() <<endl;
                                        cout << "Status of Offers : " << o[j]->getOfferStatus() <<endl;
                                    }
                                    cout << "Apakah anda akan menerima bantuan ini? y/n : "; cin >> submitO;
                                    if (submitO == 'y' || submitO == 'Y'){
                                        for (int j = 0; j < o.size(); j++){
                                            o[j]->setOfferStatus("ACCEPTED");
                                        }
                                    }
                                    break;
                                }
                            }

                            cout << "Apakah Anda Akan Menutup Request Ini? y/n : "; cin >> close;
                            if (close == 'y' || close == 'Y'){
                                for (int i = 0; i < tr.size(); i++){
                                    tr[i]->setReqStatus("CLOSED");
                                }

                                for (int i = 0; i < rr.size(); i++){
                                    rr[i]->setReqStatus("CLOSED");
                                }
                            }
                            k = 0;
                            break;
                        case 2:
                            // sorted by status
                            sort(tr.begin(), tr.end(), [](const Request* a, const Request* b){
                                return a->getReqStatus() < b->getReqStatus();           
                            });

                            //show Tutorial Request
                            for (int i = 0 ; i < tr.size(); i++){
                                if (tr[i]->getSchoolID() == s[indexSA]->getschoolId()){
                                    if (tr[i]->getReqStatus() == "NEW"){
                                        cout << ++k <<".  " << s[indexSA]->getschoolName() <<endl;
                                        cout << "   Request ID : " << tr[i]->getReqID() <<endl;
                                        cout << "   City : " << s[indexSA]->getCity() <<endl;
                                        cout << "   Description : " << tr[i]->getDesc() <<endl;
                                        cout << "   Status : " << tr[i]->getReqStatus() <<endl;                                                
                                    }
                                }
                            }

                            //show Resource Request
                            for (int i = 0 ; i < rr.size() ; i++){
                                if (rr[i]->getSchoolID() == s[indexSA]->getschoolId()){
                                    if (rr[i]->getReqStatus() == "NEW"){
                                        cout << ++k <<".  " << s[indexSA]->getschoolName() <<endl;
                                        cout << "    Request ID : " << rr[i]->getReqID() <<endl;
                                        cout << "    City : " << s[indexSA]->getCity() <<endl;
                                        cout << "    Description : " << rr[i]->getDesc() <<endl;
                                        cout << "    Status : " << rr[i]->getReqStatus() <<endl;
                                    }
                                }                               
                            }

                            //show Request yang dipilih
                            cout << "\nPilih berdasarkan Request ID : "; cin >> view1;
                            for (int i = 0; i < tr.size(); i++){
                                if (tr[i]->getReqID() == view1){
                                    for (int j = 0; j < o.size(); j++){
                                        cout << "Description : " << tr[i]->getDesc() <<endl;
                                        cout << "Date of Offers : " << o[i]->getOffersDate() <<endl;
                                        cout << "Remarks : " << o[i]->getRemarks() <<endl;
                                        cout << "Status of Offers : " << o[i]->getOfferStatus() <<endl;
                                    }
                                    cout << "Apakah anda akan menerima bantuan ini? y/n : "; cin >> submitO1;
                                    if (submitO1 == 'y' || submitO == 'Y'){
                                        for (int j = 0; j < o.size(); j++){
                                            o[j]->setOfferStatus("ACCEPTED");
                                        }
                                    }
                                    break;
                                }
                            }

                            for (int i = 0; i < rr.size(); i++){
                                if (rr[i]->getReqID() == view1){
                                    for (int j = 0; j < o.size(); j++){
                                        cout << "Description : " << tr[i]->getDesc() <<endl;
                                        cout << "Date of Offers : " << o[i]->getOffersDate() <<endl;
                                        cout << "Remarks : " << o[i]->getRemarks() <<endl;
                                        cout << "Status of Offers : " << o[i]->getOfferStatus() <<endl;
                                    }

                                    cout << "Apakah anda akan menerima bantuan ini? y/n : "; cin >> submitO1;
                                    if (submitO1 == 'y' || submitO1 == 'Y'){
                                        for (int j = 0; j < o.size(); j++){
                                            o[j]->setOfferStatus("ACCEPTED");
                                        }
                                    }

                                    break;
                                }
                            }

                            cout << "Apakah Anda Akan Menutup Request Ini? y/n : "; cin >> close1;
                            if (close1 == 'y' || close1 == 'Y'){
                                for (int i = 0; i < tr.size(); i++){
                                    tr[i]->setReqStatus("CLOSED");
                                }

                                for (int i = 0; i < rr.size(); i++){
                                    rr[i]->setReqStatus("CLOSED");
                                }
                            }

                            break;
                            
                        default:
                            break;
                        }
                        k=0;
                        break;
                    
                    default:
                        break;
                    }
                    
                    cout << "Ulangi Menu School Admin? (y/n) : "; cin >> pilihSA;

                } while (pilihSA == 'y' || pilihSA == 'Y');
            }                      
            break;
        
        default:
            break;
        }

        cout << "Apakah Anda Ingin Menjalankan Program ini lagi? (y/n) : "; cin >> pilihU;

    } while (pilihU == 'y' || pilihU == 'Y');
    
}