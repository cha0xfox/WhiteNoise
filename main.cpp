#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>


// -- User includes

#include "functions.hpp"

#define RAND_NUM  512 //Size of random array

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
      wikirand(whitenoise);
      double autowhite[RAND_NUM*2-1];
      autofunc (autowhite, whitenoise, whitenoise, RAND_NUM, RAND_NUM);
      

      wikirand(whitenoise);
      double dirrak[RAND_NUM];
      corellation(dirrak, whitenoise, whitenoise, RAND_NUM);

      //-----------------PART 3
	
      double expwhite[RAND_NUM];
      double arrayofnum2[RAND_NUM];
      randvec(arrayofnum);
      randvec(arrayofnum2);
      double white2[RAND_NUM];
      wikirand(white2);
      expcalcsin(expwhite,arrayofnum,arrayofnum2);

      //-----------------PART 4

      double expwhite1[RAND_NUM];
      
      wikirand(arrayofnum);
      wikirand(arrayofnum2);
      expcalcsin(expwhite,arrayofnum,arrayofnum2);
      
      wikirand(arrayofnum);
      wikirand(arrayofnum2);
      expcalcsin(expwhite1,arrayofnum,arrayofnum2);

      double arrlaplas[RAND_NUM];
      laplas(arrlaplas,expwhite,expwhite1);


      //-----------------WRITING TO FILE
      
      std::cout << "Openning csv file...\n";
      std::ofstream csvf;
      
      csvf.open ("histogramm.txt");
      std::cout << "File openned.\n";

      wikirand(arrayofnum);

      // line 0
      for (double i = 0.00; i<1.01; i=i+0.01){
            csvf << countOccurrences(arrayofnum, sizeof(arrayofnum)/sizeof(double), i) << ",";
      }

      csvf << "\n";

      // line 1
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autof[i] << ",";
      }

      csvf << "\n";

      // line 2
      for (double i = -RAND_NUM/6; i<RAND_NUM/6; i=i+0.001){
            csvf << countOccurrences(whitenoise, sizeof(whitenoise)/sizeof(double),i) << ",";
      }


      csvf << "\n";

      // line 3
      for (int i = 0; i<RAND_NUM; i++){
            csvf << whitenoise[i] << ",";
      }


      csvf << "\n";

      // line 4
      for (int i = 0; i<RAND_NUM*2-1; i++){
            csvf << autowhite[i] << ",";
      } 
      
      csvf << "\n";

      // line 5
      for (int i = 0; i<RAND_NUM; i++){
            csvf << dirrak[i] << ",";
      } 
      
      csvf << "\n";
	
      // line 6
      for (int i = 0; i<RAND_NUM; i++){
            csvf << expwhite[i] << ",";
      }

      csvf << "\n";

      // line 7
      for (int i = 0; i<RAND_NUM; i++){
            csvf << expwhite1[i] << ",";
      }

      csvf << "\n";

      // line 8
      for (int i = 0; i<RAND_NUM; i++){
            csvf << arrlaplas[i] << ",";
      }

      csvf.close();
      std::cout << "File closed." << std::endl;
      //system("pause");
      return 0;
}
