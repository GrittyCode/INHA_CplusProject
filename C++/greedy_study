#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
   int iLine = 0;

   cin >> iLine;

   int** pArr = new int* [iLine];      // Input
   int** pArrNum = new int* [iLine];   // Tree


    for (int i = 0; i < iLine; ++i)
    {
        pArr[i] = new int[i + 1];
        pArrNum[i] = new int[i + 1];

        memset(pArrNum[i], 0, sizeof(int) * (i + 1));

        for (int j = 0; j < i + 1; ++j)
        {
            cin >> pArr[i][j];
            if (i == iLine - 1)
                pArrNum[i][j] = pArr[i][j];
        }
   }

   int iRes = 0;

   for (int i = iLine - 1; i > 0; --i)
   {
      for (int j = 0; j < i; ++j)
      {
         if (pArrNum[i][j] >= pArrNum[i][j + 1])
         {
            pArrNum[i - 1][j] = pArr[i - 1][j] + pArrNum[i][j];
         }
         else
         {
            pArrNum[i - 1][j] = pArr[i - 1][j] + pArrNum[i][j + 1];
         }

      }
   }

   iRes = pArrNum[0][0];

   cout << iRes << endl;

   // Release
   for (int i = 0; i < iLine; ++i)
   {
      delete[] pArr[i];
      pArr[i] = nullptr;

      delete[] pArrNum[i];
      pArrNum[i] = nullptr;
   }

   delete[] pArrNum;
   pArrNum = nullptr;

   delete[] pArr;
   pArr = nullptr;

   return 0;
}
