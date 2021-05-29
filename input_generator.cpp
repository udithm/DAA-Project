#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream fout;

    
    int n = rand()%300;
    int k = rand()%10;//k is constrained to 1 to 300 but for best test cases i kept till 10

    fout.open("input.txt");
    
    fout<<n<<" "<<k<<endl;

    for(int i=0;i<n;i++){
        int x = rand()%300;
        fout<<x<<" ";
        for(int j=0;j<x;j++){
            int e = rand()%10;//for best results constrained to 10
            fout<<e<<" ";
        }
        fout<<endl;
    }

    fout.close();

    return 0;
}

