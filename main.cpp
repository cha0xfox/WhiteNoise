#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>


// -- User includes

#include "functions.hpp"

#define RAND_NUM  1512 //Size of random array

int main( int argc, char* argv[] )
{     
      std::cout << "<-----------/Start/----------->\n";
      std::srand(time(nullptr));

      std::cout << "Main calculations\n";

      // ----------------PART 1
      // Генерация равномерного распределения
      double arrayofnum[RAND_NUM];
      randvec(arrayofnum);
      // Автокорелляция равномерного распределения
      double autof[RAND_NUM*2-1];
      autofunc(autof, arrayofnum, arrayofnum, RAND_NUM, RAND_NUM);
      
      //-----------------PART 2
      // Генерация нормального распределения с нормализацией
      double whitenoise[RAND_NUM]; 
      wikirand(whitenoise);
      // Автокорелляция нормального распределения
      double autowhite[RAND_NUM*2-1];
      autofunc (autowhite, whitenoise, whitenoise, RAND_NUM, RAND_NUM);

      //-----------------PART 3
	
      double expwhite[RAND_NUM];
      double expwhite2[RAND_NUM];
      double reley[RAND_NUM];
      double arrayofnum2[RAND_NUM];
      randvec(arrayofnum);
      randvec(arrayofnum2);

      expcalcsin(expwhite,arrayofnum,arrayofnum2);
      randvec(arrayofnum);
      randvec(arrayofnum2);
      expcalccos(expwhite2,arrayofnum,arrayofnum2);
      sqrsumm(reley,expwhite,expwhite2);
      

      //-----------------PART 4

      // Генерация нормального распределения
      double white2[RAND_NUM];
      wikirand(white2);
      // Корелляция нормального распределения
      double dirrak[RAND_NUM];
      corellation(dirrak, white2, white2, RAND_NUM);


      //-----------------WRITING TO FILE
      
      std::cout << "Openning csv file...\n";
      std::ofstream csvf;
      
      csvf.open ("histogramm.txt");
      std::cout << "File openned.\n";

      randvec(arrayofnum);
      //plot [0]
      for (double i = 0.00; i<1.01; i=i+0.01){
            csvf << countOccurrences(arrayofnum, sizeof(arrayofnum)/sizeof(double), i) << ",";
      }
      csvf << "\n";

      //plot [1]
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autof[i] << ",";
      }
      csvf << "\n";

      //plot [2]
      for (double i = -2; i<2.01; i=i+0.001){
            csvf << countOccurrences(whitenoise, sizeof(whitenoise)/sizeof(double),i) << ",";
      }
      csvf << "\n";

      //plot [3]
      for (int i = 0; i<RAND_NUM; i++){
            csvf << whitenoise[i] << ",";
      }
      csvf << "\n";

      //plot [4]
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autowhite[i] << ",";
      } 
      csvf << "\n";

      //plot [5]
      for (int i = 0; i<RAND_NUM; i++){
            csvf << dirrak[i] << ",";
      } 
      csvf << "\n";

      //plot [6]
      for (double i = -3.0; i<3.01; i=i+0.1){
            csvf << countOccurrences(expwhite, sizeof(expwhite)/sizeof(double),i) << ",";
      }
      csvf << "\n";

      //plot [7]
      for (int i = 0; i<RAND_NUM; i++){
            csvf << expwhite[i] << ",";
      }
      csvf << "\n";

      //plot [8]
      for (double i = 0; i<3.01; i=i+0.001){
            csvf << countOccurrences(reley, sizeof(reley)/sizeof(double),i) << ",";
      }
      csvf << "\n";

      //plot [9]
      for (int i = 0; i<RAND_NUM; i++){
            csvf << reley[i] << ",";
      }

      csvf.close();
      std::cout << "File closed." << std::endl;
      //system("pause");
      return 0;
}
