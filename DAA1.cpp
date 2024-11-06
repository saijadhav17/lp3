#include <bits/stdc++.h>
using namespace std;

class Fibonacci{
    public:
        int n;
        
        Fibonacci(int n){
            this->n=n;
        }
        
        int recursive(int i){
            if(i<=1){
                return i;
            }
            return recursive(i-1) + recursive(i-2);
        }
        
        void iterative(){
            int n1=0;
            int n2=1;
            int num;
            cout<<n1<<" "<<n2<<" ";
            for(int i=2;i<n;i++){
                num=n1+n2;
                n1=n2;
                n2=num;
                cout<<num<<" ";
            }
        }
};
        
        int main(){
            int n;
            cout<<"Enter N:";
            cin>>n;
            Fibonacci fb(n); // initialized
            cout<<"Iterative: ";
            fb.iterative();
            cout<<endl;
            cout<<"Recursive: ";
	    for (int i = 0; i < n; i++)
            {
            	cout << fb.recursive(i) << " ";
            }
            return 0;
        }
