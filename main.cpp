#include <iostream>
#include "Brainz.h"

void testFirstMove();

using namespace std;

int main()
{
//    char check=-1;
//    char mat [3][3]={{'-','p','-'},
//                     {'-','-','-'},
//                     {'-','-','-'}};
//    check=brainz(mat);
//    cout<<(int)check<<endl;
// check=checkFieldIsClaimed(mat,1);
    //check=checkTwoInRow_all(mat, 'O');
    //cout << "Hello world!" << endl;
    //cout << (int)check<<endl;
    int n=0, o=0;
    while(n<9){
        cout<<n<<endl;
        n+=2+((o%2)*2);
        o++;

    }
    return 0;
}
