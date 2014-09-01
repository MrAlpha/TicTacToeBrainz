#include <iostream>
#include "Brainz.h"

using namespace std;

void testTwoInRow(){

    cout<<"Testing left row"<<endl;

    char check=0;
    char mat [3][3]={{'O','O','-'},
                     {'-','-','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==2)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
    check=0;
    mat =           {{'-','-','-'},
                     {'O','O','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==5)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************/
    check=0;
    mat =           {{'-','-','-'},
                     {'-','-','-'},
                     {'O','O','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==8)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************/
    /********************************************************************/

    cout<<"Testing right row"<<endl;

    check=0;
    mat  =          {{'-','O','O'},
                     {'-','-','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==0)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
    check=0;
    mat =           {{'-','-','-'},
                     {'-','O','O'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==3)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************/
    check=0;
    mat =           {{'-','-','-'},
                     {'-','-','-'},
                     {'-','O','O'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==6)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************/
    /********************************************************************/

    cout<<"Testing bottom row"<<endl;

    check=0;
    mat =           {{'-','-','-'},
                     {'-','-','O'},
                     {'-','-','O'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==2)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /**********************************************************************/
        check=0;
    mat =           {{'-','-','-'},
                     {'-','O','-'},
                     {'-','O','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==1)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************************/
        check=0;
    mat =           {{'-','-','-'},
                     {'O','-','-'},
                     {'O','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==0)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************************/
    /********************************************************************************/
    cout<<"Testing top row"<<endl;

    check=0;
    mat =           {{'-','-','O'},
                     {'-','-','O'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==8)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /**********************************************************************/
        check=0;
    mat =           {{'-','O','-'},
                     {'-','O','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==7)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************************/
        check=0;
    mat =           {{'O','-','-'},
                     {'O','-','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==6)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /****************************************************************************/
    /****************************************************************************/
    /****************************************************************************/
    cout<<"Testing horizontal Gap"<<endl;
    check=0;
    mat =           {{'-','-','O'},
                     {'-','-','-'},
                     {'-','-','O'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==5)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /**********************************************************************/
        check=0;
    mat =           {{'-','O','-'},
                     {'-','-','-'},
                     {'-','O','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************************/
        check=0;
    mat =           {{'O','-','-'},
                     {'-','-','-'},
                     {'O','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==3)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /*****************************************************************************/
    /*****************************************************************************/
    cout<<"Testing vertical gap"<<endl;
    check=0;
    mat  =          {{'O','-','O'},
                     {'-','-','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==1)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
    check=0;
    mat =           {{'-','-','-'},
                     {'O','-','O'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************/
    check=0;
    mat =           {{'-','-','-'},
                     {'-','-','-'},
                     {'O','-','O'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==7)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /********************************************************************/
    /********************************************************************/
    /********************************************************************/
    cout<<"Testing cross gap"<<endl;
    check=0;
    mat =           {{'O','-','-'},
                     {'-','-','-'},
                     {'-','-','O'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /*************************************************************************/
        check=0;
    mat =           {{'-','-','O'},
                     {'-','-','-'},
                     {'O','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /**************************************************************************/
    cout<<"Testing corner \"gaps\""<<endl;
    check=0;
    mat =           {{'-','-','-'},
                     {'-','O','-'},
                     {'O','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==2)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /**************************************************************************/
    check=0;
    mat =           {{'-','-','-'},
                     {'-','O','-'},
                     {'-','-','O'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==0)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /**************************************************************************/
            check=0;
    mat =           {{'-','-','O'},
                     {'-','O','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==6)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    /**************************************************************************/
            check=0;
    mat =           {{'O','-','-'},
                     {'-','O','-'},
                     {'-','-','-'}};

    check=checkTwoInRow_all(mat, 'O');

    if (check==8)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
    cout<<"All Tests past"<<endl;
}

void testFirstMove(){
    cout<<"Testing human opening corner"<<endl;

    char check=0;
    char mat [3][3]={{'X','-','-'},
                     {'-','-','-'},
                     {'-','-','-'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
        check=0;
        mat        ={{'-','-','-'},
                     {'-','-','-'},
                     {'X','-','-'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
        check=0;
        mat        ={{'-','-','-'},
                     {'-','-','-'},
                     {'-','-','X'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
        check=0;
        mat        ={{'-','-','X'},
                     {'-','-','-'},
                     {'-','-','-'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
cout<<"test human opening middle"<<endl;
        check=0;
        mat        ={{'-','-','-'},
                     {'-','X','-'},
                     {'-','-','-'}};

    check=brainz(mat);

    if (check==6)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
cout<<"test human opening side edge"<<endl;
        check=0;
        mat        ={{'-','-','-'},
                     {'X','-','-'},
                     {'-','-','-'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
        check=0;
        mat        ={{'-','-','-'},
                     {'-','-','-'},
                     {'-','X','-'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
        check=0;
        mat        ={{'-','-','-'},
                     {'-','-','X'},
                     {'-','-','-'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
/***************************************************************/
        check=0;
        mat        ={{'-','X','-'},
                     {'-','-','-'},
                     {'-','-','-'}};

    check=brainz(mat);

    if (check==4)
        cout<<"OK!"<<endl;
    else{
        cout<<"FAIL"<<endl;
        return;
    }
cout<<"BAM all human opening move tests past!"<<endl;
}

//        for(char i=0,i<3,i++){
//            for(char j=0,j<3,j++){
//                cout<<mat[i][j];
//            }
//            cout<<endl;
//        }


