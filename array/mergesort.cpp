#include<iostream>
using namespace std;
int main()
{
    int arr1[4]={1,2,3,4};
    int arr2[4]={7,8,5,9};
    int arr3[8];
    for(int i=0;i<4;i++)
    {
        arr3[i]=arr1[i];
        }
        for(int i=0;i<4;i++)
        {
            arr3[i+4]=arr2[i];
            }
            for(int i=0;i<8;i++)
            {
                cout<<arr3[i]<<" ";
                }
                cout<<endl;
                cout<<endl;
              for(int i=0;i<8;i++)
              {
                for(int j=i+1;j<8;j++)
                {
                    if(arr3[j]<arr3[i])
                    {
                        int temp;
                        temp=arr3[i];
                        arr3[i]=arr3[j];
                        arr3[j]=temp;

                    }
                }
              }
              for(int i=0;i<8;i++)
              {
                cout<<arr3[i]<<" ";

              }

 return 0;
}
