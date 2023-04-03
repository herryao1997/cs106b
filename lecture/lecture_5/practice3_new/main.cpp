#include<iostream>
#include<string>
#include<set>

using namespace std;

struct contact{
    string name;
    mutable string address;
    mutable string sex;
    mutable int age;
    mutable int num;
    friend ostream& operator<< (ostream &myout, const contact &person);
    bool operator <(const contact& person) const;
};

ostream& operator << (ostream &myout, const contact &person){
    myout << "name is " << person.name << "\t"
    << "age is " << person.age << "\t"
    << "phone num is " << person.num << endl
    << "address is " << person.address << "\t"
    << "sex is " << person.sex << "\t";

    return myout;
}

bool contact::operator < (const contact& person) const{
    if(person.age > this->age)
        return true;
    else
        return false;
}

contact createContact(const string &name, const string &address, const string &sex, const int &age, const int &num);

void Add(set<contact> &list, const contact &person);

void Show(const set<contact> &list);

void Delete(set<contact> &list, const string &name);

void Clear(set<contact> &list);

void Change(set<contact> &list, const string &name, const string &sex, const string &address, const int &age, const int &num);

void Find(set<contact> &list, const string &name);


int main(){
    set<contact> list;
    contact person0 = createContact("Yao", "korean", "M", 25, 4888);
    contact person1 = createContact("Guo", "China", "F", 53, 4889);
    contact person2 = createContact("Yan", "China", "F", 25, 4890);
    contact person3 = createContact("Liu", "China", "M", 28, 4891);
    Add(list, person0);

    Add(list, person1);
    Show(list);
    cout << "============================================" << endl;
    Add(list, person2);
    Add(list, person3);
    Show(list);
    cout << "============================================" << endl;
    Delete(list, "Yao");
    Show(list);
    cout << "============================================" << endl;
    Find(list, "Guo");
    Change(list, "Liu", "F", "Jiantaizi", 60, 8888);
    Show(list);
    cout << "============================================" << endl;
    Clear(list);
    Show(list);
    cout << "============================================" << endl;
    return 0;
}

contact createContact(const string &name, const string &address, const string &sex, const int &age, const int &num){
    contact person = {name, address, sex, age, num};
    return person;
}

void Add(set<contact> &list, const contact &person){
    list.insert(person);
}

void Show(const set<contact> &list){
    for (auto itr = list.begin(); itr != list.end(); itr++){
        cout << *itr << endl;
    }
}

void Delete(set<contact> &list, const string &name){
    bool flag = false;
    auto itr = list.begin();
    for(auto itr = list.begin(); itr != list.end(); itr++){
        if(itr->name == name){
            flag = true;
            break;
        }
    }
    if(flag){
        list.erase(itr);
    }
}

void Clear(set<contact> &list){
    list.clear();
}

void Change(set<contact> &list, const string &name, const string &sex, const string &address, const int &age, const int &num){

    for (auto itr = list.begin(); itr != list.end(); itr++){
        if (itr->name == name){
            itr->sex = sex;
            itr->address = address;
            itr->age = age;


            itr->num = num;
            break;
        }
    }
}

void Find(set<contact> &list, const string &name){
    bool found = false;
    for(auto itr = list.begin(); itr != list.end(); itr++){
        if(itr->name == name){
            found = true;
            cout << *itr << endl;
            break;
        }
    }
    if (!found){
        cout << "no result!" << endl;
    }
}
