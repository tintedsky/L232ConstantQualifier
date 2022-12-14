//
//  main.cpp
//  L232ConstantQualifier
//
//  Created by Hongbo Niu on 2022-11-25.
//

#include <iostream>
using namespace std;

class ConstDemo{
public:
    int x=10;
    int y=20;
    
    void display() const /* const here guarantee the value cannot be modified inside the function body. */
    {
        // x++; here is wrong because the const keywork in the function signature.
        cout<<"x:"<<x<<endl<<"y:"<<y<<endl;
    }
};


void displayValues(const int &x, const int &y){
     /* y--; from the parameter list, y is the reference of a constant integer */
    cout<<"From "<<__FUNCTION__<<": x3:"<<x<<" y3:"<<y<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    const int x = 10;  /* const need to be intialized directly */
    int const y = 20 ;  /* const type === type const */
    
    int x1 = 11, y1=21;
    const int *p1 = &x1; /* p1 can change but (*p1) no. The value cannot be changed by the poitner */
    cout<<p1<<endl;
    cout<<*p1++<<endl;   /*Note the difference *p1++ vs (*p1)++ */
    
    p1=&y1;   /*p1 can pointer to the different memory, still 'const int *' === 'int const *' */
    cout<<++x1<<endl;
    /* The variable x1 itself can be changed, but cannot mo chagned through the pointer p1 */
    
    int x2=12, y2=22;
    int * const p2 = &x2;
    /** p2 = &y2; the pointer cannot point to anywhere else */
    
    int x3=13, y3=23;
    const int * const p3 = &x3;
    
    ConstDemo cd;
    cd.display();
    
    displayValues(x3, y3);
    
    /**x4 can increase by itself, but the const int pointer p4 cannot change the value of x4 */
    int x4=14, y4=24;
    const int* p4=&x4;
    cout<<*p4<<endl;
    ++x4;
    cout<<*p4<<endl;

    const int x5 = 15;
    /* int* p5=&x5; normal pointer cannot be assigned with a const integer value's address */
    
    
    return 0;
}
