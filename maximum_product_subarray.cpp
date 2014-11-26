class Solution {

public:
  int maxProduct(int A[], int n) {

    if(n <= 0){
      return -1;
    }

    int maxProduct = A[0];
    int productMax = A[0];
    int productMin = A[0];
    for(int i = 1; i < n; i++){

      int tmpMax = productMax * A[i];
      int tmpMin = productMin * A[i];

      if(tmpMax > tmpMin){
        productMax = tmpMax > A[i] ? tmpMax : A[i];
        productMin = tmpMin > A[i] ? A[i] : tmpMin;
      }
      else{
        productMax = tmpMin > A[i] ? tmpMin : A[i];
        productMin = tmpMax > A[i] ? A[i] : tmpMax;
      }

      if(productMin > productMax){
        maxProduct = productMin > maxProduct ? productMin : maxProduct;
      }
      else{
        maxProduct = productMax > maxProduct ? productMax : maxProduct;
      }

    }

    return maxProduct;
  }

};

