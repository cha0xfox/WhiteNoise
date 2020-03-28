#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>


// -- User includes

#include "functions.hpp"

#define RAND_NUM  256 //Size of random array

int main( int argc, char* argv[] )
{     
      std::cout << "<-----------/Start/----------->\n";
      std::srand(time(nullptr));

      std::cout << "Main calculations\n";

      // ----------------PART 1
      double arrayofnum[RAND_NUM];
      randvec(arrayofnum);

      double autof[RAND_NUM*2-1];
      autofunc(autof, arrayofnum, arrayofnum, RAND_NUM, RAND_NUM);
      
      //-----------------PART 2
      double whitenoise[RAND_NUM]; 
      double sum;
      for (int i = 0; i<RAND_NUM ; i++){
            randvec(arrayofnum);
            sum = 0;
            for (int j = 0; j<RAND_NUM; j++){
                  sum += arrayofnum[j];
            }
            //std::cout << sum << std::endl;
            whitenoise[i]=(sum-RAND_NUM/2)/2;
      }

      double autowhite[RAND_NUM*2-1];
      //randvec(arrayofnum);
      autofunc (autowhite, whitenoise, whitenoise, RAND_NUM, RAND_NUM);

      //-----------------PART 3

      double expwhite[RAND_NUM];
      double arrayofnum2[RAND_NUM];
      randvec(arrayofnum);
      randvec(arrayofnum2);
      expcalc(expwhite,arrayofnum,arrayofnum);

      //-----------------WRITING TO FILE
      
      std::cout << "Openning csv file...\n";
      std::ofstream csvf;
      
      csvf.open ("histogramm.csv");
      std::cout << "File openned.\n";

      csvf << "Part 1 : flat after rand()" << "\n";
      for (double i = 0.00; i<1.01; i=i+0.01){
            csvf << countOccurrences(arrayofnum, sizeof(arrayofnum)/sizeof(double), i) << ";";
      }

      csvf << "\n";

      csvf << "Part 1 : auto function" << "\n";
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autof[i] << ";";
      }


      csvf << "\n";

      csvf << "Part 2 : white noise" << "\n";
      for (double i = -4; i<4; i=i+0.01){
            csvf << countOccurrences(whitenoise, sizeof(whitenoise)/sizeof(double),i) << ";";
      }


      csvf << "\n";

      csvf << "Part 2 : autof of white noise" << "\n";
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autowhite[i] << ";";
      } 
      
      csvf << "\n";

      csvf << "Part 3 : exp" << "\n";
      for (int i = 0; i<RAND_NUM; i++){
            csvf << expwhite[i] << ";";
      }

      csvf.close();
      std::cout << "File closed." << std::endl;
      //system("pause");
      return 0;
}