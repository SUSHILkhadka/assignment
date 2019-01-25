#include <iostream>
#include <cstring>
using namespace std;
void menu()
{
    cout<<"(p): Print elements\n";
    cout<<"(a): Add element\n";
    cout<<"(d): Delete element\n";
    cout<<"(r): Return size\n";
    cout<<"(e): Exit\n";
}
class like_vector
    {
        int *ptr= new int [2];
        int size=2;
        int length=0;
    public:
        void Add_element();
        void Del_element();
        void Print_elements();
        void return_size();
    };
void like_vector::Add_element()     //Whenever element is given, puts it is ptr[length] then length increases afterwards.
    {
        int num;
        cout<<"Enter element to add: "<<endl;
        cin>>num;
        if (length>=size)
        {
            cout<<"Array expanded/n"<<endl;
            size*=2;
            int *temp=new int [size];
            temp=(int *) memcpy(temp,ptr,length*sizeof(int));
            delete ptr;
            ptr=temp;
        }
        ptr[length]=num;
        length++;
    }
void like_vector::Del_element()     //If ptr has element which is not equal to ,given element to delete, then puts it in increasing index of a. Else skips it.
    {
        int num;
        cout<<"Enter element to delete: "<<endl;
        cin>>num;
        int temp;
        int a=0;
        int count=0;
        for(int i=0;i<length;i++)
        {
          if (ptr[i]!=num){
              ptr[a]=ptr[i];;
              a++;

          }
          else
          {
              count++;
          }
          
        }
        if (count>0)
        {
            length=length-count;
        }
        else
        {
            cout<<"Not there\n"<<endl;
        }
        if (length<=size/2)
        {

            size/=2;
            int *temp=new int [size];
            temp=(int *) memcpy(temp,ptr,length*sizeof(int));
            delete ptr;
            ptr=temp;
            cout<<"Array shrinked\n"<<endl;
        }
    }
void like_vector::Print_elements()
    {
        if (length>0)
        {
            for (int i=0;i<length;i++)
            {
                cout<<ptr[i]<<",";
            }
            cout<<endl;
        }
        else
        {
            cout<<"No elements\n"<<endl;
        }
    }
void like_vector::return_size()
    {
        cout<<" S: "<<size;
        cout<<" E: "<<length<<endl;
    }


int main()
    {
        char input;
        like_vector vector;
        do{
            menu();
            cout<<"Enter option: ";
            cin>>input;
            switch(input)
            {
                case 'p':
                     vector.Print_elements();
                    break;
                case 'a':
                    vector.Add_element();
                    break;
                 case 'd':
                    vector.Del_element();
                    break;
                case 'r':
                    vector.return_size();
                    break;
            }
        }while(input!='e');
    }