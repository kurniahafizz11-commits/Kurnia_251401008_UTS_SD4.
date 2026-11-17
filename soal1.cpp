#include <iostream>
using namespace std;

int main(){
    int nilai[5][4],rata;

    for (int i = 0; i <5; i++){
        for(int j = 0; j < 4; j++){
            cout<<"Nilai Mahasiswa: "<<i + 1<<": ";
            cin>>nilai[i][j];
        }
    }
    for (int i = 0; i <5; i++){
        for(int j = 0; j < 4; j++){
            cout<<nilai[i][j]<<" ";
        }
        cout<<endl;
    }            
    return 0;            
} 