#include<iostream>
using namespace std;
#define M 15

template <class T>
class Sort{

    private:
        T arr[M];
        int n;

    public:
        Sort(){

            getArray();
            cout << "Before sorting ";
            printArray();
            SelectionSort();
            cout << "After sorting ";
            printArray();
            cout << endl;
        }
        void getArray(){

            cout << "Enter size : ";
            cin >> n;

            if (n > M){
                cout << "Maximum size exceeded.\nSetting size as max size i.e. " << M << endl;
                n = M;
            }

            for( int i=0; i<n; i++){
                cout << "Enter element no. " << i+1 << " : ";
                cin >> arr[i];
            }
            cout << "Array stored successfully!\n";
        }

        void printArray(){

            cout << "array is :  ";
            for (int i=0; i<n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void SelectionSort() {

            // cout << "Sorting elements according to selection sort\n";

            for (int i=0; i<n-1; i++){

                int minPos = i;
                for(int j=i+1; j<n; j++){

                    if(arr[minPos]>arr[j])
                        minPos = j;
                }
                swap(arr[i], arr[minPos]);
            }

            // cout << "Selection Sort Completed\n\n";
        }
    
};

int main() {
    while(true){

            cout << "\n     M A I N  M E N U\n"
                 << "1-int\n"
                 << "2-char\n"
                 << "3-float\n"
                 << "4-double\n"
                 << "5-string\n"
                 << "0-exit\n\n";

            cout << "Enter your choice : ";
            int ch;
            cin >> ch;

            if( ch==0) {
                cout << "   T E R M I N A T I N G \n";
                exit(0);
            }
            else if( ch==1 ) {
                cout << "* data-type : int\n";
                Sort<int> obj;
            }
            else if( ch==2 ) {
                cout << "* data-type : char\n";
                Sort<char> obj;
            }
            else if( ch==3 ) {
                cout << "* data-type : float\n";
                Sort<float> obj;
            }
            else if( ch==4 ) {
                cout << "* data-type : double\n";
                Sort<double> obj;
            }
            else if( ch==5 ) {
                cout << "* data-type : string\n";
                Sort<string> obj;
            }
            else
                cout << "Invalid-Selection!\nLet's Try Again!!\n\n";
    }
}