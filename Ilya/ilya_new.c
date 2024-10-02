#include <stdio.h>

// Function to print an integer array
void printIntArr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// function that returns sum of even numbers in array
int calcEven(int arr[], int n) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (!(arr[i] % 2)) {
      res += arr[i];
    }
  }
  return res;
}

int main() {
  int N;
  scanf("%d", &N);
  int arr[N];
  int arrindex[N];
  int res = 0;
  int newN = N;
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    arrindex[i] = 0;
  }
  if (N != 1) {
    // find integers in arr to delete

    // for the first element of arr
    if (arr[0] < arr[1]) {
      arrindex[0] = 1;
      newN--;
    }

    for (int i = 1; i + 1 < N; i++) {
      if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
        arrindex[i] = 1;
        printf("We skipping [%d] because it is always greater than [%d]\n",
               arr[i + 1], arr[i]);
        i++; // we skip next integer
        newN--;
      }
    }

    // for the last element of arr
    if (arr[N - 1] < arr[N - 2]) {
      arrindex[N - 1] = 1;
      newN--;
    }

    // create new arr or use default to calculate even numbers
    if (newN != N) {
      int newArr[newN];
      int j = 0;
      for (int i = 0; i < N; i++) {
        if (!arrindex[i]) {
          newArr[j] = arr[i];
          j++;
        }
      }
      res = calcEven(newArr, newN);
      printf("\nNew array:\n");
      printIntArr(newArr, newN);
    }

    else {
      res = calcEven(arr, N);
      printf("Unchanged array:\n");
      printIntArr(arr, N);
    }
    printf("\nSum of even numbers: %d\n", res);
  }
  // if theres only one integer in array
  else {
    if (!(arr[0] % 2)) {
      printf("Sum of even numbers: %d\n", arr[0]);
    } else {
      printf("Sum of even numbers: 0\n");
    }
  }
}
