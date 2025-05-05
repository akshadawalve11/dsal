#include<iostream>
#include<stdio.h>
using namespace std;

class flight{
    int m[10][10],n,i,j;
    char choice;
    string v[20];
    public:
    void get(){
        cout<<"Enter number of cities:";
        cin>>n;
        cout<<"Enter name of cities:"<<endl;
        for(i=0;i<n;i++){
            cin>>v[i];
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<"If there is route between cities "<<v[i]<<" and "<<v[j]<<" then enter y "<<endl;
                cin>>choice;
                if(choice=='y'){
                    cout<<"Enter time required to reach "<<v[j]<<" from "<<v[i]<<endl;
                    cin>>m[i][j];
                }
                else if(choice=='n'){
                    m[i][j]=0;
                }
                else{
                    cout<<"Invalid choice!";
                }
            }
        }
    }
    void display(){
        cout<<"\n";
        for(j=0;j<n;j++){
            cout<<"\t"<<v[j];
        }
        for(i=0;i<n;i++){
            cout<<"\n"<<v[i];
            for(j=0;j<n;j++){
                cout<<"\t"<<m[i][j];
            }
            cout<<"\n";
        }
    }
};
int main(){
    int m;
    char ans;
    flight f;
    do{
        cout<<"\n 1.Insert graph \n 2.display \n 3.Exit \n enter your choice:";
        cin>>m;
        switch(m){
            case 1:
            f.get();
            break;

            case 2:
            f.display();
            break;

            case 3:
            break;

            default:
            cout<<"Invalid choice!";
        }
        cout<<"Do you want to continue(y/n):";
        cin>>ans;
    }while(ans=='y');
    return 0;
}