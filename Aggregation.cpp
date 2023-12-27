#include<bits/stdc++.h>
using namespace std;

class a
{
    public:
    string street;
    string city;
    string state;
    a(string street,string city,string state)
    {
        this->street=street;
        this->city=city;
        this->state=state;
    }
};

class b
{
    private:
    a*ad;
    public:
    string name;
    int id;
    b(string name,int id,a*ad)
    {
        this->name=name;
        this->id=id;
        this->ad=ad;
    }

    void dispaly()
    {
        cout<<id<<endl<<name<<endl<<ad->street<<endl<<ad->city<<endl<<ad->state<<endl;
    }
};

int main()
{
    a base("Kanuru","Vijayawada","Andhra Pradesh");
    b der("Hemanth",354,&base);
    der.dispaly();
}