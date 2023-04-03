
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
    bool operator< (const contact &person) const;
};

bool contact::operator<(const contact &person) const{
    if (this->age > person.age){
        return 0;
    }
    else return 1;
}

ostream& operator << (ostream &myout, const contact &person){
    myout << "name is " << person.name << "\t"
    << "age is " << person.age << "\t"
    << "phone num is " << person.num << endl
    << "address is " << person.address << "\t"
    << "sex is " << person.sex << "\t";

    return myout;
}

contact createContact(string &name, string &address, string &sex, int age, int num);

void Add(set<contact> &list, const contact &person);

void Show(const set<contact> &list);

void Delete(set<contact> &list, const string &name);

void Clear(set<contact> &list);

void Change(set<contact> &list);

void Find(set<contact> &list, const string &name);

int main(){
    set<contact> list;
    string name0 = "Yao";
    string address0 = "korean";
    string sex0 = "M";
    int age0 = 25;
    int num0 = 4888;
    string name1 = "Guo";
    string address1 = "China";
    string sex1 = "F";
    int age1 = 53;
    int num1 = 4889;
    string name2 = "Yan";
    string address2 = "China";
    string sex2 = "F";
    int age2 = 25;
    int num2 = 4890;
    string name3 = "Liu";
    string address3 = "China";
    string sex3 = "M";
    int age3 = 28;
    int num3 = 4891;
    contact person0 = createContact(name0, address0, sex0, age0, num0);
    contact person1 = createContact(name1, address1, sex1, age1, num1);
    contact person2 = createContact(name2, address2, sex2, age2, num2);
    contact person3 = createContact(name3, address3, sex3, age3, num3);
    Add(list, person0);

    Add(list, person1);
    Show(list);
    Add(list, person2);
    Add(list, person3);
    Show(list);
    Delete(list, "Yao");
    Show(list);
    Find(list, "Guo");
    Change(list);
    Show(list);
    Clear(list);
    Show(list);

    return 0;
}

contact createContact(string &name, string &address, string &sex, int age, int num){
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
    for(itr = list.begin(); itr != list.end(); itr++){
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

void Change(set<contact> &list){
    string name, address, sex;
    int age, num;
    cout << "please enter the name, address, sex, age and num respectively!: " << endl;
    cin >> name >> address >> sex >> age >> num;
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
