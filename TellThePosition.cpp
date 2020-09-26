#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    int rollno;
    string name;
    int totalMarks;
    
    student(int rollno, string name, int totalMarks){
        this -> rollno = rollno;
        this -> name = name;
        this -> totalMarks = totalMarks;
    }
};
bool compare(student a, student b){
	if(a.totalMarks == b.totalMarks){
        return a.rollno < b.rollno;
    }else{
        return a.totalMarks > b.totalMarks ;
    }
}
int main()
{
    vector<student> class1;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        string name;
        cin >> name;
        int m1 , m2 , m3;
        cin >> m1 >> m2 >> m3;
        int total = m1 + m2 + m3;
        student s(i+1,name,total);
        class1.push_back(s);
    }
    sort(class1.begin(),class1.end(), compare);
    vector<student>:: iterator it;
    int i = 1;
    for(it = class1.begin(); it != class1.end(); it++){
        cout << i <<" " << it -> name << endl;
        i++;
    }
	return 0;
}
