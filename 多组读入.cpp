		#include <iostream>
		#include<vector>
		using namespace std;
		int main(){
			int i,x,sum=0,count;
			float result=0;
			int max=0;
		    int min=9999999;
			vector<int> arr;
		    cin>>count;
			for(i=1;i<=count;i++){
				cin>>x;
				if(x>max)
					max=x;
				if(x<min)
					min =x;
				arr.push_back(x);
	    	}
		
	    for(i=0;i<=count-1;i++)
	    {
		    sum=arr[i]+sum;
		}
	       result=((float)sum-max-min)/(count-2);
	       printf("%.2f",result);
		return 0;
		}

