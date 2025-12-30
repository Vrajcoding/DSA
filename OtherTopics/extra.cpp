#include <iostream>
#include<vector>
#include <limits>
#include <algorithm>
using namespace std;
void printSeven(int mat[][3], int n, int m)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            swap(mat[i][j], mat[i][n - j - 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void constuctedArray(int *arr, int len)
{
    int mat[1][3] = {{0}};
    int n = 3, m = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = arr[i * n + j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }

        cout << endl;
    }
}
void grid(int arr[][3], int n)
{
    int len = n * n;
    int temp[len];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i * n + j] = arr[i][j];
        }
    }

    sort(temp, temp + len);
    int duplicateValue = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (temp[i] == temp[i + 1])
        {
            duplicateValue = temp[i];
            // cout << "Final value is :" << duplicateValue << endl;
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < n * n; i++)
    {
        sum += temp[i];
    }

    sum = sum - duplicateValue;
    cout << "sum of arry is : " << sum;
    int calculateSum = (len * (len + 1)) / 2; // 3
    cout << "calculate sum of arry is : " << calculateSum << endl;
    int missingvalue = calculateSum - sum;
    cout << "Missing value is :" << missingvalue << endl;

    cout << "duplicate value is :" << duplicateValue << endl;
    cout << "missing value is :" << missingvalue << endl;
}

bool searchMatrix(int arr[][4], int n, int m, int key)
{
    int str = 0, stc = 0, endr = n - 1, endc = m - 1;

    while (str <= endr)
    {
        int rmid = (str + endr) / 2;

        if (arr[rmid][str] == key)
        {
            return true;
        }
        else if (arr[rmid][str] > key)
        {
            endr = rmid - 1;
            while (stc <= endc)
            {
                int cmid = (stc + endc) / 2;
                if (arr[str][cmid] == key)
                {
                    return true;
                }
                else if (arr[str][cmid] > key)
                {
                    endc = cmid - 1;
                }
                else
                {
                    stc = cmid + 1;
                }
            }
        }
        else
        {
            str = rmid + 1;
            while (stc <= endc)
            {
                int cmid = (stc + endc) / 2;
                if (arr[endr][cmid] == key)
                {
                    return true;
                }
                else if (arr[endr][cmid] > key)
                {
                    endc = cmid - 1;
                }
                else
                {
                    stc = cmid + 1;
                }
            }
        }
    }
    return false;
}
int peakIndex(int *arr, int n)
{

    int st = 0, end = n - 1;
    while (st < end)
    {
        int mid = (st + end) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            st = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return st;
}

int chefDoll(int *arr, int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i - 1] != arr[i] && arr[i] != arr[i + 1])
        {
            cout << "Missing value is :" << arr[i] << endl;
            return arr[i];
        }
    }
    return -1;
}

int LargestReactagle(int *arr,int n) {
    int temparr[1000];
    temparr[n-1] = 0;

    for(int i = 0;i < n-1;i++) {
        temparr[i] = arr[i+1];
    }
    int currentValue = 0,value = 0;
    for(int i = 0;i < n;i++) {
       currentValue = min(temparr[i], arr[i]) * 2;
       cout << currentValue << " ";
       value = max(currentValue , value);
    }
    cout << endl;
    cout << value << " " << endl;
}

void twoDDyanamic() {
    int rows,cols;

   cout << "Enter the rows :";
   cin >> rows;

   cout << "Enter the columns : ";
   cin >> cols;

   int* *matrix = new int*[rows];
   for(int i = 0;i < rows;i++) {
      matrix[i] = new int[cols];
   }
  int x = 1;
   for(int i = 0;i < rows;i++) {
    for(int j = 0;j < cols;j++) {
        matrix[i][j] = x++;
        cout << matrix[i][j] << " ";
        
    }
    cout << endl;
   }
}

int binarySearch(vector<int> nums,int target) {
 int st = 0,end = nums.size() - 1;

 while (st <= end)
 {
  int mid  = st + (end - st) / 2;
  if(nums[mid] == target) {
    return mid;
  } else if(nums[mid] < target) {
      st = mid + 1; // 0
  } else {
     end = mid - 1; // 0
  } 
 }
 return st;
}


void expontention(int x,int n) {
    int sum = 1;
    while(n > 0) {
        int lastDig = n & 1;
        if(lastDig) {
             sum *= x;
        }
        x = x * x;
        n = n >> 1;

    }
}


void initValue(int num,int i,int j) {

    // approach one
   while(i <= j) {
      int mask = ~(1 << i);
      num = num & mask;
      i++;
   }
   cout << num << endl;


   //Approach two
   // ending position
   int a = (~0) << (j+1);
   // starting position
   int b = (1 << i) - 1;

   int mask = a | b;
   num = num & mask;

   cout << num << endl;
}

void singleValue(vector<int> nums){
    int current = nums[0];
    for(int i = 0;i < nums.size() - 1;i++) {
          int ans =  current ^ nums[i+1];
          if(!ans) {
            cout << current << endl;
            return;
          }
    }
}

class Complex {
    int real;
    int img;

    public:
      Complex(int r,int i) {
        real = r;
        img = i;
      }

      void showNum() {
        cout <<  real << "+" << img << "i" << endl; 
      }

      Complex operator + (Complex &obj) {
        int realNum = this->real + obj.real;
        int imageNum = this->img + obj.img;
        Complex c3(realNum, imageNum);
        return c3;
      }

       Complex operator - (Complex &obj) {
        int realNum = this->real - obj.real;
        int imageNum = this->img - obj.img;
        Complex c3(realNum, imageNum);
        return c3;
      }
};



int fact(int n) {
    if(n == 0) {
        return 0;
    }

    return n + fact(n-1);
}

void func(int n) {
    if(n == 0) {
        return;
    }

    func(n-1);
    cout << n << " ";
}

int firstOcc(vector<int> arr,int target,int i){
    int n = arr.size();
    if(i == n-1){
      return -1;
    }

    if(target == arr[i]) {
        return i;
    }

    return firstOcc(arr,target,i+1);
}

int lastOccur(vector<int> arr,int target,int i) {
    if(i == -1) {
        return -1;
    }

    if(target == arr[i]) {
        return i;
    }

    return lastOccur(arr, target, i-1);
}

int pow(int base,int n) {
    if(n == 0) {
        return 1;
    }

    int halfSquare = pow(base, n/2);
    int halfPart = halfSquare * halfSquare;

    if(n % 2 != 0) {
        return base * halfPart;
    }

    return halfPart;
}


int main()
{
   cout << pow(2, 10) << endl;
    return 0;

}