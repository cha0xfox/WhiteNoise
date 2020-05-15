#define RAND_NUM 1512
#define PI 3.141592653589793

// Генерация равномерного распределения
void randvec(double array[]){
      for ( int i = 0; i< RAND_NUM; i++){
            array[i] = (rand()%51)*(0.02); // 0 - 1
      }
}

// Генерация нормализованного распределения (алгоритм вики)
void wikirand(double array[]){
    for (int i = 0; i < RAND_NUM; i++){
        array[i] = 0;
        for (int j = 0; j < 12; j++){
            array[i]+=((rand()%51)*0.02);
        }
        array[i] = (array[i]-6)/2;
    }
}

// Сравнение чисел float
bool compare(double a, double b){
    return (fabs(a-b) < 0.01);
}

// Подсчет значений для гистограмм
int countOccurrences(double arr[], int n, double x){ 
    int res = 0; 
    for (int i=0; i<n; i++) 
        if (compare(arr[i],x))
          res++; 
    return res; 
}

// Функция сверки, выступает в качестве алгоритма автокорелляции
void autofunc(double w[] ,double arr1[], double arr2[], int arrlen1, int arrlen2){
      for (int k = 0; k < arrlen1+arrlen2-1; k++){
            w[k] = 0;
            for (int i = std::max(0,k-arrlen2+1); i < std::min(k+1,arrlen1); i++){
                  w[k] += (arr1[i] * arr2[k - i]);
            }
    }
} 

// Рассчет через формулу косинуса
void calccos(double w[], double arr1[], double arr2[]){
      for (int k = 0; k < RAND_NUM; k++){
            w[k] = sqrt(-2*log(arr1[k]))*cos(2*PI*arr2[k]);
    }
}

// Рассчет через формулу синуса
void calcsin(double w[], double arr1[], double arr2[]){
      for (int k = 0; k < RAND_NUM; k++){
            w[k] = sqrt(-2*log(arr1[k]))*sin(2*PI*arr2[k]);
    }
}

// Сумма квадратов двух массивов
void sqrsumm(double arrr[],double arrx[], double arry[]){
      for (int k = 0; k < RAND_NUM; k++){
            arrr[k] = sqrt(pow(arrx[k],2)+pow(arry[k],2));
    }
}

// Функция нормализации для массивов равномерного распределения
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

// Функция корелляции
void corellation(double w[], double a[], double b[], int N){
	for(int i = 0; i < N; i++){
		w[i]=0;
		for(int j = 0; j < N; j++){
			if (j+i<=N)
				w[i]+=a[j]*b[j+i];
			else
				w[i]+=a[j]*0;
		}
	w[i]=w[i]/N;
	}
}

// Рассчет экспоненциального распределения через сумму квадратов
void calcexp(double w[], double a[], double b[]){
    for (int i = 0; i < RAND_NUM; i++){
        w[i] = pow(a[i],2)+pow(b[i],2);
    }
}
