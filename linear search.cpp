#include<iostream>
using namespace std;

int searchlist(int list[],int numOfElements,int value);
int main()
{
    int a[5]={8,7,4,6,3},n=5,srch;
    cout<<"Enter the value you want to search\n";
    cout<<"list is : {8,7,4,6,3} \n";
    cin>>srch;
    int ret;
    ret= searchlist(a,5,srch);
    cout<<"position  "<<ret;

}
  int searchlist(int list[],int numOfElements,int value){

    int index=0;
    int position= -1;
    bool found = false;
    while(index<numOfElements && !found)
    {
        if(list[index]==value)
        {
            found=true;
            position=index;
        }
        index++;
    }
    return position;
}
