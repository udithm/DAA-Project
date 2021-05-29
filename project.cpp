#include <bits/stdc++.h>
using namespace std;

struct id
{
    int num;
    vector<int> seq;
};

int Intersection(vector<int> vec1, vector<int> vec2, int m, int n) 
{ 
  int i = 0, j = 0;
  int count=0;
  while (i < m && j < n) 
  { 
    if (vec1[i] < vec2[j]) 
       i++; 
    else if (vec2[j] < vec1[i]) 
       j++; 
    else 
    { 
       //cout<<vec1[i]<<endl;
       count++;
       i++; 
       j++; 
    } 
  }
  //cout<<"count="<<count<<endl;
  return count;
}

void flag_filler(vector<int> matrix[], bool* flag_arr)
{
    queue<int> que;
    que.push(0);
    
    while(que.size()!=0)
    {
        int index = que.front();
        que.pop();
        //cout<<"IN"<<endl;
        for(auto it:matrix[index])
        {
            //cout<<"IN2"<<endl;
            if(flag_arr[it]==0){
                flag_arr[it]=1;
                que.push(it);
            }
        }
    }
}


int main(void) {
	
    ifstream fin;
    fin.open("input.txt");
    int n,k;
    fin>>n;
    fin>>k;
    //cout<<n<<" "<<k<<endl;
    
    id ids[n];
    for(int i=0;i<n;i++)
    {
        //int number;
        fin>>ids[i].num;
        //cout<<number<<endl;
        //ids[n].num=number;
        for(int j=0;j<ids[i].num;j++){
            int x;
            fin>>x;
            ids[i].seq.push_back(x);
        }
        sort(ids[i].seq.begin(),ids[i].seq.end());
       //cout<<ids[i].num<<"xx"<<ids[i].seq[0]<<endl;
    }
    
    fin.close();

	vector<int> matrix[n];
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        int c = Intersection(ids[i].seq,ids[j].seq,ids[i].num,ids[j].num);
	        //cout<<c<<endl;
            if(c>=k)
	        {
	            matrix[i].push_back(j);
	            matrix[j].push_back(i);
                //cout<<i<<j<<endl;
	        }
	    }
	}
	
	bool flag_arr[n]={0};
	flag_arr[0]=1;

	flag_filler(matrix,flag_arr);
 
	int val=0;
	for(int i=0;i<n;i++){
	    if(flag_arr[i])
	    {
	        val++; 
            //cout<<val<<endl;   
	    }
	}
	cout<<val<<endl;
	return 0;
}