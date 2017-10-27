#include<iostream>

using namespace std;

class Student
{
private:
    int id ,score;
public:
    Student()
    {
        id=0;
        score=0;
    }
    Student(int id, int mark){
        this->id = id;
        score = mark;
    }
    int getId(int id)
    {
        return id;
    }
    int getScore()
    {
        return score;
    }
    void set(int a,int b)
    {
        id=a;
        score=b;
    }
    void print()
    {
        cout<<id<<" "<<score<<endl;
    }
};

int main()
{
    int i=0;
    int id,score;
    Student* stu=new Student[5];
    //Student stu[5];
    while(i<5)
    {
        cin>>id>>score;
        stu[i]=Student(id, score);
        i++;
    	
    }
    stu[0].print();
    stu[2].print();
    stu[4].print();
}
