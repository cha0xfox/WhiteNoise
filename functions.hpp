#define RAND_NUM 512
#define PI 3.141592653589793


void randvec(double array[]){
      for ( int i = 0; i< RAND_NUM; i++){
            array[i] = (rand()%51)*(0.02); // 0 - 1
      }
}

void wikirand(double array[]){
    srand(time(NULL));
    for (int i = 0; i < RAND_NUM; i++){
        array[i] = 0;
        for (int j = 0; j < 12; j++){
            array[i]+=((rand()%51)*0.02);
        }
        array[i] = (array[i]-6)/2;
    }
}

bool compare(double a, double b){
    return (fabs(a-b) < 0.01);
}

int countOccurrences(double arr[], int n, double x){ 
    int res = 0; 
    for (int i=0; i<n; i++) 
        if (compare(arr[i],x))
          res++; 
    return res; 
}

void autofunc(double w[] ,double arr1[], double arr2[], int arrlen1, int arrlen2){
      for (int k = 0; k < arrlen1+arrlen2-1; k++){
            w[k] = 0;
            for (int i = std::max(0,k-arrlen2+1); i < std::min(k+1,arrlen1); i++){
                  w[k] += (arr1[i] * arr2[k - i]);
            }
    }
} 

void expcalccos(double w[], double arr1[], double arr2[]){
      for (int k = 0; k < RAND_NUM; k++){
            w[k] = sqrt(-2*log(arr1[k]))*cos(2*PI*arr2[k]);
    }
}

void expcalcsin(double w[], double arr1[], double arr2[]){
      for (int k = 0; k < RAND_NUM; k++){
            w[k] = sqrt(-2*log(arr1[k]))*sin(2*PI*arr2[k]);
    }
}

void laplas(double arrr[],double arrx[], double arry[]){
      for (int k = 0; k < RAND_NUM; k++){
            arrr[k] = sqrt(pow(arrx[k],2)+pow(arry[k],2));
    }
}

void normalize(double arr[]){
      double sum;
      double arrayofnum[RAND_NUM];
      for (int i = 0; i<RAND_NUM ; i++){
            randvec(arrayofnum);
            sum = 0;
            for (int j = 0; j<RAND_NUM; j++){
                  sum += arrayofnum[j];
            }
            //std::cout << sum << std::endl;
            arr[i]=(sum-RAND_NUM/2)/2;
      }
}

void corellation(double w[], double array1[], double array2[], int N){
	for(int i = 0; i < N; i++){
		w[i]=0;
		for(int j = 0; j < N; j++){
			if (j+i<=N)
				w[i]+=array1[j]*array2[j+i];
			else
				w[i]+=array1[j]*0;
		}
	w[i]=w[i]/N;
	}
}
