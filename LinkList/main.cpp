// main.cpp : 测试链表功能。
#include <iostream>
#include "linkList/linklist.h"
using namespace std;
//这TM
int main()
{
    LinkList head;
    Info val1,val2,val3,val4;
    val1.id =1,val1.name="Kevin",val2.id=2,val2.name="Cathy",val3.id=3,val3.name="Lucy",val4.id=4,val4.name="Gravin";

    //测试插入功能
    cout<<"Insert test:"<<endl;
    head.InsertHead(val1);
    head.Print();
    head.Insert(val2,1);
    head.Print();
    head.Insert(val3,4);
    head.Print();
    head.InsertHead(val3);
    head.Insert(val4,2);
    head.Print();

    //测试反序功能
    cout<<"reverse test:"<<endl;
    head.Reverse();
    cout<<"reversed linklist is:"<<endl;
    head.Print();

    //测试删除功能
    cout<<"remove test:"<<endl;
    cout<<"the length of linklist is:"<<endl;
    cout<<head.Length()<<endl;
    head.Remove(val4);
    head.Print();
    cout<<"the length of linklist is:"<<endl;
    cout<<head.Length()<<endl;
    head.Remove(val4);
    head.Print();
    return 0;
}
