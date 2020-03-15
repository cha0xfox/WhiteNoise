#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>

#define RAND_NUM  128 //Size of random array

void randvec(double array[]){
      for ( int i = 0; i< RAND_NUM; i++){
            array[i] = rand()%13; // 0 - 12
      }
}

int countOccurrences(double arr[], int n, int x) 
{ 
    int res = 0; 
    for (int i=0; i<n; i++) 
        if (x == arr[i]) 
          res++; 
    return res; 
}

void autofunc(double w[] ,double arr1[], double arr2[], int arrlen1, int arrlen2){
      for (int k = 0; k < RAND_NUM*2-1; k++){
            w[k] = 0;
            for (int i = std::max(0,k-arrlen2+1); i < std::min(k+1,arrlen1); i++){
                  w[k] += round((arr1[i] * arr2[k - i])/10);
            }
    }
} 

int main( int argc, char* argv[] )
{     
      std::cout << "<-----------/Start/----------->\n";
      std::srand(time(nullptr));

      std::cout << "Main calculations\n";
      double arrayofnum[RAND_NUM];
      randvec(arrayofnum);

      double autof[RAND_NUM*2-1];
      autofunc(autof, arrayofnum, arrayofnum, RAND_NUM, RAND_NUM);
      
      
      double whitenoise[RAND_NUM]; 
      double sum;
      for (int i = 0; i<RAND_NUM ; i++){
            randvec(arrayofnum);
            sum = 0;
            for (int j = 0; j<RAND_NUM; j++){
                  sum += (arrayofnum[j]-6);
            }
            std::cout << sum << std::endl;
            whitenoise[i]=sum/2;
      }

      double autowhite[RAND_NUM*2-1];
      //randvec(arrayofnum);
      autofunc (autowhite, whitenoise, whitenoise, RAND_NUM, RAND_NUM);
      
      std::cout << "Openning csv file...\n";
      std::ofstream csvf;
      
      csvf.open ("histogramm.csv");
      std::cout << "File openned.\n";

      csvf << "Part 1 : flat after rand()" << "\n";
      for (int i = 0; i<13; i++){
            csvf << countOccurrences(arrayofnum, sizeof(arrayofnum)/sizeof(double), i) << ";";
      }

      csvf << "\n";

      csvf << "Part 1 : auto function" << "\n";
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autof[i] << ";";
      }


      csvf << "\n";

      csvf << "Part 2 : white noise" << "\n";
      for (int i = -RAND_NUM/2; i<RAND_NUM/2; i++){
            csvf << countOccurrences(whitenoise, sizeof(whitenoise)/sizeof(double),i) << ";";
      }


      csvf << "\n";

      csvf << "Part 2 : autof of white noise" << "\n";
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autowhite[i] << ";";
      }

      csvf.close();

      //system("pause");
      return 0;
}