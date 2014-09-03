#include <iostream>
#include "Brainz.h"

void testFirstMove();

using namespace std;

int main()
{
    char check=-1;
    char mat [3][3]={{'-','p','-'},
                     {'-','-','-'},
                     {'-','-','-'}};
//    check=brainz(mat);
//    cout<<(int)check<<endl;
 check=checkFieldIsClaimed(mat,1);
    //check=checkTwoInRow_all(mat, 'O');
    //cout << "Hello world!" << endl;
    cout << (int)check<<endl;

    return 0;
}
