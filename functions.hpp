#define RAND_NUM 256

void randvec(double array[]){
      for ( int i = 0; i< RAND_NUM; i++){
            array[i] = (double)(rand()%101)/100; // 0 - 1
      }
}

bool compare(double a, double b)
{
    return (fabs(a-b) < 0.01);
}

int countOccurrences(double arr[], int n, double x) 
{ 
    int res = 0; 
    for (int i=0; i<n; i++){ 
        if (compare(arr[i],x))
          res++; 
      //std::cout << arr[i] << " : " << x << std::endl;
    }
    return res; 
}

void autofunc(double w[] ,double arr1[], double arr2[], int arrlen1, int arrlen2){
      for (int k = 0; k < RAND_NUM*2-1; k++){
            w[k] = 0;
            for (int i = std::max(0,k-arrlen2+1); i < std::min(k+1,arrlen1); i++){
                  w[k] += (arr1[i] * arr2[k - i]);
            }
    }
} 
